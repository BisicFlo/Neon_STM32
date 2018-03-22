/**
  ******************************************************************************
  * @file    Project/STM32L1xx_StdPeriph_Templates/stm32l1xx_it.c 
  * @author  MCD Application Team
  * @version V1.2.0
  * @date    16-May-2014
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32l1xx_it.h"
//#include "USART1_functions.h"
    extern uint8_t etat;
extern uint8_t valeur;
extern float moyenne;
extern float testf;
extern uint32_t compteur;
extern char data;
    extern uint8_t var;
    extern uint8_t cpt;

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
    
  //extern uint8_t etat;
  //extern uint8_t etat1;
  //extern uint8_t etat2;
    //extern uint8_t var;
    //extern uint8_t cpt;
//extern uint8_t etat;
//extern uint32_t valeur;

//int i=0;
/* Private function prototypes -----------------------------------------------*/
    
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
    
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32L1xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32l1xx_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/
/*
#define taille 6

int TAB[taille];
uint32_t total;
uint32_t somme;

void TIM2_IRQHandler(void) //Filtre
{   
    TIM2->SR &= ~(1<<0);
    
    //Lancement de la conversion(SWSTART à 1)
    ADC1->CR2 |= ADC_CR2_SWSTART; 
  
    //Si la conversion est terminée
    while((ADC1->SR & (1<<1)) != ADC_SR_EOC);
    
    //Lecture de la valeur convertie en Numérique
    valeur = ADC1->DR;
    
    if(i<taille){
      //Envoi de la valeur numérique vers le DAC
      DAC->DHR12R1 = valeur;
      
      //MAJ du Buffer
      TAB[i%taille] = valeur;
    }
    else{
      //Envoi de la valeur numérique vers le DAC
      
      somme = coeffs[0] 
            + coeffs[1] 
            + coeffs[2] 
            + coeffs[3] 
            + coeffs[4] 
            + coeffs[5]; 
      total = (coeffs[0]*TAB[5]
            + coeffs[1]*TAB[4]
            + coeffs[2]*TAB[3]
            + coeffs[3]*TAB[2]
            + coeffs[4]*TAB[1]
            + coeffs[5]*TAB[0])/somme;
      
      DAC->DHR12R1 = total;
      
      //MAJ du Buffer
      int j=0;
      for(j=0; j<taille-1; j++){
        TAB[j] = TAB[j+1];
        j++;
      }
      TAB[taille-1]=valeur;
      j=0;
    }
    i++;
}
*/
char temp;
void TIM2_IRQHandler(void)
{
 /* TIM2->SR &= ~(1<<0);
  
     //On éteint une LED en conséquence
     temp = (GPIOB->ODR & ~(1<<1)); 
     temp |= (~(GPIOB->ODR & (1<<1))&(1<<1));
   GPIOB->ODR = temp; //(1<<1);
       
    //Lancement de la conversion(SWSTART à 1)
    ADC1->CR2 |= (1<<30); 

    //Si la conversion est terminée
    while((ADC1->SR & (1<<1)) != ADC_SR_EOC);
//    printf("1");
    //Lecture de la valeur convertie
    valeur = ADC1->DR; 
    if (valeur>5) // parce qu'on ne met qu'une diode, donc une seule partie de l'onde
    {
      compteur++;
      if (compteur++==0){
        testf=0;}
      
      testf = (float)valeur/(float)compteur;
      moyenne = moyenne*(float)(compteur-1)/(float)compteur+(float)valeur/(float)compteur;
    }
    
 /*     USART1->DR=valeur;
  
  USART1->CR1|= USART_CR1_TE;
  
  while ((USART1->SR & USART_SR_TC) == 0x00);
  
  USART1->SR;
  
  USART1->CR1|= USART_CR1_RE;*/
  
}
  char *trame1;
    char *trame2;
      char *trame3;
extern    char taille[3];
    char donnee[10];
