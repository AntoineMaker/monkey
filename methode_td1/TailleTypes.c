#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	printf("Nb d'octets pour un char\t : \t %lu\n", sizeof(char));
	printf("Nb d'octets pour un short\t : \t %lu\n", sizeof(short));
	printf("Nb d'octets pour un int\t\t : \t %lu\n", sizeof(int));
	printf("Nb d'octets pour un long\t : \t %lu\n", sizeof(long));
	printf("Nb d'octets pour un long long\t : \t %lu\n", sizeof(long long));
	printf("Nb d'octets pour un float\t : \t %lu\n", sizeof(float));
	printf("Nb d'octets pour un double\t : \t%lu\n", sizeof(double));
	printf("Nb d'octets pour un long double\t : \t %lu\n",sizeof(long double));
	return(0);
}
