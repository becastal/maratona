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

	int n, i, f; cin >> n >> i >> f;
	vector<int> v(n);
	for (auto& vi : v)
		cin >> vi;

	int c = 0;
	for (int j = 0; j < n; j++)
		for (int k = j + 1; k < n; k++)
			if (v[j] + v[k] >= i and v[j] + v[k] <= f)
				c++;

	cout << c << endl;
    
    return(0);
}
