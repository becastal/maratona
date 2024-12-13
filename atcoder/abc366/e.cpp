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


int main() {
    _;

	const int m = 2e6;
	int n, d; cin >> n >> d;
	vector<int> X(n, 0), Y(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> X[i] >> Y[i];
	}

	auto f = [&](vector<int> v) {
		vector<ll> soma(2*m+1, 0);
		sort(v.begin(), v.end());

		soma[0] = accumulate(v.begin(), v.end(), (ll)0) + (ll)n * (ll)m;
		int i = 0;
		for (int x = 1; x <= 2*m; x++) {
			while (i < n and v[i] < x - m) {
				i++;
			}
			soma[x] = soma[x-1] + 2 * i - n;
		}
		sort(soma.begin(), soma.end());
		return soma;
	};

	auto xs = f(X), ys = f(Y);

	ll res = 0;
	int j = 0;
	for (int i = 2*m; i >= 0; i--) {
		while (j < 2*m+1 and xs[i] + ys[j] <= d) {
			j++;
		}
		res += j;
	}

	cout << res << endl;
    
    return 0;
}
