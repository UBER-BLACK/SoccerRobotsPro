//GitHub: http://GitHub.com/UBER-BLACK/SoccerRobotsPro/
//LICENSE: http://raw.githubusercontent.com/UBER-BLACK/SoccerRobotsPro/main/LICENSE
//██╗░░░██╗██████╗░███████╗██████╗░░░░░░░██████╗░██╗░░░░░░█████╗░░█████╗░██╗░░██╗
//██║░░░██║██╔══██╗██╔════╝██╔══██╗░░░░░░██╔══██╗██║░░░░░██╔══██╗██╔══██╗██║░██╔╝
//██║░░░██║██████╦╝█████╗░░██████╔╝█████╗██████╦╝██║░░░░░███████║██║░░╚═╝█████═╝░
//██║░░░██║██╔══██╗██╔══╝░░██╔══██╗╚════╝██╔══██╗██║░░░░░██╔══██║██║░░██╗██╔═██╗░
//╚██████╔╝██████╦╝███████╗██║░░██║░░░░░░██████╦╝███████╗██║░░██║╚█████╔╝██║░╚██╗
//░╚═════╝░╚═════╝░╚══════╝╚═╝░░╚═╝░░░░░░╚═════╝░╚══════╝╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝
//by THEBIGMISHA <http://GitHub.com/THEBIGMISHA>


//SETTINGS
//////////////////////////////////////////////////////////////////////////////////////////////////////
//            NAME            //        VALUE       //                     DESCRIPTION              //
#define Monitor_Speed           9600                //--
//
#define Gamepad_Monitor         false               //--
#define Gamepad_DeadZone        20                  //--
#define Gamepad_Pin_Data        2                   //--
#define Gamepad_Pin_Command     3                   //--
#define Gamepad_Pin_Clock       4                   //--
#define Gamepad_Pin_Attention   5                   //--
//
#define MotionDLib_Monitor      false               //--
//
#define Gearbox_Monitor         false               //--
#define Gearbox_Monitor_Delay   2000                //--
#define Gearbox_MaxSpeed        1                   //--
#define Gearbox_MinSpeed        0.2                 //--
#define Gearbox_MaxStage        5                   //--
#define Gearbox_Delay           250                 //--
//



//DEFINE
#define Gamepad_NewState        Gamepad.NewButtonState()
#define Gamepad_Type            Gamepad.readType()
#define Gamepad_Pad_Up          Gamepad.Button(PSB_PAD_UP)
#define Gamepad_Pad_Right       Gamepad.Button(PSB_PAD_RIGHT)
#define Gamepad_Pad_Left        Gamepad.Button(PSB_PAD_LEFT)
#define Gamepad_Pad_Down        Gamepad.Button(PSB_PAD_DOWN)
#define Gamepad_Key_Start       Gamepad.Button(PSB_START)
#define Gamepad_Key_Select      Gamepad.Button(PSB_SELECT)
#define Gamepad_Key_Blue        Gamepad.ButtonPressed(PSB_BLUE)
#define Gamepad_Key_Green       Gamepad.ButtonPressed(PSB_GREEN)
#define Gamepad_Key_Red         Gamepad.ButtonPressed(PSB_RED)
#define Gamepad_Key_Pink        Gamepad.ButtonPressed(PSB_PINK)
#define Gamepad_Trigger_L1      Gamepad.Button(PSB_L1)
#define Gamepad_Trigger_L2      Gamepad.Button(PSB_L2)
#define Gamepad_Trigger_R1      Gamepad.Button(PSB_R1)
#define Gamepad_Trigger_R2      Gamepad.Button(PSB_R2)
#define Gamepad_Stick_Left_Y    Gamepad.Analog(PSS_LY)
#define Gamepad_Stick_Left_X    Gamepad.Analog(PSS_LX)
#define Gamepad_Stick_Left_Key  Gamepad.Button(PSB_L3)
#define Gamepad_Stick_Right_Y   Gamepad.Analog(PSS_RY)
#define Gamepad_Stick_Right_X   Gamepad.Analog(PSS_RX)
#define Gamepad_Stick_Right_Key Gamepad.Button(PSB_R3)


#if (Gearbox_Monitor == true)
uint32_t Timer0;
#endif


//INCLUDE LIBS
#include <PS2X_lib.h>     //By (NONAME)
#include <GyverMotor2.h>  //By AlexGyver
PS2X PS2X;



