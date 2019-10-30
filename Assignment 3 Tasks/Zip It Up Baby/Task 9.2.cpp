/*
    Filename: Task 9.2.cpp
    Purpose: Using Structured Arrays
    Subject: SWE20004
    Author: Jake Scott (120581840)
    Date Last Modifed: 30/10/2019
*/

#include <iostream>

using namespace std;

struct company_detail {
    string company_id;
    string company_name;
};

struct Emp {
    string emp_name;
    string emp_id;
    double salary;
    struct company_detail cmp_detail;
};

int get_data(Emp employees[]) {
    for (int i = 0; i < 2; i++) {
        cout << "Please enter Employee Name: " << endl;
        cin >> employees[i].emp_name;

        cout << "Please enter Employee ID: " << endl;
        cin >> employees[i].emp_id;

        cout << "Please enter Employee Salary: " << endl;
        cin >> employees[i].salary;

        cout << "Please enter Employee's Company ID: " << endl;
        cin >> employees[i].cmp_detail.company_id;

        cout << "Please enter Employee's Company Name: " << endl;
        cin >> employees[i].cmp_detail.company_name;
    }
}

void print_data(Emp employees[]) {
    for (int i = 0; i < 2; i++) {
        cout << "--------------------------" << endl;
        cout << "Employee " << i << endl;
        cout << "Name: " << employees[i].emp_name << endl;
        cout << "ID: " << employees[i].emp_id << endl;
        cout << "Salary: " << employees[i].salary << endl;
        cout << " " << endl;
        cout << "Company Details: " << endl;
        cout << "Company ID: " << employees[i].cmp_detail.company_id << endl;
        cout << "Company Name: " << employees[i].cmp_detail.company_name << endl;
        cout << "--------------------------" << endl;
    }
}

double get_average(Emp employees[], string searchString) {
    int employeeNumbers = 0;
    int salaryTotal = 0;
    int salaryAverage = 0;

    for (int i = 0; i < 2; i++) {
        if (employees[i].cmp_detail.company_name == searchString) {
            salaryTotal += employees[i].salary;
            employeeNumbers++;
        }
    }
    salaryAverage = (salaryTotal/employeeNumbers);
    cout << "Avarage salary of " << searchString << " is: " << salaryAverage << endl;
}

int menu() {
    int menuSelection;

    cout << "1. Display All Records" << endl;
    cout << "2. Get average (Per Company)" << endl;
    cout << "3. Exit Program" << endl;
    cin >> menuSelection;

    return menuSelection;
}

int main()
{
    // Variable Initilization
    Emp employees[5];
    int menuSelection;
    string searchString;
    bool z = true;

    // Call get_data function
    get_data(employees);

    while(z) {
        menuSelection = menu();
            switch (menuSelection) {
                case 1:
                    print_data(employees);
                    break;
                case 2:
                    cout << "Please enter the company name to find average: " << endl;
                    cin >> searchString;

                    get_average(employees, searchString);
                    break;
                case 3:
                    cout << "Exiting Program..." << endl;
                    z = false;
                    break;
        }
    }

    // Return Code
    return 0;
}
