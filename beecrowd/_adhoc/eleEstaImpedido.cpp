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

	int a, d;
	while (cin >> a >> d and a and d)
	{
		vector<int> ata(a), def(d);

		for (auto& ai : ata)
			cin >> ai;
		sort(ata.begin(), ata.end());

		for (auto& di : def)
			cin >> di;
		sort(def.begin(), def.end());

		bool imp = false;
		for (int i = 0; i < a and !imp; i++)
			if (ata[i] < def[1])
				imp = true;

		cout << (imp ? 'Y' : 'N') << endl;
	}
    
    return(0);
}
