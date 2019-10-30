/*
    Filename: Task3.8.cpp
    Purpose: Task 3.8 Computer Table
    Subject: SWE20004
    Author: Jake Scott (120581840)
    Date Last Modifed: 6/09/2019
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    // Declaring Variables
    string userName, employeeName, serialNumber, pcType, macAddress;
    float cpuSpeed;
    unsigned long ipInt;
    int noCore;

    unsigned short int ipv4P1;
    unsigned short int ipv4P2;
    unsigned short int ipv4P3;
    unsigned short int ipv4P4;

    const std::string sep = "|";

    // Assigning User input into variables
    cout << "Please enter the user name: ";
    cin >> userName;

    cout << "Please enter the employee name: ";
    cin.ignore();
    getline(cin, employeeName, '\n');

    cout << "Please enter the PC serial number (max 10 characters): ";
    cin >> serialNumber;

    cout << "Please enter the PC type (S=Server, D=Desktop, L=Laptop, T=Tablet, P=Phone): ";
    cin >> setw(1) >> pcType;

    cout << "Please enter the number of cores: ";
    cin >> setw(2) >> noCore;

    cout << "Please enter the CPU speed (GHz): ";
    cin >> cpuSpeed;

    cout << "Please enter the MAC Address: ";
    cin >> setw(16) >> macAddress;

    cout << "Please enter the IPV4 address without the dots (e.g. 111 222 333 444): ";
    cin >> ipv4P1 >> ipv4P2 >> ipv4P3 >> ipv4P4;

    // Formula to calucate ip to integer
    ipInt = (ipv4P1 * pow(256., 3)) + (ipv4P2 * pow(256., 2)) + (ipv4P3 * 256) + (ipv4P4);

    // Output Table
    cout << "+" << setfill('-') << setw(71) << "+" << endl;

    cout << setfill(' ') << left << sep << setw(8) << "User: " << userName << sep << setw(16) << "Employee: " << employeeName << sep << setw(8) << "Serial: " << serialNumber << sep << endl;
    cout << setfill(' ') << left << sep << setw(8) << "Type: " << pcType << sep << setw(7) << "Cores: " << noCore << sep << setw(5) << "Speed: " << cpuSpeed  << "GHz" << sep << setw(5) << "MAC: " << macAddress << sep << setw(6) << "IP: " << ipv4P1 << "." << ipv4P2 << "." << ipv4P3 << "." << ipv4P4 << sep << endl;
    cout << setfill(' ') << left << setw(20) << sep << "IP Address as Integer: " << ipInt << right << setw(19) << sep << endl;

    cout << "+" << setfill('-') << setw(71) << "+" << endl;
    // end of Output Table
    return 0;
}
