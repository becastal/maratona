// albertini que fez
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

#define f first
#define s second

#define vi vector<int>
#define grafo vector<vector<int>>

#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll memo[55][1000050];

ll maxi , mini , tempo;

ll pd(ll t , ll nivel , ll caminhos){
		if(t == tempo)
			return 0;
		if(nivel - 1 >= mini){
				ll &pdm = memo[t + 1][nivel - 1];
				if(pdm == -1)
					pdm = pd(t + 1 , nivel - 1 , -1);
					caminhos += 1 + pdm;
		}
		if(nivel + 1 <= maxi){
				ll &pdm = memo[t + 1][nivel + 1];
				if(pdm == -1)
					pdm = pd(t + 1 , nivel + 1 , -1);
					caminhos += 1 + pdm;	
		}
		return caminhos;
	}

int main(){ _
	
	cin >> tempo >> mini >> maxi;

	ll soma = 0;
	memset(memo , -1 , sizeof(memo));
	
	for(int i = mini ; i <= maxi ; i++){
		soma += pd(1 , i , 0);
		soma %= ll(1e9) + 7;
	}
	cout << soma << endl;

	return 0;
}
