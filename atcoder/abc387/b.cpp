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
	
	int tot = 0;
	map<int, int> f;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			f[i*j]++;
			tot += i*j;
		}
	}

	int x; cin >> x;
	cout << tot - f[x] * x << endl;
    
    return(0);
}
