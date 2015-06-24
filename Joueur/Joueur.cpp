#include"Joueur.h"
using namespace std;

Joueur:: Joueur() : nbjetons(100),pseudo("anonyme"),main(Main()),donneur(false),continu(true),perdu(false),cpu(false),numero(0){}
Joueur:: Joueur(size_t nbj, string pseu, Main m,bool don, bool cont,bool per,bool cpu,size_t num) : nbjetons(nbj),pseudo(pseu),main(m),donneur(don),continu(cont),perdu(per),cpu(cpu),numero(num){}



//Accesseurs
//en lecture
size_t Joueur::getNbJetons() const { return nbjetons; }
string Joueur::getPseudo() const { return pseudo; }
Main& Joueur::getMain() { return main; }
bool Joueur::getDonneur() const { return donneur; }
bool Joueur::getContinu() const { return continu; }
bool Joueur::getPerdu() const { return perdu;}
bool Joueur::getCpu() const { return cpu;}
size_t Joueur::getNumero() const { return numero; }

//en écriture
void Joueur::setNbJetons(size_t n) { nbjetons = n; }
void Joueur::setPseudo(string p) { pseudo = p; } 
void Joueur::setDonneur(bool d) { donneur = d; }
void Joueur::setContinu(bool c) { continu = c; }
void Joueur::setPerdu(bool p) { perdu = p; }
void Joueur::setCpu(bool c) { cpu = c; }
void Joueur::setNumero(size_t n) { numero = n; } 


void Joueur::enleverJetons(size_t quantite){
  nbjetons=nbjetons-quantite;
}
void Joueur:: ajouterJetons(size_t quantite){
  nbjetons=nbjetons+quantite;
}
void Joueur:: affiche(ostream &os)const{
  os<<"\033[5;46H";
  for(size_t i=1;i<numero;i++)
    {os<<"\033[2B";}
  os<<"\033[K";
  os<<pseudo<<"\033[100D"<<"\033[58C"<<" "<<" |    "<<nbjetons<<"\033[100D"<<"\033[72C"<<"|   "<<main.getNbCarte()<<endl;
  
  if (donneur == true)
    {
      os <<"\033[1A\033[100D\033[59C" << "D";
    }

  else if (perdu == true)
    {
      os <<"\033[1A\033[100D\033[58C" << "X";
    }

  else if (continu == false)
    {
      os <<"\033[1A\033[100D\033[58C" << "/";
    }

  os <<"\033[21;0H";
}

  
bool Joueur:: continuer(){

  char a='p';
  cout << "\033[21;0H";

  /*On place une étoile à côté du pseudo du joueur*/
  cout<<"\033[5;58H";
  
  for(size_t i=1;i<numero;i++)
    {cout<<"\033[2B";}
  
  cout << "*" ;
  cout << "\033[21;0H";

  if (!cpu)
    {
      while(a!='o' && a!='n')
	{
	  cout << pseudo <<" : voulez vous continuez? oui[o] non[n]";
	  cin>>a;
	  effsaisie();
	  if (a=='o')
	    { continu=true;}
	  if(a=='n')
	    { continu=false;}
	}
    }

  else
    {
      continu=true;
    }

  affiche(cout);
  return continu;
}



