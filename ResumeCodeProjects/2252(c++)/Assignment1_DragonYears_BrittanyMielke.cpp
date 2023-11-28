/*==========================================================

 Title:       Assignment 1 - Dragon Years
 Course:      CIS 2252
 Author:      <Brittany Mielke>
 Date:        < 9/6/23 >
 Description: This program converts your dragon mounts age into wizard years:
              * the 1st 2 years of a dragons life = 21 wizard years
              * each year following counts as 4 wizard years

 ==========================================================
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
  string name;
  float dragonAge;
  
  cin >> name;
  cin >> dragonAge;
  
  if(dragonAge <= 2){
      cout << "Dragon Mount must be 2 years old (21 wizard years).";
      
  } else {
      float wizardAge = ((dragonAge - 2) * 4) + 21;
      
  cout << "The dragon named " 
       << name 
       << " is " 
       << wizardAge 
       << " years old in wizard years.";
  }   
  return 0;
}



