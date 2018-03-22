/* programme PWM_motor */

#include "stm32l1xx_nucleo.h"




void init_TIM3 (void);
void init_PWM (void);
 void _init_ms();
void _stop_timer();
 void Delay_ms(uint32_t mSecs);
 void init_MOTEUR_EXT ();
void init_PB4 ();
//////////////////// Neon project ////////////////////


extern  uint32_t valeur = 20;

void init_GPIO_Servo()
  {
    //Dans le GPIO
    RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
    //configuration de PC9
      //mode AF
      GPIOC->MODER |= GPIO_MODER_MODER9_1;
      GPIOC->MODER &= ~GPIO_MODER_MODER9_0;      
      //vitesse
      GPIOC->OSPEEDR &=~ GPIO_OSPEEDER_OSPEEDR9_0;
      GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9_1;
      //configuration en mode PP
      GPIOC->OTYPER &=~ GPIO_OTYPER_OT_9;
      
      // Sélection et configuration de la fonction multiplexée AFRH9 
      GPIOC->AFR[1] &= ~GPIO_AFRH_AFRH9;
      GPIOC->AFR[1] |= (1<<17);
  }

void init_PB4 (void)  /*Moteur sur PB4*/
{
  
   /* force b1 at 1 activating the GPIOB on AHB data bus */
  
  RCC->AHBENR |= (1<<1);       
  
  /* set the port GPIOB as an alternative function */
  
  GPIOB->MODER |= (1<<9);      /* set MODER4 to 10 (0X1) */
  GPIOB->MODER &= ~(1<<8);     
  
  /* set the port GPIOB in a push-pull mode (deliver current) */
  GPIOB->OTYPER &= ~(1<<4);     /* set OTYPER 4 to 0  Moteur sur PB4*/ 
  
  GPIOB->AFR[0] &= ~ (1<<16);  
  GPIOB->AFR[0] |= (1<<17);  /*registre de sélection de la fonction multiplexée*/
                             /*TIM3 AFRL(PB4) 0010 bit 17 à 1*/
  GPIOB->AFR[0] &= ~(1<<18);
  GPIOB->AFR[0] &= ~(1<<19);
}



void actualisation_Rapport_Cyclique_Servo(uint32_t valeur)
{
    // Reconfiguration du rapport cyclique
    TIM4->CCR4 = valeur;
}





    
    



void main()

{
   
  init_TIM3 ();
  init_PWM ();
  //init_MOTEUR_EXT();

init_PB4 ();
    
    init_GPIO_Servo();


  
  
  while (1)
  {
    /* program execution */

    
    
  }
  
}

void init_TIM3 (void)
{
  RCC->APB1ENR |= (1<<1); /* force b1 at 1 activating the TIM3 on APB data bus */
  
  //TIM3->PSC = 1599;    /* PSC+1=1599+1=1600 soit F=10kHz donc T=100µs */
  //TIM3->ARR = 39; /* 40*100µs = 4ms donc ARR = 40-1=39*/
  
  TIM3->PSC = 319;    /* PSC+1=1599+1=1600 soit F=100Hz donc T=100µs */
  TIM3->ARR = 999; /* 40*100µs = 4ms donc ARR = 40-1=39*/
  
  
  //_______
  //TIM3->PSC = 3199;    /* PSC+1=1599+1=1600 soit F=100Hz donc T=100µs */
  //TIM3->ARR = 99; /* 40*100µs = 4ms donc ARR = 40-1=39*/
  //______
  
  //TIM3->PSC = 319999;    /* PSC+1=320 000 soit F=50Hz donc T=20ms */
  //TIM3->ARR = 100; /* 100*20ms = 2000ms donc ARR = 40-1=39*/
  
  //TIM3->PSC = 15;    /* PSC+1=15+1=16 soit F=1MHz donc T=1µs */
  //TIM3->ARR = 100; /* 49+1=50*1µs = 50µs soit F=20kHz*/
  
  TIM3->CR1 |= (1<<7); /*ARPE Autoreload register buffered*/
  TIM3->CR1 &= ~(1<<6); /*CMS edge alligned*/
  TIM3->CR1 &= ~(1<<5); /*CMS edge alligned*/
  TIM3->CR1 &= ~(1<<4); /*DIR upcounter*/
   
  
  TIM3->CR1 |= (1<<0); /*CEN counter enable*/
}

void init_PWM (void)
{
  TIM3->CCMR1 &= ~((1<<0) | (1<<1)); /* define CH1 as an output  (PA6)*/
  TIM3->CCMR1 &= ~(1<<4); /* PMW mode 1 */
  TIM3->CCMR1 |= ((1<<5) | (1<<6));
  
  TIM3->CCR1 = 75; /* duty cycle 75 -> 7,5%  -> 1.5ms -> 90° */
  
  //TIM3->CCR1 = 33; /* duty cycle  rapport cyclique= 2/3*/
  
  TIM3->CCER |= (1<<0); /* signal enable */ 
  
}  

void init_MOTEUR_EXT (void)  /*Moteur sur PB4*/
{
  
   /* force b1 at 1 activating the GPIOB on AHB data bus */
  
  RCC->AHBENR |= (1<<1);       
  
  /* set the port GPIOB as an alternative function */
  
  GPIOB->MODER |= (1<<9);      /* set MODER4 to 10 (0X1) */
  GPIOB->MODER &= ~(1<<8);     
  
  /* set the port GPIOB in a push-pull mode (deliver current) */
  GPIOB->OTYPER &= ~(1<<4);     /* set OTYPER 4 to 0  Moteur sur PB4*/ 
  
  GPIOB->AFR[0] &= ~ (1<<16);  
  GPIOB->AFR[0] |= (1<<17);  /*registre de sélection de la fonction multiplexée*/
                             /*TIM3 AFRL(PB4) 0010 bit 17 à 1*/
  GPIOB->AFR[0] &= ~(1<<18);
  GPIOB->AFR[0] &= ~(1<<19);
}
  

