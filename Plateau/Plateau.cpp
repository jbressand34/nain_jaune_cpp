#include"Plateau.h"
using namespace std;

Plateau::Plateau():derniereCarteJoue(Carte(0,0)),nbjoueur(0),joueurs(NULL),cases(new Case[5]), paquet(new Carte[52]), talon(Main()), cartesJouees(Main()), niveau(1), debugg(false){
  cases[0] = Case(3,7);
  cases[1] = Case(3,10);
  cases[2] = Case(4,11);
  cases[3] = Case(1,12);
  cases[4] = Case(2,13);

  for (size_t i = 0; i < 13 ; i++)
    {
      paquet[i] = Carte(i+1,1);
      paquet[13+i] = Carte(i+1,2);
      paquet[26+i] = Carte(i+1,3);
      paquet[39+i] = Carte(i+1,4);
    }
}

Plateau::Plateau(size_t nbjoueurs, Joueur *joueursJ, size_t niveau, bool debugg):derniereCarteJoue(Carte(0,0)),nbjoueur(nbjoueurs),joueurs(new Joueur[nbjoueurs]),cases(new Case[5]),paquet(new Carte[52]), niveau(niveau), debugg(debugg)
{
  cases[0] = Case(3,7);
  cases[1] = Case(3,10);
  cases[2] = Case(4,11);
  cases[3] = Case(1,12);
  cases[4] = Case(2,13);

  for (size_t i = 0; i < 13 ; i++)
    {
      paquet[i] = Carte(i+1,1);
      paquet[13+i] = Carte(i+1,2);
      paquet[26+i] = Carte(i+1,3);
      paquet[39+i] = Carte(i+1,4);
    }

  for (size_t i = 0; i < nbjoueur; i++)
    {
      joueurs[i] = joueursJ[i]; 
    }
}

Plateau::Plateau(const Plateau& plateau):derniereCarteJoue(plateau.derniereCarteJoue),nbjoueur(plateau.nbjoueur),joueurs(new Joueur[nbjoueur]),cases(new Case[5]),paquet(new Carte[52]),talon(plateau.talon),cartesJouees(plateau.cartesJouees),niveau(plateau.niveau),debugg(plateau.debugg)
{
  for(size_t i=0; i<nbjoueur;i++){
    joueurs[i]=plateau.joueurs[i];
  }
  for(size_t i=0; i<5;i++){
    cases[i]=plateau.cases[i];
  }
  for(size_t i=0; i<52;i++){
    paquet[i]=plateau.paquet[i];
  }
}

Plateau::~Plateau(){
  if(joueurs!=NULL){
    delete[] joueurs;
  }
  delete[] cases;
  delete[] paquet;
}

Plateau& Plateau::operator=(const Plateau& plateau){
  if(this!=&plateau){

    derniereCarteJoue = plateau.derniereCarteJoue;
    nbjoueur=plateau.nbjoueur;
    niveau = plateau.niveau;
    talon = plateau.talon;
    cartesJouees = plateau.cartesJouees;
    debugg = plateau.debugg;

    if(joueurs!=NULL){ 
    delete[] joueurs;
    }

    joueurs=new Joueur[nbjoueur];
    for(size_t i=0; i<nbjoueur;i++){
      joueurs[i]=plateau.joueurs[i];
    }

    for(size_t i=0; i<5;i++){
      cases[i]=plateau.cases[i];
    }

    for(size_t i=0; i<52;i++){
      paquet[i]=plateau.paquet[i];
    }
  }
  return *this;
}

//Accesseurs

size_t Plateau::getNbJoueur()const{
  return nbjoueur;
}

Joueur* Plateau::getJoueurs()const{
  return joueurs;
}

Case* Plateau::getCases()const{
  return cases;
}

Carte* Plateau::getPaquet()const{
  return paquet;
}


void Plateau::setJoueurs(size_t nbjoueurJ, Joueur* joueursJ)
{
  nbjoueur = nbjoueurJ;
  
  if (joueurs != NULL)
    {
      delete[] joueurs;
    }

  joueurs = new Joueur[nbjoueur];
  
  for (size_t i = 0; i < nbjoueur; i++)
    {
      joueurs[i] = joueursJ[i];
    }
}


/////////////////FONCTIONS


/////////////////////////////
/////////////////////////////


void Plateau::afficherPlateau() const
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


  //On affiche les cases
  
  for (size_t i = 0; i < 5; i++)
    {
      cout << cases[i];
    }
  
  //On affiche les joueurs

  for (size_t i = 0; i < nbjoueur; i++)
    {
      cout << joueurs[i];
    }


  //On affiche la dernière carte jouée
  if (derniereCarteJoue != Carte(0,0))
    {
      cout <<"\033[19;15H" << "Dernière carte jouée : " << derniereCarteJoue;
    }


  //On positionne le curseur dans l'espace saisie

  cout << "\033[21;0H";

  //FIN

}


/////////////////////////////
/////////////////////////////


void Plateau::melangerCartes(){

  std::string phrase;

  effsaisie();

  for (size_t i = 0; i < 52; i++)
    {

      /*On trouve un indice k aléatoire compris entre 0 et 51 et différent de i */

      size_t k = i;
      while (k == i)
	{
	  k = rand()%52;
	}


      /*On échange les cartes paquet[i] et paquet[k]*/

      Carte carte = paquet[i];
      paquet[i] = paquet[k];
      paquet[k] = carte;
    }
  effsaisie();

  //FIN

}


//////////////////////////////
//////////////////////////////


void Plateau::tirage1erJoueur(std::ofstream& log){

  std::string phrase;

  afficherPlateau();
  cout << "Tirage 1er donneur ! ";
  log << "---> Tirage 1er donneur :"<<endl<<endl;
  cin >> phrase;
  afficherPlateau();

  melangerCartes();

  if (nbjoueur > 1)
    { 
      int a = 0;

      /*On creer un tableau de cartes pour stocker les cartes prises aléatoirement et associées à un joueur chacune */
      /*On creer un tableau d'indices pour stocker les indices des cartes déjà prélevées et ainsi pouvoir vérifier à chaque prélèvement aléatoire si telle carte a déjà été prélevée ou non*/


      Carte *cartes = new Carte[nbjoueur];
      int *tableau = new int[nbjoueur];


      // On initialise le tableau d'indices avec des -1

      for(size_t i=0;i<nbjoueur;i++)
	{
	  tableau[i]=-1;
	} 


      // On parcourt le tableau des joueurs
     
      for(size_t i=0;i<nbjoueur;i++)
	{

	  effsaisie(); /*le curseur est remis à la première ligne de l'espace saisie du terminal*/

	  /*On affiche les cartes précédemment tirées*/

	  for (size_t k = 0; k < nbjoueur ; k++)
	    {
	      if ((cartes[k].getenseigne() > 0))
		{ cout << cartes[k] ; }
	      else
		{ cout << " " ; }
	      cout << " | ";
	    }

	  cout << endl << "Qui seras le donneur ?" << endl;

	  cout << "C'est à " << joueurs[i].getPseudo() << " de tirer une carte : ";
	  cin >> phrase;



	  /* On prend un indice aléatoire a et on le change si il a déjà été pris */

	  bool contient = true;

	  while (contient)
	    {
	      contient=false;
	      a=rand()%52;

	      /* On vérifie que l'indice a n'a pas déjà été pris.*/
	      
	      for(size_t j=0;j<nbjoueur;j++)
		{
		  if(tableau[j]==a)
		    {
		      contient=true;
		    }
		}
	    }


	  // On a donc un nouvel indice a


	  /*On prélève la carte corespondante que l'on met à l'indice du joueur dans le tableau de carte */
	  cartes[i]=paquet[a];

	  
	  /*On indique au joueur quelle carte il a tiré */


	  effsaisie(); /*le curseur est remis à la première ligne de l'espace saisie du terminal*/

	  /*On affiche les cartes précédemment tirées*/

	  for (size_t k = 0; k < nbjoueur ; k++)
	    {
	      if ((cartes[k].getenseigne() > 0))
		{ cout << cartes[k] ; }
	      else
		{ cout << " " ; }
	      cout << " | ";
	    }

	  cout << endl <<"Le joueur " << joueurs[i].getPseudo() << " a tiré la carte " << cartes[i] << " .";

	  log <<"---> " <<"Le joueur " << joueurs[i].getPseudo() << " a tiré la carte ";
	  if (cartes[i] == Carte(7,3))
	    {
	      log<<"nain jaune."<<endl;
	    }
	  else
	    {
	      if ((cartes[i].getnumero()<11) && (cartes[i].getnumero() != 1))
		{
		  log<<cartes[i].getnumero()<<" de ";
		}
	      else
		{
		  switch(cartes[i].getnumero())
		    {
		    case 1:
		      log<<"as de ";
		      break;
		    case 11:
		      log<<"valet de ";
		      break;
		    case 12:
		      log<<"dame de ";
		      break;
		    case 13:
		      log<<"roi de ";
		      break;
		    }
		}

	      switch (cartes[i].getenseigne())
		{
		case 1:
		  log<<"pique."<<endl;
		  break;
		case 2:
		  log<<"coeur."<<endl;
		      break;
		case 3:
		  log<<"carreau."<<endl;
		  break;
		case 4:
		  log<<"trefle."<<endl;
		  break;
		}
		
	    }
	  cin >> phrase;
	  effsaisie();


	  /*On parcourt le tableau d'indice et on ajoute l'indice a dès qu'on a une case vide*/
	      
	  int k=0;
	  while(tableau[k]!=-1)
	    {
	      k++;
	    }
	      
	  tableau[k]=a;
	}
    

      //Fin parcours du tableau de joueur. 



      /*Maintenant que l'on a tiré les cartes, on détermine celui qui va distribuer les cartes*/

      size_t indicemax = 0;

      for (size_t i = 1; i < nbjoueur; i++)
	{
	  if (cartes[i].comparercarte(cartes[indicemax]) == -1)  /* si la carte i est plus grande que la carte indicemax*/ 
	      {
		indicemax = i;
	      }
	}

      //Le joueur indicemax devient le donneur

      for (size_t i = 0; i < nbjoueur; i++)
	{
	  if (i==indicemax)
	    {
	      joueurs[i].setDonneur(true);
	    }
	  else
	    {
	      joueurs[i].setDonneur(false);
	    }
	}

      effsaisie();
      cout << joueurs[indicemax]; //on affiche le D de donneur
      log<<"---> "<<joueurs[indicemax].getPseudo()<<" devient le premier donneur."<<endl;
      /*On affiche les cartes précédemment tirées*/

      for (size_t k = 0; k < nbjoueur ; k++)
	{
	  if ((cartes[k].getenseigne() > 0))
	    { cout << cartes[k] ; }
	  else
	    { cout << " " ; }
	  cout << " | ";
	}

      cout << endl << "Le donneur est : " << joueurs[indicemax].getPseudo() << ". ";
      cin >> phrase;
      effsaisie();

      delete[] cartes;
      delete[] tableau;

      //FIN
    }
}


