################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/external/AntTweakBar-1.15/examples/TwAdvanced1.cpp \
../lib/external/AntTweakBar-1.15/examples/TwSimpleDX10.cpp \
../lib/external/AntTweakBar-1.15/examples/TwSimpleDX11.cpp \
../lib/external/AntTweakBar-1.15/examples/TwSimpleDX9\ -\ Copy.cpp \
../lib/external/AntTweakBar-1.15/examples/TwSimpleDX9.cpp \
../lib/external/AntTweakBar-1.15/examples/TwSimpleSFML.cpp \
../lib/external/AntTweakBar-1.15/examples/TwString.cpp 

C_SRCS += \
../lib/external/AntTweakBar-1.15/examples/TwDualGLUT.c \
../lib/external/AntTweakBar-1.15/examples/TwGLCoreSDL.c \
../lib/external/AntTweakBar-1.15/examples/TwSimpleGLFW.c \
../lib/external/AntTweakBar-1.15/examples/TwSimpleGLUT.c \
../lib/external/AntTweakBar-1.15/examples/TwSimpleSDL.c 

OBJS += \
./lib/external/AntTweakBar-1.15/examples/TwAdvanced1.o \
./lib/external/AntTweakBar-1.15/examples/TwDualGLUT.o \
./lib/external/AntTweakBar-1.15/examples/TwGLCoreSDL.o \
./lib/external/AntTweakBar-1.15/examples/TwSimpleDX10.o \
./lib/external/AntTweakBar-1.15/examples/TwSimpleDX11.o \
./lib/external/AntTweakBar-1.15/examples/TwSimpleDX9\ -\ Copy.o \
./lib/external/AntTweakBar-1.15/examples/TwSimpleDX9.o \
./lib/external/AntTweakBar-1.15/examples/TwSimpleGLFW.o \
./lib/external/AntTweakBar-1.15/examples/TwSimpleGLUT.o \
./lib/external/AntTweakBar-1.15/examples/TwSimpleSDL.o \
./lib/external/AntTweakBar-1.15/examples/TwSimpleSFML.o \
./lib/external/AntTweakBar-1.15/examples/TwString.o 

C_DEPS += \
./lib/external/AntTweakBar-1.15/examples/TwDualGLUT.d \
./lib/external/AntTweakBar-1.15/examples/TwGLCoreSDL.d \
./lib/external/AntTweakBar-1.15/examples/TwSimpleGLFW.d \
./lib/external/AntTweakBar-1.15/examples/TwSimpleGLUT.d \
./lib/external/AntTweakBar-1.15/examples/TwSimpleSDL.d 

CPP_DEPS += \
./lib/external/AntTweakBar-1.15/examples/TwAdvanced1.d \
./lib/external/AntTweakBar-1.15/examples/TwSimpleDX10.d \
./lib/external/AntTweakBar-1.15/examples/TwSimpleDX11.d \
./lib/external/AntTweakBar-1.15/examples/TwSimpleDX9\ -\ Copy.d \
./lib/external/AntTweakBar-1.15/examples/TwSimpleDX9.d \
./lib/external/AntTweakBar-1.15/examples/TwSimpleSFML.d \
./lib/external/AntTweakBar-1.15/examples/TwString.d 


# Each subdirectory must supply rules for building sources it contributes
lib/external/AntTweakBar-1.15/examples/%.o: ../lib/external/AntTweakBar-1.15/examples/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/common -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/AntTweakBar-1.15/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glew-1.9.0/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glfw-2.7.6/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glfw-2.7.6/lib -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glfw-2.7.6/lib/x11 -I/usr/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/Includes -I/usr/include/c++/4.6 -I/usr/include/c++/4.6/backward -I/usr/include/c++/4.6/i686-linux-gnu -I/usr/include/i386-linux-gnu/gnu -I/usr/lib/gcc/i686-linux-gnu/4.6/include -I/usr/lib/gcc/i686-linux-gnu/4.6/include-fixed -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/external/AntTweakBar-1.15/examples/%.o: ../lib/external/AntTweakBar-1.15/examples/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/common -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/AntTweakBar-1.15/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glew-1.9.0/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glfw-2.7.6/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glfw-2.7.6/lib -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glfw-2.7.6/lib/x11 -I/usr/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/Includes -I/usr/include/c++/4.6 -I/usr/include/c++/4.6/backward -I/usr/include/c++/4.6/i686-linux-gnu -I/usr/include/i386-linux-gnu/gnu -I/usr/lib/gcc/i686-linux-gnu/4.6/include -I/usr/lib/gcc/i686-linux-gnu/4.6/include-fixed -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/external/AntTweakBar-1.15/examples/TwSimpleDX9\ -\ Copy.o: ../lib/external/AntTweakBar-1.15/examples/TwSimpleDX9\ -\ Copy.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/common -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/AntTweakBar-1.15/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glew-1.9.0/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glfw-2.7.6/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glfw-2.7.6/lib -I/home/narik/Eclipseprojects/Project_base_OpenGL/lib/external/glfw-2.7.6/lib/x11 -I/usr/include -I/home/narik/Eclipseprojects/Project_base_OpenGL/Includes -I/usr/include/c++/4.6 -I/usr/include/c++/4.6/backward -I/usr/include/c++/4.6/i686-linux-gnu -I/usr/include/i386-linux-gnu/gnu -I/usr/lib/gcc/i686-linux-gnu/4.6/include -I/usr/lib/gcc/i686-linux-gnu/4.6/include-fixed -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"lib/external/AntTweakBar-1.15/examples/TwSimpleDX9 - Copy.d" -MT"lib/external/AntTweakBar-1.15/examples/TwSimpleDX9\ -\ Copy.d" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


