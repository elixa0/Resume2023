/*==========================================================

 Title:       Assignment 7 - Wizard Identification using Classes
 Course:      CIS 2252
 Author:      <Brittany Mielke>
 Date:        < 10/26/23 >
 Description: This program ....
              creates a class for storing a wizards data.
 ==========================================================
*/

#include <iostream>

using namespace std;

//Create your class Wizard here.
class Wizard {
    
    public:
    int age, id;
    string firstName, lastName;
    
    //get
    int get_wizardAge(){
        return age;
    }
    int get_wizard_ID(){
        return id;
    }
    string get_wizardFirstName(){
        return firstName;
    }
    string get_wizardLastName(){
        return lastName;
    }
    //set
    void set_wizardAge(int Age){
        age = Age;
    }
    void set_wizard_ID(int ID){
        id = ID;
    }
    void set_wizardFirstName(string first){
        firstName = first;
    }
    void set_wizardLastName(string last){
        lastName = last;
    }
    
};

int main() {
//DO NOT MODIFY THE MAIN()!!!!
    int wizardAge, wizard_ID;
    string wizardFirstName, wizardLastName;
    
    cin >> wizardAge >> wizardFirstName >> wizardLastName >> wizard_ID;
    
    Wizard wiz;
    wiz.set_wizardAge(wizardAge);
    wiz.set_wizard_ID(wizard_ID);
    wiz.set_wizardFirstName(wizardFirstName);
    wiz.set_wizardLastName(wizardLastName);
    
    cout << wiz.get_wizardAge() << "\n";
    cout << wiz.get_wizardLastName() << ", " << wiz.get_wizardFirstName() << "\n";
    cout << wiz.get_wizard_ID();
    
    return 0;
}
