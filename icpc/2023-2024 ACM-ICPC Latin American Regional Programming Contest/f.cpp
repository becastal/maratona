#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

vector<int> base(ll n, ll b) {
	vector<int> R;
	while (n) {
		R.push_back(n % b);	
		n /= b;
	}

	return R;
}

int pal(vector<int> A) {
	for (int l = 0, r = (int)A.size() - 1; l < r; l++, r--) {
		if (A[l] != A[r]) return 0;
	}
	return 1;
}

// O(sqrt(n) + log(n)cbrt(n));
const ll MAX = 1e5;
int solve() {
	ll n; cin >> n;

	vector<ll> R;
	for (ll i = 2; i * i <= n; i++) if (n % i) {
		if (pal(base(n, i))) R.push_back(i);
	}

	auto add_2 = [&](ll a) {
		if (a >= 2 and a < n and base(n, a).size() == 2) R.push_back(a);
	};

	for (ll a = 1; a * a <= n; a++) if (n % a == 0) {
		add_2(n / a - 1);	
		if (n / a != a) add_2(n / (n / a) - 1);
	}

	if (!R.size()) return cout << "*" << endl, 0;
	sort(all(R));
	R.erase(unique(all(R)), R.end());

	for (int i = 0; i < (int)R.size(); i++) {
		cout << R[i] << " \n"[i==(int)R.size()-1];
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