//Voir algo dans Joueur.h
Carte Joueur::jouerCarte(size_t numeroreference, size_t niveau, Case* cases, bool debugg)
{ 
  Carte carte;
  string phrase = "\0";

// On affiche l'étoile à côté du pseudo du joueur

  cout<<"\033[5;58H";

  for(size_t i=1;i<numero;i++)
    {cout<<"\033[2B";}

  cout << "*" ;

  if (!cpu)
    {
      cout << main; /*affiche la main du joueur et positionne le curseur dans l'espace saisie*/
    }
  else
    {
      effsaisie();
    }

  if (main.estVide())
    {
      carte = Carte(5,5);
      cout<<pseudo<<" : Je n'ai plus de carte, j'ai gagné !"<<endl;
      cin>>phrase;
      effsaisie();
    }
  
  else
    {
      if(cpu){
	carte = jouerCartec(numeroreference, niveau, cases);
	  }
      else{
	carte = jouerCartej(numeroreference, debugg);
	  }
    }

  if (carte == Carte(0,0))
    {
      cout<<pseudo<<" : sans ";
      if (numeroreference > 9)
	{
	  switch(numeroreference)
	    {
	    case 10:
	      cout<<"valet."<<endl;
	      break;
	    case 11:
	      cout<<"dame."<<endl;
	      break;
	    case 12:
	      cout<<"roi."<<endl;
	      break;
	    }
	}
      else
	{
	  cout<<numeroreference+1<<"."<<endl;
	}
      cin>>phrase;
      effsaisie();
    }

  else if(carte != Carte(5,5)) 
    {

      if (carte == Carte(7,3))
	{
	  if(!cpu)
	    {
	      cout<<"On prend les jetons ? (O/n)"<<endl;
	      cin>>phrase;
	      effsaisie();
	      if((phrase.size() == 1) && (phrase[0]=='O'))
		{
		  carte.setjoue(true);
		  cout<<pseudo<<" : nainjaune qui gagne."<<endl;
		  cin>>phrase;
		  effsaisie();
		}
	      else
		{
		  carte.setjoue(false);
		  cout<<pseudo<<" : je joue la carte "<<carte<<" (oh zut j'ai oublié de prendre les jetons !). "<<endl;
		  cin>>phrase;
		  effsaisie();
		}
	    }

	  else
	    {
	      carte.setjoue(true);
	      cout<<pseudo<<" : nainjaune qui gagne."<<endl;
	      cin>>phrase;
	      effsaisie();
	    }
	}


      else if(carte == Carte(10,3))
	{
	  if(!cpu)
	    {
	      cout<<"On prend les jetons ? (O/n)"<<endl;
	      cin>>phrase;
	      effsaisie();
	      if((phrase.size() == 1) && (phrase[0]=='O'))
		{
		  carte.setjoue(true);
		  cout<<pseudo<<" : 10 qui gagne."<<endl;
		  cin>>phrase;
		  effsaisie();
		}
	      else
		{
		  carte.setjoue(false);
		  cout<<pseudo<<" : je joue la carte "<<carte<<" (oh mince j'ai oublié de prendre les jetons !). "<<endl;
		  cin>>phrase;
		  effsaisie();
		}
	    }

	  else
	    {
	      carte.setjoue(true);
	      cout<<pseudo<<" : 10 qui gagne. "<<endl;
	      cin>>phrase;
	      effsaisie();
	    }
	}


      else if(carte == Carte(11,4))
	{
	  if (!cpu)
	    {
	      cout<<"On prend les jetons ? (O/n)"<<endl;
	      cin>>phrase;
	      effsaisie();
	      if((phrase.size() == 1) && (phrase[0]=='O'))
		{
		  carte.setjoue(true);
		  cout<<pseudo<<" : valet qui gagne."<<endl;
		  cin>>phrase;
		  effsaisie();
		}
	      else
		{
		  carte.setjoue(false);
		  cout<<pseudo<<" : je joue la carte "<<carte<<" (oh zut j'ai oublié de prendre les jetons !). "<<endl;
		  cin>>phrase;
		  effsaisie();
		}
	    }
	  else
	    {
	      carte.setjoue(true);
	      cout<<pseudo<<" : valet qui gagne."<<endl;
	      cin>>phrase;
	      effsaisie();
	    }
	}


      else if(carte == Carte(12,1))
	{
	  if(!cpu)
	    {
	      cout<<"On prend les jetons ? (O/n)"<<endl;
	      cin>>phrase;
	      effsaisie();
	      if((phrase.size() == 1) && (phrase[0]=='O'))
		{
		  carte.setjoue(true);
		  cout<<pseudo<<" : dame qui gagne."<<endl;
		  cin>>phrase;
		  effsaisie();
		}
	      else
		{
		  carte.setjoue(false);
		  cout<<pseudo<<" : je joue la carte "<<carte<<" (oh zut j'ai oublié de prendre les jetons !). "<<endl;
		  cin>>phrase;
		  effsaisie();
		}
	    }
	  else
	    {
	      carte.setjoue(true);
	      cout<<pseudo<<" : dame qui gagne."<<endl;
	      cin>>phrase;
	      effsaisie();
	    }
	}


      else if(carte == Carte(13,2))
	{
	  if (!cpu)
	    {
	      cout<<"On prend les jetons ? (O/n)"<<endl;
	      cin>>phrase;
	      effsaisie();
	      if((phrase.size() == 1) && (phrase[0]=='O'))
		{
		  carte.setjoue(true);
		  cout<<pseudo<<" : roi qui gagne."<<endl;
		  cin>>phrase;
		  effsaisie();
		}
	      else
		{
		  carte.setjoue(false);
		  cout<<pseudo<<" : je joue la carte "<<carte<<" (oh zut j'ai oublié de prendre les jetons !)."<<endl;
		  cin>>phrase;
		  effsaisie();
		}
	    }
	  else
	    {
	      carte.setjoue(true);
	      cout<<pseudo<<" : roi qui gagne."<<endl;
	      cin>>phrase;
	      effsaisie();
	    }
	}


      else
	{
	  if(cpu)
	    {
	      cout<<pseudo<<" : je joue la carte "<<carte<<"."<<endl;
	      cin>>phrase;
	      effsaisie();
	    }
	}
    }

  return carte;
}

