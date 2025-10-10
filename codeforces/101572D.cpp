#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	int n, k; cin >> n >> k;
	queue<int> Q;
	vector<int> D(1 << k, INF), A(n, 0);

	for (int i = 0; i < n; i++) {
		string S; cin >> S;
		for (int j = 0; j < k; j++) {
			if (S[j] == '1') A[i] |= (1 << j);
		}
		Q.push(A[i]);
		D[A[i]] = 0;
	}

	while (Q.size()) {
		int u = Q.front(); Q.pop();

		for (int i = 0; i < k; i++) {
			int v = u ^ (1 << i);
			if (D[v] != INF) continue;
			D[v] = D[u] + 1;
			Q.push(v);
		}
	}

	int pos = max_element(all(D)) - D.begin();
	for (int j = 0; j < k; j++) cout << (pos >> j & 1);
	cout << endl;

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
