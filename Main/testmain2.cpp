#include "Main.h"
#include <string>
#include "../Fonction/Fonction.h"

void affiche();

int main(int argc, char** argv)
{
  bool continuer = true;
  Main main;
  string phrase;
  size_t enseigne = 0;
  size_t numero = 0;
  size_t nbcartes = 0;

  while (continuer)
    {
      affiche();
     
      cout<< main<< "\033[s";
      

      //////////////////////*On demande a l'utilisateur ce qu'il veut faire*/

      phrase = "U";
      while((phrase[0]!='S') && (phrase[0]!='A') && (phrase[0]!='E'))
	{
	  cout << nbcartes << "S:Sortir||A:ajouterCarte||E:enleverCarte : ";
	  cin >> phrase;
	  affiche();
	 
	  cout <<main<< "\033[s";
	}




      /////////////////////*On analyse sa réponse*/
      

      //
      //Si il veut sortir

      if (phrase[0]=='S')
	{
	  continuer = false;
	  effacerTerminal();
	}


      //
      //Si il veut ajouter une carte

      else if (phrase[0]=='A' && (nbcartes < 15))
	{
	  //Quel enseigne de carte veut-il ajouter?
	  
	  enseigne = 0;
	  while ((enseigne < 1) || (enseigne > 4))
	    {
	      cout << "Veuillez entrez une enseigne (1:pique||2:coeur||3:carreau||4:trefle) : ";
	      cin >> phrase;
	      enseigne = convertirStringEnInt(phrase); 
	      affiche(); //efface l'écran et affiche le plateau
	      
	      cout <<main<< "\033[u"; /*je vais à la dernière position enregistrée du curseur*/ 
	    }
	  
	  //Quel numero de carte veut-il ajouter?

	  numero = 0;
	  while ((numero < 1) || (numero > 13))
	    {
	      cout << "Veuillez entrez un numero ({1...10}:{1...10}||11:valet||12:dame||13:roi) : ";
	      cin >> phrase;
	      numero = convertirStringEnInt(phrase); 
	      affiche(); //efface l'écran et affiche le plateau
	   
	      cout <<main<< "\033[u"; /*je vais à la dernière position enregistrée du curseur*/ 
	    }
	  if (main.ajouterCarte(Carte(numero,enseigne)))
	    {
	      nbcartes ++;
	    }
	}


      //
      //Si il veut enlever une carte

      else if (phrase[0]=='E' && (nbcartes > 0))
	{	  
	  //Quel enseigne de carte veut-il enlever?
	  
	  enseigne = 0;
	  while ((enseigne < 1) || (enseigne > 4))
	    {
	      cout << "Veuillez entrez une enseigne (1:pique||2:coeur||3:carreau||4:trefle) : ";
	      cin >> phrase;
	      enseigne = convertirStringEnInt(phrase); 
	      affiche(); //efface l'écran et affiche le plateau
	      
	      cout <<main<< "\033[u"; /*je vais à la dernière position enregistrée du curseur*/ 
	    }
	  
	  //Quel numero de carte veut-il enlever?

	  numero = 0;
	  while ((numero < 1) || (numero > 13))
	    {
	      cout << "Veuillez entrez un numero ({1...10}:{1...10}||11:valet||12:dame||13:roi) : ";
	      cin >> phrase;
	      numero = convertirStringEnInt(phrase); 
	      affiche(); //efface l'écran et affiche le plateau
	      
	      cout << main<<"\033[u"; /*je vais à la dernière position enregistrée du curseur*/ 
	    }

	  if(main.enleverCarte(enseigne,numero))
	    {
	      nbcartes --;
	    }
	}
    }
  return 0;
}


