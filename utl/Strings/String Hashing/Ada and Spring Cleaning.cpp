#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int _1e99 = 1e9+9;
const int _1e97 = 1e9+7;
const int p = 696969;

int solve() {
	int n, k; cin >> n >> k;
	string S; cin >> S;

	vector<int> base9(n+1, 1), base7(n+1, 1);
	for (int i = 1; i < n; i++) {
		base9[i] = base9[i-1] * p % _1e99;
		base7[i] = base7[i-1] * p % _1e97;
	}

	int hash9 = 0, hash7 = 0;
	set<int> Set;
	for (int i = 0; i < k; i++) {
		hash9 = (hash9 * p + S[i]) % _1e99;
		hash7 = (hash7 * p + S[i]) % _1e97;
	}

	auto H = [&](int a, int b) {
		return a << 30 | b;
	};

	Set.insert(H(hash9, hash7));
	for (int i = k; i < n; i++) {
		hash9 = (hash9 * p + S[i]) % _1e99;
		hash9 = (hash9 - base9[k] * S[i-k] % _1e99) % _1e99;
		if (hash9 < 0) hash9 += _1e99;

		hash7 = (hash7 * p + S[i]) % _1e97;
		hash7 = (hash7 - base7[k] * S[i-k] % _1e97) % _1e97;
		if (hash7 < 0) hash7 += _1e97;

		Set.insert(H(hash9, hash7));
	}
	cout << Set.size() << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

