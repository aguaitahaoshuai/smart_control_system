################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/ASR01/asr01.c 

OBJS += \
./APP/ASR01/asr01.o 

C_DEPS += \
./APP/ASR01/asr01.d 


# Each subdirectory must supply rules for building sources it contributes
APP/ASR01/%.o: ../APP/ASR01/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\Ƕ��ʽCH������Ŀ ����\����openCH��Ŀ\���ܾӼ���Ŀ����\CH32V307VCT6\APP\ASR01" -I"D:\Ƕ��ʽCH������Ŀ ����\����opCH���ܾӼҿ���-���ض�\����CH32Դ����\CH32V307VCT6\Debug" -I"D:\Ƕ��ʽCH������Ŀ ����\����openCH��Ŀ\���ܾӼ���Ŀ����\CH32V307VCT6\APP\ASR01" -I"D:\Ƕ��ʽCH������Ŀ ����\����openCH��Ŀ\���ܾӼ���Ŀ����\CH32V307VCT6\APP\showXY" -I"D:\Ƕ��ʽCH������Ŀ ����\����openCH��Ŀ\���ܾӼ���Ŀ����\CH32V307VCT6\APP\LCD" -I"D:\Ƕ��ʽCH������Ŀ ����\����openCH��Ŀ\���ܾӼ���Ŀ����\CH32V307VCT6\APP\KEY" -I"D:\Ƕ��ʽCH������Ŀ ����\����openCH��Ŀ\���ܾӼ���Ŀ����\CH32V307VCT6\APP\LED" -I"D:\Ƕ��ʽCH������Ŀ ����\����opCH���ܾӼҿ���-���ض�\����CH32Դ����\CH32V307VCT6\Core" -I"D:\Ƕ��ʽCH������Ŀ ����\����opCH���ܾӼҿ���-���ض�\����CH32Դ����\CH32V307VCT6\User" -I"D:\Ƕ��ʽCH������Ŀ ����\����opCH���ܾӼҿ���-���ض�\����CH32Դ����\CH32V307VCT6\Peripheral\inc" -I"D:\Ƕ��ʽCH������Ŀ ����\����openCH��Ŀ\���ܾӼ���Ŀ����\CH32V307VCT6\APP\interrupt" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

