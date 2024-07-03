#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

    vector<int> dados;
    int n, d, soma;

    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> d;

        dados.push_back(d);

        soma+=d;
    }

    int menor = INF;
    for(int i = 1; i < 7; i++){
        soma = 0;
        for(int j = 0; j < n; j++){
            if(dados[j] + i == 7){
                soma += 2;
            }
            else if( dados[j] + i != 7 && dados[j] != i ){
                soma += 1;
            }
        }
        if( soma < menor){
            menor = soma;
        }
    }

    cout << menor << endl;

    return(0);
}
