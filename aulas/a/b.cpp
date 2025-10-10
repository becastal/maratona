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

	vector<vector<int>> p;
	vector<int> p8(8);
	iota(all(p8), 0);
	do {
		p.push_back(p8);
	} while(next_permutation(all(p8)));
	sort(all(p));

	vector<int> P(64);
	iota(all(P), 1);
	shuffle(all(P), mt19937{random_device{}()});
	for (int i : P) cout << i << ' '; cout << endl << endl;

	auto vals = [&](vector<int> a) {
		vector<int> b;
		for (int i = 0; i < 8; i++) {
			b.push_back(P[i * 8 + a[i]]);
		}
		return b;
	};
	auto comprime = [](vector<int> a) {
		vector<int> b(a);
		sort(all(b));
		b.erase(unique(all(b)), b.end());
		for (int& i : a) i = lower_bound(all(b), i) - b.begin();
		return a;
	};

	for (int i = 0; i < 40320; i++) {
		vector<int> V = vals(p[i]);
		if (!i or comprime(V) == p[i]) {
			cout << "BOM (" << i << ")" << endl;
			cout << "P: "; for (int j : V) cout << j << ' '; cout << endl;
			cout << "p: "; for (int j : p[i]) cout << j << ' '; cout << endl;
		}
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
