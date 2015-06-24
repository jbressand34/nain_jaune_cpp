#include "Carte.h"

using namespace std;

  //Constructeur
Carte::Carte() : nom("a"),numero(0),enseigne(0),joue(false){}
Carte::Carte(size_t num, size_t ens): nom("a"), numero(num), enseigne(ens), joue(false){}
Carte::Carte(string nom, size_t numero, size_t enseigne,bool joue) : nom(nom),numero(numero),enseigne(enseigne),joue(joue){}

  //Methode
     //acceseurs
string Carte::getnom() const{
    return nom;}
size_t Carte::getnumero() const{
    return numero;}
size_t Carte::getenseigne() const{
    return enseigne;}
bool Carte::getjoue() const{
    return joue;}
void Carte::setnom(string nom){
    this->nom=nom;}
void Carte::setnumero(size_t numero){
    this->numero=numero;}
void Carte::setenseigne(size_t enseigne){
    this->enseigne=enseigne;}
void Carte::setjoue(bool joue){
    this->joue=joue;}

int Carte::comparercarte(const Carte &carteacompare)const{
  int i = -2;
  if(numero>carteacompare.numero)
      {i = -1;}
  if(numero<carteacompare.numero)
    {i = 1;}
  if(numero==carteacompare.numero){
    if(enseigne==carteacompare.enseigne){   
      i = 0;}
    if(enseigne<carteacompare.enseigne){   
      i = -1;}
    if(enseigne>carteacompare.enseigne){  	
i = 1;}
  }  
  return i;
}


ostream& Carte::affichecarte(std::ostream &flux) const{
  string a;
  string b;

if(enseigne==2)
    a="♥";
if(enseigne==4)
  a="♣";
if(enseigne==3)
  a="♦";
if(enseigne==1)
  a="♠";
if(numero>10){
  if(numero==11){
b="V";}
  if(numero==12){
b="D";}
  if(numero==13){
b="R";}
  if(enseigne==2 || enseigne==3){
    flux<<b<<"\033[0;31m"<<a<<"\033[0m";}
  else{flux<<b<<"\033[0;30m"<<a<<"\033[0m";}}
 else{ 
   if(enseigne==2 || enseigne==3){
     flux<<numero<<"\033[0;31m"<<a<<"\033[0m";}
   else{ 
     flux<<numero<<"\033[0;30m"<<a<<"\033[0m";}} 
 return flux;
}


bool Carte::peutEtreJoue(size_t numeroreference) const
{
  bool peutEtreJouee = false;

  if ((numeroreference == 13) || (numeroreference == 0) )
    {
      peutEtreJouee = true;
    }

  else if ((++numeroreference) == numero)
    {
      peutEtreJouee = true;
    }

  return peutEtreJouee;
}


bool Carte::estSpeciale() const
{
  bool retour = false;

  if ((*this == Carte(7,3)) ||(*this == Carte(10,3)) ||(*this == Carte(11,4)) ||(*this == Carte(12,1)) ||(*this == Carte(13,2)))
    {
      retour = true;
    }

  return retour;
}



bool Carte::operator==(const Carte &carte) const
{
  return ((numero == carte.numero) && (enseigne == carte.enseigne));
}

bool Carte::operator!=(const Carte &carte) const
{
  return !operator==(carte);
}


ostream& operator<<(ostream& os, const Carte &carte)
{
  return carte.affichecarte(os);
}

istream& operator>>(istream& is, Carte& carte){
  string saisie;
  effsaisie();    
  
  
 do {

cout<<"Saisissez carte :";
    cin>>saisie;
    cout<<boolalpha<<saisi(saisie);
 }while(!saisi(saisie));
 effsaisie();
  string numero;
  string enseigne;
  size_t i=1,j;
  while(saisie[i]!='/'){
    i++;}
  for(j=0;j<=i;j++){
    numero.push_back(saisie[j]);}
  for(j=i+1;j<saisie.size();j++){
    enseigne.push_back(saisie[j]);
  }

char* a=&saisie[0];
  switch(enseigne[0]){
  case 'P':
    carte.enseigne=1;
    break;
  case 'C':
    carte.enseigne=3;
    break;
  case'T' :
    carte.enseigne=4;
    break;
  case 'H' :
    carte.enseigne=2;
    break;
  default:
    break;}

  if (saisie[0]=='R' || saisie[0]=='D' || saisie[0]=='V'){
    if(saisie[0]=='R'){
      carte.numero=13;}
    if(saisie[0]=='D'){
      carte.numero=12;
      cout<<"test";}
    if(saisie[0]=='V'){
      carte.numero=11;}}
  else{
    carte.numero=atoi(a)+atoi(a+1)*10;}
  carte.nom="cartesaisie";
  carte.joue=false;

  return is;
}
