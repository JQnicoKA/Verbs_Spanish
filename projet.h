#ifndef __PROJET_H__
#define __PROJET_H__

#include <stdlib.h>
#include <stdio.h>


/* Définition d'un boolean' */
typedef enum
{
	false,
	true
}Bool;

/* Définition de notre structure verbe */
struct Verbe
{
	char verbeFrancais[100];
	char temps[50];
	char personne[150];
	char conjugaison[50];
};

typedef struct Verbe Verbe;

/* Définition d'une base de connaissances regroupant tous les verbes */
typedef struct full
{
	Verbe ligne;
	struct full *next;
}Full;

typedef Full *Base;


Base newBase();
Verbe newVerbe();
Verbe remplir(Verbe v, char w[], char x[], char y[], char z[]);
Base insert_base(Base BC, Verbe regle);
int jeu(Base BC, int choix);
void scores(int score, int choix);
Bool compare(char reponse[], char reponseJuste[]);
void retirer_caracteres_blancs(char chaine[], char copy[]);

#endif