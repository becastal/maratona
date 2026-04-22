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

    int n, d, soma = 0;

    cin >> n;

    vector < int > necessario(n,22);

    for(int i = 0; i < n -1; i ++){
        cin >> d;
        soma +=d;
    }


    int cont = 0;
    int aux = 0;
    while(true){
        if(aux == n){
            break;
        }
        int resto = (soma+cont) % n;
        if(necessario[resto] == 22){
            aux ++;
            if(cont <= 20){
                necessario[resto] = cont;
            }
            else{
                necessario[resto] = -1;
            }
        }
        cont++;

    }
    for(int i = 0; i < necessario.size(); i++){
        cout << necessario[i] << endl;
    }

    return(0);
}
