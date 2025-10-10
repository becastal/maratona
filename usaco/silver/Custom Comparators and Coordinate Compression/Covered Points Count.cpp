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
	int n; cin >> n;
	vector<pair<ll, ll>> a(n);
	vector<ll> s;
	for (auto& [l, r] : a) {
		cin >> l >> r; r++;
		s.push_back(l), s.push_back(r);
	}
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());

	auto id = [&s](ll x) {
		return lower_bound(s.begin(), s.end(), x) - s.begin();
	};

	int N = s.size();
	vector<ll> diff(N, 0), cont(n+1, 0);
	for (auto [l, r] : a) {
		diff[id(l)]++;
		diff[id(r)]--;
	}

	ll agr = 0;
	for (int i = 0; i < N-1; i++) {
		agr += diff[i];
		cont[agr] += s[i+1] - s[i];
	}

	for (int i = 1; i <= n; i++) {
		cout << cont[i] << " \n"[i==n];
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
