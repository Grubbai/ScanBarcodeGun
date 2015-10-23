/*
*********************************************************************************************************
****文   件   名：				Hd_Com_Scanner.c
****作        者：				GRUB'BAI
****公        司：				MESNAC 
****版        本：				V0.0.1
****日        期：				2014.10.29
****IDE  版   本：				MDK-ARM 5.11A
****STM32库 版本：				1.3
****操作系统版本：				UC/OS 2.92
****简  要 说 明：			 	
*********************************************************************************************************
*/

#ifndef _memAlloc_h_
#define _memAlloc_h_


//#include "includes.h"
void memInit(void);
void* getMemory(uint16_t requestedSize);
void freeMemory(void *p);

#endif
