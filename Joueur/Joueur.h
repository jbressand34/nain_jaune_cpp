#ifndef Joueur_H
#define Joueur_H



#include <iostream>
#include <string> 
#include"../Main/Main.h"
#include "../Fonction/Fonction.h"
#include "../Case/Case.h"


class Joueur{
 public: 
  size_t nbjetons;
  std::string pseudo;
  Main main;
  bool donneur;
  bool continu;
  bool perdu;
  bool cpu;
  size_t numero;

  Joueur();
  Joueur(size_t nbj, std::string pseudo, Main m,bool don, bool cont,bool per,bool cpu,size_t num);


  //Accesseurs

  size_t getNbJetons() const;
  std::string getPseudo() const;
  Main& getMain();
  bool getDonneur() const;
  bool getContinu() const;
  bool getPerdu() const;
  bool getCpu() const;
  size_t getNumero() const;

  void setNbJetons(size_t n);
  void setPseudo(std::string p);
  void setDonneur(bool d);
  void setContinu(bool c);
  void setPerdu(bool p);
  void setCpu(bool c);
  void setNumero(size_t n);


  //Fonctions

  void enleverJetons(size_t quantite);
  void ajouterJetons(size_t quantite);


  /*algo méthode jouerCarte :
   
   0) On regarde si il reste des cartes dans la main du joueur.

       0.1) Si le joueur a des cartes.
            - On passe au 1)

       0.2) Sinon.
            - On retourne en sortie la carte Carte(5,5) pour indiquer que le joueur a gagné la manche.
	    - Fin.

   1) On demande au joueur si il veut jouer une carte ou si il veut passer son tour.

       1.1) Si il veut passer son tour.
            - Soit il ne peut plus jouer de carte et donc on passe au 3)
	    - Soit il peut encore jouer une carte et donc on revient au 1)
       
       1.2) Si il veut jouer une carte.
            - Soit il ne peut plus jouer de carte et donc on revient au 1)
	    - Soit il peut jouer une carte et donc on passe au 2)

   2) On demande au joueur quelle carte veut-il jouer.

       2.1) Soit la carte demandée ne peut être jouée et on revient au 2)

       2.2) Soit la carte peut être jouée alors :
            - On enleve la carte de la main.
	    - On retourne en sortie la carte correspondante.
	    - Fin.

   3) Le joueur ne peut donc pas jouer de carte et décide de passer son tour.

       - On retourne en sortie la carte Carte(0,0) pour indiquer que le joueur ne peut plus jouer mais qu'il a encore des cartes.
       - Fin.

*/

  Carte jouerCarte(size_t numeroreference, size_t niveau, Case* cases, bool debugg);
  Carte jouerCartej(size_t numeroreference, bool debugg);
  Carte jouerCartec(size_t numeroreference, size_t niveau, Case* cases);


  void affiche(std::ostream &os)const;
  
  bool continuer();
};

std::ostream &operator<<( std::ostream &flux, Joueur const& joueur);



#endif
