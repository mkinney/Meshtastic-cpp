/**
 * @file open_port.cpp
 * @brief File containing example of serial port communication
 *
 * This example opens serial port
 *
 * Note: Copied from the serialib example1
 *
 */


// Serial library
#include "serialib.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

// bring in the nanopb library
#include "pb_encode.h"
#include "pb_decode.h"
#include "pb_common.h"

// bring in the generated protobuf code
#include "admin.pb.h"
#include "apponly.pb.h"
#include "cannedmessages.pb.h"
#include "channel.pb.h"
#include "deviceonly.pb.h"
#include "mesh.pb.h"
#include "mqtt.pb.h"
#include "portnums.pb.h"
#include "radioconfig.pb.h"
#include "remote_hardware.pb.h"
#include "storeforward.pb.h"
#include "telemetry.pb.h"

using std::string;


/*!
 * \brief main  Open serial port
 * \return      0 : success
 *              <0 : an error occured
 */
int main(int argc, char *argv[]) {
    // Serial object
    serialib serial;

    string serial_port = "";
    string serial_port_prefix = "";
#if defined (_WIN32) || defined(_WIN64)
    //for serial ports above "COM9", we must use this extended syntax of "\\.\COMx".
    //also works for COM0 to COM9.
    //https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilea?redirectedfrom=MSDN#communications-resources
    serial_port_prefix = "\\\\.\\"
#endif
//#if defined (__linux__) || defined(__APPLE__)
    //#define SERIAL_PORT "/dev/cu.usbserial-0001"
//#endif

    if (argc > 1) {
        serial_port = argv[1];
    }
    else {
        printf("Usage: %s port\n", argv[0]);
        printf("example: %s /dev/cu.usbserial-0001\n", argv[0]);
        return(-1);
    }

    // Connection to serial port
    char errorOpening = serial.openDevice(serial_port.c_str(), 921600);


    // If connection fails, return the error code otherwise, display a success message
    if (errorOpening!=1) return errorOpening;
    printf("Successful connection to %s\n", serial_port.c_str());

    ToRadio startConfig = ToRadio();

    // Display ASCII characters (from 32 to 128)
    /*
    for (int c=32;c<128;c++)
    {
        serial.writeChar(c);
        usleep(10000);
    }
    */

    // Close the serial device
    serial.closeDevice();

    return(0);
}
