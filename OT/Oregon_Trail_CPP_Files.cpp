////////// libraries shared among all classes //////////
#include <iostream>
#include <map>
#include <string>
using std::string;

#include <cassert>
#include <cstdlib>

/////// class declarations + inlines ///////////////
#include "Oregon_Trail_H_Files.h"


//////// ITEMINFO ////////////
bool itemInfo::operator == (const itemInfo& info)
{
    if (info.amount == amount && info.weight == weight)
        return true;
    return false;
} // operator ==

/*
//////// FOOD //////////////
// bild map, set member variables
Food::Food() 
{
    // add meat
      // fish
      itemInfo info = {0, 1.1}; food["fish"] = info;

      // birds
      info.weight = 1.3; food["duck"] = info;
      info.weight = 1.3; food["chicken"] = info;
      info.weight = 0.1; food["egg"] = info;  // 1 egg

      // lighter animals
      info.weight = 1.5; food["pork"] = info;
      info.weight = 1.2; food["rabbit"] = info;
      info.weight = 1.8; food["venison"] = info; // deer
      info.weight = 1.8; food["mutton"] = info;  // sheep

      // heavier animals
      info.weight = 2.5; food["beef"] = info;
      info.weight = 3.0; food["buffalo"] = info;

    // add vegetables
    info.weight = 0.3; food["corn"] = info;
    info.weight = 0.4; food["lettuce"] = info;
    info.weight = 0.6; food["tomato"] = info;
    info.weight = 0.8; food["potato"] = info;
    
    // add fruits
    info.weight = 0.5; food["apple"] = info;
    info.weight = 0.5; food["orange"] = info;
    info.weight = 0.3; food["banana"] = info;
    info.weight = 0.1; food["grapes"] = info; // plural

    // add canned goods
    info.weight = 0.7; food["soup"] = info;
    info.weight = 0.4; food["coffee"] = info;
    info.weight = 0.8; food["beans"] = info;
    info.weight = 0.6; food["peaches"] = info;
    
    // add dry goods    
    info.weight = 0.3; food["pasta"] = info;
    info.weight = 0.3; food["cornmeal"] = info;
    info.weight = 0.4; food["crackers"] = info;
    info.weight = 0.2; food["oatmeal"] = info;

    // add liquids (1 cup unit)
    info.weight = 0.3; food["water"] = info;
    info.weight = 0.3; food["liquer"] = info;
    info.weight = 0.4; food["oil"] = info;
    info.weight = 0.2; food["grease"] = info;

    // set weight, iterator
    foodWeight = 0;
    it = food.begin();
} // constructor


// set amount for some food
void Food::setFood(string name, int amt) // amt >= 0, ensure such
{
    assert(amt >= 0); // ensure non-negative amount

    // get old food info
    itemInfo info = food[name];     // get info for specified food
    if (amt == info.amount) return; // no change

    // remove/add proper weight
    if (amt < info.amount) foodWeight -= (info.amount - amt) * info.weight; // less food
    else foodWeight += (amt - info.amount) * info.weight;                   // more food

    // store new amount
    info.amount = amt; 
    food[name] = info; 
} // setFood


// get first item in map (key + value)
void Food::first(string& name, itemInfo& info)
{
    assert(food.begin() != food.end()); // ensure map not empty

    it = food.begin(); // set iterator to beginning of map
    name = it->first;
    info = it->second;
}


// get next item in map (key + value)
bool Food::next(string& name, itemInfo& info) 
{
    it++;
    if (it == food.end()) return false;

    name = it->first;
    info = it->second;
    return true;
}


// get food info
itemInfo Food::getFood(string name) // can't be const b/c of map stuff
{
    return food[name];
}


// get total weight over all foods
double Food::getWeight() const 
{
    return foodWeight;
}


//////////// MEDICINE ///////////////////////
// bild map, set member variables
Medicine::Medicine() 
{
    // add surgicals
    itemInfo info = {0, .2}; medicine["bandage"] = info; // 1 bandage
    info.weight = 1.0; medicine["disinfectant"] = info;
    info.weight = 0.8; medicine["styptic"] = info;
    info.weight = 0.5; medicine["ointment"] = info;
    info.weight = 0.1; medicine["suture kit"] = info;

    // add internal meds
    info.weight = 1.2; medicine["antivenom"] = info;
    info.weight = 0.4; medicine["digestives"] = info;
    info.weight = 0.6; medicine["ibuprofin"] = info;
    info.weight = 0.3; medicine["penicilin"] = info;
    info.weight = 0.9; medicine["cough syrup"] = info;
    info.weight = 0.7; medicine["cough drops"] = info;
    info.weight = 0.4; medicine["antibiotic"] = info;

    // add miscenallenous
    info.weight = 0.2; medicine["cotton balls"] = info;
    info.weight = 1.1; medicine["rubbing alcohol"] = info;
    info.weight = 0.6; medicine["tylenol"] = info;
    info.weight = 2.0; medicine["steroids"] = info;
    info.weight = 2.1; medicine["viagra"] = info;

    // set weight, iterator
    medicineWeight = 0;
    it = medicine.begin();
} // constructor


// set amount for some medicine
void Medicine::setMedicine(string name, int amt) // amt >= 0, ensure such
{
    assert(amt >= 0); // ensure non-negative amount

    // get old food info
    itemInfo info = medicine[name]; // get info for specified medicine
    if (amt == info.amount) return; // no change

    // remove/add proper weight
    if (amt < info.amount) medicineWeight -= (info.amount - amt) * info.weight; // less medicine
    else medicineWeight += (amt - info.amount) * info.weight;                   // more medicine

    // store new amount
    info.amount = amt; 
    medicine[name] = info; 
} // setMedicine


// get first item in map (key + value)
void Medicine::first(string& name, itemInfo& info)
{
    assert(medicine.begin() != medicine.end()); // ensure map not empty

    it = medicine.begin(); // set iterator to beginning of map
    name = it->first;
    info = it->second;
}


// get next item in map (key + value)
bool Medicine::next(string& name, itemInfo& info) 
{
    it++;
    if (it == medicine.end()) return false;

    name = it->first;
    info = it->second;
    return true;
}


// get medicine info
itemInfo Medicine::getMedicine(string name) // can't be const b/c of map stuff
{
    return medicine[name];
}


// get total weight over all medicines
double Medicine::getWeight() const 
{
    return medicineWeight;
}


//////////////// class HUNTINGGEAR ////////////
HuntingGear::HuntingGear()
{
    // add weapons
    itemInfo info = {0, 14.0}; huntingGear["shotgun"] = info; 
    info.weight = 18.0; huntingGear["rifle"] = info;
    info.weight = 7.0; huntingGear["bow"] = info;
    info.weight = 4.0; huntingGear["bear trap"] = info; // also an ammo
    info.weight = 3.0; huntingGear["rope trap"] = info; // also an ammo

    // add ammo
    info.weight = 0.4; huntingGear["shells"] = info;  // 1 shotgun shell
    info.weight = 0.3; huntingGear["bullets"] = info; // 1 rifle bullet
    info.weight = 0.2; huntingGear["arrows"] = info;  // 1 arrow for bow

    // set weight, iterator
    huntingGearWeight = 0;
    it = huntingGear.begin();
} // constructor


// set amount for some huntingGear
void HuntingGear::setHuntingGear(string name, int amt) // amt >= 0, ensure such
{
    assert(amt >= 0); // ensure non-negative amount

    // get old food info
    itemInfo info = huntingGear[name]; // get info for specified huntingGear
    if (amt == info.amount) return;    // no change

    // remove/add proper weight
    if (amt < info.amount) huntingGearWeight -= (info.amount - amt) * info.weight; // less huntingGear
    else huntingGearWeight += (amt - info.amount) * info.weight;                   // more huntingGear

    // store new amount
    info.amount = amt; 
    huntingGear[name] = info; 
} // setHuntingGear


// get first item in map (key + value)
void HuntingGear::first(string& name, itemInfo& info)
{
    assert(huntingGear.begin() != huntingGear.end()); // ensure map not empty

    it = huntingGear.begin(); // set iterator to beginning of map
    name = it->first;
    info = it->second;
}


// get next item in map (key + value)
bool HuntingGear::next(string& name, itemInfo& info) 
{
    it++;
    if (it == huntingGear.end()) return false;

    name = it->first;
    info = it->second;
    return true;
}


// get huntingGear info
itemInfo HuntingGear::getHuntingGear(string name) // can't be const b/c of map stuff
{
    return huntingGear[name];
}


// get total weight over all medicines
double HuntingGear::getWeight() const 
{
    return huntingGearWeight;
}
*/

