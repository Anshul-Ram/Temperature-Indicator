



#define BLUE 3
#define GREEN 5
#define RED 6

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11


DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);

  Serial.begin(9600);
  dht.begin();
}

// define variables
int redValue;
int greenValue;
int blueValue;


void loop() {

  
  float humi = dht.readHumidity();

  float tempC = dht.readTemperature();

  float tempF = dht.readTemperature(true);

  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print("*C ~ ");

  #define delayTime 10 // fading time between colors

  redValue = 255;
  greenValue = 0;
  blueValue = 0;

  for(int i = 0; i < 255; i +=1){
    redValue -= 1;
    greenValue += 1;

    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    delay(delayTime);
    
    }

  redValue = 0;
  greenValue = 255;
  blueValue = 0;

  for(int i = 0; i < 255; i += 1) // fades out green bring blue full when i=255
  {
    greenValue -= 1;
    blueValue += 1;
    // The following was reversed, counting in the wrong directions
    // analogWrite(GREEN, 255 - greenValue);
    // analogWrite(BLUE, 255 - blueValue);
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
    delay(delayTime);
  }

  redValue = 0;
  greenValue = 255;
  blueValue = 0;

  for(int i = 0; i < 255; i += 1){
    blueValue -= 1;
    redValue += 1;

    analogWrite(BLUE, blueValue);
    analogWrite(RED, redValue);
    delay(delayTime);
    
    }

  

}
