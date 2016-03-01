#ifndef _FUNCTION_H_  //handling multiple inclusions
#define _FUNCTION_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <openssl/md5.h>
#include <math.h>


void key_gen(int len, char * p); // function to generate keys.
char * RandomInteger(int len, char * p); // function to get md5 values for key generation
char *  stream_call(int l, char * p); // used to get md5 stream
int get_pos(char find); // used to get position of the character from 0-25
void crypt(FILE * fp1, FILE * fp2, FILE * fp); // converts text to cypher text using key. 
void invkey(FILE * fp1, FILE * fp2); // computes inverse key using the key. 
char get_char(int pos); // returns an alphabet at a position from 0-25
void histo(int t, int which, FILE * fp); // gives histogram for cipher text. 
void solve(char * filename); //kasiski's method
void solve1(char * filename, int t_max); // solve - method 2
void solve2(char * filename, int t_max); //solve - method 3

#endif