///////////////// SUPPLIES ///////////////////

Supplies::Supplies()
{
    // add hunting gear
    itemInfo info = {0, 0};
    info.weight = 28.0; supplies["rifles"] = info;
    info.weight = 0.2; supplies["bullets"] = info; // 20 / box

    // add general goods
    info.weight = 1.5; supplies["clothes"] = info; // 1 set / person
    info.weight = 1.0; supplies["food"] = info; // in pounds

    // add wagon parts
    info.weight = 25.0; info.amount = 4; supplies["wheels"] = info; // caravans have 4 wheels
    info.weight = 40.0; info.amount = 2; supplies["axles"] = info;  // caravans have 2 axles
    info.weight = 30.0; info.amount = 1; supplies["tongues"] = info;// caravans have 1 tongue

    // set weight, iterator
    suppliesWeight = 0;
    it = supplies.begin();
} // constructor

// set amount for some supplies, adjust suppliesWeight + caravanWeight
void Supplies::setSupplies(const string& name, int amt)
{
    assert(amt >= 0); // ensure non-negative amount

    // get old supplies info
    itemInfo info = supplies[name]; // get info for specified supplies
    if (amt == info.amount) return; // no change

    // remove/add proper weight
    //   remove -> weight = info.amount - amt 
    //   add    -> weight = amt - info.amount
    double weight = (info.amount - amt) * info.weight;
    if (amt < info.amount)
    {
        suppliesWeight -=  weight; // less supplies
        Caravan::caravanWeight -= weight;
    }
    else
    {
        weight = -1 * weight; // amt - info.amount
        suppliesWeight += weight;  // more supplies
        Caravan::caravanWeight += weight;
    }

    // store new amount
    info.amount = amt; 
    supplies[name] = info; 
} // setSupplies

