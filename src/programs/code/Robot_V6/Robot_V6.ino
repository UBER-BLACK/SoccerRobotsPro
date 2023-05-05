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
#define PC_Console_Speed        9600                //Information exchange rate.
#define Gamepad_Debug           true                //--
#define Gamepad_DeadZone        5                   //--
#define Gamepad_Pressures       false               //!!!Check For Error!!!     
#define Gamepad_Rumble          false               //!!!Check For Error!!!
#define Gamepad_Pin_Data        2                   //Gamepad Data Contact
#define Gamepad_Pin_Command     3                   //Gamepad Command Contact
#define Gamepad_Pin_Clock       4                   //Gamepad Clock Contact
#define Gamepad_Pin_Attention   5                   //Gamepad Attention Contact
#define MotionDriver_Debug      true                //--
#define MotionDriver_Boost      0.9                 //--
#define MotionDriver_Normal     0.5                 //--
#define MotionDriver_Freeze     0.1                 //--
#define Motor_Debug             true                //--
#define Motor_Type              HIGH                //Whatever works best for you
#define Motor_Test              true                //--
#define Motor_Power             8                   //Motor Driver Stendby Contact
#define Motor_MinSpeed          20                  //--
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


//DEFINE
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



//INCLUDE LIBS
#include <PS2X_lib.h>     //By (NONAME)
#include <GyverMotor2.h>  //By AlexGyver                      
#include <math.h>         //By Arduino


//CLASES
PS2X Gamepad;
GMotor2<DRIVER3WIRE> MotorR(Motor_Right_Pin_A,  Motor_Right_Pin_B, Motor_Right_Power);
GMotor2<DRIVER3WIRE> MotorL(Motor_Left_Pin_A,   Motor_Left_Pin_B,  Motor_Left_Power);
GMotor2<DRIVER3WIRE> MotorB(Motor_Back_Pin_A,   Motor_Back_Pin_B,  Motor_Back_Power);
GMotor2<DRIVER3WIRE> Shaft(Shaft_Pin_A,         Shaft_Pin_B,       Shaft_Power);
class GamepadForControlOmniWheels {
  public:
    void CustomGamepadData(uint8_t LX, uint8_t LY, uint8_t RX, uint8_t RY, bool Boost, bool Freeze) {
      _Gamepad_LX = LX;
      _Gamepad_LY = LY;
      _Gamepad_RX = RX;
      _Gamepad_RY = RY;
      _Gamepad_Boost = Boost;
      _Gamepad_Freeze = Freeze;
    }
    void PS2XLibData(bool Boost, bool Freeze) {
      //BETA
      _Gamepad_LX = Gamepad_Stick_Left_X;
      _Gamepad_LY = Gamepad_Stick_Left_Y;
      _Gamepad_RX = Gamepad_Stick_Right_X;
      _Gamepad_RY = Gamepad_Stick_Right_Y;
      _Gamepad_Boost = Boost;
      _Gamepad_Freeze = Freeze;
    }
    int16_t GetMotorData(uint8_t MotorNumber) {
      return Formula(MotorNumber);
    }
  private://private
    float Formula(int MotorNumber) {
      float x = _Gamepad_LX;
      float y = _Gamepad_LY;
      float px = _Gamepad_RX;
      float mid = _DeadZone;
      float spd = _SpeedDuty;
      int mot[3]; float pov; float k = 0.9;
      px = (px - 128) / 128; x = (x - 128) * 2; y = (y - 128) * (-2);
      mot[0] = -((0.8 * y) + (0.4 * x)) * k; mot[1] = -((-0.8 * y) + (0.4 * x)) * k; mot[2] = x;
      if (px > (mid / 256)) {
        pov = -0.8 * (1 - spd) * ((255 * spd) - spd * fabs(fmin(mot[0], fmin(mot[1], mot[2]))));
      }
      else if (px < (-mid / 256)) {
        pov = 0.8 * (1 - spd) * ((255 * spd) - spd * fabs(fmax(mot[0], fmax(mot[1], mot[2]))));
      }
      else {
        pov = 0;
      }
      if (x<mid and x>(-mid)) {
        mot[2] = 0; if (y<mid and y>(-mid)) {
          mot[0] = 0; mot[1] = 0; mot[2] = 0;
        }
      }
      mot[0] = mot[0] + pov; mot[1] = mot[1] + pov; mot[2] = mot[2] + pov;
      return (mot[MotorNumber] * spd);
    }
    //Gamepad Data
    uint8_t _Gamepad_LX = 127;
    uint8_t _Gamepad_LY = 127;
    uint8_t _Gamepad_RX = 127;
    uint8_t _Gamepad_RY = 127;
    bool _Gamepad_Boost = false;
    bool _Gamepad_Freeze = false;
    //Values
    float _DeadZone = 15;
    float _SpeedDuty = 0.3;
    float _SpeedBoost = 0.9;
    float _SpeedNormal = 0.3;
    float _SpeedFreeze = 0.1;
};
GamepadForControlOmniWheels MotionDriver;


