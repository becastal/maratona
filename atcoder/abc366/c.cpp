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

	int q, tam = 0; cin >> q;
	map<int, int> mp;
	while (q--) {
		int qi; cin >> qi;
		if (qi == 3) {
			cout << tam << endl;
			continue;
		}

		int x; cin >> x;
		if (qi == 1) {
			tam += !mp.count(x);
			mp[x]++;
		} else {
			mp[x]--;
			if (!mp[x]) {
				mp.erase(x);
				tam--;
			}
		}
	}
    
    return(0);
}
