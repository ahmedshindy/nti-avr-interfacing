CC = avr-gcc
VPATH = App HAL/Keypad HAL/LCD MCAL/DIO MCAL/ADC MCAL/Timer  MCAL/USART MCAL/SPI
INCLUDES := -I MCAL/DIO -I LIB -I HAL/Keypad -I HAL/LCD -I MCAL/EX_INT -I MCAL/ADC -I MCAL/Timer -I MCAL/USART -I MCAL/SPI
CC_FLAGS := -mmcu=atmega32 -Os -std=c99 -Wall -g -F_CPU=8000000


# These are each project dependencies and modules required

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


# Generating Project .elf , .hex files

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
	
# Projects compilation
SPI_app.o:ChatOverUSART_Tx.c
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



# MCAL Drivers
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