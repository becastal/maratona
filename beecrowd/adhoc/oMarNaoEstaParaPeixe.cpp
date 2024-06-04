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
	vector<vector<int>> v(n, vector<int>(4));
	
	for (auto& vi : v)
		for (int i = 0; i < 4; i++)
			cin >> vi[i];

	int area = 0;

	for (int i = 1; i < 100; i++)
		for (int j = 1; j < 100; j++)
		{
			bool dentro = false;
			for (int k = 0; k < n; k++)
				if (v[k][0] <= i and i < v[k][1] and v[k][2] <= j and j < v[k][3])
					dentro = true;
			if (dentro)
				area++;
		}

	cout << area << endl;
    
    return(0);
}
