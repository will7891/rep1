// Oregon_Trail_H_Files
// Oregon_Trail_CPP_Files
// Oregon_Trail_DRIVERS_Files
#include <iostream>
//using namespace std;

#include <cstdlib>

#include "Oregon_Trail_H_Files.h"
//#include "Oregon_Trail_CPP_Files.cpp"


/* NOTES: 
//        
          
*/
void setUpCaravan (Caravan& car);

int main() 
{
    // seed random # generator
    srand(0);

    //testClasses();

    // ****** caravan object ****** //
    Caravan car; 
    car.wearDown.tongue = 100; // force fix, see H-file

    // set up stuff for trail blazing
    city pitStop[10] = {{"cityA",2000}, {"cityB",1900}, // cities along to trail
                        {"cityC",1600}, {"cityD",1400},
                        {"cityE",1150}, {"cityF",800},
                        {"cityF",650}, {"cityG",450},
                        {"cityH",200}, {"DONE",0}};
    int stop = 0;                                       // pitStop index
    car.setDistance(pitStop[stop] - pitStop[stop + 1]); // distance to 1st destination
    int loopCount = 0;                                  // for prompting new pacing and rationing

    // set up caravan (people + supplies), pacing, rationing, $$$ done in constructor
        // people in caravan
/*        string name = ""; int numPeople = 0;
        std::cout << "Who will travel the trail? (max of 4) (0 for done)\n";
        while (numPeople < 4)
        {
            std::cout << "Enter names: ";
            std::getline(std::cin, name);
            if (name == "0") break;
            car.setPerson((string)name);   
            numPeople++;
        }*/
        setUpCaravan(car);
    
        // supplies
        visitPitStop(pitStop[stop].name, car);

        // pacing
/*        string response = "";
        std::cout << "Set pacing (slow, steady, fast, blazing): ";
        std::cin >> response;
        if (response != "steady" && response != "fast" && response != "blazing")
            response = "slow";
        car.setPacing(response);

        // rationing
        std::cout << "Set rationing (bare bones, meager, ample, full): ";
        std::cin >> response;
        if (response != "bare bones" && response != "meager" && response != "ample")
            response = "full";
         car.setRationing(response);*/

    // ***** Begin Game ***** //
    std::cout << "\nStarting the trail!!\n\n";
    while (stop != 9) // when at 10th stop -> reached end (stop + 1 DNE)
    {
        // check distance
        if (car.getDistance() == 0)
        {
            stop++; // next stop
            visitPitStop(pitStop[stop].name, car);              // visit pit-stop
            car.setDistance(pitStop[stop] - pitStop[stop + 1]); // set distance for next destination
        }

        // print information, runCaravan
        std::cout << "  food = " << car.getCaravanSupplies("food").amount << std::endl
                  << "  distance = " << car.getDistance() << std::endl;
        car.runCaravan();
        People p; car.first(p);
        do
        {
            std::cout << p.getHealth() << " " << p.getSickness() << "\n";
        } while (car.next(p));
        
        // get new pacing and rationing (uses loopCount)
        string answer = "";
        if (loopCount % 2 == 0)
        {       
            // rationing
            std::cout << "new rationing?: ";
            std::cin >> answer;
            if (answer == "bare bones" || answer == "meager" || answer == "ample" || answer == "full")
                car.setRationing(answer);

            // pacing
            std::cout << "\nnew pace?: ";
            std::cin >> answer;
            if (answer == "slow" || answer == "steady" || answer == "fast" || answer == "blazing")
                car.setPacing(answer);
            else if (answer == "stopped")
            {
                car.restCaravan(2);
                std::cout << "  food = " << car.getCaravanSupplies("food").amount << std::endl
                          << "  distance = " << car.getDistance() << std::endl;
            }
            std::cout << std::endl;
        } // if
        loopCount++;       
    } // while

    system("Pause");
} // main

void setUpCaravan (Caravan& car)
{
        // create people 
        People person1("Jacob McNab");
        People person2("Mary Ann");
        People person3("Willy Johanson");

        // put people in caravan
        car.setPerson(person1);
        car.setPerson(person2);
        car.setPerson(person3);

        // put supplies in caravan, get oxen
        car.addSupply("rifles", 3);
        car.addSupply("bullets", 95);
        car.addSupply("clothes", 40);
        car.addSupply("food", 1300);
        car.addSupply("wheels", 3); // no addSupply?
        car.addSupply("axles", 2);
        car.addSupply("tongues", 2);
        car.setOxen(1);

        // pacing and rationing
        car.setPacing("steady");
        car.setRationing("full");
} // set up caravan