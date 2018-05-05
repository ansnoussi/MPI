#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//le type de liste pour les donnees non comprimees
typedef struct CharListe {
	char c ;
	struct CharListe* suiv ;
}CharListe;

typedef struct CharListe* charliste ;

//le type de liste pour les donnees comprimees
typedef struct CodeListe{
	char c ;
	int count ;
	struct CodeListe* suiv;
}CodeListe;

typedef struct CodeListe* codeliste ;

charliste CreeCharVide(){
	return NULL;
}
codeliste CreeCodeVide(){
	return NULL;
}

void AjoutCharElem(charliste* l, char c){
	charliste nv = CreeCharVide() ;
	if(!(nv = (charliste)malloc(sizeof(CharListe)))){
		printf("erreur d'allocation! ");
		exit(0);
	}
	
	nv->c = c;
	nv->suiv = NULL ;
	
	if(*l == NULL){
		*l = nv ;
	}else{
		charliste courant = *l ;
		while(courant->suiv != NULL){
			courant = courant->suiv ;
		}
		courant->suiv = nv ;
	}
}

void AjoutCodeElem(codeliste* l, int count , char c){
	codeliste nv = CreeCodeVide() ;
	if(!(nv = (codeliste)malloc(sizeof(CodeListe)))){
		printf("erreur d'allocation ");
		exit(0);
	}
	nv->c = c ;
	nv->count = count ;
	nv->suiv = NULL;
	if(*l == NULL){
		*l = nv;
	}else{
		codeliste courant = *l ;
		while(courant != NULL){
			courant = courant->suiv;
		}
		courant->suiv = nv ;
	}
}

codeliste CoderListe(charliste l){
	printf("test! \n");
	codeliste nv  = CreeCodeVide();
	if(l == NULL){
		return NULL;
	}
	char aux = l->c;
	int count = 0;
	while(l != NULL){
		if(l->c == aux){
			count ++ ;
			l = l->suiv;
		}else{
			AjoutCodeElem(&nv , count , aux);
			aux = l->c ;
			count = 1;
			l = l->suiv ;
		}
	}
	AjoutCodeElem(&nv , count , aux );
	return nv ;
}

charliste DecoderListe(codeliste l){
	charliste nv ;
	while( l != NULL){
		for(int i=0 ; i< l->count ; i++){
			AjoutCharElem(&nv, l->c);
		}
		l = l->suiv;
	}
	return nv ;
}

char ComparerListes(charliste l1 , charliste l2){
	char kifkif = 1 ;
	while(l1 != NULL && l2 != NULL && kifkif){
		if(l1->c != l2->c){
			kifkif = 0;
		}
		l1 = l1->suiv ;
		l2 = l2->suiv ;
	}
	return(kifkif && (l1 == l2));
}

charliste CreeCharListe(char s[]){
	charliste nv  = CreeCharVide();
	for(int i=0 ; i< strlen(s) ; i++){
		AjoutCharElem(&nv , s[i]);
	}
	return nv;
}

void afficherCharListe(charliste l){
	while(l != NULL){
		printf("(%c) ->",l->c);
		l = l->suiv;
	}
	printf(" \n ");
}
void afficherCodeListe(codeliste l){
	while(l != NULL){
		printf("(%c - %d)->",l->c,l->count);
	}
	printf(" \n ");
	l = l->suiv;
}



int main() {
	charliste nvListe = CreeCharListe("aaaaabbbbkkkjjj");
	codeliste nvCode = CreeCodeVide();
	nvCode = CoderListe(nvListe);
	charliste nvString = DecoderListe(nvCode);
	if(ComparerListes(nvListe,nvString)){
		printf("tous va bien !");
	}
}
