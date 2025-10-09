## Freertos OS sample APPs

This folder contains some basic freertos sample apps and tests

1. Basic CLI application
    * A simple CLI app which exposes basic features of various drivers available in the platform
2. Ethernet sample application
    * Sample APPs using the the ethernet stack
    * one of the sample can be selected in file **main_freertosplus_basic/main_freertosplus_basic.h**<br>
    Following are the available samples, *only one can be enabled at a time*
        * DEMO_PING<br>
        The device will ping an externel machine (define the externel device IP in the same header file)
        * DEMO_TCP<br>
        A sample TCP server, use port 9640 (can be changed in the header file), server will acknowledge the messages recieved
        * DEMO_UDP<br>
        A sample UDP app, use port 8897 (can be changed in the header file)
        * DEMO_ECHOTCP<br>
        A TCP server which will echo back any message sent to it
        * DEMO_IPERF<br>
        Will run an Iperf server instance
        * Default app is **DEMO_ECHOTCP**
3. OS tests
    * This test basic kernel functionalities
    * Enable/disable the tests ifn FreeRTOSConfig.h file in directory<br>
    **FreeRTOS/Demo/CORTEX_A55_SOCFPGA/FreeRTOSConfig.h**
    * By default all tests are enabled.
4. FreeRTOS blinky app
    * A simple blinky app which queues and dequeues a message in the queue<br>
    the dequeued message is printed in the console


**Building the APPs**

The project uses cmake to setup the build<br>
This app adds Agilex5 FreeRTOS port as dependency<br>

To build any application, navigate to the application folder and execute the below commands:-
```bash
cmake -B build .
cmake --build build
```
