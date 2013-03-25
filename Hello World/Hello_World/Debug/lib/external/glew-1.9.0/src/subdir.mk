################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/external/glew-1.9.0/src/glew.c \
../lib/external/glew-1.9.0/src/glewinfo.c \
../lib/external/glew-1.9.0/src/visualinfo.c 

OBJS += \
./lib/external/glew-1.9.0/src/glew.o \
./lib/external/glew-1.9.0/src/glewinfo.o \
./lib/external/glew-1.9.0/src/visualinfo.o 

C_DEPS += \
./lib/external/glew-1.9.0/src/glew.d \
./lib/external/glew-1.9.0/src/glewinfo.d \
./lib/external/glew-1.9.0/src/visualinfo.d 


# Each subdirectory must supply rules for building sources it contributes
lib/external/glew-1.9.0/src/%.o: ../lib/external/glew-1.9.0/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/common -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/AntTweakBar-1.15/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glew-1.9.0/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glfw-2.7.6/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glfw-2.7.6/lib -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glfw-2.7.6/lib/x11 -I/usr/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/Includes -I/usr/include/c++/4.6 -I/usr/include/c++/4.6/backward -I/usr/include/c++/4.6/i686-linux-gnu -I/usr/include/i386-linux-gnu/gnu -I/usr/lib/gcc/i686-linux-gnu/4.6/include -I/usr/lib/gcc/i686-linux-gnu/4.6/include-fixed -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


