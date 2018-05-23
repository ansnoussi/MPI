

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
