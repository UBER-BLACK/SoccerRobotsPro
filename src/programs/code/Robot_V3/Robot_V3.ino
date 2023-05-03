//GitHub: https://GitHub.com/UBER-BLACK/SoccerRobotsPro/
//LICENSE: https://raw.githubusercontent.com/UBER-BLACK/SoccerRobotsPro/main/LICENSE
//██╗░░░██╗██████╗░███████╗██████╗░░░░░░░██████╗░██╗░░░░░░█████╗░░█████╗░██╗░░██╗
//██║░░░██║██╔══██╗██╔════╝██╔══██╗░░░░░░██╔══██╗██║░░░░░██╔══██╗██╔══██╗██║░██╔╝
//██║░░░██║██████╦╝█████╗░░██████╔╝█████╗██████╦╝██║░░░░░███████║██║░░╚═╝█████═╝░
//██║░░░██║██╔══██╗██╔══╝░░██╔══██╗╚════╝██╔══██╗██║░░░░░██╔══██║██║░░██╗██╔═██╗░
//╚██████╔╝██████╦╝███████╗██║░░██║░░░░░░██████╦╝███████╗██║░░██║╚█████╔╝██║░╚██╗
//░╚═════╝░╚═════╝░╚══════╝╚═╝░░╚═╝░░░░░░╚═════╝░╚══════╝╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝
//by THEBIGMISHA & MR_Prepod



//SETTINGS
//////////////////////////////////////////////////////////////////////////////////////////////////////
//            NAME            //        VALUE       //                     DESCRIPTION              //
#define PC_Console_Debug        false                //Debug mode
#define PC_Console_Speed        500000              //Information exchange rate.
#define Gamepad_Pressures       false               //!!!Check For Error!!!     
#define Gamepad_Rumble          false               //!!!Check For Error!!!
#define Gamepad_Pin_Data        2                   //Gamepad Data Contact
#define Gamepad_Pin_Command     3                   //Gamepad Command Contact
#define Gamepad_Pin_Clock       4                   //Gamepad Clock Contact
#define Gamepad_Pin_Attention   5                   //Gamepad Attention Contact
#define Motor_Type              HIGH                //Whatever works best for you
#define Motor_Test              true                //--
#define Motor_Power             8                   //Motor Driver Stendby Contact
#define Motor_Right_Reverse     false               //--
#define Motor_Right_Power       6                   //--
#define Motor_Right_Pin_A       A0                  //--
#define Motor_Right_Pin_B       A1                  //--
#define Motor_Left_Reverse      false               //--
#define Motor_Left_Power        9                   //--
#define Motor_Left_Pin_A        A2                  //--
#define Motor_Left_Pin_B        A3                  //--
#define Motor_Back_Reverse      false               //--
#define Motor_Back_Power        10                  //--
#define Motor_Back_Pin_A        A4                  //--
#define Motor_Back_Pin_B        A5                  //--
#define Shaft_Reverse           false               //--
#define Shaft_Power             11                  //--
#define Shaft_Pin_A             12                  //--
#define Shaft_Pin_B             13                  //--
#define Solinoid                7                   //--
//////////////////////////////////////////////////////////////////////////////////////////////////////



//INCLUDE LIBS
#include <PS2X_lib.h>     //By (NONAME)
#include <GyverMotor2.h>  //By AlexGyver                      



//CLASES
GMotor2<DRIVER3WIRE> MotorR(Motor_Right_Pin_A,  Motor_Right_Pin_B, Motor_Right_Power);
GMotor2<DRIVER3WIRE> MotorL(Motor_Left_Pin_A,   Motor_Left_Pin_B,  Motor_Left_Power);
GMotor2<DRIVER3WIRE> MotorB(Motor_Back_Pin_A,   Motor_Back_Pin_B,  Motor_Back_Power);
GMotor2<DRIVER3WIRE> Shaft(Shaft_Pin_A,         Shaft_Pin_B,       Shaft_Power);
PS2X Gamepad;



