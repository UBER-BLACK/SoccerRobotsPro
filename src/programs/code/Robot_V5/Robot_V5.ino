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
#define PC_Console_Speed        9600              //Information exchange rate.
#define Gamepad_DeadZone        15                  //--
#define Gamepad_Pressures       false               //!!!Check For Error!!!     
#define Gamepad_Rumble          false               //!!!Check For Error!!!
#define Gamepad_Pin_Data        2                   //Gamepad Data Contact
#define Gamepad_Pin_Command     3                   //Gamepad Command Contact
#define Gamepad_Pin_Clock       4                   //Gamepad Clock Contact
#define Gamepad_Pin_Attention   5                   //Gamepad Attention Contact
#define MotionDriver_Boost      0.9                 //--
#define MotionDriver_Normal     0.5                 //--
#define MotionDriver_Freeze     0.1                 //--
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
#include <math.h>         //By Arduino


//CLASES
PS2X Gamepad;
GMotor2<DRIVER3WIRE> MotorR(Motor_Right_Pin_A,  Motor_Right_Pin_B, Motor_Right_Power);
GMotor2<DRIVER3WIRE> MotorL(Motor_Left_Pin_A,   Motor_Left_Pin_B,  Motor_Left_Power);
GMotor2<DRIVER3WIRE> MotorB(Motor_Back_Pin_A,   Motor_Back_Pin_B,  Motor_Back_Power);
GMotor2<DRIVER3WIRE> Shaft(Shaft_Pin_A,         Shaft_Pin_B,       Shaft_Power);
class GamepadForControlOmniWheels {
  public:
    void Set(uint8_t DeadZone, float SpeedBoost, float SpeedNormal, float SpeedFreeze) {
      //Obtaining job dataObtaining job data
      _DeadZone = DeadZone;
      _SpeedBoost = SpeedBoost;
      _SpeedNormal = SpeedNormal;
      _SpeedFreeze = SpeedFreeze;
    }
    void GamepadData(uint8_t Gamepad_LX, uint8_t Gamepad_LY, uint8_t Gamepad_RX, uint8_t Gamepad_RY, bool Gamepad_Boost, bool Gamepad_Freeze) {
      _Gamepad_LX = Gamepad_LX;
      _Gamepad_LY = Gamepad_LY;
      _Gamepad_RX = Gamepad_RX;
      _Gamepad_RY = Gamepad_RY;
      _Gamepad_Boost = Gamepad_Boost;
      _Gamepad_Freeze = Gamepad_Freeze;
      Gearbox();
    }
    void PS2XData(bool Gamepad_Boost, bool Gamepad_Freeze) {
      _Gamepad_LX = Gamepad.Analog(PSS_LX);
      _Gamepad_LY = Gamepad.Analog(PSS_LY);
      _Gamepad_RX = Gamepad.Analog(PSS_RX);
      _Gamepad_RY = Gamepad.Analog(PSS_RY);
      _Gamepad_Boost = Gamepad_Boost;
      _Gamepad_Freeze = Gamepad_Freeze;
    }
    uint8_t GetMotorSpeed(uint8_t MotorNumber) {
      return GetMotorSpeedData(MotorNumber);
    }
  private://private
    void Gearbox() {
      if (_Gamepad_Boost)_SpeedDuty = _SpeedBoost;
      else if (_Gamepad_Freeze)_SpeedDuty = _SpeedFreeze;
      else _SpeedDuty = _SpeedNormal;
    }
    float GetMotorSpeedData(uint8_t MotorNumber) {
      int16_t Motor[3];
      float RotationFactor;
      float SecretConstant = 0.82;
      uint8_t Gamepad_CY = (_Gamepad_LY);
      _Gamepad_RX = (_Gamepad_RX - 128) / 128;
      _Gamepad_LX = (_Gamepad_LX - 128) * 2;
      Gamepad_CY = (Gamepad_CY - 128) * (-2);
      Motor[0] = -((0.8 * Gamepad_CY) + (0.4 * _Gamepad_LX)) * SecretConstant;
      Motor[1] = -((-0.8 * Gamepad_CY) + (0.4 * _Gamepad_LX)) * SecretConstant;
      Motor[2] = _Gamepad_LX;
      if (_Gamepad_RX > (_DeadZone / 256))RotationFactor = -0.8 * (1 - _SpeedDuty) * ((255 * _SpeedDuty) - _SpeedDuty * fabs(fmin(Motor[0], fmin(Motor[1], Motor[2]))));
      else if (_Gamepad_RX < (-_DeadZone / 256))RotationFactor = 0.8 * (1 - _SpeedDuty) * ((255 * _SpeedDuty) - _SpeedDuty * fabs(fmax(Motor[0], fmax(Motor[1], Motor[2]))));
      else RotationFactor = 0;
      if (_Gamepad_LX<_DeadZone and _Gamepad_LX>(-_DeadZone)) {
        Motor[2] = 0;
        if (Gamepad_CY<_DeadZone and Gamepad_CY>(-_DeadZone)) {                                       
          Motor[0] = 0; Motor[1] = 0; Motor[2] = 0;
        }
      }
      Motor[0] = Motor[0] + RotationFactor;
      Motor[1] = Motor[1] + RotationFactor;
      Motor[2] = Motor[2] + RotationFactor;
      return (Motor[MotorNumber] * _SpeedDuty);
    }
    //Gamepad Data
    float _Gamepad_LX;
    float _Gamepad_LY;
    float _Gamepad_RX;
    float _Gamepad_RY;
    bool _Gamepad_Boost;
    bool _Gamepad_Freeze;
    //Values
    uint8_t _DeadZone;
    float _SpeedDuty;
    float _SpeedBoost;
    float _SpeedNormal;
    float _SpeedFreeze;
};
GamepadForControlOmniWheels MotionDriver;


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
  //digitalWrite(Motor_Power, HIGH);
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
  MotionDriver.Set(Gamepad_DeadZone, MotionDriver_Boost, MotionDriver_Normal, MotionDriver_Freeze);
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
  MotorR.tick();
  MotorL.tick();
  MotorB.tick();
  MotionDriver.PS2XData(Gamepad_Trigger_L1, Gamepad_Trigger_L2);
  //MotionDriver.GamepadData(127, 127, 127, 127,  0, 0);
  MotorR.setSpeed(MotionDriver.GetMotorSpeed(0));
  MotorL.setSpeed(MotionDriver.GetMotorSpeed(1));
  MotorB.setSpeed(MotionDriver.GetMotorSpeed(2));
  motor_monitor();
}
//UTILITES
void motor_monitor(){
  Serial.println("==================");
  Serial.print("Motor1 ");Serial.println(MotionDriver.GetMotorSpeed(0));
  Serial.print("Motor2 ");Serial.println(MotionDriver.GetMotorSpeed(1));
  Serial.print("Motor3 ");Serial.println(MotionDriver.GetMotorSpeed(2));
  delay(1000);
}
//APPS
