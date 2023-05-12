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
#define Gearbox_MaxGearSpeed    1                   //--
#define Gearbox_MinGearSpeed    0.2                 //--
#define Gearbox_DefaultGear     0                   //--
#define Gearbox_MaxGear         5                   //--
#define Gearbox_GearDelay       250                 //--

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
#define ShockPanel_Monitor      false               //--
#define ShockPanel_ShotSpeed    255                 //--
#define ShockPanel_SuctionSpeed 150                 //--
#define ShockPanel_Pin_Solinoid 7                   //--
//



#if (Gearbox_Monitor)
uint32_t Timer0;
#endif
#if (Gamepad_Monitor)
uint32_t Timer1;
#endif
#if (Motor_Monitor)
uint32_t Timer2;
#endif
#if (ShockPanel_Monitor)
uint32_t Timer3;
#endif



//LIBS
#include <PS2X_lib.h>     //By (NONAME)
#include <GyverMotor2.h>  //By AlexGyver
PS2X PS2X;
GMotor2<DRIVER3WIRE>MotorR(MotorR_Pin_Plus, MotorR_Pin_Minus, MotorR_Pin_Power);
GMotor2<DRIVER3WIRE>MotorL(MotorL_Pin_Plus, MotorL_Pin_Minus, MotorL_Pin_Power);
GMotor2<DRIVER3WIRE>MotorB(MotorB_Pin_Plus, MotorB_Pin_Minus, MotorB_Pin_Power);
GMotor2<DRIVER3WIRE>MotorF(MotorF_Pin_Plus, MotorF_Pin_Minus, MotorF_Pin_Power);


