/************************************************/
/* Author : Amr Abbdeen                         */
/* Date   : 5 Feb. 2019                         */
/* Version: V01                                 */          
/************************************************/

/*Comment: inital direction for I/O pins       */
/*Range  : DIO_u8_PIN_INIT_OUTPUT              */
/*         DIO_u8_PIN_INIT_INPUT               */

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define DIO_u8_PIN0     (u8)0
#define DIO_u8_PIN1   	(u8)1
#define DIO_u8_PIN2   	(u8)2
#define DIO_u8_PIN3   	(u8)3
#define DIO_u8_PIN4   	(u8)4
#define DIO_u8_PIN5   	(u8)5
#define DIO_u8_PIN6   	(u8)6
#define DIO_u8_PIN7   	(u8)7
#define DIO_u8_PIN8   	(u8)8
#define DIO_u8_PIN9   	(u8)9
#define DIO_u8_PIN10    (u8)10
#define DIO_u8_PIN11    (u8)11
#define DIO_u8_PIN12    (u8)12
#define DIO_u8_PIN13    (u8)13
#define DIO_u8_PIN14    (u8)14
#define DIO_u8_PIN15    (u8)15
#define DIO_u8_PIN16    (u8)16
#define DIO_u8_PIN17    (u8)17
#define DIO_u8_PIN18    (u8)18
#define DIO_u8_PIN19    (u8)19
#define DIO_u8_PIN20    (u8)20
#define DIO_u8_PIN21    (u8)21
#define DIO_u8_PIN22    (u8)22
#define DIO_u8_PIN23    (u8)23
#define DIO_u8_PIN24    (u8)24
#define DIO_u8_PIN25    (u8)25
#define DIO_u8_PIN26    (u8)26
#define DIO_u8_PIN27    (u8)27
#define DIO_u8_PIN28    (u8)28
#define DIO_u8_PIN29    (u8)29
#define DIO_u8_PIN30    (u8)30
#define DIO_u8_PIN31    (u8)31
#define DIO_u8_PIN32    (u8)32
#define DIO_u8_PIN33    (u8)33
#define DIO_u8_PIN34    (u8)34
#define DIO_u8_PIN35    (u8)35
#define DIO_u8_PIN36    (u8)36
#define DIO_u8_PIN37    (u8)37

/*****************************************************/
/*Description:                                       */
/*--------------                                     */
/* Used to define Port Values                        */
/* DIO_u8_PORT_LOW: Used to indicate port LOW Value  */
/* DIO_u8_PORT_HIGH Used to indicate port HIGH Value */
/*****************************************************/
#define DIO_u8_PORT_LOW     (u8)0
#define DIO_u8_PORT_HIGH    (u8)1
/*************************************************************/
/*Description:                                               */
/*--------------                                             */
/* Used to define Port Directions                            */
/* DIO_u8_PORT_INPUT:Used to define port Input Direction     */
/* DIO_u8_PORT_OUTPUT:Used to define port Ou8tput Direction   */
/*************************************************************/
#define DIO_u8_PORT_INPUT_PULL_UP_DOWN  		(u8)0b1000
#define DIO_u8_PORT_INPUT_FLOATING   			(u8)0b0100
#define DIO_u8_PORT_INPUT_ANALOG   				(u8)0b0000
                                                
#define DIO_u8_PORT_2M_OUTPUT_PUSH_PULL  		(u8)0b0011
#define DIO_u8_PORT_2M_OUTPUT_OPEN_DRAIN 		(u8)0b0111
#define DIO_u8_PORT_2M_OUTPUT_AF_PUSH_PULL 		(u8)0b1011
#define DIO_u8_PORT_2M_OUTPUT_AF_OPEN_DRAIN		(u8)0b1111
                                                
                                                
#define DIO_u8_PORT_10M_OUTPUT_PUSH_PULL  		(u8)0b0010
#define DIO_u8_PORT_10M_OUTPUT_OPEN_DRAIN 		(u8)0b0101
#define DIO_u8_PORT_10M_OUTPUT_AF_PUSH_PULL  	(u8)0b1001
#define DIO_u8_PORT_10M_OUTPUT_AF_OPEN_DRAIN 	(u8)0b1101
                                                
