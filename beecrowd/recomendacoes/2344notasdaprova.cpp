#include <bits/stdc++.h>
using namespace std;

int main()
{
	int nota; cin >> nota;
    string conceito;
    if (nota == 0) conceito = "E";
    else if (nota >= 1 && nota <= 35) conceito = "D";
    else if (nota >= 36 && nota <= 60) conceito = "C";
    else if (nota >= 61 && nota <= 85) conceito = "B";
    else if (nota >= 86 && nota <= 100) conceito = "A";
    cout << conceito << endl;
}
