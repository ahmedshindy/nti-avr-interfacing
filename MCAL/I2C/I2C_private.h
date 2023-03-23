#ifndef I2C_PRIV
#define I2C_PRIV


#define TWCR        (*((volatile u8* )0x56))
/* TWCR */
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
/* bit 1 reserved */
#define TWIE    0

#define TWDR        (*((volatile u8* )0x23))


/* TWAR */
#define TWAR        (*((volatile u8* )0x22))
#define TWA6    7
#define TWA5    6
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE   0

/* TWSR */
#define    TWSR     (*((volatile u8* )0x21))
#define TWS7    7
#define TWS6    6
#define TWS5    5
#define TWS4    4
#define TWS3    3
/* bit 2 reserved */
#define TWPS1   1
#define TWPS0   0


#define    TWBR     (*((volatile u8* )0x20))
#endif