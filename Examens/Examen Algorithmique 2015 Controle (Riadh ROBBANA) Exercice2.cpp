#include <stdio.h>
#include <stdlib.h>

typedef struct Liste{
	int val ;
	struct Liste* suiv;
}Liste;

typedef Liste* liste;

liste Intercection(liste l1 , liste l2){
	liste nvListe = creeListeVide();
	liste courant = l2
	while(!listeEstVide(l1)){
		while(!listeEstVide(courant)){
			if(courant->val == l1->val){
				ajoutElement(&nvListe,courant->val);
				break;
			}
			courant = courant->suiv;
		}
		l1 = l1->suiv;
	}
	return nvListe;
}


liste Difference(liste l1, liste l2){
	liste nvListe = creeListeVide();
	liste courant = l2;
	int trouve;
	while(!listeEstVide(l1)){
		trouve =0;
		while(!listeEstVide(courant)){
			if(courant->val == l1->val){
				trouve = 1;
			}
			courant = courant->suiv;
		}
		if(!trouve){
			ajoutElement(&nvListe,l1->val);
		}
		l1 = l1->suiv;
	}
	return nvListe;
}
