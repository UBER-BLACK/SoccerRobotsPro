#include <GyverMotor.h> //https://alexgyver.ru/gyvermotor/



//SETTINGS
#define PCBod 9600
//MOTION
#define Driver_Type HIGH                  // HIGH or LOW
#define Motor_Deadtime 100                // MS 
#define Shaft_Deadtime 0                  // MS 
#define MotorA_Reverse NORMAL             // NORMAL / REVERSE
#define MotorB_Reverse NORMAL             // NORMAL / REVERSE
#define MotorC_Reverse NORMAL             // NORMAL / REVERSE
#define Shaft_Reverse NORMAL              // NORMAL / REVERSE
#define Motor_Mode AUTO                   // FORWARD AUTO BACKWARD BRAKE STOP
#define Shaft_Mode FORWARD                // FORWARD AUTO BACKWARD BRAKE STOP
#define Motor_MinPower 50                 // 0 255
#define Shaft_MinPower 50                 // 0 255

//PINS
#define GamePad_DAT 2
#define GamePad_CMD 3
#define GamePad_CLK 4
#define GamePad_ATN 5

#define MotorPower 8

#define MotorA_PWM 6
#define MotorA_PINA A0
#define MotorA_PINB A1

#define MotorB_PWM 9
#define MotorB_PINA A2
#define MotorB_PINB A3

#define MotorC_PWM 10
#define MotorC_PINA A4
#define MotorC_PINB A5

#define Shaft_PWM 11
#define Shaft_PINA 12
#define Shaft_PINB 13

#define Solinoid 7



//SETUP
void setup() {
  setup_pc_monitor();
  setup_motor_driver();
  Serial.println("SETUP: OK");
}
void setup_pc_monitor() {
  Serial.begin(PCBod);
  Serial.println("PC MONITOR: OK");
}
void setup_motor_driver() { //CHECK HIGH / LOW
  Serial.println("GyverMotor: Initialization...");
  GMotor MotorA(DRIVER3WIRE, MotorA_PINA, MotorA_PINB, MotorA_PWM, (Driver_Type));
  GMotor MotorB(DRIVER3WIRE, MotorB_PINA, MotorB_PINB, MotorB_PWM, (Driver_Type));
  GMotor MotorC(DRIVER3WIRE, MotorC_PINA, MotorC_PINB, MotorC_PWM, (Driver_Type));
  GMotor Shaft(DRIVER3WIRE, Shaft_PINA, Shaft_PINB, Shaft_PWM, (Driver_Type));

  Serial.println("GyverMotor: Installing motor deadtime");
  MotorA.setDeadtime(Motor_Deadtime);
  MotorB.setDeadtime(Motor_Deadtime);
  MotorC.setDeadtime(Motor_Deadtime);
  Shaft.setDeadtime(Shaft_Deadtime);

  Serial.println("GyverMotor: Installing motor direction");
  MotorA.setDirection(NORMAL);
  MotorB.setDirection(NORMAL);
  MotorC.setDirection(NORMAL);
  Shaft.setDirection(NORMAL);

  Serial.println("GyverMotor: Installing motor mode");
  MotorA.setMode(Motor_Mode);
  MotorB.setMode(Motor_Mode);
  MotorC.setMode(Motor_Mode);
  Shaft.setMode(Shaft_Mode);

  Serial.println("GyverMotor: Installing minimal power");
  MotorA.setMinDuty(Motor_MinPower);
  MotorB.setMinDuty(Motor_MinPower);
  MotorC.setMinDuty(Motor_MinPower);
  Serial.println("GyverMotor: OK");
}
