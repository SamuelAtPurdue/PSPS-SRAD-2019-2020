################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Sensors/BMP.c \
../src/Sensors/GPS.c \
../src/Sensors/IMU.c \
../src/Sensors/LIN.c \
../src/Sensors/Sensors.c 

OBJS += \
./src/Sensors/BMP.o \
./src/Sensors/GPS.o \
./src/Sensors/IMU.o \
./src/Sensors/LIN.o \
./src/Sensors/Sensors.o 

C_DEPS += \
./src/Sensors/BMP.d \
./src/Sensors/GPS.d \
./src/Sensors/IMU.d \
./src/Sensors/LIN.d \
./src/Sensors/Sensors.d 


# Each subdirectory must supply rules for building sources it contributes
src/Sensors/%.o: ../src/Sensors/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"C:\Users\Jeff\Documents\GitHub\PSPS-SRAD-2019-2020\Sensors and Data Acquisition\eclipse-workspace\SDA\src" -I"C:\Users\Jeff\Documents\GitHub\PSPS-SRAD-2019-2020\Sensors and Data Acquisition\eclipse-workspace\SDA\src\DataProcessing" -I"C:\Users\Jeff\Documents\GitHub\PSPS-SRAD-2019-2020\Sensors and Data Acquisition\eclipse-workspace\SDA\src\DataProcessing\Filter" -I"C:\Users\Jeff\Documents\GitHub\PSPS-SRAD-2019-2020\Sensors and Data Acquisition\eclipse-workspace\SDA\src\DataProcessing\GeoMag" -I"C:\Users\Jeff\Documents\GitHub\PSPS-SRAD-2019-2020\Sensors and Data Acquisition\eclipse-workspace\SDA\src\Setup" -I"C:\Users\Jeff\Documents\GitHub\PSPS-SRAD-2019-2020\Sensors and Data Acquisition\eclipse-workspace\SDA\src\Executives" -I"C:\Users\Jeff\Documents\GitHub\PSPS-SRAD-2019-2020\Sensors and Data Acquisition\eclipse-workspace\SDA\src\Sensors" -I"C:\Users\Jeff\Documents\GitHub\PSPS-SRAD-2019-2020\Sensors and Data Acquisition\eclipse-workspace\SDA\src\MatrixVector" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


