/*
- Project: 스택2020 척척추추
- 담당자: 양준혁
- 최종 수정일: 2020.09.04
*/

//헤더파일 선언부
#include <SoftwareSerial.h>
#include <Wire.h>

//define 선언부
#define MPU6050 0x68 //mpu6050 주소
#define Vibration 4 //진동 모듈 핀

//전역 변수 선언부
SoftwareSerial BTSerial(2, 3); //블루투스 모듈 HC-06 모듈 핀 설정 (TX, RX)

long acX, acY, acZ, gyX, gyY, gyZ; //가속도, 각속도 값을 저장하는 변수

double angle = 0, deg; //각도, deg data

double dgyX; //accData

//Millis
int c_millis = 0;
int p_millis = 0;

void setup() {               
  Serial.begin(9600); //pc와 연결

  //블루투스 연결
  BTSerial.begin(9600);

  //mpu6050 setup
  Wire.begin();  
  Wire.beginTransmission(MPU6050);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.write(0); 
  Wire.endTransmission(true);

  pinMode(Vibration, OUTPUT); //진동 모듈
}

void loop() {
  calAngleY(); //Y을 통해서 척추의 각도를 측정하는 함수를 실행
}
  
//------------------------------------------------

//MPU6050 상포필터 값을 통해서 척추의 각도를 측정하는함수
void calAngleY(){

  Wire.beginTransmission(MPU6050);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050, 6, 1);

  //가속도
  acX = Wire.read() << 8 | Wire.read();
  acY = Wire.read() << 8 | Wire.read();
  acZ = Wire.read() << 8 | Wire.read();

  Wire.beginTransmission(MPU6050);

  Wire.write(0x43);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050, 6, 1);

  //자이로
  gyX = Wire.read() << 8 | Wire.read();
  gyY = Wire.read() << 8 | Wire.read();
  gyZ = Wire.read() << 8 | Wire.read();

  //각도 계산
  deg = atan2(acX, acZ) * 180 /PI;
  dgyX = gyY / 131. ;
  angle = (0.95 * (angle + (dgyX * 0.001))) + (0.05 * deg);

  //출력
  Serial.println(angle);

  //안드로이드 기기에 각도 전송
  BTSerial.println(angle);
  
  workingVibration(); //진동 함수 호출
  
}

//진동을 처리하는함수
void workingVibration(){
  
  c_millis = millis();
  if(c_millis - p_millis > 3000){
    p_millis = c_millis;     
    if(angle < 80 || angle > 120){
      if(angle < 80 || angle > 120){
           analogWrite(Vibration, 800); //진동을 울린다.
           delay(300);
           analogWrite(Vibration, 0); //진동을 끈다.  
      }else{
           analogWrite(Vibration, 0); //진동을 끈다. 
      }
    }
  }
}
