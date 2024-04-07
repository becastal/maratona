#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int i;
    cin>>i;
    string mes;

    if (i == 1)
    {
        mes = "January";
    }
    else if (i == 2)
    {
        mes = "February";
    }
    else if (i == 3)
    {
        mes = "March";
    }
    else if (i == 4)
    {
        mes = "April";
    }
    else if (i == 5)
    {
        mes = "May";
    }
    else if (i == 6)
    {
        mes = "June";
    }
    else if (i == 7)
    {
        mes = "July";
    }
    else if (i == 8)
    {
        mes = "August";
    }
    else if (i == 9)
    {
        mes = "September";
    }
    else if (i == 10)
    {
        mes = "October";
    }
    else if (i == 11)
    {
        mes = "November";
    }
    else
    {
        mes = "December";
    }
    cout<<mes<<endl;
}