//////////////////////////////
//////////////////////////////


void Plateau::distribution(std::ofstream& log)
{

  /*Le joueur donneur indique aux autres joueurs qu'il va distribuer*/

  size_t idonneur = 0;
  std::string phrase;

  for (size_t i = 0; i < nbjoueur; i++)
    {
      if (joueurs[i].getDonneur())
	{ idonneur = i; }
    }


  /*on doit connaître le nombre de carte par joueur réel (en enlevant ceux qui ont perdu ou ceux qui se sont arrêté)*/

  size_t nbreel = 0;
  for (size_t i = 0; i < nbjoueur; i++)
    {
      if(!joueurs[i].getPerdu() && joueurs[i].getContinu())
	{
	  nbreel ++;
	}
    }

  size_t nbCartesParJ = 0;

  switch(nbreel)
    {
    case 3:
      nbCartesParJ = 15;
      break;
    case 4:
      nbCartesParJ = 12;
      break;
    case 5:
      nbCartesParJ = 9;
      break;
    case 6:
      nbCartesParJ = 8;
      break;
    case 7:
      nbCartesParJ = 7;
      break;
    case 8:
      nbCartesParJ = 6;
      break;
    }

  effsaisie();
  cout << joueurs[idonneur].getPseudo() << " : Distribution des cartes ! ";
  log<<endl<<endl<<"---> "<<joueurs[idonneur].getPseudo()<<" mélange les cartes."<<endl;
  log<<"---> "<<joueurs[idonneur].getPseudo()<<" distribue les cartes."<<endl<<endl;
  cin >> phrase;
  effsaisie();



  /* Distribution des cartes : chaque joueur ayant perdu ou arreté ne reçoit pas de carte. Le premier joueur a recevoir une carte est le joueur suivant le donneur*/


  size_t indicejoueur = 0;

  if (idonneur == (nbjoueur - 1))
    { indicejoueur = 0; }
  else
    { indicejoueur = (idonneur + 1);}

  for (size_t i = 0; i < nbCartesParJ; i++)
    {

      for (size_t k = 0; k < nbreel; k++)
	{ 

	  while (joueurs[indicejoueur].getPerdu() || !joueurs[indicejoueur].getContinu())
	    {
	      if (indicejoueur == (nbjoueur - 1))
		{ indicejoueur = 0; }
	      else
		{ indicejoueur++; }
	    }
	  
	  if (!joueurs[indicejoueur].getMain().ajouterCarte(paquet[(i*nbreel) + k]))
	    {
	      cout << "Echec ajout carte";
	      exit(EXIT_FAILURE);
	    }
	  else
	    {
	      log<<"---> "<<joueurs[indicejoueur].getPseudo()<<" recupere la carte : ";
	      if (paquet[(i*nbreel) + k] == Carte(7,3))
		{
		  log<<"nain jaune."<<endl;
		}
	      else
		{
		  if ((paquet[(i*nbreel) + k].getnumero() < 11) && (paquet[(i*nbreel) + k].getnumero() != 1))
		    {
		      log<<paquet[(i*nbreel) + k].getnumero()<<" de ";
		    }
		  else
		    {
		      switch(paquet[(i*nbreel) + k].getnumero())
			{
			case 1:
			  log<<"as de ";
			  break;
			case 11:
			  log<<"valet de ";
			  break;
			case 12:
			  log<<"dame de ";
			  break;
			case 13:
			  log<<"roi de ";
			  break;
			}
		    }
		  
		  switch(paquet[(i*nbreel) + k].getenseigne())
		    {
		    case 1:
		      log<<"pique."<<endl;
		      break;
		    case 2:
		      log<<"coeur."<<endl;
		      break;
		    case 3:
		      log<<"carreau."<<endl;
		      break;
		    case 4:
		      log<<"trefle."<<endl;
		      break;
		    }
		}
	    }

	  if (indicejoueur == (nbjoueur - 1))
	    { indicejoueur = 0; }
	  else
	    { indicejoueur++; }
	  
	}

    }

  /*On met les cartes qui restent dans le talon.*/

  for (size_t i = (nbreel * nbCartesParJ); i<52; i++)
    {
      talon.ajouterCarte(paquet[i]);
    }

  /*Le joueur donneur indique aux autres joueurs qu'il a fini de distribuer les cartes*/

  //affichage des joueurs

  for (size_t i = 0; i < nbjoueur; i++)
    {
      cout << joueurs[i];
    }

  effsaisie();
  cout << joueurs[idonneur].getPseudo() << " : Fin distribution des cartes ! ";
  cin >> phrase;

  /*on doit réafficher les joueurs effacer le terminal*/

  afficherPlateau();


  //FIN
}


//////////////////////////////
//////////////////////////////


void Plateau::miseDeDepart(std::ofstream& log)
{
  //Chaque joueur n'ayant pas perdu et n'ayant pas arrêté doit miser 15 jetons
  /*1 jeton dans la case du 10 de carreau, 2 ..., 5 jetons dans la case du nain jaune*/

  std::string phrase;

  afficherPlateau();
  cout << "Mise de depart ! ";
  log<<"---> "<<"Chaque joueurs mise 15 jetons :"<<endl<<endl;
  cin >> phrase;
  effsaisie();


  size_t idonneur = 0;

  /*On commence par le joueur suivant le donneur*/

  for (size_t i = 0; i < nbjoueur; i++)
    {
      if (joueurs[i].getDonneur())
	{ idonneur = i; }
    }

  size_t indicejoueur = 0;

  if (idonneur == (nbjoueur - 1))
    { indicejoueur = 0; }
  else
    { indicejoueur = (idonneur + 1);}

  /*__________*/


  for (size_t i = 0; i < nbjoueur; i++)
    {

      if (!joueurs[indicejoueur].getPerdu() && joueurs[indicejoueur].getContinu())
	{

	  transfererJtJoueurVersCase(1, joueurs[indicejoueur], cases[1], log);

	  transfererJtJoueurVersCase(2, joueurs[indicejoueur], cases[2], log);

	  transfererJtJoueurVersCase(3, joueurs[indicejoueur], cases[3], log);

	  transfererJtJoueurVersCase(4, joueurs[indicejoueur], cases[4], log);

	  transfererJtJoueurVersCase(5, joueurs[indicejoueur], cases[0], log);

	}
 
      if (indicejoueur == (nbjoueur - 1))
	{ indicejoueur = 0; }
      else
	{ indicejoueur = (indicejoueur + 1);}
    }

  effsaisie();
  cout << "Fin mise de depart ! ";
  cin >> phrase;
  effsaisie();

  //FIN
}


//////////////////////////////
//////////////////////////////


