#include "STD_TYPES.h"
#include "BIT_CALC.h"

#include "DIO_interface.h"

#include "DIO_config.h"

#include "DIO_private.h"




/*void DIO_voidInit(void)
{
    DDRA->ByteAccess=CONC_8bit (DIO_u8_PIN0_DIR,
                           DIO_u8_PIN1_DIR,
                           DIO_u8_PIN2_DIR,
                           DIO_u8_PIN3_DIR,
                           DIO_u8_PIN4_DIR,
                           DIO_u8_PIN5_DIR,
                           DIO_u8_PIN6_DIR,
                           DIO_u8_PIN7_DIR
    );

    DDRB->ByteAccess=CONC_8bit(DIO_u8_PIN8_DIR ,
                          DIO_u8_PIN9_DIR ,
                          DIO_u8_PIN10_DIR,
                          DIO_u8_PIN11_DIR,
                          DIO_u8_PIN12_DIR,
                          DIO_u8_PIN13_DIR,
                          DIO_u8_PIN14_DIR,
                          DIO_u8_PIN15_DIR
    );

     DDRC->ByteAccess=CONC_8bit(DIO_u8_PIN16_DIR,
                           DIO_u8_PIN17_DIR,
                           DIO_u8_PIN18_DIR,
                           DIO_u8_PIN19_DIR,
                           DIO_u8_PIN20_DIR,
                           DIO_u8_PIN21_DIR,
                           DIO_u8_PIN22_DIR,
                           DIO_u8_PIN23_DIR
    );

     DDRD->ByteAccess=CONC_8bit(DIO_u8_PIN24_DIR,
                           DIO_u8_PIN25_DIR,
                           DIO_u8_PIN26_DIR,
                           DIO_u8_PIN27_DIR,
                           DIO_u8_PIN28_DIR,
                           DIO_u8_PIN29_DIR,
                           DIO_u8_PIN30_DIR,
                           DIO_u8_PIN31_DIR
    );


     // SET PORT VALUES  :
     PORTA->ByteAccess=CONC_8bit (DIO_u8_PIN0_VALUE,
                            DIO_u8_PIN1_VALUE,
                            DIO_u8_PIN2_VALUE,
                            DIO_u8_PIN3_VALUE,
                            DIO_u8_PIN4_VALUE,
                            DIO_u8_PIN5_VALUE,
                            DIO_u8_PIN6_VALUE,
                            DIO_u8_PIN7_VALUE
     );

     PORTB->ByteAccess=CONC_8bit(DIO_u8_PIN8_VALUE ,
                           DIO_u8_PIN9_VALUE,
                           DIO_u8_PIN10_VALUE,
                           DIO_u8_PIN11_VALUE,
                           DIO_u8_PIN12_VALUE,
                           DIO_u8_PIN13_VALUE,
                           DIO_u8_PIN14_VALUE,
                           DIO_u8_PIN15_VALUE
     );
      PORTC->ByteAccess=CONC_8bit(DIO_u8_PIN16_VALUE,
                            DIO_u8_PIN17_VALUE,
                            DIO_u8_PIN18_VALUE,
                            DIO_u8_PIN19_VALUE,
                            DIO_u8_PIN20_VALUE,
                            DIO_u8_PIN21_VALUE,
                            DIO_u8_PIN22_VALUE,
                            DIO_u8_PIN23_VALUE
     );
      PORTD->ByteAccess=CONC_8bit(DIO_u8_PIN24_VALUE,
                            DIO_u8_PIN25_VALUE,
                            DIO_u8_PIN26_VALUE,
                            DIO_u8_PIN27_VALUE,
                            DIO_u8_PIN28_VALUE,
                            DIO_u8_PIN29_VALUE,
                            DIO_u8_PIN30_VALUE,
                            DIO_u8_PIN31_VALUE
     );


  return;
}*/




