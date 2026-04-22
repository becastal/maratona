#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, q; cin >> n >> q;
	map<int, int> F;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
		F[i]++;
	}

	while (q--) { 
		int k; cin >> k;
		vector<int> B(k);
		for (int& i : B) {
			cin >> i; i--;
			if (--F[A[i]] == 0) F.erase(A[i]);
		}

		cout << F.begin()->first << endl;

		for (int& i : B) {
			F[A[i]]++;
		}
	}

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

