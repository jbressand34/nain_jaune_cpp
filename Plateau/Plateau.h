#ifndef Plateau_H
#define Plateau_H

#include<iostream>
#include<string>
#include <ctime>
#include <fstream>
#include"../Joueur/Joueur.h"
#include"../Case/Case.h"
#include "../Fonction/Fonction.h"

typedef class Plateau Plateau;

class Plateau{
  
 private:
  Carte derniereCarteJoue;
  size_t nbjoueur;
  Joueur *joueurs;
  Case *cases;
  Carte *paquet;
  Main talon;
  Main cartesJouees;
  size_t niveau;
  bool debugg;

 public:

  Plateau(); // créer un plateau contenant des cases et un paquet mais pas de joueurs
  Plateau(size_t nbjoueurs, Joueur *joueursJ, size_t niveau, bool debug);
  Plateau(const Plateau &plateau);
  ~Plateau(); //destructeur

  //Operateur affectation

  Plateau &operator=(const Plateau &plateau);

  //Accesseurs
  size_t getNbJoueur()const;
  Joueur* getJoueurs()const;
  Case* getCases()const;
  Carte* getPaquet()const;

  void setJoueurs(size_t nbjoueurJ, Joueur* joueursJ);
  
  //Fonctions

  void afficherPlateau() const; 
  /*affiche le plateau, les cases, les joueurs et remet le curseur dans l'espace saisie*/

  void melangerCartes(); 
  /*mélange les cartes en O(n)*/

  void jouer(std::ofstream& log); 
  //appelle les fonctions suivantes:     

  void tirage1erJoueur(std::ofstream& log); 
  //on determine le 1er joueur

  void distribution(std::ofstream& log); 
  //on distribue les cartes

  void miseDeDepart(std::ofstream& log); 
  //chaque joueur met ses jetons sur les cases 

  void jouerManche(std::ofstream& log); 
  //chaque joueur joue a tour de rôle

  void decompteJetons(std::ofstream& log); 
  //fin de partie remise des jetons

  void fin(std::ofstream& log);
  //fin du jeu, affichage des scores

  void transfererJtJoueurVersCase(size_t nbJetons, Joueur &joueur, Case &cas, std::ofstream& log); 
  //tranfere des jetons du joueur vers la case

  void transfererJtCaseVersJoueur(Joueur &joueur, Case &cas, std::ofstream& log);
  //tranfere des jetons de la case vers le joueur 

  void transfererJtJoueurVersJoueur(size_t nbJetons, Joueur &joueurDon, Joueur &joueurRec, std::ofstream& log); 
  //transfere des jetons du joueurDon vers joueurRec

  void debug(std::ofstream& log);
  //active la fonction debug.

  void afficherCartes() const;
  /*affiche toutes les mains des joueurs, utile pour le mode debug*/
};


#endif