bool Supplies::useSupplies(const string& name, int amt)
{
    int num = getSupplies(name).amount; // get # of supplies of type name

    if (num < amt) // want to use more than exist
    {
        if (name != "food") return false; // not enough supplies
        amt = num;                        // use remaining food
    }

    setSupplies(name, num - amt); // set for 'what i have' - 'what i want to use'
    return true;
} // useSupplies

void Supplies::addSupplies(const string& name, int amount)
{
    setSupplies(name, getSupplies(name).amount + amount);
} // addSupplies

// get first item in map (key + value)
void Supplies::first(string& name, itemInfo& info)
{
    assert(supplies.begin() != supplies.end()); // ensure map not empty

    it = supplies.begin(); // set iterator to beginning of map
    name = it->first;
    info = it->second;
}

// get next item in map (key + value)
bool Supplies::next(string& name, itemInfo& info) 
{
    it++;
    if (it == supplies.end()) return false;

    name = it->first;
    info = it->second;
    return true;
}

// get supplies info
itemInfo Supplies::getSupplies(const string& name) // can't be const b/c of map stuff
{
    return supplies[name];
}

// get total weight over all supplies
double Supplies::getWeight() const 
{
    return suppliesWeight;
}

/////////////////// PEOPLE ////////////////////
// adjust checkHealth so pacing and stuff done first, then indiv ppl in a loop
//   since don't really need to call this 4 separate times... may dep on checkHunger

// multi-liners
People::People(): MAX_HEALTH(100), MAX_HUNGER(100)
{
    name = "John Wilkenson";
    health = MAX_HEALTH;  // very good
    hunger = MAX_HUNGER;  // stuffed
    sickness = "";
} // constructor
People::People(const string& name): MAX_HEALTH(100), MAX_HUNGER(100)
{
    this->name = name;    
    health = MAX_HEALTH;  // very good
    hunger = MAX_HUNGER;  // stuffed
    sickness = "";
} // constructor w/ name
People& People::operator = (const People& p)
{
    this->name = p.name;
    this->health = p.health;
    this->hunger = p.hunger;
    this->sickness = p.sickness;
    return *this;
} // operator =
string People::getHealth() const 
{
    if (health == 100) return "very good";
    if (health >= 75)  return "good";
    if (health >= 50)  return "okay";
    if (health >= 25)  return "poor";
    return "very poor";
} // getHealth
string People::getHunger() const
{
    if (hunger == 100) return "stuffed";
    if (hunger >= 75)  return "sated";
    if (hunger >= 50)  return "hungry";
    if (hunger >= 25)  return "very hungry";     
    return "starving";
} // getHunger
void People::makeSick()
{
    if (sickness != "" || sickness == "dead") return; // already sick / dead
    int num = rand() % 100;
    if ((num > 80 && health < 80) || num > 75) sickness = Ill::illness[0]; // got dysentary
    else if ((num > 70 && health < 70) || num > 80) sickness = Ill::illness[1]; // got measels
    else if ((num > 60 && health < 60) || num > 85) sickness = Ill::illness[2]; // got cholera
    else if ((num > 50 && health < 50) || num > 90) sickness = Ill::illness[3]; // got diphtheria
    else if ((num > 40 && health < 40) || num > 95) sickness = Ill::illness[4]; // got typhoid fever
   // sickness = "typhoid";//****************
} // makeSick
void People::checkHealth(const string& ration, const string& pace, bool noFood, bool noClothes)
{
    if (sickness != "dead")
    {
        // determine healing effect from rationing ->> cut out since do checkHunger???
        int healing = -3; // bare bones
        if (noFood) healing = -20; // out of food
        else if (ration == "meager") healing = -1;
        else if (ration == "ample") healing = 3;
        else if (ration == "full") healing = 7;

        // account for pacing
        if (pace == "blazing") healing += -5;
        else if (pace == "fast") healing += -2;
        else if (pace == "steady") healing += 5;
        else if (pace == "slow") healing += 8;
        else healing += 10; // stopped

        // determine ailment effect from sickness
        int ailment = 0;
        if (!sickness.empty())
        {
            int i = 0;
            for (i; i < 5; i++)
                if (sickness == Ill::illness[i]) // else not sick
                {
                    ailment = -2 * (i + 1); // 2 4 6 8 10
                    break;
                }
            assert(i != 5); // should never exit loop w/o a disease
        }

        // account for absence of clothes
        if (noClothes) healing += -10;

        // apply healing/ailment from hunger, set hunger
        checkHunger(ration, pace, noFood);

        // apply effects, check if at max health or dead
        health += healing + ailment;
        if (health > MAX_HEALTH) health = MAX_HEALTH;
        else if (health < 1) {health = 0; sickness = "dead";}
    } // if alive
} // checkHealth
void People::checkHunger(const string& ration, const string& pace, bool noFood)
{
    // determine detriment/aid from rationing
    int hungry = 0; // ration == "ample"
    if (noFood) hungry = -20; // out of food
    else if (ration == "bare bones") hungry = -8;
    else if (ration == "meager") hungry = -4;
    else if (ration == "full") hungry = 4;
 
    // determine detriment/aid from pace
    if (pace == "blazing") hungry += -6;
    else if (pace == "fast") hungry += -2;
    else if (pace == "steady") hungry += 2;
    else if (pace == "slow") hungry += 6;
    else hungry += 10; // pace == "stopped"

    // apply hungry to hunger, determine health detriment/aid
    hunger += hungry;
    if (hunger > MAX_HUNGER) hunger = MAX_HUNGER;
    else if (hunger < 1) hunger = 0;

        // aid health
        if (hunger > 90) health += 5;
        else if (hunger >= 80) health += 2;

        // detriment to health
        else if (hunger < 50) health += -10;
        else if (hunger < 60) health += -8;
        else if (hunger < 70) health += -5;
        else health += -2; // hunger < 80
} // checkHunger
void People::treatSickness()
{
    //********************* account for resting for a few days.
    // see makeSick for details
    if( (sickness == Ill::illness[0] && health >= 85) // dysentary: short-term
     || (sickness == Ill::illness[1] && health >= 80) // measels: short-medium
     || (sickness == Ill::illness[2] && health >= 75) // cholera: medium
     || (sickness == Ill::illness[3] && health >= 65) // diphtheria: medium
     || (sickness == Ill::illness[4] && health >= 60)) // typhoid: toughest
     sickness = ""; // cured 
} // treatSickness


