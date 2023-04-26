//https://GitHub.com/UBER-BLACK//SoccerRobotsPro
//██╗░░░██╗██████╗░███████╗██████╗░░░░░░░██████╗░██╗░░░░░░█████╗░░█████╗░██╗░░██╗
//██║░░░██║██╔══██╗██╔════╝██╔══██╗░░░░░░██╔══██╗██║░░░░░██╔══██╗██╔══██╗██║░██╔╝
//██║░░░██║██████╦╝█████╗░░██████╔╝█████╗██████╦╝██║░░░░░███████║██║░░╚═╝█████═╝░
//██║░░░██║██╔══██╗██╔══╝░░██╔══██╗╚════╝██╔══██╗██║░░░░░██╔══██║██║░░██╗██╔═██╗░
//╚██████╔╝██████╦╝███████╗██║░░██║░░░░░░██████╦╝███████╗██║░░██║╚█████╔╝██║░╚██╗
//░╚═════╝░╚═════╝░╚══════╝╚═╝░░╚═╝░░░░░░╚═════╝░╚══════╝╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝



//SETTINGS
//PCMonitor
#define PC_Monitor_Bod 9600     // BOD
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
#include <PS2X_lib.h>



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



//CLASS CREATION
GMotor MotorA(DRIVER3WIRE, MotorA_PINA, MotorA_PINB, MotorA_PWM, (Driver_Type)); //MotorA
GMotor MotorB(DRIVER3WIRE, MotorB_PINA, MotorB_PINB, MotorB_PWM, (Driver_Type)); //MotorB
GMotor MotorC(DRIVER3WIRE, MotorC_PINA, MotorC_PINB, MotorC_PWM, (Driver_Type)); //MotorC
GMotor Shaft(DRIVER3WIRE, Shaft_PINA, Shaft_PINB, Shaft_PWM, (Driver_Type));     //Shaft
PS2X GamePad;



//CREATE GLOBAL VARIABLES
//FOR LIB "PS2X_lib.h"
int error = 0;
byte type = 0;
byte vibrate = 0;
byte GamePad_NewState = false;
byte GamePad_Key_Start = false;
byte GamePad_Key_Select = false;
byte GamePad_Pad_Up = false;
byte GamePad_Pad_Right = false;
byte GamePad_Pad_Left = false;
byte GamePad_Pad_Down = false;
byte GamePad_Key_Blue = false;
byte GamePad_Key_Green = false;
byte GamePad_Key_Red = false;
byte GamePad_Key_Pink = false;
byte GamePad_Trigger_L1 = false;
byte GamePad_Trigger_L2 = false;
byte GamePad_Trigger_R1 = false;
byte GamePad_Trigger_R2 = false;
int Gamepad_Stick_Left_Y = 0;
int Gamepad_Stick_Left_X = 0;
int Gamepad_Stick_Right_Y = 0;
int Gamepad_Stick_Right_X = 0;
byte Gamepad_Stick_Left_Key = false;
byte Gamepad_Stick_Right_Key = false;
byte Gamepad_Vibration = false;
byte Gamepad_Vibration_Mode = false;

void setup() {
  setup_pc_monitor();
  setup_motor_driver();
  setup_gamepad_driver();
  Serial.println("SETUP: OK");
}
void setup_pc_monitor() {
  Serial.begin(PC_Monitor_Bod);
  Serial.println("################################################################");
  Serial.println("RAM: OK"); //PONT
  Serial.println("ROM: OK"); //PONT
  Serial.println("PC MONITOR: OK");
}
void setup_motor_driver() {
  Serial.println("Motor_Driver: Initialization...");
  pinMode(MotorPower, OUTPUT);
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
  digitalWrite(MotorPower, HIGH);
  Serial.println("Motor_Driver: OK");
}
void setup_gamepad_driver() {
  Serial.println("GamePad_Driver: Initialization...");
  error = GamePad.config_gamepad(GamePad_CLK, GamePad_CMD, GamePad_ATN, GamePad_DAT, true, true); //...Pressures?, Rumble?
  if (error == 0) {
    Serial.print("GamePad_Driver: Found Controller");
    if (GamePad.readType() == 0) {
      Serial.println(" Type: Unknown");
    }
    else if (GamePad.readType() == 1) {
      Serial.println(" Type: DualShock (PS1/PS2)");
    }
  }
  else if (error == 1) {
    Serial.println("GamePad_Driver: No controller found");
  }
  else if (error == 2) {
    Serial.println("GamePad_Driver: Found but not accepting commands");
  }
  else if (error == 3) {
    Serial.println("GamePad_Driver: Controller refusing to enter Pressures mode");
  }
  if (error > 0) {
    Serial.println("GamePad_Driver: ERROR");
  }
  else {
    Serial.println("GamePad_Driver: OK");
  }
}



