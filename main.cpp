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
{
  ScoreBoard s1;
  printScoreBoardAndOptions(s1);
  return 0;
}

void printScoreBoardAndOptions(ScoreBoard s1)
{
  char exit = ' ';
  int yards = 0;
  int choice = 0;
  do
  {
    string possesion = s1.getPossesion() ? "Home": "Away"; //resets possesion variable with the updated value of possesion with each iteration of the do while loop

    //ScoreBoard output to user
    {
      for(int a = 0; a < 40; a++) //basically using 40 new lines to create a clearing screen effect
      {
        cout << "\n";
      }

      cout << "\n\n ___________________________________________________________";
      cout << "\n/\t\t\t\t\t\tSCOREBOARD\t\t\t\t\t\t\t\\";
      cout << "\n|-----------------------------------------------------------|\n";
      cout << "|\tHOME:" << s1.getHomeName() << "\tAWAY:" << s1.getAwayName() << "\t|\n";
      cout << "|\tScore:(" << s1.getHomeScore() << ")\t\t\t\t\tSCORE:(" << s1.getAwayScore() << ")\t\t\t\t\t|\n";
      cout << "|\tDOWN:[" << s1.getDown() << "]\t\t\t\t\tYdsToNextDown:[" << s1.getToGo() <<  "]\t\t\t|\n";
      cout << "|\tQUARTER:" << s1.getQuarter() << "\t\t\t\t\tPossesion:" << possesion << "\t\t\t\t|\n";
      cout << "\\___________________________________________________________/\n";
      cout << "Last Play: " << choice << ")" << endl;
      
      for(int a = 0; a < 16; a++) //space between the scoreboard and the plays menu
      {
        cout << s1.getPossesionColor() << "\n\033[0m";
      }
    }
    //Plays Menu output to user
    {
      cout << "\n\n\n-------PLAYS MENU--------\n";
      cout << "1) Gained/Lost Yards\n";
      cout << "2) Touchdown\n";
      cout << "3) Field Goal\n";
      cout << "4) Change Possesion\n";
      cout << "5) Next Quarter\n";
      cout << "6) Game Over\n"; 
      cout << "-------------------------\n\n";
      cout << "Enter an integer 1-6 to choose what happens next\n";
      validateInt(choice);
      switch(choice)
      {
        case 1:
        {
          cout << "Please Enter how many yards were gained (negative number for lost yards)";
          validateInt(yards);
          
          if(yards >= 0 && yards < s1.getToGo())
          {
            if(s1.getDown() == 4)
            {
              s1.changePossesion();
              s1.setDown(1);
              s1.setToGo(10);
            }
            else
            {
              s1.nextDown();
              s1.setYardGain(yards);
            }
          }
          else if(yards < 0)
          {
            if(s1.getDown() == 4)
            {
              s1.changePossesion();
              s1.setDown(1);
              s1.setToGo(10);
            }
            else
            {
              s1.nextDown();
              s1.setYardLoss(yards);
            }
          }
          else
          {
            if(s1.getDown() == 4)
            {
              s1.changePossesion();
              s1.setDown(1);
              s1.setToGo(10);
            }
            else
              s1.nextDown();
          }
        }
        break;
        case 2:
        s1.touchDown();
        break;
        case 3:
        s1.fieldGoal();
        break;
        case 4:
        s1.changePossesion();
        break;
        case 5:
        s1.nextQuarter();
        break;
        case 6:
        exit = 'e';
        break;
      }
    }
  }
  while(exit != 'e' && exit != 'E');
}