
#include "hw3.h"
/*
Samyukta Satish Rao
University of Southern California
*/

static char * md5_array;
static int i = 1;



//---------------generates md5 key for the homework---------------------------------------------------------------
char *  stream_call(int l, char * p)
{

   	char md5_buf[MD5_DIGEST_LENGTH];
    int len=strlen(p)+2+MD5_DIGEST_LENGTH;
    char *s=malloc(len+1);
    int i=0, m=0, j=0, ctr=0 ; // variables for the loop. 
    int counter = l; // counter to contain the while loop 
    unsigned char * key_str = calloc(l, sizeof(char));
    key_str[l] = '\0'; // variable to hold the key in hex format for use in encryt function.
    char * send = calloc((2*l)+1, sizeof(unsigned char));


//-----------------------------------------------------------------------------------------------------------------
    
    MD5((unsigned char *)p, (unsigned  int)strlen(p), (unsigned char *)md5_buf);


//---------------------------------------------------------------------------------------------------------------

        while(1) 
        {

            if(counter>0) // normal 8 byte genaration.
            {
                sprintf(&s[MD5_DIGEST_LENGTH], "%02d%s", i, p);
                memcpy(s, md5_buf, MD5_DIGEST_LENGTH);
                MD5((unsigned char *)s, (unsigned int)len, (unsigned char * )md5_buf);
                for(m=0;m<8;m++)
                {                      

                    key_str[j] = md5_buf[m];
                    sprintf(&send[ctr], "%02x", (unsigned int)(unsigned char)md5_buf[m]);

                    j=j+1; 
                    ctr=ctr+2;
           
                }


            }
            else
            {
                break;
            }
            counter = counter -8;


            if (++i == 100) 
                i = 0;    
            
        }

  

//------------------------------------------------------------------------------------------------------------------
    free(s);

    return send;
    
}


char * RandomInteger(int len, char * p) // returns corresponding values based on successful calls. 
{

     char * temp = (char * ) calloc(16, sizeof(char));
    if(i==1)
    {
        md5_array = stream_call(len, p);
        i++;
        strncpy(temp, md5_array, 8);
        md5_array+=8;
        return temp;
    }
    else
    {
        strncpy(temp, md5_array, 8);
        md5_array+=8;
        return temp;

    }
}

//===================================================== generates key ===================================================
void key_gen(int len, char * p)
{
    FILE * fp = fopen("keyfile.txt", "w");
    int  r=0;
    char temp;
    unsigned int l = 26;
    char * hexstring;
    long long x; 
    int i, j;
    for(j=0; j<len; j++)
    {
        char alpha [26] = "abcdefghijklmnopqrstuvwxyz";
        
        for(i=0;i<2;i++)
        {
   
            r=0, l=26, x=0;
            while(l>1)
            {
                hexstring = RandomInteger(len*2*25*4, p);
                x = strtoll(hexstring, NULL, 16);
                r = (int)(x%l);
                if(r!=(l-1))
                {
                    temp = alpha[r];
                    alpha[r] = alpha[l-1];
                    alpha[l-1] = temp;
                }


                l--;
            }

            
        }
        printf("%s\n", alpha);
        fputs(alpha, fp);
        fputc('\n', fp);


    }
    
fclose(fp);

}

//==================================================== end of keygen =====================================================
















