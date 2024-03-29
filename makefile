# Compiler
CC = avr-gcc

# Applications
VPATH = App/DIO App/Keypad App/scheduler App/ADC App/Timer App/USART App/SPI App/I2C App/ChatOverUSART_Tx App/Ext_EEPROM App/
VPATH += App/LCD App/Motor_Control App/Ultrasonic App/Tone_Generator App/PushButton	 App/ICU 
# MCAL (.c) files
VPATH += MCAL/DIO MCAL/ADC MCAL/Timer MCAL/USART MCAL/SPI MCAL/I2C 
# HAL (.c) files
VPATH +=  HAL/Keypad HAL/Ext_EEPROM HAL/LCD 

# Compiler include directories
INCLUDES 	:= -I MCAL/DIO -I LIB -I HAL/Keypad -I HAL/LCD -I HAL/Ext_EEPROM  -I MCAL/EX_INT -I MCAL/ADC 
INCLUDES 	+=-I MCAL/Timer -I MCAL/USART -I MCAL/SPI -I MCAL/I2C	-I App/scheduler
CC_FLAGS 	:= -mmcu=atmega32 -Os -std=c99 -Wall -g -F_CPU=16000000UL


# These are each project dependencies and modules required
SCHEDULER_OBJs		:= DIO_program.o LCD_program.o Keypad_program.o Timer_program.o
SCHEDULER_OBJs		+= I2C_program.o SPI_program.o


SMART_HOME_OBJs		:= I2C_program.o SPI_program.o DIO_program.o LCD_program.o Keypad_program.o USART_program.o
I2C_OBJs			:= Ext_EEPROM_program.o I2C_program.o DIO_program.o LCD_program.o
SPI_OBJs			:= SPI_app.o SPI_program.o DIO_program.o LCD_program.o
ChatOverUSART_Tx_OBJs := ChatOverUSART_Tx.o USART_program.o DIO_program.o LCD_program.o
USART_OBJs			:= USART_app.o USART_program.o DIO_program.o LCD_program.o
ICU_OBJs			:= ICU_app.o Timer_program.o DIO_program.o LCD_program.o
Ultrasonic_OBJs		:= Ultrasonic.o Timer_program.o DIO_program.o LCD_program.o
MotorControl_OBJs 	:= MotorControl_app.o ADC_program.o Timer_program.o DIO_program.o 
ADC_OBJs			:= ADC_test.o ADC_program.o Timer_program.o  Keypad_program.o DIO_program.o LCD_program.o
Timer_OBJs			:= Timer_app.o Timer_program.o  Keypad_program.o DIO_program.o LCD_program.o
Calculator_OBJs		:= Calculator.o DIO_program.o Keypad_program.o LCD_program.o
DIO_OBJs 			:= DIO_test.o DIO_program.o
Keypad_OBJs 		:= Keypad_test.o Keypad_program.o DIO_program.o LCD_program.o
LCD_OBJs			:= LCD_test.o DIO_program.o LCD_program.o Keypad_program.o


# Linking and generating Project .elf , .hex files


scheduler: scheduler.o $(SCHEDULER_OBJs)
	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@.elf
	avr-objcopy -j .text -j .data -O ihex $@.elf  $@.hex
	@size $@.hex
	@rm *.o


Smart_Home_Master: $(SMART_HOME_OBJs)
	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@.elf
	avr-objcopy -j .text -j .data -O ihex $@.elf  $@.hex
	@size $@.hex
	@rm *.o

Smart_Home_Slave: $(SMART_HOME_OBJs)
	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@.elf
	avr-objcopy -j .text -j .data -O ihex $@.elf  $@.hex
	@size $@.hex
	@rm *.o

Ext_EEPROM_app: Ext_EEPROM_app.o $(I2C_OBJs)
	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@.elf
	avr-objcopy -j .text -j .data -O ihex $@.elf  $@.hex
	@size $@.hex
	@rm *.o

I2C_app: I2C_app.o $(I2C_OBJs)
	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@.elf
	avr-objcopy -j .text -j .data -O ihex $@.elf  $@.hex
	@size $@.hex
	@rm *.o

SPI_app: $(SPI_OBJs)
	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@.elf
	avr-objcopy -j .text -j .data -O ihex $@.elf  $@.hex
	@size $@.hex
	@rm *.o


