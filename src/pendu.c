#include "pendu.h"

struct ChaineSecrete {
	char SecretWord[30];
	bool* Decouvert;
};

static char lireCaractere() 
{ 
    char caractere = 0;
 
    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà
 
    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer) 
    while (getchar() != '\n') ;
 
    return caractere; // On retourne le premier caractère qu'on a lu 
}

static int rand_a_b(int a, int b){
    srand(time(NULL));
    return (rand()%(b-a+1) + a);
}

static char* motAleatoire() {
	FILE* dico = fopen("dico.txt","r");
	assert(dico);
	int NombreMots;
	fscanf(dico, "%d", &NombreMots);
	assert(NombreMots != 0);
	int RandomWord = rand_a_b(1, NombreMots);
	char SecretWord[30];

	while(RandomWord != 0) {
		fscanf(dico, "%29s", SecretWord);
		RandomWord--;
	}

	fclose(dico);
	char* copie = malloc((strlen(SecretWord)+1)*sizeof(char));
    strcpy(copie,SecretWord);

    return(copie);
}

static ChaineSecrete creerChaineSecrete(char Chaine[]) {
	ChaineSecrete newChaine = malloc(sizeof(struct ChaineSecrete));
	strcpy(newChaine->SecretWord, Chaine);
	newChaine->Decouvert = malloc(sizeof(bool)*strlen(Chaine));
	for (int i = 0; i < strlen(Chaine); ++i)
		newChaine->Decouvert[i] = false;
	return newChaine;
}

static void supprimerChaineSecrete(ChaineSecrete c) {
	free(c->Decouvert);
	free(c);
}

static void afficherMot(ChaineSecrete Game) {
	printf("\n");
	for(int i = 0; i < strlen(Game->SecretWord); i++) {
		if(Game->Decouvert[i])
			printf("%c", Game->SecretWord[i]);
		else
			printf("*");
	}
	printf("\n");
}

static int choixNbTour() {
	int NbTour = 0;
	do {
		printf("How many attempts to find the word? ");
		scanf("%d", &NbTour);
	} while(NbTour < 1);
	return NbTour;
}

static bool gagnant(ChaineSecrete Game) {
	for (int i = 0; i < strlen(Game->SecretWord); ++i)
		if(!Game->Decouvert[i])
			return false;
	printf("You won ! The word was %s\n", Game->SecretWord);
	return true;
}

static bool devoilerLettre(char current, ChaineSecrete Game) {
	bool ok = false;
	for (int j = 0; j < strlen(Game->SecretWord); ++j)
	{
		if(Game->SecretWord[j] == current) {
			Game->Decouvert[j] = true;
			ok = true;
		}
	}
	return ok;
}

static void viderBuffer() {
	int c = 0;
    while (c != '\n' && c != EOF)
        c = getchar();
}

void jeu() {

	ChaineSecrete Game = creerChaineSecrete(motAleatoire());
	int NbTours = choixNbTour();
	afficherMot(Game);
	char current;
	viderBuffer();

	while(NbTours > 0) {
		printf("\n %d attemps remaining\nEnter a letter : ", NbTours);
		current = lireCaractere();
		if(!devoilerLettre(current, Game))
			NbTours--;
		afficherMot(Game);
		if(gagnant(Game))
			return;
	}

	printf("Loooooser ! The word to find was %s\n", Game->SecretWord);
	supprimerChaineSecrete(Game);
}