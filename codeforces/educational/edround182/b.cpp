#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;
	vector<int> A(n), foi(n+1, 0);

	for (int& i : A) {
		cin >> i;
		foi[i] = 1;
	}

	int j = n;
	for (int& i : A) if (!i) {
		while (foi[j]) j--;
		i = j--;
	}

	if (is_sorted(all(A))) return cout << 0 << endl, 0;

	int l = 0, r = n-1;
	for (int i = 0; i < n; i++) {
		if (A[i] != (i + 1)) {
			l = i;
			break;
		}
	}

	for (int i = n-1; i >= 0; i--) {
		if (A[i] != (i + 1)) {
			r = i;
			break;
		}
	}

	cout << r - l + 1 << endl;

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