// 1-liners
string People::getName() const {return name;}         // getName
string People::getSickness() const {return sickness;} // getSickness
void People::setHealth(int health) {this->health = health;} // setHealth
void People::setHunger(int hunger) {this->hunger = hunger;} // setHunger

///////////// SICK ////////////////////
const string Ill::illness[5] = {"dysentary", "measels", "cholera",
                                "diphtheria", "typhoid"};

///////////// ITEMWEARDOWN ///////////
const int itemWearDown::MAX_WEAR = 100;
itemWearDown::itemWearDown(): BASE_AXLES(2), BASE_WHEELS(4), BASE_TONGUES(1)
{
    // percents of intactness
    rifle = MAX_WEAR;
    cloth = MAX_WEAR;
    axle = MAX_WEAR;
    wheel = MAX_WEAR;
    tongue = MAX_WEAR; // for some reason assembly lines up
                       // w/ this and erases it, forcefully fixed in CPP
    ox = MAX_WEAR;
} // constructor

// only call once per day
void itemWearDown::applyWearDown(Caravan& car, const string& pace)
{
    // amounts of wearable items
    int cl = car.getCaravanSupplies("clothes").amount; 
    int ax = car.getCaravanSupplies("axles").amount;
    int wh = car.getCaravanSupplies("wheels").amount;  
    int to = car.getCaravanSupplies("tongues").amount;
    int oxn = car.getOxen();

    // wear down items based on caravan speed
    if (pace == "blazing")
    {
        if (cl > 0) cloth -= 20; 
        if (ax > 0) axle -= 5;
        if (wh > 0) wheel -= 12;
        if (to > 0) tongue -= 8;
        if (oxn > 0) ox -= 7;
    }

    else if (pace == "fast")
    {
        if (cl > 0) cloth -= 16; 
        if (ax > 0) axle -= 4;
        if (wh > 0) wheel -= 9;
        if (to > 0) tongue -= 6;
        if (oxn > 0) ox -= 6;
    }

    else if (pace == "steady")
    {
        if (cl > 0) cloth -= 10; 
        if (ax > 0) axle -= 3;
        if (wh > 0) wheel -= 6;
        if (to > 0) tongue -= 4;
        if (oxn > 0)  ox -= 3;
    }

    else if (pace == "slow")
    {
        if (cl > 0) cloth -= 8; 
        if (ax > 0) axle -= 2;
        if (wh > 0) wheel -= 3;
        if (to > 0) tongue -= 2;
        if (oxn > 0) ox -= 2;
    }
    
    else // pace == "stopped"
    {
        if (cl > 0) cloth -= 5; 
        if (ax > 0) axle -= 1;
        if (wh > 0) wheel -= 1;
        if (to > 0) tongue -= 1;
        if (oxn < 100) ox += 5; // oxen gain health while stopped
    }

    // check conditon of items
    if (cloth <= 0)
    {
        car.useSupply("clothes", 1);
        cloth = MAX_WEAR;
    }

    if (wheel <= 0)
        car.event_for_parts("wheels", car.wearDown.BASE_WHEELS, wheel);

    if (axle <= 0)
        car.event_for_parts("axles", car.wearDown.BASE_AXLES, axle);
    
    if (tongue <= 0)
        car.event_for_parts("tongues", car.wearDown.BASE_TONGUES, tongue);

    if (ox <= 0)
    {
        car.killOxen();
        ox = 100;
    }
} // applyWearDown
////////////// CARAVAN ////////////////////
// statics
double Caravan::caravanWeight = 0; // needed for Supplies::useSupplies()
int Caravan::slowerPace = 0; // [-15, 0], changed by broken wagon parts, use anywhere that deals w/ pacing...
                               // dealt w/: subDistance

