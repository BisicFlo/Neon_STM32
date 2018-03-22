


#include "my_ADC.h"

#include "stm32l1xx.h"


void ADC_CONFIG(void)
{
   // Alimentation du périphérique ADC1 qui se trouve dans APB2
   
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
    
    
    // Activation de l'horloge HSI
    
    RCC->CR |= RCC_CR_HSION;
    
    
    //HSI divisé par 4
    
    RCC->CRR |= ADC_CCR_ADCPRE_ 1;
    ADC->CCR &= ~ADC_CCR_ADCPRE_0;
    
    
    // 1 conversion 
    
    ADC1->SQR1 &= ~ADC_SQR1_L;
        //RI
     RI->ASCR1 &= ~RI_ASCR1_CH0/GR11;
     
     //(ADC_SQR1)
     ADC->SQR1 &= ~ADC_SQR1_L; // 1 conversion 
     ADC->SQR5 &= ~ADC_SQR5_SQ1; // 0000 : ch0
     
     // type
     
     ADC->CR1 &= ~ ADC_CR1_SCAN;
     ADC->CR2 &= ~ ADC_CR2_CONT;
     
     // activer l'ADC
     
     ADC->CR2 |= ADC_CR2_ADON;
     
     while ( (ADC-> SR & ADC_SR_ADONS) ==0); // vérification de l'activation
     

     
     
  
}


int ADC_CONFIG(void){

      ADC->CR2 |= ADC_CR2_SWSTART;
      
      while ( (ADC->SR & ADC_SR_EOC) ==0); //          --/!\-- vérification fin de conversion
      
      
      return(ADC->DR & ADC_DR_DATA );
}    

void GPIO_INIT(void)
{    
    // canal d'aquisition:
    
    //GPIO

    RCC-> AHBENR |= RCC_AHBENR_GPIOAEN;
    
    GPIOA->MODER|=GPIO_MODER_MODER0;
  
}
