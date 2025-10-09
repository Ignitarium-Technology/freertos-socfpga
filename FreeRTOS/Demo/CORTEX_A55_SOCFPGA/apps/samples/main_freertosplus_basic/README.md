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
This app adds Agilex5 FreeRTOS port as dependency

**1.1 Building using standard make build system**

Configure cmake build
```bash
cmake -B build .
```
Build .elf alone
```bash
cmake --build build
```
Build SD image
```bash
cmake --build build -t sd-image
```
Build QSPI image
```bash
cmake --build build -t qspi-image
```
Build eMMC image
```bash
cmake --build build -t emmc-image
```
**1.2 Building using ninja build system**

Configure cmake build
```bash
cmake -B build -G Ninja
```
Build .elf alone
```bash
ninja -C build
```
Build SD image
```bash
ninja -C build sd-image
```
Build QSPI image
```bash
ninja -C build qspi-image
```
Build eMMC image
```bash
ninja -C build emmc-image
```

**2. Setting up the SD card**

Insert the SD card and find the block device path ( if the device is enumerated as /dev/mmcblk0)
Eg:
```bash
    dd of=/dev/mmcblk0 if=sd.img bs=1M status=progress
```

**3. Output files**

After build the following can be found in the build directory
1. sd.img : SD card image
2. qspi_image.jic : QSPI image
