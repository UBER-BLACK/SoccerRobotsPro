//https://GitHub.com/UBER-BLACK//SoccerRobotsPro
//██╗░░░██╗██████╗░███████╗██████╗░░░░░░░██████╗░██╗░░░░░░█████╗░░█████╗░██╗░░██╗
//██║░░░██║██╔══██╗██╔════╝██╔══██╗░░░░░░██╔══██╗██║░░░░░██╔══██╗██╔══██╗██║░██╔╝
//██║░░░██║██████╦╝█████╗░░██████╔╝█████╗██████╦╝██║░░░░░███████║██║░░╚═╝█████═╝░
//██║░░░██║██╔══██╗██╔══╝░░██╔══██╗╚════╝██╔══██╗██║░░░░░██╔══██║██║░░██╗██╔═██╗░
//╚██████╔╝██████╦╝███████╗██║░░██║░░░░░░██████╦╝███████╗██║░░██║╚█████╔╝██║░╚██╗
//░╚═════╝░╚═════╝░╚══════╝╚═╝░░╚═╝░░░░░░╚═════╝░╚══════╝╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝



//SETTINGS
//PCMonitor
#define PC_Monitor_Bod 2400     // BOD
//MotorDriver
#define Driver_Type HIGH        // HIGH or LOW
#define Motor_Deadtime 70       // MS 
#define Shaft_Deadtime 5        // MS 
#define MotorA_Reverse NORMAL   // NORMAL / REVERSE
#define MotorB_Reverse NORMAL   // NORMAL / REVERSE
#define MotorC_Reverse NORMAL   // NORMAL / REVERSE
#define Shaft_Reverse NORMAL    // NORMAL / REVERSE
#define Motor_Mode AUTO         // FORWARD AUTO BACKWARD BRAKE STOP
#define Shaft_Mode FORWARD      // FORWARD AUTO BACKWARD BRAKE STOP
#define Motor_MinPower 50       // 0 255
#define Shaft_MinPower 50       // 0 255
#define Motor_Acceleration 10   // 0 255
#define Shaft_Acceleration 5    // 0 255


//CONNECTING LIBRARIES
#include <GyverMotor.h> //https://alexgyver.ru/gyvermotor/#include



//OUTPUTS SETTINGS
//GamePad
#define GamePad_DAT 2           //Data
#define GamePad_CMD 3           //Command
#define GamePad_CLK 4           //Clock
#define GamePad_ATN 5           //Attention
//MotorDriver
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
//Mosfet
#define Solinoid 7



//MOTORS INITIALIZATION
GMotor MotorA(DRIVER3WIRE, MotorA_PINA, MotorA_PINB, MotorA_PWM, (Driver_Type)); //MotorA
GMotor MotorB(DRIVER3WIRE, MotorB_PINA, MotorB_PINB, MotorB_PWM, (Driver_Type)); //MotorB
GMotor MotorC(DRIVER3WIRE, MotorC_PINA, MotorC_PINB, MotorC_PWM, (Driver_Type)); //MotorC
GMotor Shaft(DRIVER3WIRE, Shaft_PINA, Shaft_PINB, Shaft_PWM, (Driver_Type));     //Shaft



void setup() {
  setup_pc_monitor();
  setup_motor_driver();
  Serial.println("SETUP: OK");
}
void setup_pc_monitor() {
  Serial.begin(PC_Monitor_Bod);
  Serial.println("################################################################");
  Serial.println("RAM: OK"); //PONT
  Serial.println("ROM: OK"); //PONT
  Serial.println("PC MONITOR: OK");
}
void setup_motor_driver() { //CHECK HIGH / LOW
  Serial.println("Motor_Driver: Initialization...");
  pinMode(MotorPower,OUTPUT);
  //INSTALLING MOTOR DEADTIME
  Serial.println("Motor_Driver: Installing motor deadtime");
  MotorA.setDeadtime(Motor_Deadtime);
  MotorB.setDeadtime(Motor_Deadtime);
  MotorC.setDeadtime(Motor_Deadtime);
  Shaft.setDeadtime(Shaft_Deadtime);
  //INSTALLING MOTOR DIRECTIONS
  Serial.println("Motor_Driver: Installing motor direction");
  MotorA.setDirection(NORMAL);
  MotorB.setDirection(NORMAL);
  MotorC.setDirection(NORMAL);
  Shaft.setDirection(NORMAL);
  //INSTALLING MOTOR MODE
  Serial.println("Motor_Driver: Installing motor mode");
  MotorA.setMode(Motor_Mode);
  MotorB.setMode(Motor_Mode);
  MotorC.setMode(Motor_Mode);
  Shaft.setMode(Shaft_Mode);
  //INSTALLING MINIMAL POWER
  Serial.println("Motor_Driver: Installing minimal power");
  MotorA.setMinDuty(Motor_MinPower);
  MotorB.setMinDuty(Motor_MinPower);
  MotorC.setMinDuty(Motor_MinPower);
  Shaft.setMinDuty(Shaft_MinPower);
  //INSTALLING ACCELERATION
  Serial.println("Motor_Driver: Installing acceleration");
  MotorA.setSmoothSpeed(Motor_Acceleration);
  MotorB.setSmoothSpeed(Motor_Acceleration);
  MotorC.setSmoothSpeed(Motor_Acceleration);
  Shaft.setSmoothSpeed(Shaft_Acceleration);
  //POWER AUTOSTART
  Serial.println("Motor_Driver: Power autostart");
  digitalWrite(MotorPower,HIGH);
  Serial.println("Motor_Driver: OK");
}



void loop() {
  MotorA.setSpeed(120);

}
