#include "Main.h"
using namespace std;

Main::Main():nbCarte(0){}

Main::Main(const Main &main){
  PlaceCarte p = NULL;
  nbCarte = main.nbCarte;
  for (size_t i = 0; i<13; i++)
    {
      p = main.cartes[i].premier();
      while(p != NULL)
	{
	  cartes[i].ajoutFin(main.cartes[i].valeur(p));
	  p = main.cartes[i].suivant(p);
	}
    }
}

Main& Main::operator=(const Main &main){
  if (this != &main)
    {
      nbCarte = main.nbCarte;
      PlaceCarte p = NULL;
      for (size_t i = 0; i<13; i++)
	{
	  cartes[i].vider();
	  p = main.cartes[i].premier();
	  while(p != NULL)
	    {
	      cartes[i].ajoutFin(main.cartes[i].valeur(p));
	      p = main.cartes[i].suivant(p);
	    }
	}
    }
  return *this;
}

Main::~Main(){}

void Main::vider()
{
  nbCarte = 0;
  for (size_t i = 0; i<13; i++)
    {
      cartes[i].vider();
    }
}


size_t Main::getNbCarte() const { return nbCarte; }
const ListeCarte* Main::getCartes() const { return cartes; }


/*Doit vérifier que la carte n'est pas déjà dans la main*/

bool Main::ajouterCarte(const Carte &carte){
  bool trouve = false;
  PlaceCarte p = cartes[carte.getnumero()-1].premier();

  while(p != NULL && !trouve)
    {
      if (cartes[carte.getnumero()-1].valeur(p) == carte)
	{
	  trouve = true;
	}

      p = cartes[carte.getnumero()-1].suivant(p);
    }
  
  if(!trouve)
    {
      nbCarte ++;
      switch (carte.getenseigne())
	{
	case 1:
	  cartes[carte.getnumero()-1].ajoutDebut(carte);
	  break;

	case 2:
	  if ((cartes[carte.getnumero()-1].premier() != NULL) && (cartes[carte.getnumero()-1].valeur(cartes[carte.getnumero()-1].premier()).getenseigne() == 1))
	    {
	      cartes[carte.getnumero()-1].ajoutApres(cartes[carte.getnumero()-1].premier(), carte);
	    }

	  else
	    {
	      cartes[carte.getnumero()-1].ajoutDebut(carte);
	    }
	  break;

	case 3:
	  if ((cartes[carte.getnumero()-1].dernier() != NULL) && (cartes[carte.getnumero()-1].valeur(cartes[carte.getnumero()-1].dernier()).getenseigne() == 4))
	    {
	      cartes[carte.getnumero()-1].ajoutAvant(cartes[carte.getnumero()-1].dernier(), carte);
	    }

	  else
	    {
	      cartes[carte.getnumero()-1].ajoutFin(carte);
	    }
	  break;

	case 4:
	  cartes[carte.getnumero()-1].ajoutFin(carte);
	  break;
	}
    }
  return !trouve;
}


/*Doit vérifier que la carte est dans la main*/

bool Main::enleverCarte(size_t enseigne, size_t numero)
{
  bool trouve = false;
  PlaceCarte p = cartes[numero-1].premier();
  while(p != NULL && !trouve)
    {

      if (cartes[numero-1].valeur(p).getenseigne() == enseigne)
	{
	  trouve = true;
	}
      else
	{
	  p = cartes[numero-1].suivant(p);
	}
    }

  if (trouve)
    {
      cartes[numero-1].enlever(p);
      nbCarte --;
    }
  return trouve;
}


size_t Main::rechercherCarte(size_t numero) const
{
  size_t nombre = 0;

  if ((numero == 13) || (numero == 0))
    {
      nombre = nbCarte;
    } 

  else
    {
      nombre = cartes[numero].longueur();
    }

  return nombre;
}

