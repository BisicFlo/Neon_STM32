

/*

# include "stm32l1xx_nucleo.h"
# include "my_ADC.h"

void ADC_CONFIG(void)
{
   // Alimentation du périphérique ADC1 qui se trouve dans APB2
   
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
    
    
    // Activation de l'horloge HSI
    
    RCC->CR |= RCC_CR_HSION;
    
    
    //HSI divisé par 4
    
    ADC->CCR |= ADC_CCR_ADCPRE_1;
    ADC->CCR &= ~ADC_CCR_ADCPRE_0;
    
    
    // 1 conversion 
    
    ADC1->SQR1 &= ~ADC_SQR1_L;
        //RI
     RI->ASCR1 &= ~RI_ASCR1_CH_0;
     
     //(ADC_SQR1)
     ADC1->SQR1 &= ~ADC_SQR1_L; // 1 conversion 
     ADC1->SQR5 &= ~ADC_SQR5_SQ1; // 0000 : ch0
     
     // type
     
     ADC1->CR1 &= ~ ADC_CR1_SCAN;  //scan off
     ADC1->CR2 &= ~ ADC_CR2_CONT; //mode simple
     
     // activer l'ADC
     
     ADC1->CR2 |= ADC_CR2_ADON;
     
     while ( (ADC1-> SR & ADC_SR_ADONS) ==0); // vérification de l'activation
     

     
     
  
}


int ADC_conv(void){

      ADC1->CR2 |= ADC_CR2_SWSTART;
      
      while ( (ADC1->SR & ADC_SR_EOC) ==0); //          --/!\-- vérification fin de conversion
      
      
      return(ADC1->DR & ADC_DR_DATA );
}    

void GPIO_INIT(void)
{    
    // canal d'aquisition:
    
    //GPIO

    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    
    GPIOA->MODER |= GPIO_MODER_MODER0;
  
}


void init_timer (uint32_t delay_us){
  
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
  
  TIM2->CR1 &= ~ TIM_CR1_DIR;
  
    TIM2->CR1 &= ~ TIM_CR1_CMS;

  
  TIM2->ARR = delay_us -1;
  
  TIM2->PSC =  15;
  
  
  //Trigger interrupt enable
  
  TIM2->DIER |= TIM_DIER_TIE;
 
  //6
  TIM2->CR1 |= TIM_CR1_CEN;
  
}

void init_interrupt_timer(void){
  
   TIM2->DIER |= TIM_DIER_UIE;
   
  
  
  NVIC->ISER[0] |= NVIC_ISER_SETENA_28 ; // inter n°28 se trouve dans ISER[0]
  
}

void GPIOA_INIT(void)
{
  //activer horloge 
  RCC -> AHBENR |= RCC_AHBENR_GPIOAEN ;
  
  // mode
  GPIOA -> MODER |= GPIO_MODER_MODER4;
  
   GPIOA -> MODER |= GPIO_MODER_MODER0;
  
  
}


void init_DAC(void){

  /*  //GPIO
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  
    GPIOA -> MODER |= GPIO_MODER_MODER0;
    
    GPIOA -> MODER |= GPIO_MODER_MODER4;
    
  */
    /*
    
  RCC->APB1ENR |= RCC_APB1ENR_DACEN;// activer horloge
    
   /* DAC -> DHR12R1 */
/*
   DAC -> CR |= DAC_CR_EN1; // activer la voie 1
   DAC -> CR |=  DAC_CR_BOFF1 ; // activer le buffer
    
    
  
}

*/