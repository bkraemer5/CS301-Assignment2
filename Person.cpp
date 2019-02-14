#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "ExtendableVector.h"

using namespace std;

struct Person {
  char name[20];
  float balance;
};

void display(ExtendableVector<Person>  v, int n);
void findRichest(ExtendableVector<Person> v, int n);

int main() {

  int fileSize = 0;
  string line;

  ifstream inData;
  inData.open("data.txt");
  while (inData) {
    getline(inData, line);
    fileSize++;
  } 
  inData.close();

  ExtendableVector<Person> people(fileSize);

  inData.open("data.txt");
  char fname[9];
  char lname[9];
  char n[20];
  float b;
  Person p;
  for (int i = 0; i < fileSize; i++) {
    cin >> fname;
    cin >> lname;
    cin >> b;
    strcat(n, fname);
    strcat(n, " ");
    strcat(n, lname);
    strcat(p.name, n);
    p.balance = b;
    people.insert(i, p);
  }
  inData.close();
  
  display(people, fileSize);
  findRichest(people, fileSize);
  return 0;
}

void display(ExtendableVector<Person> v, int n) {
  cout << "\tName\tBalance" << endl;
  cout << "\t--------------------" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < strlen(v.at(i).name); j++) {
      cout << v.at(i).name[j];
    }
    cout << " " << v.at(i).balance << endl;
  }
}

void findRichest(ExtendableVector<Person> v, int n) {
  float highest = 0;
  int highestIndex = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v.at(i).balance > highest) {
      highest = v.at(i).balance;
      highestIndex = i;
    } 
  }
  cout << "The customer with the maximum balance is ";
  for (int i = 0; i < strlen(v.at(highestIndex).name); i++) {
    cout << v.at(highestIndex).name[i];
  } 
  cout << endl;
}
