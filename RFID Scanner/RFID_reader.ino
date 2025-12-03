#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

// LED & buzzer pins
int greenLed = 7;
int redLed   = 8;
int buzzer   = 6;

// Enter your authorized UID here after testing
String authorizedUID = "99 6E 0D 06"; // placeholder

String getUID() {
  String uid = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) uid += "0";
    uid += String(mfrc522.uid.uidByte[i], HEX);
    if (i < mfrc522.uid.size - 1) uid += " ";
  }
  uid.toUpperCase();
  return uid;
}

void setup() {
  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();

  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, LOW);
  digitalWrite(buzzer, LOW);

  Serial.println("RFID Ready... Scan a card!");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  String uid = getUID();
  Serial.print("Card UID: ");
  Serial.println(uid);

  if (uid == authorizedUID) {
    // AUTHORIZED → green LED
    digitalWrite(greenLed, HIGH);
    tone(buzzer, 1500, 150);
    delay(500);
    digitalWrite(greenLed, LOW);
  } else {
    // UNAUTHORIZED → ***RED LED SHOULD TURN ON HERE***
    digitalWrite(redLed, HIGH);
    tone(buzzer, 700, 200);
    delay(600);
    digitalWrite(redLed, LOW);
  }

  delay(200);
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}
