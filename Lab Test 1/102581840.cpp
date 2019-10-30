#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

int tv() {
        srand(time(0));
        double minimum = 300;
        double maximum = 1000;

        double random = (float)rand()/(float)maximum;
        double diff = maximum - minimum;
        double price = random + diff;

        int amount = rand()% 10 + 1;
        cout << "Rate for TV is: " << price << endl;
        if (price > 500) {
            price = price - 50;
        }
        cout << "TV Price after payback (if any):" << price << endl;
        cout << "Number of TVs in this purchase is: " << amount << endl;
        double total = price * amount;
        cout << "Total Price of the TV is: " << ceil(total) << endl;
        return total;
}

int refrigerator() {
        srand(time(0));
        double minimum = 100;
        double maximum = 500;

        double random = (float)rand()/(float)maximum;
        double diff = maximum - minimum;
        double price = random + diff;

        double amount = rand()% 10 + 1;

        cout << "Rate for refigerator is: " << price << endl;
        cout << "Number of refrigerators in this purchase is " << amount << endl;

        int total = (price * amount) * 1.055;

        cout << "Bill amount for Refrigerator is " << ceil(total) << endl;
        return total;
}

int laptop() {
    srand(time(0));

    double price = 1000;
    int amount = rand()% 10 + 1;

    cout << "Rate for laptop is: " << price << endl;
    cout << "Number of laptops in this purchase is: " << amount << endl;

    int total = price * amount;

    cout << "Bil amount for laptop is " << ceil(total) << endl;
    return total;

}

int mobile() {
    srand(time(0));

    double price = 500;
    int amount = rand()% 10 + 10;
    double total;

    cout << "Rate for mobile is: " << price << endl;
    cout << "Number of mobiles in this purcahse is: " << amount << endl;

    if (amount > 10) {
        amount = amount - 10;
        int discountTotal = amount * 250;
        int normalTotal = price * 10;
        total = discountTotal + normalTotal;
    }
    else {
        total = price * amount;
    }
    cout << "Bill amount for mobile is: " << ceil(total) << endl;
    return total;
}

int main()
{
    string menu_input;
    bool i = true;

    cout << "" << endl;
    cout << "" << endl;
    cout << "Enter T for TV" << endl;
    cout << "Enter R for Refrigerator" << endl;
    cout << "Enter L for Laptop" << endl;
    cout << "Enter M for Mobile" << endl;
    cout << "Enter E to exit" << endl;

    while (i) {
    cin >> menu_input;
    double tv_total, refrigerator_total, laptop_total, mobile_total, total;

    if (menu_input == "T") {
        cout << "You have selected TV" << endl;
        tv_total = tv();
        main();
    }
    else if (menu_input == "R") {
        cout << "You have selected Refrigerator" << endl;
        refrigerator_total = refrigerator();
        main();
    }
    else if (menu_input == "L") {
        cout << "You have selected Laptop" << endl;
        laptop_total = laptop();
        main();
    }
    else if (menu_input == "M") {
        cout << "You have selected Mobile" << endl;
        mobile_total = mobile();
        main();
    }
    else if (menu_input == "E") {
    cout << "" << endl;
    cout << "" << endl;
    cout << "Final Recipt" << endl;
    cout << "TV: " << nearbyint(tv_total) << endl;
    cout << "Refrigerator: " << nearbyint(refrigerator_total) << endl;
    cout << "Laptop: " << nearbyint(laptop_total) << endl;
    cout << "Mobile: " << nearbyint(mobile_total) << endl;
    total = tv_total + refrigerator_total + laptop_total + mobile_total;
    cout << "Total :" << total << endl;
    cout << "Rounded Bill amount is: " << nearbyint(total) << endl;

    i = false;
    }
    else {
        cout << "Please select a valid option" << endl;
    }
}


    return 0;
}
