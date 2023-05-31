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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//            NAME              //   VALUE   //                                             LINK TO THE GUIDE                                               //
#define Monitor_Speed             9600       //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#monitor_speed
//
#define Gamepad_Monitor           false      //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#name_monitor
#define Gamepad_MonitorDelay      2000       //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#name_monitordelay
//
#define Gearbox_Monitor           false      //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#name_monitor
#define Gearbox_MonitorDelay      2000       //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#name_monitordelay
#define Gearbox_MaxSpeed          0.9        //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#gearbox_maxspeed
#define Gearbox_MinSpeed          0.4        //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#gearbox_minspeed
#define Gearbox_MinPower          20         //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#gearbox_minpower
#define Gearbox_DefGear           0          //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#gearbox_defgear
#define Gearbox_MaxGear           5          //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#gearbox_maxgear
#define Gearbox_AutoBrake         true       //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#gearbox_autobrake
#define Gearbox_Delay             250        //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#gearbox_delay
//
#define Motor_Monitor             false      //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#name_monitor
#define Motor_MonitorDelay        2000       //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#name_monitordelay
#define MotorR_Reverse            false      //
#define MotorL_Reverse            false      //
#define MotorB_Reverse            false      //
#define MotorF_Reverse            false      //
//
#define Shockpanel_Monitor        false      //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#name_monitor
#define Shockpanel_MonitorDelay   2000       //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#name_monitordelay
#define Shockpanel_MinigunDelay   20         //
#define Shockpanel_ShotSpeed      255        //
#define Shockpanel_HoldSpeed      255        //
#define Shockpanel_NormSpeed      50         //
#define Shockpanel_APIBoost       0.5        //
#define Shockpanel_Delay          150        //
//
#define Motion_Monitor            false      //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#name_monitor
#define Motion_MonitorDelay       2000       //https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/firmware#name_monitordelay
#define Motion_ControlSens        0.40       //--
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
#define Gamepad_Data              2        //NOT RECOMMENDED TO CHANGE
#define Gamepad_Command           3        //NOT RECOMMENDED TO CHANGE
#define Gamepad_Clock             4        //NOT RECOMMENDED TO CHANGE
#define Gamepad_Attention         5        //NOT RECOMMENDED TO CHANGE
//
#define Solinoid_Pin              7        //NOT RECOMMENDED TO CHANGE
//
#define Motor_Standby             8        //NOT RECOMMENDED TO CHANGE
#define MotorR_Power              6        //NOT RECOMMENDED TO CHANGE
#define MotorR_Plus               A0       //NOT RECOMMENDED TO CHANGE
#define MotorR_Minus              A1       //NOT RECOMMENDED TO CHANGE
#define MotorL_Power              9        //NOT RECOMMENDED TO CHANGE
#define MotorL_Plus               A2       //NOT RECOMMENDED TO CHANGE
#define MotorL_Minus              A3       //NOT RECOMMENDED TO CHANGE
#define MotorB_Power              10       //NOT RECOMMENDED TO CHANGE
#define MotorB_Plus               A4       //NOT RECOMMENDED TO CHANGE
#define MotorB_Minus              A5       //NOT RECOMMENDED TO CHANGE
#define MotorF_Power              11       //NOT RECOMMENDED TO CHANGE
#define MotorF_Plus               12       //NOT RECOMMENDED TO CHANGE
#define MotorF_Minus              13       //NOT RECOMMENDED TO CHANGE



//LIBS
#include <PS2X_lib.h>     //By @madsci1016 (Bill Porter) GitHub:https://github.com/madsci1016/Arduino-PS2X LICENSE: NO FOUND!
#include <GyverMotor2.h>  //By @GyverLibs (AlexGyver) GitHub:https://github.com/GyverLibs/GyverMotor LICENSE:https://raw.githubusercontent.com/GyverLibs/GyverMotor/main/LICENSE
PS2X PS2X;
GMotor2<DRIVER3WIRE>MotorR(MotorR_Plus,MotorR_Minus,MotorR_Power);
GMotor2<DRIVER3WIRE>MotorL(MotorL_Plus,MotorL_Minus,MotorL_Power);
GMotor2<DRIVER3WIRE>MotorB(MotorB_Plus,MotorB_Minus,MotorB_Power);
GMotor2<DRIVER3WIRE>MotorF(MotorF_Plus,MotorF_Minus,MotorF_Power);



