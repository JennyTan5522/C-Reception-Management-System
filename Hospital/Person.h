// Person.h
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
private:
    int age;
    char name[30], address[30], email[30], phoneNo[30];

public:
    void getPersonData();
    void showPersonData();
};

#endif // PERSON_H