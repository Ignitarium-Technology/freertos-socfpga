## Ethernet Demo App
This is a sample Ethernet demo application using the Ethernet stack. <br>
One of the sample can be selected in file **main_freertosplus_basic/main_freertosplus_basic.h** <br>

Following are the available samples, *only one can be enabled at a time* <br>
        * DEMO_PING<br>
        The device will ping an externel machine (define the externel device IP in the same header file) <br>
        * DEMO_TCP<br>
        A sample TCP server, use port 9640 (can be changed in the header file), server will acknowledge the messages recieved <br>
        * DEMO_UDP<br>
        A sample UDP app, use port 8897 (can be changed in the header file) <br>
        * DEMO_ECHOTCP<br>
        A TCP server which will echo back any message sent to it <br>
        * DEMO_IPERF<br>
        Will run an Iperf server instance <br>
        * Default app is **DEMO_ECHOTCP**

**1. Building the app**

The project uses cmake to setup the build<br>

**1.1 Build using standard make build system**

Configure cmake build. Specify the desired build directory.
```bash
cmake -B <build-dir> .
```
Build .elf alone
```bash
cmake --build <build-dir>
```
Build SD image
```bash
cmake --build <build-dir> -t sd-image
```
Build qspi image
```bash
cmake --build <build-dir> -t qspi-image
```
Build eMMC image
```bash
cmake --build <build-dir> -t emmc-image
```
**1.2 Build using ninja build system**

Configure cmake <build-dir>
```bash
cmake -B <build-dir> -G Ninja
```
Build .elf alone
```bash
ninja -C <build-dir>
```
Build SD image
```bash
ninja -C <build-dir> sd-image
```
Build qspi image
```bash
ninja -C <build-dir> qspi-image
```
Build eMMC image
```bash
ninja -C <build-dir> emmc-image
