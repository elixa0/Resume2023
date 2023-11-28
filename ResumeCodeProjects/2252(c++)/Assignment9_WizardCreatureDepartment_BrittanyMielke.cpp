/*==========================================================

 Title:     Assignment 9 - C++ Wizard Creature Department
 Course:  	CIS 2252
 Author:  	<Brittany & Mielke>
 Date:    	<11/17/23 >
 Description: store creature types , name , and quantity for
             new wizard's creature registration.

 ==========================================================
*/

#include <iostream>

using namespace std;

//Write classes here...
class Creature{
    public:
    string name;
    string creatureType = "unknown";
    int quantity;
    
    Creature (){}
    
    Creature (string Name, int Quantity){
        name = Name;
        quantity = Quantity;
    }
    string getName(){
        return name;
    }
    int getQuantity(){
        return quantity;
    }
    void setName(string Name){
        name = Name;
    }
    void setQuantity(int Quantity){
        quantity = Quantity;
    }
    void printStatement(){
       cout << "There's " << quantity <<
       " creatures named " << name << endl ;
    }
};

class Phoenix:public Creature{
    private:
    string color;
    
    public:
    string getColor(){
        return color;
    }
    void setColor(string Color){
        color = Color;
    }
    void printStatement(){
        cout << "There's " << quantity << " " <<
         color << " phoenixes named " 
        << name << endl;
    }
};

class Basilisk:public Creature{
    public:
    
    void printStatement(){
        quantity = 1;
        cout << "There's " << quantity 
        << " basilisk named " << name << endl;
    }
};

int main()
{
	//create empty array of size 3 for storing name
    string nameArr[3];

	// Write loop here to record user input as names
    // and set third name to “Clover”
    for(int i = 0; i < 2; i++){
        cin >> nameArr[i];
        nameArr[2] = "Clover";
    }

	Creature c(nameArr[0], 2);
	//print statement from class
	c.printStatement();

	Phoenix p;
	//sets name, quantity and color
	p.setName(nameArr[1]);
	p.setQuantity(3);
	p.setColor("golden");
    //print statement from class
	p.printStatement();

	Basilisk b;
    //sets name
	b.setName(nameArr[2]);
    //prints statement from class
	b.printStatement();

    
}

