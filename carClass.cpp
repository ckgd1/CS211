#include <iostream>
using namespace std;

enum direc{NORTH, EAST, SOUTH, WEST};

class Car
{
private:
  string model;
  int year;
  int milage;
  int X;
  int Y;
  direc direction;

public:
  Car(string md, int year);
  string getModel() const;
  void goforward(int blk);
  int getX() const;  
  int getY() const;
  void turnRight();
  string getDirection();
  void turnLeft();
  string getMake() const;
  //void getmileage (int m);
};

Car::Car(string md, int yr)
{
  model = md;
  year = yr;
  milage = 0;
  X = 0;
  Y = 0;
  direction = NORTH;
}

string Car:: getModel() const
{
  return model;
}

void Car:: goforward(int blk)
{
    if (direction == NORTH)
      Y += blk;
    else if(direction == EAST)
      X += blk;
    else if (direction == SOUTH)
      Y-= blk;
    else // WEST
      X-= blk;

}

int Car::getX() const
{
  return X;
}

int Car::getY() const
{
  return Y;
}

void Car::turnRight()
{
  if(direction == WEST)
    direction == NORTH;
  else
    direction = (direc)(direction + 1);

}

string Car:: getDirection()
{
  switch(direction)
    {
    case NORTH:return "north";
    case EAST:return "east";
    case SOUTH:return "south";
    case WEST:return  "west";
    }
}

void Car:: turnLeft()
{
  if (direction == NORTH)
    direction = (direc)(direction + 1);
  else 
    direction = (direc)(direction - 1);
}

string Car::getMake() const
{
  return model;
}
/*
void Car:: getmilage(int m);
{
  int m = 0;
  if (direction == NORTH)
    Y += blk;
  else if(direction == EAST)
    X += blk;
  else if (direction == SOUTH)
    Y-= blk;
  else // WEST                                                                
    X-= blk;
  miles ++;
}
*/
int main()
{
  Car c1("Camry", 2022);
  /*
  cout << c1.getModel() << endl;
  
  c1.turnRight();
  c1.goforward(5);  
  c1.turnRight();
  c1.goforward(2);
  c1.turnRight();
  c1.turnRight();
  c1.goforward(3);  
  cout << c1.getX() << ',' << c1.getY()  << " is facing " << c1.getDirection() << endl;
  */
  c1.goforward(3);
  c1.turnRight();
  c1.goforward(5);
  c1.turnRight();
  c1.goforward(7);
  c1.turnRight();
  c1.goforward(6);
  c1.turnLeft();
  c1.goforward(1);
  cout << c1.getX()<< ',' << c1.getY() << "   " <<  c1.getDirection() << endl;
  //  c1.getmileage();
return 0;
}

/*
void showInfo (const Car& c)
{
  cout << c.getMake() << "(" << c.yr << ")" << " is located at " << "(" << c.getX() << "'" << c.getY() << ")" << " facing " << c.getDirection() << "." << " It has " << endl;

}
*/
