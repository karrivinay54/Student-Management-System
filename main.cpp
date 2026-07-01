#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cstdio>

using namespace std;

struct Student
{
    string id;
    string name;
    int age;
    string branch;
    float cgpa;
    string phone;
};

int main()
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "     Student Management System\n";
        cout << "=====================================\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "\n=====================================\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
{
    Student s;

    cout << "\nEnter Student ID: ";
    cin >> s.id;
    Student tempStudent;
string tempAge, tempCgpa;

ifstream checkFile("students.txt");

bool duplicate = false;

while(getline(checkFile, tempStudent.id, ','))
{
    getline(checkFile, tempStudent.name, ',');
    getline(checkFile, tempAge, ',');
    getline(checkFile, tempStudent.branch, ',');
    getline(checkFile, tempCgpa, ',');
    getline(checkFile, tempStudent.phone);

    if(tempStudent.id == s.id)
    {
        duplicate = true;

        cout << "\n=====================================\n";
        cout << " Student Already Exists!\n";
        cout << "=====================================\n";

        cout << "ID      : " << tempStudent.id << endl;
        cout << "Name    : " << tempStudent.name << endl;
        cout << "Age     : " << atoi(tempAge.c_str()) << endl;
        cout << "Branch  : " << tempStudent.branch << endl;
        cout << "CGPA    : " << atof(tempCgpa.c_str()) << endl;
        cout << "Phone   : " << tempStudent.phone << endl;

        break;
    }
}

checkFile.close();

if(duplicate)
{
    break;
}
    

    cout << "Enter Student Name: ";
    cin >> s.name;

    cout << "Enter Age: ";
    cin >> s.age;
    
    if(s.age < 15 || s.age > 100)
{
    cout << "\nInvalid Age!\n";
    break;
}

    cout << "Enter Branch (ECE/CSE/EEE/IT/MECH/CIVIL): ";
    cin >> s.branch;

for(int i = 0; i < s.branch.length(); i++)
{
    s.branch[i] = toupper(s.branch[i]);
}

if(s.branch != "ECE" &&
   s.branch != "CSE" &&
   s.branch != "EEE" &&
   s.branch != "IT" &&
   s.branch != "MECH" &&
   s.branch != "CIVIL")
{
    cout << "\nInvalid Branch!\n";
    break;
}

    cout << "Enter CGPA: ";
    cin >> s.cgpa;
    
    if(s.cgpa < 0 || s.cgpa > 10)
{
    cout << "\nInvalid CGPA!\n";
    break;
}
    
    cout << "Enter Phone: ";
    cin >> s.phone;
    
    bool valid = true;

if(s.phone.length() != 10)
{
    valid = false;
}

for(int i = 0; i < s.phone.length(); i++)
{
    if(!isdigit(s.phone[i]))
    {
        valid = false;
        break;
    }
}

if(!valid)
{
    cout << "\nInvalid phone number!\n";
    cout << "Phone number must contain exactly 10 digits.\n";
    break;
}


checkFile.close();

if(duplicate)
{
    cout << "\n=====================================\n";
    cout << " Student ID already exists!\n";
    cout << "=====================================\n";
    break;
}
    
   ofstream file("students.txt", ios::app);

if(!file)
{
    cout << "Error opening file!\n";
    break;
}

file << s.id << ","
     << s.name << ","
     << s.age << ","
     << s.branch << ","
     << s.cgpa << ","
     << s.phone << endl;

file.close();

cout << "\n=====================================\n";
cout << " Student Added Successfully!\n";
cout << "=====================================\n";
    break;
}

            case 2:
{
    ifstream file("students.txt");

    if(!file)
    {
        cout << "\nNo student records found!\n";
        break;
    }

    Student s;

    string age, cgpa;

    cout << "\n";
    cout << left
     << setw(15) << "ID"
     << setw(15) << "Name"
     << setw(8) << "Age"
     << setw(12) << "Branch"
     << setw(8) << "CGPA"
     << setw(15) << "Phone" << endl;

    cout << "--------------------------------------------------------------------------\n";

    while(getline(file, s.id, ','))
    {
        getline(file, s.name, ',');
        getline(file, age, ',');
        getline(file, s.branch, ',');
        getline(file, cgpa, ',');
        getline(file, s.phone);

        s.age = atoi(age.c_str());
        s.cgpa = atof(cgpa.c_str());

        cout << left
             << setw(15) << s.id
             << setw(15) << s.name
             << setw(8) << s.age
             << setw(12) << s.branch
             << setw(8) << s.cgpa
             << setw(15) << s.phone
             << endl;
    }

    file.close();

    break;
}

            case 3:
{
    ifstream file("students.txt");

    if(!file)
    {
        cout << "\nNo student records found!\n";
        break;
    }

    Student s;
    string searchID;
    string age, cgpa;
    bool found = false;

    cout << "\nEnter Student ID to Search: ";
    cin >> searchID;

    while(getline(file, s.id, ','))
    {
        getline(file, s.name, ',');
        getline(file, age, ',');
        getline(file, s.branch, ',');
        getline(file, cgpa, ',');
        getline(file, s.phone);

        s.age = atoi(age.c_str());
        s.cgpa = atof(cgpa.c_str());

        if(searchID == s.id)
        {
            found = true;

            cout << "\n=====================================\n";
            cout << " Student Found!\n";
            cout << "=====================================\n";
            cout << "ID      : " << s.id << endl;
            cout << "Name    : " << s.name << endl;
            cout << "Age     : " << s.age << endl;
            cout << "Branch  : " << s.branch << endl;
            cout << "CGPA    : " << s.cgpa << endl;
            cout << "Phone   : " << s.phone << endl;

            break;
        }
    }

    if(!found)
    {
        cout << "\n=====================================\n";
        cout << " Student Not Found!\n";
        cout << "=====================================\n";
    }

    file.close();
    break;
}

            case 4:
{
    ifstream file("students.txt");
    ofstream temp("temp.txt");

    if(!file || !temp)
    {
        cout << "\nError opening file!\n";
        break;
    }

    Student s;
    string updateID;
    string age, cgpa;
    bool found = false;
    bool invalidData = false;

    cout << "\nEnter Student ID to Update: ";
    cin >> updateID;

    while(getline(file, s.id, ','))
    {
        getline(file, s.name, ',');
        getline(file, age, ',');
        getline(file, s.branch, ',');
        getline(file, cgpa, ',');
        getline(file, s.phone);

        s.age = atoi(age.c_str());
        s.cgpa = atof(cgpa.c_str());

        if(updateID == s.id)
        {
            found = true;

            cout << "\nEnter New Name: ";
            cin >> s.name;

            cout << "Enter New Age: ";
            cin >> s.age;

            if(s.age < 15 || s.age > 100)
{
    cout << "\nInvalid Age!\n";
    invalidData = true;
    break;
}

            cout << "Enter New Branch (ECE/CSE/EEE/IT/MECH/CIVIL): ";       
            cin >> s.branch;
            for(int i = 0; i < s.branch.length(); i++)
            {
             s.branch[i] = toupper(s.branch[i]);
            }
            if(s.branch != "ECE" &&
            s.branch != "CSE" &&
            s.branch != "EEE" &&
            s.branch != "IT" &&
            s.branch != "MECH" &&
            s.branch != "CIVIL")
            {
             cout << "\nInvalid Branch!\n";
             invalidData = true;
             break;
            }

            cout << "Enter New CGPA: ";
            cin >> s.cgpa;

            if(s.cgpa < 0 || s.cgpa > 10)
{
    cout << "\nInvalid CGPA!\n";
    invalidData = true;
    break;
}

            cout << "Enter New Phone: ";
            cin >> s.phone;

            temp << s.id << ","
                 << s.name << ","
                 << s.age << ","
                 << s.branch << ","
                 << s.cgpa << ","
                 << s.phone << endl;
        }
        else
        {
            temp << s.id << ","
                 << s.name << ","
                 << s.age << ","
                 << s.branch << ","
                 << s.cgpa << ","
                 << s.phone << endl;
        }
    }

    file.close();
    temp.close();
    if(invalidData)
{
    remove("temp.txt");
    break;
}

    if(found)
    {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        cout << "\n=====================================\n";
        cout << " Student Updated Successfully!\n";
        cout << "=====================================\n";
    }
    else
    {
        remove("temp.txt");
        cout << "\nStudent ID Not Found!\n";
    }

    break;
}

            case 5:
{
    ifstream file("students.txt");
    ofstream temp("temp.txt");

    if(!file || !temp)
    {
        cout << "\nError opening file!\n";
        break;
    }

    Student s;
    string deleteID;
    string age, cgpa;
    bool found = false;

    cout << "\nEnter Student ID to Delete: ";
    cin >> deleteID;

    while(getline(file, s.id, ','))
    {
        getline(file, s.name, ',');
        getline(file, age, ',');
        getline(file, s.branch, ',');
        getline(file, cgpa, ',');
        getline(file, s.phone);

        s.age = atoi(age.c_str());
        s.cgpa = atof(cgpa.c_str());

        if(deleteID == s.id)
        {
            found = true;

            // Skip writing this record
            continue;
        }

        temp << s.id << ","
             << s.name << ","
             << s.age << ","
             << s.branch << ","
             << s.cgpa << ","
             << s.phone << endl;
    }

    file.close();
    temp.close();

    if(found)
    {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        cout << "\n=====================================\n";
        cout << " Student Deleted Successfully!\n";
        cout << "=====================================\n";
    }
    else
    {
        remove("temp.txt");
        cout << "\nStudent ID Not Found!\n";
    }

    break;
}

            case 6:
                cout << "\n=====================================\n";
                cout << " Thank You for Using\n";
                cout << " Student Management System\n";
                cout << "=====================================\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while(choice != 6);

    return 0;
}
