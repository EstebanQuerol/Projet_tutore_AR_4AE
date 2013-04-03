################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/src_openGL33/controls.cpp \
../src/src_openGL33/objloader.cpp 

OBJS += \
./src/src_openGL33/controls.o \
./src/src_openGL33/objloader.o 

CPP_DEPS += \
./src/src_openGL33/controls.d \
./src/src_openGL33/objloader.d 


# Each subdirectory must supply rules for building sources it contributes
src/src_openGL33/%.o: ../src/src_openGL33/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"../../Project C++/lib/AntTweakBar-1.15/include" -I"../../Project C++/lib/glew-1.9.0/include" -I"../../Project C++/lib/glfw-2.7.6/include" -I"../../Project C++/lib/glfw-2.7.6/lib" -I"../../Project C++/lib/glfw-2.7.6/lib/x11" -I"../../Project C++/lib/glm-0.9.4.0" -I/usr/include -I/usr/include/c++/4.6 -I/usr/include/c++/4.6/backward -I/usr/include/c++/4.6/i686-linux-gnu -I/usr/include/i386-linux-gnu -I/usr/lib/gcc/i686-linux-gnu/4.6/include -I/usr/lib/gcc/i686-linux-gnu/4.6/include-fixed -I/usr/include/GL -I/usr/include/glib-2.0 -I"../../Project C++/lib/ARToolKit/include" -I/usr/include/gstreamer-0.10 -I/usr/include/libxml2 -I/usr/lib/i386-linux-gnu/glib-2.0/include -I/usr/local/include -I"../../Project C++/Include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


