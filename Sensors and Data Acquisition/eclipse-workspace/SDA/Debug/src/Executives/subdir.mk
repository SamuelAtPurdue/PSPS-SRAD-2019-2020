################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Executives/Bahaa.c \
../src/Executives/Jeff.c \
../src/Executives/Matt.c 

OBJS += \
./src/Executives/Bahaa.o \
./src/Executives/Jeff.o \
./src/Executives/Matt.o 

C_DEPS += \
./src/Executives/Bahaa.d \
./src/Executives/Jeff.d \
./src/Executives/Matt.d 


# Each subdirectory must supply rules for building sources it contributes
src/Executives/%.o: ../src/Executives/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"C:\Users\Jeff\Documents\GitHub\PSPS-SRAD-2019-2020\Sensors and Data Acquisition\eclipse-workspace\SDA\src" -I"C:\Users\Jeff\Documents\GitHub\PSPS-SRAD-2019-2020\Sensors and Data Acquisition\eclipse-workspace\SDA\src\DataProcessing" -I"C:\Users\Jeff\Documents\GitHub\PSPS-SRAD-2019-2020\Sensors and Data Acquisition\eclipse-workspace\SDA\src\DataProcessing\Filter" -I"C:\Users\Jeff\Documents\GitHub\PSPS-SRAD-2019-2020\Sensors and Data Acquisition\eclipse-workspace\SDA\src\DataProcessing\GeoMag" -I"C:\Users\Jeff\Documents\GitHub\PSPS-SRAD-2019-2020\Sensors and Data Acquisition\eclipse-workspace\SDA\src\Setup" -I"C:\Users\Jeff\Documents\GitHub\PSPS-SRAD-2019-2020\Sensors and Data Acquisition\eclipse-workspace\SDA\src\Executives" -I"C:\Users\Jeff\Documents\GitHub\PSPS-SRAD-2019-2020\Sensors and Data Acquisition\eclipse-workspace\SDA\src\Sensors" -I"C:\Users\Jeff\Documents\GitHub\PSPS-SRAD-2019-2020\Sensors and Data Acquisition\eclipse-workspace\SDA\src\MatrixVector" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


