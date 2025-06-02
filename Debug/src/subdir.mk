################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TADCasilla.cpp \
../src/TADJuego.cpp \
../src/TADTablero.cpp \
../src/entorno.cpp \
../src/main.cpp \
../src/pruebasTADCasilla.cpp \
../src/pruebasTADTablero.cpp 

CPP_DEPS += \
./src/TADCasilla.d \
./src/TADJuego.d \
./src/TADTablero.d \
./src/entorno.d \
./src/main.d \
./src/pruebasTADCasilla.d \
./src/pruebasTADTablero.d 

OBJS += \
./src/TADCasilla.o \
./src/TADJuego.o \
./src/TADTablero.o \
./src/entorno.o \
./src/main.o \
./src/pruebasTADCasilla.o \
./src/pruebasTADTablero.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/TADCasilla.d ./src/TADCasilla.o ./src/TADJuego.d ./src/TADJuego.o ./src/TADTablero.d ./src/TADTablero.o ./src/entorno.d ./src/entorno.o ./src/main.d ./src/main.o ./src/pruebasTADCasilla.d ./src/pruebasTADCasilla.o ./src/pruebasTADTablero.d ./src/pruebasTADTablero.o

.PHONY: clean-src

