//GitHub: http://GitHub.com/UBER-BLACK/SoccerRobotsPro/
//LICENSE: http://raw.githubusercontent.com/UBER-BLACK/SoccerRobotsPro/main/LICENSE
//SoccerRobotPro Firmware By UBER-BLACK
//██╗░░░██╗██████╗░███████╗██████╗░░░░░░░██████╗░██╗░░░░░░█████╗░░█████╗░██╗░░██╗
//██║░░░██║██╔══██╗██╔════╝██╔══██╗░░░░░░██╔══██╗██║░░░░░██╔══██╗██╔══██╗██║░██╔╝
//██║░░░██║██████╦╝█████╗░░██████╔╝█████╗██████╦╝██║░░░░░███████║██║░░╚═╝█████═╝░
//██║░░░██║██╔══██╗██╔══╝░░██╔══██╗╚════╝██╔══██╗██║░░░░░██╔══██║██║░░██╗██╔═██╗░
//╚██████╔╝██████╦╝███████╗██║░░██║░░░░░░██████╦╝███████╗██║░░██║╚█████╔╝██║░╚██╗
//░╚═════╝░╚═════╝░╚══════╝╚═╝░░╚═╝░░░░░░╚═════╝░╚══════╝╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝
//Copyright © UBER-BLACK Teem. 2023. All rights reserved.
//Dev THEBIGMISHA <http://GitHub.com/THEBIGMISHA>



//SETTINGS
///////////////////////////////////////////////////////////////////////////////////////////////
//            NAME              //   VALUE   //                   DESCRIPTION                //
#define Monitor_Speed             9600       //--
//
#define Gamepad_Monitor           false      //--
#define Gamepad_MonitorDelay      2000       //--
//
#define Gearbox_Monitor           false      //--
#define Gearbox_MonitorDelay      2000       //--
#define Gearbox_MaxSpeed          1          //--
#define Gearbox_MinSpeed          0.3        //--
#define Gearbox_MinPower          25         //--
#define Gearbox_DefGear           0          //--
#define Gearbox_MaxGear           5          //--
#define Gearbox_Delay             250        //--
//
#define Motor_Monitor             false      //--
#define Motor_MonitorDelay        2000       //--
#define MotorR_Reverse            false      //--
#define MotorL_Reverse            false      //--
#define MotorB_Reverse            false      //--
#define MotorF_Reverse            false      //--
//
#define Shockpanel_Monitor        false      //--
#define Shockpanel_MonitorDelay   2000       //--
#define Shockpanel_MiniGunDelay   20         //--
#define Shockpanel_MotorShotSpeed 255        //--
#define Shockpanel_MotorHoldSpeed 150        //--
//
#define Motion_ControlSens        0.45       //--
#define Motion_ControlRSens       1.00       //--
#define Motion_ControlLSens       1.00       //--
#define Motion_ControlBSens       1.00       //--
#define Motion_DriftSens          1.00       //--
#define Motion_DriftRFactor       0.58       //--
#define Motion_DriftLFactor       0.58       //--
#define Motion_DriftBFactor       0.98       //--



//PINS I/O
/////////////////////////////////////////////
//            NAME              //   PIN   //
#define Gamepad_Data              2
#define Gamepad_Command           3
#define Gamepad_Clock             4
#define Gamepad_Attention         5
//
#define Solinoid                  7
//
#define Motor_Standby             8
#define MotorR_Power              6
#define MotorR_Plus               A0
#define MotorR_Minus              A1
#define MotorL_Power              9
#define MotorL_Plus               A2
#define MotorL_Minus              A3
#define MotorB_Power              10
#define MotorB_Plus               A4
#define MotorB_Minus              A5
#define MotorF_Power              11
#define MotorF_Plus               12
#define MotorF_Minus              13