Carte Joueur::jouerCartec(size_t numeroreference, size_t niveau, Case* cases)
{
  Carte carte;
  size_t nb;
  PlaceCarte p = NULL;
  size_t icarte = 0;
  size_t icarte2 = 0;
  size_t nbJetonsMax = 0;

  if(numeroreference!=13 && numeroreference!=0)
    {
      nb= main.rechercherCarte(numeroreference);
      if(nb!=0)
	{
	  switch(niveau)
	    {

	    case 1:
	      carte = main.getCartes()[numeroreference].valeur(main.getCartes()[numeroreference].premier());
	      break;
 
	    default:
	      p = main.getCartes()[numeroreference].premier();
	      while (p!=NULL && !main.getCartes()[numeroreference].valeur(p).estSpeciale())
		{
		  p = main.getCartes()[numeroreference].suivant(p);
		}
	      
	      if(p == NULL)
		{
		  carte = main.getCartes()[numeroreference].valeur(main.getCartes()[numeroreference].premier());
		}

	      else
		{
		  carte = main.getCartes()[numeroreference].valeur(p);		  
		}
	      break;
	    }
	}
      else
	{
	  carte = Carte(0,0);
	}
    }

  else /*Le numero de reference = 0 ou = 13*/
    {
      switch (niveau)
	{
	case 1: /*On prend la premiere carte*/
	  icarte = 0;
	  
	  while(main.getCartes()[icarte].estVide())
	    {
	      icarte++;
	    }

	  carte = main.getCartes()[icarte].valeur(main.getCartes()[icarte].premier());
	  break;

	case 2: /*On prend la premiere carte spéciale, sinon juste la premiere carte*/
	  icarte = 0;

	  /*On parcourt les listes tant que celles-ci ne sont pas spéciales*/

	  while (icarte<13 && !main.getCartes()[icarte].estSpeciale())
	    {
	      icarte++;
	    }

	  if (icarte == 13)
	    {
	      icarte=0;

	      while (main.getCartes()[icarte].estVide())
		{
		  icarte++;
		}

	      carte = main.getCartes()[icarte].valeur(main.getCartes()[icarte].premier());

	    }

	  else
	    {
	      p = main.getCartes()[icarte].premier();

	      while(!main.getCartes()[icarte].valeur(p).estSpeciale())
		{
		  p = main.getCartes()[icarte].suivant(p);
		}

	      carte = main.getCartes()[icarte].valeur(p);
	    }

	  break;

	case 3: /*On prend la carte spéciale *ayant le plus grand nb de jetons ! sinon juste la premiere carte*/
	  icarte = 0;

	  /*On parcourt les listes tant que celles-ci ne sont pas spéciales*/

	  while (icarte2<13)
	    {
	      if (main.getCartes()[icarte2].estSpeciale())
		{
		  if (icarte == 0)
		    {
		      icarte =icarte2;
		      
		      if (icarte == 6)
			{
			  nbJetonsMax = cases[0].getNbJetons();
			}

		      else
			{
			  nbJetonsMax = cases[icarte - 8].getNbJetons();
			}
		    }
		  else
		    {
		      if (cases[icarte2 - 8].getNbJetons() > nbJetonsMax)
			{
			  icarte = icarte2;
			  nbJetonsMax = cases[icarte - 8].getNbJetons();
			}
		    }
		  icarte2++;
		}
	    }

	  if (icarte == 0)
	    {

	      while (main.getCartes()[icarte].estVide())
		{
		  icarte++;
		}

	      carte = main.getCartes()[icarte].valeur(main.getCartes()[icarte].premier());

	    }

	  else
	    {
	      p = main.getCartes()[icarte].premier();

	      while(!main.getCartes()[icarte].valeur(p).estSpeciale())
		{
		  p = main.getCartes()[icarte].suivant(p);
		}

	      carte = main.getCartes()[icarte].valeur(p);
	    }

	  break;
	case 4:
	  carte=main.pluslongueliste();
	  break;
	case 5:
	  carte=main.pluslonguelistespeciale();
	  break;
	case 6:
	  carte=main.pluslonguelisteroi();
	  break;
	}
    }
  if(carte != Carte(0,0))
    {
      main.enleverCarte(carte.getenseigne(),carte.getnumero());
    }
  return carte;
}

