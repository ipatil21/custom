#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Assuming input is null terminated string
char* removeDuplicate(char* in)
{
  char *op;
  char *ptr = (char*)malloc(strlen(in));
  op = ptr;
  
  while(*in != '\0')
  { 
	if(*in != *(in + 1))  
       	*ptr++ = *in++;
	else
	   	in++;
  }

  *ptr = '\0';
  
  return op;
}

int main()
{
	char *in = "abccddrefhgh";
	char *op = removeDuplicate(in);
	
	while(*op != '\0')
		printf("%c", *op++);
		
  	return 0;
}
