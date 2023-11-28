/*==========================================================

 Title:       Assignment 2 - Numerical Representation
 Course:      CIS 2252
 Author:      <Brittany Mielke>
 Date:        < 09/15/23 >
 Description: This program takes user input ( two numbers)
              Then, converts the Range of the numbers 
              to a lowercase string (one). -> only 1-9
              
              If the number is over 9 the output returns 'even' or 'odd'
              // program assumes first input is greater than the second
 ==========================================================
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    int inOne, inTwo;
           
    // user inputs 
    cin >> inOne;
    cin >> inTwo;
     
 
        
        while (inOne <= inTwo){
            
            switch (inOne) {
                case 1 : cout << "one\n";
                    break; 
                case 2 : cout << "two\n";
                    break;
                case 3 : cout << "three\n";
                    break;
                case 4 : cout << "four\n";
                    break;
                case 5 : cout << "five\n";
                    break;
                case 6 : cout << "six\n";
                    break;
                case 7 : cout << "seven\n";
                    break;
                case 8 : cout << "eight\n";
                    break;
                case 9 : cout << "nine\n";
                    break;
                default :
                     if (inOne %2== 0){
                         cout << "even\n";
                     } else { cout << "odd\n"; }
            } // end switch
            inOne++;
            
        } // end while
        

    
  return 0;
}

