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

void initLed(void)
{
  //configuration en sortie PushPull du periph GPIOB
  //alimenter le periph GPIOB
      RCC->AHBENR|=(1<<1);
        
  //config all led
  //config PBI en sortie
      //led 1
      GPIOB->MODER|=(1<<2);
      GPIOB->MODER&=~(1<<3);
      //led 2
      GPIOB->MODER|=(1<<4);
      GPIOB->MODER&=~(1<<5);
      //led 8,7,6,5,4,3
      for(uint8_t i=20;i<32;i++)
      {
        GPIOB->MODER|=(1<<i);
        GPIOB->MODER&=~(1<<i+1);
        i++;
      }
      
  //Config en Push pull
      for(uint8_t i=10;i<16;i++)
        GPIOB->OTYPER&=~(1<<i);
      GPIOB->OTYPER&=~(1<<1);
      GPIOB->OTYPER&=~(1<<2);
      
  //config SPEED
      for(uint8_t i=10;i<16;i++)
        GPIOB->OSPEEDR&=~((1<<i)|(1<<i+1));
      GPIOB->OSPEEDR&=~((1<<2)|(1<<3));
      GPIOB->OSPEEDR&=~((1<<4)|(1<<5));
  //initialiser l'état
      for(uint8_t i=10;i<16;i++)
        if(i%2)
          GPIOB->ODR&=~(1<<i);
        else
          GPIOB->ODR|=(1<<i);
      GPIOB->ODR|=(1<<1);
      GPIOB->ODR&=~(1<<2);
}

void allumeLed(void)
{
    GPIOB->ODR|=(1<<1);
    GPIOB->ODR|=(1<<2);
    for(uint8_t i=10;i<16;i++)
        GPIOB->ODR|=(1<<i);
}

void eteindLed(void)
{
    GPIOB->ODR&=~(1<<1);
    GPIOB->ODR&=~(1<<2);
    for(uint8_t i=10;i<16;i++)
      GPIOB->ODR&=~(1<<i);
}

void initTimer(uint32_t temps)
{
  //activer le periph
  RCC->APB1ENR|=(1<<1);
  
  
  //config le prescaler
  TIM3->PSC=15999;
  
  //config mode compteur
  TIM3->CR1|=(1<<7);
  TIM3->CR1&=~((1<<6)|(1<<5));
  TIM3->CR1&=~(1<<4);
  
  //ARR
  TIM3->ARR=temps-1;
  
}

void DELAY(void)
{
  TIM3->CR1|=(1<<0);
  while((TIM3->SR&(1<<0))==0);
  TIM3->SR&=~(1<<0);
}

       
void initBTN(void)
{
  //configuration en sortie PushPull du periph GPIOC
  //alimenter le periph GPIOC
      RCC->AHBENR|=RCC_AHBENR_GPIOCEN;
        
  //alimenter le periph GPIOA
      RCC->AHBENR|=(1<<0);
      
      
  //config PAI en entrées
      //PA11 BTN1
      GPIOA->MODER&=~((1<<22)|(1<<23));
      //PA12 BTN2
      GPIOA->MODER&=~((1<<24)|(1<<25));
      
  //config PCI en entrées
      //PC6 BTN3
      GPIOC->MODER&=~((1<<12)|(1<<13));
      //PC5 BTN4
      GPIOC->MODER&=~((1<<11)|(1<<10));
    
  //PC en flottante
      GPIOC->PUPDR&=~((1<<10)|(1<<11));
}
  



void initInterrup(void)
{
    //interruption timer
  TIM3->DIER|=(1<<0);
  NVIC->ISER[0]|=(1<<29);
  
  //interruption btn3
  EXTI->IMR|=(1<<23);
  EXTI->FTSR|=(1<<23);
  SYSCFG->EXTICR[2]|=SYSCFG_EXTICR2_EXTI6_PC;
  NVIC->ISER[0]|=(1<<23);
  
}
  

void initMoteur(void)
{
  RCC->AHBENR|=RCC_AHBENR_GPIOBEN;
  GPIOB->MODER|=GPIO_MODER_MODER4_1;
  GPIOB->OTYPER&=~GPIO_OTYPER_OT_4;
  GPIOB->OSPEEDR|=GPIO_OSPEEDER_OSPEEDR4_0;
  GPIOB->ODR&=~GPIO_ODR_ODR_4;
  GPIOB->AFR[0]|=(2<<16);
} 
  
  
  
void main()
{
  initLed();
  initTimer(1000);
  initInterrup();
   
  //config timer pour PWM
  TIM3->CCMR1|=TIM_CCMR1_OC1M;
  TIM3->CCR1=700;
  TIM3->CCER|=TIM_CCER_CC1E;
  
  initMoteur();
     
  TIM3->CR1|=(1<<0);
//  GPIOB->ODR|=GPIO_ODR_ODR_4;
    
  while(1){
    
  }
  
}