void Plateau::jouerManche(std::ofstream& log)
{
  Carte carte(0,0);
  bool plusDeCarte = false;
  size_t i = 0;
  size_t numeroreference = 0;
  size_t nbNePeutPlusJouer = 0;  
  size_t j = 8;

  /*Lors d'une manche, il peut arriver que plus aucun joueur ne puisse jouer de carte. Dans ce cas c'est au dernier joueur ayant posé une carte de choisir un nouveau rang de référence donc de poser une nouvelle carte.
   Pour savoir quand plus aucun joueur ne peut jouer de carte, on crée cet indice nbNePeutPlusJouer que l'on reinitialise à 0 à chaque fois qu'un joueur joue une carte et que l'on incrémente à chaque fois qu'un joueur ne peut plsu jouer de carte*/

  std::string phrase;

  effsaisie();
  cout << "Debut de la manche !";
  log<<endl<<"/////////////////////////////////////////////////"<<endl<<endl;
  log<<"---> Debut de la manche !"<<endl<<endl;
  log<<"/////////////////////////////////////////////////"<<endl<<endl;
  cin >> phrase;
  effsaisie();

  //On positionne l'indice i sur le joueur donneur dans le tableau joueurs

  while (!joueurs[i].getDonneur())
    {
      i++;
    }


 //Le premier joueur est le joueur suivant le donneur

  if ( i == (nbjoueur - 1))
    { i=0; }
  else
    { i++; }


  //
  //On commence la manche

  while (!plusDeCarte)/*Tant que chaque joueur (n'ayant pas perdu ni arrêté) a au moins une carte*/ 
    {

      if (!joueurs[i].getPerdu() && joueurs[i].getContinu()) /*si le joueur i n'a pas perdu et n'a pas dit qu'il voulait arrêter*/
	{ 
	  if (i != j)
	    {
	      log<<endl<<"---> C'est à "<<joueurs[i].getPseudo()<<" de jouer :"<<endl;
	      j = i;
	    }

	  /*Si tous le joueurs ne peuvent plus jouer alors on remet le numero de référence à 0*/

	  if (nbNePeutPlusJouer == nbjoueur)
	    {
	      numeroreference = 0;
	      cout << "Plus personne ne peut jouer, " << joueurs[i].getPseudo() << " joue une carte de son choix : ";
	      log<<"---> Personne ne peut plus jouer, "<<joueurs[i].getPseudo()<<" joue une carte de son choix."<<endl;  
	      cin >> phrase;
	      effsaisie();
	    }


	  //Le joueur i joue une carte
	  

	  carte = joueurs[i].jouerCarte(numeroreference, niveau, cases, debugg);

      
	  //Si le joueur i ne peut plus jouer mais a encore des cartes
      
	  if (carte == Carte(0,0))
	    {
	      effsaisie();
	      log<<"---> "<<joueurs[i].getPseudo()<<" ne peut pas jouer mais possede encore des cartes."<<endl;
	      if ((i == nbjoueur - 1))
		{ i = 0; }
	      else
		{ i++; }
	      nbNePeutPlusJouer ++;

	      if(joueurs[i].getCpu())
		{
		  debug(log);
		}
	    }	  


	  //Si le joueur j ne peut plus jouer car il n'a plus de carte
      
	  else if ((carte.getnumero()==5) && (carte.getenseigne()==5))
	    {
	      log<<"---> "<<joueurs[i].getPseudo()<<" n'a plus de carte, il gagne la manche."<< endl;
	      plusDeCarte = true;	  
	      if ((i == nbjoueur - 1))
		{ i = 0; }
	      else
		{ i++; }

	      if(joueurs[i].getCpu())
		{
		  debug(log);
		}
	    }

	  /*si le joueur a activé le mode debug*/

	  else if(carte == Carte(6,6) && debugg)
	    {
	      debug(log);
	    }
	  
	  //Si le joueur peut jouer et a joué
	  
	  else
	    {
	      log<<"---> "<<joueurs[i].getPseudo()<<" joue la carte : ";
	      if (carte == Carte(7,3))
		{
		  log<<"nain jaune."<<endl;
		}
	      else
		{
		  if ((carte.getnumero() < 11) && (carte.getnumero() != 1))
		    {
		      log<<carte.getnumero()<<" de ";
		    }
		  else
		    {
		      switch (carte.getnumero())
			{
			case 1:
			  log<<"as de ";
			  break;
			case 11:
			  log<<"valet de ";
			  break;
			case 12:
			  log<<"dame de ";
			  break;
			case 13:
			  log<<"roi de ";
			  break;
			}
		    }

		  switch(carte.getenseigne())
		    {
		    case 1:
		      log<<"pique."<<endl;
		      break;
		    case 2:
		      log<<"coeur."<<endl;
		      break;
		    case 3:
		      log<<"carreau."<<endl;
		      break;
		    case 4:
		      log<<"trefle."<<endl;
		      break;
		    }
		}
	    
	      nbNePeutPlusJouer = 0;
	      derniereCarteJoue = carte;
	      cartesJouees.ajouterCarte(derniereCarteJoue);
	      numeroreference = derniereCarteJoue.getnumero();

	      /*Si le joueur a joué une carte spéciale alors il récupère les jetons de la case correspondante*/

	      if (carte == Carte(7,3))
		{
		  if (carte.getjoue())
		    {
		      transfererJtCaseVersJoueur(joueurs[i], cases[0], log); 
		    }
		  else
		    {
		      log<<" ---> "<<joueurs[i].getPseudo()<<" a oublié de prendre les jetons sur la case du nainjaune."<<endl;
		    }
		}
	      
	      else if (carte == Carte(10,3))
		{
		  if (carte.getjoue())
		    {
		      transfererJtCaseVersJoueur(joueurs[i], cases[1], log); 
		    }
		  else
		    {
		      log<<" ---> "<<joueurs[i].getPseudo()<<" a oublié de prendre les jetons sur la case du 10 de carreau."<<endl;
		    }
		}
	      
	      else if (carte == Carte(11,4))
		{
		  if (carte.getjoue())
		    {
		      transfererJtCaseVersJoueur(joueurs[i], cases[2], log); 
		    }
		  else
		    {
		      log<<" ---> "<<joueurs[i].getPseudo()<<" a oublié de prendre les jetons sur la case du valet de trefle."<<endl;
		    }
		}
	      
	      else if (carte == Carte(12,1))
		{
		  if (carte.getjoue())
		    {
		      transfererJtCaseVersJoueur(joueurs[i], cases[3], log); 
		    }
		  else
		    {
		      log<<" ---> "<<joueurs[i].getPseudo()<<" a oublié de prendre les jetons sur la case de la dame de pique."<<endl;
		    }
		}
	      
	      else if (carte == Carte(13,2))
		{
		  if (carte.getjoue())
		    {
		      transfererJtCaseVersJoueur(joueurs[i], cases[4], log); 
		    }
		  else
		    {
		      log<<" ---> "<<joueurs[i].getPseudo()<<" a oublié de prendre les jetons sur la case du roi de coeur."<<endl;
		    }
		}

	      if(joueurs[i].getCpu())
		{
		  debug(log);
		}
	      	      	      	      
	    } 

	  /*fin du else (else = si le joueur a jouée une carte)*/
	  
	}  

      /*fin du : si le joueur n'a pas perdu et n'a pas arrêté*/

      else  //Si le joueur i avait perdu ou avait arrêté
	{
	  if ((i == nbjoueur - 1))
	    { i = 0; }
	  else
	    { i++; }
	  nbNePeutPlusJouer++;
	}

      /* On réaffiche le plateau car le joueur a peut-être joué une carte, il a peut-être récupéré des jetons donc il faut afficher tous ces changements */
      afficherPlateau();

    }     

  /*fin du : tant que chaque joueur ait au moins une carte*/


  /*On cherche le gagnant*/

  size_t indiceJoueurGagnant = 0;

  for (size_t j = 0; j < nbjoueur; j++)
    {
      if (!joueurs[j].getPerdu() && joueurs[j].getContinu() && joueurs[j].getMain().estVide())
	{
	  indiceJoueurGagnant = j;
	}
    } 

  /*On indique aux joueurs qui a gagné la manche*/

  effsaisie();
  cout << "Fin de la manche !" << endl;
  cout << "Le joueur ayant gagné la manche est : " << joueurs[indiceJoueurGagnant].getPseudo() << " ";

  log<<endl<<endl<<"//////////////////////////////////////////////////"<<endl<<endl;
  log<<"---> Fin de la manche !"<<endl<<endl;
  log<<"//////////////////////////////////////////////////"<<endl<<endl<<endl;

  cin >> phrase;
  effsaisie();

  //FIN
}


//////////////////////////////
//////////////////////////////
  

