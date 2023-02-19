#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n = 4;
    int m = 4;
    cout << (1 << (n*m)) << pow(2, n*m);
}