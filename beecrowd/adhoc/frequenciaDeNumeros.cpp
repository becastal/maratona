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

	vector<int> v(2e3 + 10, 0);

	int n; cin >> n;
	while (n--)
	{
		int ni; cin >> ni;
		v[ni]++;
	}

	for (int i = 0; i < v.size(); i++)
		if (v[i])
			cout << i << " aparece " << v[i] << " vez(es)" << endl;
    
    return(0);
}
