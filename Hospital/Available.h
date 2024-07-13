// Available.h
#ifndef AVAILABLE_H
#define AVAILABLE_H

#include <iostream>
#include <string>
#include <ctime>

class Available {
private:
    char DayOfWeek[7][15], shift1[25], shift2[25];
    int i, NoD;

public:
    void whenAvailable();
    void displayAvailable();
};

#endif // AVAILABLE_H
