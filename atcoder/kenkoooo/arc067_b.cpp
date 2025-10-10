#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, a, b; cin >> n >> a >> b;
	vector<int> X(n);
	for (int& i : X) cin >> i;

	// grafo entre os pontos. entre dois pontos tu liga uma aresta estre a
	// distancia deles e o w da areta eh a * (X[i] - X[i-1])
	// dai tem um nodo pica que eh o teleportador. de todo ponto tu liga uma
	// aresta com preco zero ate ele e prevo b de volta ao ponto.
	// res eu acho que eh *max_element(all(dists)) 

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
