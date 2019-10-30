#include <iostream>

using namespace std;

int main()
{
    struct company_detail {
        string company_id;
        string company_name;
    };

    struct Emp {
        string emp_name;
        string emp_id;
        double salary;
        struct comapny_detail cmp_detal;
    };

    Emp employee[5];











    return 0;
}
