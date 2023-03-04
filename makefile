CC = avr-gcc
VPATH = App HAL/Keypad HAL/LCD MCAL/DIO MCAL/ADC MCAL/Timer
INCLUDES := -I MCAL/DIO -I LIB -I HAL/Keypad -I HAL/LCD -I MCAL/EX_INT -I MCAL/ADC -I MCAL/Timer
CC_FLAGS := -mmcu=atmega32 -Os -std=c99 -Wall -g -F_CPU=8000000


# These are each project dependencies and modules required
MotorControl_OBJs 	:= MotorControl_app.o ADC_program.o Timer_program.o DIO_program.o 
ADC_OBJs			:= ADC_test.o ADC_program.o Timer_program.o  Keypad_program.o DIO_program.o LCD_program.o
Timer_OBJs			:= Timer_app.o Timer_program.o Keypad_test.o Keypad_program.o DIO_program.o LCD_program.o
DIO_OBJs 			:= DIO_test.o DIO_program.o
Keypad_OBJs 		:= Keypad_test.o Keypad_program.o DIO_program.o LCD_program.o
LCD_OBJs			:= LCD_test.o DIO_program.o LCD_program.o Keypad_program.o

# Choose one of the Projects: LCD_test.elf and DIO_test.elf ADC_test.elf Timer_app

PROJECT_NAME := LCD_test


# $(PROJECT_NAME).elf: $(PROJECT_NAME).o DIO_program.o Keypad_program.o LCD_program.o Timer_program.o
# 	$(CC) $(INCLUDES) $(CC_FLAGS) $^ -o $@
# 	avr-objcopy -j .text -j .data -O ihex $(PROJECT_NAME).elf  $(PROJECT_NAME).hex
# 	@size $(PROJECT_NAME).hex




# Generating Project .elf , .hex files

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

Keypad_test.o: Keypad_test.c
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<	



# HAL Drivers
LCD_program.o: LCD_program.c LCD_interface.h LCD_private.h LCD_config.h
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<

Keypad_program.o: Keypad_program.c Keypad_private.h Keypad_interface.h 
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<		



# MCAL Drivers
Timer_program.o:Timer_program.c Timer_private.h Timer_interface.h 
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<

DIO_program.o: DIO_program.c DIO_private.h DIO_interface.h 
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<

ADC_program.o: ADC_program.c ADC_private.h ADC_interface.h 
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $<



# Clean build outputs
clean:
	@rm *.hex *.elf 


