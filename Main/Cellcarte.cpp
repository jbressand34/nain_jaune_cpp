#include "Cellcarte.h"

CellCarte::CellCarte():prec(NULL), suiv(NULL){}

CellCarte::CellCarte(TypeValCarte valeur):prec(NULL), val(valeur), suiv(NULL){}


CellCarte* CellCarte::getPrec() const { return prec; }

TypeValCarte& CellCarte::getVal() { return val; } 

CellCarte* CellCarte::getSuiv() const { return suiv; }



void CellCarte::setPrec(CellCarte* precedent){
  prec = precedent;
}

void CellCarte::setVal(TypeValCarte valeur){
  val = valeur;
}

void CellCarte::setSuiv(CellCarte* suivant){
  suiv = suivant;
} 

