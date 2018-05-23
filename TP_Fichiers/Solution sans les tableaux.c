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

/*
une fonction qui ouvre le fichier nomFichier en mode r+
en faisant les tests nécessaires
*/
FILE* ouvrirFichier(char nomFichier[]){
	FILE* fichier = NULL;
	if((fichier = fopen(nomFichier,"r+"))==NULL){
		printf("impossible de trouver le fichier %s. \n",nomFichier);
		printf("creation de fichier...\n");
		system("pause && cls");
		fichier = fopen(nomFichier,"w+");
		if(fichier == NULL){
			printf("un erreur s'est produit.\n");
			system("pause");
			exit(0);
		}
		printf("tous va bien :)\n\n");	
		return fichier;
	}
	return fichier;
	
}

//fonction qui vérifie si un étudiant existe dans le fichier
//et qui retourne les donnes de cet étudiant s'il existe
etudiant trouveEtudiant(long carte){
	FILE* fichierEtudiants = ouvrirFichier(FICHIER_ETUDIANTS);
	rewind(fichierEtudiants);
	etudiant etu;
	long carteAux ; // va contenir chaque fois la carte prélevée du ficher
	char ligne[100]; // va contenir chaque fois une ligne du fichier
	
	while(fgets(ligne,200,fichierEtudiants)!=NULL){
    sscanf(ligne,"%5ld",&carteAux);
	if (carte == carteAux){
		etu.carteEtudiant = carte;
		strncpy(etu.nom,ligne+7,29);
		strncpy(etu.prenom,ligne+39,29);
		strncpy(etu.section,ligne+71,9);
		fclose(fichierEtudiants);
		return etu;
	}
	}
	fclose(fichierEtudiants);
	return etu;
}

//fonction qui va enregistrer une structure étudiant dans le fichier
void enregisterEtudiant(etudiant etu){
	FILE* fichierEtudiants = ouvrirFichier(FICHIER_ETUDIANTS);
	fseek(fichierEtudiants,0,SEEK_END);
	fprintf(fichierEtudiants,"%5.5ld  %-30.30s  %-30.30s  %-10.10s\n",etu.carteEtudiant,etu.nom,etu.prenom,etu.section);
	fclose(fichierEtudiants);
}



void ajouterUnEtudiant(){
	system("cls");
	//une structure qui contient les donnes de l'étudiant à ajouter :
	etudiant newEtudiant ;
	printf("pour quitter entrer 0\n\n");
	do{
	printf("donner la carte: ");
	scanf("%5ld",&newEtudiant.carteEtudiant);
	fflush(stdin);
	if(newEtudiant.carteEtudiant == 0){
		return ;
	}
	}while(trouveEtudiant(newEtudiant.carteEtudiant).carteEtudiant != 0);
	char auxChar[31];
	printf("donner le nom: ");
	//pour tenir compte des noms composees sans depasser le taille maximal
	gets(auxChar);
	sprintf(newEtudiant.nom,"%-30.30s\0",auxChar);
	printf("donner le prenom: ");
	gets(auxChar);
	sprintf(newEtudiant.prenom,"%-30.30s\0",auxChar);
	printf("donner la section: ");
	gets(auxChar);
	sprintf(newEtudiant.section,"%-10.10s\0",auxChar);
	
	enregisterEtudiant(newEtudiant);

}

//fonction qui vérifie si une matière existe dans le fichier
matiere trouveMatiere(long code){
	FILE* fichierMatiere = ouvrirFichier(FICHIER_MATIERE);
	rewind(fichierMatiere);
	matiere mat;
	long codeAux ; // va contenir chaque fois le code prélevé du ficher
	char ligne[100]; // va contenir chaque fois une ligne du fichier
	while(fgets(ligne,200,fichierMatiere)!=NULL){
    sscanf(ligne,"%5ld",&codeAux);
    fflush(stdin);
	if (code == codeAux){
		mat.codeMatiere = code;
		strncpy(mat.section,ligne+7,9);
		strncpy(mat.intitileMatiere,ligne+19,29);
		sscanf(ligne+51,"%5f",&mat.cofficient);
		fflush(stdin);
		fclose(fichierMatiere);
		return mat;
	}
	}
	fclose(fichierMatiere);
	return mat;
}

//fonction qui va enregistrer une structure matière dans le fichier
void enregisterMatiere(matiere mat){
	FILE* fichierMatiere = ouvrirFichier(FICHIER_MATIERE);
	fseek(fichierMatiere,0,SEEK_END);
	fprintf(fichierMatiere,"%5.5ld  %-10.10s  %-30.30s  %5f\n",mat.codeMatiere,mat.section,mat.intitileMatiere,mat.cofficient);
	fclose(fichierMatiere);
}

