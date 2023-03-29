#include "FingPrint_interface.h"
#include "USART_interface.h"
#include "DIO_interface.h"
#define F_CPU 16000000
#include <util/delay.h>

u8 buffer_state = FP_WAIT_DATA;   //state of the data buffer

u8 buffer[30];			
u8 buffer_index= 0;			
u8  package_content[20];	
u16 package_content_len;		

void FingPrint_Init()
{	
    // UART_Init(57600);	
	Send_Command(VfyPwd, SIZE_OF_PASS);
    u16 LED_sum = 0x3D + LED_CTRL + LED_COLOR + LED_SPD + LED_TIMES;
    f_auraLED[14]= (LED_sum>>8);
    f_auraLED[15]= LED_sum;  
	Send_Command(f_auraLED, SIZE_OF_AURA_LED);
}	
	
void UART_ISR(u16 DATA)
{
	buffer[buffer_index] = DATA;
	buffer_index++;	
	if(buffer_index>0)
	{
		buffer_state = FP_DATA_RECVEIED; 
	} 
		//flag = 1;
	}
	
	void Clear_buffer(void){
		for(u8 i=0; i<30; i++)
		buffer[i] = 0;
		buffer_index = 0;
	}

 //send any package
u8 Send_Command(u8 *pack, u16 len)
{  
	u8 res = ERROR;
	Clear_buffer();
	_delay_ms(100);
	
	for(u8 i=0; i<len; i++)
	{
		UART_SendSynschronous(pack[i]);
	}
	
	_delay_ms(1000);
	if(buffer_state = FP_DATA_RECVEIED){
		if((buffer[0] == 0xEF) && (buffer[1] == 0x01)){
			// check for ack. byte
			if(buffer[6] == 0x07)
			{
				//check for successful operation
				if(buffer[9] == 0)
				 {
					//read the data frame length
					package_content_len = buffer[7];
					package_content_len<<=8;
					package_content_len |= buffer[8];
					
					//clear packet content buffer
					for(u8 i=0; i<package_content_len; i++)
					{
					package_content[i]=0;
					}
					
					//copy the data frame to the packet content buffer
					for(u8 i=0; i<package_content_len-2; i++)
					package_content[i] = buffer[10+i];

					res=PASS;
				}
				else
				res=ERROR;
			}
		}
		buffer_index = 0;
		buffer_state = FP_WAIT_DATA;
		//flag = 1;
		return res;
	}
	return res;
}




// Enrollment Function
u8 Enroll_FingPrint(u16 finger_ID)   
{
	for(int i=0;i<3;i++)
	  {
		if(Send_Command(GenImg, SIZE_OF_DETECT) == PASS)
		{
			
			if(Send_Command(Img2Char1, SIZE_OF_IMG_TO_CH) == PASS)
			{
				
				if(Send_Command(GenImg, SIZE_OF_DETECT) == PASS)
				{
					
					if(Send_Command(Img2Char2, SIZE_OF_IMG_TO_CH) == PASS)
					{
						
						if(Send_Command(RegModel, SIZE_OF_CREATE_MODEL) == PASS)
						 {
							//update the ID bytes
							f_storeModel[11]= (finger_ID>>8) & 0xff;
							f_storeModel[12]= finger_ID & 0xff;
							
							//update check sum bytes
							u16 store_sum = 14 + finger_ID;
							f_storeModel[13]= (store_sum>>8) & 0xff;
							f_storeModel[14]= store_sum & 0xff;
							
							if(Send_Command(f_storeModel, SIZE_OF_STORE_MODEL) == PASS)
							{
								return PASS;
							}
						 }
					}
				}
			}
		}
		if(i==2)
		return NO_FINGER;
	}
	return ERROR;
}


// Matching Function 
u8 Read_FingPrint(void) 
{
	if(Send_Command(GenImg, SIZE_OF_DETECT) == PASS){
		
		if(Send_Command(Img2Char1, SIZE_OF_IMG_TO_CH) == PASS){
			
			if (Send_Command(f_search, SIZE_OF_SEARCH) == PASS){
				//extract the scanned ID from the data buffer
				u8 scannedID = package_content[0];
				scannedID<<8;
				scannedID += package_content[1];
				
				return scannedID;
			}		
			else{
				return WRONG_FINGER;
			}
		}
	}
	return NO_FINGER;
}




