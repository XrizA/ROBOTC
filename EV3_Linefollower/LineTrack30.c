#pragma config(Motor,  motorB,          leftWheel,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightWheel,    tmotorEV3_Large, PIDControl, driveRight, encoder)

#define PWR 50
#define NPWR 0
#define THRESHOLD 35
#define GOSTRAIGHT 30

task main()
{
	int leftLight = 0;
	int rightLight = 0;
	while (true)
	{
		leftLight = getColorReflected(S2);
		rightLight = getColorReflected(S3);
		if (leftLight > THRESHOLD && rightLight < THRESHOLD)
		{
			motor[rightWheel] = PWR;
			motor[leftWheel] = NPWR;
		}
		else if (leftLight < THRESHOLD && rightLight > THRESHOLD)
		{
			motor[leftWheel] = PWR;
			motor[rightWheel] = NPWR;
		}
		else
		{
			motor[leftWheel] = GOSTRAIGHT;
			motor[rightWheel] = GOSTRAIGHT;
		}
	}
}
