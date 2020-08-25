/*

- Project: 스택2020 척척추추
- 담당자: 양준혁
- 최종 수정일: 2020.08.25

*/

#include <SoftwareSerial.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

SoftwareSerial BTSerial(1, 0); //블루투스 모듈 HC-06 모듈 핀 설정 (TX, RX)

MPU6050 mpu6050(Wire); //mpu6050 객체 생성

float calY; //mpu6050에서 받아온 Y값을 저장하는 변수
float Y;

void setup() {               
  Serial.begin(9600); //pc와 연결

  //블루투스 연결
  BTSerial.begin(9600);

  //mpu6050 라이브러리 시작
  Wire.begin();
  mpu6050.begin();      

  pinMode(3, OUTPUT);
}

void loop() {
  calAngleY(); //Y을 통해서 척추의 각도를 측정하는 함수를 실행
}
  
//------------------------------------------------

//Y값을 통해서 척추의 각도를 측정하는함수
void calAngleY(){
  mpu6050.update(); //mpu6050 값을 업데이트 해줌
  calY = mpu6050.getAccX(); //mpu6050에서 받아온 각도를 저장하는 과정

  Serial.print("calY: "); 
  Serial.println(calY);
  delay(100);

  //각도를 비교해서 -60도가 넘어가면 코드 실행
  if(calY < -0.05 || calY > 0.60){

    delay (2000);
    mpu6050.update();
    calY = mpu6050.getAccY();
    

    //다시한번 각도를 비교해서 -60도가 넘어가면 코드 실행(척추 각도 비정상)
    if(calY < -0.05 || calY > 0.60){ 
      analogWrite(3, 300); //진동을 울린다.
      BTSerial.println("10"); //안드로이드로 10을 블루투스로 전송한다.
      delay (1000);
      analogWrite(3, 0); //진동을 끈다.
    }
  }
  //-60도를 넘어가지 않았다면 코드 실행(척추 각도 정상)
  else{ 
    BTSerial.println("20"); //안드로이드로 20을 전송한다.
  }
}
