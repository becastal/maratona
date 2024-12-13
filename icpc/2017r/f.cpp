// alexandre que fez
#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
using namespace std;



int main() {
    _;
    int pessoas, passou;

    cin >> pessoas;
    cin >> passou;

    vector<int>notas(pessoas,0);

    for(int i = 0; i < pessoas; i++){
        cin >> notas[i];
    }

    sort(notas.begin(), notas.end());
    reverse(notas.begin(), notas.end());

    int cont = 0;

    for(int i = 0; i < pessoas; i++){
        if(i < passou-1){
            cont++;
        }
        else if(i == passou-1){
            while(notas[cont] == notas[cont+1]){
                cont++;
            }
            cont++;
            break;
        }
    }

    cout << cont << endl;

    return 0;
}


