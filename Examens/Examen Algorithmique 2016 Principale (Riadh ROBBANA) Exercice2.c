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
//version 1: on va supprimer le plus petit element jusqu'a detriure l'arbre

void detruireIterativeV1(arbre a){
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


//fonction itérative pour detruire une arbre binaire
//version 2: on va utiliser un file pour se faire
//donc on doit defenir les fonctions necessaires

typedef struct File{
	arbre a;
	struct File* suiv;
}File;
typedef File* file;

file teteDuFile ;

file creeVide(){
	return NULL;
}
int fileEstVide(file f){
	return(f == NULL);
}
void enfiler (file* f, arbre a){
	file nvFile = creeVide();
	if(!(nvFile = (file)malloc(sizeof(File)))){
		printf("erreur d'allocation");
		exit(0);
	}
	nvFile->a = a;
	nvFile->suiv=NULL;
	
	if(fileEstVide(*f)){
		*f = nvFile;
		return;
	}
	file courant = *f;
	while(!fileEstVide(courant->suiv)){
		courant = courant->suiv;
	}
	courant->suiv = nvFile;
}
arbre  getTete(file f){
	if(fileEstVide(f)){
		return NULL;
	}
	return(f->a);
}
void defiler(file *f){
	file fileAux = *f;
	*f = *f->suiv;
	free(fileAux);
}

//fonction de destruction de l'arbre
void detruireIterativeV2(arbre a){
	file nvFile =creeVide();
	enfiler(&nvFile,a);
	while(!fileEstVide(nvFile)){
		arbre aux, aux1, aux2;
		aux = getTete(nvFile);
		aux1 =aux->fd;
		aux2 =aux->fg;
		if(aux1){
			enfiler(&nvFile,aux1);
		}
		if(aux2){
			enfiler(&nvFile,aux2);
		}
		free(aux);
		defiler(&nvFile);
	}
}
