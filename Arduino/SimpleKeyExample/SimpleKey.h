#ifndef _SimpleKeyLib_h
#define _SimpleKeyLib_h
#include <Keyboard.h>
#include "ATBSettings.h"


class SimpleKey
{
  public:
    SimpleKey(int, char, bool, int, bool);  //Puerto, Letra a presionar, SinglePress, Umbral (opcional), Debug (opcional)
    void Read();
    bool IsPressed();
    void Release();
  private:
    int  _AnalogPin;
    char _KeyCode;
    int  _Threshold;
    bool _SinglePress;
    bool _PreviousState;
    bool _Debug;
    bool _KeyPressed = false;
};
    

SimpleKey::SimpleKey(int analogPin, char keyCode, bool singlePress, int threshold = THRESHOLD_DFLT, bool debug = false)
{
  _AnalogPin = analogPin;
  _KeyCode = keyCode;
  _Threshold = threshold;
  _SinglePress = singlePress;
  _Debug = debug;
  pinMode(_AnalogPin, INPUT);
  if (_Debug) Serial.begin(115200);   //Optativo para hacer debug
  Keyboard.begin();
}


void SimpleKey::Read()
{
  int positiveCounter = 0;
  if (INTERNAL_REFERENCE) analogReference(INTERNAL);
  
  for (int i=0; i < FILTER; i++)
  {
    int adcValue = analogRead(_AnalogPin);
    if (adcValue >= _Threshold) positiveCounter++;
  }
  
  if (_SinglePress)
  {
    Serial.print("*P.C.:"); Serial.println(positiveCounter);
    if (positiveCounter >= MIN_POSITIVE_COUNT)     //Si al menos X de las veces se interpretó que la tecla esta presionada
    {
      if (!_KeyPressed)             //Si la tecla no esta presionada entonces la presiono
      {
        Keyboard.write(_KeyCode);   //Presiona la tecla
        _KeyPressed = true;
        if (_Debug) { Serial.print("*WRITE:"); Serial.println(_KeyCode); }
      }
    }
    else
    {
      _KeyPressed = false;
      if (_Debug) { Serial.print("*NO WRITE:"); Serial.println(_KeyCode); }
    } 
  }
  else
  {
    if (_Debug && positiveCounter > 0) {Serial.print("K. YES:"); Serial.print(positiveCounter); Serial.println("  ");}
    //Si al menos la mitad de las veces se interpretó que la tecla esta presionada
    if (positiveCounter >= MIN_POSITIVE_COUNT)   
    {
      if (!_KeyPressed)                   //Si la tecla no esta presionada entonces la presiono
      {
        _KeyPressed = true;
        Keyboard.press(_KeyCode);         //Presiona la tecla    
        if (_Debug) { Serial.print("*K. PRESS "); Serial.println(_KeyCode); }
      }
    }
    else
    {
      if (_KeyPressed)                    //Si la tecla no esta liberada entonces la libero
      {
        _KeyPressed = false;
        Keyboard.release(_KeyCode);       //Libera la tecla    
        if (_Debug) { Serial.print("*K. REL. "); Serial.println(_KeyCode); }  
      }
    }
  }
}


void SimpleKey::Release()
{
    Keyboard.release(_KeyCode); 
}


//Solo se fija si está presionada, pero no envia pulsacion
bool SimpleKey::IsPressed()
{
  int positiveCounter = 0, adcValue;
  if (INTERNAL_REFERENCE) analogReference(INTERNAL);

  for (int i=0; i < FILTER; i++)
  {
    adcValue = analogRead(_AnalogPin);
    if (adcValue >= _Threshold) positiveCounter++;
  }

  return (positiveCounter >= MIN_POSITIVE_COUNT);
}

#endif
