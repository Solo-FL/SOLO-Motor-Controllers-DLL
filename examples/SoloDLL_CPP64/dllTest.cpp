
// Copyright: (c) 2021, SOLO motor controllers project
// GNU General Public License v3.0+ (see COPYING or https://www.gnu.org/licenses/gpl-3.0.txt)

/*
*    Title: SOLO Motor Controllers DLL
*    Author: SOLOMotorControllers
*    Date: 2022
*    Code version: 0.0.0
*    Availability: https://github.com/Solo-FL/SOLO-motor-controllers-DLL
This Library is made by SOLOMotorControllers.com
To learn more please visit:  https://www.SOLOMotorControllers.com/
*/

#include <iostream>
using std::cout, std::endl;

#include <conio.h>

#include "SoloDLL_CPP64.h"

//change val for new value set
float val = 19.43;

float readVal;

int main(void)
{
    bool status = FALSE;
    int error;
    SOLOMotorControllers solo1, solo2;

    //TRY CONNECT LOOP
    while(status == false ){
        status = solo1.serialSetup(0, (char *)"COM3", 115200);
        if(status)
        {
            std::cout << "Solo Succesfully Conneced! " << std::endl;
        }
        else
        {
            std::cout << "Solo connection failed. Retry" << std::endl;
            Sleep(500);
        }
    }

    //first object read/write test
    //test write function 
    status = solo1.SetCurrentLimit(val, error);

    if(status)
    {
        std::cout << "Succesfully to Set solo1 Variable.Error is:" << error << std::endl;
    }
    else
    {
        std::cout << "Failed to set solo1 Variable.Error is:" <<  error << std::endl;
    }

    //test read function 
    //PRINT LOOP
    for(int i=0;i<100; i++)
    {
        readVal = solo1.GetBusVoltage(error);
        if(error == SOLOMotorControllers::SOLOMotorControllersError::noErrorDetected)
        {
            std::cout << "Succesfully read from solo, Value: " << readVal << std::endl;
        }
        else
        {
            std::cout << "Failed to set solo, Error: " <<  error << std::endl;
        }
    }
    
    solo1.Disconnect();
    ////////////////

    cout << "Press Enter to test the second SOLO";
    getch();

    //TRY CONNECT LOOP
    status = false;
    while(status == false ){
        status = solo2.serialSetup(0, (char *)"COM5", 115200);
        if(status)
        {
            std::cout << "Readed Value from solo is: " << readVal << std::endl;
        }
        else
        {
            std::cout << "Failed to Read solo Variable.Error is:" << error << std::endl;
            Sleep(500);
        }
    }

    // second object read/write test
    // test write function 
    status = solo2.SetCurrentLimit(val, error);

    if(status)
    {
        std::cout << "Succesfully Set solo2 Variable" << std::endl;
    }
    else
    {
        std::cout << "Failed to set solo2 Variable.Error is:" << error << std::endl;
    }

    // test read function 
   //PRINT LOOP
    for(int i=0;i<100; i++)
    {
        readVal = solo2.GetBusVoltage(error);
        if(error == SOLOMotorControllers::SOLOMotorControllersError::noErrorDetected)
        {
            std::cout << "Succesfully read from solo, Value: " << readVal << std::endl;
        }
        else
        {
            std::cout << "Failed to set solo, Error: " <<  error << std::endl;
        }
    }
    solo2.Disconnect();
    cout << "Press Enter to Exit";

    getch();
    return 0;
}