int sizeb;      
void TIM3_IRQHandler(void)
{
  /*   TIM3->SR &= ~(1<<0);
           //On change l'état de la LED la LED sur PB2 en conséquence
     temp = (GPIOB->ODR & ~(1<<2)); 
     temp |= (~(GPIOB->ODR & (1<<2))&(1<<2));
     GPIOB->ODR = temp; //(1<<1);
   /*  sprintf(donnee,"%f",moyenne);
     TX_STRING(donnee);
     TX_STRING("\r\n");
       moyenne = 0;
  compteur = 0;
  wait();
  
  trame1 = "GET /dbhistorique/index.php?conso=";
  sprintf(donnee,"%f",moyenne);
  moyenne = 0;
  compteur = 0;
  sizeb=strlen(donnee);
  trame3 = " HTTP/1.1\r\nHost: 192.168.4.2:80\r\n\r\n\r\n   ";
  sprintf(taille,"%d",strlen(trame1)+strlen(donnee)+strlen(trame3)-3);
    TX_STRING("AT+CIPSEND=");
    TX_STRING(taille);
    TX_STRING("\r\n");

    wait();

         TX_STRING(trame1);
         TX_STRING(donnee);
         TX_STRING(trame3);
     
TX_STRING("AT+CIPCLOSE\r\n");*/
}
  
 /* 
       TX_STRING("AT+CIPSTART=\"TCP\",\"192.168.4.2\",80\r\n");
wait();
wait();

       TX_STRING("AT+CIPSEND=70\r\n");
       wait();
wait();
       TX_STRING("GET /dbhistorique/index.php?conso=5 HTTP/1.1\r\nHost: 192.168.4.2:80\r\n\r\n\r\n");
wait();
wait();
wait();
wait();


    //Lancement de la conversion(SWSTART à 1)
   // ADC1->CR2 |= (1<<30); 
    
    //Si la conversion est terminée
   // while((ADC1->SR & (1<<1)) != ADC_SR_EOC);
    //Lecture de la valeur convertie
  //  valeur = ADC1->DR; 

}
 /*
#define taille 10000
int TAB[taille];

void TIM2_IRQHandler(void) //Echo
{
    TIM2->SR &= ~(1<<0);
    
    //Lancement de la conversion(SWSTART à 1)
    ADC1->CR2 |= ADC_CR2_SWSTART; 
  
    //Si la conversion est terminée
    while((ADC1->SR & (1<<1)) != ADC_SR_EOC);
    
    //Lecture de la valeur convertie en Numérique
    valeur = ADC1->DR;
    
    if(i<taille){
    //Envoi de la valeur numérique vers le DAC
    DAC->DHR12R1 = valeur;
    }
    else{
    //Envoi de la valeur numérique vers le DAC
    DAC->DHR12R1 = (valeur + TAB[i%taille])/2;
    }
    
    //MAJ du buffer
    TAB[i%taille] = (valeur + TAB[i%taille])/2;
    i++;
}*/

/*
#define taille 10000
int TAB[taille];

void TIM2_IRQHandler(void) //Doubleur
{
    TIM2->SR &= ~(1<<0);
    
    //Lancement de la conversion(SWSTART à 1)
    ADC1->CR2 |= ADC_CR2_SWSTART; 
  
    //Si la conversion est terminée
    while((ADC1->SR & (1<<1)) != ADC_SR_EOC);
    
    //Lecture de la valeur convertie en Numérique
    valeur = ADC1->DR;
    
    if(i<taille){
    //Envoi de la valeur numérique vers le DAC
    DAC->DHR12R1 = valeur;
    }
    else{
    //Envoi de la valeur numérique vers le DAC
    DAC->DHR12R1 = (valeur + TAB[i%taille])/2;
    }
    
    //MAJ du buffer
    TAB[i%taille] = valeur;
    i++;
}
*/

/*
void TIM2_IRQHandler(void) //DAC 2.0
{
    TIM2->SR &= ~(1<<0);
    
    //Lancement de la conversion(SWSTART à 1)
    ADC1->CR2 |= (1<<30); 
  
    //Si la conversion est terminée
    while((ADC1->SR & (1<<1)) != ADC_SR_EOC);
    
    //Lecture de la valeur convertie en Numérique
    valeur = ADC1->DR;
    
    
    
    DAC->DHR12R1 = valeur;
}
*/

