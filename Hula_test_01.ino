#include "DHT.h"
#define KGas A3
#define ASang 9
#define LMua 10

#define DHTPIN 5     // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
String Stringdata, LED1, LED2, LED3, REM, CUA, QUAT, hehe;
//String hehe
int quang, gas = 212, binh = 0;
char incomingByte;
int  temp = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  //  Serial.println(F("DHTxx test!"));
  dht.begin();
  //pinMode(A5,INPUT);
  pinMode(KGas, INPUT);
  pinMode(ASang, INPUT);
  pinMode(LMua, INPUT);
}

void loop() {

  // put your main code here, to run repeatedly:
  //digitalWrite(13,1);
  //delay(50);
  //digitalWrite(13,digitalRead(A5));
  //delay(100);
  //int bh=analogRead(Gas);//(9~29)đk binh thuong
  //Serial.println(bh);
  // int bh1=analogRead(ASang);//
  //Serial.println(bh1);
  //int bh2=analogRead(LMua);//
  //Serial.println(bh2);
  //test dht11
  /*
    CB_DOAM();
    if(t>20)
    {
    digitalWrite(13,1);
    delay(100);
    digitalWrite(13,0);
    delay(100);
    }
  */
  CB_DOAM();
  Receive_data();
  Send_data();
  if (LED1 == "ON");
  {
    Serial.println(212121212);
    digitalWrite(13, 1);
    //  delay(50);
    //  digitalWrite(13,1);
    //  delay(50);
  }
  if (LED1 == "OFF");
  {
    Serial.println(44444444);
    digitalWrite(13, 0);
    //  delay(50);
    //  digitalWrite(13,1);
    //  delay(50);
  }
  //  giaotiep();
}
void CB_DOAM()
{
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  temp = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(temp) || isnan(f)) {
    //    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(temp, h, false);

  //  Serial.print(F("Humidity: "));
  //  Serial.print(h);
  //  Serial.print(F("%  Temperature: "));
  //  Serial.print(t);
  //  Serial.print(F("°C "));

}
void Send_data() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    // look for the next valid integer in the incoming serial stream:
    //    int command = Serial.parseInt();
    // look for the newline. That's the end of your sentence:
    //
    if (Serial.available() > 0) {
      String hehe = Serial.readString();
      // xuất ra những gì nhận được
      //      Serial.print("Toi nghe duoc: ");
      //      Serial.print(hehe);
      int a = hehe.lastIndexOf('a');
      int b = hehe.lastIndexOf('b');
      int c = hehe.lastIndexOf('c');
      int d = hehe.lastIndexOf('d');
      int e = hehe.lastIndexOf('e');
      int g = hehe.lastIndexOf('g');
      int h = hehe.lastIndexOf('h');
      LED1 = hehe.substring(a + 1, b);
      LED2 = hehe.substring(b + 1, c);
      LED3 = hehe.substring(c + 1, d);
      REM = hehe.substring(d + 1, e);
      CUA = hehe.substring(e + 1, g);
      QUAT = hehe.substring(g + 1, h);
      Serial.println(LED1);
    }
  }
}
void Receive_data()
{

  Stringdata = "a" + String(temp) + "b" + String(gas) + "c";
  //  Serial.println(Stringdata);
}
// void recvWithStartEndMarkers() {
//  static boolean recvInProgress = false;
//  static byte ndx = 0;
//  char startMarker = '<';
//  char endMarker = '>';
//  char rc;
//
//  while (Serial.available() > 0 && newData == false) {
//    rc = Serial.read();
//
//    if (recvInProgress == true) {
//      if (rc != endMarker) {
//        receivedChars[ndx] = rc;
//        ndx++;
//        if (ndx >= numChars) {
//          ndx = numChars - 1;
//        }
//      }
//      else {
//        receivedChars[ndx] = '\0'; // terminate the string
//        recvInProgress = false;
//        ndx = 0;
//        newData = true;
//      }
//    }
//
//    else if (rc == startMarker) {
//      recvInProgress = true;
//    }
//  }
//}
