#include <stdio.h>
#include <stdlib.h>


int NombreGaucheDroite(arbre a){
	if(a == NULL){
		return 0;
	}else if(!a->fd){
		return(NombreGaucheDroite(a->fg));
	}else if(!a->fg){
		return (NombreGaucheDroite(a->fd));
	}else{
		return(1 + NombreGaucheDroite(a->fd) + NombreGaucheDroite(a->fg));
	}
}




arbre suppElem(arbre a, int v){
	/*
		on verifie si l'arbre est vide ou si 
		l'element à supprimer n'existe pas dans l'arbre
	*/
	if(arbreEstVide(a)){
		return a;
	}else if(!trouve(a,v)){
		return a; 
	}else{
		if(a->val == v){
			/*
				si l'un des branches est vide lorsque
				on a trouve le noeud cherche, on retourne
				l'autre
			*/
			if(arbreEstVide(a->fd)){
				arbre aux = a->fg ;
				free(a);
				return aux ;
			}else if(arbreEstVide(a->fg)){
				arbre aux = a->fd ; 
				free(a);
				return aux ;
			}
			/*
				sinon, on commence par chercher l'element 
				le plus grand de la branche de gauche 
			*/
			arbre courant = a->fg ;
			while(!arbreEstVide(courant->fd)){
				courant = courant->fd;
			}
			/*
				on registre sa branche gauche, dans
				le cas si ce noeud n'est pas une feille
			*/
			arbre aux1 = courant->fg;
			/*
				on place ce noeud dans la place de noeud 
				qui va etre supprimé
			*/
			courant->fg = a->fg;
			courant->fd = a->fd;
			/*
			on revient et on supprime le nouveau element
			pour éviter un boucle fermé
			*/
			arbre courant2 =a->fg ;
			while(courant2->fd != courant){
				courant2 = courant2->fd ;
			}
			courant2->fd = NULL ;
			
			free(a);
			return courant ;
			
			
			}else if(a->val>v){
				a->fg = suppElem(a->fg,v);
			}else{
				a->fd = suppElem(a->fd,v);
			}
	}
}
