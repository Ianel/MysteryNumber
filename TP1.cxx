#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Le but est de creer un mini jeu dans lequel on demande a l'utilisateur de trouver un nombre mystere.*/

int main()
{
	/*Initialisation des variables et des constantes*/
	bool continuerPartie = 1;
	const int MAX = 100, MIN = 1;
	int nombreMystere, nombreEntre, cpt;
	char choix;

	do { //Debut de la 1ere boucle
	srand(time(NULL));
	nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
	
	do { //Debut de la 2nde boucle
		cpt++; //Le compteur ne marche pas
		printf("Entrer un nombre compris entre 1 et 100\n");
		scanf("%d", &nombreEntre);
		
		if (nombreEntre < nombreMystere)
		{
			printf("C'est plus\n");
		} else if (nombreEntre > nombreMystere) {
			printf("C'est moins\n");
		} else {
			printf("Vous avez trouvé le nombre mystere en %d coups\n", cpt);
		}
	} while (nombreEntre != nombreMystere);

	printf("\nVoulez-vous continuer la partie?\n");

	do { //Debut de la derniere boucle
	printf("Tapez 1 pour continuer et 2 pour quitter\n");
	scanf("%d", &choix);
	
	switch (choix) {
		case 1:
			continuerPartie = 1;
			break;
		case 2:
			continuerPartie = 0;
			break;
		default:
			printf("Tapez soit 1 soit 2\n\n");
			break;
	}
	} while (choix != 1 && choix != 2);
	} while (continuerPartie);
	
	return 0;
}