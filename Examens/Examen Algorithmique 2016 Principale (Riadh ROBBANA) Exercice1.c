#include <stdio.h>
#include <stdlib.h>

typedef struct FilePrio{
	int priorite ;
	int val ;
	struct File* suiv ;
}FilePrio;

typedef File* filePrio ;

fileprio creeVide(){
	return NULL;
}
int fileEstVide(filePrio f){
	if(f == NULL){
		return 1 ;
	}else{
		return 0;
	}
}

void depot(filePrio* f, int prio , int v){
	filePrio nvFile = creeVide();
	if(!(nvFile = (filePrio)malloc(sizeof(FilePrio)))){
		printf("erreur d'allocation ");
		exit(0);
	}
	nvFile->priorite = prio ;
	nvFile->val = v ;
	nvFile->suiv = *f ;
	if(fileEstVide(*f)){
		*f = nvFile;
	}
}

/*
	on veut obtenir l'element le plus encien
    avec la priorite la plus haute
*/
int retrait (filePrio* f){
	if(fileEstVide(*f)){
		return (-1);
	}
	int prioMax = 0;
	filePrio fileAux = creeVide();
	/*
		on considere q'on possède ces fonctions:
		int getTeteVal(file f) :qui retourne la valeur de l'élement du tete
		int getTetePrio(file f) :qui retourne la priorité de l'élement du tete
		void defiler(file* f) :qui defile une file
	*/
	while(!fileEstVide(*f)){
		if(getTetePrio(*f) > prioMax){
			prioMax = getTetePrio(*f); 
		}
		depot(&fileAux,getTetePrio(*f),getTeteVal(*f));
		defiler(f);
	}
	int ret;
	while(!fileEstVide(fileAux)){
		if(getTetePrio(fileAux)==prioMax){
			ret = getTeteVal(fileAux);
		}
		depot(f,getTetePrio,getTeteVal);
		defiler(&fileAux);
	}
	return ret;
}
