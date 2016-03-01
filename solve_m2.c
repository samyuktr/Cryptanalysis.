#include "hw3.h"

struct list1
{
	char alpha;
	double freq;
	double per;
	double numer;
};

struct list1 l1[26];
double total_num;




void solve1(char * filename, int t_max) // 2nd method
{
	FILE * fp = fopen(filename, "rb");
	if(!fp)
	{
		fprintf(stderr, "Error opening file\n");
		exit(0);
	}

	int t;
	int a, b=97;
	 for(a = 0; a < 26; a++)
	 {
	     l1[a].alpha = b;
	     b++;   
	 }
//================================================================================================
	char hist[26];
	int j;
	for(j=0;j<26;j++)
	{
		hist[j] = 0;
	}


	while(!feof(fp))
	{

		char c = fgetc(fp);
		if(c>='a'&& c<='z')
		{	

			int pos = get_pos(c);
			l1[pos].freq++;
		}
		

	}
//====================================================================================================
	int sum=0;


	for(j=0;j<26;j++)
	{
		sum = sum + l1[j].freq;
	}
	printf("L=%d\n", (int)sum);
//=====================================================================================================

	//int k;
	int n=26;
    for(a=0;a<26;a++)
    {
    	l1[a].numer = l1[a].freq * (l1[a].freq-1);
    }
    for (a=0;a<26;a++)
    {
    	total_num = total_num + l1[a].numer;
    }


	for(a=0;a<26;a++)
	{
		l1[a].per = ((double)l1[a].freq/(double)sum)*100;
		printf("f('%c')=%d\n", l1[a].alpha, (int)l1[a].freq);
	}
	printf("IC=%.8g\n", total_num/(sum*(sum-1)));

//======================================================================================================
	double kp = 0.0658;
	double kr = 1/(double)n;
	for(t=1;t<=t_max;t++)
	{
		double sum1 = (double)sum;
		double t1 = (double)t;
		double p1 = (1/t1) * (sum1-t1)/(sum1-1) * kp ;
		double p2 =  (double)((t1-1)/t1) * (double)(sum1 / (double)(sum1-1)) * kr ;
		double value = p1+p2;
		printf("t=%d, E(IC)=%.8g\n", t, value);
	}
} // end of solve1()

void solve2(char * filename, int t_max) // 3rd method
{



	FILE * fp1 = fopen(filename, "rb");
	FILE * fp2 = fopen(filename, "rb");
	FILE * fp = fopen( filename, "rb");
	if(!fp)
	{
		fprintf(stderr, "Error opening file\n");
		exit(0);
	}
	
	int a, b=97;

	 for(a = 0; a < 26; a++) // populating the structure. 
	 {
	     l1[a].alpha = b;
	     b++;   
	 }
//=====================================================================================
	char hist[26];
	int j;
	for(j=0;j<26;j++)
	{
		hist[j] = 0;
	}
	
//=====================================================================================

	while(!feof(fp))
	{

		char c = fgetc(fp);
		if(c>='a'&& c<='z')
		{	

			int pos = get_pos(c); // calculating frequency for all valid characters. 
			l1[pos].freq++;
		}
		

	}
//=======================================================================================
	int sum=0;


	for(j=0;j<26;j++)
	{
		sum = sum + l1[j].freq;
	}
	int count=0;;
	int i;
	int t;
	
	fseek(fp1, 0L, SEEK_END);
	int x = ftell(fp1); // number of characters in the file. 

//==========================================================================================
	printf("\nAuto-correlation Method\n");
	printf("=======================\n");
	char * str = calloc(x, sizeof(char));
	fread(str, 1, x, fp2); // read entire file into str

	t=1;
	for(t=1;t<=t_max;t++)
	{
		for(i=0; i<=x-t; i++)
		{
			if(str[i]>='a'&& str[i]<='z')
			{
				if(str[i]==str[i+t])
				{
					count = count+1;
				}
			}

			
		}
		printf("t=%d, count=%d\n", t,  count);
		count = 0;
	}
	
} // end of solve2()


void solve(char * filename)
{
	FILE * fp1 = fopen(filename, "rb");
	FILE * fp2 = fopen(filename, "rb");
		if(!fp1)
	{
		fprintf(stderr, "Error opening file\n");
		exit(0);
	}

	fseek(fp1, 0L, SEEK_END);
	int x = ftell(fp1);  // numner of characters in the given file. 
	char * str = calloc(x, sizeof(char));
	fread(str, 1, x, fp2); // read all characters from the file. 
 
	int init_len = 4;
	printf("Kasiski Method\n");
	printf("==============\n");
	while(1)
	{
		int i, j, k, cmp;
		char * str1 = calloc(sizeof(char), init_len);
		char * str2 = calloc(sizeof(char), init_len);
		int match = 0;
		for(i=0; i<x-init_len; i++)
		{
			int correct = 1;
			strncpy(str1, &str[i], init_len);

			for(cmp=0;cmp<init_len;cmp++)
			{
				if(str1[cmp]<'a' || str1[cmp]>'z')
				{
					correct = 0;
				}
				
			
			}

			if(correct ==1)
			{
				for(j=i+1; j<x-init_len; j++)
				{
					strncpy(str2, &str[j], init_len);
					if(strncmp(str1, str2, init_len)==0)
					{
						match = 1;
						fprintf(stdout, "len=%d, i=%d, j=%d, j-i=%d, %s\n", init_len, i, j, (j-i), str1);

					}

					for(k=0;k<init_len;k++)
					{
						str2[k] = '\0';
					}

				} // end of jth loop

			}
			for(k=0;k<init_len;k++)
			{
				str1[k] = '\0';
			}

		}
		if(match==1)
		{
			init_len++;
		}
		else if(match ==0)
		{
			printf("len=%d, no more matches\n\n", init_len);
			break;
		}
	}

	
}

