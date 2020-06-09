#include <SoftwareSerial.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

SoftwareSerial BTSerial(1, 0); //블루투스 모듈 HC-06 모듈 핀 설정 (TX, RX)

MPU6050 mpu6050(Wire);

float X;
float calX;


void setup() {               
  Serial.begin(9600); //pc와 연결

  //블루투스 연결
  BTSerial.begin(9600);

  Wire.begin();
  mpu6050.begin();      
}

void loop() {
  calAngleX();
}

//------------------------------------------------

//X값을 통해서 척추의 각도를 측정하는함수

void calAngleX(){
  mpu6050.update();
  calX = mpu6050.getAccAngleX();
  Serial.print("calX: ");
  Serial.println(calX);
  delay(100);
  if(calX > -60){
    delay (2000);
    mpu6050.update();
    calX = mpu6050.getAccAngleX();
    if(calX > -60){
      analogWrite(3, 200);
      BTSerial.println("10");
      delay (1000);
      analogWrite(3, 0);
    }
  }else{
    BTSerial.println("20");
  }
}
