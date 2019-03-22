/*
Brittany Kraemer 
CS301 - 03
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

struct Person {
  char name[20];
  float balance;
};

void display(Person a[], int);
void findRichest(Person a[], int);
void deposit(Person a[], int, string, float);
void newCopy(const char*, Person a[], int);
Person * readData(int &n);

int main() {

  ifstream inData1;
  inData1.open("data.txt");
  int numOfPeople = 0;
  string line;
  while (!inData1.eof()) {
    getline(inData1, line);
    numOfPeople++;
  }
  inData1.close();


  Person* people = readData(numOfPeople);
  display(people, numOfPeople);
  findRichest(people, numOfPeople);
  deposit(people, numOfPeople, "Maria Brown", 100);
  newCopy("data.txt", people, numOfPeople);
  display(people, numOfPeople);
  return 0;
}

void display(Person a[], int n) {
  cout << "\tName\tBalance" << endl;
  cout << "\t--------------------" << endl;
  for (int i = 0; i < n-1; i++) {
    cout << "\t" << a[i].name << " " << a[i].balance << endl;
  }
}

void findRichest(Person a[], int n) {
  float highest = 0;
  int highestIndex = 0;
  for (int i = 0; i < n-1; i++) {
    if (a[i].balance > highest) {
      highest = a[i].balance;
      highestIndex = i;
    }
  }
  cout << "The customer with the maximum balance is " << a[highestIndex].name << endl;
}

void deposit(Person a[], int n, string custName, float amount) {
  int found = -1;
  for (int i = 0; i < n-1; i++) {
    if (custName == a[i].name) {
      found = i;
    }
  }
  if (found == -1) {
    cout << "Record not found!" << endl;
  }
  else {
    a[found].balance += amount;
    cout << a[found].name << ", your new balance is " << a[found].balance << endl;
  }
}

void newCopy(const char* f, Person a[], int n) {
  ofstream data;
  data.open(f);
  for (int i = 0; i < n-1; i++) {
    data << a[i].name << " " << a[i].balance << endl;
  }
  data.close();
  cout << "File updated..." << endl;
}

Person* readData(int &n) {
  Person* people = NULL;
  people = new Person[n];
  ifstream inData2;
  inData2.open("data.txt");
  string fname;
  string lname;
  string fullname;
  string r;
  float b;
  int index = 0;
  while (!inData2.eof()) {
    inData2 >> fname;
    inData2 >> lname;
    inData2 >> b;
    fullname = fname + " " + lname;
    strcpy(people[index].name, fullname.c_str());
    people[index].balance = b;
    getline(inData2, r);
    index++;
  }
  inData2.close();
  return people;
}
