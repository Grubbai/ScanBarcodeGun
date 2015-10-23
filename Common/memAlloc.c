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

#include "memAlloc.h"


enum bufSize_t{
	SMALL_BUFFER_SIZE = 16,
	MEDIUM_BUFFER_SIZE = 70,
	LARGE_BUFFER_SIZE = 160,
};

static _declare_box(mpool1,SMALL_BUFFER_SIZE,16);/* Reserve a memory for 8 blocks of SMALL_BUFFER_SIZE-bytes. */
static _declare_box(mpool2,MEDIUM_BUFFER_SIZE,12);/* Reserve a memory for 8 blocks of MEDIUM_BUFFER_SIZE-bytes. */
static _declare_box(mpool3,LARGE_BUFFER_SIZE,6);/* Reserve a memory for 8 blocks of LARGE_BUFFER_SIZE-bytes. */
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
void memInit(void)
{
	_init_box (mpool1, sizeof (mpool1),SMALL_BUFFER_SIZE );
	_init_box (mpool2, sizeof (mpool2),MEDIUM_BUFFER_SIZE );
	_init_box (mpool3, sizeof (mpool3),LARGE_BUFFER_SIZE );
}
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
// getmemory(A) ��ʵ����A�ĳ����뼸������ȥ�Ƚ�Ȼ���������ֵ
void* getMemory(U16 requestedSize) 
{ 
    if ( requestedSize <= SMALL_BUFFER_SIZE ){
		return _alloc_box (mpool1);
	}
    else if ( requestedSize <= MEDIUM_BUFFER_SIZE ){
		return _alloc_box (mpool2);
	}
    else if ( requestedSize <= LARGE_BUFFER_SIZE ){
		return _alloc_box (mpool3);
	}else{
		return 0;
	}
}
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
void freeMemory(void *p) 
{
	if(p >= mpool3)
		_free_box (mpool3,p);
	else if(p >= mpool2)
		_free_box (mpool2,p);
	else
		_free_box (mpool1,p);
}
