/**
 * @file sendtext.cpp
 * @brief File containing example of sending a text message over serial port
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

    string message = "";

    if (argc > 2) {
        serial_port = argv[1];
        message = argv[2];
    }
    else {
        printf("Usage: %s port message\n", argv[0]);
        printf("example: %s /dev/cu.usbserial-0001 'hello'\n", argv[0]);
        return(-1);
    }

    // Connection to serial port
    char errorOpening = serial.openDevice(serial_port.c_str(), 921600);


    // If connection fails, return the error code otherwise, display a success message
    if (errorOpening!=1) return errorOpening;
    printf("Successful connection to %s\n", serial_port.c_str());

    Data data = Data();
    data.set_payload(message);
    data.set_portnum(TEXT_MESSAGE_APP);

    MeshPacket packet = MeshPacket();
    packet.set_channel(0);
    // packet.set_allocated_decoded(data);

    // TODO
    //packet.decoded.set_payload(message);
    //packet.decoded.set_portnum(TEXT_MESSAGE_APP);
    packet.set_to(0xffffffff); // broadcast
    packet.set_want_ack(false);
    packet.set_hop_limit(3);
    packet.set_id(0); // TODO: set random

    ToRadio toRadio = ToRadio();

    // Close the serial device
    serial.closeDevice();

    return(0);
}
