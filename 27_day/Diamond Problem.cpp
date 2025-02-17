#include <iostream>
using namespace std;

// Base Class (Virtual to avoid duplication)
class Person {
protected:
    string name;
    int age;

public:
    // Constructor
    Person(string n, int a) : name(n), age(a) {}

    // Display function
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Student class derived from Person
class Student : virtual public Person {
protected:
    int studentID;

public:
    // Constructor
    Student(string n, int a, int sID) : Person(n, a), studentID(sID) {}

    // Show Student Details
    void show_student() {
        cout << "Student ID: " << studentID << endl;
    }
};

// Employee class derived from Person
class Employee : virtual public Person {
protected:
    int empID;

public:
    // Constructor
    Employee(string n, int a, int eID) : Person(n, a), empID(eID) {}

    // Show Employee Details
    void show_employee() {
        cout << "Employee ID: " << empID << endl;
    }
};

// WorkingStudent derived from both Student and Employee
class WorkingStudent : public Student, public Employee {
public:
    // Constructor to initialize all attributes
    WorkingStudent(string n, int a, int sID, int eID)
        : Person(n, a), Student(n, a, sID), Employee(n, a, eID) {}

    // Show all details (formatted to match expected output)
    void showDetails() {
        display();        // Show name & age from Person
        show_student();   // Show student ID
        show_employee();  // Show employee ID
    }
};

// Function to execute user-defined logic (since main() is auto-generated)
void userMain() {
    // Taking user input
    string name;
    int age, studentID, empID;

    cin >> name >> age >> studentID >> empID;  // Read space-separated values

    // Creating a WorkingStudent object
    WorkingStudent ws(name, age, studentID, empID);

    // Displaying details (Formatted correctly)
    ws.showDetails();
}

int main() {
    char name[100];
    int age,stdId;
    int empId;
    cin>>name>>age>>stdId>>empId;
        WorkingStudent ws(name, age, stdId, empId);
        ws.showDetails(); 
    return 0;
}