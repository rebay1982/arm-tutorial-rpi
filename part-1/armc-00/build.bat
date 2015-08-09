@ECHO OFF

arm-none-eabi-gcc -O2 -mfpu=vfp -mfloat-abi=hard -march=armv6zk -nostartfiles -mtune=arm1176jzf-s -g armc-00.c -o kernel.elf
pause
