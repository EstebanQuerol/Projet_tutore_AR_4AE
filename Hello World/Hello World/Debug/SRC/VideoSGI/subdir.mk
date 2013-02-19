################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/media/7954AD1876DA1529/Documentos/Clase/Segundo\ semestre/Projet\ tutoré/Git/Projet_tutore_AR_4AE/ARToolKit/lib/SRC/VideoSGI/video.c \
/media/7954AD1876DA1529/Documentos/Clase/Segundo\ semestre/Projet\ tutoré/Git/Projet_tutore_AR_4AE/ARToolKit/lib/SRC/VideoSGI/video2.c 

OBJS += \
./SRC/VideoSGI/video.o \
./SRC/VideoSGI/video2.o 

C_DEPS += \
./SRC/VideoSGI/video.d \
./SRC/VideoSGI/video2.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/VideoSGI/video.o: /media/7954AD1876DA1529/Documentos/Clase/Segundo\ semestre/Projet\ tutoré/Git/Projet_tutore_AR_4AE/ARToolKit/lib/SRC/VideoSGI/video.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/include -I/usr/include/GL -I../../../ARToolKit/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SRC/VideoSGI/video2.o: /media/7954AD1876DA1529/Documentos/Clase/Segundo\ semestre/Projet\ tutoré/Git/Projet_tutore_AR_4AE/ARToolKit/lib/SRC/VideoSGI/video2.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/include -I/usr/include/GL -I../../../ARToolKit/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


