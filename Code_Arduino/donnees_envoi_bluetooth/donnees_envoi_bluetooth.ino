#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
# define nombreDePixelsEnlargeur 128
# define nombreDePixelsEnHauteur 64
#define  brocheResetOLED -1 
# define adresseI2CecranOLED 0x3C

int dataPin = A1;
SoftwareSerial mySerial (6, 7);
int consigne=0;
//int16_t posx = 40;
//int16_t posy = 10;
int16_t couleur = SSD1306_WHITE;
Adafruit_SSD1306 ecranOLED(nombreDePixelsEnlargeur, nombreDePixelsEnHauteur, &Wire, brocheResetOLED);



void setup() {
  Serial.begin(9600);
if(!ecranOLED.begin(SSD1306_SWITCHCAPVCC,adresseI2CecranOLED))
  while(1); 
  //Serial.println("ok");
  ecranOLED.clearDisplay();
  ecranOLED.setTextSize(2);
  delay(2000);
  ecranOLED.setCursor(64,32);
  ecranOLED.setTextColor(SSD1306_WHITE);
  
 
   
  
}

void loop() {
  float mesure = analogRead(dataPin);  //recup valeur capteur 
  Serial.println(mesure); //retoune la valeur 
  delay(1);
  //Serial.println(Serial.read());
//Serial.println(mySerial.available());
 while (mySerial.available()>0){
   consigne=mySerial.read();
      Serial.println(consigne,DEC);
      if (consigne==1){
        digitalWrite(13,HIGH);
      }
      if (consigne==2){
        digitalWrite(13,LOW);
      }
  }
  
      ecranOLED.clearDisplay();
      // calcul
      mesure=(5/1023)*mesure;
      float resistance = ((1+(100))*100000*(5/mesure)-100000-10000);// changer capteur trop nulle l'autre
      
      ecranOLED.println(resistance);
      //Serial.print("lz");
      ecranOLED.display();
       ecranOLED.setCursor(64,32);
      delay(2000);
}
