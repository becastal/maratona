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

int ed(const string& a, const string& b) {
	int n = (int)a.size(), m = (int)b.size();

	int res = 0;
	for (int i = 0; i < min(n, m); i++) {
		res += a[i] != b[i];	
	}
	return res;
};

int main()
{
    _;

	string a; cin >> a;
	int k, res = INF, pos;; cin >> k;

	vector<string> v(5);
	for (int i = 0; i < 5; i++) {
		cin >> v[i];

		int agr = ed(a, v[i]);
		if (agr <= k and agr < res) {
			res = agr;
			pos = i+1;
		}
	}

	if (res == INF) {
		cout << -1 << endl;
	} else {
		cout << pos << endl << res << endl;
	}
    
    return(0);
}