#define DIO_u8_PORT_50M_OUTPUT_PUSH_PULL  		(u8)0b0011
#define DIO_u8_PORT_50M_OUTPUT_OPEN_DRAIN 		(u8)0b0111
#define DIO_u8_PORT_50M_OUTPUT_AF_PUSH_PULL  	(u8)0b1011
#define DIO_u8_PORT_50M_OUTPUT_AF_OPEN_DRAIN 	(u8)0b1111                  

/***************************************************/
/*Description:                                     */
/*--------------                                   */
/* Used to define Port Values                      */
/* DIO_u8_PIN_LOW :Used to define Pin LOW Value    */
/* DIO_u8_PIN_HIGH :Used to define Pin HIGH Value  */
/***************************************************/
#define DIO_u8_PIN_LOW     (u8)0
#define DIO_u8_PIN_HIGH    (u8)1


/***************************************************/
/*Description:                                     */
/*--------------                                   */
/* Used to define Port numbers                     */
/*	           DIO_U8_PORTA : Port 0               */
/*			   DIO_U8_PORTB : Port 1               */
/*             DIO_U8_PORTC : Port 2               */
/*             DIO_U8_PORTD : Port 3               */
/***************************************************/
#define DIO_U8_PORT0     (u8)0
#define DIO_U8_PORT1     (u8)1
#define DIO_U8_PORT2     (u8)2
#define DIO_U8_PORT3     (u8)3

/***************************************************/
/*Description:                                     */
/*--------------                                   */
/* void DIO_voidInit(void)                         */
/*	           DIO_u8_PORT_LOW                     */
/*			   DIO_u8_PORT_HIGH                    */
/***************************************************/
void DIO_voidInit(void );
/***************************************************/
/*Description:                                     */
/*--------------                                   */
/* Used to configure Port Values                   */
/*	           DIO_u8_PORT_LOW                     */
/*			   DIO_u8_PORT_HIGH                    */
/***************************************************/
//  pin APIs
u8 DIO_u8SetPinDirection(u8  Copy_u8PinNb,u8  Copy_u8Direction);

/***************************************************/
/*Description:                                     */
/*--------------                                   */
/* Used to configure Port Values                   */
/*	           DIO_u8_PORT_LOW                     */
/*			   DIO_u8_PORT_HIGH                    */
/***************************************************/
u8 DIO_u8SetPinValue(u8  Copy_u8PinNb, u8  Copy_u8PinValue);
/***************************************************/
/*Description:                                     */
/*--------------                                   */
/* Used to configure Port Values                   */
/*	           DIO_u8_PORT_LOW                     */
/*			   DIO_u8_PORT_HIGH                    */
/***************************************************/
u8 DIO_u8GetPinValue(u8  Copy_u8PinNb, u8 *  Copy_pu8PinValue);
/***************************************************/
/*Description:                                     */
/*--------------                                   */
/* Used to configure Port Values                   */
/*	           DIO_u8_PORT_LOW                     */
/*			   DIO_u8_PORT_HIGH                    */
/***************************************************/

// port APIs
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNb, u8  Copy_u8Direction);
/***************************************************/
/*Description:                                     */
/*--------------                                   */
/* Used to configure Port Values                   */
/*	           DIO_u8_PORT_LOW                     */
/*			   DIO_u8_PORT_HIGH                    */
/***************************************************/
u8 DIO_u8SetPortnValue(u8  Copy_u8PortNb, u8  Copy_u8PortValue);
/***************************************************/
/*Description:                                     */
/*--------------                                   */
/* Used to configure Port Values                   */
/*	           DIO_u8_PORT_LOW                     */
/*			   DIO_u8_PORT_HIGH                    */
/***************************************************/
u8 DIO_u8GetPortnValue(u8  Copy_u8PinNb, u8 *  Copy_pu8PortValue);




#endif
