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

	vector<int> v(4);
	for (auto& vi : v)
		cin >> vi;

	sort(v.begin(), v.end());
	cout << abs((v[0] + v[3]) - (v[1] + v[2])) << endl; 
    
    return(0);
}
