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

	vector<string> r = {"azar", "azar", "azar", "terno", "quadra", "quina", "sena"}; 
	set<int> s;

	for (int i = 0; i < 6; i++)
	{
		int ni; cin >> ni;
		s.insert(ni);
	}

	int q = 0;
	for (int i = 0; i < 6; i++)
	{
		int ni; cin >> ni;
		q += s.count(ni);
	}

	cout << r[q] << endl;
    
    return(0);
}
