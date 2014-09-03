/*********************************************************************************************
 **                                                                                         **
 ** @author         : Ilker MORAL                                                           **
 ** @version        : 1                                                                     **
 ** @email          : ilkermoral@gmail.com                                                  **
 ** @since          : Sep  3 13:38:11 2014                                                  **
 ** @compiled with  : G++ GCC4.2.1 (MacOS Mavericks)                                        **
**********************************************************************************************/

#include "TermiosSerialCom.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;


char message[] = "rx\n";

int main(void) {

    openSerialPort("/dev/tty.usbserial-FTP25FYT", 115200);

    int i = 0;

    while (i < 2) {
        writeSerialPort(message);
        char* readChar = readSerialPort();

        cout << static_cast<string>(readChar);

        i++;
        sleep(5);
    }

    closeSerialPort();

    return EXIT_SUCCESS;
}
