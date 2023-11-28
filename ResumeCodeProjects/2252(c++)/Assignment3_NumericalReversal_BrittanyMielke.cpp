/*==========================================================

 Title:       Assignment 3 - Numerical Reversal
 Course:      CIS 2252
 Author:      <Brittany mielke>
 Date:        < 09/23/23 >
 Description: This program ....
              accept 2 inputs 
              first input is the size of the Array 
              second input will be the the numbers in the array

 ==========================================================
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int size;
    
  cin >> size;
  
  const int SIZE = size;
  string* array = new string[SIZE];
  
  for ( int i = 0; i < SIZE; i++){
      cin >> array[i];
      
  }
  
  for (int i = SIZE; i >= 0; i--){
       cout << array[i] << " ";
  }

  
  return 0;
}

