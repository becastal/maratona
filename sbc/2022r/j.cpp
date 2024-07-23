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
	vector<int> cont(20, 0);

	int j1, j2; cin >> j1 >> j2; cont[j1]++, cont[j2]++;
	int m1, m2; cin >> m1 >> m2; cont[m1]++, cont[m2]++;

	int j = min(10, j1) + min(10, j2), m = min(10, m1) + min(10, m2);

	while (n--)
	{
		int i; cin >> i;
		cont[i]++;
		j += min(i, 10), m += min(i, 10);
	}

	int maria = 0;
	for (int i = 1; i <= 13; i++)
	{
		if (cont[i] == 4) continue;
		int ji = j + min(i, 10), mi = m + min(i, 10);
		if (mi == 23 or (ji > 23 and mi < 23))
		{
			maria = min(i,10);
			break;
		}
	}

	cout << (maria ? maria : -1) << endl;

    return(0);
}
