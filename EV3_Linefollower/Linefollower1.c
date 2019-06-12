#pragma config(Motor, motorB, leftWheel, tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor, motorC, rightWheel, tmotorEV3_Large, PIDControl, driveRight, encoder)

#define THRESHOLD 50

task main()
{
	while (true)
	{
		setMotorSync(leftWheel, rightWheel, 20, 45);
		if (getColorReflected(S2) > THRESHOLD)
		{
			motor[leftWheel] = 0;
			motor[rightWheel] = 50;
		}
		else
		{
			motor[leftWheel] = 50;
			motor[rightWheel] = 0;
		}
		wait1Msec(1000);
	}
}
