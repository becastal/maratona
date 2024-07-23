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

	int t; cin >> t;
	while (t--)
	{
		int n, m; cin >> n >> m;
		vector<char> a(n), b(m);
		vector<int> op(m);
		for (char& ai : a)
			cin >> ai;

		set<int> s;
		for (int& opi : op)
		{
			cin >> opi;
			s.insert(opi);
		}

		for (char& bi : b)
			cin >> bi;
		
		sort(b.begin(), b.end());
		int j = 0;
		for (int i : s)
			a[i - 1] = b[j++];	

		for (char c : a)
			cout << c;
		cout << endl;
	}

    
    return(0);
}
