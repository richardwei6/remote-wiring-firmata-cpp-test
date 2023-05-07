#include <chrono>
#include <iostream>
#include <thread>

#include <remote_wiring>
#include <serial_wiring>

using namespace remote_wiring::boards::arduino::uno;  // change to your board
using namespace remote_wiring::wiring;

int main(int, char**) {
    std::cout << "Hello, world!\n";

    //
    serial_wiring::UartSerial usb("/dev/cu.usbmodem1101");
    remote_wiring::FirmataDevice board(usb);

    // Establish a communication channel
    usb.begin(57600);

    // Attach to the remote device
    board.attach();

    // Survey the board's capabilities
    // (not necessary but allows for error checking)
    board.survey();

    // Initialize digital pin LED_BUILTIN as an output
    board.pinMode(LED_BUILTIN, OUTPUT);

    // Issue commands to the remote device via the Wiring API
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    board.digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    board.digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
    std::this_thread::sleep_for(std::chrono::milliseconds(100));  // allow time for the serial to send

    // Clean-up and exit
    board.detach();
    usb.end();
    return 0;
}