//SETUPS
void setup() {
  if (setup_pc_monitor() == true)Serial.println("[OK] PC Console");
  if (setup_motor_driver() == true)Serial.print("[OK]"); else Serial.print("[ERROR]"); Serial.println(" Motor");
  if (setup_motor_driver() == true)Serial.print("[OK]"); else Serial.print("[ERROR]"); Serial.println(" Gamepad");
}
bool setup_pc_monitor() {
  Serial.begin(PC_Console_Speed);
  return true;
}
bool setup_motor_driver() {
  pinMode(Motor_Power, OUTPUT);
  digitalWrite(Motor_Power, HIGH);
  MotorR.reverse(Motor_Right_Reverse);
  MotorL.reverse(Motor_Left_Reverse);
  MotorB.reverse(Motor_Back_Reverse);
  Shaft.reverse(Shaft_Reverse);
  if (Motor_Test) {
    MotorR.setSpeed(50);
    MotorL.setSpeed(50);
    MotorB.setSpeed(50);
    Shaft.setSpeed(50);
    delay(70);
  }
  MotorR.brake();
  MotorL.brake();
  MotorB.brake();
  Shaft.brake();
  return true;
  delay(100);
}
bool setup_gamepad_driver() {
#define Gamepad_NewState        Gamepad.NewButtonState()
#define Gamepad_Type            Gamepad.readType()
#define Gamepad_Key_Start       Gamepad.Button(PSB_START)
#define Gamepad_Key_Select      Gamepad.Button(PSB_SELECT)
#define Gamepad_Pad_Up          Gamepad.Button(PSB_PAD_UP)
#define Gamepad_Pad_Right       Gamepad.Button(PSB_PAD_RIGHT)
#define Gamepad_Pad_Left        Gamepad.Button(PSB_PAD_LEFT)
#define Gamepad_Pad_Down        Gamepad.Button(PSB_PAD_DOWN)
#define Gamepad_Key_Blue        Gamepad.ButtonPressed(PSB_BLUE)
#define Gamepad_Key_Green       Gamepad.ButtonPressed(PSB_GREEN)
#define Gamepad_Key_Red         Gamepad.ButtonPressed(PSB_RED)
#define Gamepad_Key_Pink        Gamepad.ButtonPressed(PSB_PINK)
#define Gamepad_Trigger_L1      Gamepad.Button(PSB_L2)
#define Gamepad_Trigger_L2      Gamepad.Button(PSB_L3)
#define Gamepad_Trigger_R1      Gamepad.Button(PSB_R2)
#define Gamepad_Trigger_R2      Gamepad.Button(PSB_R3)
#define Gamepad_Stick_Left_Y    Gamepad.Analog(PSS_LY)
#define Gamepad_Stick_Left_X    Gamepad.Analog(PSS_LX)
#define Gamepad_Stick_Right_Y   Gamepad.Analog(PSS_RY)
#define Gamepad_Stick_Right_X   Gamepad.Analog(PSS_RX)
#define Gamepad_Stick_Left_Key  Gamepad.Button(PSB_L1)
#define Gamepad_Stick_Right_Key Gamepad.Button(PSB_R1)
  uint8_t error = 0;
  error = Gamepad.config_gamepad(Gamepad_Pin_Clock, Gamepad_Pin_Command, Gamepad_Pin_Attention, Gamepad_Pin_Data, Gamepad_Pressures, Gamepad_Rumble);
  if (PC_Console_Debug) {
    Serial.print("[...] Gamepad: ");
    if (error == 0) {
      Serial.print("Found Controller");
      if (Gamepad.readType() == 0)Serial.println(" Type: Unknown");
      else if (Gamepad.readType() == 1)Serial.println(" Type: Dualshock (PS1/PS2)");
      else if (Gamepad.readType() == 2)Serial.println(" Type: GuitarHero");
    }
    else if (error == 1)Serial.println("No controller found");
    else if (error == 2)Serial.println("Found but not accepting commands");
    else if (error == 3)Serial.println("Controller refusing to enter Pressures mode");
  }
  if (error == 0)return true;
  else return false;
}



void loop() {
  if(Gamepad_NewState)Serial.println("Gamepad_NewState");
  //MotorR.setSpeed(255);
  //MotorL.setSpeed(255);
  //MotorB.setSpeed(255);
}
//UTILITES
//APPS
