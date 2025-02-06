#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

string docFile = "docFile.txt";
string patFile = "patFile.txt";

int Interface();
int doctorsInterface();
int patientsInterface();

struct Doctor {
    int id;
    string name;
    string department;
};

struct Patient {
    string name;
    string email;
    string message;
    int phone;
    int age;
    Doctor doctor;
};

vector<Doctor> doctors;
vector<Patient> patients;

int patientsInterface() {
    int choice;
    cout << "\nPatient Management\n";
    cout << "[1] Register Patient\n[2] Search Patient\n[3] Update Patient Record\n[4] Remove Patient\n[5] Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1: {
            Patient patient;
            cout << "\n[Register New Patient]\n";
            cout << "\nEnter Patient Name: ";
            getline(cin, patient.name);
            cout << "Enter Age: ";
            cin >> patient.age;
            cin.ignore();
            cout << "Enter Email: ";
            getline(cin, patient.email);
            cout << "Enter Phone: ";
            cin >> patient.phone;
            cin.ignore();
            cout << "Enter Description of Illness: ";
            getline(cin, patient.message);
            cout << "Assign Doctor by Name: ";
            getline(cin, patient.doctor.name);

            bool found = false;
            for (int i = 0; i < doctors.size(); i++) {
                if (doctors[i].name == patient.doctor.name) {
                    patient.doctor = doctors[i];
                    patients.push_back(patient);
                    cout << "\nPatient registered successfully.";
                    cout << "\nDoctor Assigned: " << doctors[i].name << " (Department: " << doctors[i].department << ")";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nDoctor not found. Please assign later.";
            }
            break;
        }
        case 2: {
            cout << "\n[Patient Search]\n";
            cout << "\nEnter Patient Name: ";
            string name;
            getline(cin, name);

            bool found = false;
            for (int i = 0; i < patients.size(); i++) {
                if (patients[i].name == name) {
                    found = true;
                    cout << "Patient Name: " << patients[i].name << "\n";
                    cout << "Age: " << patients[i].age << "\n";
                    cout << "Email: " << patients[i].email << "\n";
                    cout << "Phone: " << patients[i].phone << "\n";
                    cout << "Description: " << patients[i].message << "\n";
                    cout << "Assigned Doctor: " << patients[i].doctor.name << " (Department: " << patients[i].doctor.department << ")\n";
                    break;
                }
            }

            if (!found) {
                cout << "\nPatient not found.\n";
            }
            break;
        }
        case 3: {
            cout << "\n[Update Patient Record]\n";
            cout << "\nEnter Patient Name: ";
            string name;
            getline(cin, name);

            bool found = false;
            for (int i = 0; i < patients.size(); i++) {
                if (patients[i].name == name) {
                    found = true;
                    cout << "New Name: ";
                    getline(cin, patients[i].name);
                    cout << "New Age: ";
                    cin >> patients[i].age;
                    cin.ignore();
                    cout << "New Email: ";
                    getline(cin, patients[i].email);
                    cout << "New Phone: ";
                    cin >> patients[i].phone;
                    cin.ignore();
                    cout << "New Description: ";
                    getline(cin, patients[i].message);
                    cout << "New Doctor Name: ";
                    getline(cin, patients[i].doctor.name);

                    bool doctorFound = false;
                    for (int j = 0; j < doctors.size(); j++) {
                        if (doctors[j].name == patients[i].doctor.name) {
                            patients[i].doctor = doctors[j];
                            cout << "\nDoctor assigned successfully.";
                            doctorFound = true;
                            break;
                        }
                    }

                    if (!doctorFound) {
                        cout << "\nDoctor not found. Keeping previous doctor.";
                    }

                    cout << "\nPatient record updated successfully.\n";
                    break;
                }
            }

            if (!found) {
                cout << "\nPatient not found.\n";
            }
            break;
        }
        case 4: {
            cout << "\n[Remove Patient]\n";
            cout << "\nEnter Patient Name: ";
            string name;
            getline(cin, name);

            for (int i = 0; i < patients.size(); i++) {
                if (patients[i].name == name) {
                    patients.erase(patients.begin() + i);
                    cout << "\nPatient removed successfully.\n";
                    break;
                }
            }
            break;
        }
        case 5:
            return Interface();
        default:
            cout << "\nInvalid choice. Please try again.\n";
    }
    return patientsInterface();
}

int doctorsInterface() {
    int choice;
    cout << "\n[Doctor Management]\n";
    cout << "\n[1] Register Doctor\n[2] Search Doctor\n[3] Update Doctor Record\n[4] Remove Doctor\n[5] Exit\n";
    cout << "\nEnter [Key]\n";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1: {
            Doctor doctor;
            cout << "\n[Register Doctor]\n";
            cout << "\nEnter Doctor Name: ";
            getline(cin, doctor.name);
            cout << "Enter Department Name: ";
            getline(cin, doctor.department);
            cout << "Enter Doctor ID: ";
            cin >> doctor.id;
            cin.ignore();

            doctors.push_back(doctor);
            cout << "\nDoctor registered successfully.";
            break;
        }
        case 2: {
            cout << "\n[Search Doctor]\n";
            cout << "Enter Doctor ID: ";
            int id;
            cin >> id;
            cin.ignore();

            for (int i = 0; i < doctors.size(); i++) {
                if (doctors[i].id == id) {
                    cout << "Doctor Name: " << doctors[i].name << "\n";
                    cout << "Department: " << doctors[i].department << "\n";
                    break;
                }
            }
            break;
        }
        case 3: {
            cout << "\n[Update Doctor Record]\n";
            cout << "Enter Doctor ID: ";
            int id;
            cin >> id;
            cin.ignore();

            for (int i = 0; i < doctors.size(); i++) {
                if (doctors[i].id == id) {
                    cout << "New Name: ";
                    getline(cin, doctors[i].name);
                    cout << "New Department: ";
                    getline(cin, doctors[i].department);
                    cout << "\nDoctor record updated successfully.\n";
                    break;
                }
            }
            break;
        }
        case 4: {
            cout << "\n[Remove Doctor]\n";
            cout << "\n Enter Doctor ID: ";
            int id;
            cin >> id;
            cin.ignore();

            for (int i = 0; i < doctors.size(); i++) {
                if (doctors[i].id == id) {
                    doctors.erase(doctors.begin() + i);
                    cout << "\nDoctor removed successfully.\n";
                    break;
                }
            }
            break;
        }
        case 5:
            return Interface();
        default:
            cout << "\nInvalid choice. Please try again.\n";
    }
    return doctorsInterface();
}

int Interface() {
    cout << "\n[1] Doctor Management\n[2] Patient Management\n[-1] Exit\n";
    cout << "\nEnter [Key]\n";
    int choice;
    cin >> choice;

    if (choice == 1) return doctorsInterface();
    if (choice == 2) return patientsInterface();
    if (choice == -1) return 0;

    cout << "\nInvalid choice. Please try again.\n";
    return Interface();
}

int main() {
    cout << "\nWelcome to [Triad Health]\n";
    return Interface();
}
