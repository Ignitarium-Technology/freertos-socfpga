## Hello world APP
This is a sample FreeRTOS Hello world app which will periodically print the string "hello world" to the console
(console is configured as UART 0)

**1. Building the app**

The project uses cmake to setup the build<br>
This app adds Agilex5 FreeRTOS port as dependency

**1.1 Build using standard make build system**

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
Build qspi image
```bash
cmake --build build -t qspi-image
```
Build eMMC image
```bash
cmake --build build -t emmc-image
```
**1.2 Build using ninja build system**

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
Build qspi image
```bash
ninja -C build qspi-image
```
Build eMMC image
```bash
ninja -C build emmc-image
```

**2. Setup the sd card**

Insert the sd card and find the block device path ( if the device is enumerated as /dev/mmcblk0)
Eg:
```bash
    dd of=/dev/mmcblk0 if=sd.img bs=1M status=progress
```

**3. output files**

after build the following can be found in the build directory
1. sd.img : SD card image
2. qspi_image.jic : QSPI image
