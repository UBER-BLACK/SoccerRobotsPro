//GitHub: https://GitHub.com/UBER-BLACK/SoccerRobotsPro/
//LICENSE: https://raw.githubusercontent.com/UBER-BLACK/SoccerRobotsPro/main/LICENSE
//██╗░░░██╗██████╗░███████╗██████╗░░░░░░░██████╗░██╗░░░░░░█████╗░░█████╗░██╗░░██╗
//██║░░░██║██╔══██╗██╔════╝██╔══██╗░░░░░░██╔══██╗██║░░░░░██╔══██╗██╔══██╗██║░██╔╝
//██║░░░██║██████╦╝█████╗░░██████╔╝█████╗██████╦╝██║░░░░░███████║██║░░╚═╝█████═╝░
//██║░░░██║██╔══██╗██╔══╝░░██╔══██╗╚════╝██╔══██╗██║░░░░░██╔══██║██║░░██╗██╔═██╗░
//╚██████╔╝██████╦╝███████╗██║░░██║░░░░░░██████╦╝███████╗██║░░██║╚█████╔╝██║░╚██╗
//░╚═════╝░╚═════╝░╚══════╝╚═╝░░╚═╝░░░░░░╚═════╝░╚══════╝╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝




//SETTINGS
//PCMonitor
#define PC_Monitor_Bod 9600   // BOD 9600 - def 5000000 - debug
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
#define GamePad_Pressures false //CHECK FOR ERROR
#define GamePad_Rumble false    //CHECK FOR ERROR
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



//DEFINE
//GamePad
#define GamePad_NewState (GamePad.NewButtonState())
#define GamePad_Key_Start (GamePad.Button(PSB_START))
#define GamePad_Key_Select (GamePad.Button(PSB_SELECT))
#define GamePad_Pad_Up (GamePad.Button(PSB_PAD_UP))
#define GamePad_Pad_Right (GamePad.Button(PSB_PAD_RIGHT))
#define GamePad_Pad_Left (GamePad.Button(PSB_PAD_LEFT))
#define GamePad_Pad_Down (GamePad.Button(PSB_PAD_DOWN))
#define GamePad_Key_Blue (GamePad.ButtonPressed(PSB_BLUE))
#define GamePad_Key_Green (GamePad.ButtonPressed(PSB_GREEN))
#define GamePad_Key_Red (GamePad.ButtonPressed(PSB_RED))
#define GamePad_Key_Pink (GamePad.ButtonPressed(PSB_PINK))
#define GamePad_Trigger_L1 (GamePad.Button(PSB_L2))
#define GamePad_Trigger_L2 (GamePad.Button(PSB_L3))
#define GamePad_Trigger_R1 (GamePad.Button(PSB_R2))
#define GamePad_Trigger_R2 (GamePad.Button(PSB_R3))
#define GamePad_Stick_Left_Y (GamePad.Analog(PSS_LY))
#define GamePad_Stick_Left_X (GamePad.Analog(PSS_LX))
#define GamePad_Stick_Right_Y (GamePad.Analog(PSS_RY))
#define GamePad_Stick_Right_X (GamePad.Analog(PSS_RX))
#define GamePad_Stick_Left_Key (GamePad.Button(PSB_L1))
#define GamePad_Stick_Right_Key (GamePad.Button(PSB_R1))


//CLASS CREATION
GMotor MotorA(DRIVER3WIRE, MotorA_PINA, MotorA_PINB, MotorA_PWM, (Driver_Type)); //MotorA
GMotor MotorB(DRIVER3WIRE, MotorB_PINA, MotorB_PINB, MotorB_PWM, (Driver_Type)); //MotorB
GMotor MotorC(DRIVER3WIRE, MotorC_PINA, MotorC_PINB, MotorC_PWM, (Driver_Type)); //MotorC
GMotor Shaft(DRIVER3WIRE, Shaft_PINA, Shaft_PINB, Shaft_PWM, (Driver_Type));     //Shaft
PS2X GamePad;                                                                    //GamePad



//CREATE GLOBAL VARIABLES
//For lib "PS2X_lib.h"
int Number = 0;//GamePad Monitor
int error = 0;
byte type = 0;
byte vibrate = 0;
byte Gamepad_Vibration_Mode = false;
//Setup
byte setup_error = false;

