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

	int n, m; cin >> n >> m;
	vector<int> deg(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		deg[u] ^= 1;	
		deg[v] ^= 1;	
	}

	int ruim = 0;
	for (int i = 0; i < n and !ruim; i++) {
		ruim |= deg[i];
	}

	cout << (ruim ? "Rambo esta perdido" : "Rambo esta salvo") << endl;
    
    return(0);
}
