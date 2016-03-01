#include "hw3.h"

/*
Samyukta Satish Rao
University of Southern California
*/

struct list
{
	char alpha;
	double freq;
	double per;
};

struct list l[26];

//============================= calculates histogram for the cipher text according to the given value of period and i==========================


void histo(int t, int which, FILE * fp)
{
	int a, b=97;
	 for(a = 0; a < 26; a++)
	 {
	     l[a].alpha = b;
	     b++;   
	 }

	char p = '%';
	which = which-1;
	char hist[26];
	int j;
	for(j=0;j<26;j++)
	{
		hist[j] = 0;
	}
	
	char * c = calloc(t, sizeof(char));


	while(!feof(fp))
	{

		int n = fread(c, 1, t, fp);
		if(n==0)
			break;
		if(c[which]>='a'&& c[which]<='z')
		{	

			int pos = get_pos(c[which]);
			l[pos].freq++;
		}
		

	}

	int sum=0;


	for(j=0;j<26;j++)
	{
		sum = sum + l[j].freq;
	}
	printf("L=%d\n", (int)sum);


	int k;
	int n=26;
	for(j=1;j<n;j++)
    {
        for(k=0;k<n-j;k++)
        {
            if(l[k].freq < l[k+1].freq)
            {
                struct list temp = l[k];
                l[k] =l[k+1];
                l[k+1] = temp;
            }
        }
    }

	for(a=0;a<26;a++)
	{
		l[a].per = ((double)l[a].freq/(double)sum)*100;
		printf("%c: %d (%2.2lf%c)\n", l[a].alpha, (int)l[a].freq, l[a].per , p);
	}

}

//============================================================= end of histogram ===============================================================
