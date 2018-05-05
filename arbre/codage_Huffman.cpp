#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Noeud{
	char c ;
	int count ;
	struct Noeud* fd ;
	struct Noeud* fg ;
}noeud;

/*
	 on peut considerer le noeud comme une liste
	 si on considere le pointeur fd somme le pointeur
	 suiv dans une structure de liste  ordinaire
*/
typedef struct Noeud* liste ;


/*
	 et on peut aussi considerer le structure 
	 noeud comme une arbre binaire
*/
typedef struct Noeud* arbre ;


/*
	on va cree une nouveau type de liste qui va etre un variable global
	et qui va contenir le code de chaque lettre apres la creation de 
	l'arbre. le remplissage de cette liste sera assuré par la fonction
	coderArbre. 
*/

typedef struct block{
	char c ;
	char s[30];
	struct block* suiv;
}block;

typedef struct block* Block ;

//on declare un variable global de type Block
//(c'est un pointeur sur un block)

Block codage = NULL ;


/*
	ajout d'une lettre c avec son chemin correspendant s
	dans la liste de typde Block
*/
void ajoutBlock(Block* b, char c, char s[]){
	Block nvB ;
	if(!(nvB =(Block) malloc(sizeof(block)))){
		printf("erreur d'allocation! ");
		exit(0);
	}
	strcpy(nvB->s,s);
	nvB->c = c ;
	nvB->suiv = NULL;
	
	if(*b == NULL){
		*b = nvB ;
		return ;
	}
	Block courant = *b;
	while(courant->suiv != NULL){
		courant = courant->suiv ;
	}
	courant->suiv = nvB;
}


/*
	enregiste chque lettre avec son chemin correspendant
	de l'arbre dans la liste(variable global)codage
*/
void coderArbre(arbre a, char s[]){
	if(a->c !='#'){
		ajoutBlock(&codage,a->c,s);
	}else{
		char s1[30];
		strcpy(s1,s);
		strcat(s1,"0");
		strcat(s,"1");
		coderArbre(a->fg,s1);
		coderArbre(a->fd,s);
	}
}


//retourne une liste de type liste nulle
liste creeVide(){
	return NULL ;
}

//verifie si une liste est nulle
char estVide(liste a){
	if(a == NULL){
		return 1;
	}else{
		return 0;
	}
}

/*
	ajout d'un caractere dans la liste des frequence
	il y a deux cas:
		-le caractere exite => on augmente sa frequence.
		-le caractere n'existe pas => on cree une nouvelle noeud.
*/
void ajoutChar(liste* a, char c){
	liste courant = *a ;
	while(!estVide(courant)){
		if(courant->c == c){
			courant->count ++ ;
			break ;
		}
		courant = courant->fd ;
	}
	//si on n'a pas trouve le caractere
	if(estVide(courant)){
		//on cree un noeud contenant le caracrere
		liste nvListe = creeVide();
		if(!(nvListe =(liste) malloc(sizeof(noeud)))){
			printf("erreur d'allocation! \n");
			exit(0);
		}
		nvListe->c = c;
		nvListe->count = 1;
		nvListe->fd = NULL;
		nvListe->fg = NULL;
		//on cherche sa position et on le place
		if(estVide(*a)){
			*a=nvListe;
		}else{
			courant= *a;
			while(!estVide(courant->fd)){
				courant = courant->fd ;
			}
			courant->fd = nvListe ;
		}
	}
}

/*
	verfie deux principaux caracteres d'une chaine à coder:
		-elle n'est pas trop petite.
		-elle se termine par le carctere #.
*/
char estValable(char* s){
	if(strlen(s)== 1){
		printf("chaine trop petite! \n");
		return 0 ;
	}
	for(int i=0 ; i<strlen(s); i++){
		if (s[i] == '#'){
			return 1 ;
		}
	}
	printf("usage: chaine_a_coder#  \n");
	return 0 ;
	
}

//on cree la liste de frequences a partir de la chaine s
liste creeListe(char s[]){
	liste L = creeVide();
	int i= 0 ;
	while(s[i] != '#'){
		ajoutChar(&L,s[i]);
		i++;
	} 
	
	return L;
}

//affiche la liste initiale contenant les lettres et leurs frequences
void afficheListe(liste l){
	while(!estVide(l)){
		printf("(%c/%d)->",l->c,l->count);
		l = l->fd ;
	}
}


//on ajout a l'arbre a2 le caractere: c de frequence: count
arbre fusion(char c,int count, arbre a2){
	arbre a1 =creeVide();
	if(!(a1=(arbre)malloc(sizeof(noeud)))){
		printf("erreur d'allocation !");
		exit(0);
	}
	a1->c = c;
	a1->count = count ;
	a1->fd = NULL ;
	a1->fg =NULL;
	if(estVide(a2)){
		return a1;
	}
	arbre nv = creeVide() ;
	if(!(nv = (arbre)malloc(sizeof(noeud)))){
		printf("erreur d'allocation !");
		exit(0);
	}
	nv->c = '#';
	nv->count = (a1->count) + (a2->count);
	if(a1->count > a2->count){
		nv->fd = a1;
		nv->fg = a2;
	}else{
		nv->fd = a2;
		nv->fg = a1;
	}
	
	return nv;
}