//MONITOR OPTIMIZATION
#if (Gearbox_Monitor)//Creating a delay variable
uint32_t Timer0 = Gearbox_MonitorDelay;
#endif
#if (Gamepad_Monitor)//Creating a delay variable
uint32_t Timer1 = Gamepad_MonitorDelay;
#endif
#if (Motor_Monitor)//Creating a delay variable
uint32_t Timer2 = Motor_MonitorDelay;
#endif
#if (Shockpanel_Monitor)//Creating a delay variable
uint32_t Timer3 = Shockpanel_MonitorDelay;
#endif



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
      _DriftBFactor     = constrain(DriftBFactor,0,1);}
    gamepadPS2X(){
      int16_t LY = PS2X.Analog(PSS_LY);
      int16_t LX = PS2X.Analog(PSS_LX);
      int16_t RY = PS2X.Analog(PSS_RY);
      int16_t RX = PS2X.Analog(PSS_RX);
      gamepadManual(LY, LX, RY, RX, 0, 255);}
    gamepadManual(int16_t LY, int16_t LX, int16_t RY, int16_t RX, int16_t MaxIn, int16_t MinIn){
      _Gamepad_LY = constrain(MegaMap(LY, MinIn, MaxIn, _Gamepad_Min, _Gamepad_Max), _Gamepad_Min, _Gamepad_Max);
      _Gamepad_LX = constrain(MegaMap(LX, MinIn, MaxIn, _Gamepad_Max, _Gamepad_Min), _Gamepad_Min, _Gamepad_Max);
      _Gamepad_RY = constrain(MegaMap(RY, MinIn, MaxIn, _Gamepad_Min, _Gamepad_Max), _Gamepad_Min, _Gamepad_Max);
      _Gamepad_RX = constrain(MegaMap(RX, MinIn, MaxIn, _Gamepad_Max, _Gamepad_Min), _Gamepad_Min, _Gamepad_Max);}
    int16_t API_OUT_SHOCKPANEL(){
      return _Gamepad_CY();}
    int16_t GetMotor(uint8_t Number){
      formula();
      return _Motor[Number];}
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
          return -1;
          break;}}
    SetData(uint8_t Number, double Value){
      switch (Number) {
        case 1: //SET CONTROL SENS
          _ControlSens = Value;
          break;
        case 2: //SET CONTROL SENS (RIGHT)
          _ControlRSens = Value;
          break;
        case 3: //SET CONTROL SENS (LEFT)
          _ControlLSens = Value;
          break;
        case 4: //SET CONTROL SENS (BACK)
          _ControlBSens = Value;
          break;
        case 5: //SET DRIFT SENS
          _DriftSens = Value;
          break;
        case 6: //SET DRIFT FACTOR (RIGHT)
          _DriftRFactor = Value;
          break;
        case 7: //SET DRIFT FACTOR (LEFT)
          _DriftLFactor = Value;
          break;
        case 8: //SET DRIFT FACTOR (BACK)
          _DriftBFactor = Value;
          break;
        case 9: //SET GAMEPAD ASIX LY
          _Gamepad_LY = Value;
          break;
        case 10://SET GAMEPAD ASIX LX
          _Gamepad_LX = Value;
          break;
        case 11://SET GAMEPAD ASIX RY
          _Gamepad_RY = Value;
          break;
        case 12://SET GAMEPAD ASIX RX
          _Gamepad_RX = Value;
          break;
        default:
          return -1;
          break;}}
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
      else if (abs(_Gamepad_LY) < abs(_Gamepad_RY))return _Gamepad_RY;}
    double MegaMap(double Value, double MinIn, double MaxIn, double MinOut, double MaxOut){
      double Map = (Value - MinIn) * (MaxOut - MinOut) / (MaxIn - MinIn) + MinOut;
      return Map;}
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
    int16_t _Gamepad_RX;};
