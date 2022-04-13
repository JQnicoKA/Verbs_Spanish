#include "projet.h"
#include "projet.c"
#include "tableau.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
/**
* Création d'une boucle do while pour proposer au joueur de rejouer
* grace à la variable voulezVousRejouer, terminée ligne 105
*/
	int voulezVousRejouer;
	do{

//Cette ligne de code "clean" l'interface console
system("cls");

printf("\n\n-------------------------MENU---------------------------\n");
printf("********************************************************\n**********************Verbes espanol********************\n********************************************************\n\n");

/**
* Menu proposant les possibilités à l'utilisateur
* la variable valeurRenvoyeeParScanf nous permet de verifier que l'utilisateur ne rentre pas n importe quoi
* cette action se poursuit jusque ligne 50
*/
int valeurRenvoyeeParScanf;
int choix;

printf("\nQue voulez-vous faire ?\n");
printf("1 : Jouer avec les verbes irreguliers\n2 : Jouer avec les verbes reguliers : Tomar, Deber et Recibir\n3 : Jouer avec les 500 verbes\n");
printf("\nvotre choix : ");
valeurRenvoyeeParScanf = scanf("%d",& choix);

while(valeurRenvoyeeParScanf !=	1 || (choix != 1 && choix != 2 && choix != 3)){

	int c;
	do{
		c = fgetc(stdin);
	}while(c != '\n' && c != EOF);

printf("\nQue voulez-vous faire ?\n");
printf("1 : Jouer avec les verbes irreguliers\n2 : Jouer avec les verbes reguliers : Tomar, Deber et Recibir\n3 : Jouer avec les 500 verbes\n");
printf("\nvotre choix : ");
valeurRenvoyeeParScanf = scanf("%d",& choix);

														  		}

//Cette ligne de code "clean" l'interface console
system("cls");

/**
* Creation de la base de donnees BC
* puis remplissage de celle ci avec toutes les conjugaisons
*/
Base BC = newBase();
BC = creation(BC);

//Creation d'une variable score pour récupérer le score de l'utilisateur
int score;

/**
* on envoie un code à la fonction jeu qu'on utilisera pour traiter quels verbes l'utilisateur veut exercer
* puis on appelle la fonction score pour remplir un fichier txt avec le score du joueur
*/
score = jeu(BC, choix);
scores(score, choix);

/**
* Menu proposant les possibilités à l'utilisateur à la fin
* la variable valeurRenvoyeeParScanf nous permet de verifier que l'utilisateur ne rentre pas n importe quoi
* cette action se poursuit jusque ligne 103
*/
printf("\nQue voulez-vous faire ?\n");
printf("1 : Rejouer\n2 : Quitter\n");
printf("\nvotre choix : ");
valeurRenvoyeeParScanf = scanf("%d",& voulezVousRejouer);

while(valeurRenvoyeeParScanf !=	1 || (voulezVousRejouer != 1 && voulezVousRejouer != 2)){

	int c;
	do{
		c = fgetc(stdin);
	}while(c != '\n' && c != EOF);

printf("\nQue voulez-vous faire ?\n");
printf("1 : Rejouer\n2 : Quitter\n");
printf("\nvotre choix : ");
valeurRenvoyeeParScanf = scanf("%d",& voulezVousRejouer);

														  		}

		}while(voulezVousRejouer != 2);


printf("\nMerci d'avoir jou\x82 !\nNicolas Lecas");
}