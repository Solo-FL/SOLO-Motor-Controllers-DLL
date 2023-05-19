// Copyright: (c) 2021-2023, SOLO motor controllers project
// GNU General Public License v3.0+ (see COPYING or https://www.gnu.org/licenses/gpl-3.0.txt)

/*
*    Title: SOLO Motor Controllers DLL
*    Author: SOLOMotorControllers
*    Date: 2023
*    Code version: 1.0.0
*    Availability: https://github.com/Solo-FL/SOLO-Motor-Controllers-DLL
This Library is made by SOLOMotorControllers.com
To learn more please visit:  https://www.SOLOMotorControllers.com/
*/

//#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;

#include <conio.h>
#include<windows.h>
#include "SoloDLLUART_CPP64.h"

float readVal;

int i=0;
int main(void)
{
	bool status = FALSE;
	int error;
	SOLOMotorControllersSerial *solo1 = new SOLOMotorControllersSerial((char*)"COM3", 0, SOLOMotorControllersSerial::UartBaudrate::rate115200, 50, 3, false);

	std::cout << "Test1 Run:" << std::endl;

	// solo1 = new SOLOMotorControllersSerial((char*)"COM6", 0, SOLOMotorControllers::UartBaudrate::rate115200, 50, 3, false);

	do{
		status = solo1->Connect();

		if (status)
		{
			std::cout << "solo1 Succesfully Conneced" << std::endl;
		}

		else
		{
			std::cout << "solo1 Can't Connect" << std::endl;
		}
	}while(!status);
	

	do{
		i++;
		readVal = solo1->GetBusVoltage(error);
		if (readVal != -1)
		{
			std::cout << "Readed Value from solo1 is: " << readVal << std::endl;
		}
		else
		{
			std::cout << "Failed to Read solo1 Variable.Error is:" << error << std::endl;
			solo1->Disconnect();
			Sleep(1000);
			solo1->Connect();
		}
	}while(i<20);

	solo1->Disconnect();

	cout << "Press Enter to Exit";
	getch();
	return 0;
}