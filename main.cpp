#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

string docFile = "doctors.txt";
string patFile = "patFile.txt";

int Interface(); int doctorsInterface(); int patientsInterface();

struct Doctor
{
    int id;
    string name;
    string department;
};

struct Patient
{
    string name;
    string email;
    string message;

    int phone;
    int age;

    Doctor doctor;
};

vector<Doctor> doctors; vector<Patient> patients;

int patientsInterface()
{
    int choice;
    cout << "\n[1] Register Patient\n[2] Search Patient\n[3] Update Patient Record\n[4] Remove Patient\n[5] Exit\n";
    cout << "\nEnter [Key]: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            {
                Patient patient;
                cout << "\nEnter Patient Name: ";
                cin.ignore();
                getline(cin, patient.name);
                cout << "Enter Patient Age: ";
                cin.ignore();
                cin >> patient.age;
                cout << "Enter Patient Email: ";
                cin.ignore();
                getline(cin, patient.email);
                cout << "Enter Patient Phone: ";
                cin.ignore();
                cin >> patient.phone;
                cout << "Enter Description of illness: ";
                cin.ignore();
                getline(cin, patient.message);

                cout << "Assign Doctor by Name: ";
                getline(cin, patient.doctor.name);

                for (int i = 0; i < doctors.size(); i++)
                {
                    if (doctors[i].name == patient.doctor.name)
                    {
                        patient.doctor = doctors[i];
                        patients.push_back(patient);
                        cout << "\nDoctor available\n";
                        break;
                    }
                    cout << "\nDoctor not found\n";
                }
                break;
            }
    case 2:
            {
                string name;
                cout << "\nEnter Patient Name: ";
                cin.ignore();
                getline(cin, name);
                for (int i = 0; i < patients.size(); i++)
                {
                    if (patients[i].name == name)
                    {
                        cout << "Patient Age: " << patients[i].age << "\nPatient Email: " << patients[i].email << "\nPatient Phone: " << patients[i].phone
                        << "\nDescription: " << patients[i].message << endl;
                        cout << "\nAssigned Doctor: " << patients[i].doctor.id << "\nName: " << patients[i].doctor.name << "\nDepartment: " << patients[i].doctor.department << endl;
                    }
                }
                break;
            }
    case 5:
            {
                Interface();
                return 0;
            }
    default:
        cout << "\nInvalid Key\n";
    }
    patientsInterface();
    return 0;
}

int doctorsInterface()
{
    int choice;
    cout << "\n[1] Register Doctor\n[2] Search Doctor\n[3] Update Doctor Record\n[4] Remove Doctor\n[5] Exit\n";
    cout << "\nEnter [Key]: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        {
            Doctor doctor;
            cout << "\nEnter Doctor Name: ";
            cin.ignore();
            getline(cin, doctor.name);
            cout << "Enter Department Name: ";
            getline(cin, doctor.department);
            cout << "Enter Doctor ID: ";
            cin >> doctor.id;
            doctors.push_back(doctor);
            break;
        }
    case 2:
        {
            cout << "\nEnter Doctor ID: ";
            int id;
            cin >> id;
            for (int i = 0; i < doctors.size(); i++)
            {
                if (doctors[i].id == id)
                {
                    cout << "\nDoctor Name: " << doctors[i].name << "\nDoctor Department: " << doctors[i].department << "\n";
                }
            }
            break;
        }
    case 3:
        {
            cout << "\nEnter Doctor ID: ";
            int id;
            cin >> id;
            for (int i = 0; i < doctors.size(); i++)
            {
                if (doctors[i].id == id)
                {
                    cout << "Enter new name: ";
                    cin.ignore();
                    getline(cin, doctors[i].name);
                    cout << "Enter new department: ";
                    getline(cin, doctors[i].department);
                }
            }
            break;
        }
    case 4:
        {
            cout << "\nEnter Doctor ID: ";
            int id;
            cin >> id;
            for (int i = 0; i < doctors.size(); i++)
            {
                if (doctors[i].id == id)
                {
                    doctors.erase(doctors.begin() + i);
                }
            }
            break;
        }
    case 5:
        Interface();
        return 0;
    default:
        cout << "\nInvalid Key\n";
    }
    doctorsInterface();
    return 0;
}

int Interface()
{
    cout << "\n[1] Doctor Management\n[2] Patient Management\n[-1] Exit\n";
    cout << "\nEnter [Key]\n";

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        cout << "\n[Doctors]\n";
        doctorsInterface();
    } else if (choice == 2)
    {
        cout << "\n[Patients]\n";
        patientsInterface();
    } else if (choice == -1) {
        return 0;
    } else
    {
        cout << "\nInvalid Choice\n";
        Interface();
    }
    return 0;
}

int main() {

    cout << "\nWelcome to [Triad Health]\n";

    Interface();

    return 0;
}
