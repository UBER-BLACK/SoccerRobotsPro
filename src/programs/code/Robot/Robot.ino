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
#define PC_Monitor_Bod 500000   // BOD 9600 - def 500000 - debug
//MotorDriver
#define Driver_Type HIGH        // HIGH / LOW
#define Motor_Deadtime 70       // MS 
#define Shaft_Deadtime 5        // MS 
#define MotorA_Reverse NORMAL   // NORMAL / REVERSE
#define MotorB_Reverse NORMAL   // NORMAL / REVERSE
#define MotorC_Reverse NORMAL   // NORMAL / REVERSE
#define Shaft_Reverse NORMAL    // NORMAL / REVERSE
#define Motor_Mode AUTO         // FORWARD / AUTO / BACKWARD / BRAKE / STOP
#define Shaft_Mode FORWARD      // FORWARD / AUTO / BACKWARD / BRAKE / STOP
#define Motor_MinPower 50       // 0-255
#define Shaft_MinPower 50       // 0-255
#define Motor_Acceleration 10   // MS
#define Shaft_Acceleration 5    // MS



//CONNECTING LIBRARIES
#include <GyverMotor.h> //https://alexgyver.ru/gyvermotor/#include
#include <PS2X_lib.h>



//OUTPUTS SETTINGS
//GamePad
#define Gamepad_Pressures false //CHECK FOR ERROR
#define Gamepad_Rumble false    //CHECK FOR ERROR
#define Gamepad_DAT 2           //Data
#define Gamepad_CMD 3           //Command
#define Gamepad_CLK 4           //Clock
#define Gamepad_ATN 5           //Attention
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
#define Gamepad_NewState (Gamepad.NewButtonState())
#define Gamepad_Type (Gamepad.readType())
#define Gamepad_Key_Start (Gamepad.Button(PSB_START))
#define Gamepad_Key_Select (Gamepad.Button(PSB_SELECT))
#define Gamepad_Pad_Up (Gamepad.Button(PSB_PAD_UP))
#define Gamepad_Pad_Right (Gamepad.Button(PSB_PAD_RIGHT))
#define Gamepad_Pad_Left (Gamepad.Button(PSB_PAD_LEFT))
#define Gamepad_Pad_Down (Gamepad.Button(PSB_PAD_DOWN))
#define Gamepad_Key_Blue (Gamepad.ButtonPressed(PSB_BLUE))
#define Gamepad_Key_Green (Gamepad.ButtonPressed(PSB_GREEN))
#define Gamepad_Key_Red (Gamepad.ButtonPressed(PSB_RED))
#define Gamepad_Key_Pink (Gamepad.ButtonPressed(PSB_PINK))
#define Gamepad_Trigger_L1 (Gamepad.Button(PSB_L2))
#define Gamepad_Trigger_L2 (Gamepad.Button(PSB_L3))
#define Gamepad_Trigger_R1 (Gamepad.Button(PSB_R2))
#define Gamepad_Trigger_R2 (Gamepad.Button(PSB_R3))
#define Gamepad_Stick_Left_Y (Gamepad.Analog(PSS_LY))
#define Gamepad_Stick_Left_X (Gamepad.Analog(PSS_LX))
#define Gamepad_Stick_Right_Y (Gamepad.Analog(PSS_RY))
#define Gamepad_Stick_Right_X (Gamepad.Analog(PSS_RX))
#define Gamepad_Stick_Left_Key (Gamepad.Button(PSB_L1))
#define Gamepad_Stick_Right_Key (Gamepad.Button(PSB_R1))



//CLASS CREATION
GMotor MotorA(DRIVER3WIRE, MotorA_PINA, MotorA_PINB, MotorA_PWM, (Driver_Type)); //MotorA
GMotor MotorB(DRIVER3WIRE, MotorB_PINA, MotorB_PINB, MotorB_PWM, (Driver_Type)); //MotorB
GMotor MotorC(DRIVER3WIRE, MotorC_PINA, MotorC_PINB, MotorC_PWM, (Driver_Type)); //MotorC
GMotor Shaft(DRIVER3WIRE, Shaft_PINA, Shaft_PINB, Shaft_PWM, (Driver_Type));     //Shaft
PS2X Gamepad;                                                                    //GamePad



//CREATE GLOBAL VARIABLES
//For lib "PS2X_lib.h"
int Number = 0;//GamePad Monitor
int error = 0;
byte type = 0;
byte vibrate = 0;
//Setup
byte setup_error = false;



