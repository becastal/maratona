#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	string A, B, C; cin >> A >> B >> C;
	int t = (int)A.size(), n = (int)B.size(), m = (int)C.size();

	map<char, int> M;
	for (int i = 0; i < t; i++) {
		M[A[i]] = i;
	}

	vector<int> W(n), S(m);
	
	for (int i = 0; i < n; i++) {
		W[i] = M[B[i]];
	}
	
	for (int i = 0; i < m; i++) {
		S[i] = M[C[i]];
	}

	vector<int> P(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j and W[i] != W[j]) j = P[j-1];
		P[i] = (j += W[i] == W[j]);
	}

	vector<int> R;
	for (int shift = 0; shift < t; shift++) {
		int matches = 0;	

		for (int i = 0, j = 0; i < m; i++) {
			while (j and W[j] != (S[i] - shift + t) % t) j = P[j-1];				
			if (W[j] == (S[i] - shift + t) % t) j++;
			if (j == n) matches++, j = P[j-1];
		}

		if (matches == 1) R.push_back(shift);
	}

	if (R.empty()) return cout << "no solution" << endl, 0;
	if (R.size() == 1) return cout << "unique: " << R[0] << endl, 0;
	cout << "ambiguous: ";
	for (int i = 0; i < (int)R.size(); i++) {
		cout << R[i] << " \n"[i==(int)R.size()-1];
	}

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