void ajouterUneMatiere(){
	system("cls");
	//une structure qui contient les donnes de la matière a ajouter:
	matiere newMatiere ;
	printf("pour quitter entrer 0\n");
	do{
	printf("donner le code matiere: ");
	scanf("%5ld",&newMatiere.codeMatiere);
	fflush(stdin);
	if(newMatiere.codeMatiere == 0){
		return ;
	}
	}while(trouveMatiere(newMatiere.codeMatiere).codeMatiere != 0);
	char auxChar[30];
	printf("donner la section: ");
	gets(auxChar);
	sprintf(newMatiere.section,"%-10.10s\0",auxChar);
	printf("donner l'intitule matiere: ");
	gets(auxChar);
	sprintf(newMatiere.intitileMatiere,"%-30.30s\0",auxChar);
	printf("donner le coeficient: ");
	scanf("%5f",&newMatiere.cofficient);
	fflush(stdin);
	
	enregisterMatiere(newMatiere);
}

/*
cette fonction ne ferme pas le fichier après avoir trouver 
la note, pour faciliter la modification du note:
on doit donc avoir le curseur au position du note trouve
après la recherche
*/
notes trouveNote(notes nt, FILE* fichier){
	rewind(fichier);
	long carteAux ; // va contenir chaque fois la carte prélevée du fichier
	long codeAux ; // va contenir chaque fois le code prélevé du ficher
	char ligne[100]; // va contenir chaque fois une ligne du fichier
	
	while(fgets(ligne,200,fichier)!=NULL){
    sscanf(ligne,"%5ld",&carteAux);
    fflush(stdin);
	if (nt.carteEtudiant == carteAux){
		sscanf(ligne+7,"%5ld",&codeAux);
		fflush(stdin);
		if(nt.codeMatiere == codeAux){
			sscanf(ligne+14,"%5f",&nt.note);
			fflush(stdin);
			return nt ; 
		    }
     	}
	}
	notes noteVide ;
	return noteVide;
}

int notePossible(notes newNote){
	etudiant etu = trouveEtudiant(newNote.carteEtudiant);
	matiere mat = trouveMatiere(newNote.codeMatiere);
	if(newNote.note<0 || newNote.note>20){
		printf("la note doit etre dans l'intervalle [0,20]\n");
		return(0);
	}
	if(etu.carteEtudiant == 0){
		printf("etudiant non trouve! \n\n");
		return(0);
	}
	if(mat.codeMatiere == 0){
		printf("matiere non trouvee! \n\n");
		return(0);
	}
	if(strcmp(mat.section,etu.section)!= 0 ){
		printf("sections incompatibles! \n\n");
		return(0);
	}
	FILE* fichierNotes = ouvrirFichier(FICHIER_NOTES);; 
	if (trouveNote(newNote,fichierNotes).carteEtudiant != 0){
		printf("note deja attribuee! (note = %f)\n",trouveNote(newNote,fichierNotes).note);
		printf("il est possible de modifier la note en choisissant 5 dans le Menu Principal\n\n");
		fclose(fichierNotes);
		return(0);
	}
	return(1);
}

void ajouterUneNote(){
	system("cls");
	notes newNote ;
	printf("pour quitter entrer  0 \n");
	do{
		printf("donner la carte etudiant: ");
		scanf("%5ld",&newNote.carteEtudiant);
		fflush(stdin);
		if(newNote.carteEtudiant == 0){
			return ; 
		}
		printf("donner le code matiere: ");
		scanf("%5ld",&newNote.codeMatiere);
		fflush(stdin);
		printf("donner la note: ");
		scanf("%f",&newNote.note);
		fflush(stdin);
	}while(!notePossible(newNote));
	FILE* fichierNotes = ouvrirFichier(FICHIER_NOTES);
	fseek(fichierNotes,0,SEEK_END);
	fprintf(fichierNotes,"%5ld  %5ld  %-2.3f\n",newNote.carteEtudiant,newNote.codeMatiere,newNote.note);
	printf("note attribuee avec succes! \n");
	fclose(fichierNotes);	
}

