#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

vector<int> nums;
int solve() {
	ll x; cin >> x;

	auto ter = [](ll a) {
		vector<int> res;
		while (a) {
			res.push_back(a  % 3);
			a /= 3;
		}
		res.push_back(0);
		return res;
	};
	auto ter_ = [](vector<int> v) {
		ll res = 0, agr = 1;
		for (int c : v) {
			if (c == 1) res += agr;
			agr *= 3;
		}
		return res;
	};

	//int res = *lower_bound(nums.begin(), nums.end(), x);
	//cout << res << ": " << endl << ter(x) << endl << ter(res) << endl << endl;
	auto v = ter(x);
	int n = (int)v.size();

	int pos = -1, pos_;
	for (int i = 0; i < n; i++) {
		if (v[i] == 2) {
			pos = i;
		}
	}
	if (pos == -1) return cout << x << endl, 0;

	for (pos_ = pos; pos_ < n; pos_++) {
		if (!v[pos_]) break;
	}
	v[pos_] = 1;
	for (int i = 0; i < pos_; i++) {
		v[i] = 0;
	}

	cout << ter_(v) << endl;

	return(0);
}

int main()
{
    _;

	vector<ll> pot;
	for (ll tr = 1; tr < (ll)1e5; tr *= 3LL) {
		pot.push_back(tr);
	}

	int n = (int)pot.size(); 
	for (int i = 1; i < (1 << n); i++) {
		int agr = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				agr += pot[j];
			}
			//cout << !!(i & (1 << j));
		}
		//cout << ": " << agr << endl;
		nums.push_back(agr);
	}

	sort(nums.begin(), nums.end());

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
