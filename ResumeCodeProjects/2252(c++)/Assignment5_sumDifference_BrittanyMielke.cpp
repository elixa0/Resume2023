/*==========================================================

 Title:       Assignment 5 - Sum/Difference with Pointer
 Course:      CIS 2252
 Author:      <Brittany Mielke>
 Date:        < 10/07/23 >
 Description: This program ....

 ==========================================================
*/
using namespace std;
#include <iostream>
void Modify(int *x, int *y) {
    // store the sum of the 2 input nums in x
    *x = *x + *y;
    // store absolute Difference of the 2 input nums  in y 
    *y = ((*x - *y) - *y);
    if (*y < 0){
        *y = *y * -1;
    }
}

int main() {
    //DO NOT MODIFY ANYTHING IN THE main() !!!
    
    int x, y;
    
    int *ptr_x = &x;
    int *ptr_y = &y;
    
    cin >> x;
    cin >> y;
    
    Modify(ptr_x, ptr_y);
    
    cout << x << endl;
    cout << y;
                 
    return 0;
}
