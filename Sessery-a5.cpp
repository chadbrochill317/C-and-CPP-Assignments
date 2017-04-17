// Assignment 5

#include<iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

struct Student{
  string fname;
  string lname;
  double exams[4];
  char grade;
};

struct Best{
  string fname;
  string lname;
  double mark;
};

string get_file_name(){
   cout << "File Name: ";
   string fname;
   cin >> fname;
   cout << endl;
   return fname;
}

void getinfo (fstream & myfile, Student * cs211, int & n){
  n = 0;
  while (!myfile.fail()){
     myfile >> cs211[n].fname >> cs211[n].lname;
     if (!myfile.fail()){
       for (int i=0; i<3; i++)
          myfile >> cs211[n].exams[i];
       n++;
     }
  }
}

char grade (int rounded){
    if (rounded < 50)
       return 'F';
    else if (rounded < 65)
       return 'C';
    else if (rounded < 80)
        return 'B';
    else return 'A';
}

void calculate_total_grade (Student * cs211, int n){
  for (int i=0; i<n; i++){
    cs211[i].exams[3] = 0;
    for (int j=0; j<3; j++)
       cs211[i].exams[3] += cs211[i].exams[j];
    cs211[i].exams[3] = cs211[i].exams[3]/3;

    int rounded = cs211[i].exams[3];
    cs211[i].grade = grade(rounded);
  }
}

void sort(Student * cs211, int n){
  for (int i=0; i<n-1; i++)
    for (int j=0; j<n-i-1; j++)
       if (cs211[j].lname > cs211[j+1].lname)
          swap (cs211[j], cs211[j+1]);
}

void print_data(Student * cs211, int n){
  cout << left << setw(8) << "Fname" << setw(8) << "Lname";
  cout << right << setw(12) << "Quiz" << setw(12) << "Mid" << setw(12) << "Final";
  cout << setw(12) << "Total" << setw(8) << "Grade" << endl ;
  cout << left << setw(8) << "-----" << setw(8) << "-----";
  cout << right << setw(12) << "----" << setw(12) << "---" << setw(12) << "-----";
  cout << setw(12) << "-----" << setw(8) << "-----" << endl ;
  for (int i=0; i<n; i++){
     cout << left << setw(8) << cs211[i].fname << setw(8) << cs211[i].lname;
     cout << fixed << setprecision(1);
     for (int j=0; j<4; j++)
        cout << right << setw(12) << cs211[i].exams[j];
     cout << setw(8) << cs211[i].grade << endl;
  }
  cout << endl;
}

void print_av (Student * cs211, int n){
  double ave[4];
    // average for each of the 4 components
  for (int j = 0; j < 4; j++){
      // calculating the averages
      ave[j] = 0;
      for (int i=0; i<n; i++)
         ave[j] += cs211[i].exams[j];
      ave[j] = ave[j]/n;
  }
    
    // print
  cout << left << setw(16) << "Class Average";
  for (int i=0; i<4; i++)
     cout << right << setw(12) << ave[i];
  cout << setw(8) << grade(round(ave[3]));
  cout << endl ;
}

void print_best(Student * cs211, int n){
   int best[4];
    // index of best student
   for (int j = 0; j < 4; j++){
      best[j] = 0;
      for (int i=0; i<n; i++)
        if (cs211[i].exams[j] > cs211[best[j]].exams[j])
           best[j] = i;
   }
    
    // printing best grade
   cout << left << setw(16) << "Highest";
   for (int i=0; i<4; i++)
      cout << right << setw(12) << cs211[best[i]].exams[i];
   cout << setw(8) << grade(round(cs211[best[3]].exams[3]));
   cout << endl;
   cout << left << setw(16) << " ";
   string name;
   for (int i=0; i<4; i++){
      name = "(" + cs211[best[i]].fname.substr(0,1) + ". " + cs211[best[i]].lname + ")";
      cout << right << setw(12) << name;
   }
   cout << endl << endl;
}

int main(){
  fstream myfile;
  string file_name = get_file_name();
  myfile.open (file_name.c_str());

  int size = 50;
  Student * cs211 = new Student[size];
  int n;

  getinfo (myfile, cs211, n);
  myfile.close();

  calculate_total_grade(cs211, n);

  sort (cs211, n);
  print_data (cs211, n);

  print_av (cs211, n);
  print_best(cs211, n);
}