void Plateau::decompteJetons(std::ofstream& log)
{
  log<<"---> Decompte des jetons :"<<endl<<endl;
  string phrase;

  /*On doit trouver celui qui a gagné : c'est celui qui n'a ni perdu ni arrêté et qui n'a plus de carte*/

  size_t indiceJoueurGagnant = 0;

  for (size_t i = 0; i < nbjoueur; i++)
    {
      if((!joueurs[i].getPerdu()) && (joueurs[i].getContinu()) && (joueurs[i].getMain().estVide()))
	{
	  indiceJoueurGagnant = i;
	}
    }

  
  /*Il faut connaître combien il reste de joueurs */

  size_t nbJoueurReel = 0;

  for (size_t i = 0; i < nbjoueur; i++)
    {
      if((!joueurs[i].getPerdu()) && (joueurs[i].getContinu()))
	{
	  nbJoueurReel ++;
	}
    }
  
  /*Maintenant que l'on connait le joueur gagnant et le nombre de joueur restant, on va pouvoir parcourir le tableau de joueur et faire le decompte des jetons.
   Pour cela, nous avons besoin de parcourir la liste des cartes dans la main du joueur donc d'en faire une copie dans une variable locale ListeCarte cartes[13].*/

  ListeCarte cartes[13];
  size_t indiceJoueur = 0;


  //On parcourt le tableau de joueur

  for (size_t i = 0; i < nbJoueurReel; i++)
    {

      /*On prend le prochain joueur n'ayant ni perdu ni arrêté*/

      while ((joueurs[indiceJoueur].getPerdu()) || (!joueurs[indiceJoueur].getContinu()))
	{
	  indiceJoueur++;
	}


      /*Si ce joueur n'est pas le joueur gagnant, alors il doit donner des jetons*/

      if (indiceJoueur != indiceJoueurGagnant) 
	{

	  log<<endl<<"---> "<<joueurs[indiceJoueur].getPseudo()<<" doit donner des jetons :"<<endl<<endl;

	  for (size_t j = 0; j<13; j++)
	    {
	      cartes[j] = joueurs[indiceJoueur].getMain().getCartes()[j];
	    }


	  /*On va besoin de savoir combien de jetons le joueur va donner au joueur gagnant
	    Ce nombre correspond au nombre de cartes non spéciales contenues dans la main du joueur*/

	  size_t nbCarteNonSpeciale = 0;

	  /*On va parcourir les listes de carte, on a besoin d'un pointeur sur cellule carte  */

	  PlaceCarte pcarte = NULL;

	  for (size_t j = 0; j<13; j++)
	    {
	      pcarte = cartes[j].premier();

	      while (pcarte != NULL)
		{
		  
		  //Si la carte est une carte spéciale
		  
		  if ((pcarte->getVal() == Carte(7,3)) || (pcarte->getVal() == Carte(10,3)) || (pcarte->getVal() == Carte(11,4)) || (pcarte->getVal() == Carte(12,1)) || (pcarte->getVal() == Carte(13,2)))
		    {
		      /*On évalue la carte*/
		      /*Le joueur doit doubler le contenu de la case correspondante.*/
		      
		      if (pcarte->getVal() == Carte(7,3))
			{
			  log<<"---> "<<joueurs[indiceJoueur].getPseudo()<<" doit doubler le nombre de jetons sur la case du nainjaune :"<<endl;
			  transfererJtJoueurVersCase(cases[0].getNbJetons(), joueurs[indiceJoueur], cases[0], log);
			} 
		      
		      else if (pcarte->getVal() == Carte(10,3))
			{
			  log<<"---> "<<joueurs[indiceJoueur].getPseudo()<<" doit doubler le nombre de jetons sur la case du 10 de carreau :"<<endl;
			  transfererJtJoueurVersCase(cases[1].getNbJetons(), joueurs[indiceJoueur], cases[1], log);
			} 
		      
		      else if (pcarte->getVal() == Carte(11,4))
			{
			  log<<"---> "<<joueurs[indiceJoueur].getPseudo()<<" doit doubler le nombre de jetons sur la case du valet de trefle :"<<endl;
			  transfererJtJoueurVersCase(cases[2].getNbJetons(), joueurs[indiceJoueur], cases[2], log);
			} 
		      
		      else if (pcarte->getVal() == Carte(12,1))
			{
			  log<<"---> "<<joueurs[indiceJoueur].getPseudo()<<" doit doubler le nombre de jetons sur la case de la dame de pique :"<<endl;
			  transfererJtJoueurVersCase(cases[3].getNbJetons(), joueurs[indiceJoueur], cases[3], log);
			} 
		      
		      else if (pcarte->getVal() == Carte(13,2))
			{
			  log<<"---> "<<joueurs[indiceJoueur].getPseudo()<<" doit doubler le nombre de jetons sur la case du roi de coeur :"<<endl;
			  transfererJtJoueurVersCase(cases[4].getNbJetons(), joueurs[indiceJoueur], cases[4], log);
			} 

		    }


		  //Si la carte n'est pas une carte spéciale

		  else
		    {
		      nbCarteNonSpeciale++;
		    }

		  pcarte = cartes[j].suivant(pcarte);

		}
	    }

	  //On fait le transfert de jetons entre joueur et joueurGagnant

	  transfererJtJoueurVersJoueur(nbCarteNonSpeciale, joueurs[indiceJoueur], joueurs[indiceJoueurGagnant], log);

	  //On incremente indiceJoueur

	  indiceJoueur ++;

	}

      // fin if (indiceJoueur != indiceJoueurGagnant) 


      /*Si le joueur est le joueur gagnant alors il ne donne pas de jeton, on passe au joueur suivant*/

      else
	{ indiceJoueur ++; }

    }
  
  //fin  for (size_t i = 0; i < nbJoueurReel; i++)


  /* On indique aux joueurs que le decompte est terminé */

  cout << "Fin decompte des jetons ! ";
  cin >> phrase;
  effsaisie();


  //Fin

}


//////////////////////////////
//////////////////////////////


void Plateau::jouer(std::ofstream& log)
{
  size_t numeroManche = 0;


  /*Une partie contient plusieurs manches, la partie se termine quand moins de trois joueurs (n'ayant pas perdu) veulent continuer ou quand il n'y a plus que des joueurs CPU*/

  size_t nbJoueurContinuer = nbjoueur;
  size_t nbJoueurHumain = 0;

  for(size_t i = 0; i<nbjoueur; i++)
    {
      if (!joueurs[i].getCpu())
	{
	  nbJoueurHumain ++;
	}
    }

  //Le tirage 1er joueur ne se fait qu'en début de partie une fois pour toute

  tirage1erJoueur(log);

  if (debugg)
    {
      debug(log);
    }

  //On peut commencer la partie

  while ((nbJoueurContinuer > 2) && (nbJoueurHumain > 0)) 
    {
      numeroManche ++;
      log<<endl<<endl<<endl<<"/////////////////////////////////////////////////"<<endl<<endl;
      log<<"---> On prépare la ";
      if (numeroManche == 1)
	{
	  log<<"1ere manche :"<<endl;
	}
      else
	{
	  log<<numeroManche<<"eme manche :"<<endl;
	}
      log<<endl<<"/////////////////////////////////////////////////"<<endl<<endl<<endl<<endl;

      /*la distribution, la mise de depart, et le decompte des jetons se fait à chaque manche */

      miseDeDepart(log);

      if (debugg)
	{
	  debug(log);
	}

      distribution(log);

      if (debugg)
	{
	  debug(log);
	}

      jouerManche(log);

      if (debugg)
	{
	  debug(log);
	}

      decompteJetons(log);

      if (debugg)
	{
	  debug(log);
	}

      log<<endl<<endl<<"---> Qui a perdu ? Qui veut continuer ?"<<endl<<endl;

      /*1 jeton dans la case du 10 de carreau, 2 ..., 5 jetons dans la case du nain jaune*/
      size_t miseDepart = 15;


      //On évalue les joueurs ayant perdu

      for (size_t i = 0; i < nbjoueur ; i++)
	{

	  //Si le joueur n'a pas déjà perdu ou arrêté

	  if (!joueurs[i].getPerdu() && joueurs[i].getContinu())
	    {
	      
	      //Si le joueur n'a pas assez de jetons alors il a perdu

	      if (joueurs[i].getNbJetons() < miseDepart)
		{
		  log<<"---> "<<joueurs[i].getPseudo()<<" n'a plus assez de jetons pour continuer, il a donc perdu."<<endl;
		  joueurs[i].setPerdu(true); 
		}


	      //Autrement, on lui demande si il veut continuer

	      else
		{
		  if (joueurs[i].continuer())
		    {
		      joueurs[i].setContinu(true);
		      log<<"---> "<<joueurs[i].getPseudo()<<" n'a pas perdu et souhaite continuer."<<endl;
		    }
		  else
		    {
		      joueurs[i].setContinu(false);
		      log<<"---> "<<joueurs[i].getPseudo()<<" n'a pas perdu mais ne souhaite pas continuer."<<endl;
		    }
		}

	    }

	  else
	    {
	      if (joueurs[i].getContinu())
		{
		  log<<"---> "<<joueurs[i]<<" avait décidé de ne plus continuer et n'a donc pas participé à la manche."<<endl;;
		}
	      else
		{
		  log<<"---> "<<joueurs[i]<<" avait perdu lors des manches précédentes."<<endl;
		}
	    }
	}

      //fin for


      //On vide les mains des joueurs

      for (size_t i = 0; i < nbjoueur ; i++)
	{
	  joueurs[i].getMain().vider();
	}



  //On détermine combien il reste de joueurs qui n'ont pas perdu ni arrêté

      nbJoueurContinuer = 0;
      for (size_t i = 0; i < nbjoueur; i++)
	{
	  if (!joueurs[i].getPerdu() && joueurs[i].getContinu())
	    { nbJoueurContinuer ++ ; };
	}

      nbJoueurHumain = 0;
      for(size_t i = 0; i<nbjoueur; i++)
	{
	  if (!joueurs[i].getCpu() && !joueurs[i].getPerdu() && joueurs[i].getContinu())
	    {
	      nbJoueurHumain ++;
	    }
	}


      /*Le donneur devient le joueur (n'ayant ni perdu ni arrêté) suivant le donneur*/

      size_t idonneur = 0;

      while (!joueurs[idonneur].getDonneur())
	{
	  idonneur ++;
	}

      size_t idonneursuiv = idonneur;

      do
	{
	  if (idonneursuiv == (nbjoueur -1))
	    { idonneursuiv = 0; }
	  else
	    { idonneursuiv++; }
	} while(joueurs[idonneursuiv].getPerdu() || !joueurs[idonneursuiv].getContinu());
      
      
      if (nbJoueurContinuer > 2)
	{
	  log<<endl<<endl<<"--> "<<joueurs[idonneursuiv].getPseudo()<<" devient le nouveau donneur."<<endl;
	}

      joueurs[idonneursuiv].setDonneur(true);
      joueurs[idonneur].setDonneur(false);


    }

  //fin while

  fin(log);

  //FIN
}


//////////////////////////////
//////////////////////////////