ChatOverUSART_Tx: $(ChatOverUSART_Tx_OBJs)
	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@.elf
	avr-objcopy -j .text -j .data -O ihex $@.elf  $@.hex
	@size $@.hex
	@rm *.o


USART_app: $(USART_OBJs)
	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@.elf
	avr-objcopy -j .text -j .data -O ihex $@.elf  $@.hex
	@size $@.hex
	@rm *.o

ICU_app: $(ICU_OBJs)
	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@.elf
	avr-objcopy -j .text -j .data -O ihex $@.elf  $@.hex
	@size $@.hex
	@rm *.o


Ultrasonic: $(Ultrasonic_OBJs)
	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@.elf
	avr-objcopy -j .text -j .data -O ihex $@.elf  $@.hex
	@size $@.hex
	@rm *.o

MotorControl_app: $(MotorControl_OBJs)
	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@.elf
	avr-objcopy -j .text -j .data -O ihex $@.elf  $@.hex
	@size $@.hex
	@rm *.o


Timer_app: $(Timer_OBJs)
	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@.elf
	avr-objcopy -j .text -j .data -O ihex $@.elf  $@.hex
	@size $@.hex
	@rm *.o

ADC_test: $(ADC_OBJs)
	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@.elf
	avr-objcopy -j .text -j .data -O ihex $@.elf  $@.hex
	@size $@.hex
	@rm *.o

Calculator: $(Calculator_OBJs)
	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@.elf
	avr-objcopy -j .text -j .data -O ihex $@.elf  $@.hex
	@size $@.hex
	@rm *.o

LCD_test: $(LCD_OBJs)
	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@.elf
	avr-objcopy -j .text -j .data -O ihex $@.elf  $@.hex
	@size $@.hex
	@rm *.o


Keypad_test: $(Keypad_OBJs)
	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@.elf
	avr-objcopy -j .text -j .data -O ihex $@.elf  $@.hex
	@size $@.hex
	@rm *.o

	
DIO_test: $(DIO_OBJs)
	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@.elf
	avr-objcopy -j .text -j .data -O ihex $@.elf  $@.hex
	@size $@.hex
	@rm *.o



# Projects main file compilation

scheduler.o:scheduler.c	scheduler.h
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<

Smart_Home_Master.o:Smart_Home_Master.c
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<

Smart_Home_Slave.o:Smart_Home_Slave.c
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<

Ext_EEPROM_app.o:Ext_EEPROM_app.c
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<

I2C_app.o:I2C_app.c
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<

SPI_app.o:SPI_app.c
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<

ChatOverUSART_Tx.o:ChatOverUSART_Tx.c
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<

USART_app.o:USART_app.c
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<	

ICU_app.o:ICU_app.c
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<	

Ultrasonic.o:Ultrasonic.c
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<	

MotorControl_app.o: MotorControl_app.c
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<	

Timer_app.o:Timer_app.c
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<	

ADC_test.o:ADC_test.c
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<	

DIO_test.o: DIO_test.c
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<	

LCD_test.o: LCD_test.c
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<	

Calculator.o: Calculator.c
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<	

Keypad_test.o: Keypad_test.c
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<	



# HAL Drivers
LCD_program.o: LCD_program.c LCD_interface.h LCD_private.h LCD_config.h
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<

Keypad_program.o: Keypad_program.c Keypad_private.h Keypad_interface.h 
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<		

Ext_EEPROM_program.o:Ext_EEPROM_program.c Ext_EEPROM_config.h Ext_EEPROM_interface.h
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<



# MCAL Drivers
I2C_program.o:I2C_program.c I2C_private.h I2C_interface.h 
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<

SPI_program.o:SPI_program.c SPI_private.h SPI_interface.h 
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<

USART_program.o:USART_program.c USART_private.h USART_interface.h 
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<

Timer_program.o:Timer_program.c Timer_private.h Timer_interface.h 
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<

DIO_program.o: DIO_program.c DIO_private.h DIO_interface.h 
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<

ADC_program.o: ADC_program.c ADC_private.h ADC_interface.h 
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<



# Clean build outputs
clean:
	@rm *.hex *.elf 
