#include <TTSi7006.h>

TTSi7006 si7006 = TTSi7006(true);

void setup(){
  Serial.begin(9600);
  Serial.print("Si7006 is connected: ");
  Serial.println(si7006.isConnected() ? "Yes" : "No");
}

void loop(){
  //Print out humidity
  Serial.print("Humidity: ");
  Serial.print(si7006.readHumidity());
  Serial.println(" % rel.");

  //Print out Temperature °C
  Serial.print("Temperature: ");
  Serial.print(si7006.readTemperatureC());
  Serial.print(" ");
  Serial.print(char(176));
  Serial.println("C");
  
  //Print out Temperature F
  Serial.print("Temperature: ");
  Serial.print(si7006.readTemperatureF());
  Serial.print(" ");
  Serial.print(char(176));
  Serial.println("F");
  
  delay(2000);
}



