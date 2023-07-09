#include "pendu.h"
#include "dico.h"

int main(int argc, char*argv[]){

	int choix = 0;
	do {
		do
		{
			printf("\n1- Play\n");
			printf("2- Display dictionary\n");
			printf("3- Add a word\n");
			printf("4- Exit\n");
			printf("\n Choice : ");
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