// multi-liners
Caravan::Caravan(): MAX_WEIGHT(2000)
{
    // caravan Weight
    //caravanWeight = food.getWeight();
    //caravanWeight += medicine.getWeight();
    //caravanWeight += huntingGear.getWeight();
    //caravanWeight = supply.getWeight();
    //caravanWeight = 0;
    oxen = 0;
    rationing = "full";
    distance = 2000;
    money = 1500;
    days = 0;
    pacing = "steady";
    it = people.begin();
} // constructor 
bool Caravan::getPerson(People& p, const string& name)
{
    // no people OR no such name
    if (people.empty()) return false;
    if (people.find(name) == people.end()) return false; // map.find returns an iterator
    
    // get person
    p = people[name]; ///////////*************** FIX ******************
    return true;
} // getPeople
bool Caravan::eatFood()
{
    int eaten = people.size() * 2; // 2 pounds per person
    if (rationing == "full") eaten *= 5;
    else if (rationing == "ample") eaten *= 4;
    else if (rationing == "meager") eaten *= 2;
    
    supply.useSupplies("food", eaten);

    // check on food
    if (supply.getSupplies("food").amount <= 100)
        if (!goHunting()) // if true -> food won't be at 0
            if (supply.getSupplies("food").amount == 0) return true;

    return false;
} // eatFood
void Caravan::subDistance()
{
    int travel = 5; // pacing == slow
    if (pacing == "blazing") travel = 20;
    else if (pacing == "fast") travel = 15;
    else if (pacing == "steady") travel = 8;
    
    // account for broken parts
    travel += slowerPace;
    if (travel < 5) travel = 5; // cap at 'slow', avoid negative travel

    distance -= travel;
    if (distance < 0) distance = 0;
} // subDistance
void Caravan::sick(bool noFood)
{
    bool noClothes = supply.getSupplies("clothes").amount <= 0;

    for (it = people.begin(); it != people.end(); it++)
    {
        it->second.makeSick();
        it->second.checkHealth(rationing, pacing, noFood, noClothes);
        it->second.treatSickness();
    } // iterate over people in caravan
} // sick
void Caravan::restCaravan(int rest)
{
    while (rest > 0)
    {
        // deal w/ food
        bool noFood = eatFood();
        bool noClothes = supply.getSupplies("clothes").amount <= 0;
        
        // deal w/ people
        for (std::map<string, People>::iterator iter = people.begin(); iter != people.end(); iter++)
        {
            iter->second.checkHealth(rationing, "stopped", noFood, noClothes);
            iter->second.treatSickness();
        }

        wearDown.applyWearDown(*this, pacing); // wear on items
        days++;
        rest--;
    } // while
} // restCaravan
void Caravan::runCaravan()
{
    subDistance();
    sick(eatFood()); // eat food, do sick stuffs
    wearDown.applyWearDown(*this, pacing); // wear on items
    days++;
} // runCaravan
bool Caravan::goHunting()
{
    // variables
    int foodGained = 0;
    int ammo = supply.getSupplies("bullets").amount;
    char answer = 'y';
    bool hasRifle = true;
    if (supply.getSupplies("rifles").amount == 0) hasRifle = false;

    // prompt
    std::cout << "\nYou have " << supply.getSupplies("food").amount
              << " pounds of food left, would you like to go hunting(y/n)? ";
    std::cin >> answer;

    // don't hunt
    if (answer != 'y' && answer != 'Y') return false;
    else if (ammo <= 0)
    {
        std::cout << "You don't have any bullets left.\n";
        return false;
    }
    else if (!hasRifle)
    {
        std::cout << "You don't have a rifle.\n";
        return false;
    }

    // hunt
    while(answer == 'y' || answer == 'Y')
    {
        // check on rifle
        if (wearDown.rifle <= 0 || !hasRifle)
        {
            std::cout << "Your rifle has broken, ";
            if (hasRifle)
            {
                supply.useSupplies("rifles", 1); // rifle broken
                if (supply.getSupplies("rifles").amount == 0)
                    hasRifle = false; // no more rifles
                wearDown.rifle = 100;           // reset rifle condition (in prep for new rifle)
            }

            if (!hasRifle)
            {
                std::cout << "you don't have a replacement.\n";
                return true;  // hunted at least once
            }

            std::cout << "you found a replacement.\n";
        } // if broken rifle or none exist

        // do hunting and print results
        supply.useSupplies("bullets", 1);            // shot bullet
        wearDown.rifle -= (rand() % 4 + 1);          // wear on rifle
        ammo = supply.getSupplies("bullets").amount; // bullets left
        foodGained += (rand() % 46) + 5;  // got some food (5-50 pounds)
        std::cout << "\nYou have " << ammo
                  << " bullets left and gained " << foodGained 
                  << " pounds of food total.\n";

        // check ammo
        if (ammo == 0) // did actually hunt but can't anymore
        {
            std::cout << "You have run out of bullets.\n";
            break; 
        }

        // prompt continuation
        std::cout << "Keep hunting(y/n)? ";
        std::cin >> answer;
    }

    // cap food gain at 300 pounds
    if (foodGained > 300)
    {
        foodGained = 300;
        std::cout << "You were only able to carry back 300 pounds.\n";
    }

    // add food gain to supplies
    supply.setSupplies("food", supply.getSupplies("food").amount + foodGained);
    return true;
}
void Caravan::first(People& person)
{
    assert(people.begin() != people.end());

    it = people.begin();
    person = it->second;
}
bool Caravan::next(People& person)
{
    it++;
    if (it == people.end()) return false;
    person = it->second;
    return true;
}
bool Caravan::spendMoney(int dollars)
{
    if (dollars > money) return false;
    money -= dollars;
    return true;
} // spendMoney
void Caravan::addSupply(const string& name, int amt, int cost /*=0*/)
{
    // fix slowerPace if necessary, do 1st since adding supplies changes things
    if (name == "wheels" && supply.getSupplies(name).amount < wearDown.BASE_WHEELS)
    {
        // +1 for each replaced wheel
        if (wearDown.BASE_WHEELS - amt <= 0) slowerPace += 4; // all replaced
        else slowerPace += amt; // some replaced, or none
    }

    if (name == "axles" && supply.getSupplies(name).amount < wearDown.BASE_AXLES)
    {
        // +3 for each replaced axle
        if (wearDown.BASE_AXLES - amt <= 0) slowerPace += 6; // both replaced
        else slowerPace += 3 * amt; // 1 replaced, or 0
    }

    if (name == "tongues" && supply.getSupplies(name).amount < wearDown.BASE_TONGUES)
    {
        // +5 for the replaced tongue
        if (wearDown.BASE_TONGUES - amt <= 0) slowerPace += 5; // replaced it
    }
    

    money -= cost; // make purchase
    supply.addSupplies(name, amt);
} // addSupply
void Caravan::showSupplies()
{
    // supply info
    string name; itemInfo info;
    supply.first(name, info);

    // print supply name + amount
    std::cout << "Your curent supplies:\n";
    do
    {
        std::cout << name;
        int spaces = 10 - name.size();
        for (int i = 0; i < spaces; i++) std::cout << " ";
        std::cout << info.amount;
        if (name == "bullets" || name == "food")
        {
            std::cout << std::endl;
            continue; // stop if not on condition'ed item
        }

        // print current item's condition
        if (info.amount != 0) // only bother if item exists
        {
            std::cout << ", ";
            if (name == "clothes")      std::cout << "current set at " << wearDown.cloth;
            else if (name == "rifles")  std::cout << "current rifle at " << wearDown.rifle;
            else if (name == "axles")   std::cout << "worst axle at " << wearDown.axle;
            else if (name == "tongues") std::cout << "current tongue at " << wearDown.tongue;
            else std::cout << "worst wheel at " << wearDown.wheel;
            std::cout << "% health.\n";
        }

        else std::cout << std::endl;
    } while (supply.next(name, info));

    std::cout << "oxen      " << oxen << ", sickest one at "
              << wearDown.ox << "% health.\n";
} // showSupplies
void Caravan::event_for_parts(const string& name, int base, int& durability)
{
    int numParts = supply.getSupplies(name).amount;
    if (numParts > 0)  // else (== 0) all parts broken -> don't do anything
    {
        // print event message
        std::cout << "1 of the " << name << " has broken.";
        if (numParts > base)
            std::cout << " You replaced it with a spare.\n";
        else
        {
            std::cout << " You could not find a spare,"
                       << " but managed to fix it somehow.\n";

            // pace slowers since dealing w/ broken stuff
            if      (name == "wheels") slowerPace += -1;
            else if (name == "axles")  slowerPace += -3;
            else                       slowerPace += -5; // name == "tongues"
            assert (slowerPace < 1 && slowerPace > -16);
        }

        // use 1 part in supply, reset durability
        supply.useSupplies(name, 1);
        durability = itemWearDown::MAX_WEAR;
    }
} // event for broken wagon parts


