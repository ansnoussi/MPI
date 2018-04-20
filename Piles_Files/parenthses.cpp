#include "./Pile-File/pile.cpp"
#include <string.h>

char wrong(char * s){
	Pile p = creePileVide();
	for(int i=0 ;i<strlen(s);i++){
		if(s[i] == '('){
			p= Empiler(p , i+1);
		}else if(s[i] == ')'){
			if(pileEstVide(p)){
				return(i+1);
			}else{
				p = Depiler(p);
			}
		}
	}
	
	
	if(pileEstVide(p)){
		return 0 ;
	}else{
		return getPileTete(p) ;
	}
}

int main(){
	printf("donner une expression arithmetique: ");
	char  string[100];
	gets(string);
	if(wrong(string)){
		printf("l'expression est fausse! \n");
	}else{
		printf("l'expression est correcte \n");
	}
}
