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
	int n, q; cin >> n >> q;
	vector<int> s;
	vector<array<int, 3>> a(n);
	vector<array<int, 2>> b(q);

	for (auto& [l, r, v] : a) {
		cin >> l >> r >> v;
		s.push_back(l), s.push_back(r);
	}

	for (auto& [l, r] : b) {
		cin >> l >> r;
		s.push_back(l), s.push_back(r);
	}

	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());

	auto id = [&s](int x) {
		return lower_bound(s.begin(), s.end(), x) - s.begin();	
	};

	int N = s.size();
	vector<ll> diff(N+10, 0), tam(N+1, 0), pre(N+1, 0);
	for (auto& [l, r, v] : a) {
		diff[id(l)+1] += v;
		diff[id(r)+1] -= v;
	}

	for (int i = 1; i < N; i++) {
		tam[i] = s[i] - s[i-1];
	}

	for (int i = 1; i < N; i++) {
		diff[i] += diff[i-1];
	}

	for (int i = 1; i < N; i++) {
		pre[i] = pre[i-1] + tam[i] * diff[i];
	}

	for (auto& [l, r] : b) {
		cout << pre[id(r)] - pre[id(l)] << endl;
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
