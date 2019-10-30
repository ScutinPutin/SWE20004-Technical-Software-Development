#include <iostream>
#include <fstream>

using namespace std;

struct person_tag{
    string name;
    int age;
};

struct offical_tag{
    int dept_id;
    string companyName;
    double salary;
};

struct employee_tag{
    person_tag personal_info;
    offical_tag offical_info;
};

int read_file(employee_tag employee[], int sizeOfArray) {
    fstream file;
    file.open("employee.txt", fstream::in);
    for (int i = 0; i < 100; i++) {
        if (file.eof()) {
        break;
        }

        file >> employee[i].personal_info.name;
        file >> employee[i].personal_info.age;
        file >> employee[i].offical_info.dept_id;
        file >> employee[i].offical_info.companyName;
        file >> employee[i].offical_info.salary;
        sizeOfArray + 1;
    }
    file.close();
    return employee, sizeOfArray;
}

int menu() {
    int menuSelection;

    cout << "Enter your choice:" << endl;
    cout << "1. Display the grade details" << endl;
    cout << "2. Print the employee's details who gets the highest salary in this database" << endl;
    cout << "3. Find average salary of a particular company" << endl;
    cout << "4. Exit program" << endl;

    cin >> menuSelection;
    return menuSelection;
}

int display(employee_tag employee[], int sizeOfArray) {
    for (int i = 0; i < sizeOfArray; i++) {
        cout << "Name: " << employee[i].personal_info.name << endl;
        cout << "Age: " << employee[i].personal_info.age << endl;
        cout << "Department ID: " << employee[i].offical_info.dept_id << endl;
        cout << "Company Name: " << employee[i].offical_info.companyName << endl;
        cout << "Salary: " << employee[i].offical_info.salary << endl;
        cout << " " << endl;
    }
}

int findMaximum(employee_tag employee[], int sizeOfArray) {
    int maxSalaryIndex;
    for (int i = 0; i < sizeOfArray; i++) {
        for (int j = i + 1; j < sizeOfArray; j++) {
            if (employee[i].offical_info.salary > employee[j].offical_info.salary) {
                maxSalaryIndex = i;
            }
        }
    }
    return maxSalaryIndex;
}

double find_average_salary(employee_tag employee[], int sizeOfArray, string searchCompany) {
    int employeeNumbers = 0;
    double SalaryTotal = 0;
    double salaryAverage = 0;

    for (int i = 0; i < sizeOfArray; i++) {
        if (employee[i].offical_info.companyName == searchCompany) {
            SalaryTotal = employee[i].offical_info.salary + SalaryTotal;
            employeeNumbers = employeeNumbers + 1;
        }
    }
    salaryAverage = (SalaryTotal / employeeNumbers);
    cout << "Avarage salary of " << searchCompany << " is: " << salaryAverage << endl;
}

int main()
{
    // Vairaible Initilization
    bool z = true;
    employee_tag employee[100];
    int sizeOfArray = 0;
    int maxSalaryIndex;
    string searchCompany;

    // Reading Data from File.
    read_file(employee, sizeOfArray);
    // Size of Array
    sizeOfArray = 5;
    // Menu persistance.
    while (z) {
        int menuSelection = menu();
            switch(menuSelection) {
                case 1:
                    display(employee, sizeOfArray);
                    break;
                case 2:
                    maxSalaryIndex = findMaximum(employee, sizeOfArray);
                    cout << "Name: " << employee[maxSalaryIndex].personal_info.name << "\n Age: " << employee[maxSalaryIndex].personal_info.age << "\n Department ID: " << employee[maxSalaryIndex].offical_info.dept_id << "\n Company Name: " << employee[maxSalaryIndex].offical_info.companyName << "\n Salary: " << employee[maxSalaryIndex].offical_info.salary << endl;
                    break;
                case 3:
                    cout << "Enter Company Name:" << endl;
                    cin >> searchCompany;
                    find_average_salary(employee, sizeOfArray, searchCompany);
                    break;
                case 4:
                    z = false;
                    cout << "Exiting Program..." << endl;
                    break;
        }
    }
    return 0;
}
