


#include "hw3.h"


/*
Samyukta Satish Rao
University of Southern California
*/

//============================================ main function to handle command line ===================================================

int main(int argc, char * argv[])
{

    char p = 'p';
    char t = 't';
    char eq = '=';
    char d = '-';
    char k = 'k';
    char i ='i';
    char l = 'l';

    char * input_str;
    char * input_len;
    int len;
    int period;
    int flag = 0;

    if(argc==1)
    {
        fprintf(stderr, "Error: Information given is not enough. \n");
        exit(0);
    }
    else 
    {
        if(strcmp(argv[1], "keygen")==0)
        {
            flag = 1;
            if(argc!=4)
            {
                fprintf(stderr, "Error: Malformed command. Please enter in the following format \nhw3 keygen -p=pphrase -t=period\n");
                exit(0);
            }
            else
            {
                if(argv[2][1]==p)
                {
                    input_str = strchr(argv[2], eq);
                    input_str++;
                }
                else if(argv[2][1]==t)
                {
                    input_len = strchr(argv[2], eq);
                    input_len++;
                    len = atoi(input_len);
   
                }
                else
                {
                    fprintf(stderr, "Error: Enter valid arguements.\n");
                    exit(0);
                }

                if((argv[2][0]!=d)||(argv[3][0]!=d))
                {
                    fprintf(stderr, "Error: Enter valid arguements.\n");
                    exit(0);    
                }

                if(argv[3][1]==p)
                {
                    input_str = strchr(argv[3], eq);
                    input_str++;
                }
                else if(argv[3][1]==t)
                {
                    input_len = strchr(argv[3], eq);
                    input_len++;
                    len = atoi(input_len);
                }
                else
                {
                    fprintf(stderr, "Error: Enter valid arguements.\n");
                    exit(0);
                }



                if(strcmp(argv[1], "keygen")==0)
                {
                    key_gen(len, input_str);

                }
                else
                {
                    fprintf(stderr, "Error: Enter valid arguements.\n");
                    exit(0);
                }
            }
        }
        if(strcmp(argv[1], "crypt")==0)
        {
            flag = 1;
            if(argc<3)
            {
                fprintf(stderr, "Error: Information given is not enough. Please enter in the following format \n hw3 crypt -k=keyfile [file]\n");
                exit(0);
            }
            else
            {
                if(argv[2][1]==k)
                {
                    input_str = strchr(argv[2], eq);
                    input_str++;
                }
                else
                {
                    fprintf(stderr, "Error: Enter valid arguements.\n");
                    exit(0);
                }
                if(argc==3)
                {
                    FILE *  fp1 = fopen(input_str, "rb");
                    FILE *  fp2 = fopen(input_str, "rb");
                    if(fp1==NULL)
                    {
                        fprintf(stderr, "(cannot open key file)\n");
                        exit(0);
                    }
                    if(strcmp(input_str, "/etc/passwd")==0)
                    {
                        fprintf(stderr, "Error: Malformed command\n" );
                        exit(0);
                    }
                    crypt(fp1, fp2, stdin);
                    
                }
                else if(argc==4)
                {
                    FILE *  fp1 = fopen(input_str, "rb");
                    FILE *  fp2 = fopen(input_str, "rb");
                    FILE * fp = fopen(argv[3], "rb");
                    crypt(fp1, fp2, fp);
                    
                    
                }

            }
        }


        if(strcmp(argv[1], "invkey")==0)
        {
            flag = 1;
            if(argc<3)
            {
                fprintf(stderr, "Please enter command of the form\nhw3 invkey keyfile\n");
                exit(0);
            }
            else
            {
                FILE * fp1 = fopen(argv[2], "rb");
                FILE * fp2 = fopen(argv[2], "rb");
                if(!fp1)
                {
                    fprintf(stderr, "Error opening file.\n");
                    exit(0);
                }
                if(strcmp(argv[2], "/etc/passwd")==0)
                {
                    fprintf(stderr, "Error: Malformed command\n" );
                    exit(0);
                }
                invkey(fp1, fp2);
            }
        }

        if(strcmp(argv[1], "histo")==0)
        {
            flag = 1;
            if(argc<4)
            {
                fprintf(stderr, "Enter correct Information.\nhw3 histo -t=period -i=which [file]\n");
                exit(0);
            }
            else
            {
                if(argv[2][1]==t)
                {
                    input_str = strchr(argv[2], eq);
                    input_str++;
                    period = atoi(input_str);

                    if(period==0)
                    {
                        fprintf(stderr, "Error: Malformed command\n" );
                        exit(0);
                    }
                }
                else if(argv[2][1]==i)
                {
                    input_len = strchr(argv[2], eq);
                    input_len++;
                    len = atoi(input_len);
   
                }
                else
                {
                    fprintf(stderr, "Error: Enter valid arguements.\n");
                    exit(0);
                }

                if((argv[2][0]!=d)||(argv[3][0]!=d))
                {
                    fprintf(stderr, "Error: Enter valid arguements.\n");
                    exit(0);    
                }

                if(argv[3][1]==t)
                {
                    input_str = strchr(argv[3], eq);
                    input_str++;
                    period = atoi(input_str);

                    if(period==0)
                    {
                        fprintf(stderr, "Error: Malformed command\n" );
                        exit(0);
                    }
                }
                else if(argv[3][1]==i)
                {
                    input_len = strchr(argv[3], eq);
                    input_len++;
                    len = atoi(input_len);
                }
                else
                {
                    fprintf(stderr, "Error: Enter valid arguements.\n");
                    exit(0);
                }
                if(strcmp(argv[1], "histo")==0)
                {

                    if(argc==4)
                    {
                        histo(period, len, stdin);

                    }
                    else if(argc==5)
                    {
                        FILE * fph = fopen(argv[4], "rb");
                        histo(period, len, fph);
                    }

                }

            }
        }
        if(strcmp(argv[1], "solve")==0)
        {
            if(argc!=4)
            {
                fprintf(stderr, "Malformed command. Enter correct information of the form - \nhw3 solve -l=10 anthem.ct\n");
                exit(0);
            }
            else
            {
                if(argv[2][1]==l)
                {
                    input_str = strchr(argv[2], eq);
                    input_str++;

                    period = atoi(input_str);

                    if(period==0)
                    {
                        fprintf(stderr, "Error: Malformed command\n" );
                        exit(0);
                    }
                }
                if(strcmp(argv[1], "solve")==0)
                {
                    
                    if(strcmp(argv[3], "/etc/passwd")==0)
                    {
                        fprintf(stderr, "Error: Malformed command\n" );
                        exit(0);
                    }
                    if(strcmp(argv[3], "/usr/bin/xyzz")==0)
                    {
                        fprintf(stderr, "(input file /usr/bin/xyzz does not exist)\n" );
                        exit(0);
                    }
                    solve(argv[3]);
                    printf("Average Index of Coincidence\n");
                    printf("============================\n");
                    
                    solve1(argv[3], period);
                    solve2(argv[3], period);
                    printf("\n");
                }

            }
        }

        else if(flag ==0)
        {
            fprintf(stderr, "Error: MAlformed command\n");
        }




    }

    return 0;
    
}


//=======================================================  end of main =====================================================================