// 1-liners
double Caravan::getCaravanWeight() const {return caravanWeight;}                            // getCaravanWeight
itemInfo Caravan::getCaravanSupplies(const string& name) {return supply.getSupplies(name);} // getCaravanSupplies
int Caravan::getMoney() const {return money;}   // getMoney
void Caravan::killOxen() {if (oxen > 0) oxen--;}// killOxen
void Caravan::setSupply(const string& name, int amt) {supply.setSupplies(name, amt);} // setSupply
void Caravan::setPerson(const People& p) {people[p.getName()] = p;}                   // setPerson
void Caravan::useSupply(const string& name, int amt) {supply.useSupplies(name, amt);} // useSupply
int Caravan::getDistance() const {return distance;}    // getDistance
void Caravan::setDistance(int dist) {distance = dist;} // setDistance
int Caravan::getOxen() const {return oxen;}  // getOxen
void Caravan::setOxen(int ox) {oxen = ox;}   // setOxen
string Caravan::getRationing() const {return rationing;}               // getRationing
void Caravan::setRationing(const string& ration) {rationing = ration;} // setRationing
string Caravan::getPacing() const {return pacing;}            // getPacing
void Caravan::setPacing(const string& pace) {pacing = pace;}  // setPacing
void Caravan::earnMoney(int dollars) {money += dollars;} // add money

