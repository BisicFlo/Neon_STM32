/******************************************************************************/
/*                                                                            */
/*                      MAIN BASIQUE STM32L152RE                              */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                       ELodie PAULY                                         */
/*                        Février 2017                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/******************************************************************************/



#include "stm32l1xx_nucleo.h"





void main()
{
    uint8_t tmp;
    /*activation de l'horloge sur GPIOB*/
    RCC ->AHBENR |= (1<<1);
     /*configuration PB1 en OUTPUT MODERs = 01*/
    tmp = GPIOB -> MODER;
    tmp &=(1<<3);
    tmp |=(1<<2);
    GPIOB -> MODER = tmp;
     /*configuration PB1 en pushpull OTYPERs  = 0*/
    
    GPIOB -> OTYPER &= ~(1<<1);
    /*configuration PAS en high speed  OSPEEDRs  = 11*/
    GPIOB -> OSPEEDR |= ((1<<2)|(1<<3));
    /* etat initial*/
    GPIOB-> ODR &=~(1<<1);
    
    
    /*________________________________________________*/
      /*activation de l'horloge sur GPIOB*/
    RCC ->AHBENR |= (1<<2);
     /*configuration PC5 en input MODERs = 00*/
    GPIOC -> MODER  &= ~((1<<10)|(1<<11));

    
    GPIOC -> PUPDR &= ~((1<<10)|(1<<11));

    
  
  while(1)
  {
 /* GPIOB-> ODR |= (1<<1);
   for (uint16_t i=0;i<65535;i++);
   
   GPIOB-> ODR &=~(1<<1);
   for ( uint16_t i=0 ; i < 65535;i++);
   
    */
    
    
    while ( ( GPIOC -> IDR &(1<<5))!=0);
    
    GPIOB-> ODR ^=(1<<1);
  }
  
}

