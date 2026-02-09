#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*

pra toda ordenacao topologica valida, quantos valores
podem aparecer em cada posicao?

*/

int solve() {
	int n; cin >> n;
	string S; cin >> S;

	vector<vector<int>> G(n);
	for (int i = 0; i < n-1; i++) {
		if (S[i] == 'L') G[i].push_back(i + 1);
		else G[i+1].push_back(i);
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

