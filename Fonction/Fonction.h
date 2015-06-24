#ifndef Fonction_H
#define Fonction_H

#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string> 
#include "../Carte/Carte.h"
#include "../Score/Score.h"



bool saisi(std::string &saisie);
void espace(size_t);
void tiretbas(size_t);
void effsaisie();
size_t convertirStringEnInt(std::string phrase);
void effacerTerminal();

void lecture(Score tab[10]);
size_t decalage(Score tab[10],const Score &aplacer);
void ecriture(const Score tab[10]);
size_t bestscore(size_t score,std::string a1="\0",std::string a2="\0",std::string a3="\0",std::string a4="\0",std::string a5="\0",std::string a6="\0",std::string a7="\0",std::string a8="\0");

void help();

#endif
