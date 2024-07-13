#pragma warning(disable:4996)
// Person.h
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
private:
    int age;
    std::string name, address, email, phoneNo;

public:
    void getPersonData();
    void showPersonData();
    int getAge() const { return age; }  // Getter for age, if needed
};

#endif // PERSON_H


// Person.cpp
#include "Person.h"
using namespace std;

void Person::getPersonData() {
    cout << "\t\t\t\t Full Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "\t\t\t\t Age: ";
    cin >> age;

    cout << "\t\t\t\t Address: ";
    cin.ignore();
    getline(cin, address);

    cout << "\t\t\t\t Phone Number: ";
    getline(cin, phoneNo);

    cout << "\t\t\t\t Email: ";
    getline(cin, email);
}

void Person::showPersonData() {
    cout << "\t\t\t\t=============================================" << endl;
    cout << "\t\t\t\t             Personal Information             " << endl;
    cout << "\t\t\t\t=============================================" << endl;

    cout << "\t\t\t\t Name: " << name << endl;
    cout << "\t\t\t\t Age: " << age << endl;
    cout << "\t\t\t\t Address: " << address << endl;
    cout << "\t\t\t\t Phone No: " << phoneNo << endl;
    cout << "\t\t\t\t Email: " << email << endl;
}

#ifndef DISEASE_H
#define DISEASE_H

#include <iostream>
#include <string>

class Disease {
private:
    static const int MAX_DISEASE_NAME_SIZE = 30;
    static const int MAX_VIRUS_NAME_SIZE = 20;

    std::string diseaseName, virusName, specializations;

public:
    void getDiseaseDetails();
    void getSpecializationDetails();
    void showDiseaseList();
    std::string getSpecializations() const;  // Add this line
};

#endif // DISEASE_H

//Disease.cpp
#include "Disease.h"
using namespace std;

void Disease::getDiseaseDetails() {
    cout << "\t\t\t\t Enter the name of Disease: ";
    getline(cin, diseaseName);

    cout << "\t\t\t\t Enter the name of Virus: ";
    getline(cin, virusName);
}

void Disease::getSpecializationDetails() {
    cout << "\t\t\t\t Enter the Specializations: ";
    getline(cin, specializations);
}

void Disease::showDiseaseList() {
    cout << "\t\t\t\t ---> Disease: " << diseaseName << endl;
    cout << "\t\t\t\t ---> Virus name: " << virusName << endl;
}

std::string Disease::getSpecializations() const {
    return specializations;
}


// Available.h
#ifndef AVAILABLE_H
#define AVAILABLE_H

#include <iostream>
#include <string>
#include <ctime>

class Available {
private:
    static const int MAX_DAY_OF_WEEK = 15;
    static const int MAX_SHIFT_SIZE = 25;

    std::string dayOfWeek[MAX_DAY_OF_WEEK], shift1;
    int NoD;

public:
    static const int MAX_AVAILABLE_DAYS = 7;
    void whenAvailable();
    void displayAvailable();
};

#endif // AVAILABLE_H

// Available.cpp
#include "Available.h"
#include <ctime>
using namespace std;

void Available::whenAvailable() {
    cout << "\t\t\t\t Enter no. of available days (1-" << MAX_AVAILABLE_DAYS << "): ";
    cin >> NoD;

    while (NoD < 1 || NoD > MAX_AVAILABLE_DAYS) {
        cout << "\t\t\t\t Error, the number you entered is out of range!" << endl;
        cout << "\t\t\t\t Enter the number between 1-" << MAX_AVAILABLE_DAYS << " ONLY: ";
        cin >> NoD;
    }

    cout << "\t\t\t\t Enter " << NoD << " days of the week for Dr. Available?: ";
    for (int i = 0; i < NoD; i++) {
        cin >> dayOfWeek[i];
    }
}

void Available::displayAvailable() {
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    cout << "\t\t\t\t Local time: " << asctime(timeinfo);

    cout << "\t\t\t\t Dr. is available for " << NoD << " days in the week" << endl;
    cout << "\t\t\t\t ***** Available days are ";

    for (int i = 0; i < NoD; i++) {
        cout << dayOfWeek[i];
        if (i < NoD - 1) {
            cout << " | ";
        }
    }
    cout << " *****";
    cout << endl;
}

// Patient.h
#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"
#include "Disease.h"
#include <fstream>

class Patient : public Person {
private:
    static const int MAX_FILE_NAME_SIZE = 20;

