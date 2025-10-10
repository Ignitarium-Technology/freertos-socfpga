## Sample APPs for drivers
This folder contains various sample applications for all the available drivers in this platform

**1. Building the app**

The project uses cmake to setup the build<br>

Each sample application needs to be built from the respective project folder.

**1.1 Building using standard make build system**

Configure cmake build. Specify the desired build directory.
```bash
cmake -B <build-dir> .
```
Build .elf alone
```bash
cmake --build <build-dir>
```
Build SD card image
```bash
cmake --build <build-dir> -t sd-image
```
Build QSPI image
```bash
cmake --build <build-dir> -t qspi-image
```
**1.2 Building using ninja build system**

Configure cmake build
```bash
cmake -B <build-dir> -G Ninja
```
Build .elf alone
```bash
ninja -C <build-dir>
```
Build SD card image
```bash
ninja -C <build-dir> sd-image
```
Build qspi image
```bash
ninja -C <build-dir> qspi-image
```
