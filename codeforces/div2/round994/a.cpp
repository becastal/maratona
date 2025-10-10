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

void solve() {
	int n; cin >> n;
	vector<int> v(n);

	map<int, int> freq;
	for (int& i : v) cin >> i, freq[i]++;

	if (freq.size() == 1) {
		cout << int(v[0] != 0) << endl;
		return;
	}

	v.insert(v.begin(), 0);
	v.push_back(0);

	// se tiver so uma sequencia de nao zero
	int cont = 0;
	for (int i = 1; i < (int)v.size(); i++) {
		if (v[i] and !v[i-1]) cont++;
	}

	cout << (cont == 1 ? 1 : 2) << endl;
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
