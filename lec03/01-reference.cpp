#include<iostream> 

using namespace std; 
  
int main() 
{ 
  int x = 10; 
  
  // ref je reference na x 
  int& ref = x; 
  
  // hodnota x je nyni zmenena na 20 
  ref = 20; 
  cout << "x = " << x << endl ; 
  
  // hodnota x je nyni zmenena na 30 
  x = 30; 
  cout << "ref = " << ref << endl; 
  
  return 0; 
} 
