#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

struct Person {
  char name[20];
  float balance;
};

void display(vector<Person>, int);
void findRichest(vector<Person>, int);
void deposit(string, vector<Person> &v, int);
void newCopy(const char*,vector<Person>, int);

int main() {
  cout << "in main" << endl;

  vector<Person> people;
  ifstream inData;
  inData.open("data.txt");
  string fname;
  string lname;
  string fullname;
  string r;
  char n[20];
  float b;
  Person p;
  while (!inData.eof()) {
    inData  >> fname;
    inData >> lname;
    inData >> b;
    fullname = fname + " " + lname;
    strcpy(p.name, fullname.c_str());
    p.balance = b;
    people.push_back(p);
    getline(inData, r); 
  }
  inData.close();

  cout << "file read" << endl;
  
  display(people, people.size());
  findRichest(people, people.size());
  deposit("Maria Brown", people, people.size());
  newCopy("data.txt", people, people.size());
  display(people, people.size());
  return 0;
}

void display(vector<Person> v, int n) {
  cout << "\tName\tBalance" << endl;
  cout << "\t--------------------" << endl;
  for (int i = 0; i < n; i++) {
    cout << "\t" << v[i].name << " " << v[i].balance << endl;
  }
}

void findRichest(vector<Person> v, int n) {
  float highest = 0;
  int highestIndex = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].balance > highest) {
      highest = v[i].balance;
      highestIndex = i;
    } 
  }
  cout << "The customer with the maximum balance is ";
  for (int i = 0; i < strlen(v[highestIndex].name); i++) {
    cout << v[highestIndex].name[i];
  } 
  cout << endl;
}

void deposit(string cust, vector<Person> &v, int n) {
  float deposit;
  cout << "Enter your full name to deposit money: " << cust << endl;
  cust = cust.c_str();
  int found = -1;
  for (int i = 0; i < n; i++) {
    if (cust == v[i].name) {
      found = i;
    }
  }
  if (found == -1) {
    cout << "Customer not found!" << endl;
  }
  else {
    cout << cust << ", how much would you like to deposit? ";
    cin >> deposit;
    v[found].balance += deposit;
    cout << cust << ", your new balance is " << v[found].balance << endl;
  }
}

void newCopy(const char* f, vector<Person> v, int n) {
  ofstream data;
  data.open(f);
  cout << "NEW COPY" << endl;
  for (int i = 0; i < n-1; i++) {
    data << v[i].name << " " << v[i].balance << endl;
  }
  data.close();
}
