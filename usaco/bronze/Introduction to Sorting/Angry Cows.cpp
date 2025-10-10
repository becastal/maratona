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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("angry");

	int n; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	sort(a.begin(), a.end());

	int res = 0;
	for (int i = 0; i < n; i++) {
		int agr = 1;
		
		for (int r = i, d = 1; r + 1 < n; d++) {
			int r_ = r;
			while (r + 1 < n and a[r + 1] - a[r_] <= d) r++, agr++;
			if (r_ == r) break;
		}
		
		for (int l = i, d = 1; l - 1 >= 0; d++) {
			int l_ = l;
			while (l - 1 >= 0 and a[l_] - a[l - 1] <= d) l--, agr++;
			if (l_ == l) break;
		}

		res = max(res, agr);
	}
	cout << res << endl;
	
    return(0);
}