void Plateau::fin(std::ofstream& log)
{
  string phrase = "\0";

  /*On doit connaitre le nombre de joueurs qui n'ont pas perdu*/

  size_t nbJoueurRestant = 0;

  for (size_t i = 0; i<nbjoueur; i++)
    {
      if (!joueurs[i].getPerdu())
	{
	  nbJoueurRestant ++;
	}
    }

  /*On creer deux tableaux de joueurs : 
    --> un de taille nbJoueurRestant qui va contenir les joueurs qui n'ont pas perdu.
    --> un de taille nbjoueur - nbJoueurRestant qui va contenir les joueurs ayant perdu.
    Et un tableau d'entier de taille nbJoueurRestant qui va contenir le rang du joueur (1er, 2eme etc...)*/

  Joueur *joueursRestant = new Joueur[nbJoueurRestant];
  
  Joueur *joueursPerdant = new Joueur[nbjoueur - nbJoueurRestant];

  size_t *rang = new size_t[nbJoueurRestant];

  size_t ires = 0;
  size_t iper = 0;

  for (size_t i = 0; i<nbjoueur; i++)
    {
      if (joueurs[i].getPerdu())
	{
	  joueursPerdant[iper] = joueurs[i];
	  iper++;
	}
      else
	{
	  joueursRestant[ires] = joueurs[i];
	  rang[ires] = 0;
	  ires++;
	}
    }

  /*On va trier le tableau joueursRestant par ordre décroissant en fonction du nombre de jetons : méthode du tri à bulle.*/
  Joueur joueur;

  for (size_t i=(nbJoueurRestant-1); i>0; i--)
    {
      for (size_t j=0; j<i; j++)
	{
	  if (joueursRestant[j].getNbJetons() < joueursRestant[j+1].getNbJetons())
	    {
	      joueur = joueursRestant[j];
	      joueursRestant[j] = joueursRestant[j+1];
	      joueursRestant[j+1] = joueur;
	    } 
	}
    } 

  /*On va donner un rang à chaque joueur.*/

  size_t rang1 = 1;

  rang[0] = 1;

  for (size_t i = 0; i<(nbJoueurRestant-1); i++)
    {
      if (joueursRestant[i].getNbJetons() == joueursRestant[i+1].getNbJetons())
	{
	  rang[i+1] = rang1;
	}
      else
	{
	  rang1 ++;
	  rang[i+1] = rang1;
	}
    }

  /*On écrit dans le terminal les résultats*/

  cout<<" Fin de la partie : ";

  for (size_t i = 0; i<nbJoueurRestant; i++)
    {
      cout<<joueursRestant[i].getPseudo()<<" ("<<joueursRestant[i].getNbJetons()<<" ";
      if (joueursRestant[i].getNbJetons() < 2)
	{
	  cout<<"jeton) ";
	}
      else
	{
	  cout<<"jetons) ";
	}
      if (rang[i] == 1)
	{
	  cout<<"1er / ";
	}
      else
	{
	  cout<<rang[i]<<"eme / ";
	}
    }

  for (size_t i = 0; i < (nbjoueur-nbJoueurRestant); i++)
    {
      cout<<joueursPerdant[i].getPseudo()<<" ("<<joueursPerdant[i].getNbJetons()<<" ";
      if (joueursPerdant[i].getNbJetons() < 2)
	{
	  cout<<"jeton) ";
	}
      else
	{
	  cout<<"jetons) ";
	}
      cout<<"perdu / ";
    }
  

  /*On écrit dans le log les résultats*/

  log<<endl<<endl<<endl<<endl<<"//////////////////////////////////////////////////"<<endl<<endl;
  log<<"---> Fin de la partie ! "<<endl<<endl;
  log<<"//////////////////////////////////////////////////"<<endl<<endl<<endl<<endl;

  for (size_t i = 0; i<nbJoueurRestant; i++)
    {
      log<<"---> "<<joueursRestant[i].getPseudo()<<" ("<<joueursRestant[i].getNbJetons()<<" ";
      if (joueursRestant[i].getNbJetons() < 2)
	{
	  log<<"jeton) ";
	}
      else
	{
	  log<<"jetons) ";
	}
      if (rang[i] == 1)
	{
	  log<<"est 1er."<<endl;
	}
      else
	{
	  log<<"est "<<rang[i]<<"eme."<<endl;
	}
    }

  for (size_t i = 0; i < (nbjoueur-nbJoueurRestant); i++)
    {
      log<<"---> "<<joueursPerdant[i].getPseudo()<<" ("<<joueursPerdant[i].getNbJetons()<<" ";
      if (joueursPerdant[i].getNbJetons() < 2)
	{
	  log<<"jeton) ";
	}
      else
	{
	  log<<"jetons) ";
	}
      log<<"a perdu."<<endl;
    }
  cin>>phrase;



  /*On doit trouver le nombre de joueurs gagnant non CPU*/

  size_t nbJoueurG = 0;
  size_t maxScore = joueursRestant[0].getNbJetons();
  string pseudos[8];
  size_t ijoueur = 0;

  for (size_t i = 0; i<nbJoueurRestant; i++)
    {
      if ((joueursRestant[i].getNbJetons() == maxScore) && (!joueursRestant[i].getCpu()))
	{
	  nbJoueurG ++;
	  pseudos[ijoueur] = joueursRestant[i].getPseudo();
	  ijoueur ++;
	}
    }


  /*On ecrit les scores dans le fichier scores.txt*/

  switch(nbJoueurG)
    {
    case 1:
      bestscore(maxScore, pseudos[0]);
      break;
    case 2:
      bestscore(maxScore, pseudos[0], pseudos[1]);
      break;
    case 3:
      bestscore(maxScore, pseudos[0], pseudos[1], pseudos[2]);
      break;
    case 4:
      bestscore(maxScore, pseudos[0], pseudos[1], pseudos[2], pseudos[3]);
      break;
    case 5:
      bestscore(maxScore, pseudos[0], pseudos[1], pseudos[2], pseudos[3], pseudos[4]);
      break;
    case 6:
      bestscore(maxScore, pseudos[0], pseudos[1], pseudos[2], pseudos[3], pseudos[4], pseudos[5]);
      break;
    case 7:
      bestscore(maxScore, pseudos[0], pseudos[1], pseudos[2], pseudos[3], pseudos[4], pseudos[5], pseudos[6]);
      break;
    case 8:
      bestscore(maxScore, pseudos[0], pseudos[1], pseudos[2], pseudos[3], pseudos[4], pseudos[5], pseudos[6], pseudos[7]);
      break;
    }
  effacerTerminal();  
  //delete[] joueursRestant;
  //delete[] joueursPerdant;
  //delete[] rang;
}


//////////////////////////////    
//////////////////////////////

void Plateau::transfererJtJoueurVersCase(size_t nbJetons, Joueur &joueur, Case &cas, std::ofstream& log)
{
  effsaisie();
  /*On affiche une étoile à côté du pseudo de joueur*/

  cout<<"\033[5;58H";

  for(size_t i=1;i<joueur.getNumero();i++)
    {cout<<"\033[2B";}

  cout << "*" ;
  cout << "\033[21;0H";

  //On doit vérifier que le joueur ait assez de jetons. 

  size_t nbJetonsJoueur = joueur.getNbJetons();
  string phrase;

  if (nbJetonsJoueur >= nbJetons)
    {
      cout << joueur.getMain();
      cout << "Le joueur " << joueur.getPseudo() << " met " << nbJetons << " jeton(s) sur la case " << Carte(cas.getNumero(), cas.getEnseigne())<<"."<< endl;


      log<<"---> "<<joueur.getPseudo()<<" met "<<nbJetons;
      if ((nbJetons == 0) || (nbJetons == 1))
	{
	  log<<" jeton sur la case : ";
	}
      else
	{
	  log<<" jetons sur la case: ";
	}

      if ((cas.getNumero() == 7) && (cas.getEnseigne() == 3))
	{
	  log<<"nain jaune."<<endl;
	}
      else
	{
	  if (cas.getNumero() < 11)
	    {
	      log<<cas.getNumero()<<" de ";
	    }
	  else
	    {
	      switch(cas.getNumero())
		{
		case 11:
		  log<<"valet de ";
		  break;
		case 12:
		  log<<"dame de ";
		  break;
		case 13:
		  log<<"roi de ";
		  break;
		}
	    }

	  switch(cas.getEnseigne())
	    {
	    case 1:
	      log<<"pique."<<endl;
	      break;
	    case 2:
	      log<<"coeur."<<endl;
	      break;
	    case 3:
	      log<<"carreau."<<endl;
	      break;
	    case 4:
	      log<<"trefle."<<endl;
	      break;
	    }
	}

      cin >> phrase;
      joueur.enleverJetons(nbJetons);
      cas.ajouterJetons(nbJetons);

      /*On réaffiche le joueur et la case puis on efface l'espace saisie */

      cout << joueur << cas;
      effsaisie();

    }


  else
    {
      cout << joueur.getMain();
      cout << "N'ayant pas assez de jetons, le joueur " << joueur.getPseudo() << " met " << nbJetonsJoueur << " jeton(s) sur la case " << Carte(cas.getNumero(), cas.getEnseigne()) << " au lieu de " << nbJetons << " jetons. " <<  endl;

      log<<"---> "<<"N'ayant pas assez de jetons, "<<joueur.getPseudo()<<" met "<<nbJetonsJoueur;
      if ((nbJetonsJoueur == 0) || (nbJetonsJoueur == 1))
	{
	  log<<" jeton sur la case : ";
	}
      else
	{
	  log<<" jetons sur la case: ";
	}


      if ((cas.getNumero() == 7) && (cas.getEnseigne() == 3))
	{
	  log<<"nain jaune ";
	}
      else
	{
	  if (cas.getNumero() < 11)
	    {
	      log<<cas.getNumero()<<" de ";
	    }
	  else
	    {
	      switch(cas.getNumero())
		{
		case 11:
		  log<<"valet de ";
		  break;
		case 12:
		  log<<"dame de ";
		  break;
		case 13:
		  log<<"roi de ";
		  break;
		}
	    }

	  switch(cas.getEnseigne())
	    {
	    case 1:
	      log<<"pique ";
	      break;
	    case 2:
	      log<<"coeur ";
	      break;
	    case 3:
	      log<<"carreau ";
	      break;
	    case 4:
	      log<<"trefle ";
	      break;
	    }
	}
      log<<"au lieu de "<<nbJetons<<" jetons."<<endl;


      cin >> phrase;
      joueur.enleverJetons(nbJetonsJoueur);
      cas.ajouterJetons(nbJetonsJoueur);

      /*On réaffiche le joueur et la case puis on efface l'espace saisie */

      cout << joueur << cas;
      effsaisie();

    }

  //FIN

}


