// Doctor.h
#ifndef DOCTOR_H
#define DOCTOR_H

#include "Available.h"
#include "Disease.h"
#include "Person.h"
#include <fstream>

class Doctor : public Person {
private:
    int doctorID;
    Disease disease;
    Available available;
    char doctorFile[20] = "doctorData.dat";
    char doctorTempFile[20] = "doctorData2.dat";

public:
    void getDoctorData();
    void showDoctorData();
    void addDoctorData();
    void showDoctorDataFromFile();
    void deleteDoctor();
    void editDoctor();
    void doDoctorRelatedWork();
};

#endif // DOCTOR_H
