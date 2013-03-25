################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/playground.cpp 

OBJS += \
./src/playground.o 

CPP_DEPS += \
./src/playground.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../Project_base_OpenGL/lib/common -I../../Project_base_OpenGL/lib/external/AntTweakBar-1.15/include -I../../Project_base_OpenGL/lib/external/glfw-2.7.6/include -I../../Project_base_OpenGL/lib/external/glfw-2.7.6/lib -I../../Project_base_OpenGL/lib/external/glfw-2.7.6/lib/x11 -I../../Project_base_OpenGL/lib/external/glew-1.9.0/include -I/usr/include -I/usr/include/c++/4.6 -I/usr/include/c++/4.6/backward -I/usr/include/c++/4.6/i686-linux-gnu -I/usr/include/i386-linux-gnu -I/usr/lib/gcc/i686-linux-gnu/4.6/include -I/usr/lib/gcc/i686-linux-gnu/4.6/include-fixed -I../../Project_base_OpenGL/lib/external/glm-0.9.4.0 -I/usr/include/GL -I/usr/include/glib-2.0 -I../../Project_base_OpenGL/lib/external/ARToolKit/include -I/usr/include/gstreamer-0.10 -I/usr/include/libxml2 -I/usr/lib/i386-linux-gnu/glib-2.0/include -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


