#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud{
	int val ;
	struct Noeud* suivant ;
}Noeud;

typedef Noeud* file ;


file creeFileVide(){
	return NULL ;
}

char fileEstVide(file f){
	if(!f){
		return 1 ;
	}else{
		return 0;
	}
}

file Enfiler (file f, int v){
	file nvFile = creeFileVide();
	if(!(nvFile = (file)malloc(sizeof(Noeud)))){
		printf("erreur d'allocation \n");
		exit(0);
	}
	nvFile->suivant = NULL;
	nvFile->val = v;
	if(fileEstVide(f)){
		return nvFile;
	}else{
		file courant = f ;
		while(courant->suivant != NULL){
			courant = courant->suivant;
		}
		courant->suivant = nvFile;
		return f;
	}
}

file Defiler(file f){
	if(fileEstVide(f)){
		return NULL;
	}else{
		file fileAux = f->suivant ;
		free(f);
		return fileAux ;
	}
}

int getFileTete(file f){
	if(fileEstVide(f)){
		printf("erreur : File est vide! \n");
		return (-1);
	}else{
		return f->val;
	}
}

int longeurFile(file *f){
	file fileAux = creeFileVide();
	int i =0 ;
	while(!fileEstVide(*f)){
		i ++ ;
		fileAux = Enfiler(fileAux , getFileTete(*f));
		*f = Defiler(*f);
	}
	while(!fileEstVide(fileAux)){
		*f = Enfiler(*f, getFileTete(fileAux));
		fileAux = Defiler(fileAux);
	}
	return i ;
}

void afficherFile(file* f){
	file fileAux = creeFileVide();
	while(!fileEstVide(*f)){
		printf("%d <- ",(*f)->val);
		fileAux = Enfiler(fileAux, getFileTete(*f));
		*f = Defiler(*f);
	}
	printf("POINTER");
	*f =fileAux;
	
}

int main() {
	file f = creeFileVide();
	f = Enfiler(f, 20);
	f = Enfiler(f, 23);
	f = Enfiler(f, 60);
	f = Enfiler(f, 50);
	f = Enfiler(f, 33);
	f = Enfiler(f, 20);
	f = Enfiler(f, 20);
	afficherFile(&f);
	printf("\n");
	printf("longeur file: %d \n",longeurFile(&f));
	afficherFile(&f);
	printf("\n");
	afficherFile(&f);
}
