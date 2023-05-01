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
#define PC_Console_Debug        true                //Debug mode
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
}
bool setup_pc_monitor() {
  Serial.begin(PC_Console_Speed);
  return true;
}
bool setup_motor_driver() {
  pinMode(Motor_Power, OUTPUT);
  digitalWrite(Motor_Power, HIGH);
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



void loop() {
  //MotorR.setSpeed(255);
}
//UTILITES
//APPS