//////////////////////////////
//////////////////////////////


 void Plateau::transfererJtCaseVersJoueur(Joueur &joueur, Case &cas, std::ofstream& log)
{
  /*On affiche une étoile à côté du pseudo de joueur*/

  cout<<"\033[5;58H";

  for(size_t i=1;i<joueur.getNumero();i++)
    {cout<<"\033[2B";}

  cout << "*" ;
  cout << "\033[21;0H";


  string phrase;

  /*On transfere la totalité des jetons de la case vers le joueur*/

  log<<"---> "<<joueur.getPseudo()<<" récupère les "<<cas.getNbJetons();
  if ((cas.getNbJetons() == 0) || (cas.getNbJetons() == 1))
	{
	  log<<" jeton de la case : ";
	}
      else
	{
	  log<<" jetons de la case : ";
	}

      if ((cas.getNumero() == 7) && (cas.getEnseigne() == 3))
	{
	  log<<"nain jaune."<<endl;
	}
      else
	{
	  if (cas.getNumero() < 11)
	    {
	      log<<cas.getNumero()<<" de ";
	    }
	  else
	    {
	      switch(cas.getNumero())
		{
		case 11:
		  log<<"valet de ";
		  break;
		case 12:
		  log<<"dame de ";
		  break;
		case 13:
		  log<<"roi de ";
		  break;
		}
	    }

	  switch(cas.getEnseigne())
	    {
	    case 1:
	      log<<"pique."<<endl;
	      break;
	    case 2:
	      log<<"coeur."<<endl;
	      break;
	    case 3:
	      log<<"carreau."<<endl;
	      break;
	    case 4:
	      log<<"trefle."<<endl;
	      break;
	    }
	}

  joueur.ajouterJetons(cas.getNbJetons());
  cas.enleverJetons(cas.getNbJetons());



  cout << joueur << cas;

  //FIN
}


//////////////////////////////
//////////////////////////////


void Plateau::transfererJtJoueurVersJoueur(size_t nbJetons, Joueur &joueurDon, Joueur &joueurRec, std::ofstream& log)
{
  afficherPlateau();

  /*On affiche une étoile à côté du pseudo de joueurDon*/

  cout<<"\033[5;58H";

  for(size_t i=1;i<joueurDon.getNumero();i++)
    {cout<<"\033[2B";}

  cout << "*" ;
  cout << "\033[21;0H";


  /*On affiche un G à côté du pseudo de joueurRec*/

  cout<<"\033[5;59H";

  for(size_t i=1;i<joueurRec.getNumero();i++)
    {cout<<"\033[2B";}

  cout << "G" ;
  cout << "\033[21;0H";


  //On doit vérifier que le joueurDon ait assez de jetons. 

  size_t nbJetonsJoueur = joueurDon.getNbJetons();
  std::string phrase;

  if (nbJetonsJoueur >= nbJetons)
    {
      cout << joueurDon.getMain();
      cout << "Le joueur " << joueurDon.getPseudo() << " donne " << nbJetons << " jeton(s) à " << joueurRec.getPseudo() << endl;

      log<<"---> Comme il lui reste "<<nbJetons<<" cartes non spéciales dans sa main, "<<joueurDon.getPseudo()<<" donne "<< nbJetons;
      if (nbJetons == 1)
	{
	  log<<" jeton à "<<joueurRec.getPseudo()<<"."<<endl;
	}
      else
	{
	  log<<" jetons à "<<joueurRec.getPseudo()<<"."<<endl;
	}
 
      cin >> phrase;
      joueurDon.enleverJetons(nbJetons);
      joueurRec.ajouterJetons(nbJetons);

      /* On réaffiche les deux joueurs puis on efface l'espace saisie */

      cout << joueurDon << joueurRec;
      effsaisie();

    }

  else
    {
      cout << joueurDon.getMain();
      cout << "N'ayant pas assez de jetons, le joueur " << joueurDon.getPseudo() << " donne " << nbJetonsJoueur << " jeton(s) à " << joueurRec.getPseudo() << " au lieu de " << nbJetons << " jetons. " <<  endl;

      log<<"---> Comme il lui reste "<<nbJetons<<" cartes non spéciales dans sa main mais n'ayant pas assez de jetons, "<<joueurDon.getPseudo()<<" donne "<< nbJetonsJoueur;
      if ((nbJetonsJoueur == 1) || (nbJetonsJoueur == 0))
	{
	  log<<" jeton à "<<joueurRec.getPseudo()<<"."<<endl;
	}
      else
	{
	  log<<" jetons à "<<joueurRec.getPseudo()<<"."<<endl;
	}

      cin >> phrase;
      joueurDon.enleverJetons(nbJetonsJoueur);
      joueurRec.ajouterJetons(nbJetonsJoueur);

      /* On réaffiche les deux joueurs puis on efface l'espace saisie */

      cout << joueurDon << joueurRec;
      effsaisie();

    }

  //FIN

}

