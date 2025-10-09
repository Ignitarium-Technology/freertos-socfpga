## Sample APPs for drivers
This folder contains various sample applications for all the available drivers in this platform

**1. Building the app**

The project uses cmake to setup the build<br>
This app adds Agilex5 FreeRTOS port as dependency

Each sample application needs to be built from the respective project folder.

**1.1 Building using standard make build system**

Configure cmake build
```bash
cmake -B build .
```
Build .elf alone
```bash
cmake --build build
```
Build SD card image
```bash
cmake --build build -t sd-image
```
Build QSPI image
```bash
cmake --build build -t qspi-image
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
Build SD card image
```bash
ninja -C build sd-image
```
Build qspi image
```bash
ninja -C build qspi-image
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
