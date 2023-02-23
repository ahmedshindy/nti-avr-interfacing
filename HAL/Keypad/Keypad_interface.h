/*
 * Keypad_interface.h
 *
 * Created: 2/18/2023 7:25:18 AM
 *  Author: Ahmed Shindy
 */ 
#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H


#define	NOTPRESSED	0XFF
void Keypad_vInit();
u8	 Keypad_u8Scan();

#endif