//LIBS
#include <PS2X_lib.h>     //By (NONAME)
#include <GyverMotor2.h>  //By @AlexGyver 
PS2X PS2X;
GMotor2<DRIVER3WIRE>MotorR(MotorR_Plus, MotorR_Minus, MotorR_Power);
GMotor2<DRIVER3WIRE>MotorL(MotorL_Plus, MotorL_Minus, MotorL_Power);
GMotor2<DRIVER3WIRE>MotorB(MotorB_Plus, MotorB_Minus, MotorB_Power);
GMotor2<DRIVER3WIRE>MotorF(MotorF_Plus, MotorF_Minus, MotorF_Power);



//CLASES
class Motion{
  public:
    setup(double ControlSens, double ControlRSens, double ControlLSens, double ControlBSens, double DriftSens, double DriftRFactor, double DriftLFactor, double DriftBFactor){
      _ControlSens      = constrain(ControlSens,0,1);
      _ControlRSens     = constrain(ControlRSens,0,1);
      _ControlLSens     = constrain(ControlLSens,0,1);
      _ControlBSens     = constrain(ControlBSens,0,1);
      _DriftSens        = constrain(DriftSens,0,1);
      _DriftRFactor     = constrain(DriftRFactor,0,1);
      _DriftLFactor     = constrain(DriftLFactor,0,1);
      _DriftBFactor     = constrain(DriftBFactor,0,1); }
    gamepadPS2X(){
      int16_t LY = PS2X.Analog(PSS_LY);
      int16_t LX = PS2X.Analog(PSS_LX);
      int16_t RY = PS2X.Analog(PSS_RY);
      int16_t RX = PS2X.Analog(PSS_RX);
      gamepadManual(LY, LX, RY, RX, 0, 255); }
    gamepadManual(int16_t LY, int16_t LX, int16_t RY, int16_t RX, int16_t MaxIn, int16_t MinIn){
      _Gamepad_LY = constrain(MegaMap(LY, MinIn, MaxIn, _Gamepad_Min, _Gamepad_Max), _Gamepad_Min, _Gamepad_Max);
      _Gamepad_LX = constrain(MegaMap(LX, MinIn, MaxIn, _Gamepad_Max, _Gamepad_Min), _Gamepad_Min, _Gamepad_Max);
      _Gamepad_RY = constrain(MegaMap(RY, MinIn, MaxIn, _Gamepad_Min, _Gamepad_Max), _Gamepad_Min, _Gamepad_Max);
      _Gamepad_RX = constrain(MegaMap(RX, MinIn, MaxIn, _Gamepad_Max, _Gamepad_Min), _Gamepad_Min, _Gamepad_Max); }
    int16_t APISpMotorSpd(){
      return _Gamepad_CY(); }
    int16_t GetMotor(uint8_t Number){
      formula();
      return _Motor[Number]; }
    double GetData(uint8_t Number){
      switch (Number) {
        case 1: //GET CONTROL SENS
          return _ControlSens;
          break;
        case 2: //GET CONTROL SENS (RIGHT)
          return _ControlRSens;
          break;
        case 3: //GET CONTROL SENS (LEFT)
          return _ControlLSens;
          break;
        case 4: //GET CONTROL SENS (BACK)
          return _ControlBSens;
          break;
        case 5: //GET DRIFT SENS
          return _DriftSens;
          break;
        case 6: //GET DRIFT FACTOR (RIGHT)
          return _DriftRFactor;
          break;
        case 7: //GET DRIFT FACTOR (LEFT)
          return _DriftLFactor;
          break;
        case 8: //GET DRIFT FACTOR (BACK)
          return _DriftBFactor;
          break;
        case 9: //GET GAMEPAD ASIX LY
          return _Gamepad_LY;
          break;
        case 10://GET GAMEPAD ASIX LX
          return _Gamepad_LX;
          break;
        case 11://GET GAMEPAD ASIX RY
          return _Gamepad_RY;
          break;
        case 12://GET GAMEPAD ASIX RX
          return _Gamepad_RX;
          break;
        case 13://GET GAMEPAD ASIX CY
          return _Gamepad_CY();
          break;
        default:
          return 0;
          break; } }
  private:
    formula(){
      int16_t MotorR = 0;
      int16_t MotorL = 0;
      int16_t MotorB = 0;
      //Move
      MotorR = (MotorR + _Gamepad_CY());
      MotorL = (MotorL + _Gamepad_CY() * -1);
      //Rotate
      MotorR = (MotorR + (_Gamepad_LX) * _ControlRSens * _ControlSens *-1);
      MotorL = (MotorL + (_Gamepad_LX) * _ControlLSens * _ControlSens *-1);
      MotorB = (MotorB + (_Gamepad_LX) * _ControlBSens * _ControlSens *-1);
      //Drift
      MotorR = (MotorR + (_Gamepad_RX) * _DriftRFactor * _DriftSens *-1);
      MotorL = (MotorL + (_Gamepad_RX) * _DriftLFactor * _DriftSens *-1);
      MotorB = (MotorB + (_Gamepad_RX) * _DriftBFactor * _DriftSens *1);
      //End
      _Motor[0] = MotorR;
      _Motor[1] = MotorL;
      _Motor[2] = MotorB;}
    int16_t _Gamepad_CY(){
      if (abs(_Gamepad_LY) >= abs(_Gamepad_RY))return _Gamepad_LY;
      else if (abs(_Gamepad_LY) < abs(_Gamepad_RY))return _Gamepad_RY; }
    double MegaMap(double Value, double MinIn, double MaxIn, double MinOut, double MaxOut){
      double Map = (Value - MinIn) * (MaxOut - MinOut) / (MaxIn - MinIn) + MinOut;
      return Map; }
    //Value
    int16_t _Motor[2];
    double _GeneralSens;
    double _ControlSens;
    double _ControlRSens;
    double _ControlLSens;
    double _ControlBSens;
    double _DriftSens;
    double _DriftRFactor;
    double _DriftLFactor;
    double _DriftBFactor;
    int16_t _Gamepad_Min = -200; //DON'T TOUCH
    int16_t _Gamepad_Max = 200;  //DON'T TOUCH
    int16_t _Gamepad_LY;
    int16_t _Gamepad_LX;
    int16_t _Gamepad_RY;
    int16_t _Gamepad_RX; 
};
class Gearbox{
  public:
    setup(double MaxSpeed, double MinSpeed, uint8_t MinPower, uint8_t MaxGear, uint8_t DefGear, uint16_t Delay){
      _MaxSpeed = constrain(MaxSpeed,0,1);
      _MinSpeed = constrain(MinSpeed,0,1);
      _MinPower = constrain(MinPower,0,255);
      _MaxGear  = constrain(MaxGear,0,255);
      _DutyGear = constrain(DefGear,0,255);
      _Delay    = constrain(Delay,0,65535); }
    shifterPS2X(){
      shifterManual(PS2X.Button(PSB_L1), PS2X.Button(PSB_R1)); }
    shifterManual(bool KeyDOWN, bool KeyUP){
      if (KeyUP and KeyDOWN)BOOST();
      else if (KeyUP)UP();
      else if (KeyDOWN)DOWN(); }
    UP(){
      if (millis() - _Timer0 >= _Delay) {
        _Timer0 = millis();
        if (_DutyGear >= _MaxGear)_DutyGear = _MaxGear;
        else _DutyGear++;
      } }
    DOWN(){
      if (millis() - _Timer0 >= _Delay) {
        _Timer0 = millis();
        if (_DutyGear <= 0)_DutyGear = 0;
        else _DutyGear--;
      } }
    BOOST() {
      _DutyGear = _MaxGear; }
    FREEZE() {
      _DutyGear = 0; }
    int16_t GetSpeed(uint8_t Number, int16_t OriginalSpeed){
      int16_t Speed = OriginalSpeed * DutySpeed();
      if (abs(Speed) >= _MinPower){
        _Brake[Number]=false;
        return Speed;
      }
      else {
        _Brake[Number]=true;
        return 0;
      }
    }
    int16_t GetBrake(uint8_t Number){
      return _Brake[Number];
    }
    double GetData(uint8_t Number){
      switch (Number) {
        case 0: //GET MAX SPEED
          return _MaxSpeed;
          break;
        case 1: //GET MIN SPEED
          return _MinSpeed;
          break;
        case 2: //GET MIN POWER
          return _MinPower;
          break;
        case 3: //GET MAX GEAR
          return _MaxGear;
          break;
        case 4: //GET DUTY GEAR
          return _DutyGear;
          break;
        case 5: //GET DELAY
          return _Delay;
          break;
        case 6: //GET DUTY SPEED
          return DutySpeed();
          break;
        default:
          return 0;
          break; } }
  private:
    double DutySpeed(){
      return MegaMap(_DutyGear,0,_MaxGear,_MinSpeed,_MaxSpeed); }
    double MegaMap(double Value, double MinIn, double MaxIn, double MinOut, double MaxOut){
      double Map = (Value - MinIn) * (MaxOut - MinOut) / (MaxIn - MinIn) + MinOut;
      return Map; }
    //Values
    double _MaxSpeed;
    double _MinSpeed;
    uint8_t _MinPower;
    uint8_t _MaxGear;
    uint8_t _DutyGear;
    uint16_t _Delay;
    bool _Brake[4];
    //Timers
    uint32_t _Timer0;
};
class Shockpanel{

};
Motion Motion;
Gearbox Gearbox;
void setup() {
  //CODE
  PWM();
  pinMode(Motor_Standby, OUTPUT);
  digitalWrite(Motor_Standby,HIGH);
  //LIBS
  PS2X.config_gamepad(Gamepad_Clock, Gamepad_Command, Gamepad_Attention, Gamepad_Data, 0, 0);
  Serial.begin(Monitor_Speed);
  MotorR.reverse(MotorR_Reverse);
  MotorL.reverse(MotorL_Reverse);
  MotorB.reverse(MotorB_Reverse);
  MotorF.reverse(MotorF_Reverse);
  //CLASES
  Gearbox.setup(Gearbox_MaxSpeed, Gearbox_MinSpeed, Gearbox_MinPower, Gearbox_MaxGear, Gearbox_DefGear, Gearbox_Delay);
  Motion.setup(Motion_ControlSens, Motion_ControlRSens, Motion_ControlLSens, Motion_ControlBSens, Motion_DriftSens, Motion_DriftRFactor, Motion_DriftLFactor, Motion_DriftBFactor);
  Serial.println("SoccerRobotPro Firmware: It Works!");
  Serial.println("Copyright © UBER-BLACK. 2023. All rights reserved.");
  Serial.println("Dev @THEBIGMISHA");
}
void loop() {
  PS2X.read_gamepad(0, 0);
  Motion.gamepadPS2X();
  Gearbox.shifterPS2X();
  MotorR.setSpeed(Gearbox.GetSpeed(0,Motion.GetMotor(0)));
  MotorL.setSpeed(Gearbox.GetSpeed(1,Motion.GetMotor(1)));
  MotorB.setSpeed(Gearbox.GetSpeed(2,Motion.GetMotor(2)));
  MotorF.setSpeed(Gearbox.GetSpeed(3,255));
  if(Gearbox.GetBrake(0))MotorR.brake();
  if(Gearbox.GetBrake(1))MotorL.brake();
  if(Gearbox.GetBrake(2))MotorB.brake();
  if(Gearbox.GetBrake(3))MotorF.brake();
}



//FUNC
void PWM(){
  //D5 & D6
  //TCCR0B = 0b00000001;  // x1
  //TCCR0A = 0b00000011;  // fast pwm
  //D9 & D10
  TCCR1A = 0b00000001;  // 8bit
  TCCR1B = 0b00001001;  // x1 fast pwm
  //D3 & D11
  TCCR2B = 0b00000111;  // x1024
  TCCR2A = 0b00000001;  // phase correct
}
void PWM_underclock(){
  //FOR FUNNY
  //D5 & D6
  //TCCR0B = 0b00000101;  // x1024
  //TCCR0A = 0b00000001;  // phase correct
  //D9 & D10
  TCCR1A = 0b00000001;  // 8bit
  TCCR1B = 0b00000100;  // x256 phase correct
  //D3 & D11
  TCCR2B = 0b00000111;  // x1024
  TCCR2A = 0b00000001;  // phase correct
}