//  pin APIs
u8 DIO_u8SetPinDirection(u8  Copy_u8PinNb, u8 Copy_u8Direction){
    u8 Local_u8Error=ERROR_OK;
    u8 Local_u8PinId;
    u8 Local_u8PortId;
    if(Copy_u8PinNb >= DIO_MAXPINNB || Copy_u8PinNb < STD_ZERO || Copy_u8Direction > DIO_MAX_PINS_IN_PORT || Copy_u8Direction < STD_ZERO ||  Copy_u8Direction == DIO_RESERVED_DIR){
      Local_u8Error = ERROR_NOK;
    }else{
        if(Copy_u8PinNb < STD_EIGHT){
          BIT_CALC_ASSIGN_NIBBLE(Copy_u8PinNb ,Copy_u8Direction, CRLA->LongAccess );
        }else if( Copy_u8PinNb < STD_SIXTEEN){
          BIT_CALC_ASSIGN_NIBBLE(Copy_u8PinNb- STD_EIGHT ,Copy_u8Direction, CRHA->LongAccess );
        }else if (Copy_u8PinNb < STD_TWENTY_FOUR){
          BIT_CALC_ASSIGN_NIBBLE(Copy_u8PinNb- STD_SIXTEEN ,Copy_u8Direction, CRLB->LongAccess );
        }else if (Copy_u8PinNb < STD_THIRTY_TWO){
          BIT_CALC_ASSIGN_NIBBLE(Copy_u8PinNb- STD_TWENTY_FOUR ,Copy_u8Direction, CRHB->LongAccess );
        }else if (Copy_u8PinNb < STD_THIRTY_FIVE){
          BIT_CALC_ASSIGN_NIBBLE(Copy_u8PinNb- STD_NINTEEN ,Copy_u8Direction, CRHC->LongAccess );
        }else{
          BIT_CALC_ASSIGN_NIBBLE(Copy_u8PinNb- STD_THIRTY_FIVE ,Copy_u8Direction, CRLD->LongAccess );
        }
    }
    return Local_u8Error;
}

/*********************************************************/
/*Description :                                          */
/*------------                                           */
/*		this function set PIN VALUE                     */
/*	INPUTS :                                             */
/*			Copy_u8PinNb     : PIN Number                */
/* 	 	 	Copy_u8PinValue : PIN VALUE                  */
/*	OUTPUT:                                              */
/*			return ERROR STATE                           */
/*********************************************************/
u8 DIO_u8SetPinValue(u8  Copy_u8PinNb, u8  Copy_u8PinValue){
    u8 Local_u8Error=ERROR_OK;
    u8 Local_u8PinId;
    u8 Local_u8PortId;
    if(Copy_u8PinNb >= DIO_MAXPINNB || Copy_u8PinNb < STD_ZERO || (Copy_u8PinValue != DIO_u8_PIN_LOW && Copy_u8PinValue != DIO_u8_PIN_HIGH) ){
      Local_u8Error = ERROR_NOK;
    }else{
        
        switch(Copy_u8PinValue){
          case  DIO_u8_PIN_LOW :
            if(Copy_u8PinNb < STD_SIXTEEN){
                BRRA->LongAccess = (1 << Copy_u8PinNb);
            }else if (Copy_u8PinNb < STD_THIRTY_TWO){
              BRRB->LongAccess = (1 << (Copy_u8PinNb - STD_SIXTEEN));
            }else if (Copy_u8PinNb < STD_THIRTY_FIVE){
                BRRC->LongAccess = (1 << (Copy_u8PinNb - STD_NINTEEN));
            }else{
              BRRD->LongAccess = (1 << (Copy_u8PinNb - STD_THIRTY_FIVE));
            }


          break;
          case DIO_u8_PIN_HIGH : 
            if(Copy_u8PinNb < STD_SIXTEEN){
                BSRA->LongAccess = (1 << Copy_u8PinNb);
            }else if (Copy_u8PinNb < STD_THIRTY_TWO){
              BSRB->LongAccess = (1 << (Copy_u8PinNb - STD_SIXTEEN));
            }else if (Copy_u8PinNb < STD_THIRTY_FIVE){
                BSRC->LongAccess = (1 << (Copy_u8PinNb - STD_NINTEEN));
            }else{
              BSRD->LongAccess = (1 << (Copy_u8PinNb - STD_THIRTY_FIVE));
            }


          break;
        }
    }
    return Local_u8Error;
}
u8 DIO_u8GetPinValue(u8  Copy_u8PinNb, u8 *  Copy_pu8PinValue){
	/*********************************************************/
	/*Description :                                          */
	/*------------                                           */
	/*		this function reads pin value and save it          */
	/* 		in Copy_pu8PinValue                                */
	/*	INPUTS :                                             */
	/*			Copy_u8PinNb     : PIN Number                    */
	/* 	 	 	Copy_u8PinValue  : PIN VALUE                     */
	/*	OUTPUT:                                              */
	/*			return :ERROR STATE                              */
	/*********************************************************/
  u8 Local_u8Error=ERROR_OK;
    u8 Local_u8PinId;
    u8 Local_u8PortId;
    if((Copy_u8PinNb >= DIO_MAXPINNB || Copy_u8PinNb < STD_ZERO ) || (Copy_pu8PinValue ==NULL)){
      Local_u8Error = ERROR_NOK;
    }else{
            if(Copy_u8PinNb < STD_SIXTEEN){
                *Copy_pu8PinValue = BIT_CALC_GET_BIT(IDRA->LongAccess,Local_u8PinId);
            }else if (Copy_u8PinNb < STD_THIRTY_TWO){
              *Copy_pu8PinValue = BIT_CALC_GET_BIT(IDRB->LongAccess,Local_u8PinId - STD_SIXTEEN);
            }else if (Copy_u8PinNb < STD_THIRTY_FIVE){
              *Copy_pu8PinValue = BIT_CALC_GET_BIT(IDRC->LongAccess,Local_u8PinId - STD_NINTEEN);
            }else{
               *Copy_pu8PinValue = BIT_CALC_GET_BIT(IDRD->LongAccess,Local_u8PinId - STD_THIRTY_FIVE);
            }

      }

    
    return Local_u8Error;
}

