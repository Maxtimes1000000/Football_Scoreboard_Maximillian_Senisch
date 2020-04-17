//Maximillian Senisch
//COSC-1437-58000 Programming Fundamentals II
//4-12-2020
//Dr.Tyson McMillan
//IDE: repl.it
//Description: The goal of this programming project is to practice using classes to create a scoreboard with data about each team (Home and Away) and more that can be updated through user input

#include <iostream>
#include "Input_Validation_Extended.h"
#include "ScoreBoard.h"

void chooseATeam(bool);
void printScoreBoardAndOptions(ScoreBoard);

using namespace std;

int main() 
{/*
  int choice[2] = {0, 0};
  bool status = true; // true is home, false is away

  chooseATeam(status);
  validateInt(choice[0]);
  Team home = Team(choice[0], status);
  status = false;
  chooseATeam(status);
  validateInt(choice[1]);
  Team away = Team(choice[1], status);
*/
  ScoreBoard s1;
  printScoreBoardAndOptions(s1);
  return 0;
}

void printScoreBoardAndOptions(ScoreBoard s1)
{
  //ScoreBoard output to user
  for(int a = 0; a < 40; a++)
  {
    cout << "\n";
  }
  string possesion = s1.getPossesion() ? "Home": "Away";
  cout << "\n\n ___________________________________________________________";
  cout << "\n/\t\t\t\t\t\tSCOREBOARD\t\t\t\t\t\t\t\\";
  cout << "\n|-----------------------------------------------------------|\n";
  cout << "|\tHOME:" << s1.getHomeName() << "\tAWAY:" << s1.getAwayName() << "\t|\n";
  cout << "|\tScore:(" << s1.getHomeScore() << ")\t\t\t\t\tSCORE:(" << s1.getAwayScore() << ")\t\t\t\t\t|\n";
  cout << "|\tDOWN:(" << s1.getDown() << ")\t\t\t\t\tYdsToNextDown:(" << s1.getToGo() <<  ")\t\t\t|\n";
  cout << "|\tQUARTER:" << s1.getQuarter() << "\t\t\t\t\tPossesion:" << possesion << "\t\t\t\t|\n";
  cout << "\\___________________________________________________________/\n";

  for(int a = 0; a < 20; a++)
  {
    cout << "\n";
  }

  //Options outputed to user
  cout << "1) Offense Gained Yards\n";
  cout << "2) Touchdown\n";
  cout << "3) Feild Goal\n";
  cout << "4) Time Out\n";
  
}