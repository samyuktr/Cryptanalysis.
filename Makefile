all: main.o keygen.o crypt.o invkey.o histogram.o solve_m2.o
	gcc -g  main.o keygen.o crypt.o solve_m2.o invkey.o histogram.o -o hw3 -L/home/scf-22/csci551b/openssl/lib -lcrypto -lm

main.o: main.c hw3.h
	gcc -c -g main.c -Wall -I/home/scf-22/csci551b/openssl/include

keygen.o: keygen.c hw3.h
	gcc -c -g  keygen.c  -Wall -I/home/scf-22/csci551b/openssl/include

crypt.o: crypt.c hw3.h
	gcc -c -g crypt.c -Wall -I/home/scf-22/csci551b/openssl/include

invkey.o: invkey.c hw3.h
	gcc -c -g invkey.c -Wall -I/home/scf-22/csci551b/openssl/include

histogram.o: histogram.c hw3.h
	gcc -c -g -Wall histogram.c -I/home/scf-22/csci551b/openssl/include

solve_m2.o: solve_m2.c hw3.h
	gcc -c -g -Wall solve_m2.c -I/home/scf-22/csci551b/openssl/include


clean:
	rm *.o
	rm hw3