// [NOT NOW ]
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNb, u8  Copy_u8Direction){
	/*********************************************************/
	/*Description :                                          */
	/*------------                                           */
	/*		this function SETS PORT DIRECTION                */
	/*	INPUTS :                                             */
	/*			Copy_u8PortNb    : PORT Number               */
	/* 	 	 	Copy_u8Direction  : PORT direction           */
	/*	OUTPUT:                                              */
	/*			return :ERROR STATE                          */
	/*********************************************************/





  u8 Local_u8Error=ERROR_OK;
  if((Copy_u8PortNb >= DIO_MAXPORTNB) || (Copy_u8Direction <=DIO_PORT_OUTPUT && Copy_u8Direction >= DIO_PORT_INPUT)){
    Local_u8Error = ERROR_NOK;
  }else{
    switch (Copy_u8PortNb){
      case DIO_PORT_A :
        BIT_CALC_SET_PORT_DIRECTION(PORTA->ByteAccess,Copy_u8Direction);
      break;
      case DIO_PORT_B:
        BIT_CALC_SET_PORT_DIRECTION(PORTB->ByteAccess,Copy_u8Direction);
      break;
      case DIO_PORT_C:
        BIT_CALC_SET_PORT_DIRECTION(PORTC->ByteAccess,Copy_u8Direction);
      break;
      case DIO_PORT_D:
        BIT_CALC_SET_PORT_DIRECTION(PORTD->ByteAccess,Copy_u8Direction);
      break;
    }

  }
  return Local_u8Error;
}


  /*********************************************************/
  /*Description :                                          */
  /*------------                                           */
  /*    this function SETS PORT VALUE                    */
  /*  INPUTS :                                             */
  /*      Copy_u8PortNb    : PORT Number               */
  /*      Copy_u8Direction  : PORT VALUE               */
  /*  OUTPUT:                                              */
  /*      return :ERROR STATE                          */
  /*********************************************************/
u8 DIO_u8SetPortnValue(u8  Copy_u8PortNb, u8  Copy_u8PortValue){

  u8 Local_u8Error=ERROR_OK;

    if((Copy_u8PortNb >= DIO_MAXPORTNB || Copy_u8PortNb < STD_ZERO) || (Copy_u8PortValue > DIO_MAX_PORT_VALUE || Copy_u8PortValue < DIO_MIN_PORT_VALUE)){
    Local_u8Error = ERROR_NOK;
  }else{
    switch (Copy_u8PortNb){
      case DIO_PORT_A :
        BIT_CALC_SET_PORT_VALUE(ODRA->LongAccess,Copy_u8PortValue);
      break;
      case DIO_PORT_B:
        BIT_CALC_SET_PORT_VALUE(ODRB->LongAccess,Copy_u8PortValue);
      break;
      case DIO_PORT_C:
        BIT_CALC_SET_PORT_VALUE(ODRC->LongAccess,Copy_u8PortValue);
      break;
      case DIO_PORT_D:
        BIT_CALC_SET_PORT_VALUE(ODRD->LongAccess,Copy_u8PortValue);
      break;
    }

  }
  return Local_u8Error;
}
u8 DIO_u8GetPortnValue(u8  Copy_u8PinNb, u8 *  Copy_pu8PortValue){
	/*********************************************************/
	/*Description :                                          */
	/*------------                                           */
	/*		this function GETS PORT VALUE and store it       */
	/*      in  Copy_pu8PortValue                            */
	/*	INPUTS :                                             */
	/*			Copy_u8PortNb    : PORT Number               */
	/* 	 	 	Copy_u8Direction : PORT direction            */
	/*	OUTPUT:                                              */
	/*			return :ERROR STATE                          */
	/*********************************************************/
  u8 Local_u8Error=ERROR_OK;
  if((Copy_u8PinNb >= DIO_MAXPORTNB) ){
    Local_u8Error = ERROR_NOK;
  }else{
    switch (Copy_u8PinNb){
      case DIO_PORT_A :
        *Copy_pu8PortValue = PINA->ByteAccess;
      break;
      case DIO_PORT_B:
        *Copy_pu8PortValue = PINB->ByteAccess;
      break;
      case DIO_PORT_C:
        *Copy_pu8PortValue = PINC->ByteAccess;
      break;
      case DIO_PORT_D:
        *Copy_pu8PortValue = PIND->ByteAccess;
      break;
    }

  }
  return Local_u8Error;
}
