



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

// Define variables
int redValue;
int greenValue;
int blueValue;


// Function to calculate the blue value.
int redLED(double temp)
{
    double y;
    y = -(temp - 23) + 1;

    if (y > 1 || y < 0){
      return 0;
    } else {
        
      return round( 255 * y );
    }
}


// Function to calculate the red value.
int blueLED(double temp)
{
    double y;
    y = (temp - 23) - 1;

    if (y > 1 || y < 0){
      return 0;
    } else {
        
      return round( 255 * y );
    }
}

// Function to calculate the green value.
int greenLED(double temp)
{
    double y;
    y = -2 * abs(temp - 24) + 1;

    if (y > 1 || y < 0){
      return 0;
    } else {
        
      return round( 255 * y );
    }
}



void loop() {

  
  float humi = dht.readHumidity();

  float tempC = dht.readTemperature();

  float tempF = dht.readTemperature(true);

  
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print("*C ~ ");
  
  #define delayTime 100
  delay(delayTime);

  analogWrite( BLUE, blueLED( tempC ) );
  analogWrite( GREEN, greenLED( tempC ) );
  analogWrite( RED, redLED( tempC ) );

  
  /*
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
  */
 

}
