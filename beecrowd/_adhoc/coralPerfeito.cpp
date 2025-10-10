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

	int n;
	while (cin >> n)
	{
		int s = 0;
		vector<int> v(n);
		for (auto& vi : v)
		{
			cin >> vi;
			s += vi;
		}

		int m = s / n, r = 0;
		for (auto vi : v)
			r += abs(m - vi);

		r /= 2;
		r++;

		if (s % m != 0)
			r = -1;

		cout << r << endl;
	}
    
    return(0);
}
