// Patient.h
#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"
#include "Disease.h"
#include <fstream>

class Patient : public Person {
private:
    int patientID;
    Disease disease;
    std::string appointmentDate;
    char patientFile[20] = "patientData.dat";
    char patientTempFile[20] = "patientData2.dat";

public:
    void getPatientInformation();
    void addPatient();
    void showPatientData();
    void showPatientDataFromFile();
    void dischargePatient();
    void editPatient();
    void doPatientRelateWork();
};

#endif // PATIENT_H


