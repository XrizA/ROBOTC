#pragma config(Motor, motorB, leftWheel, tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor, motorC, rightWheel, tmotorEV3_Large, PIDControl, driveRight, encoder)

#define PWR 55
#define NPWR -65
#define THRESHOLD 35
#define GOSTRAIGHT 50

task main()
{
	while (true)
	{
		// 2 white, 3 black -> left
		if (getColorReflected(S2) > THRESHOLD && getColorReflected(S3) < THRESHOLD)
		{
			motor[leftWheel] = NPWR;
			motor[rightWheel] = PWR;
		}
                // 2 black, 3 white -> right
		else if (getColorReflected(S2) < THRESHOLD && getColorReflected(S3) > THRESHOLD)
		{
			motor[leftWheel] = PWR;
			motor[rightWheel] = NPWR;
		}
                // 2 white black, 3 white black -> Go straight
		else
		{
			motor[leftWheel] = GOSTRAIGHT;
			motor[rightWheel] = GOSTRAIGHT;
		}
	}
}
