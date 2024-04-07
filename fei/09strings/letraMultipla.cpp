#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    string rastros;
    while (cin >> rastros)
    {
        int processos;
        cin >> processos;

        int processosAtuais = processos;
        int ciclos = 0;
        for (int i = 0; i < rastros.size(); i++)
        {
            if (rastros[i] == 'W')
            {
                processosAtuais = processos;
                ciclos++;
            }
            else if (rastros[i] == 'R')
            {
                if (processosAtuais == 1 || i + 1 == rastros.size() || rastros[i + 1] != 'R')
                {
                    processosAtuais = processos;
                    ciclos++;
                }
                else
                {
                    processosAtuais--;
                }
            }
        }
        cout << ciclos << endl;
    }
}