/*
void TIM2_IRQHandler(void) //DAC
{
    TIM2->SR &= ~(1<<0);
    
    valeur = coeffs[i];
    
    DAC->DHR12R1 = valeur;
    
    if(i==Lut_size+1){
      i=0;
    }
    else{
      i++;
    }
}
*/
/*
void TIM2_IRQHandler(void) //ADC
{
    TIM2->SR &= ~(1<<0);
    
    //Lancement de la conversion(SWSTART à 1)
    ADC1->CR2 |= (1<<30); 
  
    //Si la conversion est terminée
    while((ADC1->SR & (1<<1)) != ADC_SR_EOC);
    
    //Lecture de la valeur convertie
    valeur = ADC1->DR;
}

void TIM2_IRQHandler(void) //LEDS
{
     if(((TIM2->SR & (1<<0))!=0)&&(etat==1)){
      GPIOB->ODR &= ~((1<<1)|(1<<2)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14)|(1<<15));
      GPIOB->ODR |= (1<<1);
      etat=2;
      TIM2->SR &= ~(1<<0);
     }
     else if(((TIM2->SR & (1<<0))!=0)&&(etat==2)){
      GPIOB->ODR &= ~((1<<1)|(1<<2)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14)|(1<<15));
      GPIOB->ODR |= (1<<2);
      etat=10;
      TIM2->SR &= ~(1<<0);
     }
     else if(((TIM2->SR & (1<<0))!=0)&&(etat==10)){
      GPIOB->ODR &= ~((1<<1)|(1<<2)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14)|(1<<15));
      GPIOB->ODR |= (1<<10);
      etat=11;
      TIM2->SR &= ~(1<<0);
     }
     else if(((TIM2->SR & (1<<0))!=0)&&(etat==11)){
      GPIOB->ODR &= ~((1<<1)|(1<<2)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14)|(1<<15));
      GPIOB->ODR |= (1<<11);
      etat=12;
      TIM2->SR &= ~(1<<0);
     }
     else if(((TIM2->SR & (1<<0))!=0)&&(etat==12)){
      GPIOB->ODR &= ~((1<<1)|(1<<2)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14)|(1<<15));
      GPIOB->ODR |= (1<<12);
      etat=13;
      TIM2->SR &= ~(1<<0);
     }
     else if(((TIM2->SR & (1<<0))!=0)&&(etat==13)){
      GPIOB->ODR &= ~((1<<1)|(1<<2)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14)|(1<<15));
      GPIOB->ODR |= (1<<13);
      etat=14;
      TIM2->SR &= ~(1<<0);
     }
     else if(((TIM2->SR & (1<<0))!=0)&&(etat==14)){
      GPIOB->ODR &= ~((1<<1)|(1<<2)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14)|(1<<15));
      GPIOB->ODR |= (1<<14);
      etat=15;
      TIM2->SR &= ~(1<<0);
     }
     else if(((TIM2->SR & (1<<0))!=0)&&(etat==15)){
      GPIOB->ODR &= ~((1<<1)|(1<<2)|(1<<10)|(1<<11)|(1<<12)|(1<<13)|(1<<14)|(1<<15));;
      GPIOB->ODR |= (1<<15);
      etat=1;
      TIM2->SR &= ~(1<<0);
     }
}
*/

/*
void EXTI2_IRQHandler(void)
{

} 
*/
/*
void EXTI9_5_IRQHandler(void)
{
  if(((EXTI->PR & (1<<6))!=0)&&(etat==0)){
      GPIOB->ODR &= ~(1<<2)&~(1<<14)&~(1<<15);
      GPIOB->ODR |= (1<<2);
      etat=1;
      EXTI->PR |= (1<<6);
    }
    else if(((EXTI->PR & (1<<6))!=0)&&(etat==1)){
      GPIOB->ODR &= ~(1<<2)&~(1<<14)&~(1<<15);
      GPIOB->ODR |= (1<<14);
      etat=2;
      EXTI->PR |= (1<<6);
    }else if(((EXTI->PR & (1<<6))!=0)&&(etat==2)){
      GPIOB->ODR &= ~(1<<2)&~(1<<14)&~(1<<15);
      GPIOB->ODR |= (1<<15);
      etat=0;
      EXTI->PR |= (1<<6);
    }
}
*/
/*
void EXTI15_10_IRQHandler(void)
{
 
}    
*/
/*
void USART2_IRQHandler(void){
  
}

//On déclare notre variable.  
char dataUSART; 
/*  Donnee représente la donnée qui a été envoyée par le module de communication. 
On part de l'hypothèse que le module de communication envoie toujours 3 Bytes. S'il envoie plus, alors il faudra changer dans le IRQHandler pour que
 l'enregistrement s'arrète quand on a reçu les caractères de "stop" (\r\n par exemple)*/
int j = 0;

/*void USART1_IRQHandler(void){

  while((USART1->SR & USART_SR_RXNE) == 0 );

  
    dataUSART = USART1->DR;
  USART1->DR=dataUSART;
  
  USART1->CR1|= USART_CR1_TE;
  
  while ((USART1->SR & USART_SR_TC) == 0x00);
  
  USART1->SR;
  
  USART1->CR1|= USART_CR1_RE;
  
 
}*/





/**
  * @}
  */ 


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
