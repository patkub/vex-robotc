#pragma config(Sensor, in1,    linefollower,   sensorLineFollower)
#pragma config(Sensor, dgtl5,  OutputBeltSonar, sensorSONAR_mm)
#pragma config(Motor,  port6,           WhipCreamMotor, tmotorVex393, openLoop)
#pragma config(Motor,  port7,           InputBeltMotor, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           ElevatorMotor, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           OutputBeltMotor, tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
  Project Title:	Cookie Maker
  Team Members:	Patka
  Date:
  Section:


  Task Description:	Control cookie maker machine


  Pseudocode:
  	Move input conveior belt set distance
  	Move elevator set distance
  	Move output conveior belt until whip cream
  	Press whip cream
  	Reset whip cream
  	Move output conveior belt to end
  	Reset elevator
*/

task main()
{                                     //Program begins, insert code within curly braces
	while (true)
	{
		//Input Conveior Belt
		startMotor(InputBeltMotor, 127);
		wait(2.5);
		stopMotor(InputBeltMotor);

		//Elevator
		startMotor(ElevatorMotor, 127);
		wait(1.5);
		stopMotor(ElevatorMotor);

		//Move Cookie To line follower
		do
		{
			startMotor(OutputBeltMotor, -127);
		}
		while(SensorValue(linefollower) > 2900);
		stopMotor(OutputBeltMotor);

		//Reset Elevator
		startMotor(ElevatorMotor, -127);
		wait(2);
		stopMotor(ElevatorMotor);

		//Move Cookie To Whip Cream
		startMotor(OutputBeltMotor, -127);
		wait(0.4);
		stopMotor(OutputBeltMotor);

		//Whip Cream Press
		startMotor(WhipCreamMotor, -127);
		wait(1);
		stopMotor(WhipCreamMotor);

		//Whip Cream Reset
		startMotor(WhipCreamMotor, 127);
		wait(0.9);
		stopMotor(WhipCreamMotor);

		//Output Conveior Belt
		startMotor(OutputBeltMotor, -127);
		wait(2);
	}
}
