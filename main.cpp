#include <iostream>
#include <string>
#include <vector>
#include "Building.h"
using namespace std;

/* FUNCTIONS */
double timefromD(double x, double v){//calculate time (minutes) from distance (feet)
    if (v == 0)//error handling
        return 0.0;
    return x / v;//return distance over velocity
    }
double secToMin(double s){//convert seconds to minutes
    return s / 60.0;//divide seconds by 60 to get minutes
    }
double totalTime(int hours, int minutes, char meridian){//get total time from hours and minutes
    double totalMin{};
    if (meridian == 'a' || meridian == 'm')//am or military
        return totalMin + (hours * 60) + minutes;
    else if (meridian == 'p')//pm, 12 + hours
        return totalMin + (hours + 12) * 60 + minutes;
    else
        return -1;//meridian is not a valid character
        }
void printHrsMin(double totTime, char mer){ //print total number of minutes as hh:mm
    int totHours = totTime / 60; //get total amount of hours
    if (mer == 'p')
        totHours -= 12; //reduce by 12 for pm
    int remMinutes = (int)totTime % 60;//get remaining minutes
    if (totHours < 10){//check if hours are less than 10
        if(remMinutes >= 10)//check if minutes are greater or equal to 10
            cout << "0" << totHours << ":" << remMinutes << endl;//example: 0X:XX
        else
            cout << "0" << totHours << ":0" << remMinutes << endl;//example: 0X:0X
    }
    else{
        if (remMinutes >= 10)//if minutes are greater or equal to 10
            cout << totHours << ":" << remMinutes << endl;//example:XX:XX
        else
            cout << totHours << ":0" << remMinutes << endl;//example:XX:0X
    }
}
void insertionSortStrings(vector<Building>& arr) {//insertion sort - building edition
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        Building key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j].getName() > key.getName()) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int findString(vector<Building> &build, string x) {//binary search: strings edition ft. dante from the devil may cry series

    int l = 0;
    int r = build.size() - 1;
    // Loop to implement Binary Search
    while (l <= r) {

        // Calculating mid
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (build[m].getName() == x) {
            return m;
        }

        // If x greater, ignore left half
        if (build[m].getName() < x) {
            l = m + 1;
        }

        // If x is smaller, ignore right half
        else {
            r = m - 1;
        }
    }
    return -1;
}

