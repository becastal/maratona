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

	const int N = 2e5 + 10;
	vector<int> soma(N, 0);

	auto f = [] (int i) {
		int cont = 0;
		while (i) {
			i /= 3;
			cont++;
		}
		return cont;
	};

	auto solve = [&]() {
		int l, r; cin >> l >> r;
		cout << soma[r] - soma[l-1] + f(l) << endl;
	};

	for (int i = 1; i < N; i++) {
		soma[i] = soma[i-1] + f(i);
	}

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
