#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FICHIER_ETUDIANTS "etudiant.txt"
#define FICHIER_MATIERE "matiere.txt"
#define FICHIER_NOTES "notes.txt"

typedef struct{
	long codeMatiere = 0;
	char section[10] = "";
	char intitileMatiere[30] = "";
	float cofficient = 0 ;
}matiere ;

typedef struct{
	long carteEtudiant = 0;
	char nom[30] = "";
	char prenom[30] = "";
	char section[10] = "";
}etudiant;

typedef struct{
	long carteEtudiant = 0;
	long codeMatiere = 0;
	float note = 0; 
}notes;

void afficheMenu(){
	printf("*********************\n");
	printf("* Gestion des notes *\n");
	printf("*********************\n\n");
	printf("1. Ajouter un etudiant \n");
	printf("2. Ajouter une matiere \n");
	printf("3. Ajouter une note \n");
	printf("4. Moyenne etudiant \n");
	printf("5. Mise a jour note \n");
	printf("6. Bulletin des notes \n");
	printf("7. Quitter \n \n");
}

void lireChoix(int* choix){
	do{
		printf("donner votre choix: ");
		scanf("%d",choix);
		fflush(stdin);
	}while(*choix<1 || *choix>7);
}


void ajouterUnEtudiant();
void ajouterUneMatiere();
void ajouterUneNote();
void moyenneEtudiant();
void miseAJourNote();
void bulletinNotes();




int main() {
	int choix ;
	debut : system("cls");
	afficheMenu();
	lireChoix(&choix);
	switch (choix) {
		case 1 :{
			ajouterUnEtudiant();
			system("pause");
			goto debut;
		}
		case 2 :{
			ajouterUneMatiere();
			system("pause");
			goto debut;
		}
		case 3 :{
			ajouterUneNote();
			system("pause");
			goto debut;
		}
		case 4 :{
			moyenneEtudiant();
			system("pause");
			goto debut;
		}
		case 5 :{
			miseAJourNote();
			system("pause");
			goto debut;
		}
		case 6 :{
			bulletinNotes();
			system("pause");
			goto debut;
		}
		case 7 :{
			break;
	}
	printf("\nAu revoir!");
}
}


/*
une fonction qui ouvre le fichier nomFichier en mode r+
en faisant les tests nécessaires
*/
FILE* ouvrirFichier(char* nomFichier) {
	FILE* fichier = NULL;
	if((fichier = fopen(nomFichier,"r+"))==NULL){
		printf("impossible de trouver le fichier %s. \n",nomFichier);
		printf("creation de fichier...\n");
		system("pause && cls");
		fichier = fopen(nomFichier,"w+");
		if(fichier == NULL){
			//dans le cas ous il ne trouve pas la memoire suffesante pour le fichier
			printf("un erreur s'est produit.\n");
			system("pause");
			exit(0);
		}
		printf("tous va bien :)\n\n");	
		return fichier;
	}
	return fichier;
	
}

//fonction qui determine le nombre de ligne dans un fichier
int NBLignes (char* nomFichier){
	FILE* fichier = ouvrirFichier(nomFichier);
	int n = 0 ;
	char ligne[100];
	while(fgets(ligne,200,fichier)!=NULL){
		n ++ ;
	}
	fclose(fichier);
	return n ;
}

/*fonction qui lit le fichier des etudiants et retourne un tableau
contenant les etudints enregistrés et leur nombre*/

void getEtudiants(etudiant* etu, int n){
	FILE* fichierEtudiants = ouvrirFichier(FICHIER_ETUDIANTS);
	//on lit les donnes du fichier
	rewind(fichierEtudiants);
	char ligne[100];
	for(int i=0 ; i< n ;i++){
		fgets(ligne,200,fichierEtudiants);
		sscanf(ligne,"%5ld",&etu[i].carteEtudiant);
		sscanf(ligne+7,"%30s",etu[i].nom);
		sscanf(ligne+39,"%30s",etu[i].prenom);
		sscanf(ligne+71,"%10s",etu[i].section);
	}
	fclose(fichierEtudiants);
}

