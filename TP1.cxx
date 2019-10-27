#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Le but est de creer un mini jeu dans lequel on demande a l'utilisateur de trouver un nombre mystere.*/

int main()
{
	/*Initialisation des variables et des constantes*/
	bool continuerPartie = 1;
    int nombreMax, niveau;
	int nombreMystere, nombreEntre, cpt = 0;
	const int MIN = 1;
	char choix;

	do { //Debut de la 1ere boucle
    	do {
    	printf("Choisissez le niveau de difficultés: \n");
    	printf("1- De 1 à 10: tapez 1 \n");
    	printf("2- De 1 à 100: tapez 2 \n");
    	printf("3- De 1 à 1000: tapez 3 \n");
    	printf("---------------------------------------\n");
    	scanf("%d", &niveau);
	
	switch(niveau) {
	    case 1:
	        nombreMax = 10;
	        break;
	    case 2:
	        nombreMax = 100;
	        break;
	    case 3:
	        nombreMax = 1000;
	        break;
	     default:
	         printf("Entrer une valeur valide svp!");
	         break;
	}
	     }  while (niveau < 0 && niveau > 4);
	         
	srand(time(NULL));
	nombreMystere = (rand() % (nombreMax - MIN + 1)) + MIN;
	
	do { //Debut de la 2nde boucle
		cpt++; //Le compteur ne marche pas
		printf("Entrer un nombre compris entre 1 et %d \n", nombreMax);
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
	scanf("%c", &choix);
	
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