Carte Main::pluslongueliste()const
{
  size_t nb=0,nbmax=0,indice=0,indiceact=0;
  Carte carte;
  bool premier=true;
  for(size_t i=0;i<13;i++)
    {
      
      if(premier)
	{
	  if(!cartes[i].estVide())
	    {
	      nbmax++;
	    }
	  else if(nbmax!=0)
	    {
	      premier=false;
	      indiceact=i+1;
	    }
	  else
	    {
	      indice++;
	    }

	}
      else
	{
	  if(!cartes[i].estVide())
	    {
	      nb++;
	    }
	  else
	    {
	      indiceact=i+1;
	      nb=0;
	    }
	}
      if(nb>nbmax)
	{
	  nbmax=nb;
	  indice=indiceact;
	}
      //cout<<"i:"<<i<<"indice :"<<indice<<" indiceact :"<<indiceact<<" nb :"<<nb<<" nbmax :"<<nbmax<<endl;
    }
  // cout<<indice<<endl;
  return cartes[indice].speciale();
}
Carte Main::pluslonguelistespeciale()const
{
size_t nb=0,nbmax=0,indice=0,indiceact=0;
  Carte carte;
  bool premier=true,spe=false;
  ListeCarte liste;
  ListeCarte temp;
  for(size_t i=0;i<13;i++)
    {
      // cout<<"indice :"<<indice<<" indiceact :"<<indiceact<<" nb :"<<nb<<" nbmax :"<<nbmax<<" spe :"<<spe<<endl;
      if(premier)
	{
	  if(!cartes[i].estVide())
	    {
	      nbmax++;
	      liste.ajoutFin(cartes[i].speciale());
	    }
	  else if(nbmax!=0)
	    {
	      premier=false;
	      indiceact=i+1;
	      if(liste.estSpeciale())
		{
		  spe=true;
		}
	      
	    }
	  else
	    {
	      indice++;
	    }
	}
      else
	{
	  if(!cartes[i].estVide())
	    {
	      nb++;
	      temp.ajoutFin(cartes[i].speciale());
	      if(temp.estSpeciale())
		{
		  spe=true;
		}
	    }
	  else
	    {
	      indiceact=i+1;
	      nb=0;
	      temp.vider();
	    }
	}

      if(spe)
	{
	  if((nb>nbmax && temp.estSpeciale())||(temp.estSpeciale() && !liste.estSpeciale()))
	    {
	    nbmax=nb;
	  indice=indiceact;
	  liste.vider();
	  liste=temp;
	    }
	}
      else
	{
      if(nb>nbmax)
	{
	  nbmax=nb;
	  indice=indiceact;
	  liste.vider();
	  liste=temp;
	}
	}
    }
  return liste.valeur(liste.premier());
}
Carte Main::pluslonguelisteroi()const
{
  Carte carte;
  size_t indice=12;
  if(!cartes[indice].estVide())
    {
      while(!cartes[indice].estVide())
	{
	  indice--;
	}
  carte=cartes[indice+1].speciale();
    }
  else
    {
      carte= pluslonguelistespeciale();
    }
  return carte;
}
bool Main::estVide() const { return nbCarte == 0; }

ostream& Main::affiche(ostream &flux, bool joueur) const
{
  PlaceCarte p = NULL;
  size_t i=0;
  size_t fin = 13;
  PlaceCarte psuiv = NULL;
  string phrase = "\0";

  while ((fin>0) && (cartes[fin-1].longueur() == 0))
    {
      fin--;
    }

  if (joueur)
    {
      /*Tout d'abord on nettoie l'espace*/
      
      flux<<"\033[19;14H"<<"\033[1K"<<"\033[18;43H"<<"\033[1K"<<"\033[17;43H"<<"\033[1K"<<"\033[16;43H"<<"\033[1K"<<"\033[15;43H"<<"\033[1K"<<"\033[14;43H"<<"\033[1K";

      /*On revient au debut*/

      flux<<"\033[14;2H"<<"Main : [";             

      for (size_t j = 0; j<13; j++)
	{
	  p = cartes[j].premier();
	  if(p != NULL)
	    {
	      psuiv = cartes[j].suivant(p);
	    }
	  while((p != NULL) && (psuiv != NULL))
	    {
	      if(i!=10){
		flux<<cartes[j].valeur(p);
		if(i!=9){
		  flux << "|";}
		else{
		  flux<<"]";}}
	      if(i==10){
		flux<<endl<<"        [";
		flux<<cartes[j].valeur(p);
		flux << "|";
		;}
	      p = psuiv;
	      psuiv = cartes[j].suivant(psuiv);
	      i++;}
	  if(p != NULL)
	    {
	      if(i!=10){
		flux<<cartes[j].valeur(p);
		if(i!=9)
		  {
		    if(j<(fin-1))
		      {
			flux << "|";
		      }
		  }
		else{
		  flux<<"]";}}
	      if(i==10){
		flux<<endl<<"        [";
		flux<<cartes[j].valeur(p);
		if(j<(fin-1))
		  {
		    flux << "|";
		  }
	      }
	      i++;
	    }
	}
      flux<<"]"<<"\033[21;0H";
    }

  else
    {
      flux<<"[";

      for(size_t i = 0; i<fin; i++)
	{
	  p = cartes[i].premier();
	  while (p!=NULL && cartes[i].suivant(p)!=NULL)
	    {
	      flux<<cartes[i].valeur(p)<<"|";
	      p = cartes[i].suivant(p);
	    }

	  if ((i+1) == fin)
	    {
	      flux<<cartes[i].valeur(p)<<"]";
	    }
	  else if (p != NULL)
	    {
	      flux<<cartes[i].valeur(p)<<"|";
	    }
	}
      if (fin==0)
	{
	  flux<<"]";
	}
    }
  return flux;
}

ostream& operator<<(ostream& os, const Main &main)
{
  return main.affiche(os, true);
}

