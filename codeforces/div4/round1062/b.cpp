#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(26, 0), B(A);

	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		A[c-'a']++;
	}
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		B[c-'a']++;
	}
	cout << (A == B ? "YES" : "NO") << endl;

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