class Gamepad {
  public:
  private:
};
class Gearbox {
  public:
    //MainFunc
    void Setup(float MaxSpeed, float MinSpeed, uint8_t MaxStage, uint16_t Delay) {
      _MaxSpeed = MaxSpeed;
      _MinSpeed = MinSpeed;
      _MaxStage = MaxStage;
      _Delay = Delay;
    }
    void GearShifterPS2X() {
      GearShifterManual(PS2X.Button(PSB_R1), PS2X.Button(PSB_L1));
    }
    void GearShifterManual(bool ShifterUP, bool ShifterDOWN) { //LOOP
      if (ShifterUP and ShifterDOWN) {
        if (millis() - _Timer0 >= _Delay) {
          _Timer0 = millis();
          _DutyStage = _MaxStage;
        }
      }
      else if (ShifterUP) {
        if (millis() - _Timer0 >= _Delay) {
          _Timer0 = millis();
          if (_DutyStage >= _MaxStage)_DutyStage = _MaxStage;
          else _DutyStage++;
        }
      }
      else if (ShifterDOWN) {
        if (millis() - _Timer0 >= _Delay) {
          _Timer0 = millis();
          if (_DutyStage <= 0)_DutyStage = 0;
          else _DutyStage--;
        }
      }
    }
    void UP() {
      if (_DutyStage >= _MaxStage)_DutyStage = _MaxStage;
      else _DutyStage++;
    }
    void DOWN() {
      if (_DutyStage <= 0)_DutyStage = 0;
      else _DutyStage--;
    }
    //OtherFunc
    float GetDutySpeed() {
      return (_DutyStage - 0) * (_MaxSpeed - _MinSpeed) / (_MaxStage - 0) + _MinSpeed;
    }
    float GetMinSpeed() {
      return _MinSpeed;
    }
    float GetMaxSpeed() {
      return _MaxSpeed;
    }
    float GetMaxStage() {
      return _MaxStage;
    }
    float GetDutyStage() {
      return _DutyStage;
    }
    uint16_t GetDelay() {
      return _Delay;
    }
    void SetMinSpeed (float MinSpeed) {
      _MinSpeed = MinSpeed;
    }
    void SetMaxSpeed (float MaxSpeed) {
      _MinSpeed = MaxSpeed;
    }
    void SetMaxStage(uint8_t MaxStage) {
      _MaxStage = MaxStage;
    }
    void SetDutyStage(uint8_t DutyStage) {
      _DutyStage = DutyStage;
    }
    void SetDelay(uint16_t Delay) {
      _Delay = Delay;
    }
  private:
    //Values
    float _MaxSpeed;
    float _MinSpeed;
    uint8_t _DutyStage;
    uint8_t _MaxStage;
    uint16_t _Delay;
    //Timers
    uint32_t _Timer0;
};
Gearbox Gearbox;
void setup() {
  Gearbox.Setup(Gearbox_MaxSpeed, Gearbox_MinSpeed, Gearbox_MaxStage, Gearbox_Delay);
  uint8_t error = 0;
  error = PS2X.config_gamepad(Gamepad_Pin_Clock, Gamepad_Pin_Command, Gamepad_Pin_Attention, Gamepad_Pin_Data, 0, 0);

  Serial.begin(9600);
}

void loop() {
  Drivers();
  Monitors();
  Gearbox.GearShifterPS2X();
}
void Monitors() {
#if (Gearbox_Monitor == true)
  if (millis() - Timer0 >= Gearbox_Monitor_Delay) {
    Timer0 = millis();
    Serial.println("GEARBOX-MONITOR===========+++");
    Serial.print("DutySpeed     "); Serial.println(Gearbox.GetDutySpeed());
    Serial.print("MaxSpeed      "); Serial.println(Gearbox.GetMaxSpeed());
    Serial.print("MinSpeed      "); Serial.println(Gearbox.GetMinSpeed());
    Serial.print("DutyStage     "); Serial.println(Gearbox.GetDutyStage());
    Serial.print("MaxStage      "); Serial.println(Gearbox.GetMaxStage());
    Serial.print("Delay         "); Serial.println(Gearbox.GetDelay());
  }
#endif
}
void Drivers() {
  PS2X.read_gamepad(0, 0);
}
