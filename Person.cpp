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
