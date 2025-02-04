#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

string docFile = "doctors.txt";
string patFile = "patFile.txt";

int Interface(); int doctorsInterface();

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
    string department;
    string message;

    int phone;
    int age;

    Doctor doctor;
};

vector<Doctor> doctors; vector<Patient> patients;

int doctorsInterface()
{
    int choice;
    cout << "\n[1] Register Doctor\n[2] Search Doctor\n[3] Update Doctor\n[4] Remove Doctor\n[5] Exit\n";
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
                    cout << doctors[i].name << " " << doctors[i].department << endl;
                }
            }
            break;
        }
    case 5:
        Interface();
        break;
    default:
        cout << "\nWrong Choice\n";
    }
    doctorsInterface();
    return 0;
}

int Interface()
{
    cout << "\n[1] Doctors Management\n[2] Patients Management\n[-1] Exit\n";
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
