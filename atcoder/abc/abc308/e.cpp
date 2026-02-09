#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	considerar o do meio sempre.
	olhar pra toda array o possivel mex dela.
*/

int solve() {
	int n; cin >> n;
	vector<int> A(n);
	for (int& i : A) cin >> i;
	string S; cin >> S;

	vector<pair<vector<int>, int>> B;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				vector<int> vis(3);				
				vis[i] = vis[j] = vis[k] = 1;
				int mex = 0;
				while (mex < 3 and vis[mex]) mex++;
				B.push_back(make_pair(vector<int>{i, j, k}, mex));	
			}
		}
	}

	map<pair<char, int>, int> Mp, Ms;
	Mp[make_pair(S[0], A[0])] = 1;
	for (int i = 1; i < n; i++) {
		Ms[make_pair(S[i], A[i])]++;
	}

	ll res = 0;
	for (int i = 1; i < n-1; i++) {
		auto agr = make_pair(S[i], A[i]);
		Ms[agr]--;

		for (auto [v, mex] : B) {
			ll a = Mp[make_pair('M', v[0])], b = (agr == make_pair('E', v[1])), c = Ms[make_pair('X', v[2])];
			res += (a * b * c) * mex;
		}

		Mp[agr]++;
	}
	cout << res << endl;

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

