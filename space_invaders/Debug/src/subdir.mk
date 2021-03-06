################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bitmap.c \
../src/collisions.c \
../src/control.c \
../src/dma_screencap.c \
../src/explosion.c \
../src/fastinvader1.c \
../src/fastinvader2.c \
../src/fastinvader3.c \
../src/fastinvader4.c \
../src/invaderkilled.c \
../src/letters.c \
../src/pit_timer.c \
../src/platform.c \
../src/renderer.c \
../src/shoot.c \
../src/space_invaders_main.c \
../src/tankFireSound.c \
../src/ufo_explosion.c \
../src/ufo_highpitch.c \
../src/ufo_lowpitch.c \
../src/xac97_l.c 

LD_SRCS += \
../src/lscript.ld 

OBJS += \
./src/bitmap.o \
./src/collisions.o \
./src/control.o \
./src/dma_screencap.o \
./src/explosion.o \
./src/fastinvader1.o \
./src/fastinvader2.o \
./src/fastinvader3.o \
./src/fastinvader4.o \
./src/invaderkilled.o \
./src/letters.o \
./src/pit_timer.o \
./src/platform.o \
./src/renderer.o \
./src/shoot.o \
./src/space_invaders_main.o \
./src/tankFireSound.o \
./src/ufo_explosion.o \
./src/ufo_highpitch.o \
./src/ufo_lowpitch.o \
./src/xac97_l.o 

C_DEPS += \
./src/bitmap.d \
./src/collisions.d \
./src/control.d \
./src/dma_screencap.d \
./src/explosion.d \
./src/fastinvader1.d \
./src/fastinvader2.d \
./src/fastinvader3.d \
./src/fastinvader4.d \
./src/invaderkilled.d \
./src/letters.d \
./src/pit_timer.d \
./src/platform.d \
./src/renderer.d \
./src/shoot.d \
./src/space_invaders_main.d \
./src/tankFireSound.d \
./src/ufo_explosion.d \
./src/ufo_highpitch.d \
./src/ufo_lowpitch.d \
./src/xac97_l.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: MicroBlaze gcc compiler
	mb-gcc -Wall -O3 -g3 -c -fmessage-length=0 -I../../space_invaders_bsp/microblaze_0/include -mlittle-endian -mxl-barrel-shift -mxl-pattern-compare -mcpu=v8.20.b -mno-xl-soft-mul -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo Finished building: $<
	@echo ' '


