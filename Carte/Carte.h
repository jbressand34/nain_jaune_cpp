#ifndef Carte_H
#define Carte_H

#include <stdlib.h>
#include <iostream>
#include <string> 
#include "../Fonction/Fonction.h"

class Carte{
 public:
  std::string nom;
  size_t numero;
  size_t enseigne;
  bool joue;

  //Constructeur
  Carte();
  Carte(size_t num, size_t ens);
  Carte(std::string nom, size_t numero, size_t enseigne,bool joue);

  //Methode
     //acceseurs
  std::string getnom() const;
  size_t getnumero() const;
  size_t getenseigne() const;
  bool getjoue() const;
  void setnom(std::string nom);
  void setnumero(size_t numero);
  void setenseigne(size_t enseigne);
  void setjoue(bool joue);
  //void saisi();
  bool peutEtreJoue(size_t numeroreference) const;
  int comparercarte(const Carte &carteacompare) const;
  std::ostream& affichecarte(std::ostream &flux) const;

  //methode utile

  bool estSpeciale() const;

  //Opérateur de comparaison

  bool operator==(const Carte &carte) const;
  bool operator!=(const Carte &carte) const;

};

std::ostream& operator<<(std::ostream& os, const Carte &carte);
std::istream& operator>>(std::istream& is, Carte& carte);
#endif
