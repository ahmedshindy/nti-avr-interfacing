#ifndef I2C_CONFIG
#define I2C_CONFIG

/*Options */
#define SLAVE_MODE      0
#define MASTER_MODE     1
#define SCL_CLK_OPTION_ONE      100000UL
#define SCL_CLK_OPTION_THREE    400000UL


#define SCL_PRESCALAR_01        0x01
#define SCL_PRESCALAR_4         0x04
#define SCL_PRESCALAR_16        0x16
#define SCL_PRESCALAR_64        0x64



/***Configurations */
#define MODE            MASTER_MODE
#define SCL_Clock       SCL_CLK_OPTION_THREE
#define SCL_PRESCALAR   SCL_PRESCALAR_16

#endif