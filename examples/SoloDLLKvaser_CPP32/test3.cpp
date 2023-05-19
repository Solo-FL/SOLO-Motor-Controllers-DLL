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
#include "SoloDLLKvaser_CPP32.h"

//change val for new value set
float val = 13.29;
float readVal;

void CheckForError(char cmd[50], canStatus stat);
void ListChannels();
void Check(const char* id, canStatus stat);

// Holds a handle to the CAN channel
canHandle hnd, hnd2;



// The CANlib channel number we would like to use
int channel_number = 0;

// The msg will be the body of the message we send on the CAN bus.
char msg[8];
long id;
unsigned int dlc, flags;
unsigned char rcvMsg[8];
DWORD timestamp;

int i=0;
int main(void)
{
	bool status = FALSE;
	int error;
	
	uint16_t ID ;
	uint8_t DLC; 
	uint8_t Data;

	SOLOMotorControllersKvaser *solo1, *solo2;

	solo2 = new SOLOMotorControllersKvaser(1, SOLOMotorControllers::CanbusBaudrate::rate1000, 500, false);

	do{
		status = solo2->Connect();

		if (status)
		{
			std::cout << "solo2 Succesfully Conneced" << std::endl;
		}

		else
		{
			std::cout << "solo2 Can't Connect" << std::endl;
		}
	}while(!status);
	

	do{
		//i++;
		readVal = solo2->GetBusVoltage(error);
		if (readVal != -1)
		{
			std::cout << "Readed Value from solo2 is: " << readVal << std::endl;
		}
		else
		{
			std::cout << "Failed to Read solo2 Variable.Error is:" << error << std::endl;
			solo2->Disconnect();
			Sleep(1000);
			solo2->Connect();
		}
	}while(i<20);

	solo2->Disconnect();

	cout << "Press Enter to Exit";
	getch();
	return 0;
}