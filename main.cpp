//============================================================================
// Name        : main.cpp
// Author      : Willi Penner
//
// Description : Contains the main function. It also contains test functions
//               to test the connection to the controller and the movement of
//       		 the servos.
//============================================================================

#include "SerialCom.hpp"
#include "Pololu.hpp"
#include "ServoMotor.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include<unistd.h>

using namespace std;

void close(ServoMotor *arm0);
void open(ServoMotor *arm0);
void startPosition(ServoMotor *arm0, ServoMotor *arm1, ServoMotor *arm2);
void getCube(ServoMotor *arm0, ServoMotor *arm1, ServoMotor *arm2);
void setCube(ServoMotor *arm0, ServoMotor *arm1, ServoMotor *arm2);
int startPos0 = 8166;
int Pos1 = 8800;
int Pos2 = 5750;

int Pos0 = startPos0;

int main()
{
	try{
		const char* portName = "/dev/ttyACM0";  // Mac
		Pololu conn(portName, 9600);
		// Open connection to COM port.
		conn.openConnection();
		conn.getErrors();

        
        
		// Define the servos of the robot manipulator
		ServoMotor arm_0(0, 6000, 4000	, &conn);
        ServoMotor arm_1(1, 6000, 4000  , &conn);
        ServoMotor arm_2(2, 6000, 4000  , &conn);
        ServoMotor arm_3(3, 6000, 4000  , &conn);

        arm_0.setAcceleration(40);
        arm_1.setAcceleration(40);
        arm_2.setAcceleration(40);


		unsigned short pMin, pMid, pMax;
		arm_0.showPololuValues(pMin,pMid,pMax);
		cout << pMin	<< " " << pMid << " " << pMax << endl;

        startPosition(&arm_0, &arm_1, &arm_2);
        open(&arm_3);
        
        getCube(&arm_0, &arm_1, &arm_2);
        close(&arm_3);
        
        startPosition(&arm_0, &arm_1, &arm_2);

        setCube(&arm_0, &arm_1, &arm_2);
        open(&arm_3);
        
        startPosition(&arm_0, &arm_1, &arm_2);

        getCube(&arm_0, &arm_1, &arm_2);
        close(&arm_3);
        
        startPosition(&arm_0, &arm_1, &arm_2);
        
        setCube(&arm_0, &arm_1, &arm_2);
        open(&arm_3);
        
        startPosition(&arm_0, &arm_1, &arm_2);

        getCube(&arm_0, &arm_1, &arm_2);
        close(&arm_3);
        
        startPosition(&arm_0, &arm_1, &arm_2);
        
        setCube(&arm_0, &arm_1, &arm_2);
        open(&arm_3);
        
        startPosition(&arm_0, &arm_1, &arm_2);

        getCube(&arm_0, &arm_1, &arm_2);
        close(&arm_3);
        
        startPosition(&arm_0, &arm_1, &arm_2);
        Pos0 = startPos0;
        
        setCube(&arm_0, &arm_1, &arm_2);
        open(&arm_3);
        startPosition(&arm_0, &arm_1, &arm_2);

        /*
        while(1)
		{
			cout << "servo 0:" << arm_0.getPositionInAbs() << "---------servo 1:" << arm_1.getPositionInAbs() << "---------servo 2:" << arm_2.getPositionInAbs() << "---------servo 3:" << arm_3.getPositionInAbs() << endl;
		}*/
        /*
		//arm_0.setMinMaxDegree(-45,45);
        arm_0.setSpeed(80);
		//arm_0.setPositionInDeg(degree1);
        arm_0.setPositionInAbs(degree1);

        //arm_1.setMinMaxDegree(-45,45);
        arm_1.setSpeed(80);
        arm_1.setAcceleration(80);
        //arm_1.setPositionInDeg(degree1);
        arm_1.setPositionInAbs(degree1);

        //arm_2.setMinMaxDegree(-45,45);
        arm_2.setSpeed(80);
        arm_2.setAcceleration(80);
        //arm_2.setPositionInDeg(degree1);
        arm_2.setPositionInAbs(degree1);

        arm_3.setMinMaxDegree(-45,45);
        arm_3.setSpeed(80);
        arm_3.setAcceleration(80);
        //arm_3.setPositionInDeg(degree1);
        arm_3.setPositionInAbs(degree1);
*/

/*
        cout << "Arm 1: " << arm_0.getMaxPosInAbs() << endl;
        cout << "max. pos.: " << arm_0.getMaxPosInAbs() << endl;
        cout << "min. pos.: " << arm_0.getMinPosInAbs() << endl;
        cout << "get current pos.: "  << arm_0.getPositionInAbs() << endl;
        
        
        cout << "Arm 2: " << arm_1.getMaxPosInAbs() << endl;
        cout << "max. pos.: " << arm_1.getMaxPosInAbs() << endl;
        cout << "min. pos.: " << arm_1.getMinPosInAbs() << endl;
        cout << "get current pos.: "  << arm_1.getPositionInAbs() << endl;
        
        cout << "Arm 3: " << arm_2.getMaxPosInAbs() << endl;
        cout << "max. pos.: " << arm_2.getMaxPosInAbs() << endl;
        cout << "min. pos.: " << arm_2.getMinPosInAbs() << endl;
        cout << "get current pos.: "  << arm_2.getPositionInAbs() << endl;
        
        cout << "Arm 4: " << arm_3.getMaxPosInAbs() << endl;
        cout << "max. pos.: " << arm_3.getMaxPosInAbs() << endl;
        cout << "min. pos.: " << arm_3.getMinPosInAbs() << endl;
        cout << "get current pos.: "  << arm_3.getPositionInAbs() << endl;
        
        arm_0.setPositionInAbs(7000);
        sleep(3);
        arm_0.setPositionInAbs(5000);
*/

		conn.closeConnection();

	}catch(IException *e){
		cout << e->getMsg() << endl;
	}catch(string e){
		cout << "string Error: " << e << endl;
	}catch(...){
		cout << "unknown error\n";
	}

	return 0;
}

void close(ServoMotor *arm3)
{
    arm3->setPositionInAbs(3100);
    sleep(1);
}

void open(ServoMotor *arm3)
{
    arm3->setPositionInAbs(6000);
    sleep(1);
}

void startPosition(ServoMotor *arm0, ServoMotor *arm1, ServoMotor *arm2)
{    
    arm1->setPositionInAbs(6399);
    sleep(1);
    arm2->setPositionInAbs(6232);
    sleep(1);
    arm0->setPositionInAbs(6388);
    sleep(1);
}

void getCube(ServoMotor *arm0, ServoMotor *arm1, ServoMotor *arm2)
{
    arm0->setPositionInAbs(Pos0);
    sleep(1);
    arm2->setPositionInAbs(Pos2);
    sleep(1);
    arm1->setPositionInAbs(Pos1);
    Pos0 = Pos0-1600;
    sleep(1);
}

void setCube(ServoMotor *arm0, ServoMotor *arm1, ServoMotor *arm2)
{
    arm0->setPositionInAbs(Pos0);
    sleep(1);
    arm1->setPositionInAbs(Pos1);
    sleep(1);
    arm2->setPositionInAbs(Pos2);
    sleep(1);
}
