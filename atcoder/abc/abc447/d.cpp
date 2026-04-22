#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	string S; cin >> S;
	int n = (int)S.size();

	vector<vector<int>> P(3);
	vector<int> C(3);
	for (int i = n-1; i >= 0; i--) {
		P[S[i]-'A'].push_back(i);
		C[S[i]-'A']++;
	}

	int res = 0;
	for (int c = 0, b = 0, a = 0; c < C[2] and b < C[1] and a < C[0];) {
		int pa = P[0][a], pb = P[1][b], pc = P[2][c];

		if (pb > pc) {
			b++;
		} else if (pa > pb) {
			a++;	
		} else {
			a++, b++, c++;
			res++;
		}
	}
	cout << res << endl;

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