Carte Joueur::jouerCartej(size_t numeroreference, bool debugg)
{
  Carte carte;
  string phrase = "U";
  string phrase2;
  bool ajoue = false;


 
  //On est au 1)
  while ((phrase[0]!='J') && (phrase[0]!='S') && (phrase[0]!='D'))
    {
      if(!debugg)
	{
	  cout << pseudo << " J:Jouer une carte||S:Passer son tour : ";
	}
      else
	{
	  cout << pseudo << " J:Jouer une carte||S:Passer son tour||D:Debug : ";
	}
      cin >> phrase;
	  
      //On est au 1.1)
      if (phrase[0]=='S' && (main.rechercherCarte(numeroreference) > 0))
	{
	  phrase="U";
	} 
	  
      //On est au 1.2)
      else if(phrase[0]=='J' && (main.rechercherCarte(numeroreference) == 0))
	{
	  phrase="U";
	}

      else if(phrase[0]=='D')
	{
	  if (debugg)
	    {
	      carte = Carte(6,6);
	    }
	  else
	    {
	      phrase="U";
	    }
	}

      effsaisie();  /*efface le terminal et affiche le plateau et positionne le curseur dans l'espace saisie*/
    }

      
  switch(phrase[0])
    {
	  
    case 'J':  // On est au 2)
	      
	  
      //On demande au joueur quelle carte veut-il jouer?
	      
      ajoue = false;
      while (!ajoue)
	{

	  cin >> carte;	      

	  if ((carte.peutEtreJoue(numeroreference)) && (main.enleverCarte(carte.getenseigne(),carte.getnumero())))
	    {
	      ajoue = true;
	    }
	      
	  else
	    {
	      phrase = "U";
	    }

	}

      break;

    case 'S': // On est au 3)
      carte = Carte(0,0);
      break;

    }

  return carte;
}

ostream &operator<<( ostream &flux,const Joueur & joueur)
{
    joueur.affiche(flux) ;
    return flux;
}
