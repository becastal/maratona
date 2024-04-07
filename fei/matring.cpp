#include <iostream>
#include <vector>
#include <string>

using namespace std;
 
int main() {
    string linha;
    string f = "", l = "";
    getline(cin, linha);
    vector<string> caracteres(linha.size() - 2);
    for (int i = 0; i < 4; i++)
    {
        f += linha[0];
        l += linha[linha.size()-1];
        for (int j = 1; j < linha.size() - 1; j++)
        {
            caracteres[j - 1] += linha[j];
        }
        if (i < 3) {getline(cin, linha);}
    }

    int F = stoi(f);
    int L = stoi(l);
    char ans;
    for (int k = 0; k < caracteres.size(); k++)
    {
        int Mi = stoi(caracteres[k]);
        ans = (F * Mi + L) % 257;
        cout << ans;
    }
    cout << endl;
    
    return 0;
}