#include"Case.h"
using namespace std;

void Case:: affiche(ostream &os)const{
  Carte a;
  a.setenseigne(enseigne);
  a.setnumero(numero);
if(numero==13 && enseigne==2){
    os<<"\033[4;18H"<<"\033[1K"<<"\033[4;0H"<<" | ";
    os << a;
    os<<": "<<nbjetons<<"jetons";}
if(numero==10 && enseigne==3){
  os<<"\033[10;18H"<<"\033[1K"<<"\033[10;0H"<<" | ";
  os << a;
  os<<": "<<nbjetons<<"jetons";}
if(numero==12 && enseigne==1){
  os<<"\033[4;23H"<<"\033[0K"<<"\033[4;24H";
  os << a;
  os<<": "<<nbjetons<<"jetons"<<"\033[4;42H"<<"| |                |           |";
      }
if(numero==11 && enseigne==4){
  os<<"\033[10;23H"<<"\033[0K"<<"\033[10;24H";
  os << a;
  os<<": "<<nbjetons<<"jetons"<<"\033[10;42H"<<"| |                |           |";
      }
if(numero==7 && enseigne==3){
  os<<"\033[7;31H"<<"\033[1K"<<"\033[7;0H"<< " |_________|  ";
  os << a;
  os<<": "<<nbjetons<<"jetons";} 

  os<<"\033[21;0H";
}

Case::Case():nbjetons(0),enseigne(5),numero(14){}
Case::Case(size_t enseigne, size_t numero):nbjetons(0),enseigne(enseigne),numero(numero){}

size_t Case::getNbJetons()const{
  return nbjetons;
}

size_t Case::getEnseigne() const{
  return enseigne;
}

size_t Case::getNumero() const{
  return numero;
}

void Case::setNbJetons(size_t nbj){
  nbjetons=nbj;
}

void Case::enleverJetons(size_t nbj){
  if(nbjetons>nbj){
    nbjetons=nbjetons-nbj;
  }
  else{
    nbjetons=0;
  }
}

void Case::ajouterJetons(size_t nbj){
  nbjetons=nbjetons+nbj;
}

ostream &operator<<( ostream &flux, const Case & cas)
{
    cas.affiche(flux) ;
    return flux;
}
