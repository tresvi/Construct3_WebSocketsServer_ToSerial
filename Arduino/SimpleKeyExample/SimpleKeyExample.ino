#include "SimpleKey.h"
#define UMBRAL 20 

//////////////Declaro las teclas que voy a usar///////////////
SimpleKey key_S(A3, 'A', false, UMBRAL);  // Parametros: Puerto, tecla a presionar, presion simple ,umbral
SimpleKey key_A(A1, 'S', false, UMBRAL);
SimpleKey key_D(A10, 'D', false, UMBRAL);
SimpleKey key_Z(A2, 'Z', false, UMBRAL);
//SimpleKey key_X(A0, 'X', false, UMBRAL);
SimpleKey key_ENTER(A0, KEY_RETURN, false, UMBRAL);       //Enter 
SimpleKey key_UP(A6, KEY_UP_ARROW, false, UMBRAL);        //UpArrow
SimpleKey key_LEFT(A7, KEY_LEFT_ARROW, false, UMBRAL);    //Left
SimpleKey key_RIGHT(A8, KEY_RIGHT_ARROW, false, UMBRAL);  //Right
SimpleKey key_DOWN(A9, KEY_DOWN_ARROW , false, UMBRAL);   //Down


//AnalogKey analogKey(A7, sizeof(levelKeys), levelKeys);
//MouseKey mouse_LEFT(A7, MOUSE_LEFT, UMBRAL);
//MouseMove mouse_X(A7, MOUSE_X, sensibility); //4 niveles de sensibilidad


void setup()
{
}

void loop() 
{
  /////////////////Leo todas las teclas/////////////////
  key_S.Read();
  key_A.Read();
  key_D.Read();
  key_Z.Read();
  key_ENTER.Read();
  key_UP.Read();
  key_LEFT.Read();
  key_RIGHT.Read();
  key_DOWN.Read();

  //mouse_LEFT.Read();
  //analogKey.Read();
}
