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
} employees[5];

int get_data() {
    for (int i = 0; i < 4; i++) {
        cout << "Please enter employee name: " << i << endl;
        cin >> employees[i].emp_name;

        cout << "Please enter employee id: " << i << endl;
        cin >> employees[i].emp_id;

        cout << "Please enter employee salary: " << i << endl;
        cin >> employees[i].salary;
    }
}

void print_data() {
    int menu;
    cout << "Please select an option:" << endl;
    cout << "1. Print out all employee information" << endl;
    cout << "2. Print out one employee information" << endl;
    cin >> menu;

    if (menu == 1) {
        for (int i = 0; i < 4; i++) {
            cout << "Employee " << i << " name: " << employees[i].emp_name << endl;
            cout << "Employee " << i << " id: " << employees[i].emp_id << endl;
            cout << "Employee " << i << " salary: " << employees[i].salary << endl;
            cout << "------------------------------" << endl;
        }
    }
    else if (menu == 2) {
        int temp;
        cout << "Please enter the employee id: " << endl;
        cin >> temp;

        cout << "Employee " << temp << " name: " << employees[temp].emp_name << endl;
        cout << "Employee " << temp << " id: " << employees[temp].emp_id << endl;
        cout << "Employee " << temp << " salary: " << employees[temp].salary << endl;
        cout << "------------------------------" << endl;
    }
}

int main()
{
    get_data();
    print_data();
    return 0;
}
