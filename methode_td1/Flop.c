#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>

unsigned int cpt=0;

void my_handler(int s) {
	printf("Nb d'operations effectuees : %e\n", (double) cpt);
	exit(0);
}

int main(int argc, char **argv) {

	srandom(time(NULL));

	float a = (float) (random()*1.0/RAND_MAX);
	float b = (float) (random()*1.0/RAND_MAX);
	float c;

//	printf("a=%g\t b=%g\n", a, b);

// Installation du handler du signal SIGUSR1

	signal(SIGUSR1, my_handler);

	if(!fork()) { // processus fils s'endormant 1 seconde puis envoyant un signal au papa
		sleep(1);
		kill(getppid(), SIGUSR1);
		exit(0);
	}

// On est dans le processus père

	while(1) {
		c = a+b;
		cpt++;
	}
}
