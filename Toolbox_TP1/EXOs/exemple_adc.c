# include "stm32l1xx_nucleo.h"

# include "ADC.h"



/**
  * @brief      Initialisation du Convertisseur Analogique - Digital (ADC)
  *                     Initialisation pour la conversion de PA0 & PA1 (Potentiom�tre 1 & 2)
  *
  * @param      -       Aucun
  * @retval     -       Aucun
  */
void init_ADC()
{
    /**
      * @brief        Initialisation de l'horloge de l'ADC
      * @section      HSI Init
      */
    
    // Alimentation du p�riph�rique ADC1
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
    
    // Activation de l'horloge HSI
    RCC->CR |= RCC_CR_HSION;
    
    // Configuration du pr�scaler de l'horloge (HSI divis�e par 4)
    ADC->CCR |= ADC_CCR_ADCPRE_1;
    ADC->CCR &= ~ADC_CCR_ADCPRE_0;
    
    
    /**
      * @brief        Configuration de la s�quence de conversions
      * @section      S�quence Conversions
      */
    
    // D�finition du nombre de conversion (0001 -> 2 conversions)
    ADC1->SQR1 &= ~ADC_SQR1_L;
    ADC1->SQR1 |= ADC_SQR1_L_0;
    
    // Premier num�ro de s�quence � convertir (ADC_IN1)
    ADC1->SQR5 &= ~ADC_SQR5_SQ1;
    ADC1->SQR5 |= ADC_SQR5_SQ1_0;
    
    // Deuxi�me num�ro de s�quence � convertir (ADC_IN0)
    ADC1->SQR5 &= ~ADC_SQR5_SQ2;
    
    
    /**
      * @brief        Configuration des caract�ristiques de l'ADC
      * @section      ADC Init
      */
    
    // Configuration du Switch Analogique (PA0 -> ADC_IN0 -> CH0 / Groupe 1) pour le Potentiom�tre 1
    RI->ASCR1 |= RI_ASCR1_CH_0;
    
    // Configuration du Switch Analogique (PA1 -> ADC_IN1 -> CH1 / Groupe 1) pour le Potentiom�tre 2
    RI->ASCR1 |= RI_ASCR1_CH_1;
    
    // Activation du Scan (parcours les s�quences de conversions SQRx)
    ADC1->CR1 |= ADC_CR1_SCAN;
    
    // D�finition de la r�solution de conversion (8 bits)
    ADC1->CR1 |= ADC_CR1_RES_1;
    ADC1->CR1 &= ~ADC_CR1_RES_0;
    
    // Configuration de l'ADC en mode simple
    ADC1->CR2 &= ~ADC_CR2_CONT;
    
    // Selection de la Bank A pour les ADC_INx (utile seulement pour les entr�es ADC_INx_b) 
    ADC1->CR2 &= ~ADC_CR2_CFG;
    
    
    /**
      * @brief        Alimentation de l'ADC et Lancement des conversions
      * @section      Activation ADC
      */
    
    // Initialisation du flag de fin de conversion � 0
    ADC1->CR2 |= ADC_CR2_EOCS;
    
    // Activation du convertisseur (ADC)
    ADC1->CR2 |= ADC_CR2_ADON;
    
    // Attente d'activation finale du convertisseur (ADC) (D�lai d'activation)
    while ((ADC1->SR & ADC_SR_ADONS) == 0);
    
    // Lancement des conversions
    ADC1->CR2 |= ADC_CR2_SWSTART;
}