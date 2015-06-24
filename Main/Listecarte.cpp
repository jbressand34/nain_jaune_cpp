#include "Listecarte.h"

//MASQUEURS

void ListeCarte::setSuivant(PlaceCarte p, PlaceCarte suiv){p->setSuiv(suiv);}

void ListeCarte::setPrecedent(PlaceCarte p, PlaceCarte prec){p->setPrec(prec);}


//ACCESSEURS

PlaceCarte ListeCarte::premier() const {return tete;}

PlaceCarte ListeCarte::dernier() const {return queue;}

PlaceCarte ListeCarte::suivant(PlaceCarte p) const {return p->getSuiv();}

PlaceCarte ListeCarte::precedent(PlaceCarte p) const {return p->getPrec();}

TypeValCarte& ListeCarte::valeur(PlaceCarte p) const {return p->getVal();}


//UTILE

bool ListeCarte::estVide() const {return tete==NULL;}

size_t ListeCarte::longueur() const {return nbElem;}

bool ListeCarte::estSpeciale() const
{
  bool retour = false;
  PlaceCarte p = NULL;

  if (nbElem != 0)
    {
      p = premier();

      while (p!=NULL && !valeur(p).estSpeciale())
	{
	  p = suivant(p);
	}

      if (p!=NULL)
	{
	  retour = true;
	}
    }

  return retour;
}
Carte ListeCarte::speciale()const
{
  PlaceCarte p=premier();
  Carte carte= Carte(0,0);
  if(nbElem!=0)
    {
  while(p!=NULL && !valeur(p).estSpeciale())
    {
      p=suivant(p);
    }
  if (p==NULL)
    {
      carte=valeur(premier());
    }
  else
    {
      carte=valeur(p);
    }
    }
  return carte;
}
//INSERTION

void ListeCarte::ajoutAvant(PlaceCarte p, TypeValCarte v)
{
  PlaceCarte place = new CellCarte(v);
  nbElem ++;
  if (p==NULL) //liste vide
    {
      tete = place;
      queue = place;
    }
  else
    {
      if(p==tete)  //1 voisin
	{
	  tete = place;
	  setSuivant(place, p);
	  setPrecedent(p, place);
	}
      else //2 voisins
	{
	  setSuivant(place, p);
	  setPrecedent(place, precedent(p));
	  setSuivant(precedent(p), place);
	  setPrecedent(p, place);
	}
    }
}


void ListeCarte::ajoutApres(PlaceCarte p, TypeValCarte v)
{
  PlaceCarte place = new CellCarte(v);
  nbElem ++;
  if (p==NULL) //liste vide
    {
      tete = place;
      queue = place;
    }
  else
    {
      if(p==queue)  //1 voisin
	{
	  queue = place;
	  setSuivant(p, place);
	  setPrecedent(place, p);
	}
      else //2 voisins
	{
	  setPrecedent(place, p);
	  setSuivant(place, suivant(p));
	  setSuivant(p, place);
	  setPrecedent(suivant(p), place);
	}
    }
}

void ListeCarte::ajoutDebut(TypeValCarte v){ajoutAvant(tete, v);}

void ListeCarte::ajoutFin(TypeValCarte v){ajoutApres(queue, v);}


//CONSTRUCTEURS
		       
ListeCarte::ListeCarte():tete(NULL),queue(NULL),nbElem(0){}

ListeCarte::ListeCarte(const ListeCarte &liste)
{
  tete = NULL;
  queue = NULL;
  nbElem = 0;
  PlaceCarte p= NULL;
  for(p=liste.premier();p!= NULL; p=liste.suivant(p))
    {
      ajoutFin(liste.valeur(p));
    }
}


//DESTRUCTEURS

ListeCarte::~ListeCarte()
{
  PlaceCarte p= tete;
  while(p!=NULL)
    {
      p= suivant(p);
      delete tete;      
      tete = p;
    }
}

//NETTOYEUR

void ListeCarte::vider()
{
  PlaceCarte p= tete;
  while(p!=NULL)
    {
      p= suivant(p);
      delete tete;      
      tete = p;
    }
  tete = NULL;
  queue = NULL;
  nbElem = 0;
}

//SUPPRESSION ELEMENT

void ListeCarte::enlever(PlaceCarte p)
{
  if(nbElem == 1)
    {
      tete = NULL;
      queue = NULL;
    }
  else 
    {
      if(p== tete)//1 voisin
	{
	  tete = suivant(p);
	  setPrecedent(tete, NULL);
	}
      else if(p== queue)//1 voisin
	{
	  queue = precedent(p);
	  setSuivant(queue, NULL);
	}
      else //2 voisins
	{
	  setPrecedent(suivant(p), precedent(p));
	  setSuivant(precedent(p), suivant(p));
	}
    }
  delete p;
  nbElem --;
}

//AFFECTATION

ListeCarte& ListeCarte::operator=(const ListeCarte &liste)
{
  if(this != &liste)
    {
      vider();
      PlaceCarte p= liste.premier();
      while(p!=NULL)
	{
	  ajoutFin(liste.valeur(p));
	  p= liste.suivant(p);
	}
    }
  return *this;
}