    int patientID;
    Disease disease;
    std::string appointmentDate;
    char patientFile[MAX_FILE_NAME_SIZE] = "patientData.dat";
    char patientTempFile[MAX_FILE_NAME_SIZE] = "patientData2.dat";

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

// Patient.cpp
#include "Patient.h"
#include <iomanip>
using namespace std;

void Patient::getPatientInformation() {
    cout << "\n\n\t\t\t\t*********************************************" << endl;
    cout << "\t\t\t\t  Enter Personal Information To Be Recorded       " << endl;
    cout << "\t\t\t\t*********************************************" << endl;
    Person::getPersonData();  // Use the base class function

    cout << "\n\n\t\t\t\t*********************************************" << endl;
    cout << "\t\t\t\t Disease Details of the Patient                 " << endl;
    cout << "\t\t\t\t*********************************************" << endl;
    disease.getDiseaseDetails();

    cout << "\t\t\t\t Appointment Date: ";
    cin.ignore();
    getline(cin, appointmentDate);
}

void Patient::addPatient() {
    cout << "\t\t\t\t Enter Patient ID: ";
    cin >> patientID;

    getPatientInformation();
    ofstream patientDatabase(patientFile, ios::binary | ios::out | ios::app);
    if (patientDatabase.is_open()) {
        patientDatabase.write(reinterpret_cast<char*>(this), sizeof(Patient));
        patientDatabase.close();
    }
    else {
        cout << "\t\t\t\t Error opening the patient database file." << endl;
    }
}

void Patient::showPatientData() {
    cout << "\n\t\t\t\t ---------------- Patient ID ----------------\n";
    cout << "\t\t\t\t Patient ID: " << setw(3) << setfill('0') << patientID << endl;
    cout << "\t\t\t\t ----------------------------------------------\n\n";
    Person::showPersonData();  // Use the base class function
    cout << "\n\t\t\t\t ------------------ Disease Details ------------------\n";
    disease.showDiseaseList();
    cout << "\n\t\t\t\t -------------- Appointment Information --------------\n";
    cout << "\t\t\t\t Appointment Date: " << appointmentDate << endl;
    cout << "\t\t\t\t -----------------------------------------------------\n";
}

void Patient::showPatientDataFromFile() {
    ifstream ReadDatafromDATABASE(patientFile, ios::binary | ios::in);
    if (ReadDatafromDATABASE.is_open()) {
        while (ReadDatafromDATABASE.read(reinterpret_cast<char*>(this), sizeof(Patient))) {
            showPatientData();
        }
        ReadDatafromDATABASE.close();
    }
    else {
        cout << "\t\t\t\t Error opening the patient database file." << endl;
    }
}

void Patient::dischargePatient() {
    int n, flag = 0;
    cout << "\n\t\t\t\t Enter the ID of the patient that you want to delete: ";
    cin >> n;

    ifstream ifpatient(patientFile, ios::in | ios::binary);
    ofstream ofpatient(patientTempFile, ios::out | ios::binary);

    if (ifpatient.is_open() && ofpatient.is_open()) {
        while (ifpatient.read(reinterpret_cast<char*>(this), sizeof(Patient))) {
            if (n == patientID) {
                flag = 1;
            }
            else {
                ofpatient.write(reinterpret_cast<char*>(this), sizeof(Patient));
            }
        }

        ifpatient.close();
        ofpatient.close();
        remove(patientFile);
        rename(patientTempFile, patientFile);

        if (flag == 1) {
            cout << "\n\t\t\t\t Record Successfully Deleted!\n";
        }
        else {
            cout << "\n\t\t\t\t Record not found!\n";
        }
    }
    else {
        cout << "\t\t\t\t Error opening patient database files." << endl;
    }
}

void Patient::editPatient() {
    int n, flag = 0;
    cout << "\n\t\t\t\t Enter the patient ID you want to edit: ";
    cin >> n;

    fstream fpatient(patientFile, ios::binary | ios::in | ios::out);

    if (fpatient.is_open()) {
        std::streamoff pos; // Correct type for 'pos'

        while (fpatient.read(reinterpret_cast<char*>(this), sizeof(Patient))) {
            pos = fpatient.tellg();
            if (n == patientID) {
                flag = 1;

                getPatientInformation();

                fpatient.seekp(pos - static_cast<std::streamoff>(sizeof(Patient))); // Adjust position for writing
                fpatient.write(reinterpret_cast<char*>(this), sizeof(Patient));

                showPatientData();
                break; // Break should be inside the if statement
            }
        }

        fpatient.close();

        if (flag == 1) {
            cout << "\n\t\t\t\t Record Successfully Modified!\n";
        }
        else {
            cout << "\n\t\t\t\t Record not Found!\n";
        }
    }
    else {
        cout << "\t\t\t\t Error opening patient database file." << endl;
    }
}


void Patient::doPatientRelateWork() {
    char flag;
    int choice;
    do {
        cout << "\n\n\t\t\t\t=============================================" << endl;
        cout << "\t\t\t\t               Patient Menu                 " << endl;
        cout << "\t\t\t\t=============================================" << endl;
        cout << "\t\t\t\t 1. Add a new patient                         " << endl;
        cout << "\t\t\t\t 2. Show all patient data                    " << endl;
        cout << "\t\t\t\t 3. Discharge a patient                       " << endl;
        cout << "\t\t\t\t 4. Edit patient's data                       " << endl;
        cout << "\t\t\t\t 5. Exit the program                          " << endl;
        cout << "\t\t\t\t=============================================" << endl;
        cout << "\t\t\t\t Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            do {
                addPatient();
                cout << "\n\t\t\t\t Add another patient? Press 'Y' for YES: ";
                cin >> flag;
            } while (flag == 'Y' || flag == 'y');
        }
        else if (choice == 2) {
            showPatientDataFromFile();
        }
        else if (choice == 3) {
            dischargePatient();
        }
        else if (choice == 4) {
            editPatient();
        }
    } while (choice >= 1 && choice <= 4);
}

