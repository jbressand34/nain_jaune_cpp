#include "nainjaune.h"
using namespace std;
int main(int argc, char** argv)
{
  bool debugg = false;
  effacerTerminal();
  //gestion de la syntaxe d'appel
  if(argc>2){
    cerr<<"Syntax error"<<endl;
    return 1;
  }
  if(argc==2){
  if((string)argv[1]=="--help")
    {
      help();
      return 0;
    }
  else if((string)argv[1]=="--debug")
    {
      debugg = true;
    }
else{
  cerr<<"Syntax error"<<endl;
    return 1;
  }
    }

  //initialisation d'une partie
  ofstream log("log.txt");
  if(!log){
    cerr<<"Attention probleme d'ouverture";
  }
  log<<"/////////////////////////////////////////////////"<<endl<<endl;
  log<<"---> Debut de la partie !"<<endl<<endl;
  log<<"/////////////////////////////////////////////////"<<endl<<endl<<endl<<endl;
  size_t nbjh=1;
  size_t nbjc=0;
  size_t nbj;
  size_t min = 0;
  size_t max = 0;
  do{
    cout<<"Saisissez le nombre de joueurs humains : {1-8} ";
    cin>>nbjh;
    effacerTerminal();
  }while(nbjh<1 || nbjh>8);
  log<<"---> "<<nbjh<<" joueurs humains rejoignent la partie :"<<endl<<endl;

  if (nbjh>2)
    {
      min = 0;
    }
  else
    {
      min = 3-nbjh;
    }
  max = 8 - nbjh;

  do{
    cout<<"Saisissez le nombre de joueurs cpu : {"<<min<<"-"<<max<<"} ";
    cin>>nbjc;
    effacerTerminal();
  }while(nbjc>max || nbjc<min);

  log<<"---> "<<nbjh<<" joueurs cpu rejoignent la partie :"<<endl<<endl;

  nbj = nbjc + nbjh;

  Joueur *players = new Joueur[nbj];
  bool mm=false;
  string phrase;

  for(size_t i = nbjh; i<nbj; i++)
    {
      players[i].setCpu(true);
    }


  for(size_t i=0;i<nbj;i++)
    {
      do
	{
	  if(mm)
	    {
	      cout<<"Ce pseudo est deja pris !"<<endl;
	    }
	  if (i<nbjh)
	    {
	      cout<<"Saisissez le pseudo du "<<i+1<<" joueur humain : {1-12 caractere(s)}"<<endl;
	    }
	  else
	    {
	      cout<<"Saisissez le pseudo du "<<i+1 - nbjh<<" joueur CPU : {1-12 caractere(s)}"<<endl;
	    }
	  cin>>phrase;
	  for(size_t j=0;j<i;j++)
	    {
	      if(phrase.compare(players[j].getPseudo())==0)
		{
		  phrase="";
		  mm=true;
		}
	    }
	}
      while(phrase.size()>12 || phrase.size()<1);

      players[i].setPseudo(phrase);
      players[i].setNumero(i+1);
      mm=false;
      if (i<nbjh)
	{
	  cout<<"Le joueur humain n°" <<players[i].getNumero()<<" s'appelle desormais "<<players[i].getPseudo()<<endl;
	  log<<"---> "<<players[i].getPseudo()<<" est le joueurhumain n°"<<players[i].getNumero()<<"."<<endl;
	}
      else 
	{
	  cout<<"Le joueur CPU n°" <<players[i].getNumero() - nbjh<<" s'appelle desormais "<<players[i].getPseudo()<<endl;
	  log<<"---> "<<players[i].getPseudo()<<" est le joueurCPU n°"<<players[i].getNumero() - nbjh<<"."<<endl;
	}
    }
  size_t niveau=0;
  do
    {
      cout<<"Choisissez le niveau {1-6} : ";
      cin >> niveau;
    }while(niveau>6 && niveau<1);

 

  log<<"---> Le niveau CPU est : "<<niveau<<"."<<endl;
  cout<<"Vous avez choisi le niveau : "<<niveau;
  cin>>phrase;
  log<<endl;

  size_t nbjetons=0;
  while((nbjetons<15) || (nbjetons>75))
    {
      cout<<"Choisissez le nombre de jetons de depart {15-75} : ";
      cin >> phrase;
      nbjetons = convertirStringEnInt(phrase);
    }

  log<<"---> "<<"Chaque joueur reçoit "<<nbjetons<<" jetons."<<endl<<endl;;
  for(size_t i=0;i<nbj;i++){
    players[i].setNbJetons(nbjetons);}
  
  Plateau plateau(nbj, players, niveau, debugg);

  cout << "On commence la partie ! ";

  srand(time(NULL));

  plateau.jouer(log);
  delete[] players;
  return 0;
}
