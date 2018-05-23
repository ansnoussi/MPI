#include <stdio.h>

//tester si deux ABR sont egaux
char Egaux(arbre a, arbre b){
	if(a == NULL){
		if(b == NULL){
			return 1 ;
		}else{
			return 0;
		}
	}else if (b == NULL){
		return 0;
	}else{
		if(a->val != b->val){
			return 0;
		}else{
			return(Egaux(a->fd , b->fd) && Egaux(a->fg , b->fg));
		}
	}
}


//retourne le nombre de valeurs inférieurs a k dans l'ABR a
int Compteur_Inf(arbre a, int k){
	if(a == NULL){
		return 0 ;
	}
	if(a->val > k){
		return (Compteur_Inf(a->fg , k));
	}else{
		return(1 + Compteur_Inf(a->fg , k) + Compteur_Inf(f->fd , k));
	}
}
