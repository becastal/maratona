#include <bits/stdc++.h>
using namespace std;

bool ehOperador(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int pesoOperador(char c)
{
    map<char, int> pesoOperador{ {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3} };
    return (pesoOperador[c]);
}

bool comparePairs(const pair<int, char>& a, const pair<int, char>& b) {
    return a.second > b.second;
}

int main()
{
    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        queue<pair<char, int>> operadores;
        queue<char> valores;
        stack<bool> parenteses;
        string linha; cin >> linha;

        for (int j = 0; j < linha.size(); j++)
        {
            if (linha[j] == '(') parenteses.push(true);
            else if (linha[j] == ')') parenteses.pop();
            else if (ehOperador(linha[j]))
            {
                operadores.push({linha[j], pesoOperador(linha[j])+(3*(parenteses.size()+1))});
            }
            else 
            {
                valores.push(linha[j]);
            }
        }

        string resposta = "";
        vector<pair<char, int>> fila;
        resposta += valores.front(); valores.pop();
        while (!valores.empty())
        {
            resposta += valores.front(); valores.pop();
            fila.push_back(operadores.front()); operadores.pop();
            while (!operadores.empty() && operadores.front().second > fila.back().second)
            {
                resposta += valores.front(); valores.pop();
                fila.push_back(operadores.front()); operadores.pop();
            }
            vector<pair<char, int>>::iterator it = fila.begin();
            if (!operadores.empty())
            {
                sort(fila.begin(), fila.end(), comparePairs);
                while (it != fila.end() && fila.size() > 0)
                {
                    if (it->second >= operadores.front().second)
                    {
                        resposta += it->first;
                        it = fila.erase(it);
                    }
                    else ++it;
                }
            }
        }
        sort(fila.begin(), fila.end(), comparePairs);
        for(int j = 0; j < fila.size(); j++) 
        {
            resposta += fila[j].first;
        }
        cout << resposta << endl;
    }
}
