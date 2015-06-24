#ifndef Score_H
#define Score_H

#include <ctime>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <limits>
#include <stdarg.h>
class Score{
 
private:
std::string pseudo;
std::string score;
std::string date;

//Constructeur
 public:

 Score();
 Score(std::string pseudo, size_t score);

//Accesseur
 std::string getscore() const;
 std::string getpseudo() const;
 std::string getdate() const; 
 void setscore(const std::string& score);
 void setpseudo(const std::string& pseudo);
 void setdate(const std::string& date);

 //Methode
 void actualize();
 bool plusgrand(const Score& score)const;

};
bool operator==(Score const& a,Score const& b);
bool operator<(Score const& a,Score const& b);
bool operator>(Score const& a,Score const& b);
bool operator<=(Score const& a,Score const& b);
bool operator>=(Score const& a,Score const& b);
bool operator!=(Score const& a,Score const& b);
#endif
