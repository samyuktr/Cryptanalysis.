#include "hw3.h"

/* Function to find the array position of a character*/
int get_pos(char find)  
{

  	int index=99;
	char alpha [26] = "abcdefghijklmnopqrstuvwxyz";
	const char *ptr = strchr(alpha, find);
	if(ptr) 
	{
	   index = ptr - alpha;

	}
	return index;

}



// Function used for crypt and decrypt functions. 

void crypt(FILE * fp1, FILE * fp2, FILE * fp)
{
	
	char ch;
	int i;
	int lines=0;
	
	while(!feof(fp1))
	{
	  ch = fgetc(fp1);
	  if(ch == '\n')
	  {
	    lines++;
	  }
	}

	char * key[lines];


	for(i=0;i<lines;i++)
	{
		key[i] = (char *)calloc(26, sizeof(char));
	}
	for(i=0;i<lines;i++)
	{
		fread(key[i], 1, 27, fp2);
	}
	int num=0;


	char * c = calloc(lines, sizeof(char));
	char * c_out = calloc(lines, sizeof(char));

	while(!feof(fp))

	{
		fread(c, 1, lines, fp);
		
		num++;
		for(i=0;i<lines; i++)
		{
			if(c[i]>='a'&& c[i]<='z')
			{
				int pos = get_pos(c[i]);
				c_out[i] = key[i][pos];

			}
			else
			{
				c_out[i] = c[i];

			}
			num = i;
			if(c_out[i]==NULL)
				break;
			else
				putc(c_out[i], stdout);
		}


		for(i=0;i<lines;i++)
		{
			c_out[i] = '\0';
			c[i] = '\0';
		}
		
		
	}

	

}


