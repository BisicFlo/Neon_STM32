#include "stm32l1xx_nucleo.h"



void wait_t(void){
  TIM2->CR1 |=(1<<0);// On allume le CNT
  while((TIM2->SR &(1<<0))==0){ // On attend que UIF=1
  }// On applique un masque pour r�cup�rer seulement un 1 dans le bit 0
  TIM2->SR &=~(1<<0);// Apr�s on remet UIF a 0
  TIM2->CR1 &=~(1<<0);// On �teint le CNT
  }

// init les led
void init_led(void){
  RCC->AHBENR |=RCC_AHBENR_GPIOBsaolunEN;// alimenter le periph GPIOB donc on alimente AHBENR mise a 1
  GPIOB->MODER |= (1<<2);
  GPIOB->MODER &=~(1<<3);// config PB1 en sortie
  GPIOB->OTYPER &=~(1<<1);// conf en Push Pull
  GPIOB->OSPEEDR &=~((1<<2)|(1<<3));// config. Speed
  GPIOB->ODR &=~(1<<1); // Initialiser l'�tat mise a 0 au bit 1
  // Allumer la LED1
  GPIOB->MODER |= (1<<4);
  GPIOB->MODER &=~(1<<5);// config PB1 en sortie
  GPIOB->OTYPER &=~(1<<2);// conf en Push Pull
  GPIOB->OSPEEDR &=~((1<<4)|(1<<5));// config. Speed
  GPIOB->ODR &=~(1<<2); // Initialiser l'�tat mise a 0 au bit 1
  //Allumer la LED2
  GPIOB->MODER |= (1<<20);
  GPIOB->MODER &=~(1<<21);// config PB1 en sortie
  GPIOB->OTYPER &=~(1<<10);// conf en Push Pull
  GPIOB->OSPEEDR &=~((1<<20)|(1<<21));// config. Speed
  GPIOB->ODR &=~(1<<10); // Initialiser l'�tat mise a 0 au bit 1
  
  // config les LED 3,4,5,6,7
  GPIOB->MODER |= ((1<<22)|(1<<24)|(1<<26)|(1<<28)|(1<<30));
  
  GPIOB->OTYPER &=~((1<<11)|(1<<12)|(1<<13)|(1<<14)|(1<<14));
  
  GPIOB->OSPEEDR &=~((1<<22)|(1<<23)|(1<<24)|(1<<25)|(1<<26)|(1<<27)|(1<<28)|(1<<29)|(1<<30)|(1<<31));
  
  GPIOB->ODR &=~((1<<11)|(1<<12)|(1<<13)|(1<<14)|(1<<15));
}

//config timer
void init_timer(void){
  RCC->APB1ENR |=(1<<0);// activation du p�riph�rique
  TIM2->CR1 &=~((1<<4)|(1<<5)|(1<<6)); // On met 1000 au bit 7,6,5,4;
  TIM2->CR1 |=(1<<7);
  TIM2->PSC=3199; // La valeur de prescaler
  TIM2->ARR=2500; // La valeur d'auto reload 
}

void main()
{
  int j;
  init_led();
  init_timer();
  while(1)
  {
    // Allume LED0
    //GPIOB->ODR |= (1<<1); //allumer la LED L0
    //for(i=0; i<1000000 ; i++){
      
    //}
    //GPIOB->ODR &=~ (1<<1);// �teind la LED L0
    
    // Allume LED1
    //GPIOB->ODR |= (1<<2); //allumer la LED L1
    //for(i=0; i<1000000 ; i++){
      
    //}
    //GPIOB->ODR &=~ (1<<2);// �teind la LED L1

    // Allume LED2
    //GPIOB->ODR |= (1<<10); //allumer la LED L2
    //for(i=0; i<1000000 ; i++){
      
    //}
    //GPIOB->ODR &=~ (1<<10);// �teind la LED L2
    //Alume LED 3
    //GPIOB->ODR |= (1<<11); //allumer la LED L3
    //for(i=0; i<1000000 ; i++){
      
    //}
    //GPIOB->ODR &=~ (1<<11);// �teind la LED L3
    
    // Allume LED4
    //GPIOB->ODR |= (1<<12); //allumer la LED L4
    //for(i=0; i<1000000 ; i++){
      
    //}
    //GPIOB->ODR &=~ (1<<12);// �teind la LED L4
    //
    // Allume LED5
    //GPIOB->ODR |= (1<<13); //allumer la LED L5
    //for(i=0; i<1000000 ; i++){
      
    //}
    //GPIOB->ODR &=~ (1<<13);// �teind la LED L5

    // Allume LED6
    //GPIOB->ODR |= (1<<14); //allumer la LED L6
    //for(i=0; i<1000000 ; i++){
      
    //}
    //GPIOB->ODR &=~ (1<<14);// �teind la LED L6
    // Alume LED7
    //GPIOB->ODR |= (1<<15); //allumer la LED L7
    //for(i=0; i<1000000 ; i++){
      
    //}
    //GPIOB->ODR &=~ (1<<15);// �teind la LED L7
 
 //////////////////////////////////////////////// Meme code qu'avant met plus optimiser
  
    GPIOB->ODR |=(1<<1);//led1
    wait_t();
    GPIOB->ODR |=(1<<2);//led2
    wait_t();    
    for(j=10;j<16;j++){//led 3 a 8
      GPIOB->ODR |=(1<<j);
      wait_t();
    }
    //___________________On �teind les LED 
    GPIOB->ODR &=~(1<<1); //led 1
    wait_t();
    GPIOB->ODR &=~(1<<2);//led 2
    wait_t();
    for(j=10;j<16;j++){  //led 3 a 8
      GPIOB->ODR &=~(1<<j);
      wait_t();
    }
  
 }
}