// Assignment 3

#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

// find the number of days in that particular month
int find_max_days (int month, int year){
  int max_days;
  switch (month){
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: max_days = 31; break;
    case 4: case 6: case 9: case 11: max_days = 30; break;
    case 2: if (year % 4 != 0 || year%100==0 && year%400!=0)
               max_days = 28;
            else max_days = 29; break;
    default: break;
  }
  return max_days;
}

// find the name of the month
string month_name(int month){
  string mth;
  switch (month){
    case 1: mth = "January"; break;
    case 2: mth = "February"; break;
    case 3: mth = "March"; break;
    case 4: mth = "April"; break;
    case 5: mth = "May"; break;
    case 6: mth = "June"; break;
    case 7: mth = "July"; break;
    case 8: mth = "August"; break;
    case 9: mth = "September"; break;
    case 10: mth = "October"; break;
    case 11: mth = "November"; break;
    case 12: mth = "December"; break;
    }
  return mth;
}

string day_of_week(int pos){
   string day_string;
   switch (pos%7){
     case 1: day_string = "Sunday"; break;
     case 2: day_string = "Monday"; break;
     case 3: day_string = "Tuesday"; break;
     case 4: day_string = "Wednesday"; break;
     case 5: day_string = "Thursday"; break;
     case 6: day_string = "Friday"; break;
     case 0: day_string = "Saturday"; break;
  }
  return day_string;
}

void draw_month (int &first, int month, int year){
// print a heading

  cout << "\n        Calendar for " << month_name(month) << " of "<< year <<endl<<endl;
  cout << " Sun Mon Tue Wed Thu Fri Sat\n";

// Print the whole month
  int day = 1;
  first = first % 7;
  cout << setw (first*4) << day; // position the "1" under the right day of the week
  int pos = first;
  int max_days = find_max_days (month, year);
  for (day = 2; day <= max_days; day++){        // look to print all the days
     if (pos % 7 == 0)              // go to a new line at the end of the week
        cout << endl;
     cout << setw(4) << day;
     pos++;
  }
  cout <<"\nThe month ends on a " << day_of_week(pos) << endl;
  cout << endl;
  first = pos + 1;
}

int main(){

  cout << "which year? ";
  int year;             // needed to decide whether it's a leap year (for February)
  cin >> year;
  cout << "enter the day of the week for the 1st of January (1=Sun, 2=Mon etc) ";
  int first;
  cin >> first;

  for (int month = 1; month <= 12; month++)
    draw_month (first, month, year);

}

