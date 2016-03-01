#include "hw3.h"

/*
Samyukta Satish Rao
University of Southern California
*/

char alpha[26] = "abcdefghijklmnopqrstuvwxyz";

//========================================= returns character at a particular position ==============================================
char get_char(int pos)
{
	return alpha[pos];
}

//============================  generates inverse key using the *.keys file =========================================================
void invkey(FILE * fp1, FILE * fp2)
{
	char * key= (char *)calloc(26, sizeof(char));
	char * invkey= (char *)calloc(26, sizeof(char));
	int lines=0;
	int i, j;

	char ch;

// while loop to find out the period. 
	while(!feof(fp1))
	{
	  ch = fgetc(fp1);
	  if(ch == '\n')
	  {
	    lines++;
	  }
	}


	for(i=0;i<lines;i++)
	{
		fread(key, 1, 27, fp2);
		for(j=0;j<26;j++)
		{
			char alp = get_char(j);

			int pos = (int)key[j]-97;


			invkey[pos] = alp;

		}
		printf("%s\n", invkey);

	}


}

//====================================================== end of inverse key =========================================================