class Motion{
  public:
  private:
};
class Shockpanel {
  public:
    Setup(uint8_t Solinoid_Pin, int16_t ShotMotorSpeed, int16_t SuctionMotorSpeed) {
      _Solinoid_Pin = Solinoid_Pin;
      _ShotMotorSpeed = ShotMotorSpeed * -1;
      _SuctionMotorSpeed = SuctionMotorSpeed;
      pinMode(_Solinoid_Pin, OUTPUT);
      ShotManual(true);
      ShotManual(false);
    }
    void ShotPS2X() {
      ShotManual(PS2X.Button(PSB_R2));
    }
    void ShotManual(bool Shot) {
      if (_flag0)
        if (Shot == true) {
          Solinoid(true);
          MotorMode(true);
        }
        else {
          Solinoid(false);
          MotorMode(false);
        }

    }
    void Solinoid(bool Power) {
      digitalWrite(_Solinoid_Pin, Power);
    }
    void MiniGun(bool run) {
      if (run) {
        _flag0 = false;
        MotorMode(true);
        if (millis() - _Timer2 >= 20 * 2) {
          _flag1 = !_flag1;
          Solinoid(_flag1);
          _Timer2 =  millis();
        }
      }
      else {
        Solinoid(false);
        _flag0 = true;
        MotorMode(false);
      }
    }
    void MotorMode(bool Mode) {
      if (Mode)Motor(_ShotMotorSpeed);
      else if (_Suction)Motor(_SuctionMotorSpeed);
      else Motor(0);
    }
    void Motor(int16_t DutyMotorSpeed) {
      _DutyMotorSpeed = DutyMotorSpeed;
    }
    void Suction(bool Suction) {
      _Suction = Suction;
    }
    int16_t GetDutyMotorSpeed() {
      return _DutyMotorSpeed;
    }
    int16_t GetShotMotorSpeed() {
      return _ShotMotorSpeed;
    }
    int16_t GetSuctionMotorSpeed() {
      return _SuctionMotorSpeed;
    }
    uint16_t GetSolinoidPin() {
      return _Solinoid_Pin;
    }
    bool GetSuction() {
      return _Suction;
    }
    void SetShotMotorSpeed(uint16_t ShotMotorSpeed) {
      _ShotMotorSpeed = ShotMotorSpeed;
    }
    void SetSuctionMotorSpeed(uint16_t SuctionMotorSpeed) {
      _SuctionMotorSpeed = SuctionMotorSpeed;
    }
    void SetSolinoidPin(uint16_t Solinoid_Pin) {
      _Solinoid_Pin = Solinoid_Pin;
    }
    void SetSuction(bool Suction) {
      _Suction = Suction;
    }
  private:
    //Values
    uint8_t _Solinoid_Pin;
    int16_t _DutyMotorSpeed;
    int16_t _ShotMotorSpeed;
    int16_t _SuctionMotorSpeed;
    bool _Suction = true;
    //Timers
    uint32_t _Timer0;
    uint32_t _Timer1;
    uint32_t _Timer2;
    //Flags
    bool _flag0;
    bool _flag1;

};
class Gearbox {
  public:
    //MainFunc
    Setup(float MaxGearSpeed, float MinGearSpeed, uint8_t MaxGear, uint8_t DefaultGear, uint16_t GearDelay) {
      _MaxGearSpeed = MaxGearSpeed;
      _MinGearSpeed = MinGearSpeed;
      _DutyGear = DefaultGear;
      _MaxGear = MaxGear;
      _GearDelay = GearDelay;
    }
    void ShifterPS2X() {
      ShifterManual(PS2X.Button(PSB_R1), PS2X.Button(PSB_L1));
    }
    void ShifterManual(bool ShifterUP, bool ShifterDOWN) {
      if (ShifterUP and ShifterDOWN)BOOST();
      else if (ShifterUP)UP();
      else if (ShifterDOWN)DOWN();
    }
    void UP() {
      if (millis() - _Timer0 >= _GearDelay) {
        _Timer0 = millis();
        if (_DutyGear >= _MaxGear)_DutyGear = _MaxGear;
        else _DutyGear++;
      }
    }
    void DOWN() {
      if (millis() - _Timer0 >= _GearDelay) {
        _Timer0 = millis();
        if (_DutyGear <= 0)_DutyGear = 0;
        else _DutyGear--;
      }
    }
    void BOOST() {
      _DutyGear = _MaxGear;
    }
    void FREEZE() {
      _DutyGear = 0;
    }
    int16_t GetSpeed (int16_t OriginalSpeed) {
      return OriginalSpeed * GetDutySpeedFactor();
    }
    //OtherFuncs
    float GetDutySpeedFactor() {
      return (_DutyGear - 0) * (_MaxGearSpeed - _MinGearSpeed) / (_MaxGear - 0) + _MinGearSpeed;
    }
    float GetMaxSpeedFactor() {
      return _MaxGearSpeed;
    }
    float GetMinSpeedFactor() {
      return _MinGearSpeed;
    }
    uint8_t GetDutyGear() {
      return _MaxGearSpeed;
    }
    uint8_t GetMaxGear() {
      return _MaxGear;
    }
    uint8_t GetMinGear() {
      return 0;
    }
    uint16_t GetGearDelay() {
      return _GearDelay;
    }
    void SetMaxSpeedFactor(float MaxGearSpeed) {
      _MaxGearSpeed = MaxGearSpeed;
    }
    void SetMinSpeedFactor(float MinGearSpeed) {
      _MinGearSpeed = MinGearSpeed;
    }
    void SetMaxGear(uint8_t MaxGear) {
      _MaxGear = MaxGear;
    }
    void SetGearDelay(uint16_t GearDelay) {
      _GearDelay = GearDelay;
    }
  private:
    //Values
    float _MaxGearSpeed;
    float _MinGearSpeed;
    float _DutyGear;
    float _MaxGear;
    uint16_t _GearDelay;
    //Timers
    uint32_t _Timer0;
};
Gearbox Gearbox;
Shockpanel Shockpanel;
void setup() {
  pinMode(Motor_Pin_Standby, OUTPUT);
  digitalWrite(Motor_Pin_Standby, Motor_Power);
  PWM_Overclock();
  Console();
  Shockpanel.Setup(ShockPanel_Pin_Solinoid, ShockPanel_ShotSpeed, ShockPanel_SuctionSpeed);
  Gearbox.Setup(Gearbox_MaxGearSpeed, Gearbox_MinGearSpeed, Gearbox_MaxGear, Gearbox_DefaultGear, Gearbox_GearDelay);
  PS2X.config_gamepad(Gamepad_Pin_Clock, Gamepad_Pin_Command, Gamepad_Pin_Attention, Gamepad_Pin_Data, 0, 0);
}



void loop() {
  Drivers();
  Monitors();
  Emotions();
  Gearbox.ShifterPS2X();
  Shockpanel.ShotPS2X();
  MotorF.setSpeed(Shockpanel.GetDutyMotorSpeed());
  Serial.println(Shockpanel.GetShotMotorSpeed());
}


