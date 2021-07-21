// Input = "aabssdddeehff"
// Output = "aa2b1ss2ddd3ee2h1ff2"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* formatString(char* in)
{
	char* temp = (char*)malloc(strlen(in)*2);
	char* op;
	op = temp;
	
	char iTimes = 1;
	while(*in != '\0')
	{
		if(*in == *(in + 1))
		{
			*temp++ = *in++;
			iTimes++;
		}
		else
		{
			*temp++ = *in++;
			*temp++ = iTimes;
			
			iTimes = 1;
		}
	}
	
	*temp = '\0';
	return op;
}

int main()
{
	char *in = "aaaaaaaaaaaabssdddeehff";
	char *op = formatString(in);
	
	while(*op != '\0')
	{
		if(0 != isalpha(*op))
			printf("%c", *op);
		else
			printf("%d", *op);	
			
		op++;
	}
	
	return 0;
}
