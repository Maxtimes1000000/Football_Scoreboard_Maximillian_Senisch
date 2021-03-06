#include <iostream>


using namespace std;

class Team
{
  private:
    string color;
    string name;
    string coachName;
    string homeCity;
    bool homeStatus;
    int score;
    int timeOutCount;

  public:
    Team()
    {
      name = "No Name"; //default constructor values changed during the construction of the ScoreBoard object s1
      coachName = "No Name";
      homeCity = "No Name";
      color = "No Color";
      homeStatus = true;
      score = 0;
      timeOutCount = 30;
    }
    void setColor(string newColor) { color = newColor; }
    void setName(string newName) { name = newName; }
    void setCoachName(string newCoachName) { coachName = newCoachName; }
    void setHomeCity(string newHomeCity) { homeCity = newHomeCity; }
    void setHomeStatus(bool newHomeStatus)  { homeStatus = newHomeStatus; }
    void setScore(int newScore) { score = newScore; }
    void setTimeOutCount(int newTimeOutCount) { timeOutCount = newTimeOutCount; }
    void touchDownPlusKick()  { score += 7; }
    void fieldGoal()  { score += 3; }
    string getColor() const { return color; }
    string getName() const { return name; }
    string getCoachName() const { return coachName; }
    string getHomeCity() const { return homeCity; }
    bool getHomeStatus() const { return homeStatus; }
    int getScore() const { return score; }
    int getTimeOutCount() const { return timeOutCount; }
};