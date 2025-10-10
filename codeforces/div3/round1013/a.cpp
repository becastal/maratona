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
	
	int t; cin >> t;
	while (t--) {
		string s = "01032025";
		map<int, int> M;
		for (char c : s) {
			M[c-'0']++;
		}

		int n, res = 0; cin >> n;
		for (int i = 0, j = 0, x; i < n; i++) {
			cin >> x;
			if (M.count(x)) if (--M[x] == 0) M.erase(x);
			if (M.empty() and !res) res = i+1;
		}
		cout << res << endl;
	}
    
    return(0);
}
