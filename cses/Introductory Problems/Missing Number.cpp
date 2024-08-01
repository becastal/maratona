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
	vector<bool> v(n + 1, 0);

	for (int i = 0; i < n - 1; i++) {
		int x; cin >> x;
		v[x] = 1;
	}

	for (int i = 1; i <= n; i++)
		if (!v[i])
			return cout << i << endl, 0;
    
    return(0);
}
