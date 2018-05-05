#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud{
	int valeur ;
	struct Noeud* suivant ;
}Noeud;

typedef Noeud* Pile ;

Pile creePileVide(){
	return NULL; 
}

char pileEstVide(Pile p){
	if (!p)
		return 1 ;
	else
	return 0 ;
}

Pile Empiler(Pile p , int val){
	Pile nvPile ;
	if(!(nvPile = (Pile)malloc(sizeof(Noeud)))){
		printf("erreur d'allocation ! ");
		exit(0);
	}
	nvPile->valeur = val;
	nvPile->suivant = p ;
	return nvPile ;
}

Pile Depiler(Pile p){
	if(pileEstVide(p)){
		printf("pile est vide !");
		exit(0);
	}
	Pile temp = p;
	p = p->suivant ;
	free(temp);
	return p ;
}

int getPileTete(Pile p ){
	if(pileEstVide(p)){
		printf("erreur pile est vide! ");
		exit(0);
	}
	return (p->valeur);
}

int longeurPile(Pile p ){
	Pile auxPile = creePileVide();
	int i = 0;
	while(!pileEstVide(p)){
		i++ ;
		auxPile = Empiler(auxPile,getPileTete(p));
		p = Depiler(p);
	}
	while(!pileEstVide(auxPile)){
		p = Empiler(p,getPileTete(auxPile));
		auxPile = Depiler(auxPile);
	}
	return i ;
}

void afficherPile(Pile *p ){
	Pile auxPile = creePileVide();
	while(!pileEstVide(*p)){
		printf("%d --> ",(*p)->valeur);
		auxPile = Empiler(auxPile,getPileTete(*p));
		*p= Depiler(*p);
	}
		printf("NULL \n");
	while(!pileEstVide(auxPile)){
		*p = Empiler(*p,getPileTete(auxPile));
		auxPile = Depiler(auxPile);
	}
}

//diviser p en 2 piles: p1 pour les impares et p2 pour les paires

void diviserPile(Pile p,Pile* p1,Pile* p2){
	if(pileEstVide(p)){
		printf("pile est vide! \n");
		exit(0);
	}
	Pile temp = creePileVide();
	*p2 = creePileVide(); // pour les paires
	*p1 = creePileVide(); // pour les impaires
	while(!pileEstVide(p)){
		if(p->valeur % 2){
			*p1 = Empiler(*p1,getPileTete(p));
			temp = Empiler(temp, getPileTete(p));
			p = Depiler(p);
		}else{
			*p2 = Empiler(*p2,getPileTete(p));
			temp = Empiler(temp, getPileTete(p));
			p = Depiler(p);
		}
	}
	while(!pileEstVide(temp)){
		p = Empiler(p,getPileTete(temp));
		temp = Depiler(temp);
	}
}

//inverser recursivement une pile
void inverserRecusive(Pile p1 , Pile* p2){
	if(pileEstVide(p1)){
		return ;
	}
	*p2 = Empiler(*p2, getPileTete(p1));
	p1 = Depiler(p1);
	inverserRecusive(p1,p2);
}

//inverser l'ordre des elements d'une pile

Pile inverserPile(Pile p){
	Pile invPile = creePileVide();
	while(!pileEstVide(p)){
		invPile = Empiler(invPile, getPileTete(p));
		p = Depiler(p);
	}
	return invPile;
}


//combiner deux piles ordonnées en une seul

Pile CombinerPiles(Pile p1 , Pile p2){
	
	Pile fPile = creePileVide();
	while(!pileEstVide(p1) || !pileEstVide(p2)){
		if(pileEstVide(p1)){
			fPile = Empiler(fPile,getPileTete(p2));
			p2 = Depiler(p2);
		}else if(pileEstVide(p2)){
			fPile = Empiler(fPile,getPileTete(p1));
			p1 = Depiler(p1);
		}else{
		
			if(p1->valeur < p2->valeur){
				fPile = Empiler(fPile,getPileTete(p1));
				p1 = Depiler(p1);
				}else{
					fPile = Empiler(fPile,getPileTete(p2));
					p2 = Depiler(p2);
					}
			}
	}
	fPile = inverserPile(fPile);
	return fPile;
}


int main() {
	Pile p = creePileVide();
	p = Empiler(p , 55);
	p = Empiler(p , 66);
	p = Empiler(p , 20);
	p = Empiler(p , 2);
	p = Empiler(p , 12);
	afficherPile(&p);
	Pile pInv = creePileVide();
	inverserRecusive(p,&pInv);
	afficherPile(&pInv);
	
}