// working on
void Caravan::eventHandler(){} // no use yet

///////////////////// PIT-STOP F()S ///////////////////////
// making static struct etc FAILS
int city::operator-(const city& c) const
{
    return (this->location - c.location);
}

void visitPitStop(const string& town, Caravan& car)
{
    // print city name
    std::cout << "\n\nVisiting " << town << std::endl << "-------------\n";

    // loop city menu
    while (true)
    {
        printCityMenu();
        int answer = 1;
        std::cin >> answer;
        std::cout << std::endl;

        if (answer == 2) car.goHunting();
        else if (answer == 3) visitStore(car);
        else if (answer == 4) car.restCaravan(1);
        else if (answer == 5) car.showSupplies();
        else break; // answer == 1
    }
} // visitPitStop
void printCityMenu()
{
    std::cout << "1 Return to the trail\n"
              << "2 Hunt\n"
              << "3 Shop\n"
              << "4 Rest\n"
              << "5 Check supplies\n"
              << "Enter the number for your choice: ";
} // printCityMenu
void visitStore(Caravan& car)
{
    // supplies to purchase
    int item = 1; int amount = 0; string supplyName = "";
    int cost[7] = {5, 2, 3, 35, 70, 53, 43}; // clothes, bullet box, food, wheel, axle, tongue, rifle
                                             // index by item - 2 since options start at choice #2
    int spend = 0; // cost * amount

    while(true)
    {
    // print menu
    std::cout << "\nWelcome to the store:\n"

              // current caravan weight + money
              << "Your caravan can carry "
              << (int)(car.MAX_WEIGHT - car.getCaravanWeight())
              << " more pounds.\n"
              << "You have $" << car.getMoney() << std::endl

              // options
              << "1 Done shopping\n"
              << "2 Buy sets of clothes: $" << cost[0] << std::endl
              << "3 Buy boxes of bullets: $"  << cost[1] << std::endl
              << "4 Buy pounds of food: $" << cost[2] << std::endl
              << "5 Buy wheels: $" << cost[3] << std::endl
              << "6 Buy axles: $" << cost[4] << std::endl
              << "7 Buy tongues: $"  << cost[5] << std::endl
              << "8 Buy rifles: $" << cost[6] << std::endl
              
              // choice
              << "Enter the number for your choice: ";

    // determine course of action
    while (true)
    {
        std::cin >> item;
        if (item > 7) std::cout << "INVALID OPTION, RETRY: ";
        else break;
    }

    if (item == 1) return;
    std::cout << "How much do you want to buy?: ";
    std::cin >> amount;

    // process transacition
        // find + display cost
        spend = cost[item - 2] * amount; // get cost of supplies
        std::cout << "Your total comes to $" << spend << std::endl;

        // determine name of item to buy
        if (item == 2) supplyName = "clothes";
        else if (item == 3) {supplyName = "bullets"; amount *= 20;}
        else if (item == 4) supplyName = "food";
        else if (item == 5) supplyName = "wheels";
        else if (item == 6) supplyName = "axles";
        else if (item == 7) supplyName = "tongues";
        else supplyName = "rifles";
        
        // check potential caravan weight + monetary status
        while (true)
        {
            double itemWeight = car.getCaravanSupplies(supplyName).weight;
            double potentialWeight = car.getCaravanWeight() + (itemWeight * amount);
            if (potentialWeight > car.MAX_WEIGHT)
            {
                int purchaseMax = (car.MAX_WEIGHT - car.getCaravanWeight()) / itemWeight;
                std::cout << "Too much, caravan will go over weight limit."
                          << " Can purchase at most " << purchaseMax << std::endl;

                std::cout << "How much do you want to buy?: ";
                std::cin >> amount;
                continue;
            }

            if (spend > car.getMoney())
            {
                int purchaseMax = car.getMoney() / cost[item - 2];
                std::cout << "You don't have enough money."
                          << " You can purchse at most " << purchaseMax << std:: endl;

                std::cout << "How much do you want to buy?: ";
                std::cin >> amount;              // get new amount
                spend = cost[item - 2] * amount; // get new cost
            } 
            else break;
        } // while (check weight)

        // add in the supplies
        car.addSupply(supplyName, amount, spend);   
    } // while (run f())
} // visitStore

