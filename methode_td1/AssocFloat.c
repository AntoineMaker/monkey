#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define _GNU_SOURCE

#define MAX_EXP 124.0
#define MY_RAND (random()*1.0/RAND_MAX)

int main(int argc, char **argv) {

	int i, non_assoc=0, N;

	if (argc != 2) {
		printf("Usage : ./Associativite <nb_d_essais>\n");
		exit(0);
	}

	N = atoi(argv[1]);

	srandom(time(NULL));

	float a, b, c, tampon, res1, res2, res3;
	printf("My_rand %e\n\n", MY_RAND);
	for(i=0; i<N; i++) {
		a = MY_RAND*2.0;
		a *= powf(2.0, (MY_RAND-0.5)*2.0*MAX_EXP);
		b = MY_RAND*2.0;
		b *= powf(2.0, (MY_RAND-0.5)*2.0*MAX_EXP);
		c = MY_RAND*2.0;
		c *= powf(2.0, (MY_RAND-0.5)*2.0*MAX_EXP);

		tampon = a+b;
		res1 = tampon + c;
		tampon = b+c;
		res2 = tampon + a;
		tampon = a+c;
		res3 = tampon + b;

		if ((res1 != res2) || (res1 != res3) || (res2 != res3)) {
			non_assoc++;
		}
	}
	printf("Frequence de non-associativite = %g \%\n", non_assoc*100.0/N);
	exit(0);
}
