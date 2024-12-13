#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

	int n, m; cin >> n >> m;
	vector<vector<int>> A(m);

	for (int i = 0; i < n; i++) {
		int ni; cin >> ni;
		for (int j = 0; j < ni; j++) {
			int x; cin >> x; x--;
			A[x].push_back(i);
		}
	}

	vector<vector<pair<int, int>>> G(n), g(n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < A[i].size(); j++) {
			for (int k = j+1; k < A[i].size(); j++) {
				G[j].emplace_back(k, m);
				G[k].emplace_back(j, m);
			}
		}
	}

	// montar spanning agora
    
    return(0);
}
