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

    cout << "P = add a passenger car\n";
    cout << "T = add a truck\n";
    cout << "D = display all cars\n";
    cout << "Q = qit\n";
    cout << "Your choice: ";
    cin >> choice;

    return choice;

}




int main()
{
    cout << "vehicles " << endl;

    Vehicle v(12345, "toyota");
    v.display();

    cout << " Passenger Car Test" << endl;

    PassCar pc("Sedan", true, 67890, "BMW");
    pc.display();

    cout << "\n Truck Test " << endl;

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

    choice = menu(); // get the letter they choose


    switch (choice) {
        case 'P':
            cout << "Add car.\n";
            fleet.insert("sedan", true, 111, "BMW"); // uses the overloaad insert - passenger

            break;

        case 't':
            cout << "Add truck.\n";
            fleet.insert(4, 12, 6740, "MIT"); // adds a truck 

            break;

        case 'd':
            cout << "Display all cars .\n";
            fleet.display(); // displays 
            break;
        case 'q':
            cout << " Quit .\n"; 
            return;

        default:
            cout << "Wrong choice \n";

    }




    return 0;
}