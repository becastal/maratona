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

	int n; cin >> n;
	vector<int> v(n);
	set<int> s;
	for (int& i : v) cin >> i, s.insert(i);
	
	if (s.size() == 1) return cout << !!v[0] << endl, 0;

	int res = 0;
	for (int i : v) res |= (i & 1);
	res++;

	cout << res << endl;
    
    return(0);
}
