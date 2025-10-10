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
	auto query = [](vector<int> A) -> int {
		cout << "? " << (int)A.size() << ' ';
		for (int i : A) cout << i << ' ';
		cout << endl;
		int res; cin >> res;
		return res;
	};
	auto query_pref = [](int n) -> int {
		cout << "? " << n << ' ';
		for (int i = 1; i <= n; i++) cout << i << ' ';
		cout << endl;
		int res; cin >> res;
		return res;
	};

	int n; cin >> n;
	int l = 1, r = n;
	while (l <= r) {
		int m = (l + r) / 2;

		if (query_pref(m)) {
			r = m-1;
		} else {
			l = m+1;
		}
	}
	int pos = l;
	if (pos == n+1) pos = 1;

	string res = "";
	for (int i = 1; i < n; i += 2) {
		vector<int> Q;
		for (int j = 0; j < 3; j++) Q.push_back(i), Q.push_back(pos), Q.push_back(pos);
		Q.push_back(i+1), Q.push_back(pos), Q.push_back(pos);
		int qi = query(Q);
		if (qi == 4) res += "((";
		else if (qi == 3) res += "()";
		else if (qi == 1) res += ")(";
		else res += "))";
	}
	if (n % 2) {
		int qi = query({n, pos});
		if (qi) res += "(";
		else res += ")";
	}
	cout << "! " << res << endl;

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
