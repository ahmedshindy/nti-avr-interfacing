#include <stdio.h>
#include "Timer_interface.h"
#include "LCD_interface.h"
#include "DIO_interface.h"
#include "scheduler.h"
#include "util/delay.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];
int main()
{

    DIO_SetPinDir(DIO_PORTD,Pin0,OUTPUT);
    
    LCD_vInit();
    LCD_vWriteString("Hi scheduler");
    _delay_ms(1000);

    // Set up the scheduler
    SCH_Init();
    // Add the tasks (1ms tick interval)
    // Function_A will run every 10 ms
    SCH_Add_Task(Function_A, 0, 10);
    // Function_C will run every 15 ms
    SCH_Add_Task(Function_C, 3, 15);
    SCH_Start();
    while(1)
    {
        SCH_Dispatch_Tasks();
    }


    while (1);
}



SCH_Init(void)
{
    Timer1_InitNormal();
}


void SCH_Update(void) interrupt INTERRUPT_Timer_2_Overflow
{
        
    u8 Index;
    // TF2 = 0; // Have to manually clear this.
    // NOTE: calculations are in *TICKS* (not milliseconds)
    for (Index = 0; Index < SCH_MAX_TASKS; Index++)
    if the pointer is not NULL!
    {
        // Check if there is a task at this location
        if (SCH_tasks_G[Index].pTask)
        {
            if (SCH_tasks_G[Index].Delay == 0)
            {
                // The task is due to run
                SCH_tasks_G[Index].RunMe += 1; // Inc. the 'RunMe' flag
                if (SCH_tasks_G[Index].Period)
                {
                    // Schedule periodic tasks to run again
                    SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
                }
            }
            else
            {
                // Not yet ready to run: just decrement the delay
                SCH_tasks_G[Index].Delay -= 1;
            }
        }
    }
}


ISR(TIMER1_OVF_vect)
{
    // static u16 counter = 0;
    // counter ++;
    // if(counter>= 500)
    // {
    //     counter =0;
    //     DIO_TogglePinValue(DIO_PORTD,Pin0);
    // }
    TCNT1H = (1534<<8);
    TCNT1L = (u8)(1534);
    DIO_TogglePinValue(DIO_PORTD,Pin0);
}