/************************************************/
/* Author : Amr Abbdeen                         */
/* Date   : 5 Feb. 2019                         */
/* Version: V01                                 */          
/************************************************/

/*Comment: inital direction for I/O pins       */
/*Range  : DIO_u8_PIN_INIT_OUTPUT              */
/*         DIO_u8_PIN_INIT_INPUT               */

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#define DIO_PIN_INIT_OUTPUT 1
#define DIO_PIN_INIT_INPUT  0

#define DIO_PIN_INIT_HIGH   1
#define DIO_PIN_INIT_LOW    0

#define DIO_u8_PIN_DEFAULT     0 

/***********************************************************/
/* PORT0                                                   */
/***********************************************************/
#define CRLA  ((Register32*)                    0x4001 0800)
#define CRHA  ((Register32*)                    0x4001 0804)
#define IDRA  ((Register32*)                    0x4001 0808)
#define ODRA  ((Register32*)                    0x4001 080C)
#define BSRA  ((Register32*)                    0x4001 0810)
#define BRRA  ((Register32*)                    0x4001 0814)
#define LCKA  ((Register32*)                    0x4001 0818)
/***********************************************************/

/***********************************************************/
/* PORT1                                                   */
/***********************************************************/
#define CRLB  ((Register32*)                    0x4001 0C00)
#define CRHB  ((Register32*)                    0x4001 0C04)
#define IDRB  ((Register32*)                    0x4001 0C08)
#define ODRB  ((Register32*)                    0x4001 0C0C)
#define BSRB  ((Register32*)                    0x4001 0C10)
#define BRRB  ((Register32*)                    0x4001 0C14)
#define LCKB  ((Register32*)                    0x4001 0C18)
/***********************************************************/


/***********************************************************/
/* PORT2                                                   */
/***********************************************************/
#define CRLC  ((Register32*)                    0x4001 1000)
#define CRHC  ((Register32*)                    0x4001 1004)
#define IDRC  ((Register32*)                    0x4001 1008)
#define ODRC  ((Register32*)                    0x4001 100C)
#define BSRC  ((Register32*)                    0x4001 1010)
#define BRRC  ((Register32*)                    0x4001 1014)
#define LCKC  ((Register32*)                    0x4001 1018)
/***********************************************************/

/***********************************************************/
/* PORT3                                                  */
/***********************************************************/
#define CRLD  ((Register32*)                    0x4001 1400)
#define CRHD  ((Register32*)                    0x4001 1404)
#define IDRD  ((Register32*)                    0x4001 1408)
#define ODRD  ((Register32*)                    0x4001 140C)
#define BSRD  ((Register32*)                    0x4001 1410)
#define BRRD  ((Register32*)                    0x4001 1414)
#define LCKD  ((Register32*)                    0x4001 1418)
/***********************************************************/


/**********************************************************************************/
/* DIO_PIN_INPUT : represents 0 to indicate Pin direction is Input                */
/* DIO_PIN_OUTPUT: represents 1 to indicate Pin direction is Output               */
/* PIN_VALUE_HIGH: represents 1 to indicate Pin Value/state is High               */
/* PIN_VALUE_LOW: represents 0 to indicate Pin Value/state is LOW                 */
/* DIO_PORT_OUTPUT: represents 0xFF to indicate Port direction is Output          */
/* DIO_PORT_INPUT: represents 0x00 to indicate Port direction is Input            */
/* DIO_PORT_VALUE_MAX: represents 0xFF to indicate Max. value of Port register    */
/* width                                                                          */
/**********************************************************************************/

#define DIO_PIN_INPUT                         0
#define DIO_PIN_OUTPUT                        1
#define PIN_VALUE_HIGH                        1
#define PIN_VALUE_LOW                         0
#define DIO_PORT_OUTPUT                       0xFF
#define DIO_PORT_INPUT                        0x00

#define DIO_PORT_VALUE_MIN                    0x00


#define DIO_NUMBER_PINS_IN_PORT               8

#define DIO_DDR_A                             0
#define DIO_DDR_B                             1
#define DIO_DDR_C                             2
#define DIO_DDR_D                             3

#define DIO_PORT_A                            0
#define DIO_PORT_B                            1
#define DIO_PORT_C                            2
#define DIO_PORT_D                            3

#define DIO_PIN_A                             0
#define DIO_PIN_B                             1
#define DIO_PIN_C                             2
#define DIO_PIN_D                             3

#endif // STD_TYPES_H_INCLUDED
/**********************************************************************************/
/* Author : Amr Abdeen                                                            */
/* Date   : 31 Jan. 2019                                                          */
/* Version: V01                                                                   */
/**********************************************************************************/
/* Description:                                                                   */
/*--------------                                                                  */
/* DIO private File is used to define private DIO Macros.Only accessed within     */
/* DIO Driver.                                                                    */
/*                                                                                */
/**********************************************************************************/

#ifndef ATMEGA32_REGISSTERS_H_
#define ATMEGA32_REGISSTERS_H_

/**********************************************************************************/
/* DIO Registers:                                                                 */
/*--------------                                                                  */
/* DDRx : represents the DATA DIRECTION Register where x is the Port Name.        */
/* PORTx: represents the PORT Register where x is the Port Name.                  */
/* PINx: represents the PIN Register where x is the Port Name.                    */
/*                                                                                */
/**********************************************************************************/




/**********************************************************************************/
/* DIO_PIN_INPUT : represents 0 to indicate Pin direction is Input                */
/* DIO_PIN_OUTPUT: represents 1 to indicate Pin direction is Output               */
/* PIN_VALUE_HIGH: represents 1 to indicate Pin Value/state is High               */
/* PIN_VALUE_LOW: represents 0 to indicate Pin Value/state is LOW                 */
/* DIO_PORT_OUTPUT: represents 0xFF to indicate Port direction is Output          */
/* DIO_PORT_INPUT: represents 0x00 to indicate Port direction is Input            */
/* DIO_PORT_VALUE_MAX: represents 0xFF to indicate Max. value of Port register    */
/* width                                                                          */
/**********************************************************************************/
   
#define DIO_PIN_INPUT                         0
#define DIO_PIN_OUTPUT                        1
#define PIN_VALUE_HIGH                        1
#define PIN_VALUE_LOW                         0
#define DIO_PORT_OUTPUT                       0xFF
#define DIO_PORT_INPUT                        0x00
#define DIO_PORT_VALUE_MAX                    0xFF
#define DIO_PORT_VALUE_MIN                    0x00


#define DIO_NUMBER_PINS_IN_PORT               8

#define DIO_DDR_A                             0
#define DIO_DDR_B                             1
#define DIO_DDR_C                             2
#define DIO_DDR_D                             3

#define DIO_PORT_A                            0
#define DIO_PORT_B                            1
#define DIO_PORT_C                            2
#define DIO_PORT_D                            3

#define DIO_PIN_A                             0
#define DIO_PIN_B                             1
#define DIO_PIN_C                             2
#define DIO_PIN_D                             3

#define DIO_MAXPINNB 37
#define DIO_MAXPORTNB 4


#define DIO_MAX_PINS_IN_PORT    				(u8)15
#define DIO_RESERVED_DIR        				(u8)12
#define DIO_MAX_PORT_VALUE                      (u16)0xFFFF
#define DIO_MIN_PORT_VALUE                      (u16)0x0000

#endif // STD_TYPES_H_INCLUDED


