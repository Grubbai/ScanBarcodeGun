/*
*********************************************************************************************************
****��   ��   ����				Hd_Com_Scanner.c
****��        �ߣ�				GRUB'BAI
****��        ˾��				MESNAC 
****��        ����				V0.0.1
****��        �ڣ�				2014.10.29
****IDE  ��   ����				MDK-ARM 5.11A
****STM32�� �汾��				1.3
****����ϵͳ�汾��				UC/OS 2.92
****��  Ҫ ˵ ����			 	
*********************************************************************************************************
*/

#ifndef _memAlloc_h_
#define _memAlloc_h_


//#include "includes.h"
void memInit(void);
void* getMemory(uint16_t requestedSize);
void freeMemory(void *p);

#endif
