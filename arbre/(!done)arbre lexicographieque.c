#include <stdio.h>
#include <stdlib.h>

typedef struct Arbre{
	char existe = '-';
	struct Arbre* a = NULL;
	struct Arbre* b = NULL;
	struct Arbre* c = NULL;
	struct Arbre* d = NULL;
	struct Arbre* e = NULL;
	struct Arbre* f = NULL;
	struct Arbre* g = NULL;
	struct Arbre* h = NULL;
	struct Arbre* i = NULL;
	struct Arbre* j = NULL;
	struct Arbre* k = NULL;
	struct Arbre* l = NULL;
	struct Arbre* m = NULL;
	struct Arbre* n = NULL;
	struct Arbre* o = NULL;
	struct Arbre* p = NULL;
	struct Arbre* q = NULL;
	struct Arbre* r = NULL;
	struct Arbre* s = NULL;
	struct Arbre* t = NULL;
	struct Arbre* u = NULL;
	struct Arbre* v = NULL;
	struct Arbre* w = NULL;
	struct Arbre* x = NULL;
	struct Arbre* y = NULL;
	struct Arbre* z = NULL;
}Arbre;

typedef Arbre* arbre;

char arbreEstVide(arbre A){
	if(A==NULL){
		return 1 ;
	}else{
		return 0;
	}
}

arbre creeArbreVide(){
	return NULL;
}

void ajoutElem(arbre* A, char s[]){
	
	if(arbreEstVide(*A)){
		printf("found an empty tree!  \n");
		arbre nvArb = creeArbreVide() ;
		if(!(nvArb =(arbre) malloc(sizeof(Arbre)))){
			printf("erreur d'allocation ");
			exit(0);
		}
		*A = nvArb;
	}
	printf("done with it! \n");
	
	arbre courant = *A;
	int i= 0;
	while(s[i] != '\0'){
		printf("didn't reach end of string yet! \n");
		switch(s[i]) {
			case 'a' :{
				if(arbreEstVide(courant->a)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->a = nvSArb;
				}
				courant = courant->a;
				i++;
				break;
			}
			case 'b' :{
				if(arbreEstVide(courant->b)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->b = nvSArb;
				}
				courant = courant->b;
				i++;
				break;
			}
			case 'c' :{
				if(arbreEstVide(courant->c)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->c = nvSArb;
				}
				courant = courant->c;
				i++;
				break;
			}
			case 'd' :{
				if(arbreEstVide(courant->d)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->d = nvSArb;
				}
				courant = courant->d;
				i++;
				break;
			}
			case 'e' :{
				printf("found a 'e' !! jaw! \n");
				if(arbreEstVide(courant->e)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->e = nvSArb;
				}
				courant = courant->e;
				i++;
				break;
			}
			case 'f' :{
				if(arbreEstVide(courant->f)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->f = nvSArb;
				}
				courant = courant->f;
				i++;
				break;
			}
			case 'g' :{
				if(arbreEstVide(courant->g)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->g = nvSArb;
				}
				courant = courant->g;
				i++;
				break;
			}
			case 'h' :{
				if(arbreEstVide(courant->h)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->h = nvSArb;
				}
				courant = courant->h;
				i++;
				break;
			}
			case 'i' :{
				if(arbreEstVide(courant->i)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->i = nvSArb;
				}
				courant = courant->i;
				i++;
				break;
			}
			case 'j' :{
				if(arbreEstVide(courant->j)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->j = nvSArb;
				}
				courant = courant->j;
				i++;
				break;
			}
			case 'k' :{
				if(arbreEstVide(courant->k)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->k = nvSArb;
				}
				courant = courant->k;
				i++;
				break;
			}
			case 'l' :{
				if(arbreEstVide(courant->l)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->l = nvSArb;
				}
				courant = courant->l;
				i++;
				break;
			}
			case 'm' :{
				if(arbreEstVide(courant->m)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->m = nvSArb;
				}
				courant = courant->m;
				i++;
				break;
			}
			case 'n' :{
				if(arbreEstVide(courant->n)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->n = nvSArb;
				}
				courant = courant->n;
				i++;
				break;
			}
			case 'o' :{
				if(arbreEstVide(courant->o)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->o = nvSArb;
				}
				courant = courant->o;
				i++;
				break;
			}
			case 'p' :{
				if(arbreEstVide(courant->p)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->p = nvSArb;
				}
				courant = courant->p;
				i++;
				break;
			}
			case 'q' :{
				if(arbreEstVide(courant->q)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->q = nvSArb;
				}
				courant = courant->q;
				i++;
				break;
			}
			case 'r' :{
				if(arbreEstVide(courant->r)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->r = nvSArb;
				}
				courant = courant->r;
				i++;
				break;
			}
			case 's' :{
				printf("found a 's' !! jaw! \n");
				if(arbreEstVide(courant->s)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->s = nvSArb;
				}
				courant = courant->s;
				i++;
				break;
			}
			case 't' :{
				printf("found a 't' !! jaw! \n");
				if(arbreEstVide(courant->t)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->t = nvSArb;
				}
				courant = courant->t;
				i++;
				break;
			}
			case 'u' :{
				if(arbreEstVide(courant->u)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->u = nvSArb;
				}
				courant = courant->u;
				i++;
				break;
			}
			case 'v' :{
				if(arbreEstVide(courant->v)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->v = nvSArb;
				}
				courant = courant->v;
				i++;
				break;
			}
			case 'w' :{
				if(arbreEstVide(courant->w)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->w = nvSArb;
				}
				courant = courant->w;
				i++;
				break;
			}
			case 'x' :{
				if(arbreEstVide(courant->x)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->x = nvSArb;
				}
				courant = courant->x;
				i++;
				break;
			}
			case 'y' :{
				if(arbreEstVide(courant->y)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->y = nvSArb;
				}
				courant = courant->y;
				i++;
				break;
			}
			case 'z' :{
				if(arbreEstVide(courant->z)){
					arbre nvSArb = creeArbreVide();
					if(!(nvSArb = (arbre)malloc(sizeof(Arbre)))){
						printf("erreur d'allocation ");
						exit(0);
					}
					courant->z = nvSArb;
				}
				courant = courant->z;
				i++;
				break;
			}
		}
	}
	courant->existe = '*';
}


int main() {
	arbre a =creeArbreVide();
	ajoutElem(&a,"test");
	printf("this is a test! ");
}
