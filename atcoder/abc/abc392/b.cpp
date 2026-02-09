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

	int m, n; cin >> n >> m;

	set<int> s;
	for (int i = 1; i <= n; i++) {
		s.insert(i);
	}

	for (int i = 0, x; i < m; i++) {
		cin >> x;
		if (s.count(x)) s.erase(x);
	}

	cout << s.size() << endl;
	for (int i : s) cout << i << ' '; cout << endl;
    
    return(0);
}