//construire à partir la liste de frequences, l'arbre de codage
arbre constrArbre(liste l){
	arbre a= creeVide();
	while(!estVide(l)){
		// printf("ajout de (%c / %d) \n",l->c,l->count);
		/*
			pour eviter des confusions, on envoi a la fonction
			le caractere et sa frequence, elle va cree allouer 
			de l'espace memoire et faire l'enchainement.
		*/
		a = fusion(l->c,l->count,a);
		l = l->fd ;
	}
	return a;
}


//affichage prefixé de l'arbre pour la verification
void affPrefixArbre(arbre a){
	if(!estVide(a)){
		printf("  (%c/%d)  ",a->c,a->count);
		affPrefixArbre(a->fd);
		affPrefixArbre(a->fg);
	}
}

//pour decoder une phrase
void decoder(arbre a, char s[]){
	strcat(s," ");
	arbre courant = a;
	for(int i=0 ; i<strlen(s) ; i++){
		if(s[i]==' '){
			printf("%c",courant->c);
			courant = a ;
		}else if(s[i]=='0'){
			courant = courant->fg ;
		}else if(s[i]=='1'){
			courant = courant->fd;
		}
		
	}
}




//afficher le menu principal
void affMenu(){
	printf("***********************\n");
	printf("*  Codage de Huffman  *\n");
	printf("***********************\n\n");
	printf("1. coder une phrase \n");
	printf("2. decoder une phrase \n");
	printf("3. reset \n");
	printf("4. quitter \n");
}

/* 
	afficher le code d'une chaine a partir
	du liste codage conteant le code de 
	chaque lettre
*/
void coderChaine(char s[]){
	Block courant;
	for(int i=0 ; i<strlen(s);i++){
		courant = codage ;
		while(courant){
			if(courant->c == s[i]){
				printf("%s ",courant->s);
			}
			courant = courant->suiv;
		}
	}
}

//pour liberer Block
void netoyerBlock(Block b){
	if(b == NULL){
		return ;
	}else{
		netoyerBlock(b->suiv);
		free(b);
	}
}

//pour liberer une arbre
void netoyerArbre(arbre a){
	if(a == NULL){
		return ;
	}else{
		netoyerArbre(a->fd);
		netoyerArbre(a->fg);
		free(a);
	}
}


//on va liberer le structures q'on a fait
void myGarbageCollector(arbre a,liste l){
	netoyerArbre(a);
	netoyerArbre(l);
	netoyerBlock(codage);
	codage = NULL ;
}


//une maniere récursive pour coder une lettre
int trouver_coder(arbre a,char ch, int tab[] , int n){
	if(a->c == ch){
		//on a trouve le charactere cherché, donc on affiche le chemin
		for(int i=0 ; i<n ; i++){
			printf("%d",tab[i]);
		}
		return 1;
	}else if(a->c != '#'){
		//on a arrivé a la fin de l'arbre
		return 0;
	}else{
		tab[n] = 0 ;
		n++ ;
		if(!trouver_coder(a->fg,ch,tab,n)){
			tab[n-1] = 1 ;
			trouver_coder(a->fd,ch,tab,n);
		}
	}
}



int main() {
	arbre arb = creeVide();
	liste nv = creeVide();
	debut: system("cls");
	affMenu();
	int choix ;
	do{
		printf("donner votre choix: ");
		scanf("%d",&choix);
	}while(choix >4 || choix<0);
	
	switch (choix){
	    case 1 :{
	    	if(codage != NULL){
	    		printf("il faut fair reset avant pouvoir coder une autre fois! \n");
	    		system("pause");
	    		goto debut ;
			}
	    	fflush(stdin);
			char s1[100] ;
            do{
		        printf("donner la chaine à coder: ");
		        gets(s1);
		        fflush(stdin);
	        }while(!estValable(s1));
	        nv = creeListe(s1);
	        printf("\n");
	        arb = constrArbre(nv);
	        char s2[30] = "";
	        coderArbre(arb, s2);
	        /*
	        	maintenant, on le code de chaque lettre dans la liste
	        	de type Block, et on a la chaine saisie dans s1.
	        	if suffit d'envoyer s1, a la fonction coderChaine
	        	pour afficher le code.
	        */
	        printf("votre chaine codée devient: \n");
	        coderChaine(s1);
	        printf("\n");
	        system("pause");
	        goto debut ;
		    break;
		}
		case 2 :{
			char sd[200];
			fflush(stdin);
			printf("donner la chaine a decoder: ");
			gets(sd);
			decoder(arb,sd);
			printf("\n");
			system("pause");
			goto debut ;
			break;
		}
		case 3 :{
			if(codage == NULL){
				printf("if faut coder une phrase pour pouvoir notoyer! \n");
				system("pause");
				goto debut ;
			}else{
				myGarbageCollector(arb,nv);
				goto debut ;
			}
			break;
		}
		case 4 :{
			if(codage == NULL){
				myGarbageCollector(arb,nv);	
			}
			break;
		}
	}
}

