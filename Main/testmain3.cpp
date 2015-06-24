
#include "Main.h"
#include <string>
#include "../Fonction/Fonction.h"
#include "../Carte/Carte.h"

int main(int argc, char** argv)
{
  Main main;
  bool mm;
  Carte carte;
  size_t j=0;
  srand(time(NULL));
  Carte tab[12];
  while(main.getNbCarte()!=12)
    {
      mm=false;
      carte=Carte(((rand()%13)+1),(rand()%4)+1);
      for(size_t i=0;i<12;i++)
	{
	  if(carte==tab[i])
	    {
	      mm=true;
	    }
	}
      if(mm!=true)
	{
	  tab[j]=carte;
	  main.ajouterCarte(carte);
	  j++;
	    }
    }
  cout<<main<<endl;
  cout<<"sept de carreau :"<<main.getCartes()[6].speciale()<<endl;
  cout<<"roi :"<<main.getCartes()[12].speciale()<<endl;
  cout<<"plus longuer liste:"<<main.pluslongueliste()<<endl;
  cout<<"speciale:"<<main.pluslonguelistespeciale()<<endl;
  cout<<"roi:"<<main.pluslonguelisteroi()<<endl;
  return 0;
}
