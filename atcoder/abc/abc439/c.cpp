#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n; cin >> n;

	map<int, int> M;
	vector<int> A, R;
	for (int b = 1; b * b < n; b++) {

		int nn = (int)A.size();
		for (int i = 0; i < nn and b * b + A[i] * A[i] <= n; i++) {
			M[b * b + A[i] * A[i]]++;
		}
		A.push_back(b);
	}
	
	sort(all(R));

	for (auto [a, b] : M) if (b == 1) {
		R.push_back(a);
	}

	int nn = (int)R.size();
	cout << nn << endl;
	for (int i = 0; i < nn; i++) {
		cout << R[i] << " \n"[i==nn-1];
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

