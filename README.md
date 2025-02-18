# LVGL ported to the Discovery kit with STM32H735IG MCU

![image](https://i.imgur.com/Xy2hXGr.jpeg)


## Overview
The STM32H735G-DK Discovery kit is a complete demonstration and development platform for Arm® Cortex®-M7 core-based STM32H735IGK6 microcontroller, with 1 Mbyte of flash memory and 564 Kbytes of SRAM.

![image](https://i.imgur.com/0GZJ0KM.jpeg)

The STM32H735G-DK Discovery kit is used as a reference design for user application development before porting to the final product, thus simplifying the application development.

The full range of hardware features available on the board helps users to enhance their application development by an evaluation of all the peripherals (such as USB OTG FS, Ethernet, microSD™ card, USART, CAN FD, SAI audio DAC stereo with audio jack input and output, MEMS digital microphone, HyperRAM™, Octo‑SPI flash memory, RGB interface LCD with capacitive touch panel, and others). ARDUINO® Uno V3, Pmod™ and STMod+ connectors provide easy connection to extension shields or daughterboards for specific applications.

STLINK-V3E is integrated into the board, as the embedded in-circuit debugger and programmer for the STM32 MCU and USB Virtual COM port bridge.

### Buffer configuration
The example is configured for 32-bit XRGB888 color format, which is the native color format of the panel. The project uses [LVGL's LTDC driver](https://docs.lvgl.io/master/details/integration/driver/display/st_ltdc.html) in double-buffered partial rendering. A single buffer requires 510kB memory. 
All buffers are located in the external OctaSPI RAM with size of 16MB and only 1.49MB is used.
The external OctaSPI flash is in memory mapped mode where you can store images etc to the external flash (Include external Loader in the debug configuration of STM32CubeIDE from ExternalLoader folder).



## Specification

### CPU and memory

- **MCU** STM32H735IGK6 ARM Cortex M7 MCU
- **RAM** 564KB
- **Flash** 1MB
- **GPU** Chrom-Art (DMA2D)

### Display

- **Resolution** 480x272
- **Display size** 4.3”
- **Color depth** 24bit
- **Touch pad** Projected Capacitive

## Getting started
Downlod the project, improt it to your workspace, build and run it on your STM32H735G-DK board.

### Hardware setup
Connect your micro-usb cable to STLK (CN15) and the other end to your PC.
### Software setup
- Install [STM32 CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html).

### Run the project
- Clone the project: `git clone --recursive https://github.com/hussamaldean/LvGL-V9-Port-STM32H735G-DK.git`
- Open *STM32CubeIDE* and import project:` File => Open Projects from File System... => Directory => Select the "STM32CubeIde" folder => Finish`
- Build the project (for the best performance use *Release* configuration with *-O2* flag): `Project => Build Project`
- Click the ![image](https://github.com/lvgl/lv_port_riverdi_70-stm32h7/assets/7599318/ad1ba904-f917-4e0c-97b3-1c1ca12cf185) Run button to flash the project

- ### Debugging
- After building the project click the Debug button ![image](https://github.com/lvgl/lv_port_riverdi_70-stm32h7/assets/7599318/369e95fb-dbfb-44d8-9250-0a5f3f8bfc60) to flash the project. You will need to select the correct debug probe for the first run.

