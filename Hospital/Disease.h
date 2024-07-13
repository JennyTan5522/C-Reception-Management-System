// Disease.h
#ifndef DISEASE_H
#define DISEASE_H

#include <iostream>
#include <string>

class Disease {
private:
    char diseaseName[30], virusName[20], specializationsName[20];

public:
    void getDiseaseDetails();
    void showDiseaseList();
    void getSpecializationDetails();
};

#endif // DISEASE_H