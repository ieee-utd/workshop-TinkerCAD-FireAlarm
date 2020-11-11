/* temperature sensor variables */
float celcius;
float fahrenheit;
float voltage;
int temperatureSensorPin = A0;	/*assign buzzer output to pin A0*/

/* gas sensor variables */

int gasSensorPin = A1;	/*assign buzzer output to pin A1*/
int buzzerPin = 9;  	/*assign buzzer output to pin 9*/
int ledPin = 8;			/*assign buzzer output to pin 8*/

/* variable that both sensors use */
float sensorValue;

void setup()
{
  /*Tells the arduino that the temperature Sensor is an input*/
  pinMode(temperatureSensorPin, INPUT);	
  /*Tells the arduino that the buzzer is an output*/
  pinMode(buzzerPin, OUTPUT);
  /*Tells the arduino that the led is an output*/
  pinMode(ledPin, OUTPUT);
  /*Allows for the use of the serial monitor*/
  Serial.begin(9600);
}

void loop()
{
  /* code for the gas sensor */
  
  /*reads the value from the gas sensor and stores it*/
  sensorValue = analogRead(gasSensorPin);
  
  /*tests to see if there's harmful gasses or a fire*/
  if(sensorValue >= 450 || celcius > 100)
  {
	Serial.print(sensorValue);
  Serial.println("	| SMOKE/FIRE DETECTED!");
  /*buzzer go brrrrr*/
  tone(buzzerPin, 1000); // Send 1KHz sound signal...
  digitalWrite(ledPin, HIGH); // turns on the LED
  delay(1000);        // ...for 1 sec
  noTone(buzzerPin);     // Stop sound...
  digitalWrite(ledPin, LOW); // turns off the LED
  delay(1000);        // ...for 1sec
  
    
  }
  else
  {
    /*Prints out the value from the gas sensor that was stored*/
    Serial.print("Sensor Value: ");
    Serial.println(sensorValue);
  }
  
  /* code for the temperature sensor */
  
  /*reads the raw value from the temperature sensor*/
  sensorValue = analogRead(temperatureSensorPin);
  
  /* calculating the voltage collected from the sensor */
  voltage = sensorValue * 5; // multiplied by 5 since we're using 5 volts
  voltage /= 1024; // divide by 1024 since arduino reads in data from 0 to 1023 also know as 10 bits
  
  /* calculate the temperature from the voltage */
  
  celcius = (voltage - 0.5) * 100; // calculates the temperature in Celcius
  fahrenheit = (9.0 / 5) * celcius + 32; // calculates temperature in Fahrenheit
  
  /* printing the temperatures */
  Serial.print("Celcius: ");
  Serial.println(celcius);
  Serial.print("Fahrenheit: ");
  Serial.println(fahrenheit);
  Serial.println();
  
  delay(1000); // pauses for 1 seconds so we're not bombarded with data
}