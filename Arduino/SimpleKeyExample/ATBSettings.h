#ifndef _ATBSettingsLib_h
#define _ATBSettingsLib_h
#define INTERNAL_REFERENCE true //true   //Habilita referencia interna de 2.56V
#define FILTER 70//70                 //Cantidad de lecturas del ADC por ciclo de lectura en Read()
#define THRESHOLD_DFLT 15         //Valor minimo del ADC para considerar un positivo. (MAXIMO:1023)
#define MIN_POSITIVE_COUNT (FILTER - FILTER/3)   //Minima cantidad de positivos p/considerar una tecla presionada
#endif


//Resiste hasta falta de masa con persona sin pulsera y pisando descalzo
//INTERNAL_REFERENCE true 
//FILTER 170
//THRESHOLD_DFLT 15  
//MIN_POSITIVE_COUNT (FILTER - FILTER/2)

//Anda Perfecto asilado y en instalacion con tierra.
//INTERNAL_REFERENCE true
//FILTER 70
//THRESHOLD_DFLT 15
//MIN_POSITIVE_COUNT (FILTER - FILTER/10)