void affiche()
{

  effacerTerminal();

  //On replace le curseur en haut du terminal

  cout << "\033[0;0H";
 
  //affichage ligne par ligne

  espace(43); cout << "|" ; espace(16) ; cout << "|"; espace(11); cout << "|"; espace(7);
  espace(1); tiretbas(41) ; espace(1) ; cout << "|"; espace(1); cout << "Liste joueurs  " << "|"; espace(1); cout << " Nbjetons"; espace(1); cout << "| Nbcrt "; 
  espace(1); cout << "|"; espace(19);cout<<"|";espace(19);cout<<"|";espace(1); cout<<"|"; tiretbas(16) ; cout << "|"; tiretbas(11); cout << "|"; tiretbas(7);
  espace(1); cout << "|";cout<<"                   ";cout<<"|";cout<<"                   ";cout<<"|";espace(1); cout<<"|"; espace(16) ; cout << "|"; espace(11); cout << "|"; espace(7);
  espace(1); cout << "|";espace(9);tiretbas(21);espace(9);cout<<"|"; espace(1); cout << "|";cout<<"                ";cout<<"|";espace(4);cout<<"   ";espace(4);cout<<"|";espace(3);cout<<" ";espace(3);
  espace(1); cout << "|";espace(9);cout<<"|";espace(19);cout<<"|";espace(9);cout<<"|"; espace(1); cout << "|";espace(16) ; cout << "|"; espace(11); cout << "|"; espace(7);
  espace(1); cout << "|";tiretbas(9);cout<<"|";cout<<"                   ";cout<<"|";tiretbas(9);cout<<"|";espace(1); cout << "|";cout<<"                ";cout<<"|";espace(4);cout<<"   ";espace(4);cout<<"|";espace(3);cout<<" ";espace(3);
  espace(1); cout << "|";espace(9);cout<<"|";espace(19);cout<<"|";espace(9);cout<<"|"; espace(1); cout << "|";espace(16) ; cout << "|"; espace(11); cout << "|"; espace(7);
  espace(1); cout << "|";espace(9);cout << "|";tiretbas(19);cout << "|";espace(9);cout<<"|"; espace(1); cout << "|";cout<<"                ";cout<<"|";espace(4);cout<<"   ";espace(4);cout<<"|";espace(3);cout<<" ";espace(3);
  espace(1); cout << "|";cout<<"                   ";cout<<"|";cout<<"                   ";cout<<"|";espace(1); cout<<"|"; espace(16) ; cout << "|"; espace(11); cout << "|"; espace(7);
  espace(1); cout << "|"; espace(19);cout<<"|";espace(19);cout<<"|";espace(1); cout<<"|";cout<<"                ";cout<<"|";espace(4);cout<<"   ";espace(4);cout<<"|";espace(3);cout<<" ";espace(3);
  espace(1);cout << "|"; tiretbas(39) ;cout << "|"; espace(1) ; cout << "|"; espace(16) ; cout << "|"; espace(11); cout << "|"; espace(7);
  espace(43);cout<<"|                ";cout<<"|";espace(4);cout<<"   ";espace(4);cout<<"|";espace(3);cout<<" ";espace(3);
  cout << "\033[14;44H"; cout << "|"; espace(16) ; cout << "|"; espace(11); cout << "|"; espace(7);
  espace(43); cout << "|" ;cout<<"                ";cout<<"|";espace(4);cout<<"   ";espace(4);cout<<"|";espace(3);cout<<" ";espace(3);
  espace(43); cout << "|"; espace(16) ; cout << "|"; espace(11); cout << "|"; espace(7);
  espace(43); cout << "|" ;cout<<"                ";cout<<"|";espace(4);cout<<"   ";espace(4);cout<<"|";espace(3);cout<<" ";espace(3);
  espace(43); cout << "|"; espace(16) ; cout << "|"; espace(11); cout << "|"; espace(7);
  espace(43); cout << "|" ;cout<<"                ";cout<<"|";espace(4);cout<<"   ";espace(4);cout<<"|";espace(3);cout<<" ";espace(3);
  tiretbas(43); cout << "|"; tiretbas(16) ; cout << "|"; tiretbas(11); cout << "|"; tiretbas(7);


  //On positionne le curseur dans l'espace saisie

  cout << "\033[21;0H";

  //FIN

}