/*fonction qui lit le fichier des matières et retourne un tableau
contenant les matières enregistrés et leur nombre*/

void getMatieres(matiere* mat, int n){
	FILE* fichierMatieres = ouvrirFichier(FICHIER_MATIERE);
	//on lit les donnes du fichier
	rewind(fichierMatieres);
	char ligne[100];
	for(int i=0 ; i< n ;i++){
		fgets(ligne,200,fichierMatieres);
		sscanf(ligne,"%5ld",&mat[i].codeMatiere);
		sscanf(ligne+7,"%10s",mat[i].section);
		sscanf(ligne+19,"%30s",mat[i].intitileMatiere);
		sscanf(ligne+51,"%5f",&mat[i].cofficient);
	}
	fclose(fichierMatieres);
}

/*fonction qui lit le fichier des notes et retourne un tableau
contenant les notes enregistrés et leur nombre*/

void getNotes(notes* nt, int n){
	FILE* fichierNotes = ouvrirFichier(FICHIER_NOTES);
	//on lit les donnes du fichier
	rewind(fichierNotes);
	char ligne[100];
	for(int i=0 ; i< n ;i++){
		fgets(ligne,200,fichierNotes);
		sscanf(ligne,"%5ld",&nt[i].carteEtudiant);
		sscanf(ligne+7,"%5ld",&nt[i].codeMatiere);
		sscanf(ligne+14,"%5f",&nt[i].note);
	}
	fclose(fichierNotes);
}


//fonction qui enregistre un tableau d'etudiants dans le fichier des etudiants 
void ergEtudiant(etudiant etu[] , int n){
	FILE* fichierEtudiants = fopen(FICHIER_ETUDIANTS, "w+") ;
	for(int i =0 ; i< n ; i++){
		fprintf(fichierEtudiants,"%5.5ld  %-30.30s  %-30.30s  %-10.10s\n",etu[i].carteEtudiant,etu[i].nom,etu[i].prenom,etu[i].section);
	}
	fclose(fichierEtudiants);
}

//fonction qui enregistre un tableau de matiere dans le fichier des matieres 
void ergMatiere(matiere mat[] , int n){
	FILE* fichierMatieres = fopen(FICHIER_MATIERE, "w+") ;
	for(int i =0 ; i< n ; i++){
		fprintf(fichierMatieres,"%5.5ld  %-10.10s  %-30.30s  %5f\n",mat[i].codeMatiere,mat[i].section,mat[i].intitileMatiere,mat[i].cofficient);
	}
	fclose(fichierMatieres);
}

//fonction qui enregistre un tableau de notes dans le fichier des matieres 
void ergNote(notes nt[] , int n){
	FILE* fichierNotes = fopen(FICHIER_NOTES, "w+") ;
	for(int i =0 ; i< n ; i++){
		fprintf(fichierNotes,"%5ld  %5ld  %-2.3f\n",nt[i].carteEtudiant,nt[i].codeMatiere,nt[i].note);
	}
	fclose(fichierNotes);
}

//fonction qui verifie si un etudiant est enregistre dans le tableau
int trouveEtu(etudiant* etu , int n , long carte){
	for(int i= 0; i< n; i++){
		if(etu[i].carteEtudiant == carte){
			return i+1;
		}
	}
	return 0;
}


