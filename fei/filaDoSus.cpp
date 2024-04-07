#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        queue<pair<int, int>> pacientes; // <minutagemChegada, minutagemCritica>
        for (int i = 0; i < n; i++)
        {
            int h, m, c;
            cin >> h >> m >> c;
            int minutagemChegada = (h - 7) * 60 + m;
            int minutagemCritica = minutagemChegada + c;
            pacientes.push({ minutagemChegada, minutagemCritica });
        }
        int relogio = 0;
        int contagemPacientesCriticos = 0;
        while (!pacientes.empty())
        {
            if (relogio <= pacientes.front().first)
            {
                relogio = pacientes.front().first;
                if (relogio % 30 != 0) relogio += 30 - (relogio % 30);
            }
            if (relogio > pacientes.front().second) contagemPacientesCriticos++;
            pacientes.pop();
            relogio += 30;
        }
        cout << contagemPacientesCriticos << endl;
    }
    return 0;
}