#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
	int n, m; cin >> n >> m;

	vector<int> Ult(m, -1);
	string S; cin >> S;
	vector<int> C(n);
	for (int& i : C) {
		cin >> i;
		i--;
	}

	for (int i = n-1; i >= 0; i--) {
		if (Ult[C[i]] == -1) {
			Ult[C[i]] = i;
			continue;
		}
		swap(S[Ult[C[i]]], S[i]);
		Ult[C[i]] = i;
	}
	cout << S << endl;

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

