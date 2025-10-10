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
	for (auto& vi : v)
		cin >> vi;

	int l = 0, r = n - 1;
	int sl = v[l], sr = v[r];
	while (l != r - 1)
	{
		if (sl <= sr)
			sl += v[++l];
		else
			sr += v[--r];
	}

	cout << l + 1 << endl;
    
    return(0);
}
