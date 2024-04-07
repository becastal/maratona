#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

#define dbg(x) cout << #x << " = " << x << endl;

using namespace std;

int main()
{
    map<string, string> dicionario;
    dicionario.insert({"brasil", "Feliz Natal!"});
    dicionario.insert({"alemanha", "Frohliche Weihnachten!"});
    dicionario.insert({"austria", "Frohe Weihnacht!"});
    dicionario.insert({"coreia", "Chuk Sung Tan!"});
    dicionario.insert({"espanha", "Feliz Navidad!"});
    dicionario.insert({"grecia", "Kala Christougena!"});
    dicionario.insert({"estados-unidos", "Merry Christmas!"});
    dicionario.insert({"inglaterra", "Merry Christmas!"});
    dicionario.insert({"australia", "Merry Christmas!"});
    dicionario.insert({"portugal", "Feliz Natal!"});
    dicionario.insert({"suecia", "God Jul!"});
    dicionario.insert({"turquia", "Mutlu Noeller"});
    dicionario.insert({"argentina", "Feliz Navidad!"});
    dicionario.insert({"chile", "Feliz Navidad!"});
    dicionario.insert({"mexico", "Feliz Navidad!"});
    dicionario.insert({"antardida", "Merry Christmas!"});
    dicionario.insert({"canada", "Merry Christmas!"});
    dicionario.insert({"irlanda", "Nollaig Shona Dhuit!"});
    dicionario.insert({"belgica", "Zalig Kerstfeest!"});
    dicionario.insert({"italia", "Buon Natale!"});
    dicionario.insert({"libia", "Buon Natale!"});
    dicionario.insert({"siria", "Milad Mubarak!"});
    dicionario.insert({"marrocos", "Milad Mubarak!"});
    dicionario.insert({"japao", "Merii Kurisumasu!"});

    string pesquisa;
    while (cin >> pesquisa)
    {
        if (dicionario.find(pesquisa) == dicionario.end())
        {
            cout << "--- NOT FOUND ---" << endl;
        }
        else
        {
            cout << dicionario[pesquisa] << endl;
        }
    }


    return 0;
}
