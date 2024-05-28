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
	
	int t = 0, v;
	vector<int> m = {50, 10, 5, 1};
	while (cin >> v and v)
	{
		cout << "Teste " << ++t << endl;
		for (int i = 0; i < m.size(); i++)
		{
			cout << v / m[i] << (i == m.size() - 1 ? "" : " ");
			v -= (v / m[i]) * m[i];
		}
		cout << endl << endl;
	}
    
    return(0);
}
