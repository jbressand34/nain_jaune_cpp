#include "Score.h"
using namespace std;

Score::Score():pseudo("Anonyme     "),score("0     "),date("18/12/2014 11:26:17"){}
Score::Score(string pseudo, size_t score){
  size_t taille=pseudo.length();
  this->pseudo=pseudo;
  for(size_t i=0;i<12-taille;i++){
    this->pseudo+=" ";
 
  }
  stringstream out;
  out<<score;
  this->score=out.str();
  taille=(this->score.length());
  for(size_t i=0;i<6-taille;i++){
    this->score.push_back(' ');
  }
  time_t temps;
  tm date2;
  time(&temps);
  date2=*localtime(&temps);
  char temp[20];
  strftime(temp,20,"%d/%m/%Y %H:%M:%S",&date2);
  this->date=temp;
}

string Score::getscore()const{

  return this->score;
}

string Score::getpseudo()const{

  return this->pseudo;
}
string Score::getdate()const{

  return this->date;
}
void Score::setscore( const string &score){

  this->score=score;
}

void Score::setpseudo(const string &pseudo){

    this->pseudo=pseudo;
}
void Score::setdate(const string &date){

    this->date=date;
}
void Score:: actualize(){
  time_t temps;
  tm date;
  time(&temps);
  date=*localtime(&temps);
  char temp[20];
  strftime(temp,20,"%d/%m/%Y %H:%M:%S",&date);
  this->date=temp;
}
bool Score::plusgrand(const Score& score1)const{
  string scorea=score1.getscore();
  string scoreb=this->score;
  size_t scoreA=0;
  size_t scoreB=0;
  size_t NbA=0;
  size_t NbB=0;
  size_t tailleA=scorea.length();
 for(size_t i=0;i<tailleA;i++){

    if (scorea[i]!=' ' && scorea[i]!='\0'){
      NbA++;
    }
    if (scoreb[i]!=' ' && scoreb[i]!='\0'){
      NbB++;
    }
  }

  for(size_t i=0;i<tailleA;i++){
    if (scorea[i]!=' ' && scorea[i]!='\0'){
      scoreA+=atoi(&scorea[i])*(NbA-1);
      NbA--;
    }
    if (scoreb[i]!=' ' && scoreb[i]!='\0'){
      scoreB+=atoi(&scoreb[i])*(NbB-1);
      NbB--;
    }
  }
  if(scoreA>scoreB){
    return false;
  }
  return true;
}
bool operator<(Score const& a,Score const& b){
  if(a.plusgrand(b)){
    return false;
      }
  return true;
    }
bool operator>(Score const& a,Score const& b){
  if(a.plusgrand(b)){
    return true;
      }
  return false;
    }
bool operator<=(Score const& a,Score const& b){
  if(a<b || a==b){
    return true;
      }
  return false;
    }
bool operator>=(Score const& a,Score const& b){
  if(a>b || a==b){
    return true;
      }
  return false;
    }
bool operator!=(Score const& a,Score const& b){
  if( a==b){
    return false;
      }
  return true;
    }
bool operator==(Score const& a,Score const& b){
  if(b.getscore()==a.getscore() && b.getpseudo()==a.getpseudo() && b.getdate()==a.getdate()){
    return true;
  }
  return false;
}