class Gearbox{
  public:
    setup(double MaxSpeed, double MinSpeed, uint8_t MinPower, uint8_t MaxGear, uint8_t DefGear, uint16_t Delay){
      _MaxSpeed = constrain(MaxSpeed,0,1);
      _MinSpeed = constrain(MinSpeed,0,1);
      _MinPower = constrain(MinPower,0,255);
      _MaxGear  = constrain(MaxGear,0,255);
      _DutyGear = constrain(DefGear,0,255);
      _Delay    = constrain(Delay,0,65535);}
    gamepadPS2X(){
      gamepadManual(PS2X.Button(PSB_L1), PS2X.Button(PSB_R1));}
    gamepadManual(bool KeyDOWN, bool KeyUP){
      if (KeyUP and KeyDOWN)BOOST();
      else if (KeyUP)UP();
      else if (KeyDOWN)DOWN();}
    UP(){
      if (millis() - _Timer0 >= _Delay){
        _Timer0 = millis();
        if (_DutyGear >= _MaxGear)_DutyGear = _MaxGear;
        else _DutyGear++;}}
    DOWN(){
      if (millis() - _Timer0 >= _Delay){
        _Timer0 = millis();
        if (_DutyGear <= 0)_DutyGear = 0;
        else _DutyGear--;}}
    BOOST(){
      _DutyGear = _MaxGear;}
    FREEZE(){
      _DutyGear = 0;}
    int16_t GetSpeed(uint8_t Number, int16_t OriginalSpeed){
      int16_t Speed = OriginalSpeed * DutySpeed();
      Speed = constrain(Speed,-255,255);
      if (abs(Speed) >= _MinPower){
        _Brake[Number]=false;
        return Speed;}
      else{
        _Brake[Number]=true;
        return 0;}}
    int16_t GetBrake(uint8_t Number){
      return _Brake[Number];}
    SetData(uint8_t Number, double Value){
      switch (Number){
        case 0: //SET MAX SPEED
          _MaxSpeed = Value;
          break;
        case 1: //SET MIN SPEED
          _MinSpeed = Value;
          break;
        case 2: //SET MIN POWER
          _MinPower = Value;
          break;
        case 3: //SET MAX GEAR
          _MaxGear = Value;
          break;
        case 4: //SET DUTY GEAR
          _DutyGear = Value;
          break;
        case 5: //SET DELAY
          _Delay = Value;
          break;
        default:
          return -1;
          break;}}
    double GetData(uint8_t Number){
      switch (Number){
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
          return -1;
          break;}}
  private:
    double DutySpeed(){
      return MegaMap(_DutyGear,0,_MaxGear,_MinSpeed,_MaxSpeed);}
    double MegaMap(double Value, double MinIn, double MaxIn, double MinOut, double MaxOut){
      double Map = (Value - MinIn) * (MaxOut - MinOut) / (MaxIn - MinIn) + MinOut;
      return Map;}
    //Values
    double _MaxSpeed;
    double _MinSpeed;
    uint8_t _MinPower;
    uint8_t _MaxGear;
    uint8_t _DutyGear;
    uint16_t _Delay;
    bool _Brake[4];
    //Timers
    uint32_t _Timer0 = _Delay;};
