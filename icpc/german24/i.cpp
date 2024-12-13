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

	const int MAX = 1.7e6+10;
	set<int> livre;
	for (int i = 0; i < MAX; i++) {
		livre.insert(i);
	}

	int n; cin >> n;
	vector<int> sapos(n+1);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		livre.erase(x);
		sapos[i+1] = x;
	}

	int q; cin >> q;
	while (q--) {
		int s; cin >> s;
		int pos = sapos[s];

		int npos = *lower_bound(livre.begin(), livre.end(), pos+1);
		cout << npos << endl;
		livre.insert(pos);
		livre.erase(npos);
		sapos[s] = npos;
	}

    
    return(0);
}
