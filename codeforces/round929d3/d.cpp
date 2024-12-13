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

int solve() {
	// cada numero precisa ter pelo menos um numero que nao o divide ou um numero maior que ele do lado dele.
	// eu ordeno e tento colocar os valores repetidos em outras posicoes?

	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;

	sort(v.begin(), v.end());
	if (v[0] != v[1]) return cout << "yes" << endl, 0;

	int da = 0;
	for (int i = 1; i < n and !da; i++) {
		da |= (v[i] % v[0] != 0);
	}

	cout << (da ? "yes" : "no") << endl;
	return 0;
}

int main()
{
    _;
	
	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