class Shockpanel{
  public:
    setup(uint8_t MinigunDelay, uint8_t SolinoidPin, uint8_t ShotSpeed, uint8_t HoldSpeed, uint8_t NormSpeed, double APIBoost, uint16_t Delay){
    _MinigunDelay = constrain(MinigunDelay,0,255);
    _SolinoidPin  = constrain(SolinoidPin,0,255);
    _ShotSpeed    = constrain(ShotSpeed,0,255);
    _HoldSpeed    = constrain(HoldSpeed,0,255);
    _NormSpeed    = constrain(NormSpeed,0,255);
    _APIBoost     = constrain(APIBoost,0,255);
    _Delay        = constrain(Delay,0,65535);
    pinMode(_SolinoidPin, OUTPUT);}
    gamepadPS2X(){
      gamepadManual(PS2X.Button(PSB_L2), PS2X.Button(PSB_R2), PS2X.Button(PSB_SELECT));}
    gamepadManual(bool keyHold, bool keySHOT, bool keyMODE){
      if (keyMODE)MODE();
      if (keyHold and keySHOT)MINIGUN();
      else if (keySHOT)SHOT();
      else if (keyHold)HOLD();
      else NORM();}
    MINIGUN(){
      if (millis() - _Timer0 >= _MinigunDelay){
          _flag0 = !_flag0;
          solinoid(_flag0);
          _DutySpeed = -255;
          _Timer0 =  millis();}}
    SHOT(){
      if (millis() - _Timer1 >= _Delay){
        solinoid(1);
        _DutySpeed = (_ShotSpeed *-1);
        _Timer1 =  millis();}}
    HOLD(){
      if (millis() - _Timer1 >= _Delay){
        solinoid(0);
        _DutySpeed = _HoldSpeed;
        _Timer1 =  millis();}}
    NORM(){
      if (millis() - _Timer1 >= _Delay){
        solinoid(0);
        if (!_flag2){
          if (_flag1)_DutySpeed = _NormSpeed+(_APISpeed * _APIBoost);
          else _DutySpeed = _NormSpeed;
        }
        else _DutySpeed = 0;
        _Timer1 =  millis();}}
    MODE(){
      if (millis() - _Timer0 >= _Delay*2){
        _flag2 = !_flag2;
        NORM();
        _Timer0 =  millis();}}
    solinoid(bool State){
      digitalWrite(_SolinoidPin, State);}
    int16_t GetShaft(){
      return _DutySpeed;}
    API_IN_Motion(int16_t API1){
      _flag1 = true;
      _APISpeed = (API1 *-1);
      _APISpeed = constrain(_APISpeed,-255,255);}
    SetData(uint8_t Number, double Value){
      switch (Number){
        case 0: //SET MAX SPEED
          _SolinoidPin = Value;
          break;
        case 1: //SET MINIGUN DELAY
          _MinigunDelay = Value;
          break;
        case 2: //SET SHOT SPEED
          _ShotSpeed = Value;
          break;
        case 3: //SET HOLD SPEED
          _HoldSpeed = Value;
          break;
        case 4: //SET NORM SPEED
          _NormSpeed = Value;
          break;
        case 5: //SET DUTY SPEED
          _DutySpeed = Value;
          break;
        case 6: //SET API SPEED
          _APISpeed = Value;
          break;
        case 7: //SET API BOOST
          _APIBoost = Value;
          break;
        case 8: //SET DELAY
          _Delay = Value;
          break;
        default:
          return -1;
          break;}}
    double GetData(uint8_t Number){
      switch (Number){
        case 0: //GET MAX SPEED
          return _SolinoidPin;
          break;
        case 1: //GET MINIGUN DELAY
          return _MinigunDelay;
          break;
        case 2: //GET SHOT SPEED
          return _ShotSpeed;
          break;
        case 3: //GET HOLD SPEED
          return _HoldSpeed;
          break;
        case 4: //GET NORM SPEED
          return _NormSpeed;
          break;
        case 5: //GET DUTY SPEED
          return _DutySpeed;
          break;
        case 6: //GET API SPEED
          return _APISpeed;
          break;
        case 7: //GET API BOOST
          return _APIBoost;
          break;
        case 8: //GET DELAY
          return _Delay;
          break;
        default:
          return -1;
          break;}}
  private:
    //Values
    uint8_t _SolinoidPin;
    uint8_t _MinigunDelay;
    uint8_t _ShotSpeed;
    uint8_t _HoldSpeed;
    uint8_t _NormSpeed;
    int16_t _DutySpeed;
    int16_t _APISpeed;
    double _APIBoost;
    uint16_t _Delay;
    //Flags
    bool _flag0;  //MINIGUN
    bool _flag1;  //API
    bool _flag2;  //MODE
    //Timers
    uint32_t _Timer0 = _MinigunDelay;
    uint32_t _Timer1 = _Delay;};
