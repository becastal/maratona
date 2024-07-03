#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 55;
using namespace std;

int n , limite;
ll inferior , superior;

vector<ll> pesos;

ll dp(int indice , ll cap , int caixas){
		if(cap > superior) return 0;
		if(caixas == 0 and cap >= inferior) return 1;
		else if(caixas == 0) return 0;
		if(n - indice + 1 < caixas)return 0;		
		if(indice == n) return 0;

		return dp(indice + 1 , cap + pesos[indice] , caixas-1) + 
						dp(indice + 1 , cap , caixas);
	}

int main()
{
    _;
	cin >> n >> limite;	
	pesos.resize(n);
	for(ll& x : pesos) cin >> x;
	cin >> inferior >> superior;
	if(limite > n)
		cout << 0 << endl;
	else
		cout << dp(0 , 0 , limite) << endl;

    return(0);
}

