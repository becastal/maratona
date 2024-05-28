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

	vector<vector<char>> t;
	t.push_back(vector<char>(16));
	iota(t.back().begin(), t.back().end(), 'A');
	
	while (t.back().size() > 1)
	{
		vector<char> n(t.back().size() / 2);
		for (int i = 0; i < n.size(); i++)
		{
			int a, b; cin >> a >> b;
			n[i] = (a > b ? t.back()[i * 2] : t.back()[i * 2 + 1]);
		}
		t.push_back(n);
	}
	for (int i = 0; i < t.back().size(); i++)
		cout << t.back()[i] << endl;
    
    return(0);
}
