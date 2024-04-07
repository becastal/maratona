#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


int main()
{
    while (true)
    {
        int n; cin >> n;
        if (n == 0) break;

        vector<pair<bool, int>> problemas(27, { false, 0 });
        for (int i = 0; i < n; i++)
        {
            char identificador;
            int tempo;
            string julgamento;

            cin >> identificador >> tempo >> julgamento;
            int indice = abs(65 - identificador);
            if (julgamento == "correct")
            {
                problemas[indice].first = true;
                problemas[indice].second += tempo;
            }
            else
            {
                problemas[indice].second += 20;
            }
        }

        int quantidadeAcertos = 0, totalTempo = 0;
        for (int i = 0; i < problemas.size(); i++)
        {
            if (problemas[i].first)
            {
                quantidadeAcertos++;
                totalTempo += problemas[i].second;
            }
        }
        cout << quantidadeAcertos << " " << totalTempo << endl;
    }
}
