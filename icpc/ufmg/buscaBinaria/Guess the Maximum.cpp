#include <bits/stdc++.h>
#define f first
#define s second
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int solve() {
	auto query_set = [](set<int>& S) {
		cout << "? " << (int)S.size();
		for (int i : S) cout << ' ' << i;
		cout << endl;
		int res; cin >> res;
		return res;
	};
	auto query_pref = [](int n) {
		cout << "? " << n;
		for (int i = 1; i <= n; i++) cout << ' ' << i;
		cout << endl;
		int res; cin >> res;
		return res;
	};

	int n, k; cin >> n >> k;
	
	vector<vector<int>> S(k);
	vector<int> P(n + 1, -1);
	for (int i = 0, c; i < k; i++) {
		cin >> c;
		S[i] = vector<int>(c);
		for (int j = 0; j < c; j++) {
			cin >> S[i][j];
			P[S[i][j]] = i;
		}

	}

	int mx = query_pref(n);
	int l = 1, r = n, res = r;
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (query_pref(m) == mx) {
			r = m-1;
			res = m;
		} else {
			l = m+1;
		}
	}

	vector<int> pass(k, mx);
	int pos = P[res];

	if (res >= 1 and res <= n and P[res] != -1) {
		set<int> Q;
		for (int i = 1; i <= n; i++) Q.insert(i);
		for (int i : S[pos]) Q.erase(i);
		if (P[res] < k) pass[P[res]] = query_set(Q);
	}

	cout << "!";
	for (int i : pass) cout << ' ' << i;
	cout << endl;
	string ver; cin >> ver;
	if (ver != "Correct") exit(0);

	return(0);
}

int main()
{
    //_;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
