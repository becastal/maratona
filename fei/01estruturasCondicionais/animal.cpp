#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    string palavra1, palavra2, palavra3;
    cin>>palavra1;
    cin>>palavra2;
    cin>>palavra3;

    string animal;
    if (palavra1 == "vertebrado")
    {
        if (palavra2 == "ave")
        {
            if (palavra3 == "carnivoro")
            {
                animal = "aguia";
            }
            else
            {
                animal = "pomba";
            }
        }
        else
        {
            if (palavra3 == "onivoro")
            {
                animal = "homem";
            }
            else
            {
                animal = "vaca";
            }
        }
    }
    else
    {
        if (palavra2 == "inseto")
        {
            if (palavra3 == "hematofago")
            {
                animal = "pulga";
            }
            else
            {
                animal = "lagarta";
            }
        }
        else
        {
            if (palavra3 == "hematofago")
            {
                animal = "sanguessuga";
            }
            else
            {
                animal = "minhoca";
            }
        }
    }
    cout<<animal<<endl;
}
