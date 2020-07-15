# 스마틴 2020 - 척척추추 서비스
스택 2020년 프로젝트를 정리하는 문서


[프로젝트: 척척추추]


[프로젝트 소개]: 최근 현대인들의 척추 건강은 날이 갈 수록 나빠지고 있다. 그리고 척추 건강은 현대인들의 자세와 관련이 있다는 것을 알게 되었다.
많은 사람들은 자세에 중요성은 물론 어떤 자세가 올바른 자세인지도 모른다. 그래서 우리 팀에서는 올바른 자세의 척추 각도와 사용자의 척추 각도를 비교해서
사용자가 올바른 자세를 유지 할 수 있도록 도와주는 '척척추추 스마트 벨트' 를 만들게 되었다.


[기능]
1. 사용자의 척추 각도와 올바른 자세의 척추 각도를 비교해 올바르지 못한 각도를 2초이상 유지 했을 경우 진동을 통해 사용자에게 알려준다.
2. 사용자의 각도를 블루투스를 통해 스마트폰으로 보내면 스마트폰 어플리케이션에서 현재 각도 자세를 보여준다.
3. 어플리케이션에서 날마다 자세 각도의 평균을 기록해서 사용자에게 보여준다.
4. 어플리케이션에서 스트레칭 시간을 입력받아서 해당 시간마다 스트레칭을 할 수 있도록 유도 해주는 알람과 진동을 보내준다.
5. 스트레칭과 관련된 컨텐츠를 어플리케이션에서 소개해준다.


[경쟁(유사) 서비스 대비 차별화 요소] 
1. “척척추추”프로젝트는 바른 자세를 유도하는 것에 초점이 맞춰져 있습니다. 움직임이 적은 현대인에게 올바른 자세로 유도해줍니다.
2. 올바른 자세 뿐만 아니라 적절한 스트레칭 또한 척추 질환 예방에 효과적입니다. 일정 시간 이상 자리에 앉아 있는 경우 효과적인 스트레칭을 추천해주어 질병을 예방합니다.
3. 현 자세 상태를 시각화 하여 보여줌으로써 빠른 이해가 가능합니다.

[사용 툴/언어]
Arduino IDE (language: C/C++)
VS code (language: flutter)

[보드]
Arduino Nano

[센서/모듈]
MPU6050(각속도/가속도)
진동 모듈
블루투스 모듈(HC-06)
