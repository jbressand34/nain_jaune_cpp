#ifndef Listecarte_H
#define Listecarte_H

#include "Cellcarte.h"


typedef class ListeCarte ListeCarte;
typedef CellCarte* PlaceCarte;

class ListeCarte{

 private :

  PlaceCarte tete;
  PlaceCarte queue;
  int nbElem;

 public:

  //MASQUAGE STRUCTURE INTERNE
  void setSuivant(PlaceCarte p, PlaceCarte suiv);   /*p->setSuiv(suiv)*/
  void setPrecedent(PlaceCarte p, PlaceCarte prec); /*p->setPrec(prec)*/
  /*On ne manipule plus les méthodes des cellules */


  //ACCESSEURS
    
  PlaceCarte premier() const;   //renvoie tete
  PlaceCarte dernier() const;   //renvoie queue
  PlaceCarte suivant(PlaceCarte p) const; //renvoie p->getSuiv()
  PlaceCarte precedent(PlaceCarte p) const; //renvoie p->getPrec()
  TypeValCarte& valeur(PlaceCarte p) const; //renvoie p->getVal()
  /*cette fonction est const car elle renvoit par référence un élément qui n'est pas constant, bien que la liste soit constante : les pointeurs sur les cellules tête et queue sont constants mais les cellules tête et queue ainsi que les autres cellules ne sont pas constantes*/ 

  
  //FONCTIONS UTILES

  bool estVide() const;  
  size_t longueur() const;
  bool estSpeciale() const;
  Carte speciale() const;//retourne la carte speciale de la liste ou par default la premier;
  
  //INSERTION

  void ajoutAvant(PlaceCarte p, TypeValCarte v); /*créer une cellule contenant une copie de v et l'ajoute à la liste juste avant l'élément p*/
  void ajoutApres(PlaceCarte p, TypeValCarte v); /*de la même manière que la fonction précédente*/
  void ajoutDebut(TypeValCarte v); /*créer une cellule contenant une copie de v et la place en début de liste*/
  void ajoutFin(TypeValCarte v); /*de la même manière que la fonction précédente*/


  //CONSTRUCTEURS 
  ListeCarte();
  ListeCarte(const ListeCarte &liste);  //copie en profondeur

  //DESTRUCTEUR (en profondeur)
  ~ListeCarte();

  /*NETTOYEUR (on détruit le contenu de la liste mais on ne détruit pas la liste) */
  void vider();

  //SUPPRESSION ELEMENT
  void enlever(PlaceCarte p);

  //AFFECTATION (doit être fait en profondeur)
  ListeCarte &operator=(const ListeCarte &liste);
};


#endif
