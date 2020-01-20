/*   Programme visualisant le codage des nombres flottants suivant la norme IEEE-754
 */

#include <stdio.h>
#include <stdlib.h>

#define N 4 // taille d'un float en octets

int main(int argc, char **argv) {

	float x;
	int k, exp;
	unsigned char o[N];
	char *pt;

	if (argc != 2) {
		printf("usage : ShowFloat <nb_flottant>\n");
		exit(0);
	}

	x = atof(argv[1]);

	printf("Vous avez entre : %g\n", x);

	pt = (char *) &x;

	for(k=0; k<N; k++) o[k]=*(pt+k);

	printf("Affichage brut : 0x %x %x %x %x\n", o[3], o[2], o[1], o[0]);

	// affichage du bit de signe
	
	if (o[3] & 0x80) printf("Signe negatif.\n");
	else printf("Signe positif.\n");

	// affichage de l'exposant brut
	
	exp=((o[3] & 0x7f) << 1) | ((o[2] & 0x80) >> 7);
	printf("Exposant brut : %d\n",exp);

	// affichage de la mantisse
	
	printf("Mantisse : 0x %x %x %x\n", (o[2] & 0x7f) | 0x80, o[1], o[0]);

	exit(0);
}
