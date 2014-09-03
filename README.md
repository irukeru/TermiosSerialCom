TermiosSerialCom
================

Open source serial communication library for C/C++

Usage
================

#include "TermiosSerialCom.h" is enough to start to use.

Useful functions are:

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
