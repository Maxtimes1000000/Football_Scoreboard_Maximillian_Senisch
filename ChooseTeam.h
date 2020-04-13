#include <iostream>
#include <Input_Validation_Extended.h>

using namespace std;

Team ChooseTeam(bool HomeStatus);
{
  int choice = 0;
  bool HomeStatus = 0;
  do
  {
    cout << "\n1: Dallas Cowboys";
    cout << "\n2: New England Patriots";
    cout << "\n3: Green Bay Packers";
    cout << "\n4: San Fransisco 49ers";
    cout << "\n5: Seatle Seahawks";
    cout << "\nPlease enter a number (1-5) to choose team 1\n";
    validateInt(choice);
  }
  while(choice < 1 && choice > 5) //ask till the user enters a number that fits the choices

  switch(choice)
  case 1: 
    Team DallasCowboys;
    break;
  case 2: 
    Team NewEnglandPatriots;
    break;
  case 3: 
    Team GreenBayPackers;
    break;
  case 4: 
    Team SanFransisco49ers;
    break;
  case 5: 
    Team SeatleSeahawks;
    break;
}