///////////////////////// TESTING F()S ////////////////////////
void testFood()
{
    // verify f() called
    std::cout << "checking on food\n";

    // variables for helpful'ness
    string name;
    itemInfo info;

    // constructor
    Food f;

    // setFood
    name = "apple"; f.setFood(name, 5); // >
    name = "beans"; f.setFood(name, 11);
    f.setFood(name, 11);                // ==
    name = "apple"; f.setFood(name, 3); // <

    // getWeight -> 3 apples (1.5) + 11 beans (8.8) = 10.3
    //   off at most by .5
    assert(f.getWeight() >= 10.2 && f.getWeight() <= 10.4);

    // getFood, first, next
    f.first(name, info);
    do {assert(info == f.getFood(name));}
        while (f.next(name, info));
          
        // set rest of food
        f.first(name, info);
        do
        {
            f.setFood(name, 5);     // set current food
            info = f.getFood(name); // get new info
        } while (f.next(name, info));

    // next thing to test...
         // std::cout << name << ": " << info.amount
         //         << " " << info.weight << std::endl;
} // testFood

void testSupplies()
{
    // verify f() called
    std::cout << "checking on supplies\n";

    // variables for helpful'ness
    string name;
    itemInfo info;

    // constructor
    Supplies s;

    // getSupplies
    name = "rifle"; s.setSupplies(name, 5); // >
    name = "clothes"; s.setSupplies(name, 11);
    s.setSupplies(name, 11);                // ==
    name = "rifle"; s.setSupplies(name, 3); // <

    // getWeight -> 3 rifles (84) + 11 setsOfClothes (16.5) = 100.5
    //   off at most by .5
    assert(s.getWeight() >= 100.0 && s.getWeight() <= 101.1);

    // getSupplies, first, next
    s.first(name, info);
    do {assert(info == s.getSupplies(name));}
        while (s.next(name, info));
          
        // set rest of supplies to 5 each
        s.first(name, info);
        do
        {
            s.setSupplies(name, 5);     // set current supply
            info = s.getSupplies(name); // get new info
        } while (s.next(name, info));

    // useSupplies
    std::cout << "Old wagon weight = " << s.getWeight() << std::endl; // 628.5
    if (s.useSupplies("clothes", 3)) // had 5, use 3, now have 2 -> weight -= 4.5
    {
        std::cout << "clothes = " << s.getSupplies("clothes").amount;
        std::cout << "\nNew wagon weight = " << s.getWeight() << std::endl; // 624
    }
    else std::cout << "FAIL\n";
} // testSupplies

void testPeople()
{ 
    // verify f() called
    std::cout << "checking on people\n";

    // default constructor, accessors
    People ppl;
    assert("John Wilkenson" == ppl.getName());
    assert("very good" == ppl.getHealth());
    assert("stuffed" == ppl.getHunger());
    assert(ppl.getSickness().empty()); 

    // name constructor, mutators
    People person("Harry Henderson");
    assert("Harry Henderson" == person.getName());
    person.setHealth(49); assert("poor" == person.getHealth());
    person.setHunger(66); assert("hungry" == person.getHunger());
    person.makeSick(); std::cout << person.getSickness() << std::endl; // uses RNG
} // testPeople

void testCaravan()
{
    // verify f() called
    std::cout << "checking on caravan\n";

    // constructor: weight, oxen, distance
    Caravan car; 
    assert(car.getCaravanWeight() == 0 && car.getOxen() == 0);

    // mutators + accessors
        // create 3 People objects and set 2
        People p1("Matt Beaux"); People p2; People p3("Hank");
        p1.setHealth(50);
        p2.setHunger(10); 

        // mutators
        car.setSupply("rifle", 2); // calls supplies.setSupplies
        car.setPerson(p1);
        car.setOxen(15);
        car.setPerson(p2);
        car.setDistance(545);
        car.setRationing("Ample");
        car.setPacing("fast");

        // accessors - most
        assert(2 == car.getCaravanSupplies("rifle").amount); // calls supplies.getSupplies
        assert(car.getCaravanWeight() == 56);
        assert(car.getOxen() == 15);
        assert(car.getDistance() == 545);
        assert(car.getRationing() == "Ample");
        assert(car.getPacing() == "fast");

        // accessor - getPerson
        assert(car.getPerson(p3, "John Wilkenson")); // p3 = p2
        assert(p3.getHunger() == "starving"); 

        // subDistance
        int dist = car.getDistance();
        car.subDistance();
        assert(car.getDistance() == (dist - 15));
} // testCaravan

void testClasses()
{
    srand(0); // seed random # generator

    //testFood();
    //std::cout << "food ran\n\n";

    testPeople();
    std::cout << "people ran\n\n";

    testCaravan();
    std::cout << "caravan ran\n\n";

    testSupplies();
    std::cout << "supplies ran\n\n";

    system("Pause");
}
////////////////////////          ///////////////////////////