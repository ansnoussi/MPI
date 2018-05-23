#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a<=b?a:b)


typedef struct arb {
	int val;
	struct arb* fg;
	struct arb* fd;
}arb;

typedef struct arb* arbre;

arbre creeArbreVide() {
	return NULL;
}

char arbreEstVide(arbre b){
	if (b == NULL){
		return 1 ;
	}else{
		return 0 ;
	}
}

int nombreElements(arbre a){
	if(arbreEstVide(a)){
		return 0;
	}else{
		return (1 + nombreElements(a->fd) + nombreElements(a->fg));
	}
}

int longeurArbre(arbre a){
	if(arbreEstVide(a)){
		return 0 ;
	}else{
		return(1+ max(longeurArbre(a->fd),longeurArbre(a->fg)));
	}
}

arbre ajoutElem(arbre a, int v){
	if(arbreEstVide(a)){
		arbre nvArbre = creeArbreVide();
		if(!(nvArbre=(arbre)malloc(sizeof(arb)))){
			printf("erreur d'allocation \n");
			exit(0);
		}
		nvArbre->fd = NULL ;
		nvArbre->fg = NULL ;
		nvArbre->val = v ;
		return nvArbre ;
	}else{
		if(v>(a->val)){
			a->fd = ajoutElem(a->fd,v);
		}else{
			a->fg = ajoutElem(a->fg,v);
		}
	}
}


int exist(arbre a, int v){
	if(arbreEstVide(a)){
		return 0;
	}
	if(a->val == v){
		return 1 ;
	}
	if(a->val < v){
		return(exist(a->fd,v));
	}else{
		return(exist(a->fg,v));
	}
}


char trouve(arbre a, int v){
	if(arbreEstVide(a)){
		return 0;
	}else if(a->val == v){
		return 1 ;
	}else if (v>(a->val)){
		return(trouve(a->fd,v));
	}else{
		return (trouve(a->fg,v));
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

void affichageInfixe(arbre a){
	if(!arbreEstVide(a)){
		affichageInfixe(a->fd);
		printf("%d ",a->val);
		affichageInfixe(a->fg);
	}
}


void detruitArbre(arbre a){
	if(!arbreEstVide(a)){
		detruitArbre(a->fd);
		detruitArbre(a->fg);
		free(a);
	}
}


/*
int main() {
	arbre a = creeArbreVide();
	a = ajoutElem(a,50);
	a = ajoutElem(a,20);
	a = ajoutElem(a,33);
	a = ajoutElem(a,15);
	a = ajoutElem(a,90);
	a = ajoutElem(a,200);
	a = ajoutElem(a,66);
	affichageInfixe(a);
	printf("longeur: %d \n",longeurArbre(a));
	printf("nombre d'element: %d \n",nombreElements(a));
	a = suppElem(a,50);
	printf("nombre d'element: %d",nombreElements(a));
	printf("\n");
	affichageInfixe(a);
	printf("\n");
	if(trouve(a,90)){
		printf("wiouuuuuuuuuuuuuu \n");
	}
	if(!trouve(a,50)){
		printf("yeahhhhhhhhhhhhhhhh \n");
	}
}

*/
