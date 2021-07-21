#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode sn;
struct stackNode
{
	char 	cData;
	sn* 	pNext;
};

// global ptr
sn* pTop = NULL;

void push(char in)
{
	if(NULL == pTop)
	{
		printf("Adding first node \n");
		
		// new element in stack
		sn* pStruct = (sn*)malloc( sizeof(sn) );
		pStruct->cData = in;
		pStruct->pNext = NULL;
		
		// change value of top
		pTop = pStruct;
	}
	else
	{
		// new element in stack
		sn* pTemp = (sn*)malloc( sizeof(sn) );
		pTemp->cData = in;
		pTemp->pNext = pTop;
		
		// change value of top
		pTop = pTemp;
	}
}

void pop()
{
	if(NULL == pTop)
	{
		printf("Stack is empty \n");	
	}
	else
	{
		printf("Pop :- %c \n", pTop->cData);
		sn* pTemp = pTop;
		pTop = pTop->pNext;
		free(pTemp);
	}
}

int main()
{	
	printf(" *** Start Main *** \n");
	
	// Push 7 times
	push('N');
	push('A');
	push('M');
	push('R');
	push('A');
	push('T');
	push('A');
	
	// Pop eight times
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	
	printf(" ***  End  Main *** \n");
	return 0;
}
