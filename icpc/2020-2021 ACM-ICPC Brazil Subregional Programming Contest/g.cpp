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

int n; 
vector<int>valor;

int dp(int indice , int saldo){
		if(indice == n)return saldo;
		return max(dp(indice + 1 , saldo + valor[indice]) , saldo);
	}

int main()
{
    _;
	cin >> n;
	valor.resize(n);

	for(int& x : valor) cin >> x;

	cout << dp(0 , 100) << endl;
    return(0);
}
