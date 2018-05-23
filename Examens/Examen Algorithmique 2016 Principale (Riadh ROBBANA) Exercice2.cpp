#include <stdio.h>
#include <stdlib.h>

typedef strcut Arbre{
	int val ;
	struct Arbre* fd;
	struct Arbre* fg;
}Arbre;

typedef Arbre* arbre;

//fonction recursive pour detruire une arbre binaire

void detruireRecursive(arbre a){
	if(a==NULL){
		return;
	}
	detruireIterative(a->fg);
	detruireIterative(a->fd);
	free(a);
}


//fonction itérative pour detruire une arbre binaire

void detruireIterative(arbre a){
	arbre courant;
	int arbreTerminee = 0;
	while(!arbreTerminee)
	{
		/* 
			on parcourt chaque fois le demi-arbre gauche
			et on supprime l'element le plus petit
		*/
		if(a->fg != NULL){
			courant = a->fg;
			while((courant->fg) && (courant->fd)){
				if(courant->fg != NULL){
					courant = courant->fg;
				}else{
					courant = courant->fd;
				}
			}
			free(courant);
		}else if(a->fd != NULL)
		/*
			puis lorsque on termine le demi-arbre gauche 
			on commance avec le demi-arbre droit et on supprime
			chaque fois l'element le plus grand 
		*/
		{
			courant = a->fd;
			while((courant->fd) && (courant->fg)){
				if(courant->fd != NULL){
					courant = courant->fd;
				}else{
					courant = courant->fg;
				}
			}
			free(courant);
		}else
		//si on libere les deux demi-arbres, donc on a terminé
		{
			arbreTerminee = 1;
		}
	}
}
