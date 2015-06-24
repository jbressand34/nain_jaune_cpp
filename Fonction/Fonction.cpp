#include"Fonction.h"
using namespace std;

void espace(size_t n)
{
  for(size_t i =0; i<n ; i++)
    { cout << " ";}
}

void tiretbas(size_t n)
{
  for(size_t i =0; i<n; i++)
    { cout << "_";}
}


void effsaisie(){
  cout<<"\033[24;0H"; cout<<"\033[K";
  cout<<"\033[1A"; cout<<"\033[K";
  cout<<"\033[1A"; cout<<"\033[K";
  cout<<"\033[1A"; cout<<"\033[K";
  cout<<"\033[21;0H";
}



size_t convertirStringEnInt(string phrase)
{
  int base = 1;
  int nb = 0;
  int somme = 0;
  size_t n = phrase.size();
  for(size_t i = 0; i < n; i++)
    {
      nb = phrase[n-1-i] - 48;
      somme += nb*base;
      base *= 10;
    }
  if (somme < 0)
    {
      somme = 0;
    }
  return somme;
}

bool saisi(string &saisie){
  string numero;
  string enseigne;
  size_t j=0;
  bool correct=false;
   
    if(saisie[3]=='\0' || saisie[4]=='\0'){
      if(saisie[2]=='/' || saisie[1]=='/'){
	char*a=&saisie[0];
	for(int i=1;i<10;i++){
	  if(i==atoi(a)){
	    j++;}}
	if (saisie[0]=='R' || saisie[0]=='D' || saisie[0]=='V' || j==1 ||((saisie[0]=='1') && (saisie[1]=='0'))){
	  if((saisie[1]=='0' && saisie[0]=='1')|| (saisie[1]=='/')){
	    if((saisie[1]=='/' && (saisie[2]=='H'||saisie[2]=='T'||saisie[2]=='P'||saisie[2]=='C'))||(saisie[1]=='0'&& saisie[2]=='/')){
	      if((saisie[2]=='/' && (saisie[3]=='H'||saisie[3]=='T'||saisie[3]=='P'||saisie[3]=='C'))||(saisie[2]!='/' && saisie[3]=='\0')){
		correct=true;}}}}}}
  return correct;
}


void effacerTerminal()
{
        //Sys(Reset)
      cout << "\033[100B\033[100D"; // on va en bas a gauche du terminal
      for (size_t i = 0; i<100; i++)
	{
	  cout << "\033[K\033[1A";
	}
      //On a tout supprimé dans le terminal

      //On revient dans saisie

      cout << "\033[0;0H";
}




void lecture(Score tab[10]){
    string ligne;
    string temppseudo;
    string tempdate;
    string tempscore;
    fstream fichier("score.txt",ios::in |ios::out| ios::ate);
  fichier.seekp(0,ios::beg);//retour au debut du fichier
  //on se place au premier score 
  for(size_t i=0;i<9;i++){
    fichier.ignore(numeric_limits<int>::max(),'\n');//on saute une ligne
  }
  for(size_t i=0;i<10;i++){
    ligne="\0";
    getline(fichier,ligne);
    for(size_t j=0;j<12;j++){
      temppseudo.push_back(ligne[j+8]);
    }
    
    for(size_t j=0;j<6;j++){
      tempscore.push_back(ligne[j+23]);
    }
    
    for(size_t j=0;j<19;j++){
      tempdate.push_back(ligne[j+32]);
    }
    
   
    tab[i].setpseudo(temppseudo);
    tab[i].setscore(tempscore);
    tab[i].setdate(tempdate);
    // cout<<tab[i].getpseudo()<<" "<<tab[i].getscore()<<" "<<tab[i].getdate()<<endl;
    //saute 4 lignes
    for(size_t k=0;k<3;k++){
      //cout<<endl;
      fichier.ignore(numeric_limits<int>::max(),'\n');//on saute une ligne
    }
    temppseudo="\0";
    tempscore="\0";
    tempdate="\0";
  }
  fichier.clear();
  fichier.close();
}



