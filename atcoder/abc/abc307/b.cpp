#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	vector<string> A(n);
	for (auto& i : A) cin >> i;

	auto pal = [](string s) {
		for (int l = 0, r = (int)s.size() - 1; l < r; l++, r--) {
			if (s[l] != s[r]) return 0;
		}
		return 1;
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) if (i != j) {
			if (pal(A[i] + A[j])) return cout << "Yes" << endl, 0;
		}
	}
	cout << "No" << endl;

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

