## Hello world APP
This is a sample FreeRTOS Hello world application which will periodically print the string "hello world" to the console
(console is configured as UART 0)

**1. Building the app**

The project uses cmake to setup the build<br>

**1.1 Build using standard make build system**

Configure cmake build. Specify the desired build directory.
```bash
cmake -B <build-dir> . -DCMAKE_BUILD_TYPE=Release -DSOC=AGILEX5 -DCORE=A55 -DSOF_PATH=<path to .sof file> -DPFG_SDMMC=<.pfg for sd/mmc> -DPFG_QSPI=<.pfg for qspi>
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

Configure cmake build
```bash
cmake -B <build-dir> . -G Ninja -DCMAKE_BUILD_TYPE=Release -DSOC=AGILEX5 -DCORE=A55 -DSOF_PATH=<path to .sof file> -DPFG_SDMMC=<.pfg for sd/mmc> -DPFG_QSPI=<.pfg for qspi>
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
```

