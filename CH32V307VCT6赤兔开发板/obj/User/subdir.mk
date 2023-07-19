################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/ch32v30x_it.c \
../User/main.c \
../User/system_ch32v30x.c 

OBJS += \
./User/ch32v30x_it.o \
./User/main.o \
./User/system_ch32v30x.o 

C_DEPS += \
./User/ch32v30x_it.d \
./User/main.d \
./User/system_ch32v30x.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\嵌入式CH开发项目 国赛\赤兔openCH项目\智能居家项目整合\CH32V307VCT6\APP\ASR01" -I"D:\嵌入式CH开发项目 国赛\赤兔opCH智能居家开发-开拓队\赤兔CH32源代码\CH32V307VCT6\Debug" -I"D:\嵌入式CH开发项目 国赛\赤兔openCH项目\智能居家项目整合\CH32V307VCT6\APP\showXY" -I"D:\嵌入式CH开发项目 国赛\赤兔opCH智能居家开发-开拓队\赤兔CH32源代码\CH32V307VCT6\APP\ASR" -I"D:\嵌入式CH开发项目 国赛\赤兔openCH项目\智能居家项目整合\CH32V307VCT6\APP\LCD" -I"D:\嵌入式CH开发项目 国赛\赤兔openCH项目\智能居家项目整合\CH32V307VCT6\APP\KEY" -I"D:\嵌入式CH开发项目 国赛\赤兔openCH项目\智能居家项目整合\CH32V307VCT6\APP\LED" -I"D:\嵌入式CH开发项目 国赛\赤兔opCH智能居家开发-开拓队\赤兔CH32源代码\CH32V307VCT6\Core" -I"D:\嵌入式CH开发项目 国赛\赤兔opCH智能居家开发-开拓队\赤兔CH32源代码\CH32V307VCT6\User" -I"D:\嵌入式CH开发项目 国赛\赤兔opCH智能居家开发-开拓队\赤兔CH32源代码\CH32V307VCT6\Peripheral\inc" -I"D:\嵌入式CH开发项目 国赛\赤兔openCH项目\智能居家项目整合\CH32V307VCT6\APP\interrupt" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

