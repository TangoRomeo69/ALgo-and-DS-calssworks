#include <iostream>
#include <cstdlib>
using namespace std;

int factorial(int num){
  if(num == 1){
    return 1;
  }
  return (num * factorial(num-1));
}

int main(){
  int  n = 0, result = 0;
  cout<<"Insert the number to  find factorial: ";
  cin>>n;
  result = factorial(n);
  cout<<"Factorial of the number is: "<<result<<endl;
  return 0;
}
