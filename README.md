## Getting started

This repository contains FreeRTOS port for Agilex5 HPS. The FreeRTOS code is added
as a submodule inside this repository.

For FreeRTOS kernel feature information refer to the
[Developer Documentation](https://www.freertos.org/Documentation/02-Kernel/02-Kernel-features/00-Developer-docs),
and [API Reference](https://www.freertos.org/Documentation/02-Kernel/04-API-references/01-Task-creation/00-TaskHandle).

For building the projects manually, refer to this [link](tools/README.md)

## Getting the toolchain

The toolchain can be downloaded from ARM developer website
[Here](https://developer.arm.com/-/media/Files/downloads/gnu/14.3.rel1/binrel/arm-gnu-toolchain-14.3.rel1-x86_64-aarch64-none-elf.tar.xz) is the link for downloading the toolchain

### Installing the toolchain

```bash
AARCH64_TOOLCHAINPATH=<toolchain path>
mkdir -p $AARCH64_TOOLCHAINPATH
cd $AARCH64_TOOLCHAINPATH
cp <download folder>/arm-gnu-toolchain-14.3.rel1-x86_64-aarch64-none-elf.tar.xz .
tar -xf arm-gnu-toolchain-14.3.rel1-x86_64-aarch64-none-elf.tar.xz
rm arm-gnu-toolchain-14.3.rel1-x86_64-aarch64-none-elf.tar.xz
export PATH=$AARCH64_TOOLCHAINPATH/arm-gnu-toolchain-14.3.rel1-x86_64-aarch64-none-elf/bin/:$PATH
```
## Getting Quartus
Follow the steps in the official website.<br>
Download and install Quartus

## Building project

The following steps will generate a qspi image which can be flashed into the PDK

### setup the repository

```bash
git clone git@github.com:Ignitarium-Technology/freertos-socfpga.git
git submodule update --init --recursive
```

### Compiling the project
**1. Set up the toolchain, and Quartus**
- Export Quartus path required to build jic file. **Note** Quartus needs to be exported only if you are planning to build qspi image.
```bash
export QUARTUS_ROOTDIR=~/altera_pro/25.3/quartus/
export PATH=$QUARTUS_ROOTDIR/bin:$QUARTUS_ROOTDIR/linux64:$QUARTUS_ROOTDIR/../qsys/bin:$PATH
```
- Export the toolchain path.
```bash
AARCH64_TOOLCHAINPATH=<toolchain path>
export PATH=$AARCH64_TOOLCHAINPATH/arm-gnu-toolchain-14.3.rel1-x86_64-aarch64-none-elf/bin/:$PATH
```
**2. Configuring the builds**<br>

The following parameters can be configured during the cmake configuration stage.
- **Debug vs Release**<br>
	The build system by default builds Release by default. To build debug application, specify `-DCMAKE_BUILD_TYPE=Debug` when configuring the cmake build.
- **Atf log level**<br>
	The default atf debug level is set to `LOG_LEVEL_NOTICE`. If a different atf debug log level is required, specify the log level using the parameter `-DATF_LOG_LEVEL=<log-level-value>` when configuring the cmake build.
- **Sof file**<br>
	By default, it the build uses the **ghrd_a5ed065bb32ae6sr0.sof** available in the project folder. If a different sof needs to be used, it can be configured using the `-DSOF_PATH=<sof path>` during the cmake.
- **Pfg file**<br>
	If no pfg is specified, it downloads a default pfg file and uses it in the build process. If a custom pfg file needs to be used, it can be provided using the `-DPFG_PATH=<pfg path>`

**3. Building the sample APPS**

* Hello world app <br>
    For build steps, check the [hello_world README](FreeRTOS/Demo/CORTEX_A55_SOCFPGA/apps/hello_world/README.md).
* Driver samples<br>
    For build steps, check the [driver samples README](samples/README.md).
* OS samples<br>
    **Cli App**<br>
        For build steps, check the [cli app README](FreeRTOS/Demo/CORTEX_A55_SOCFPGA/apps/samples/cli_app/README.md).<br>

    **OS tests**<br>
        For build steps, check the [main_full README](FreeRTOS/Demo/CORTEX_A55_SOCFPGA/apps/samples/main_full/README.md).<br>

    **Blinky App**<br>
        For build steps, check the [Blinky sample README](FreeRTOS/Demo/CORTEX_A55_SOCFPGA/apps/samples/main_blinky/README.md).<br>

    **Ethernet demo app**<br>
        For build steps, check the [enet demo sample README](FreeRTOS/Demo/CORTEX_A55_SOCFPGA/apps/samples/main_freertosplus_basic/README.md).<br>

**4. Flashing and running**

For initial device setup, follow this [document](https://altera-fpga.github.io/rel-25.1/embedded-designs/agilex-5/e-series/premium/gsrd/ug-gsrd-agx5e-premium/)<br>
Put the device in JTAG mode to flash the JIC image, refer [Changing MSEL](https://altera-fpga.github.io/rel-25.1/embedded-designs/agilex-5/e-series/premium/gsrd/ug-gsrd-agx5e-premium/#development-kit) section.<br>
After setting the MSEL Turn on the device, Use the following command to flash the firmware to the device.
```bash
#use the image qspi_image.jic
quartus_pgm -c 1 -m jtag -o "piv;<image name>.jic"
```