void setup() {
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
  delay(2000);
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
  //POWER ON
  digitalWrite(MotorPower, HIGH);
  //TEST MOTORS
  MotorA.setSpeed(255);
  delay(100);
  MotorA.setSpeed(-255);
  delay(100);
  MotorA.setSpeed(0);
  MotorB.setSpeed(255);
  delay(100);
  MotorB.setSpeed(-255);
  delay(100);
  MotorB.setSpeed(0);
  MotorC.setSpeed(255);
  delay(100);
  MotorC.setSpeed(-255);
  delay(100);
  MotorC.setSpeed(0);
  Shaft.setSpeed(255);
  delay(100);
  Shaft.setSpeed(-255);
  delay(100);
  Shaft.setSpeed(0);
  Serial.println("[OK] Motor_Driver");
}
void setup_gamepad_driver() {
  error = Gamepad.config_gamepad(Gamepad_CLK, Gamepad_CMD, Gamepad_ATN, Gamepad_DAT, Gamepad_Pressures, Gamepad_Rumble); //...Pressures?, Rumble?
  if (error > 0) {
    Serial.print("[ERROR] ");
    setup_error = true;
  }
  else {
    Serial.print("[OK] ");
  }
  if (error == 0) {
    Serial.print("Gamepad_Driver: Found Controller");
    if (Gamepad_Type == 0 or Gamepad_Type >= 2) {
      Serial.println(" Type: Unknown");
    }
    else if (Gamepad.readType() == 1) {
      Serial.println(" Type: Dualshock (PS1/PS2)");
    }
  }
  else if (error == 1) {
    Serial.println("Gamepad_Driver: No controller found");
  }
  else if (error == 2) {
    Serial.println("Gamepad_Driver: Found but not accepting commands");
  }
  else if (error == 3) {
    Serial.println("Gamepad_Driver: Controller refusing to enter Pressures mode");
  }
}


//MAIN CODE
void loop() {
  //gamepad_monitor();        //GamePad Tester
  delay(10);                  //For Stability
}



//UTILITIES
void gamepad_monitor() {
  Serial.print("==============================REFRESH: "); Serial.println(Number);
  Serial.println("* Settings:");
  Serial.print("Gamepad_Pressures        "); Serial.println(Gamepad_Pressures);
  Serial.print("Gamepad_Rumble           "); Serial.println(Gamepad_Rumble);
  Serial.println("* Pad:");
  Serial.print("Gamepad_Pad_Up           "); Serial.println(Gamepad_Pad_Up);
  Serial.print("Gamepad_Pad_Right        "); Serial.println(Gamepad_Pad_Right);
  Serial.print("Gamepad_Pad_Left         "); Serial.println(Gamepad_Pad_Left);
  Serial.print("Gamepad_Pad_Down         "); Serial.println(Gamepad_Pad_Down);
  Serial.println("* Keys:");
  Serial.print("Gamepad_Key_Red          "); Serial.println(Gamepad_Key_Red);
  Serial.print("Gamepad_Key_Pink         "); Serial.println(Gamepad_Key_Pink);
  Serial.print("Gamepad_Key_Blue         "); Serial.println(Gamepad_Key_Blue);
  Serial.print("Gamepad_Key_Green        "); Serial.println(Gamepad_Key_Green);
  Serial.print("Gamepad_Key_Start        "); Serial.println(Gamepad_Key_Start);
  Serial.print("Gamepad_Key_Select       "); Serial.println(Gamepad_Key_Select);
  Serial.println("* Sticks:");
  Serial.print("Gamepad_Stick_Left_Y     "); Serial.println(Gamepad_Stick_Left_Y);
  Serial.print("Gamepad_Stick_Left_X     "); Serial.println(Gamepad_Stick_Left_X);
  Serial.print("Gamepad_Stick_Right_Y    "); Serial.println(Gamepad_Stick_Right_Y);
  Serial.print("Gamepad_Stick_Right_X    "); Serial.println(Gamepad_Stick_Right_X);
  Serial.print("Gamepad_Stick_Left_Key   "); Serial.println(Gamepad_Stick_Left_Key);
  Serial.print("Gamepad_Stick_Right_Key  "); Serial.println(Gamepad_Stick_Right_Key);
  Serial.println("* Triggers:");
  Serial.print("Gamepad_Trigger_L1       "); Serial.println(Gamepad_Trigger_L1);
  Serial.print("Gamepad_Trigger_L2       "); Serial.println(Gamepad_Trigger_L2);
  Serial.print("Gamepad_Trigger_R1       "); Serial.println(Gamepad_Trigger_R1);
  Serial.print("Gamepad_Trigger_R2       "); Serial.println(Gamepad_Trigger_R2);
  Serial.println("* Other:");
  Serial.print("Gamepad_NewState         "); Serial.println(Gamepad_NewState);
  Serial.print("Gamepad_Type             "); Serial.println(Gamepad_Type);
  Number++;
  delay(1000);
}
//THE END?
