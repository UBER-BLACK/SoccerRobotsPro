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
#define GearBox_Monitor         false               //--
#define GearBox_MaxSpeed        1                   //--
#define GearBox_MinSpeed        0.2                 //--
#define GearBox_MaxStage        5                   //--
//



//INCLUDE LIBS
#include <PS2X_lib.h>     //By (NONAME)
#include <GyverMotor2.h>  //By AlexGyver 



class Gearbox {
  public:
    //MainFunc
    void GearShifter(bool ShifterUP, bool ShifterDOWN) { //LOOP
      if (ShifterUP) {
        if (millis() - _Timer0 >= 250) {
          _Timer0 = millis();
          if (_DutyStage >= _MaxStage)_DutyStage = _MaxStage;
          else _DutyStage++;
        }
      }
      else if (ShifterDOWN) {
        if (millis() - _Timer0 >= 250) {
          _Timer0 = millis();
          if (_DutyStage <= 0)_DutyStage = 0;
          else _DutyStage--;
        }
      }
    }
    void GearUP() {
      if (_DutyStage >= _MaxStage)_DutyStage = _MaxStage;
      else _DutyStage++;
    }
    void GearDOWN() {
      if (_DutyStage <= 0)_DutyStage = 0;
      else _DutyStage--;
    }
    //OtherFunc
    float GetSpeed() {
      ShiftingGears();
      return _DutySpeed;
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
    void SetSpeed (float Speed) {
      _DutySpeed = Speed;
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
  private:
    void ShiftingGears() {
      _DutySpeed = (_DutyStage - 0) * (_MaxSpeed - _MinSpeed) / (_MaxStage - 0) + _MinSpeed;
    }
    //Values
    float _DutySpeed = 0.5;
    float _MaxSpeed = 1;
    float _MinSpeed = 0.3;
    uint8_t _DutyStage = 0;
    uint8_t _MaxStage = 5;
    //Timers
    uint32_t _Timer0 = 0;
};
Gearbox Gearbox;
PS2X Gamepad;
void setup() {
  uint8_t error = 0;
  error = Gamepad.config_gamepad(Gamepad_Pin_Clock, Gamepad_Pin_Command, Gamepad_Pin_Attention, Gamepad_Pin_Data, 0, 0);

  Serial.begin(9600);
}

void loop() {
  Gamepad.read_gamepad(0, 0);
  Serial.println(Gearbox.GetSpeed());
  Gearbox.GearShifter(Gamepad.Button(PSB_R1),Gamepad.Button(PSB_L1));

}
