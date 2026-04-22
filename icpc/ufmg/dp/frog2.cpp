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
	vector<int> h(n), c(n, INF);
	for (int& hi : h)
		cin >> hi;
	c[0] = 0;

	for (int i = 1; i < n; i++)
		for (int j = i; j >= 0 and j >= i - k; j--)
			c[i] = min(c[i], c[j] + abs(h[i] - h[j]));

	cout << c[n - 1] << endl;
    
    return(0);
}
