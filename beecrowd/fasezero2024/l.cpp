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
	vector<string> c(n);
	queue<string> mais;

	for (auto& p : c)
		cin >> p;

	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		mais.push(s);
	}

	set<string> tirou;
	for (int i = 0; i < n; i++)
	{
		while (tirou.find(mais.front()) != tirou.end())
			mais.pop();

		cout << mais.front() << (i < n - 1 ? " " : "");
		tirou.insert(c[i]);
	}

	cout << endl;
    
    return(0);
}
