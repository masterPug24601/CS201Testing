#ifndef BUILDING_H
#define BUILDING_H
#include <string>
using namespace std;

struct Distance{
    double northDist;
    double eastDist;
    double westDist;
    double southDist;
};
class Building{
private:
    Distance buildDist;
    string name;
public:
    Building(string nme, double n, double e, double w, double s){
        name = nme;
        buildDist.northDist = n;
        buildDist.eastDist = e;
        buildDist.westDist = w;
        buildDist.southDist = s;
    }
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
