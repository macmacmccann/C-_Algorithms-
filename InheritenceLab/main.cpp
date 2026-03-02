// Lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


#include "Vehicles.h"    
#include "CityCar.h"     



char menu();


// set up for switch case 
char menu() {

    char choice;
    cout << "===============\n";
    cout << "===============\n";

    cout << "P = add a passenger car\n";
    cout << "T = add a truck\n";
    cout << "D = display all cars\n";
    cout << "Q = Quit\n";
    cout << "===============\n";

    cout << "Your choice: ";
    cin >> choice;

    return choice;

}




int main()
{
    cout << "vehicles " << endl;

  //  Vehicle v(12345, "toyota");
  //  v.display();

    cout << " Passenger Car Test" << endl;
    cout << "===============\n";


    PassCar pc("Sedan", true, 67890, "BMW");
    pc.display();

    cout << "===============\n";

    cout << "\n Truck Test " << endl;

    cout << "===============\n";

    Truck t(4, 12.5);
    t.setNr(54321);
    t.setProd("Volvo");
    t.display();





   




    /*
    * 
    * 
    * SAMPLE ARRAY HOW IT COULD CALL DISPLAY ON DIF VEHUICLES 
      vector<Vehicle*> cars = { new PassCar() , new Truck() };

    for (Vehicle* v : cars) {
        v->display();
    }

    
    
    */
    
    CityCar fleet;


    char choice;

    do {


    choice = menu(); // get the letter they choose


    switch (toupper(choice)) {
    case 'P': {

        cout << "Car added .\n";
        //  fleet.insert("sedan", true, 111, "BMW"); // uses the overloaad insert - passenger

        string type; bool sunroof; long nr; string prod;

        cout << "Car type: "; cin >> type;
        cout << "Sunroof (1/0): "; cin >> sunroof;
        cout << "Reg nr: "; cin >> nr;
        cout << "Producer: "; cin >> prod;
        fleet.insert(type, sunroof, nr, prod);
        cout << "Passenger car added.\n";



        break;
    }
    case 't': {
        cout << "Truck added .\n";
        fleet.insert(4, 12, 6740, "MIT"); // adds a truck 
        int axles; double load; long nr; string prod;
        cout << "Axles: "; cin >> axles;
        cout << "Load capacity: "; cin >> load;
        cout << "Reg nr: "; cin >> nr;
        cout << "Producer: "; cin >> prod;
        fleet.insert(axles, load, nr, prod);
        cout << "Truck added.\n";
        break;
    }
        case 'd':
            cout << "Display all cars .\n";
            fleet.display(); // displays 
            break;
        case 'Q':
            cout << " Quit .\n"; 
            return 0;

        default:
            cout << "Wrong choice \n";

    }
    } while (choice != 'Q' && choice != 'q');




    return 0;
}