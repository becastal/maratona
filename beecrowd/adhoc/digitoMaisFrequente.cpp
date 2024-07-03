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
    
	vector<int> v(10, 0);
	string n;
	while (cin >> n)
	{
		fill(v.begin(), v.end(), 0);
		for (auto c : n)
			v[c - '0']++;

		int maior = 0, x;
		for (int i = 9; i >= 0; i--)
			if (v[i] > maior)
			{
				maior = v[i];
				x = i;
			}

		cout << x << endl;
	}
	
    return(0);
}
