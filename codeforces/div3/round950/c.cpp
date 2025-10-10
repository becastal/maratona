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
		int n; cin >> n;
		vector<int> a(n), b(n);
		map<int, int> as, bs, cs;
		for (int& i : a) cin >> i, as[i]++;
		for (int& i : b) cin >> i, bs[i]++;

		map<int, int> preciso;
		for (int i = 0; i < n; i++)
			if (a[i] != b[i]) preciso[b[i]]++;

		int m; cin >> m;	
		vector<int> c(m);
		for (int& i : c) cin >> i, cs[i]++;

		for (int i : c)
		{
			cs[i]--;
			if (preciso[i] > 0) preciso[i]--;
			else
			{
				
			}
		}

		bool res = true;
		cout << (res ? "YES" : "NO") << endl;
	}
    
    return(0);
}
