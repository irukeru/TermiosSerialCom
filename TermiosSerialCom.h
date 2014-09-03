/*********************************************************************************************
 **                                                                                         **
 ** @author         : Ilker MORAL                                                           **
 ** @version        : 1                                                                     **
 ** @email          : ilkermoral@gmail.com                                                  **
 ** @since          : Sep  3 13:34:55 2014                                                  **
 ** @compiled with  : G++ GCC4.2.1 (MacOS Mavericks)                                        **
**********************************************************************************************/

#ifndef TERMIOSSERIALCOM_H
#define TERMIOSSERIALCOM_H

/***************Libraries*****************/
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <iostream>
/***************Libraries*****************/

using namespace std;

/**
 * Opens serialport with given parameters.
 *
 * @param portName
 * @param baudRate
 */
void openSerialPort(string, int);


/**
 * Closes serialport.
 *
 */
void closeSerialPort();

/**
 * Sends message using serial port
 *
 * @param message
 */
void writeSerialPort(char*);

/**
 * Reads serial port until message is finished.
 *
 * @return result
 */
char* readSerialPort();


#endif
