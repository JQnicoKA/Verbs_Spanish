#include "projet.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//---------------------------------------------------------------------------------------------------------------------------//
/**
* Fonction principale du projet
* @param BC la base de données composée de tous nos verbes
* @param choix le choix de l'utilisateur (verbes réguliers ou irréguliers)
* @return le score (int) marqué par l'utilisateur
*/

int jeu(Base BC, int choix)
{
	//Initialisation du nombre de vies et du score à 0
	int nombreDeVies = 3;
	int score = 0;

	/**
	* Création d'une boucle while qui s'effectue tant qu'il reste des vies au joueur
	* grace à la variable nombreDeVies, terminée ligne
	*/
	while (nombreDeVies != 0){

		/**
		* Ces lignes servent à vider le buffer
		* action terminée ligne 36
		*/
		int c; 
    	do { 
        c = getchar(); 
    	} while (c != '\n' && c != EOF);

    	/**
		* Création d'un nombre aléatoire
		* Celui ci va prendre des valeurs de 0 à 394 ou de 445 à 494
		* Ceci en fonction du choix de l'utilisateur
		* Grace à la variable choix
		* Action terminée ligne 54
		*/
		int nombreAleatoire = 0;
		srand(time(NULL));

		if(choix == 1){
			nombreAleatoire = rand()%394;
		}else if (choix == 2){
			nombreAleatoire = rand()%149 + 395;
		}else if (choix == 3){
			nombreAleatoire = rand()%471 + 545;
		}
		
		/**
		* Création d'un pointeur temp sur la tête de notre base de données
		* On fait ça pour ne pas la perdre
		* On avance ce pointeur de 1 un nombre aléatoire de fois
		* (variable nombreAleatoire introduite ci-dessus)
		*/
		Full *temp;
		temp = BC;

		for(int i=0; i<nombreAleatoire ; i++){
			temp = temp->next;
		}

		
		//Affichage à l'écran du verbe en question trouvé dans la base de données
		puts(temp->ligne.verbeFrancais);
		puts(temp->ligne.temps);
		puts(temp->ligne.personne);

		//Création de la chaîne de caractère réponse, puis aquisition
		char reponse[255];
		gets(reponse);


//Si la reponse de l'utilisateur est differente de la reponse juste
if(compare(reponse, temp->ligne.conjugaison)== false)
		{
			printf("Hata, cozum suydu :");
			puts(temp->ligne.conjugaison);
			printf("                                                   Puanin : %d\n",score);
			nombreDeVies = nombreDeVies -1;
			printf("                                                   %d canin kaldi",nombreDeVies);

			
		}else{
			printf("DOGRU\n");
			score++;
			printf("                                               Puanin : %d\n",score);
			printf("                                               %d canin kaldi",nombreDeVies);
		}

							}

		


//On renvoie le score pour le traiter dans le main.c
return score;

}

//---------------------------------------------------------------------------------------------------------------------------//
/**
* Crée notre structure base de données
* @param
* @return NULL
*/

Base newBase()
{
	return NULL;
}

//---------------------------------------------------------------------------------------------------------------------------//
/**
* Crée notre structure Verbe vide
* @param
* @return Verbe v
*/

Verbe newVerbe()
{
	Verbe v = {"", "", "", ""};
	return v;
}

//---------------------------------------------------------------------------------------------------------------------------//
/**
* Remplit chaque structure Verbe
* @param Verbe element
* @param char w (verbe en français)
* @param char x (temps)
* @param char y (personne)
* @param char z (conjugaison en espagnol)
* @return Verbe element
*/

Verbe remplir(Verbe element, char w[], char x[], char y[], char z[])
{

	strcpy(element.verbeFrancais, w);
	strcpy(element.temps, x);
	strcpy(element.personne, y);
	strcpy(element.conjugaison, z);

	return element;

}

//---------------------------------------------------------------------------------------------------------------------------//


Base insert_base(Base BC, Verbe regle)
{
	Full *element = NULL;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Probleme : allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	element->ligne = regle;
	element->next = NULL;

	if(BC == NULL)
		return element;

	Full *temp;
	temp = BC;

	while(temp->next != NULL)
		temp = temp->next;

	temp->next = element;

	return BC;
}

