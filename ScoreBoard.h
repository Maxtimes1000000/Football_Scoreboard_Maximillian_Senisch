#include <iostream>
#include "Team.h"

using namespace std;

void chooseATeam(bool status)
{
  if(status)
  {
    cout << "\n\nHOME TEAM CHOICE\n";
  }
  else
  {
    cout << "\n\nAWAY TEAM CHOICE\n";
  }
  cout << "\n1: Dallas Cowboys";
  cout << "\n2: New England Patriots";
  cout << "\n3: Green Bay Packers";
  cout << "\n4: San Fransisco 49ers";
  cout << "\n5: Seatle Seahawks";
  cout << "\nPlease enter a number (1-5) to choose a team\n";
}

class ScoreBoard
{
  private:
    Team home; //the home team is an attribute of the scoreboard
    Team away; // the away team is also an attribute of the scoreboard
    int quarter; //quarter specifies what quarter the game is in
    int down; //how many plays since last down
    int toGo; //how many yards till the next down
    bool possesion; //who has the ball (home or away)
  public:
    ScoreBoard() //constructs the s1 scoreboard object and sets the scoreboard to its proper initial values including the team data chosen by the user
    {
      possesion = true;
      quarter = 1;
      down = 1;
      toGo = 10;

      int choice[2] = {0, 0};

      chooseATeam(true);
      while(choice[0] < 1 || choice[0] > 5)
      validateInt(choice[0]);
      switch(choice[0])
      {
        case 1: 
          home.setColor("\x1B[44m");
          home.setName("\x1B[34mDallas Cowboys      \033[0m");
          home.setCoachName("Mike McCarthy");
          home.setHomeCity("Dallas");
          break;
        case 2: 
          home.setColor("\x1B[41m");
          home.setName("\x1B[31mNew England Patriots\033[0m");
          home.setCoachName("Bill Belichick");
          home.setHomeCity("New England");
          break;
        case 3: 
          home.setColor("\x1B[42m");
          home.setName("\x1B[32mGreen Bay Packers   \033[0m");
          home.setCoachName("Matt Lafleur");
          home.setHomeCity("Green Bay");
          break;
        case 4: 
          home.setColor("\x1B[43m");
          home.setName("\x1B[33mSan Fransisco 49ers \033[0m");
          home.setCoachName("Kyle Shanahan");
          home.setHomeCity("San Fransisco");
          break;
        case 5: 
          home.setColor("\033[0m");
          home.setName("\033[0mSeatle Seahawks     ");
          home.setCoachName("Pete Carroll");
          home.setHomeCity("Seatle");
          break;
        default:
          break;
      }

      chooseATeam(false);
      while(choice[1] < 1 || choice[1] > 5)
      validateInt(choice[1]);
      switch(choice[1])
      {
        case 1: 
          away.setColor("\x1B[44m");
          away.setName("\x1B[34mDallas Cowboys      \033[0m");
          away.setCoachName("Mike McCarthy");
          away.setHomeCity("Dallas");
          break;
        case 2: 
          away.setColor("\x1B[41m");
          away.setName("\x1B[31mNew England Patriots\033[0m");
          away.setCoachName("Bill Belichick");
          away.setHomeCity("New England");
          break;
        case 3: 
          away.setColor("\x1B[42m");
          away.setName("\x1B[32mGreen Bay Packers   \033[0m");
          away.setCoachName("Matt Lafleur");
          away.setHomeCity("Green Bay");
          break;
        case 4: 
          away.setColor("\x1B[43m");
          away.setName("\x1B[33mSan Fransisco 49ers \033[0m");
          away.setCoachName("Kyle Shanahan");
          away.setHomeCity("San Fransisco");
          break;
        case 5: 
          away.setColor("\033[0m");
          away.setName("\033[0mSeatle Seahawks     ");
          away.setCoachName("Pete Carroll");
          away.setHomeCity("Seatle");
          break;
        default:
          break;
      }
    }

    string getPossesionColor() const
    {
      if(possesion)
      {
        return home.getColor();
      }
      else
      {
        return away.getColor();
      }
    }
    int getQuarter() const { return quarter; }
    int getDown() const { return down; }
    int getToGo() const { return toGo; }
    bool getPossesion() const { return possesion; }

    string getHomeName() const { return home.getName(); }
    string getHomeCoachName() const { return home.getCoachName(); }
    string getHomeHomeCity() const { return home.getHomeCity(); }
    bool getHomeStatus() const { return home.getHomeStatus(); }
    int getHomeScore() const { return home.getScore(); }
    int getHomeTimeOutCount() const { return home.getTimeOutCount(); }

    string getAwayName() const { return away.getName(); }
    string getAwayCoachName() const { return away.getCoachName(); }
    string getAwayHomeCity() const { return away.getHomeCity(); }
    bool getAwayStatus() const { return away.getHomeStatus(); }
    int getAwayScore() const { return away.getScore(); }
    int getAwayTimeOutCount() const { return away.getTimeOutCount(); }

    void nextQuarter() { quarter++; }
    void setQuarter(int a) { quarter = a; }
    void nextDown() { down++; }
    void setDown(int a) { down = a; }
    void setYardGain(int a) { toGo = toGo - a; }
    void setYardLoss(int a) { toGo = toGo - a; }
    void setToGo(int a) { toGo = a; }
    void changePossesion() { possesion = !possesion;}
    void touchDown()
    {
      if(possesion)
      {
        home.touchDownPlusKick();
        possesion = !possesion;
      }
      else
      {
        away.touchDownPlusKick();
        possesion = !possesion;
      }
    }
    void fieldGoal()
    {
      if(possesion)
      {
        home.fieldGoal();
        possesion = !possesion;
      }
      else
      {
        away.fieldGoal();
        possesion = !possesion;
      }
    }
    
    void setHomeName(string a) { home.setName(a); }
    void setHomeCoachName(string a) { home.setCoachName(a); }
    void setHomeHomeCity(string a) { home.setHomeCity(a); }
    void setHomeStatus(bool a) { home.setHomeStatus(a); }
    void setHomeScore(int a) { home.setScore(a); }
    void setHomeTimeOutCount(int a) { home.setTimeOutCount(a); }

    void setAwayName(string a) { away.setName(a); }
    void setAwayCoachName(string a) { away.setCoachName(a); }
    void setAwayHomeCity(string a) { away.setHomeCity(a); }
    void setAwayStatus(bool a) { away.setHomeStatus(a); }
    void setAwayScore(int a) { away.setScore(a); }
    void setAwayTimeOutCount(int a) { away.setTimeOutCount(a); }   
};
