//Maximillian Senisch
//COSC-1437-58000 Programming Fundamentals II
//4-12-2020
//Dr.Tyson McMillan
//IDE: repl.it

#include <iostream>

using namespace std;

int main() 
{
  bool HomeStatus = 1;

  //Asking the user to choose the teams
  ChooseTeam(HomeStatus);
  HomeStatus = 0;
  ChooseTeam(HomeStatus);
  return 0;
}