/* MAIN */
int main(){
    /* VARIABLES */
    const double SLOW = 88.0;//speed 1
    const double MED = 220.0;//speed 2
    const double FAST = 352.0;//speed 3 (all speed units are in feet/min)
    double CUSTOM{}, north, east, south, west, speed=MED, time, totTime{};//custom speed, distances, speed to use for functions, time
    int choice, hours{}, minutes{};//choice marker, hour of arrival, minutes of arrival
    char mer='m', loc='n', sen='\0';//am or pm or military (default military) and entrance of arrival (default north), sentinel (option 4)
    string target="South Science";//to search through the vector
    vector<Building> CSUEB;//vector
    CSUEB.emplace_back("South Science", 1000.0, 1000.0, 1000.0, 1000.0);//example on how to add a building to the vector (name, north, east, west, south)
    CSUEB.emplace_back("North Science", 2000.0, 2000.0, 2000.0, 2000.0);
    CSUEB.emplace_back("Art and Education", 3000.0, 3000.0, 3000.0, 3000.0);
    CSUEB.emplace_back("CORE", 4000.0, 4000.0, 4000.0, 4000.0);
    Building dest = CSUEB[0]; //destination
    cout << "Welcome to the Get to class on time program!";
    /* PROMPTS */
    while (choice != -1){//sentinel
        insertionSortStrings(CSUEB);//IMPORTANT: sort the vector every time the menu pops up to make Bsearch work
        cout << "================================================\n";//to look nice
        cout << "MENU:\n(1) to add building data.\n(2) to change speed.\n(3) to set time of arrival.\n(4) to change arrival location.\n(5) to change meridian.";//prompts 1: long edition
        cout << "\n(6) to calculate time to get to building.\n(7) to view current buildings.\n(8) to select a destination.\n(-1) to exit.\n";//top line is long asf
        cout << "================================================\n";//to look nice
        if(!(cin >> choice)){//input validation
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }//set to input
        cin.ignore();//mixing insurance, use after every cin command
        if (choice == 1){//CHOICE 1: BUILDING DATA
            cout << "Enter building name:";//prompt
            getline(cin, target);//input
            cout << "Enter distance from North, East, West, and South entrances (4 values):";//prompt
            cin >> north >> east >> west >> south;//input
            cin.ignore();//delete newline
            CSUEB.emplace_back(target, north, east, west, south);//add to vector CSUEB
            cout << "Building data has been inputted. If reopening this program, please reenter the data.\n";//notice
        }
        if (choice == 2){//CHOICE 2: CHANGE SPEED
            cout << "Current speed: " << speed << " feet/minute.\n(1) to change to slow\n(2) to change to medium\n(3) to change to fast\n(4) to input custom speed\n";
            cin >> choice;//set to input
            cin.ignore();//delete whitespace
            switch(choice){//switch case
            case 1://slow
                speed = SLOW;
                break;
            case 2://medium
                speed = MED;
                break;//fast
            case 3://fast
                speed = FAST;
                break;
            case 4://custom
                cout << "Input custom speed: ";
                cin >> speed;//set
                cin.ignore();//delete
                break;
            default:
                cout << "Invalid input. Returning.\n";//don't do anything, just return
            }
        }
        if (choice == 3){//CHOICE 3: SET TIME OF ARRIVAL
            cout << "REMINDER: You are in " << mer << "m time. Use Option 5 to change it.\n";
            cout << "For am/pm, input hours between 1 and 12. For military time, input between 0 and 23.\n";
            cout << "Input hour of arrival: ";//prompt
            cin >> hours;//set
            cin.ignore();//ignore
            cout << "Input minute of arrival: ";//prompt
            cin >> minutes;//set
            cin.ignore();//ignore
            time = totalTime(hours, minutes, mer);//calculate total time
            cout << "You will arrive at campus at ";//notice
            printHrsMin(time, mer);//print time
            cout << endl;//end line
        }
        if (choice == 4){//CHOICE 4: CHANGE LOCATION OF ARRIVAL
            cout << "Current location of arrival: " << loc;//indicate
            cout << "\n(n) to change to North.\n(e) to change to East.\n(w) to change to West.\n(s) to change to South.\n";
            cin >> loc;//set
            cin.ignore();//ignore
            while (sen == '\0'){//while the sentinel is null char
            switch(loc){//switch case for location character
            case 'n'://north
                cout << "Changed to North.\n";
                break;
            case 'e'://east
                cout << "Changed to East.\n";
                break;
            case 'w'://west
                cout << "Changed to West.\n";
                break;
            case 's'://south
                cout << "Changed to South.\n";
                break;
            default://default
                cout << "Invalid input. Changed to north.\n";
                loc = 'n';
            }
            sen = 'a';//to exit
            }
            sen = '\0';//for subsequent changes
        }
        if (choice == 5){//CHOICE 5: CHANGE MERIDIAN (AM-PM-MILITARY)
            cout << "Current style of time: " << mer;//indicate
            cout << "\n(a) for AM.\n(p) for PM\n(m) for military time (24 hour time)\n";
            cin >> mer;//set
            cin.ignore();//ignore
            cout << "Done.\n";//notice
        }
        if (choice == 6){//CHOICE 6: OUTPUT TIME OF ARRIVAL
            cout << "REMINDER: You are in " << mer << "m time. Use Option 5 to change it.\n";
            switch(loc){//switch case using location character (from choice 4)
            case 'n'://north case
                totTime = time + timefromD(dest.getNorth(), speed);//add to total time (dest from option 8)
                cout << "You will arrive at " << dest.getName() << " at ";//output results
                printHrsMin(totTime, mer);//output in XX:XX
                cout << "This is from the North Entrance.\n";
                break;
            case 'e'://east case
                totTime = time + timefromD(dest.getEast(), speed);
                cout << "You will arrive at " << dest.getName() << " at ";
                printHrsMin(totTime, mer);
                cout << "This is from the East Entrance.\n";
                break;
            case 'w'://west case
                totTime = time + timefromD(dest.getWest(), speed);
                cout << "You will arrive at " << dest.getName() << " at ";
                printHrsMin(totTime, mer);
                cout << "This is from the West Entrance.\n";
                break;
            case 's'://south case
                totTime = time + timefromD(dest.getSouth(), speed);
                cout << "You will arrive at " << dest.getName() << " at ";
                printHrsMin(totTime, mer);
                cout << "This is from the South Entrance.\n";
                break;
            default://should not be activated
                cout << "A terrible thing has happened";
            }
            totTime = 0.0;//reset for subsequent calculations
        }
        if (choice == 7){//CHOICE 7: OUTPUT LIST OF BUILDINGS
            cout << "LIST OF BUILDINGS: \n";
            for (Building b : CSUEB){//range-based for loop
                cout << b.getName() << endl;//output name
            }
        }
        if (choice == 8){//CHOICE 8: CHANGE DESTINATION (the vector must be sorted)
            cout << "Enter name of destination: ";//enter string to target
            getline(cin, target);//target is the name of the destination
            int index = findString(CSUEB, target); //get index of vector where target is found
            if (index != -1){//use binary search modified for strings
                dest = CSUEB[index];//set the Building object at where target was found as destination
                cout << "Found building. The destination is now " << dest.getName() << endl;//indicate found
            } else{//findString returns -1
                cout << "Not found. Use Option 1 to add data.\n";//indicate that the building does not exist
            }
        }
    }
    cout << "IMPORTANT: This program is not liable for anything if you are late to class.\n";//Step 4: Maintain Plausible Deniability
    cout << "Turning off. See you tomorrow.\n";
}









