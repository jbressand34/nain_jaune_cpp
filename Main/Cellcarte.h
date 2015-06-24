#ifndef Cellcarte_H
#define Cellcarte_H

#include "../Carte/Carte.h"
#define TypeValCarte Carte
#include <iostream>
using namespace std;

typedef class CellCarte CellCarte;
  
class CellCarte{


 private:
  CellCarte* prec;
  TypeValCarte val;
  CellCarte* suiv;

    
    
 public:  
  CellCarte();
  CellCarte(TypeValCarte valeur);
  /*si typeValCarte = Carte, val est affectée à une copie de la carte valeur*/


  //ACCESSEURS EN LECTURE
    
  CellCarte* getPrec() const;
  TypeValCarte& getVal() ;
  /*Pas de const à la fin de la fonction car le compilateur refuse le passage par référence d'un élément constant*/
  CellCarte* getSuiv() const;


  //ACCESSEURS EN ECRITURE
    
  void setPrec(CellCarte* precedent);
  void setVal(TypeValCarte valeur);
  /*si typeValCarte = Carte, on affecte a val une copie de la carte valeur*/
  void setSuiv(CellCarte* suivant); 
  
  
  
  /*pas de constructeur par copie, pas opérateur d'affectation car dans une liste toutes les cellules sont différentes donc copier une cellule n'a pas de sens */

  /*pas de destructeur non plus car le destructeur par défault supprime le contenu de val*/
}; 

#endif
