#ifndef BUILDING_H
#define BUILDING_H
#include <string>
using namespace std;

struct Distance{ //Structure for the class
    double northDist;//distance from north
    double eastDist;//distance from east
    double westDist;//distance from west
    double southDist;//distance from south
};
class Building{//class definition
private:
    Distance buildDist;//a distance structure
    string name;//string for name to act as identifier
public:
    Building(string nme, double n, double e, double w, double s){//constructor to create an object
        name = nme;
        buildDist.northDist = n;
        buildDist.eastDist = e;
        buildDist.westDist = w;
        buildDist.southDist = s;
    }
    /* Functions to get private values */
    string getName(){
        return name;
    }
    double getNorth(){
        return buildDist.northDist;
    }
    double getEast(){
        return buildDist.eastDist;
    }
    double getWest(){
        return buildDist.westDist;
    }
    double getSouth(){
        return buildDist.southDist;
    }
};
#endif
