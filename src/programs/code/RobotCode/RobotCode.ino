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
#define Gamepad_Monitor_Delay   2000                //--
#define Gamepad_DeadZone        20                  //--
#define Gamepad_Pin_Data        2                   //--
#define Gamepad_Pin_Command     3                   //--
#define Gamepad_Pin_Clock       4                   //--
#define Gamepad_Pin_Attention   5                   //--
//
#define Gearbox_Monitor         false               //--
#define Gearbox_Monitor_Delay   2000                //--
#define Gearbox_MaxSpeed        1                   //--
#define Gearbox_MinSpeed        0.2                 //--
#define Gearbox_MaxStage        2                   //--
#define Gearbox_Delay           200                 //--
//
#define Motor_Monitor           false               //--
#define Motor_Monitor_Delay     2000                //--
#define Motor_Test              true                //--
#define Motor_Power             true                //--
#define Motor_Pin_Standby       8                   //--
#define MotorR_Reverse          false               //--
#define MotorR_Pin_Power        6                   //--
#define MotorR_Pin_Plus         A0                  //--
#define MotorR_Pin_Minus        A1                  //--
#define MotorL_Reverse          false               //--
#define MotorL_Pin_Power        9                   //--
#define MotorL_Pin_Plus         A2                  //--
#define MotorL_Pin_Minus        A3                  //--
#define MotorB_Reverse          false               //--
#define MotorB_Pin_Power        10                  //--
#define MotorB_Pin_Plus         A4                  //--
#define MotorB_Pin_Minus        A5                  //--
#define MotorF_Reverse          false               //--
#define MotorF_Pin_Power        11                  //--
#define MotorF_Pin_Plus         12                  //--
#define MotorF_Pin_Minus        13                  //--
//
#define Solinoid_Pin            7                   //--



#if (Gearbox_Monitor)
uint32_t Timer0;
#endif
#if (Gamepad_Monitor)
uint32_t Timer1;
#endif
#if (Motor_Monitor)
uint32_t Timer2;
#endif



//INCLUDE LIBS
#include <PS2X_lib.h>     //By (NONAME)
#include <GyverMotor2.h>  //By AlexGyver
PS2X PS2X;
GMotor2<DRIVER3WIRE>MotorR(MotorR_Pin_Plus, MotorR_Pin_Minus, MotorR_Pin_Power);
GMotor2<DRIVER3WIRE>MotorL(MotorL_Pin_Plus, MotorL_Pin_Minus, MotorL_Pin_Power);
GMotor2<DRIVER3WIRE>MotorB(MotorB_Pin_Plus, MotorB_Pin_Minus, MotorB_Pin_Power);
GMotor2<DRIVER3WIRE>MotorF(MotorF_Pin_Plus, MotorF_Pin_Minus, MotorF_Pin_Power);



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
      if (millis() - _Timer0 >= _Delay) {
        _Timer0 = millis();
        if (_DutyStage >= _MaxStage)_DutyStage = _MaxStage;
        else _DutyStage++;
      }
    }
    void DOWN() {
      if (millis() - _Timer0 >= _Delay) {
        _Timer0 = millis();
        if (_DutyStage <= 0)_DutyStage = 0;
        else _DutyStage--;
      }
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
  Serial.begin(Monitor_Speed);
  Gearbox.Setup(Gearbox_MaxSpeed, Gearbox_MinSpeed, Gearbox_MaxStage, Gearbox_Delay);
  PS2X.config_gamepad(Gamepad_Pin_Clock, Gamepad_Pin_Command, Gamepad_Pin_Attention, Gamepad_Pin_Data, 0, 0);
}



void loop() {
  Drivers();
  Monitors();
  Gearbox.GearShifterPS2X();
}
void Monitors() {
#if (Gearbox_Monitor)
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
#if (Gamepad_Monitor)
  if (millis() - Timer1 >= Gamepad_Monitor_Delay) {
    Timer1 = millis();
    Serial.println("GAMEPAD-MONITOR===========+++");
    Serial.println("*Pads       ");
    Serial.print("UP            "); Serial.println(PS2X.Button(PSB_PAD_UP));
    Serial.print("RIGHT         "); Serial.println(PS2X.Button(PSB_PAD_RIGHT));
    Serial.print("LEFT          "); Serial.println(PS2X.Button(PSB_PAD_LEFT));
    Serial.print("DOWN          "); Serial.println(PS2X.Button(PSB_PAD_DOWN));
    Serial.println("*FastKeys   ");
    Serial.print("Start         "); Serial.println(PS2X.Button(PSB_START));
    Serial.print("Select        "); Serial.println(PS2X.Button(PSB_SELECT));
    Serial.println("*Keys       ");
    Serial.print("BLUE          "); Serial.println(PS2X.ButtonPressed(PSB_BLUE));
    Serial.print("GREEN         "); Serial.println(PS2X.ButtonPressed(PSB_GREEN));
    Serial.print("RED           "); Serial.println(PS2X.ButtonPressed(PSB_RED));
    Serial.print("PINK          "); Serial.println(PS2X.ButtonPressed(PSB_PINK));
    Serial.println("*Triggers   ");
    Serial.print("L1            "); Serial.println(PS2X.Button(PSB_L1));
    Serial.print("L2            "); Serial.println(PS2X.Button(PSB_L2));
    Serial.print("R1            "); Serial.println(PS2X.Button(PSB_R1));
    Serial.print("R2            "); Serial.println(PS2X.Button(PSB_R2));
    Serial.println("*Sticks     ");
    Serial.print("AXIS LY       "); Serial.println(PS2X.Analog(PSS_LY));
    Serial.print("AXIS LX       "); Serial.println(PS2X.Analog(PSS_LX));
    Serial.print("KEY  L        "); Serial.println(PS2X.Button(PSB_L3));
    Serial.print("AXIS RY       "); Serial.println(PS2X.Analog(PSS_RY));
    Serial.print("AXIS RX       "); Serial.println(PS2X.Analog(PSS_RX));
    Serial.print("KEY  R        "); Serial.println(PS2X.Button(PSB_R3));
    Serial.println("*Others     ");
    Serial.print("NEW STATE     "); Serial.println(PS2X.NewButtonState());
  }
#endif
#if (Motor_Monitor)
  if (millis() - Timer2 >= Motor_Monitor_Delay) {
    Timer2 = millis();
    Serial.println("MOTOR-MONITOR=============+++");
    Serial.print("Right     "); Serial.println(MotorR.getSpeed());
    Serial.print("Left      "); Serial.println(MotorL.getSpeed());
    Serial.print("Back      "); Serial.println(MotorB.getSpeed());
    Serial.print("Front     "); Serial.println(MotorF.getSpeed());
  }
#endif
}
void Drivers() {
  //Gamepad
  PS2X.read_gamepad(0, 0);
  //Motor
  MotorR.tick();
  MotorL.tick();
  MotorB.tick();
  MotorF.tick();
}