//SETUPS
void setup() {
  if (setup_pc_monitor() == true)Serial.println("[OK] PC Console");
  if (setup_motor_driver() == true)Serial.print("[OK]"); else Serial.print("[ERROR]"); Serial.println(" Motor");
  if (setup_gamepad_driver() == true)Serial.print("[OK]"); else Serial.print("[ERROR]"); Serial.println(" Gamepad");
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
  uint8_t error = 0;
  error = Gamepad.config_gamepad(Gamepad_Pin_Clock, Gamepad_Pin_Command, Gamepad_Pin_Attention, Gamepad_Pin_Data, Gamepad_Pressures, Gamepad_Rumble);
  Serial.print("[..] Gamepad: ");
  if (error == 0) {
    Serial.print("Found Controller");
    if (Gamepad.readType() == 0)Serial.println(" Type: Unknown");
    else if (Gamepad.readType() == 1)Serial.println(" Type: Dualshock (PS1/PS2)");
    else if (Gamepad.readType() == 2)Serial.println(" Type: GuitarHero");
  }
  else if (error == 1)Serial.println("No controller found");
  else if (error == 2)Serial.println("Found but not accepting commands");
  else if (error == 3)Serial.println("Controller refusing to enter Pressures mode");
  if (error == 0)return true;
  else return false;
}



void loop() {
  Motor_Driver();
  //MotorR.setSpeed(MinSpeedControl(MotionDriver.GetMotorData(0)));
  //MotorL.setSpeed(MinSpeedControl(MotionDriver.GetMotorData(1)));
  //MotorB.setSpeed(MinSpeedControl(MotionDriver.GetMotorData(2)));
  MotorR.setSpeed(MinSpeedControl(-19));
  if (Motor_Debug)Motor_Monitor();
  if (MotionDriver_Debug)MotionDriver_Monitor();
  if (Gamepad_Debug)Gamepad_Monitor();
  delay(10);
}
void MotionDriver_Monitor() {
  Serial.println("MOTION_DRIVER-MONITOR=====+++");
  Serial.println("* MotorData:");
  Serial.print("Right         "); Serial.println(MotionDriver.GetMotorData(0));
  Serial.print("Left          "); Serial.println(MotionDriver.GetMotorData(1));
  Serial.print("Back          "); Serial.println(MotionDriver.GetMotorData(2));
}
void Motor_Monitor() {
  Serial.println("MOTOR-MONITOR=============+++");
  Serial.println("* Motors:");
  Serial.print("Right         "); Serial.print(MotorR.getState()); Serial.print(" "); Serial.println(MotorR.getSpeed());
  Serial.print("Left          "); Serial.print(MotorL.getState()); Serial.print(" "); Serial.println(MotorL.getSpeed());
  Serial.print("Back          "); Serial.print(MotorB.getState()); Serial.print(" "); Serial.println(MotorB.getSpeed());
}
void Gamepad_Monitor() {
  Serial.println("GAMEPAD-MONITOR===========+++");
  Serial.println("* Settings:");
  Serial.print("Pressures     "); Serial.println(Gamepad_Pressures);
  Serial.print("Rumble        "); Serial.println(Gamepad_Rumble);
  Serial.println("* Pad:");
  Serial.print("Up            "); Serial.println(Gamepad_Pad_Up);
  Serial.print("Right         "); Serial.println(Gamepad_Pad_Right);
  Serial.print("Left          "); Serial.println(Gamepad_Pad_Left);
  Serial.print("Down          "); Serial.println(Gamepad_Pad_Down);
  Serial.println("* Keys:");
  Serial.print("Red           "); Serial.println(Gamepad_Key_Red);
  Serial.print("Pink          "); Serial.println(Gamepad_Key_Pink);
  Serial.print("Blue          "); Serial.println(Gamepad_Key_Blue);
  Serial.print("Green         "); Serial.println(Gamepad_Key_Green);
  Serial.print("Start         "); Serial.println(Gamepad_Key_Start);
  Serial.print("Select        "); Serial.println(Gamepad_Key_Select);
  Serial.println("* Sticks:");
  Serial.print("Left Y        "); Serial.println(Gamepad_Stick_Left_Y);
  Serial.print("Left X        "); Serial.println(Gamepad_Stick_Left_X);
  Serial.print("Right Y       "); Serial.println(Gamepad_Stick_Right_Y);
  Serial.print("Right X       "); Serial.println(Gamepad_Stick_Right_X);
  Serial.print("Left Key      "); Serial.println(Gamepad_Stick_Left_Key);
  Serial.print("Right Key     "); Serial.println(Gamepad_Stick_Right_Key);
  Serial.println("* Triggers:");
  Serial.print("Left 1        "); Serial.println(Gamepad_Trigger_L1);
  Serial.print("Left 2        "); Serial.println(Gamepad_Trigger_L2);
  Serial.print("Right 1       "); Serial.println(Gamepad_Trigger_R1);
  Serial.print("Right 2       "); Serial.println(Gamepad_Trigger_R2);
  Serial.println("* Other:");
  Serial.print("New State     "); Serial.println(Gamepad_NewState);
  Serial.print("Type          "); Serial.println(Gamepad_Type);
}
void Motor_Driver() {
  MotorR.tick();
  MotorL.tick();
  MotorB.tick();
}
int16_t MinSpeedControl(int16_t MotorSpeed) {
  if (MotorSpeed >= Motor_MinSpeed or -Motor_MinSpeed >= MotorSpeed)return MotorSpeed;
  else return 0;
}
