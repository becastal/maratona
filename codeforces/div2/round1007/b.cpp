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
	ll n; cin >> n;

	ll N = n * (n+1) / 2;
	ll sr = sqrt(N);
	if (sr * sr == N) {
		cout << -1 << endl;
		return;
	}

	auto sqr = [](ll x) {
		ll sr = sqrt(x);
		return sr * sr == x;
	};

	vector<int> res;

	ll s = 0;
	for (int i = 0; i < n; i++) {
		s += i + 1;
		res.push_back(i+1);

		if (sqr(s)) {
			s += i + 2;
			res.push_back(i+2);
			swap(res.back(), res[(int)res.size()-2]);
			i++;
			continue;
		}
	}
	
	for (int i : res) cout << i << ' '; cout << endl;
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