size_t decalage(Score tab[10],const Score &aplacer){
  Score temp=aplacer;
  Score passage;
  size_t place;
  for(size_t i=0;i<10;i++){
    if(temp>tab[i]){
      cout<<temp.getscore()<<"est plus grand que "<<tab[i].getscore()<<endl;
      if(temp==aplacer){
	place=i+1;
      }
	passage=tab[i];
	tab[i]=temp;
	temp=passage;
      }
      }
  return place;
  }

void ecriture(const Score tab[10]){
  fstream fichier("score.txt",ios::in |ios::out | ios::ate);
  fichier.seekp(0,ios::beg);//retour au debut du fichier
  //on se place au premier score 
  for(size_t i=0;i<9;i++){
    fichier.ignore(numeric_limits<int>::max(),'\n');//on saute une ligne
  }
  for(size_t i=0;i<10;i++){
    
    if(i==9){
      fichier<<"|  "<<i+1<<" | "<<tab[i].getpseudo()<<" | "<<tab[i].getscore()<<" | "<<tab[i].getdate()<<" |";
      // cout<<"|  "<<i+1<<" | "<<tab[i].getpseudo()<<" | "<<tab[i].getscore()<<" | "<<tab[i].getdate()<<" |"<<endl;
    }
    else{
    fichier<<"|  "<<i+1<<"  | "<<tab[i].getpseudo()<<" | "<<tab[i].getscore()<<" | "<<tab[i].getdate()<<" |";
    //cout<<"|  "<<i+1<<"  | "<<tab[i].getpseudo()<<" | "<<tab[i].getscore()<<" | "<<tab[i].getdate()<<" |"<<endl;
    }

    for(size_t j=0;j<4;j++){
      //cout<<endl;
      fichier.ignore(numeric_limits<int>::max(),'\n');//on saute une ligne
    }
  }
  fichier.clear();
  fichier.close();
}

size_t bestscore(size_t score,string a1,string a2,string a3,string a4,string a5,string a6,string a7, string a8){
  size_t place;
  Score tab[10];
 
  if(a1!="\0"){
    lecture(tab);
 for(size_t i=0;i<10;i++){
   // cout<<tab[i].getpseudo()<<"a un score de "<<tab[i].getscore()<<endl;
  }
 //cout <<endl<<endl<<endl;
    Score temp1=Score(a1,score);
    place=decalage(tab,temp1);
 for(size_t i=0;i<10;i++){
   // cout<<tab[i].getpseudo()<<"a un score de "<<tab[i].getscore()<<endl;
  }
    ecriture(tab);
  }
  if( a2!="\0"){
    lecture(tab);
    Score temp2=Score(a2,score);
    place=decalage(tab,temp2);
    ecriture(tab);
  }
  if( a3!="\0"){
    lecture(tab);
    Score temp3=Score(a3,score);
    place=decalage(tab,temp3);
    ecriture(tab);
  }
  if( a4!="\0"){
    lecture(tab);
    Score temp4=Score(a4,score);
    place=decalage(tab,temp4);
    ecriture(tab);
  }
  if( a5!="\0"){
    lecture(tab);
    Score temp5=Score(a5,score);
    place=decalage(tab,temp5);
    ecriture(tab);
  }
  if( a6!="\0"){
    lecture(tab);
    Score temp6=Score(a6,score);
    place=decalage(tab,temp6);
    ecriture(tab);
  }
  if( a7!="\0"){
    lecture(tab);
    Score temp7=Score(a7,score);
    place=decalage(tab,temp7);
    ecriture(tab);
  }
  if( a8!="\0"){
    lecture(tab);
    Score temp8=Score(a8,score);
    place=decalage(tab,temp8);
    ecriture(tab);
  } 

  return place;
}

void help(){
  ifstream fichier("LisezMoi.txt",ios::in);
  string line;
  if(fichier)
    {
  fichier.seekg(0,ios::beg);
 
  while(getline(fichier,line)){
    cout<<line<<endl;
}
  fichier.clear();
  fichier.close();
}
  else{
    cerr<<"File error"<<endl;
  }
}

 
