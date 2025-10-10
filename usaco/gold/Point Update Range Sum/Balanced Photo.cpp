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
	int n; cin >> n;
	vector<int> H(n);
	for (int& i : H) cin >> i;

	vector<int> H_ = H;
	sort(all(H_));
	H_.erase(unique(all(H_)), H_.end());
	for (int& i : H) i = lower_bound(all(H_), i) - H_.begin() + 1;

	vector<int> bit(n+1, 0), L(n), R(n);
	for (int i = 0; i < n; i++) {
		L[i] = i;
		for (int j = H[i]-1; j; j-=j&-j) L[i] -= bit[j];
		for (int j = H[i]; j <= n; j+=j&-j) bit[j]++;
	}

	fill(all(bit), 0);
	for (int i = n-1; i >= 0; i--) {
		R[i] = n - i - 1;
		for (int j = H[i]-1; j; j-=j&-j) R[i] -= bit[j];
		for (int j = H[i]; j <= n; j+=j&-j) bit[j]++;
	}

	int res = 0;
	for (int i = 0, mn, r; i < n; i++) {
		//printf("(%d, %d)\n", L[i], R[i]);
		res += (max(L[i], R[i]) > 2 * min(L[i], R[i]));
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
	setIO("bphoto");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}

