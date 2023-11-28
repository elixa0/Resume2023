/*==========================================================

 Title:       Assignment 8 - Arena Area Inheritance
 Course:      CIS 2252
 Author:      <Brittany & Mielke>
 Date:        < 11/03/23 >
 Description: This program ....
            
            compute the area of wizard competition arena 
 ==========================================================
*/

#include <iostream>
#include <cmath>
using namespace std;

//Create classes Arena and ArenaArea here
class Arena{
    public:
    int radius;
    
   virtual void display(){
        cout << radius * radius;
    }
};

class ArenaArea: public Arena{
    
    public:
    
   void scan_input(){
        cin >> radius;
    }
    void display() override {
        cout << pow(radius, 2) * 3.14 ;
    }
};

int main()
{
    //DO NOT MODIFY ANYTHING IN THE main() !!!
    
    ArenaArea stadium; //Declaring ArenaArea object stadium
    
    stadium.scan_input(); //Read the radius input
    
    stadium.Arena::display(); //Print the radius squared
    
    cout << endl;
    
    stadium.display(); //Print the area of the Arena (stadium) object
    
    return 0;
}
