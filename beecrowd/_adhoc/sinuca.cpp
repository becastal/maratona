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
	vector<vector<int>> b;

	b.push_back(vector<int>(n));
	for (auto& bi : b.back())
		cin >> bi;

	while (n > 1)
	{
		vector<int> bi(b.back().size() - 1);
		
		for (int i = 0; i < bi.size(); i++)
			bi[i] = (b.back()[i] == b.back()[i + 1] ? 1 : -1);
		
		b.push_back(bi);
		n--;
	}

	cout << (b.back()[0] == 1 ? "preta" : "branca" ) << endl;
    
    return(0);
}
