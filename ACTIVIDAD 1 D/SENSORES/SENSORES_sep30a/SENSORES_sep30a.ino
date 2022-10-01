#include "arduino_secrets.h"
// GRUPO 3 -SEAMANA 4- SENSORES Y ACTUADORES
//INCLUYO LIBRERIAS 
#include "arduino_secrets.h"
#include "thingProperties.h"
#include "DHT.h" // LIBRERIA PARA USAR EL SENSOR
#include "DHT_U.h"
#define DHTPIN 16 // PIN DONDE VOY A CONECTAR EL SENSOR 
#define DHTTYPE DHT11 // SELECCIONO EL MODELO DEL SENSOR

DHT dht(DHTPIN, DHTTYPE); // CREO EL OBJETO Y LO LLAMO dht
// FUNCION PARA CONFIGURAR EL SENSOR
void setup() {
  // INICIALIZO LA COMUNICACION SERIAL
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);
  // INICIALIZO EL SENSOR
  dht.begin();
  // DEFINO EN  thingProperties.h
  initProperties();

  // CONECTO A  Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();


}
// FUNCION BUCLE
void loop() {
  ArduinoCloud.update();
  // DEFINO UNA VARIABLE DECIMAL DEL TIPO FLOAT DONDE ALMACENO EL VALOR LEIDO DEL SENSOR 
 float temp = dht.readTemperature();
  // VERIFICO QUE SE LEYO UN VALOR 
  if ( isnan(temp) ) {
    Serial.println("Error de lectura en sensor DHT11!");
    return;
  }
 // ENVIO UN MENSAJE AL MONITOR SERI REFERIDA A LA LECTURA DE LA TEMPERATURA 
  Serial.print("Temperatura: ");
  temperatura=temp;
  Serial.print(temperatura);
  Serial.println("°C ");
  delay(5000);
  // Your code here

}


/*
  Since Temperatura is READ_WRITE variable, onTemperaturaChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTemperaturaChange()  {
  // Add your code here to act upon Msg change
}











