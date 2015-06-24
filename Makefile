################################################################################
#
#
#	Quelques infos :
#
#       - Membres : Alain Alignan, Victor Connes, Jérémy Bressand
#
#       - Date : samedi 8 novembre 2014
#
#       - Intitulé projet : Nain Jaune
#
#       - Matière : HLIN302 Programmation impérative 
#
#       -Encadrant : Alban Mancheron
#
#
#
#	Utilisation :
#
#	-make clean (supprime les fichiers issus de la programmation)
#
#	-make archive (crée une archive contenant les sources de l'application)
#
#	-make archxy (crée une archive pour la publication de l'application)
#
#	-make save (crée une sauvegarde dans un répertoire au format JJ_MM_AAAA/
#)
#	-make dep (calcul des dépendances des fichiers sources )
#
#
#
################################################################################


			 ##################
			 #    Variables   #
			 ##################


#####
# La compilation
 CPP         = $(MSQ) g++
 FLAGS       = -Wall -ansi -pedantic
 LIBS        =
 DEP_FLAG    = -MM


#####
# Les fichiers
 PROGNAME    = nainjaune
 ARCH        = $(PROGNAME).tar.gz
 ARCH_SRC    = $(PROGNAME)_src.tar.gz
 SOURCE      = Fonction/Fonction.cpp Carte/Carte.cpp Main/Cellcarte.cpp Main/Listecarte.cpp Main/Main.cpp Case/Case.cpp Joueur/Joueur.cpp Plateau/Plateau.cpp nainjaune.cpp Score/Score.cpp
 HEADERS     =
 TEXTE       = Main/main.txt Main/testmain2.cpp score.txt Score/testScore.cpp LisezMoi.txt Main/testmain3.cpp Auteurs.txt rapport.pdf
 THIS        = Makefile
 VERSION     = `eval\ date\ +%d_%m_%Y`
 DEP_FILE    = .depend


#####
# Le Shell
 MSQ         = @   #en bash lorsque l'on met @ devant une commande, celle-ci n'apparait pas dans le terminal
 RM          = $(MSQ)rm -f
 LS          = $(MSQ)ls -a --color
 MV          = $(MSQ)mv
 MKDIR       = $(MSQ)mkdir -p
 CLEAR       = $(MSQ)clear
 MAKE        = $(MSQ)make
 TAR         = $(MSQ)tar -czf


#####
# La VF
 MSG         = $(MSQ)echo -e
 MSG1        = $(MSG) "Compilation de $<\t==>\t$@"
 MSG_OK      = $(MSG) "\t\t\t..................Ok"



		 ##################
		 #     Cibles     #
		 ##################


#####
# Cibles Usuelles
 ifeq ($(wildcard $(DEP_FILE)), )
 all        : $(DEP_FILE)
	$(MAKE) 
 else
 all        : $(PROGNAME)
 endif
 dep        : $(DEP_FILE)
 archxy       : $(ARCH)
 archive    : $(ARCH_SRC)
 save       : $(VERSION)


#####
# Les Archives
 $(ARCH)    : $(THIS) $(HEADERS) $(PROGNAME) $(SOURCE:.cpp=.h) $(SOURCE:.cpp=.o) $(DEP_FILE)
	$(MSG) "Création de l'archive $@\n\tAjout des fichiers : $^"
	$(TAR) $@ $^
	$(MSG_OK)

 $(ARCH_SRC) : $(THIS) $(SOURCE) $(SOURCE:.cpp=.h) $(HEADERS) $(TEXTE)
	$(MSG) "Création de l'archive $@\n\tAjout des fichiers : $^"
	$(TAR) $@ $^
	$(MSG_OK)

 $(VERSION)  : $(ARCH_SRC)
	$(MSG) "Création du répertoire de sauvegarde : $@"
	$(RM) -rf $@
	$(MKDIR) $@
	$(MSG) "Sauvegarde de l'Archive $<"
	$(MV) $< $@
	$(MSG_OK)


#####
# Le Nettoyage
 cls        :
	$(MSG) "On fait le ménage"
	$(RM) \#*          #enleve les fichiers #*
	$(RM) *~           #enleve les fichiers ~* 
	$(RM) core         #enleve le fichier core (je ne sais pas ce que c'est)
	$(RM) *.o          #enleve les .o
	$(RM) */\#*        #de la même manière que précedemment mais dans les répertoires
	$(RM) */*~
	$(RM) */core
	$(RM) */*.o
	$(RM) $(PROGNAME)
	$(RM) $(ARCH)
	$(RM) $(ARCH_SRC)
	$(RM) $(DEP_FILE)
	$(MSG_OK)

 clean      : cls
	$(CLEAR)
	$(LS)


#####
# La Compilation
 .SUFFIXE   : .cpp .h .o

 $(DEP_FILE): $(SOURCE)
	$(MSG) "Recherche des dépendances des fichiers ..."
	$(RM) $(DEP_FILE)
	$(CPP) $(DEP_FLAG) $^ >> $@
	$(MSG_OK)

 .cpp.o       :
	$(MSG1)
	$(CPP) -c $(FLAGS) $(LIBS) $< -o $(<:.cpp=.o)
	$(MSG_OK)

 $(PROGNAME): $(SOURCE:.cpp=.o)
	$(MSG2)
	$(CPP) $(FLAGS) $(LIBS) $^ -o $@
	$(MSG_OK)  
