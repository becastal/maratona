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
	vector<pair<int, int>> a(n);
	vector<int> s;
	for (auto& [l, r] : a) {
		cin >> l >> r;
		s.push_back(l), s.push_back(r);
	}

	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());

	auto id = [&s](int x) {
		return lower_bound(s.begin(), s.end(), x) - s.begin();
	};

	int N = s.size();
	vector<int> diff(N+10, 0);
	for (auto [l, r] : a) {
		diff[id(l)]++;	
		diff[id(r)]--;	
	}

	for (int i = 1; i <= N; i++) {
		diff[i] += diff[i-1];
	}

	cout << *max_element(diff.begin(), diff.end()) << endl;

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