void ajouterUnEtudiant(){
	int n =NBLignes(FICHIER_ETUDIANTS),newN;
	//newN contient le nombre des etudiants deja enregistres + le nombre d'etudiants a ajouter
	etudiant* etu ;
	system("cls");
	do{
		printf("donner le nombre d'etudiants a ajouter (enter 0 pour quitter): ");	
		scanf("%d",&newN);
		fflush(stdin);
		if(newN == 0){
			return ;
			}
	}while(newN < 0);
	
	// on fait l'allocation de tableau
	etu =(etudiant*) malloc(sizeof(etudiant)*(n+newN));
	getEtudiants(etu, n);
	//on ajout les nouveaux etudiants dans le tableau
	for(int i = n; i<(n+newN) ; i++){
		printf("*** ajout de l'etudiant %d **** \n\n",i-n+1);
		do{
			printf("donner la carte etudiant: ");
			scanf("%5ld",&etu[i].carteEtudiant);
			fflush(stdin);
		//on verifie si le carte etudiant est deja enregistree
		}while(trouveEtu(etu, i , etu[i].carteEtudiant));
		printf("donner le nom: ");
		gets(etu[i].nom);
		printf("donner le prenom: ");
		gets(etu[i].prenom);
		printf("donner la section: ");
		gets(etu[i].section);
	}
	ergEtudiant(etu,n+newN);
	free(etu);
}

//fonction qui verifie si une matiere est enregistre dans le tableau
int trouveMat(matiere* mat , int n , long code){
	for(int i= 0; i< n; i++){
		if(mat[i].codeMatiere == code){
			return i+1;
		}
	}
	return 0;
}

void ajouterUneMatiere(){
	int n =NBLignes(FICHIER_MATIERE),newN;
	//newN contient le nombre des matieres deja enregistres + le nombre de matieres a ajouter
	matiere* mat ;
	system("cls");
	do{
		printf("donner le nombre des matieres a ajouter (enter 0 pour quitter): ");	
		scanf("%d",&newN);
		fflush(stdin);
		if(newN == 0){
			return ;
			}
	}while(newN < 0);
	// on fait l'allocation de tableau
	mat =(matiere*) malloc(sizeof(matiere)*(n+newN));
	getMatieres(mat, n);
	//on ajout les nouveaux matières dans le tableau
	for(int i = n; i<(n+newN) ; i++){
		printf("*** ajout du matiere %d **** \n\n",i-n+1);
		do{
			printf("donner le code matiere: ");
			scanf("%5ld",&mat[i].codeMatiere);
			fflush(stdin);
		//on verifie si le carte etudiant est deja enregistree
		}while(trouveMat(mat, i , mat[i].codeMatiere));
		printf("donner l'intitule matiere: ");
		gets(mat[i].intitileMatiere);
		printf("donner la section: ");
		gets(mat[i].section);
		do{
		printf("donner le coeficient: ");
		scanf("%5f",&mat[i].cofficient);
		fflush(stdin);
		}while(mat[i].cofficient <0);
	}
	ergMatiere(mat,n+newN);
	free(mat);
}

//fonction qui fait les tests necessaires lors de l'ajout d'une note
int notePosssible(notes* nt , int n , notes newNote){
	//on verifie l'intervalle du note
	if(newNote.note<0 || newNote.note > 20){
		printf("note doit etre dans l'intervalle [0,20] \n");
		return 0;
	}
	//on verifie si le note est deja attribuee
	for(int i = 0 ; i<n ; i++){
		if(nt[i].carteEtudiant == newNote.carteEtudiant && nt[i].codeMatiere == newNote.codeMatiere){
			printf("note deja attribuee (note = %3.2f) \n",nt[i].note);
			printf("il est possible de modifier la note en choisissant 5 dans le Menu Principal\n");
			return 0;
		}
	}
	//on doit verifier si la carte etudiant saisit est valable
	etudiant* etu ;
	int nbEtu =NBLignes(FICHIER_ETUDIANTS);
	etu=(etudiant*) malloc(sizeof(etudiant)*nbEtu);
	getEtudiants(etu,nbEtu);
	if(!trouveEtu(etu,nbEtu,newNote.carteEtudiant)){
		printf("etudiant non definit! \n");
		free(etu);
		return 0;
	}
	//on doit verifier si le code matiere saisit est valable
	matiere* mat ;
	int nbMat =NBLignes(FICHIER_MATIERE);
	mat=(matiere*) malloc(sizeof(matiere)*nbMat);
	getMatieres(mat,nbMat);
	if(!trouveMat(mat,nbMat,newNote.codeMatiere)){
		printf("matiere non definit! \n");
		free(mat);
		free(etu);
		return 0;
	}
	//on doit verifier si la section de l'etudiant est compatible avec calle du matiere
	int posEtudiant = trouveEtu(etu,nbEtu,newNote.carteEtudiant) -1 ;
	int posMatiere = trouveMat(mat,nbMat,newNote.codeMatiere) -1 ;
	if(strcmp(etu[posEtudiant].section,mat[posMatiere].section) != 0){
		printf("sections incompatibles! \n");
		free(etu);
		free(mat);
		return 0;
	}
	free(mat);
	free(etu);
	return 1 ;
}