//fonction qui retourne la moyenne de l'étudiant à partir de son carte
float trouveMoy(long carte){
	int trouve = 0; // un booléen qui vérifie si on a au moins une note
	long code ;
	float sommeNote=0, sommeCoef=0;
	char carteChar[6], codeChar[6],ligne[20];
	ltoa(carte,carteChar,10);
	FILE* fichierNotes = ouvrirFichier(FICHIER_NOTES);
	rewind(fichierNotes);
	while(fgets(ligne,20,fichierNotes)!=NULL){
		//lorsque on trouve une ligne qui contient la carte de l'étudiant
		if(strncmp(carteChar,ligne,5)==0){
			trouve = 1;
			//on cherche le coefficient de la matière et on l'ajout a sommeCoef
			strncpy(codeChar,ligne+7,5);
			code = atol(codeChar);
			sommeCoef += trouveMatiere(code).cofficient;
			//puis on ajoute la note attribuée à sommeNote
			sommeNote += atof(ligne+14)*trouveMatiere(code).cofficient;
		}
	}
	fclose(fichierNotes);
	if(trouve == 0){
		return (-1);
	}
	//pour obtenir la moyenne on divise sommeNote par sommeCoef
	return (sommeNote/sommeCoef);
}

void moyenneEtudiant(){
	long carte ;
	system("cls");
	printf("pour quitter entrer 0 \n\n");
	do{
		printf("donner la carte etudiant: ");
		scanf("%ld",&carte);
		fflush(stdin);
		if(carte == 0){
			return ;
		}
	}while(trouveEtudiant(carte).carteEtudiant == 0);
	if(trouveMoy(carte) == -1){
		printf("l'etudiant %ld n'a au aucune note \n",carte);
	}else{
	printf("la moyenne de l'etudiant %ld est : %f \n",carte,trouveMoy(carte));
	}
}

void miseAJourNote(){
	notes noteModifier ;
	system("cls");
	printf("pour quitter enter 0. \n\n");
	FILE* fichierNote = ouvrirFichier(FICHIER_NOTES); ; 
	do{
		printf("donner la carte etudiant: ");
		scanf("%5ld",&noteModifier.carteEtudiant);
		fflush(stdin);
		printf("donner le code matiere: ");
		scanf("%5ld",&noteModifier.codeMatiere);
		fflush(stdin);
		/*
		il est suffisant de vérifier l'existence de l'étudiant
		et matière dans le fichier notes.txt car on a vérifier 
		l'existence de ces derniers lors de l'ajout de note
		*/
	}while(trouveNote(noteModifier, fichierNote).carteEtudiant == 0);
	char ligne[20];
	fseek(fichierNote,-8,SEEK_CUR);
	do{
		printf("donner la nouvelle note: ");
		scanf("%5f",&noteModifier.note);
		fflush(stdin);
	}while(noteModifier.note<0 || noteModifier.note>20);
	fprintf(fichierNote,"%-2.3f",noteModifier.note);
	fclose(fichierNote);
}

void bulletinNotes(){
	long carteEtu ;
	system("cls");
	printf("enter 0 pour quitter. \n\n");
	do{
		printf("donner la carte etudiant: ");
		scanf("%ld",&carteEtu);
		fflush(stdin);
		if(carteEtu == 0){
			return ;
		}
	}while(trouveEtudiant(carteEtu).carteEtudiant == 0);
	printf("\nCarte Etudiant   : %ld\n",carteEtu);
	printf("Nom Etudiant     : %s\n",trouveEtudiant(carteEtu).nom);
	printf("Prenom Etudiant  : %s\n",trouveEtudiant(carteEtu).prenom);
	printf("Section Etudiant : %s\n",trouveEtudiant(carteEtu).section);
	//il faut verifier si l'etudiant a un moyenne
	if(trouveMoy(carteEtu) == -1){
		printf("Moyenne Generale : Impossible de Calculer\n\n");
		system("pause");
		return ;
	}
	printf("Moyenne Generale : %3.2f\n\n",trouveMoy(carteEtu));
	printf("\t Matiere\t\t\tNote \t Coefficient \t Total \n\n");
	FILE* fichierNotes = ouvrirFichier(FICHIER_NOTES);
	char ligne[20],carteChar[6],auxChar[6];
	float note ;
	ltoa(carteEtu,carteChar,10); 
	// carte étudiant mais de type char* pour pouvoir utiliser la fonction strcmp
	while(fgets(ligne,20,fichierNotes) != NULL){
		/*si on trouve une note associée a l'étudiant on cherche 
		les information correspondant au matière et on l'affiche*/
		if(strncmp(carteChar,ligne,5)==0){
			strncpy(auxChar,ligne+7,5);
			printf("\t%30.30s  ",trouveMatiere(atol(auxChar)).intitileMatiere);
			note = atof(ligne +14);
			printf("%2.3f \t",note);
			printf("    %2.3f",trouveMatiere(atol(auxChar)).cofficient);
			printf("\t %2.3f\n",note*trouveMatiere(atol(auxChar)).cofficient);
		}
	}
	printf("\n");
}