void Plateau::debug(ofstream& log)
{
  string phrase = "\0";
  size_t icase = 0;
  size_t ijoueur = 0;
  size_t idonneur = 0;
  size_t nbJetons = 0;
  bool fin = false;
  bool fin2 = false;
  Carte carte = Carte(0,0);

  while (!fin)
    {
      effsaisie();
      phrase = "\0";
      afficherPlateau();
      afficherCartes();
      /*On demande à l'utilisateur si il veut changer quelque chose*/

      while (((phrase[0] != 'O') && (phrase[0] != 'n')) || (phrase.size()!=1))
	{
	  afficherPlateau();
	  afficherCartes();
	  cout<<"Talon:";
	  talon.affiche(cout, false);
	  cout<<" Cartes Jouées:";
	  cartesJouees.affiche(cout, false);
	  cout<<endl;
	  cout<<"Voulez-vous changer la configuration de la partie courante ? (O/n) ";
	  cin>>phrase;
	  afficherPlateau();
	  afficherCartes();
	}

      /*si il ne veut pas alors on fait rien*/
      
      if (phrase[0] == 'O')
	{

	  //////////////////////////////

	  /*On parcourt les cases en demandant à l'utilisateur si il veut en changer les attributs.*/
	  
	  icase = 0;

	  while (icase < 5 )
	    {
	      phrase = "\0";
	      afficherPlateau();
	      afficherCartes();
	      while(((phrase[0] != 'O') && (phrase[0] != 'n')) || (phrase.size()!=1))
		{
		  cout<<"Talon:";
		  talon.affiche(cout, false);
		  cout<<" Cartes Jouées:";
		  cartesJouees.affiche(cout, false);
		  cout<<endl;
		  cout<<"Voulez-vous changer le nombre de jetons de la case ";
		  switch(icase)
		    {
		    case 0:
		      cout<<"nainjaune ? (O/n) ";
		      break;
		    case 1:
		      cout<<"10 de carreau ? (O/n) ";
		      break;
		    case 2:
		      cout<<"valet de trefle ? (O/n) ";
		      break;
		    case 3:
		      cout<<"dame de pique ? (O/n) ";
		      break;
		    case 4:
		      cout<<"roi de coeur ? (O/n) ";
		      break;
		    }
		  cin>>phrase;
		  afficherPlateau();
		  afficherCartes();
		}

	      if (phrase[0] == 'n')
		{
		  icase++;
		}

	      /*Si l'utilisateur veut changer le nombre de jetons d'un case.*/

	      else if (phrase[0] == 'O')
		{
		  nbJetons = 401;
		  phrase = "\0";
		  afficherPlateau();
		  afficherCartes();

		  while(((nbJetons > 400) && (phrase[0]!='O')) || (phrase.size() != 1))
		    {
		      cout<<"Talon:";
		      talon.affiche(cout, false);
		      cout<<" Cartes Jouées:";
		      cartesJouees.affiche(cout, false);
		      cout<<endl;
		      cout<<"Combien voulez-vous que la case "; 
		      switch(icase)
			{
			case 0:
			  cout<<Carte(7,3);
			  break;
			case 1:
			  cout<<Carte(10,3);
			  break;
			case 2:
			  cout<<Carte(11,4);
			  break;
			case 3:
			  cout<<Carte(12,1);
			  break;
			case 4:
			  cout<<Carte(13, 2);
			  break;
			}
		      cout<<" ai de jetons ? {0-400} ";
		      cin>>phrase;
		      nbJetons = convertirStringEnInt(phrase);
		      afficherPlateau();
		      afficherCartes();
		      
		      if (nbJetons < 401)
			{
			  phrase = "\0";
			  
			  while (((phrase[0] != 'O') && (phrase[0] != 'n')) || (phrase.size() != 1))
			    {
			      afficherPlateau();
			      afficherCartes();
			      cout<<"Talon:";
			      talon.affiche(cout, false);
			      cout<<" Cartes Jouées:";
			      cartesJouees.affiche(cout, false);
			      cout<<endl;
			      cout<<"Etes-vous sûr de vouloir remplacer le nombre de jetons de la case "<<Carte(cases[icase].getNumero(), cases[icase].getEnseigne())<<" par "<<nbJetons<<" ? (O/n) ";
			      cin>>phrase;
			      afficherPlateau();
			      afficherCartes();
			    }
			}
		    }
	      
		  /*On change alors le nombre de jetons de la case*/
		  if (phrase[0] == 'O')
		    {
		      cases[icase].setNbJetons(nbJetons);
		      log<<"---> /////DEBUG///// On remplace le nombre de jetons sur la case ";
		      switch(icase)
			{
			case 0:
			  log<<"nainjaune par ";
			  break;
			case 1:
			  log<<"du 10 de carreau par ";
			  break;
			case 2:
			  log<<"du valet de trefle par ";
			  break;
			case 3:
			  log<<"de la dame de pique par ";
			  break;
			case 4:
			  log<<"du roi de coeur par ";
			  break;
			}
		      log<<nbJetons<<" jetons."<<endl;
		      cout<<cases[icase];
		      icase++;
		    }
		}
	    }


	  //////////////////////////////


	  /*On parcourt le tableau de joueur en demandant à l'utilisateur si il veut en changer la configuration*/
	  ijoueur = 0;

	  while (ijoueur < nbjoueur )
	    {
	      phrase = "\0";
	      afficherPlateau();
	      afficherCartes();

	      while(((phrase[0] != 'O') && (phrase[0] != 'n')) || (phrase.size()!=1))
		{
		  cout<<"Talon:";
		  talon.affiche(cout, false);
		  cout<<" Cartes Jouées:";
		  cartesJouees.affiche(cout, false);
		  cout<<endl;
		  cout<<"Voulez-vous changer la configuration du joueur : "<<joueurs[ijoueur].getPseudo()<<" ? (O/n) ";
		  cin>>phrase;
		  afficherPlateau();
		  afficherCartes();
		}

	      if (phrase[0] == 'n')
		{
		  ijoueur++;
		}



	      /*Si l'utilisateur veut changer la coniguration d'un joueur*/

	      else if(phrase[0] == 'O')
		{

		  /*On lui demande si il veut changer le nombre de jetons du joueur.*/

		  phrase = "\0";
		  afficherPlateau();

		  // On affiche l'étoile à côté du pseudo du joueur
		  
		  cout<<"\033[5;58H";
		  
		  for(size_t i=1;i<joueurs[ijoueur].getNumero();i++)
		    {cout<<"\033[2B";}
		  
		  cout << "*" ;


		  afficherCartes();

		  while(((phrase[0]!='O') && (phrase[0]!='n')) || (phrase.size()!=1))
		    {
		      cout<<"Talon:";
		      talon.affiche(cout, false);
		      cout<<" Cartes Jouées:";
		      cartesJouees.affiche(cout, false);
		      cout<<endl;
		      cout<<"Voulez-vous changer le nombre de jetons du joueur "<<joueurs[ijoueur].getPseudo()<<" ? (O/n) ";
		      cin>>phrase;
		      afficherPlateau();

		      // On affiche l'étoile à côté du pseudo du joueur
		  
		      cout<<"\033[5;58H";
		  
		      for(size_t i=1;i<joueurs[ijoueur].getNumero();i++)
			{cout<<"\033[2B";}
		  
		      cout << "*" ;

		      afficherCartes();
		    }
		  
		  if (phrase[0]=='O')
		    {
		      nbJetons = 401;
		      phrase = "\0";
		      afficherPlateau();

		      // On affiche l'étoile à côté du pseudo du joueur
		  
		      cout<<"\033[5;58H";
		  
		      for(size_t i=1;i<joueurs[ijoueur].getNumero();i++)
			{cout<<"\033[2B";}
		  
		      cout << "*" ;

		      afficherCartes();

		      while(((nbJetons > 400) && (phrase[0]!='O')) || (phrase.size() != 1))
			{
			  cout<<"Talon:";
			  talon.affiche(cout, false);
			  cout<<" Cartes Jouées:";
			  cartesJouees.affiche(cout, false);
			  cout<<endl;
			  cout<<"Combien voulez-vous que le joueur "<<joueurs[ijoueur].getPseudo()<<" ai de jetons ? {0-400} ";
			  cin>>phrase;
			  nbJetons = convertirStringEnInt(phrase);
			  afficherPlateau();

			  // On affiche l'étoile à côté du pseudo du joueur
		  
			  cout<<"\033[5;58H";
		  
			  for(size_t i=1;i<joueurs[ijoueur].getNumero();i++)
			    {cout<<"\033[2B";}
		  
			  cout << "*" ;

			  afficherCartes();
		      
			  if (nbJetons < 401)
			    {
			      phrase = "\0";
			      afficherPlateau();

			      // On affiche l'étoile à côté du pseudo du joueur
		  
			      cout<<"\033[5;58H";
		  
			      for(size_t i=1;i<joueurs[ijoueur].getNumero();i++)
				{cout<<"\033[2B";}
		  
			      cout << "*" ;


			      afficherCartes();
			      
			      while (((phrase[0] != 'O') && (phrase[0] != 'n')) || (phrase.size() != 1))
				{
				  cout<<"Talon:";
				  talon.affiche(cout, false);
				  cout<<" Cartes Jouées:";
				  cartesJouees.affiche(cout, false);
				  cout<<endl;
				  cout<<"Etes-vous sûr de vouloir remplacer le nombre de jetons du joueur "<<joueurs[ijoueur].getPseudo()<<" par "<<nbJetons<<" ? (O/n) ";
				  cin>>phrase;
				  afficherPlateau();

				  // On affiche l'étoile à côté du pseudo du joueur
		  
				  cout<<"\033[5;58H";
		  
				  for(size_t i=1;i<joueurs[ijoueur].getNumero();i++)
				    {cout<<"\033[2B";}
				  
				  cout << "*" ;

				  afficherCartes();
				}
			    }
			}
		      
		      /*On change alors le nombre de jetons du joueur*/
		      if (phrase[0] == 'O')
			{
			  joueurs[ijoueur].setNbJetons(nbJetons);
			  log<<"---> /////DEBUG///// On remplace le nombre de jetons du joueur "<<joueurs[ijoueur].getPseudo()<<" par "<<nbJetons<<" jetons."<<endl; 
			  cout<<joueurs[ijoueur];
			}
		    }

		  /*si le joueur n'est pas donneur, on demande à l'utilisateur si il veut que ce soit lui le donneur*/

		  if(!joueurs[ijoueur].getDonneur())
		    {
		      phrase = "\0";
		      afficherPlateau();

		      // On affiche l'étoile à côté du pseudo du joueur
		  
		      cout<<"\033[5;58H";
		  
		      for(size_t i=1;i<joueurs[ijoueur].getNumero();i++)
			{cout<<"\033[2B";}
		      
		      cout << "*" ;

		      afficherCartes();

		      while (((phrase[0]!='O') && (phrase[0]!='n')) || (phrase.size()!=1))
			{
			  cout<<"Talon:";
			  talon.affiche(cout, false);
			  cout<<" Cartes Jouées:";
			  cartesJouees.affiche(cout, false);
			  cout<<endl;
			  cout<<"Voulez-vous que le joueur "<<joueurs[ijoueur].getPseudo()<<" devienne le donneur ? (O/n) ";
			  cin>>phrase;
			  afficherPlateau();

			  // On affiche l'étoile à côté du pseudo du joueur
		  
			  cout<<"\033[5;58H";
		  
			  for(size_t i=1;i<joueurs[ijoueur].getNumero();i++)
			    {cout<<"\033[2B";}
		      
			  cout << "*" ;

			  afficherCartes();
			}

		      if(phrase[0] == 'O')
			{
			  /*On doit trouver le donneur et echanger sa place avec le joueur*/
			  for (size_t i = 0; i<nbjoueur; i++)
			    {
			      if (joueurs[i].getDonneur())
				{
				  idonneur = i;
				}
			    }
			  joueurs[idonneur].setDonneur(false);
			  joueurs[ijoueur].setDonneur(true);
			  log<<"---> /////DEBUG///// Le joueur "<<joueurs[ijoueur].getPseudo()<<" devient le nouveau donneur."<<endl;
			  cout<<joueurs[idonneur];
			  cout<<joueurs[ijoueur];

			  // On affiche l'étoile à côté du pseudo du joueur
		  
			  cout<<"\033[5;58H";
		  
			  for(size_t i=1;i<joueurs[ijoueur].getNumero();i++)
			    {cout<<"\033[2B";}
			  
			  cout << "*" ;
		      
			}
		      
		    }

		  /*Fin du changement de donneur*/

		  /*On propose à present à l'utilisateur de changer la main du joueur*/

		  phrase = "\0";
		  afficherPlateau();

		  // On affiche l'étoile à côté du pseudo du joueur
		  
		  cout<<"\033[5;58H";
		  
		  for(size_t i=1;i<joueurs[ijoueur].getNumero();i++)
		    {cout<<"\033[2B";}
		  
		  cout << "*" ;

		  afficherCartes();

		  while(((phrase[0]!='O') && (phrase[0]!='n')) || (phrase.size()!=1))
		    {
		      cout<<"Talon:";
		      talon.affiche(cout, false);
		      cout<<" Cartes Jouées:";
		      cartesJouees.affiche(cout, false);
		      cout<<endl;
		      cout<<"Voulez-vous changer la main  du joueur "<<joueurs[ijoueur].getPseudo()<<" ? (O/n) ";
		      cin>>phrase;
		      afficherPlateau();

		      // On affiche l'étoile à côté du pseudo du joueur
		  
		      cout<<"\033[5;58H";
		  
		      for(size_t i=1;i<joueurs[ijoueur].getNumero();i++)
			{cout<<"\033[2B";}
		      
		      cout << "*" ;

		      afficherCartes();
		    }
		  
		  if (phrase[0]=='O')
		    {
		      fin2 = false;

		      while (!fin2)
			{
			  cout<<joueurs[ijoueur];
			  afficherCartes();
	
			  phrase = "\0";
			  afficherPlateau();

			  // On affiche l'étoile à côté du pseudo du joueur
			  
			  cout<<"\033[5;58H";
			  
			  for(size_t i=1;i<joueurs[ijoueur].getNumero();i++)
			    {cout<<"\033[2B";}
			  
			  cout << "*" ;

			  afficherCartes();

			  while(((phrase[0]!='A') && (phrase[0]!='E') && (phrase[0]!='S')) || (phrase.size()!=1))
			    {
			      cout<<"Talon:";
			      talon.affiche(cout, false);
			      cout<<" Cartes Jouées:";
			      cartesJouees.affiche(cout, false);
			      cout<<endl;
			      cout<<"A:ajouterCarte||E:enleverCarte||S:sortir : ";
			      cin>>phrase;
			      afficherPlateau();

			      // On affiche l'étoile à côté du pseudo du joueur
		  
			      cout<<"\033[5;58H";
		  
			      for(size_t i=1;i<joueurs[ijoueur].getNumero();i++)
				{cout<<"\033[2B";}
		      
			      cout << "*" ;

			      afficherCartes();
			    }

			  switch(phrase[0])
			    {
			    case 'S':
			      fin2 = true;
			      break;

			    case 'A':
			      cin>>carte;

			      if(talon.enleverCarte(carte.getenseigne(), carte.getnumero()))
				{
				  joueurs[ijoueur].getMain().ajouterCarte(carte);				
				  log<<"---> /////DEBUG///// On donne au joueur "<<joueurs[ijoueur].getPseudo()<<" la carte ";
				  if (carte == Carte(7,3))
				    {
				      log<<"nainjaune que l'on a prit dans le talon."<<endl;
				    }
				  else
				    {
				      if ((carte.getnumero()>1) && (carte.getnumero()<11))
					{
					  log<<carte.getnumero()<<" de ";
					}
				      else
					{
					  switch(carte.getnumero())
					    {
					    case 1:
					      log<<"as de ";
					      break;
					    case 11:
					      log<<"valet de ";
					      break;
					    case 12:
					      log<<"dame de ";
					      break;
					    case 13:
					      log<<"roi de ";
					      break;
					    }
					}

				      switch(carte.getenseigne())
					{
					case 1:
					  log<<"pique que l'on a prit dans le talon."<<endl;
					  break;
					case 2:
					  log<<"coeur que l'on a prit dans le talon."<<endl;
					  break;
					case 3:
					  log<<"carreau que l'on a prit dans le talon."<<endl;
					  break;
					case 4:
					  log<<"trefle que l'on a prit dans le talon."<<endl;
					  break;
					}
				    }
				}

			      else if(cartesJouees.enleverCarte(carte.getenseigne(), carte.getnumero()))
				{
				  joueurs[ijoueur].getMain().ajouterCarte(carte);
				  log<<"---> /////DEBUG///// On donne au joueur "<<joueurs[ijoueur].getPseudo()<<" la carte ";
				  if (carte == Carte(7,3))
				    {
				      log<<"nainjaune que l'on a prit dans les cartes précedemment jouées."<<endl;
				    }
				  else
				    {
				      if ((carte.getnumero()>1) && (carte.getnumero()<11))
					{
					  log<<carte.getnumero()<<" de ";
					}
				      else
					{
					  switch(carte.getnumero())
					    {
					    case 1:
					      log<<"as de ";
					      break;
					    case 11:
					      log<<"valet de ";
					      break;
					    case 12:
					      log<<"dame de ";
					      break;
					    case 13:
					      log<<"roi de ";
					      break;
					    }
					}

				      switch(carte.getenseigne())
					{
					case 1:
					  log<<"pique que l'on a pris dans les cartes précedemment jouées."<<endl;
					  break;
					case 2:
					  log<<"coeur que l'on a pris dans les cartes précedemment jouées."<<endl;
					  break;
					case 3:
					  log<<"carreau que l'on a pris dans les cartes précedemment jouées."<<endl;
					  break;
					case 4:
					  log<<"trefle que l'on a pris dans les cartes précedemment jouées."<<endl;
					  break;
					}
				    }
				}

			      afficherPlateau();

			      // On affiche l'étoile à côté du pseudo du joueur
		  
			      cout<<"\033[5;58H";
		  
			      for(size_t i=1;i<joueurs[ijoueur].getNumero();i++)
				{cout<<"\033[2B";}
		      
			      cout << "*" ;

			      afficherCartes();
			      break;

			    case 'E':
			      cin>>carte;

			      if (joueurs[ijoueur].getMain().enleverCarte(carte.getenseigne(), carte.getnumero()))
				{
				  talon.ajouterCarte(carte);
				  log<<"---> /////DEBUG///// On enleve au joueur "<<joueurs[ijoueur].getPseudo()<<" la carte ";
				  if (carte == Carte(7,3))
				    {
				      log<<"nainjaune que l'on met dans le talon."<<endl;
				    }
				  else
				    {
				      if ((carte.getnumero()>1) && (carte.getnumero()<11))
					{
					  log<<carte.getnumero()<<" de ";
					}
				      else
					{
					  switch(carte.getnumero())
					    {
					    case 1:
					      log<<"as de ";
					      break;
					    case 11:
					      log<<"valet de ";
					      break;
					    case 12:
					      log<<"dame de ";
					      break;
					    case 13:
					      log<<"roi de ";
					      break;
					    }
					}

				      switch(carte.getenseigne())
					{
					case 1:
					  log<<"pique que l'on met dans le talon."<<endl;
					  break;
					case 2:
					  log<<"coeur que l'on met dans le talon."<<endl;
					  break;
					case 3:
					  log<<"carreau que l'on met dans le talon."<<endl;
					  break;
					case 4:
					  log<<"trefle que l'on met dans le talon."<<endl;
					  break;
					}
				    }
				}

			      afficherPlateau();
			      
			      // On affiche l'étoile à côté du pseudo du joueur
		  
			      cout<<"\033[5;58H";
		  
			      for(size_t i=1;i<joueurs[ijoueur].getNumero();i++)
				{cout<<"\033[2B";}
		      
			      cout << "*" ;

			      afficherCartes();
			      break;
			    }			  
			}
		      cout<<joueurs[ijoueur];

		      // On affiche l'étoile à côté du pseudo du joueur
		  
		      cout<<"\033[5;58H";
		  
		      for(size_t i=1;i<joueurs[ijoueur].getNumero();i++)
			{cout<<"\033[2B";}
		      
		      cout << "*" ;

		    }
		  //fin du if(phrase[0] == 'O')
		}

	      //fin du else if
	    }
	  //fin du while(ijoueur<nbjoueur)
	}
      
      else
	{
	  fin = true;
	}

      afficherPlateau();
      afficherCartes();
    }

  /*On efface l'espace entre les cases et la saisie*/
  cout<<"\033[19;43H"<<"\033[1K"<<"\033[18;43H"<<"\033[1K"<<"\033[17;43H"<<"\033[1K"<<"\033[16;43H"<<"\033[1K"<<"\033[15;43H"<<"\033[1K"<<"\033[14;43H"<<"\033[1K";

  /*On revient au debut*/

  cout<<"\033[21;0H";
	    
}


