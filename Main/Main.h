#ifndef Main_H
#define Main_H

#include "Listecarte.h"
#include <iostream>


typedef class Main Main;

class Main{
 private:
  ListeCarte cartes[13];
  size_t nbCarte;

 public:
  //CONSTRUCTEUR
  Main();
  Main(const Main &main);

  //AFFECTATION
  Main &operator=(const Main &main);

  //DESTRUCTEUR
  ~Main();

  //VIDEUR
  void vider();

  //ACCESSEURS
  size_t getNbCarte() const;
  const ListeCarte* getCartes() const;

  //INSERTION
  bool ajouterCarte(const Carte &carte);
  bool enleverCarte(size_t enseigne, size_t numero);

  //RECHERCHE
  size_t rechercherCarte(size_t numero) const;
  Carte pluslongueliste()const;
  Carte pluslonguelistespeciale()const;
  Carte pluslonguelisteroi()const;
  

  //UTILE
  bool estVide() const;

  //AFFICHAGE
  std::ostream& affiche(std::ostream &flux, bool joueur) const;

};

std::ostream& operator<<(std::ostream &os, const Main& main);


#endif
