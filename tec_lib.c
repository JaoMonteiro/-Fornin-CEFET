#include "msp430.h"

void config_teclado() //configurar GPIO 

{ 
  P2DIR=0xF8;   // Configura os bits P2.3 a P2.0 como entradas
  P3DIR|=0xCF;  // Configura os bits P3.0 a P3.3 como saídas
  P3OUT|=0x0F;  // Aciona os bits ligados ao teclado já que detectam bordas de subida
  P2IE=0x07;    // Configura os bits P2.3 a P2.0 como interrupçoes
  P2IES=0x07;   // Configura os bits de entrada P2.3 a P2.0 como borda de subida
  P2IFG=0;      // Zera o flag da porta 2 para previnir inicialização errada dos registradores
}


unsigned char rd_tec() //identificar tecla e gerar código ASCII

{ unsigned char L;
  P3OUT=0x01;          
  L='n';
  switch (P2IN&0x07)    // Checa a 1a linha do teclado
  { 
    case BIT0 :
      L='3';break;      
    case BIT1 :
      L='2';break;
    case BIT2 :
      L='1';break;
    default:
       break;
}
 P3OUT=0x02;           
 switch (P2IN&0x07)    // Checa a 2a linha do teclado
 { 
    case BIT0:
      L='6';break;  
    case BIT1:
      L='5';break;
    case BIT2:
      L='4';break;
    default:
      break;    
 }
 P3OUT=0x04;
 switch (P2IN&0x07) // Checa a 3a linha do teclado
 { 
    case BIT0:
      L='9';break;  
    case BIT1:
      L='8';break;
    case BIT2:
      L='7';break;
    default:
      break;
 }
 P3OUT=0x08;
 switch (P2IN&0x07) // Checa a 4a linha do teclado
  { 
    case BIT0 :
      L='E';break;  
    case BIT1:
      L='0';break;
    case BIT2:
      L='A';break;
    default:
      break;
  }
 return(L);
}

