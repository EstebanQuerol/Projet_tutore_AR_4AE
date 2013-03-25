################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/external/glfw-2.7.6/lib/enable.c \
../lib/external/glfw-2.7.6/lib/fullscreen.c \
../lib/external/glfw-2.7.6/lib/glext.c \
../lib/external/glfw-2.7.6/lib/image.c \
../lib/external/glfw-2.7.6/lib/init.c \
../lib/external/glfw-2.7.6/lib/input.c \
../lib/external/glfw-2.7.6/lib/joystick.c \
../lib/external/glfw-2.7.6/lib/stream.c \
../lib/external/glfw-2.7.6/lib/tga.c \
../lib/external/glfw-2.7.6/lib/thread.c \
../lib/external/glfw-2.7.6/lib/time.c \
../lib/external/glfw-2.7.6/lib/window.c 

OBJS += \
./lib/external/glfw-2.7.6/lib/enable.o \
./lib/external/glfw-2.7.6/lib/fullscreen.o \
./lib/external/glfw-2.7.6/lib/glext.o \
./lib/external/glfw-2.7.6/lib/image.o \
./lib/external/glfw-2.7.6/lib/init.o \
./lib/external/glfw-2.7.6/lib/input.o \
./lib/external/glfw-2.7.6/lib/joystick.o \
./lib/external/glfw-2.7.6/lib/stream.o \
./lib/external/glfw-2.7.6/lib/tga.o \
./lib/external/glfw-2.7.6/lib/thread.o \
./lib/external/glfw-2.7.6/lib/time.o \
./lib/external/glfw-2.7.6/lib/window.o 

C_DEPS += \
./lib/external/glfw-2.7.6/lib/enable.d \
./lib/external/glfw-2.7.6/lib/fullscreen.d \
./lib/external/glfw-2.7.6/lib/glext.d \
./lib/external/glfw-2.7.6/lib/image.d \
./lib/external/glfw-2.7.6/lib/init.d \
./lib/external/glfw-2.7.6/lib/input.d \
./lib/external/glfw-2.7.6/lib/joystick.d \
./lib/external/glfw-2.7.6/lib/stream.d \
./lib/external/glfw-2.7.6/lib/tga.d \
./lib/external/glfw-2.7.6/lib/thread.d \
./lib/external/glfw-2.7.6/lib/time.d \
./lib/external/glfw-2.7.6/lib/window.d 


# Each subdirectory must supply rules for building sources it contributes
lib/external/glfw-2.7.6/lib/%.o: ../lib/external/glfw-2.7.6/lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/common -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/AntTweakBar-1.15/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glew-1.9.0/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glfw-2.7.6/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glfw-2.7.6/lib -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glfw-2.7.6/lib/x11 -I/usr/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/Includes -I/usr/include/c++/4.6 -I/usr/include/c++/4.6/backward -I/usr/include/c++/4.6/i686-linux-gnu -I/usr/include/i386-linux-gnu/gnu -I/usr/lib/gcc/i686-linux-gnu/4.6/include -I/usr/lib/gcc/i686-linux-gnu/4.6/include-fixed -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


