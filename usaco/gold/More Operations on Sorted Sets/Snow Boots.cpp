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
	int n, b; cin >> n >> b;
	vector<int> H(n), L(n), R(n), pior(n+1);
	for (int& i : H) cin >> i;

	stack<int> S;
	for (int i = 0; i < n; i++) {
		while (S.size() and H[S.top()] >= H[i]) {
			S.pop();
		}
		L[i] = (S.size() ? S.top() : -1);
		S.push(i);
	}

	while (S.size()) S.pop();
	for (int i = n-1; i >= 0; i--) {
		while (S.size() and H[S.top()] >= H[i]) {
			S.pop();
		}
		R[i] = (S.size() ? S.top() : n);
		S.push(i);
	}

	for (int i = 0; i < n; i++) {
		pior[R[i] - L[i] - 1] = max(pior[R[i] - L[i] - 1], H[i]);
	}

	for (int i = n-1; i >= 1; i--) {
		pior[i] = max(pior[i], pior[i+1]);
	}

	for (int i = 0, s, d; i < b; i++) {
		cin >> s >> d;
		cout << int(s >= pior[d]) << endl;
	}

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("snowboots");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
