/*********************************************************************************************
 **                                                                                         **
 ** @author         : Ilker MORAL                                                           **
 ** @version        : 1                                                                     **
 ** @email          : ilkermoral@gmail.com                                                  **
 ** @since          : Sep  3 09:39:26 2014                                                  **
 ** @compiled with  : G++ GCC4.2.1 (MacOS Mavericks)                                        **
 *********************************************************************************************/

#include "TermiosSerialCom.h"

/************Global Variables*************/
struct termios tio;
struct termios stdio;
struct termios old_stdio;
int tty_fd;
unsigned char c;
/************Global Variables*************/

/**
 * Opens serialport with given parameters.
 *
 * @param portName
 * @param baudRate
 */
void openSerialPort(string portName, int baudrate) {
    printf("Connecting :  %s\n", portName.c_str());
    
    tcgetattr(STDOUT_FILENO,&old_stdio);
    
    memset(&stdio,0,sizeof(stdio));
    stdio.c_iflag=0;
    stdio.c_oflag=0;
    stdio.c_cflag=0;
    stdio.c_lflag=0;
    stdio.c_cc[VMIN]=1;
    stdio.c_cc[VTIME]=0;
    tcsetattr(STDOUT_FILENO,TCSANOW,&stdio);
    tcsetattr(STDOUT_FILENO,TCSAFLUSH,&stdio);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
    
    memset(&tio,0,sizeof(tio));
    tio.c_iflag=0;
    tio.c_oflag=0;
    tio.c_cflag=CS8|CREAD|CLOCAL;
    tio.c_lflag=0;
    tio.c_cc[VMIN]=1;
    tio.c_cc[VTIME]=5;
    
    tty_fd=open(portName.c_str(), O_RDWR | O_NONBLOCK);
    cfsetospeed(&tio,baudrate);
    cfsetispeed(&tio,baudrate);
    
    tcsetattr(tty_fd,TCSANOW,&tio);
    
}

/**
 * Closes serialport.
 *
 */
void closeSerialPort() {
    close(tty_fd);
    tcsetattr(STDOUT_FILENO,TCSANOW,&old_stdio);
}

/**
 * Sends message using serial port
 *
 * @param message
 */
void writeSerialPort(char* message) {
    write(tty_fd, message, sizeof(message));
    usleep(4000 * sizeof(message));
}

/**
 * Reads serial port until message is finished.
 *
 * @return result
 */
char* readSerialPort() {
    char* result;
    char* dummyResult;
    int index = 0;

    result = (char*) malloc(sizeof(char));
    dummyResult = (char*) malloc(sizeof(char));
    
    while(1) {
        int size = read(tty_fd,&c,1);

        if (size < 0)
            break;
        index++;

        dummyResult = (char*) realloc (result, index * sizeof(char));
        
        if (dummyResult!=NULL) {
            result=dummyResult;
            result[index-1]=c;
        }
        else {
            free (result);
            cerr << "\nError (re)allocating memory" << endl;
            exit (1);
        }
    }
    
    return result;
}
