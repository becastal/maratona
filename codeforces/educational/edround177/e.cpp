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

vector<ll> zebra;
int solve() {

	vector<int> dp(N, INF);
	dp[0] = 0;

	for (int i = 0; i < N; i++) {
		for (int j : zebra) if (i - j >= 0) {
			dp[i] = min(dp[i], dp[i-j] + 1);
		}
	}

	auto greedy = [&](ll x) {
		int res = 0;
		for (int i = zebra.size()-1; i >= 0 and x; i--) {
			int q = x / zebra[i];	
			res += q;
			x -= q * zebra[i];
		}
		return res;
	};

	map<int, int> f;
	for (int i = 1; i < N; i++) {
		if (dp[i] != greedy(i)) return cout << i << endl, 0;
		f[dp[i]]++;
	}
	for (auto [a, b] : f) {
		cout << a << ": " << b << endl;
	}
	dbg(*max_element(all(dp)));

	return(0);
}

int main()
{
    _;

	ll z = 1;
	for (int i = 0; i < 32; i++) {
		zebra.push_back(z);
		z <<= 2; z |= 1;	
	}

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