void ajouterUneNote(){
	int n =NBLignes(FICHIER_NOTES),newN;
	//newN contient le nombre des matieres deja enregistres + le nombre de matieres a ajouter
	notes* nt ;
	system("cls");
	do{
		printf("donner le nombre des notes a ajouter (enter 0 pour quitter): ");	
		scanf("%d",&newN);
		fflush(stdin);
		if(newN == 0){
			return ;
			}
	}while(newN < 0);
	// on fait l'allocation de tableau
	nt =(notes*) malloc(sizeof(notes)*(n+newN));
	getNotes(nt, n);
	//on ajout les nouveaux matières dans le tableau
	char auxChar[31];
	for(int i = n; i<(n+newN) ; i++){
		printf("*** ajout du note %d **** \n\n",i-n+1);
		do{
			printf("donner la carte etudiant: ");
			scanf("%5ld",&nt[i].carteEtudiant);
			fflush(stdin);
			printf("donner le code matiere: ");
			scanf("%5ld",&nt[i].codeMatiere);
			fflush(stdin);
			printf("donner le note a attribuer: ");
			scanf("%5f",&nt[i].note);
			fflush(stdin);
		//on verifie si le note a attribuer est possible
		}while(!notePosssible(nt,i,nt[i]));
		printf("note attribuee avec succes! \n");
	}
	ergNote(nt,n+newN);
	free(nt);
}

float calculMoyenne(long carte){
	//on fait l'allocation dynamique des tableaux necessaires
	etudiant* etu ;
	notes* nt ;
	matiere* mat ;
	int nbNotes = NBLignes(FICHIER_NOTES);
	int nbMat = NBLignes(FICHIER_MATIERE);
	nt =(notes*) malloc(sizeof(notes)*nbNotes);
	mat =(matiere*) malloc(sizeof(matiere)*nbMat);
	//on remplit les tableau avec les donnes necessaires
	getMatieres(mat,nbMat);
	getNotes(nt,nbNotes);
	float sommeNotes = 0, sommeCoef = 0 ;
	int i, j;
	//on parcout le tableau des notes
	for(i =0 ; i<nbNotes ; i++){
		//si on trouve un note on ajout le note a sommeNotes
		if (nt[i].carteEtudiant == carte){
			//puis on cherche le coeficient et on l'ajout a sommeCoef
			for(j =0 ; j< nbMat ; j++){
				if(mat[j].codeMatiere == nt[i].codeMatiere){
					sommeCoef += mat[j].cofficient;
					break ;
				}
			}
			sommeNotes += nt[i].note*mat[j].cofficient ;	
		}
	}
	free(nt);
	free(mat);
	//si on n'a pas trouve une note on retourne 0
	if(sommeCoef== 0){
		return 0;
	}
	return sommeNotes/sommeCoef;
}

void moyenneEtudiant(){
	long carte ;
	etudiant* etu ;
	int nbEtu = NBLignes(FICHIER_ETUDIANTS);
	//on fait l'allocation dynamiques du tableau
	etu =(etudiant*) malloc(sizeof(etudiant)*nbEtu);
	//on le remplit par les information
	getEtudiants(etu,nbEtu);
	system("cls");
	printf("***** Calcul du Moyenne ***** \n \n");
	do{
		printf("donner la carte etudiant: ");
		scanf("%ld",&carte);
	}while(!trouveEtu(etu,nbEtu,carte));
	free(etu);
	if(calculMoyenne(carte) == 0){
		printf("acune notes est attribuee a cet etudiant ! \n");
		return ;
	}
	printf("Moyenne de l'etudiant est : %f \n",calculMoyenne(carte));
}


