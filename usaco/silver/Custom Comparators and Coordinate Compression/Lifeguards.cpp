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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("lifeguards");

	int n; cin >> n;
	vector<int> s;
	vector<pair<int, int>> a(n);
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
	vector<ll> diff(N, 0), pre(N+1, 0), tam(N, 1);

	for (auto [l, r] : a) {
		diff[id(l)]++;
		diff[id(r)]--;
	}

	for (int i = 1; i < N; i++) {
		diff[i] += diff[i-1];
	}
	for (int i = 0; i < N - 1; i++) {
		tam[i] = s[i+1] - s[i];
	}

	for (int i = 1; i <= N; i++) {
		pre[i] = pre[i-1] + (diff[i-1] == 1) * tam[i-1];
	}

	ll tot = 0;
	for (int i = 0; i < N; i++) {
		if (diff[i] != 0) tot += tam[i];
	}

	//for (int i : diff) cout << i << ' '; cout << endl;
	//for (int i : pre) cout << i << ' '; cout << endl;

	ll mn = LINF;
	for (auto [l, r] : a) {
		mn = min(mn, pre[id(r)] - pre[id(l)]);
	}

	cout << tot - mn << endl;

    return(0);
}
