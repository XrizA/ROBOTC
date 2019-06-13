#pragma config(Motor, motorB, leftWheel, tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor, motorC, rightWheel, tmotorEV3_Large, PIDControl, driveRight, encoder)

#define THRESHOLD 35

task main()
{
	while (true)
	{

		if (getColorReflected(S2) > THRESHOLD) setMotorSync(leftWheel, rightWheel, -55, 100);
		else if (getColorReflected(S3) > THRESHOLD) setMotorSync(leftWheel, rightWheel, 55, 100);
		else setMotorSync(leftWheel, rightWheel, 0, 35);
	}
}