void miseAJourNote(){
	notes newNote ;
	notes* nt ;
	int nbNotes = NBLignes(FICHIER_NOTES), trouve =1,i;
	nt = (notes*) malloc(sizeof(notes)*nbNotes);
	getNotes(nt,nbNotes);
	system("cls");
	printf("*** Mise a jour note etudiant *** \n\n");
	do{
		if(!trouve){
			printf("note non trouvee ! \n\n");
		}
		printf("donner la carte etudiant : ");
		scanf("%5ld",&newNote.carteEtudiant);
		fflush(stdin);
		printf("donner le code matiere: ");
		scanf("%5ld",&newNote.codeMatiere);
		fflush(stdin);
		//on initialise le booleen trouve à faux (=0)
		trouve = 0;
		//puis on cheche dans le tableau si le note existe
		for(i=0 ; i<nbNotes ; i++){
			if(nt[i].carteEtudiant==newNote.carteEtudiant && nt[i].codeMatiere==newNote.codeMatiere){
				trouve = 1;
				break;
			}
		}
	}while(!trouve);
	printf("note trouvee : %2.3f \n",nt[i].note);
	printf("donner la nouvelle note: ");
	scanf("%5f",&nt[i].note);
	ergNote(nt,nbNotes);
	free(nt);
	printf("tous va bien :) \n");
}

void bulletinNotes(){
	//on definit nos tbaleaux et on les remplit
	etudiant* etu ;
	matiere* mat ;
	notes* nt ;
	int nbEtu = NBLignes(FICHIER_ETUDIANTS);
	int nbMat = NBLignes(FICHIER_MATIERE);
	int nbNotes = NBLignes(FICHIER_NOTES);
	etu = (etudiant*) malloc(sizeof(etudiant)*nbEtu);
	mat = (matiere*) malloc(sizeof(matiere)*nbMat);
	nt = (notes*) malloc(sizeof(notes)*nbNotes);
	getEtudiants(etu,nbEtu);
	getMatieres(mat,nbMat);
	getNotes(nt,nbNotes);
	long carte ;
	int varAux;
	system("cls");
	do{
		printf("donner la carte etudiant: ");
		scanf("%ld",&carte);
		fflush(stdin);
		//varAux contient la position de l'etudiant -1 
		varAux = trouveEtu(etu,nbEtu,carte);
	}while(!varAux);
	printf("\nCarte Etudiant  : %ld \n",carte);
	printf("Nom Etudiant    : %s \n",etu[varAux-1].nom);
	printf("Prenom Etudiant : %s \n",etu[varAux-1].prenom);
	printf("Section         : %s \n",etu[varAux-1].section);
	//on doit verifier si l'etudiant a un moyenne
	if(calculMoyenne(carte) == 0){
		printf("Acune note trouvee pour cet etudiant \n");
		return ;
	}
	printf("Moyenne         : %2.3f \n",calculMoyenne(carte));
	
	printf("Matiere                        Note       Coeficient       Total \n\n");
	int i,j ;
	//on parcourt le fichier des notes
	for(i = 0; i<nbNotes ; i++){
		//si on trouve une note pour l'etudiant cherche
		if(nt[i].carteEtudiant == carte){
			/*on cherche dans le tableaux des matiere 
			la matiere qui correspond a cette note*/
			j = trouveMat(mat,nbMat,nt[i].codeMatiere);
			//puis on affiche les donnes demandees
			printf("%-30s",mat[j-1].intitileMatiere);
			printf("%2.3f        ",nt[i].note);
			printf("%2.3f         ",mat[j-1].cofficient);
			printf("%2.3f    \n",(nt[i].note)*(mat[j-1].cofficient));
		}
	}
	free(etu);
	free(mat);
	free(nt);
}
