################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/media/7954AD1876DA1529/Documentos/Clase/Segundo\ semestre/Projet\ tutoré/Git/Projet_tutore_AR_4AE/ARToolKit/lib/SRC/VideoMacOSX/video.c 

OBJS += \
./SRC/VideoMacOSX/video.o 

C_DEPS += \
./SRC/VideoMacOSX/video.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/VideoMacOSX/video.o: /media/7954AD1876DA1529/Documentos/Clase/Segundo\ semestre/Projet\ tutoré/Git/Projet_tutore_AR_4AE/ARToolKit/lib/SRC/VideoMacOSX/video.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/include -I/usr/include/GL -I../../../ARToolKit/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


