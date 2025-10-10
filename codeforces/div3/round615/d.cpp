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

	int q, x; cin >> q >> x;
	vector<int> v(x, 0);
	set<int> mex;
	for (int i = 0; i <= 4e5+10; i++) {
		mex.insert(i);
	}
	
	while (q--) {
		int y; cin >> y;
		mex.erase(v[y % x]++ * x + (y % x));
		cout << *mex.begin() << endl;
	}
    
    return(0);
}
