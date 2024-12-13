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

	int t, d, m; cin >> t >> d >> m;
	deque<int> v(m);
	for (int& vi : v)
		cin >> vi;
	v.push_front(0);
	v.push_back(d);

	bool res = false;
	for (int i = 1; i < (int)v.size(); i++)
		res |= (v[i] - v[i - 1]) >= t;

	cout << (res ? 'Y' : 'N') << endl;
    
    return(0);
}
