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

	int n, k; cin >> n >> k;
	int c = n;
	for (int i = 0; i < n; i++)
	{
		int vi; cin >> vi;
		if (vi > 0) c--;
	}

	cout << (c >= k ? "YES" : "NO") << endl;

    return(0);
}
