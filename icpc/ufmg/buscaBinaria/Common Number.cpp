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
	ll n, k; cin >> n >> k;

	// primeiro ponto que cont(y, n) eh >= k
	// cont(y, n) nao eh monotonico em y, entao tem que fazer tipo
	// max de sufixo de cont(y, n).
	auto lista = [&](int x) -> vector<int> {
		if (x == 1) return {1};
		vector<int> cam = {x};
		do {
			x = (x & 1) ? x-1 : x/2;
			cam.push_back(x);
		} while (x != 1);
		reverse(all(cam));
		return cam;
	};

	for (int y = 1; y <= n; y++) {
		for (int i = 1; i <= n; i++) {
			cout << i << ": ";
			vector<int> v = lista(i);
			if (count(all(v), y)) for (int j = 0; j < (int)v.size(); j++) {
				cout << (j ? ", " : "") << v[j]; 
			}
			cout << endl;
		}
		cout << "-------------------" << endl << endl;
	}


	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