void loop() {
  gamepad_driver();
  MotorA.setSpeed(255);
  MotorB.setSpeed(255);
  MotorC.setSpeed(255);
  Shaft.setSpeed(255);
  //gamepad_test();
  delay(10); //FOR STABILITY
}



//UTILITIES
void gamepad_driver() {
  GamePad.read_gamepad(Gamepad_Vibration_Mode, Gamepad_Vibration);
  GamePad_NewState = GamePad.NewButtonState();
  GamePad_Key_Start =  GamePad.Button(PSB_START);
  GamePad_Key_Select = GamePad.Button(PSB_SELECT);
  GamePad_Pad_Up = GamePad.Button(PSB_PAD_UP);
  GamePad_Pad_Right = GamePad.Button(PSB_PAD_RIGHT);
  GamePad_Pad_Left = GamePad.Button(PSB_PAD_LEFT);
  GamePad_Pad_Down = GamePad.Button(PSB_PAD_DOWN);
  GamePad_Key_Red = GamePad.ButtonPressed(PSB_RED);
  GamePad_Key_Pink = GamePad.ButtonReleased(PSB_PINK);
  GamePad_Key_Blue = GamePad.ButtonReleased(PSB_BLUE);
  GamePad_Key_Green = GamePad.ButtonReleased(PSB_GREEN);
  Gamepad_Stick_Left_Y = (GamePad.Analog(PSS_LY), DEC);
  Gamepad_Stick_Left_X = (GamePad.Analog(PSS_LX), DEC);
  Gamepad_Stick_Right_Y = (GamePad.Analog(PSS_RY), DEC);
  Gamepad_Stick_Right_X = (GamePad.Analog(PSS_RX), DEC);
  Gamepad_Stick_Left_Key = GamePad.Button(PSB_L1);
  Gamepad_Stick_Right_Key = GamePad.Button(PSB_R1);
  GamePad_Trigger_L1 = GamePad.Button(PSB_L2);
  GamePad_Trigger_L2 = GamePad.Button(PSB_L3);
  GamePad_Trigger_R1 = GamePad.Button(PSB_R2);
  GamePad_Trigger_R2 = GamePad.Button(PSB_R3);
  Gamepad_Vibration = GamePad_Key_Blue;
}
/*
void gamepad_test() {
  Serial.print("GamePad_NewState: "); Serial.println(GamePad_NewState);
  Serial.print("GamePad_Key_Start: "); Serial.println(GamePad_Key_Start);
  Serial.print("GamePad_Key_Select: "); Serial.println(GamePad_Key_Select);
  Serial.print("GamePad_Pad_Up: "); Serial.println(GamePad_Pad_Up);
  Serial.print("GamePad_Pad_Right: "); Serial.println(GamePad_Pad_Right);
  Serial.print("GamePad_Pad_Left: "); Serial.println(GamePad_Pad_Left);
  Serial.print("GamePad_Pad_Down: "); Serial.println(GamePad_Pad_Down);
  Serial.print("GamePad_Key_Red: "); Serial.println(GamePad_Key_Red);
  Serial.print("GamePad_Key_Pink: "); Serial.println(GamePad_Key_Pink);
  Serial.print("GamePad_Key_Blue: "); Serial.println(GamePad_Key_Blue);
  Serial.print("GamePad_Key_Green: "); Serial.println(GamePad_Key_Green);
  Serial.print("Gamepad_Stick_Left_Y: "); Serial.println(Gamepad_Stick_Left_Y);
  Serial.print("Gamepad_Stick_Left_X: "); Serial.println(Gamepad_Stick_Left_X);
  Serial.print("Gamepad_Stick_Right_Y: "); Serial.println(Gamepad_Stick_Right_Y);
  Serial.print("Gamepad_Stick_Right_X: "); Serial.println(Gamepad_Stick_Right_X);
  Serial.print("Gamepad_Stick_Left_Key: "); Serial.println(Gamepad_Stick_Left_Key);
  Serial.print("Gamepad_Stick_Right_Key: "); Serial.println(Gamepad_Stick_Right_Key);
  Serial.print("GamePad_Trigger_L1: "); Serial.println(GamePad_Trigger_L1);
  Serial.print("GamePad_Trigger_L2: "); Serial.println(GamePad_Trigger_L2);
  Serial.print("GamePad_Trigger_R1: "); Serial.println(GamePad_Trigger_R1);
  Serial.print("GamePad_Trigger_R2: "); Serial.println(GamePad_Trigger_R2);
  Serial.print("Gamepad_Vibration: "); Serial.println(Gamepad_Vibration);
  Serial.print("Gamepad_Vibration_Mode: "); Serial.println(Gamepad_Vibration_Mode);
}*/