// Doctor.h
#ifndef DOCTOR_H
#define DOCTOR_H

#include "Available.h"
#include "Disease.h"
#include "Person.h"
#include <fstream>

class Doctor : public Person {
private:
    static const int MAX_FILE_NAME_SIZE = 20;

    int doctorID;
    Disease disease;
    Available available;
    std::string shift1, shift2;
    char doctorFile[MAX_FILE_NAME_SIZE] = "doctorData.dat";
    char doctorTempFile[MAX_FILE_NAME_SIZE] = "doctorData2.dat";

public:
    void getDoctorData();
    void showDoctorData();
    void addDoctorData();
    int calculateExperience() const;  // New method to calculate experience
    void showDoctorDataFromFile();
    void deleteDoctor();
    void editDoctor();
    void doDoctorRelatedWork();
};

#endif // DOCTOR_H

// Doctor.cpp
#include "Doctor.h"
using namespace std;

void Doctor::getDoctorData() {
    cout << "\n\n\t\t\t\t*********************************************" << endl;
    cout << "\t\t\t\t  Enter data of Doctor To Be Recorded       " << endl;
    cout << "\t\t\t\t*********************************************" << endl;

    cout << "\n\t\t\t\t Enter Doctor ID: ";
    cin >> doctorID;
    getPersonData();

    disease.getSpecializationDetails();

    cout << "\t\t\t\t Enter Dr. First Shift: ";
    getline(cin, shift1);

    cout << "\t\t\t\t Enter Dr. Second Shift: ";
    getline(cin, shift2);

    available.whenAvailable();
}


void Doctor::showDoctorData() {

    cout << "\n\t\t\t\t Details of Doctor are: " << endl;
    cout << "\n\t\t\t\t ----------------------------------------------\n";
    cout << "\t\t\t\t\t\t Doctor ID: " << setw(3) << setfill('0') << doctorID << endl;
    cout << "\t\t\t\t ----------------------------------------------\n\n";
    showPersonData();


    cout << "\n\t\t\t\t -------------- Shift Information --------------\n";
    cout << "\t\t\t\t First Shift: " << shift1 << endl;
    cout << "\t\t\t\t Second Shift: " << shift2 << endl;
    cout << "\t\t\t\t Specializations: " << disease.getSpecializations() << endl;
    available.displayAvailable();

    cout << "\t\t\t\t Experience: " << calculateExperience() << " years" << endl;
    cout << endl;
}

int Doctor::calculateExperience() const {
    const int graduationAge = 30; // Assumed age of graduation
    return getAge() - graduationAge;
}

void Doctor::addDoctorData() {
    getDoctorData();
    ofstream doctorDatabase(doctorFile, ios::binary | ios::out | ios::app);
    if (doctorDatabase.is_open()) {
        doctorDatabase.write(reinterpret_cast<char*>(this), sizeof(Doctor));
        doctorDatabase.close();
    }
    else {
        cout << "\t\t\t\t Error opening the doctor database file." << endl;
    }
}

void Doctor::showDoctorDataFromFile() {
    ifstream readDataFromDatabase(doctorFile, ios::binary | ios::in);
    if (readDataFromDatabase.is_open()) {
        while (readDataFromDatabase.read(reinterpret_cast<char*>(this), sizeof(Doctor))) {
            showDoctorData();
        }
        readDataFromDatabase.close();
    }
    else {
        cout << "\t\t\t\t Error opening the doctor database file." << endl;
    }
}


