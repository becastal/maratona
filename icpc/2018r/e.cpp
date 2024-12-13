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

	string codigo, objetivo;

	cin >> codigo >> objetivo;

	int tam = codigo.size() - objetivo.size();

	int aux  = 0;

	int cont = 0;


	while(aux < tam){
		bool serve = true;
		int aux2 = 0;
		for(int i = aux; i < aux + tam; i++){
			if(codigo[i] == objetivo[aux2]){
				serve = false;
				break;
			}
			if(aux2 == objetivo.size() - 1 && serve){
				break;	
			}
			aux2++;
		}
		if(serve){
			cont ++;
		}
		aux++;
	}

	cout << cont << endl;
    
    return(0);
}
