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

int solve() {
	int n; cin >> n;
	int m = 2*n, res = 0;
	vector<int> A(m);
	for (int& i : A) cin >> i, i--;

	vector<int> L(n, -1), bit(m+1, 0);
	for (int i = 0; i < m; i++) {
		if (L[A[i]] == -1) {
			L[A[i]] = i;
			for (int j = i+1; j <= m; j+=j&-j) bit[j]++;
		} else {
			// somar quantos tem o L maior que o meu
			int query = 0;
			for (int j = m; j; j-=j&-j) query += bit[j];
			for (int j = L[A[i]]+1; j; j-=j&-j) query -= bit[j];

			res += query;
			for (int j = L[A[i]]+1; j <= m; j+=j&-j) bit[j]--;
		}
	}
	cout << res << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("circlecross");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