void Plateau::afficherCartes() const
{
  ListeCarte cartes;
  PlaceCarte p = NULL;
  size_t icurseur = 2;

  /*Tout d'abord on nettoie l'espace*/

  cout<<"\033[19;43H"<<"\033[1K"<<"\033[18;43H"<<"\033[1K"<<"\033[17;43H"<<"\033[1K"<<"\033[16;43H"<<"\033[1K"<<"\033[15;43H"<<"\033[1K"<<"\033[14;43H"<<"\033[1K";

  /*On revient au debut*/

  cout<<"\033[14;2H";

  /*On met toutes les cartes des joueurs dans une liste de carte*/

  for (size_t i = 0; i<nbjoueur; i++)
    {
      for (size_t j = 0; j<13; j++)
	{
	  p = joueurs[i].getMain().getCartes()[j].premier();
	  while(p!=NULL)
	    {
	      cartes.ajoutFin(joueurs[i].getMain().getCartes()[j].valeur(p));
	      p = joueurs[i].getMain().getCartes()[j].suivant(p);
	    }
	}
    }

  /*On affiche cette liste en faisant attention de ne pas dépasser la position du curseur y = 43*/

  p = cartes.premier();

  for (size_t i = 0; i<nbjoueur; i++)
    {
      if (icurseur > 35)
	{
	  cout<<"\033[1B"<<"\033[100D"<<"\033[1C";
	  icurseur = 2;
	}

      cout<<"//J"<<i+1<<"[";
      icurseur += 4;

      for (size_t j=0; j<joueurs[i].getMain().getNbCarte(); j++)
	{

	  if ((j + 1) < joueurs[i].getMain().getNbCarte())
	    {
	      if (icurseur > 39)
		{
		  cout<<"\033[1B"<<"\033[100D"<<"\033[1C";
		  icurseur = 2;
		}

	      cout<<cartes.valeur(p);
	      if (cartes.valeur(p).getnumero() == 10)
		{
		  icurseur += 3;
		}
	      else
		{
		  icurseur += 2;
		}

	      if(icurseur > 38)
		{
		  cout<<"]"<<"\033[1B"<<"\033[100D"<<"\033[1C"<<"[";
		  icurseur = 3;
		}

	      else
		{
		  cout<<"|";
		  icurseur++;
		}
	    }
	  else
	    {
	      if (icurseur > 39)
		{
		  cout<<"\033[1B"<<"\033[100D"<<"\033[1C";
		  icurseur = 2;
		}

	      cout<<cartes.valeur(p)<<"]";
	      if (cartes.valeur(p).getnumero() == 10)
		{
		  icurseur += 4;
		}
	      else
		{
		  icurseur += 3;
		}

	      if(icurseur > 39)
		{
		  cout<<"\033[1B"<<"\033[100D"<<"\033[1C";
		  icurseur = 2;
		}
	    }

	  p = cartes.suivant(p);
	}

      if (joueurs[i].getMain().getNbCarte() == 0)
	{
	  cout<<"]";
	}
    }

  cartes.vider();

  //On affiche la dernière carte jouée
  if (derniereCarteJoue != Carte(0,0))
    {
      cout <<"\033[19;15H" << "Dernière carte jouée : " << derniereCarteJoue;
    }


  //On positionne le curseur dans l'espace saisie

  cout << "\033[21;0H";

}
