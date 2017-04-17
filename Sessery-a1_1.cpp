// Assignment 1

#include<iostream>
#include<iomanip>
using namespace std;
int main(){
   const double EI = 0.024;
   const double UNION = 0.01;
   const double TAX= 0.17;
   string name;
   double hrs;                        // number of hours worked
   double rate;                    // hourly rate

//  input
   cout << "Enter name: ";
   cin >> name;
   cout << "How many hours: ";
   cin >> hrs;
   cout << "Hourly rate: ";
   cin >> rate;
   cout << endl << endl;

// Calculations
   double gross = hrs * rate;
   double empl_ins = gross * EI;
   double union_dues = gross * UNION;
   double taxes = gross * TAX;
   double deductions = empl_ins + union_dues + taxes;
   double net = gross - deductions;

// Output
   cout << left << setw(20) << "Employee name:" << name << endl << endl;
   cout << "Hours worked:        " << setw(10) << hrs << endl;
   cout << "Hourly rate:         " << setw(10) << rate << endl << endl;

   cout << "Gross Pay:" << setw(30) << gross <<endl << endl;

   cout << "Deductions\n";
   cout << "   Union Dues:          " << setw(7) << union_dues << endl;
   cout << "   Employment Insurance:" << setw(7) << hrs << endl;
   cout << "   Taxes:               " << setw(7) << rate << endl << endl;

   cout << "Total Deductions:       " << setw(7) << deductions << endl << endl;
   cout << setw(10) << "Net Pay:  " << setw(30) << gross <<endl << endl;
}
