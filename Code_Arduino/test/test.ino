#include <SoftwareSerial.h>
#include <Wire.h>

#define rxPin 5 //Broche 5 en tant que RX, a raccorder sur TX du HC-05
#define txPin 4 //Broche 4 en tant que TX, a raccorder sur RX du HC-05 
#define baudrate 9600 //bluetooth 
SoftwareSerial mySerial(rxPin ,txPin); //D�finition du software serial pour bluetooth 

#include <Adafruit_SSD1306.h>    //init OLEd 
# define nombreDePixelsEnlargeur 128    //init OLEd
# define nombreDePixelsEnHauteur 64    //init OLEd
#define  brocheResetOLED -1   //init OLEd
# define adresseI2CecranOLED 0x3C   //init OLEd

//const for flex sensor
const float VCC = 5;      // voltage at Ardunio 5V line
const float R_DIV = 33000.0;  // resistor used to create a voltage divider
const float flatResistance = 25000.0; // resistance when flat
const float bendResistance = 100000.0;  // resistance at 90 deg

int dataPin = A1;  //pin input du signal de sortie du capteur graphite 
int dataPinF = A2;      //pin input du signal de sortie du Flex Sensor 

//SoftwareSerial mySerial (6, 7);
int consigne=0; //bluetooth 
int16_t couleur = SSD1306_WHITE;// init OLED
Adafruit_SSD1306 ecranOLED(nombreDePixelsEnlargeur, nombreDePixelsEnHauteur, &Wire, brocheResetOLED); // init OLED

// Déclaration Digital pot
#include <SPI.h>

const byte csPin           = 10;      // MCP42100 chip select pin
const int  maxPositions    = 256;     // wiper can move from 0 to 255 = 256 positions
const long rAB             = 46000;   // 50k pot resistance between terminals A and B, 
                                      
const byte rWiper          = 125;     // 125 ohms pot wiper resistance
const byte pot0            = 0x11;    // pot0 addr // B 0001 0001
const byte pot0Shutdown    = 0x21;    // pot0 shutdown // B 0010 0001

void setPotWiper(int addr, int pos) {
  pos = constrain(pos, 0, 255);            // limit wiper setting to range of 0 to 255
  digitalWrite(csPin, LOW);                // select chip
  SPI.transfer(addr);                      // configure target pot with wiper position
  SPI.transfer(pos);
  digitalWrite(csPin, HIGH);               // de-select chip

  // print pot resistance between wiper and B terminal
  long resistanceWB = ((rAB * pos) / maxPositions ) + rWiper;
  Serial.print("Wiper position: ");
  Serial.print(pos);
  Serial.print(" Resistance wiper to B terminal: ");
  Serial.print(resistanceWB);
  Serial.println(" ohms");
}



void setup() {
  Serial.begin(9600);

 // Init Bluetooth
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
    
  mySerial.begin(baudrate);
  Serial.begin(baudrate);

  // Init ecran OLED 
  if(!ecranOLED.begin(SSD1306_SWITCHCAPVCC,adresseI2CecranOLED))
  while(1);   // Arrêt du programme (boucle infinie) si échec d'initialisation

  
  //Serial.println("ok");
  ecranOLED.clearDisplay();
  ecranOLED.setTextSize(2);
  delay(2000);
  ecranOLED.setCursor(0,0);
  ecranOLED.setTextColor(SSD1306_WHITE);
  
 // Digital pot 
  Serial.println("MCP41100 Demo");
  digitalWrite(csPin, HIGH);        // chip select default to de-selected
  pinMode(csPin, OUTPUT);           // configure chip select as output
  SPI.begin();   
  
  // mettre  le pot à la valeur souhaitée
  Serial.println("Pot 0 Control ");
  setPotWiper(pot0, 6); // réglage du pot à 2% de la R to (50k)
  delay(1000);

}
void loop() {


  //mesure capteur graphite 
  float mesure = analogRead(dataPin);  //recup valeur capteur 
  Serial.println("mesure capteur graphite ");
  Serial.println(mesure); //retoune la valeur en binaire de la tension 
  delay(1);
    
      // calcul
      mesure=(4.2/1023)*mesure;
      float resistance = ((1+(100))*100000*(VCC/mesure)-100000-10000);// changer capteur trop nulle l'autre
      Serial.println("R=");
      Serial.println(resistance); //retoune la valeur de résistance du capteur graphite 

      


      
  //mesure flex sensor
  float ADCflex = analogRead(dataPinF);  //recup valeur Flex sensor 
  //Serial.println("mesure Flex sensor ");
  //Serial.println(mesure1); //retoune la valeur 
  float Vflex = ADCflex * VCC / 1023.0;
  float Rflex = R_DIV * (VCC / Vflex - 1.0);
  float angle = map(Rflex, flatResistance, bendResistance, 0, 90.0); //calcul angle
  int deformationFlex = (angle/180.0)*100; 
  //deformationFlex=(int)deformationFlex;
  //Serial.println("Bend: " + String(angle) + " degrees");
  //Serial.println();

  delay(500);
  delay(1);
  
  // Affichage ecran OLED
      ecranOLED.clearDisplay();
      ecranOLED.println("R(Mohm)=");
      ecranOLED.setCursor(0,16);
      ecranOLED.println(resistance/1000000); 
;     
      ecranOLED.setCursor(0,32);
      ecranOLED.println("def flex");
      ecranOLED.setCursor(0,48);
      ecranOLED.println(deformationFlex); 
      ecranOLED.setCursor(100,48);
      ecranOLED.println("%"); 
         
      //Serial.print("lz");
      ecranOLED.display();
      ecranOLED.setCursor(0,0);
      delay(2000);

    //Envoi Bluetooth
    mySerial.println(resistance/1000000); 
    delay (500); 
  
}
