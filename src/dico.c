#include "dico.h"

void ajoutMot() {
	FILE* dico = fopen("dico.txt","r+");
	assert(dico);

	char NewWord[30];
	printf("Enter the new word to add : ");
	scanf("%29s",NewWord);

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

	printf("The dictionary contains %d words !\n", nbWord);

	char current[30];
	for (int i = 0; i < nbWord; ++i)
	{
		fscanf(dico,"%29s",current);
		printf("%s\n", current);
	}

	fclose(dico);
}