//---------------------------------------------------------------------------------------------------------------------------//


void scores(int score, int choix)
{

//Je grise psk finalement je trouve ca sert a rien de rentrer le nom

	//printf("\nVeuillez rentrer votre nom : ");

	//char nomUtilisateur[255]; 
	//gets(nomUtilisateur);

	FILE *fic = fopen("fichier.txt", "a");
	if(fic == NULL){
		exit(1);
				   }

	if(choix == 1){
		fprintf(fic, "i");
	}else if (choix ==2){
		fprintf(fic, "r");
	}else{
		fprintf(fic, "v");
	}

	//fprintf(fic, "%s", nomUtilisateur);
	fprintf(fic, "%d\n", score);

	fclose(fic);
}

//---------------------------------------------------------------------------------------------------------------------------//
/**
* Compare deux chaines de caracteres
* Ne doit pas prendre en compte ni les espaces, ni les minuscules majuscule
* @param reponse la reponse de l'utilisateur
* @param reponseJuste la vraie reponse dans la base de donnee
* @return boolean 
*/
Bool compare(char reponse[], char reponseJuste[])
{
	/**
	* Creation des pointeurs p1 et p2 qui vont pointer sur reponse et reponseJuste
	* Ils vont servir a parcourir les deux chaines de caractere sans les perdre
	* on va se servir d'une variable compte qui va compter le nombre de caracteres qui ne sont pas des espaces
	* On va ensuite creer une chaine de caractere copie de la taille du nombre de caractere +1 pour le \0
	*/
	char *p1 = reponse;
	int i=0;
	int compte1 =0;
	while(p1[i] != '\0')
	{
		if(p1[i] != ' '){
			compte1++;
		}
		i++;
	}
	char copie1[compte1+1];


	char *p2 = reponseJuste;
	i=0;
	int compte2 =0;
	while(p2[i] != '\0')
	{
		if(p2[i] != ' '){
			compte2++;
		}
		i++;
	}
	char copie2[compte2+1];

	//Si les deux chaines de caractere sans espace ne font pas la meme taille, c'est que la reponse est fausse
	if(compte1 != compte2){
		return false;
	}else{

	/**
	*On envoie copie1 et copie2 a notre fonction retirer_caracteres_blancs
	*Ainsi a partir de ce moment la copie1 et copie2 sont les memes que reponse et reponseJuste sans les espaces
	*/
	retirer_caracteres_blancs(reponse, copie1);
	
	retirer_caracteres_blancs(reponseJuste, copie2);

   for (i = 0; copie1[i]!='\0'; i++) {
     // Si les caractères sont en majuscules, on les convertit en minuscule 
     // en ajoutant 32 à leur valeur ASCII.
      if(copie1[i] >= 'A' && copie1[i] <= 'Z') {
         copie1[i] = copie1[i] +32;
      }
   }
     for (i = 0; copie2[i]!='\0'; i++) {

      if(copie2[i] >= 'A' && copie2[i] <= 'Z') {
         copie2[i] = copie2[i] +32;
      }
   }

   /**
   * On peut maintenant comparer les deux chaines maintenant qu'elles ne contiennent plus d'espace ni de majuscule
   * Si elles sont egales, la reponse et juste, fausse sinon
   */
	if(strncmp(copie1,copie2,compte1) == 0){
		return true;
	}else{
		return false;
	}

	    }
}

//---------------------------------------------------------------------------------------------------------------------------//
/**
* Retire les espaces de la chaine de caractere chaine, on stocke dans copie
* @param chaine la chaine intiale
* @param copy la copie sans espace
*/

void retirer_caracteres_blancs(char chaine[], char copy[])
{
    int i,j = 0, lg;
    lg = strlen(chaine);
    for(i=0; i<lg; i++)
    {
        if(chaine[i] != ' ' && chaine[i] != '\0')
        {
            copy[j] = chaine[i];
            j++;
        }
    }
    copy[j] == '\0';
}