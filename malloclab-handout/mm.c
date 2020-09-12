/*
 * mm-naive.c - The fastest, least memory-efficient malloc package.
 * 
 * In this naive approach, a block is allocated by simply incrementing
 * the brk pointer.  A block is pure payload. There are no headers or
 * footers.  Blocks are never coalesced or reused. Realloc is
 * implemented directly using mm_malloc and mm_free.
 *
 * NOTE TO STUDENTS: Replace this header comment with your own header
 * comment that gives a high level description of your solution.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#include "mm.h"
#include "memlib.h"

/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
team_t team = {
    /* Team name */
    "Harimu",
    /* First member's full name */
    "Quitomos",
    /* First member's email address */
    "quitomos@buaa.edu.cn",
    /* Second member's full name (leave blank if none) */
    "",
    /* Second member's email address (leave blank if none) */
    ""
};

/* single word (4) or double word (8) alignment */
#define ALIGNMENT 8

/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~0x7)


#define SIZE_T_SIZE (ALIGN(sizeof(size_t)))

//from page 599
#define WSIZE 4     //word and header/footer size
#define DSIZE 8     //double word size
size_t CHUNKSIZE = mem_pagesize();  //extend heap by one page

#define MAX(x, y) ((x) > (y)? (x) : (y));

#define PACK(size, alloc) ((size) | alloc)  //pack a size and allocated bit into a word

#define GET(p)  (*(unsigned int*)(p))   //read a word at address p
#define PUT(p, val) (*(unsigned int*)(p) = (val))   //write a word at address p

#define GET_SIZE(p) (GET(p) & ~0x7) //read the size and allocated fields from address p
#define GET_ALLOC(p) (GET(p) & 0x1) //read allocated fields from address p

#define HDRP(bp) ((char*)(bp) - WSIZE)  //compute address of the header of a block ptr
#define FTRP(bp) ((char*)(bp) + GET_SIZE(HDRP(bp)) - DSIZE)  //compute address of the footer of a block ptr

#define NEXT_BLKP(bp) ((char*)(bp) + GET_SIZE(((char*)(bp) - WSIZE)))   //dext block ptr
#define PREV_BLKP(bp) ((char*)(bp) - GET_SIZE(((char*)(bp) - DSIZE)))   //previous block ptr


static char* begin;
static char* end;

/* 
 * mm_init - initialize the malloc package.
 */
int mm_init(void)
{
    mem_init();
    begin = (char*) mem_heap_lo();
    end = (char*) mem_heap_hi();
    return 0;
}

/* 
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void *mm_malloc(size_t size)
{
    int newsize = ALIGN(size + SIZE_T_SIZE);
    void *p = mem_sbrk(newsize);
    if (p == (void *)-1)
	return NULL;
    else {
        *(size_t *)p = size;
        return (void *)((char *)p + SIZE_T_SIZE);
    }
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *ptr)
{
}

/*
 * mm_realloc - Implemented simply in terms of mm_malloc and mm_free
 */
void *mm_realloc(void *ptr, size_t size)
{
    void *oldptr = ptr;
    void *newptr;
    size_t copySize;
    
    newptr = mm_malloc(size);
    if (newptr == NULL)
      return NULL;
    copySize = *(size_t *)((char *)oldptr - SIZE_T_SIZE);
    if (size < copySize)
      copySize = size;
    memcpy(newptr, oldptr, copySize);
    mm_free(oldptr);
    return newptr;
}













