// Assignment 1-2

#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

main(){
  cout << "enter a, b, c: ";
    double a;
    double b;
    double c;
    cin >> a >> b >> c;
    double x = b*b - 4 * a * c;
    double root1, root2;
    if (x == 0)                               // equal roots
        cout << "single root = " << -b/(2*a);
    else if (x > 0){                          // distinct roots
        root1 = (-b + sqrt(x))/(2*a);
        root2 = (-b - sqrt(x))/(2*a);
        cout << "root1 = " << root1 << endl << "root2 = " << root2;
  }
    else cout << "imaginary roots";           // imaginary (complex) roots
}
