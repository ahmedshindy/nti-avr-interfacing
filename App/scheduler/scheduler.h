#ifndef SCHEDULER_H
#define SCHEDULER_H
#define F_CPU   16000000
#include "STD_TYPES.h"

typedef struct
{
    // Pointer to the task (must be a 'void (void)' function)
    void (* pTask)(void);
    // Delay (ticks) until the function will (next) be run
    u16 Delay;
    // Interval (ticks) between subsequent runs.
    u16 Period;
    // Incremented (by scheduler) when task is due to execute
    u8 RunMe;
}sTask;


#define SCH_MAX_TASKS   6
void SCH_Init();
void SCH_Add_Task((void (*pv)(void)),u16 u16Delay, u16 u16Period);
void SCH_Start(void);
void SCH_Dispatch_Tasks(void);
#endif