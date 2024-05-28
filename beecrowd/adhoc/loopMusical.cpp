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
	while (cin >> n and n)
	{
		vector<int> l(n);
		for (auto& li : l)
			cin >> li;

		int r = 0;
		for (int i = 0; i < n; i++)
		{
			int ant = l[((i - 1) + n) % n]; 
			int pos = l[(i + 1) % n]; 

			if ((l[i] < ant and l[i] < pos) or (l[i] > ant and l[i] > pos))
				r++;
		}
		cout << r << endl;
	}
    
    return(0);
}

