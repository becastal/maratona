#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;
	string S; cin >> S;

	set<int> A;
	for (int i = 0, x; i < m; i++) {
		cin >> x;
		A.insert(x);
	}

	for (int i = 0, p = 1; i < n; i++) {
		p++;
		if (S[i] == 'B') while (A.count(p)) p++;
		A.insert(p);
		if (S[i] == 'B') while (A.count(p)) p++;
	}

	cout << A.size() << endl;
	for (int i : A) cout << i << ' '; cout << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

