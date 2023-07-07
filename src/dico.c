#include "dico.h"

void ajoutMot() {
	FILE* dico = fopen("dico.txt","r+");
	assert(dico);

	char NewWord[30];
	printf("Rentrer le nouveau mot à ajouter au dictionnaire : ");
	scanf("%s",NewWord);

	for (int i = 0; i < strlen(NewWord); ++i)
		NewWord[i] = toupper(NewWord[i]);

	int nbWord;
	fscanf(dico,"%d",&nbWord);
	nbWord++;
	rewind(dico);
	fprintf(dico, "%d\n", nbWord);
	fseek(dico, 0, SEEK_END);
	fprintf(dico, "%s\n", NewWord);
	fclose(dico);
}

void afficherDico() {
	FILE* dico = fopen("dico.txt","r");
	assert(dico);

	int nbWord;
	fscanf(dico,"%d",&nbWord);

	printf("Le dictionnaire contient %d mots !\n", nbWord);

	char current[30];
	for (int i = 0; i < nbWord; ++i)
	{
		fscanf(dico,"%s",current);
		printf("%s\n", current);
	}

	fclose(dico);
}