void setup() {
  delay(1000);
  setup_pc_monitor();
  setup_motor_driver();
  setup_gamepad_driver();
  if (setup_error == false) {
    Serial.print("[OK] ");
  }
  else {
    Serial.print("[ERROR] ");
  }
  Serial.print("SETUP");
  delay(1000);
}
void setup_pc_monitor() {
  Serial.begin(PC_Monitor_Bod);
  Serial.println("[OK] PC MONITOR");
}
void setup_motor_driver() {
  pinMode(MotorPower, OUTPUT);
  //INSTALLING MOTOR DEADTIME
  MotorA.setDeadtime(Motor_Deadtime);
  MotorB.setDeadtime(Motor_Deadtime);
  MotorC.setDeadtime(Motor_Deadtime);
  Shaft.setDeadtime(Shaft_Deadtime);
  //INSTALLING MOTOR DIRECTIONS
  MotorA.setDirection(NORMAL);
  MotorB.setDirection(NORMAL);
  MotorC.setDirection(NORMAL);
  Shaft.setDirection(NORMAL);
  //INSTALLING MOTOR MODE
  MotorA.setMode(Motor_Mode);
  MotorB.setMode(Motor_Mode);
  MotorC.setMode(Motor_Mode);
  Shaft.setMode(Shaft_Mode);
  //INSTALLING MINIMAL POWER
  MotorA.setMinDuty(Motor_MinPower);
  MotorB.setMinDuty(Motor_MinPower);
  MotorC.setMinDuty(Motor_MinPower);
  Shaft.setMinDuty(Shaft_MinPower);
  //INSTALLING ACCELERATION
  MotorA.setSmoothSpeed(Motor_Acceleration);
  MotorB.setSmoothSpeed(Motor_Acceleration);
  MotorC.setSmoothSpeed(Motor_Acceleration);
  Shaft.setSmoothSpeed(Shaft_Acceleration);
  //POWER AUTOSTART
  digitalWrite(MotorPower, HIGH);
  Serial.println("[OK] Motor_Driver");
}
void setup_gamepad_driver() {
  error = GamePad.config_gamepad(GamePad_CLK, GamePad_CMD, GamePad_ATN, GamePad_DAT, GamePad_Pressures, GamePad_Rumble); //...Pressures?, Rumble?
  if (error > 0) {
    Serial.print("[ERROR] ");
    setup_error = true;
  }
  else {
    Serial.print("[OK] ");
  }
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
}



void loop() {
  //gamepad_monitor();        //GamePad Tester
  MotorA.setSpeed(255);
  MotorB.setSpeed(255);
  MotorC.setSpeed(255);
  Shaft.setSpeed(255);
  delay(10);                  //For Stability
}



//UTILITIES
void gamepad_monitor() {
  Serial.print("==============================REFRESH: ");Serial.println(Number);
  Serial.print("GamePad_Pressures        ");Serial.println(GamePad_Pressures);
  Serial.print("GamePad_Rumble           ");Serial.println(GamePad_Rumble);
  Serial.print("GamePad_NewState         ");Serial.println(GamePad_NewState);
  Serial.print("GamePad_Key_Start        ");Serial.println(GamePad_Key_Start);
  Serial.print("GamePad_Key_Select       ");Serial.println(GamePad_Key_Select);
  Serial.print("GamePad_Pad_Up           ");Serial.println(GamePad_Pad_Up);
  Serial.print("GamePad_Pad_Right        ");Serial.println(GamePad_Pad_Right);
  Serial.print("GamePad_Pad_Left         ");Serial.println(GamePad_Pad_Left);
  Serial.print("GamePad_Pad_Down         ");Serial.println(GamePad_Pad_Down);
  Serial.print("GamePad_Key_Red          ");Serial.println(GamePad_Key_Red);
  Serial.print("GamePad_Key_Pink         ");Serial.println(GamePad_Key_Pink);
  Serial.print("GamePad_Key_Blue         ");Serial.println(GamePad_Key_Blue);
  Serial.print("GamePad_Key_Green        ");Serial.println(GamePad_Key_Green);
  Serial.print("GamePad_Stick_Left_Y     ");Serial.println(GamePad_Stick_Left_Y);
  Serial.print("GamePad_Stick_Left_X     ");Serial.println(GamePad_Stick_Left_X);
  Serial.print("GamePad_Stick_Right_Y    ");Serial.println(GamePad_Stick_Right_Y);
  Serial.print("GamePad_Stick_Right_X    ");Serial.println(GamePad_Stick_Right_X);
  Serial.print("GamePad_Stick_Left_Key   ");Serial.println(GamePad_Stick_Left_Key);
  Serial.print("Gamepad_Stick_Right_Key  ");Serial.println(GamePad_Stick_Right_Key);
  Serial.print("GamePad_Trigger_L1       ");Serial.println(GamePad_Trigger_L1);
  Serial.print("GamePad_Trigger_L2       ");Serial.println(GamePad_Trigger_L2);
  Serial.print("GamePad_Trigger_R1       ");Serial.println(GamePad_Trigger_R1);
  Serial.print("GamePad_Trigger_R2       ");Serial.println(GamePad_Trigger_R2);
  Number++;
  delay(1000);
  }
