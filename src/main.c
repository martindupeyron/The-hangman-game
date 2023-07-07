#include "pendu.h"
#include "dico.h"

int main(int argc, char*argv[]){

	int choix = 0;
	do {
		do
		{
			printf("\n1- Jouer\n");
			printf("2- Afficher Dictionnaire\n");
			printf("3- Ajouter un mot au Dictionnaire\n");
			printf("4- Quitter\n");
			printf("\n Choix : ");
			scanf("%d", &choix);
		} while (choix > 4 || choix < 1);

		switch(choix) {
			case 1: jeu();
					break;
			case 2: afficherDico();
					break;
			case 3: ajoutMot();
					break;
			case 4: return 0;
		}

	} while (choix != 4);
}