void Doctor::deleteDoctor() {
    int n, flag = 0;
    cout << "\t\t\t\t Enter the Doctor ID of the doctor you want to delete: ";
    cin >> n;

    ifstream ifdoctor(doctorFile, ios::in | ios::binary);
    ofstream ofdoctor(doctorTempFile, ios::out | ios::binary);

    if (ifdoctor.is_open() && ofdoctor.is_open()) {
        while (ifdoctor.read(reinterpret_cast<char*>(this), sizeof(Doctor))) {
            if (n == doctorID) {
                flag = 1;
            }
            else

            {
                ofdoctor.write(reinterpret_cast<char*>(this), sizeof(Doctor));
            }
        }

        ifdoctor.close();
        ofdoctor.close();
        remove(doctorFile);
        rename(doctorTempFile, doctorFile);

        if (flag == 1) {
            cout << "\n\t\t\t\t Doctor Record Successfully Deleted!\n";
        }
        else {
            cout << "\n\t\t\t\t Doctor Record not found!\n";
        }
    }
    else {
        cout << "\t\t\t\t Error opening doctor database files." << endl;
    }
}

void Doctor::editDoctor() {
    int n, flag = 0;
    cout << "\n\t\t\t\t Enter the Doctor ID you want to edit: ";
    cin >> n;

    fstream fdoctor(doctorFile, ios::binary | ios::in | ios::out);

    if (fdoctor.is_open()) {
        std::streamoff pos;

        while (fdoctor.read(reinterpret_cast<char*>(this), sizeof(Doctor))) {
            pos = fdoctor.tellg(); // Get current position after reading
            if (n == doctorID) {
                flag = 1;

                getDoctorData(); // Get new data for the doctor

                fdoctor.seekp(pos - static_cast<std::streamoff>(sizeof(Doctor))); // Move back to the start of the current record
                fdoctor.write(reinterpret_cast<char*>(this), sizeof(Doctor)); // Write the updated record

                showDoctorData(); // Display the updated data
                break; // Exit the loop once the update is done
            }
        }

        fdoctor.close();

        if (flag == 1) {
            cout << "\n\t\t\t\t Doctor Record Successfully Modified!\n";
        }
        else {
            cout << "\n\t\t\t\t Doctor Record not Found!\n";
        }
    }
    else {
        cout << "\t\t\t\t Error opening doctor database file." << endl;
    }
}


void Doctor::doDoctorRelatedWork() {
    char flag;
    int choice;
    do {
        cout << "\n\n\t\t\t\t=============================================" << endl;
        cout << "\t\t\t\t                Doctor Menu                 " << endl;
        cout << "\t\t\t\t=============================================" << endl;
        cout << "\t\t\t\t 1. Add a new doctor                          " << endl;
        cout << "\t\t\t\t 2. Show all doctor data                     " << endl;
        cout << "\t\t\t\t 3. Delete a doctor                          " << endl;
        cout << "\t\t\t\t 4. Edit doctor's data                       " << endl;
        cout << "\t\t\t\t 5. Exit the program                          " << endl;
        cout << "\t\t\t\t=============================================" << endl;
        cout << "\t\t\t\t Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            do {
                addDoctorData();
                cout << "\n\t\t\t\t Add another doctor? Press 'Y' for YES: ";
                cin >> flag;
            } while (flag == 'Y' || flag == 'y');
        }
        else if (choice == 2) {
            showDoctorDataFromFile();
        }
        else if (choice == 3) {
            deleteDoctor();
        }
        else if (choice == 4) {
            editDoctor();
        }
    } while (choice >= 1 && choice <= 4);
}

// Reception.cpp
#include "Reception.h"
#include <cstdlib>  // Include the cstdlib header for exit()
using namespace std;

void Reception::startReception() {
    char flag;
    int choice;

    do {
        cout << "\n\n\t\t\t\t=============================================" << endl;
        cout << "\t\t\t\t              Welcome to the Reception       " << endl;
        cout << "\t\t\t\t=============================================" << endl;
        cout << "\t\t\t\t 1. Patient Menu                             " << endl;
        cout << "\t\t\t\t 2. Doctor Menu                              " << endl;
        cout << "\t\t\t\t 3. Exit the program                          " << endl;
        cout << "\t\t\t\t=============================================" << endl;
        cout << "\t\t\t\t Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            patientMenu();
        }
        else if (choice == 2) {
            doctorMenu();
        }
        else if (choice == 3) {
            cout << "\n\t\t\t\t Exiting the program. Goodbye!\n";
            exit(0);  // Use the exit() function to exit the program
        }

        if (choice != 3) {
            cout << "\n\t\t\t\t Do you want to go back to the main menu? Press 'Y' for YES: ";
            cin >> flag;
        }

    } while (flag == 'Y' || flag == 'y');
}


void Reception::patientMenu() {
    Patient patient;
    patient.doPatientRelateWork();
}

void Reception::doctorMenu() {
    Doctor doctor;
    doctor.doDoctorRelatedWork();
}

int main() {
    Reception reception;
    reception.startReception();

    return 0;
}