Motion Motion;//Creating an object
Gearbox Gearbox;//Creating an object
Shockpanel Shockpanel;//Creating an object
void setup(){//Here the code is executed once
  //CODE
  WELCOME(); //Welcome text
  //PWM();//SOON
  pinMode(Motor_Standby, OUTPUT); //Setting the driver activation output
  digitalWrite(Motor_Standby,HIGH); //Activating the driver
  //LIBS
  PS2X.config_gamepad(Gamepad_Clock,Gamepad_Command,Gamepad_Attention,Gamepad_Data,0,0);//Applying the settings
  Serial.begin(Monitor_Speed);//Applying the settings
  MotorR.reverse(MotorR_Reverse);//Applying the settings
  MotorL.reverse(MotorL_Reverse);//Applying the settings
  MotorB.reverse(MotorB_Reverse);//Applying the settings
  MotorF.reverse(MotorF_Reverse);//Applying the settings
  //CLASES
  Gearbox.setup(Gearbox_MaxSpeed,Gearbox_MinSpeed,Gearbox_MinPower,Gearbox_MaxGear,Gearbox_DefGear,Gearbox_Delay);//Applying the settings
  Shockpanel.setup(Shockpanel_MinigunDelay,Solinoid_Pin,Shockpanel_ShotSpeed,Shockpanel_HoldSpeed,Shockpanel_NormSpeed,Shockpanel_APIBoost,Shockpanel_Delay);//Applying the settings
  Motion.setup(Motion_ControlSens,Motion_ControlRSens,Motion_ControlLSens,Motion_ControlBSens,Motion_DriftSens,Motion_DriftRFactor,Motion_DriftLFactor,Motion_DriftBFactor);//Applying the settings
}
void loop(){//Here the code is executed in an infinite loop
  PS2X.read_gamepad(0,0);//Communication with the gamepad
  Motion.gamepadPS2X();//Receiving then processing gamepad data
  Gearbox.gamepadPS2X();//Receiving then processing gamepad data
  Shockpanel.gamepadPS2X();//Receiving then processing gamepad data
  Shockpanel.API_IN_Motion(Motion.API_OUT_SHOCKPANEL());//Automatic Shaft API
  MotorR.setSpeed(Gearbox.GetSpeed(0,Motion.GetMotor(0)));//Receiving then setting the speed of the right motor
  MotorL.setSpeed(Gearbox.GetSpeed(1,Motion.GetMotor(1)));//Receiving then setting the speed of the left motor
  MotorB.setSpeed(Gearbox.GetSpeed(2,Motion.GetMotor(2)));//Receiving then setting the speed of the back motor
  MotorF.setSpeed(Shockpanel.GetShaft());//Receiving then setting the speed of the front motor
  if(Gearbox.GetBrake(0) and Gearbox_AutoBrake)MotorR.brake();//Automatic brake on the right hand motor
  if(Gearbox.GetBrake(1) and Gearbox_AutoBrake)MotorL.brake();//Automatic brake on the left hand motor
  if(Gearbox.GetBrake(2) and Gearbox_AutoBrake)MotorB.brake();//Automatic brake on the back hand motor
}



//FUNCTIONS
void WELCOME(){//Important text when starting the program
  Serial.println("SoccerRobotPro Firmware. It Works!");
  Serial.println("Copyright © UBER-BLACK. 2023. All rights reserved.");
  Serial.println("Dev @THEBIGMISHA");
  }
void PWM(){//Changing the parameters of the (variable) PWM frequency
  //D5 & D6 DON'T TOUCH!
  //TCCR0B = 0b00000001;
  //TCCR0A = 0b00000011;
  //D9 & D10
  TCCR1A = 0b00000001;
  TCCR1B = 0b00001001;
  //D3 & D11
  TCCR2B = 0b00000111;
  TCCR2A = 0b00000001;}