//FUNC
void Emotions() {
  Shockpanel.MiniGun(PS2X.Button(PSB_PAD_UP));
}
void Drivers() {
  //Gamepad
  PS2X.read_gamepad(0, 0);
  //Motor
  MotorR.tick();
  MotorL.tick();
  MotorB.tick();
  MotorF.tick();
  //ShockPanel
}
void Monitors() {
#if (Gearbox_Monitor)
  if (millis() - Timer0 >= Gearbox_Monitor_Delay) {
    Timer0 = millis();
    Serial.println("GEARBOX-MONITOR===========+++");
    Serial.print("DutySpeedFactor "); Serial.println(GetDutySpeedFactor());
    Serial.print("MaxSpeedFactor  "); Serial.println(GetMaxSpeedFactorr());
    Serial.print("MinSpeedFactor  "); Serial.println(GetMinSpeedFactorr());
    Serial.print("DutyGear        "); Serial.println(GetDutyGear());
    Serial.print("MaxGear         "); Serial.println(GetMaxGear());
    Serial.print("MinGear         "); Serial.println(GetMaxGear());
    Serial.print("GearDelay       "); Serial.println(GetGearDelay());
  }
#endif
#if (Gamepad_Monitor)
  if (millis() - Timer1 >= Gamepad_Monitor_Delay) {
    Timer1 = millis();
    Serial.println("GAMEPAD-MONITOR===========+++");
    Serial.println("*Pads     ");
    Serial.print("UP          "); Serial.println(PS2X.Button(PSB_PAD_UP));
    Serial.print("RIGHT       "); Serial.println(PS2X.Button(PSB_PAD_RIGHT));
    Serial.print("LEFT        "); Serial.println(PS2X.Button(PSB_PAD_LEFT));
    Serial.print("DOWN        "); Serial.println(PS2X.Button(PSB_PAD_DOWN));
    Serial.println("*FastKeys ");
    Serial.print("Start       "); Serial.println(PS2X.Button(PSB_START));
    Serial.print("Select      "); Serial.println(PS2X.Button(PSB_SELECT));
    Serial.println("*Keys     ");
    Serial.print("BLUE        "); Serial.println(PS2X.ButtonPressed(PSB_BLUE));
    Serial.print("GREEN       "); Serial.println(PS2X.ButtonPressed(PSB_GREEN));
    Serial.print("RED         "); Serial.println(PS2X.ButtonPressed(PSB_RED));
    Serial.print("PINK        "); Serial.println(PS2X.ButtonPressed(PSB_PINK));
    Serial.println("*Triggers ");
    Serial.print("L1          "); Serial.println(PS2X.Button(PSB_L1));
    Serial.print("L2          "); Serial.println(PS2X.Button(PSB_L2));
    Serial.print("R1          "); Serial.println(PS2X.Button(PSB_R1));
    Serial.print("R2          "); Serial.println(PS2X.Button(PSB_R2));
    Serial.println("*Sticks   ");
    Serial.print("AXIS LY     "); Serial.println(PS2X.Analog(PSS_LY));
    Serial.print("AXIS LX     "); Serial.println(PS2X.Analog(PSS_LX));
    Serial.print("KEY  L      "); Serial.println(PS2X.Button(PSB_L3));
    Serial.print("AXIS RY     "); Serial.println(PS2X.Analog(PSS_RY));
    Serial.print("AXIS RX     "); Serial.println(PS2X.Analog(PSS_RX));
    Serial.print("KEY  R      "); Serial.println(PS2X.Button(PSB_R3));
    Serial.println("*Others   ");
    Serial.print("NEW STATE   "); Serial.println(PS2X.NewButtonState());
  }
#endif
#if (Motor_Monitor)
  if (millis() - Timer2 >= Motor_Monitor_Delay) {
    Timer2 = millis();
    Serial.println("MOTOR-MONITOR=============+++");
    Serial.print("Right "); Serial.println(MotorR.getSpeed());
    Serial.print("Left  "); Serial.println(MotorL.getSpeed());
    Serial.print("Back  "); Serial.println(MotorB.getSpeed());
    Serial.print("Front "); Serial.println(MotorF.getSpeed());
  }
#endif
#if (ShockPanel_Monitor)
  if (millis() - Timer3 >= Motor_Monitor_Delay) {
    Timer3 = millis();
    Serial.println("SCHOCKPANEL-MONITOR=======+++");
    Serial.print("Right "); Serial.println(MotorR.getSpeed());

  }
#endif
}
void PWM_Overclock() {
  /*DONT TOUCH!
    //D5 * D6
    TCCR0B = 0b00000001;  // x1
    TCCR0A = 0b00000011;  // fast pwm
  */
  //D9 & D10
  TCCR1A = 0b00000001;  // 8bit
  TCCR1B = 0b00001001;  // x1 fast pwm
  //D3 & D11
  TCCR2B = 0b00000001;  // x1
  TCCR2A = 0b00000011;  // fast pwm
}
void Console() {
  Serial.begin(Monitor_Speed);
  Serial.println("It works.");
}
