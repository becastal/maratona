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
	vector<int> v(n), r(n);

	for (auto& vi : v)
		cin >> vi;

	for (int i = 1; i < n - 1; i++)
		r[i] = v[i] + v[i - 1] + v[i + 1];

	r[0] = v[0] + v[1];
	r[n - 1] = v[n - 1] + v[n - 2];

	for (auto ri : r)
		cout << ri << endl;
    
    return(0);
}
