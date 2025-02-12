#include <iostream>
#include <string>
#include <vector> // Include vector for dynamic array
using namespace std;

class Employee {
private:
    string name;
    int id;
    double salary;

public:
    // Constructor using initializer list
    Employee(string empName, int empId, double empSalary)
        : name(empName), id(empId), salary(empSalary) {}

    // Copy Constructor
    Employee(const Employee &emp) 
        : name(emp.name), id(emp.id), salary(emp.salary) {}

    // Display Employee Details
    void display() const {
        cout << "Employee ID: " << id << "\n";
        cout << "Name: " << name << "\n";
        cout << "Salary: $" << salary << "\n";
        cout << "-------------------------\n";
    }
};

int main() {
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;
    
    vector<Employee> employees; // Use vector instead of raw array
    
    // Taking employee details from the user
    for (int i = 0; i < numEmployees; i++) {
        string name;
        int id;
        double salary;
        
        cout << "Enter details for Employee " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore(); 
        getline(cin, name);
        cout << "ID: ";
        cin >> id;
        cout << "Salary: ";
        cin >> salary;
        
        employees.emplace_back(name, id, salary); // Construct Employee in place
    }
    
    // Displaying original employee details
    cout << "\nOriginal Employee Details:\n";
    for (const auto& emp : employees) {
        emp.display();
    }
    
    // Copying an employee object using the copy constructor
    Employee copiedEmployee = employees[0];
    
    cout << "Copied Employee Details:\n";
    copiedEmployee.display();
    
    return 0;
}
