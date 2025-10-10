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

	int q; cin >> q;
	map<int, int> maxl, minr;
	while (q--) {
		char c; cin >> c;
		int l, r; cin >> l >> r;
		
		if (c == '+') {
			maxl[l]++;
			minr[r]++;
		} else {
			if (--maxl[l] == 0) maxl.erase(l);
			if (--minr[r] == 0) minr.erase(r);
		}

		cout << (maxl.size() and maxl.rbegin()->f > minr.begin()->f ? "YES" : "NO") << endl;
	}
    
    return(0);
}
