#pragma config(Sensor, S3,     colour,         sensorEV3_Color)
//#pragma config(Sensor, S1,     LeftLight,      sensorEV3_Color)
//#pragma config(Sensor, S2,     RightLight,     sensorEV3_Color)

#pragma config(Motor,  motorB,          leftwheel,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightwheel,    tmotorEV3_Large, PIDControl, encoder)

int nMotorSpeedSetting = 30;
float nPfactor = 0.3;
int grey = 50;
int lowest = 100;
int highest = 0;

void scanLine()
{
	motor[leftwheel] = 10;
	motor[rightwheel] = -10;

	time1[T1] = 0;
	while (time1[T1] < 500)
	{
		if (SensorValue[colour] > highest)
			highest = SensorValue[colour]
		if (SensorValue[colour] < lowest)
			lowest = SensorValue[colour]
	}
	grey = (highest - lowest) / 2;
	motor[leftwheel] = 0;
	motor[rightwheel] = 0;
}

task main()
{
  float error;
  scanLine();
  while (true)
  {
    error = SensorValue[colour] - grey;
    motor[leftwheel] = nMotorSpeedSetting - round(error * nPfactor);
    motor[rightwheel] = nMotorSpeedSetting + round(error * nPfactor);
    wait1Msec(50);
  }
}
