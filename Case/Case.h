//
//  Case.h
//  
//
//  Created by ALIGNAN Alain on 04/11/2014.
//
//

#ifndef _Case_h
#define _Case_h


#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include"../Carte/Carte.h"



class Case{
    public:
    size_t nbjetons; //nombre de jetons sur la case
    size_t enseigne; //Enseigne de la case trefle, pique, coeur, carreau
    size_t numero; //Numero de la case
    
    
//Constructeurs

	Case();
	Case(size_t enseigne , size_t numero);
	
    
//Accesseurs
    
	size_t getNbJetons() const;
	size_t getEnseigne() const;
	size_t getNumero() const;
	void setNbJetons(size_t nbj);
   	void affiche(std::ostream &flux) const;
	void enleverJetons(size_t nbj);
	void ajouterJetons(size_t nbj);
};

std::ostream &operator<<( std::ostream &flux, Case const& cas);
#endif
