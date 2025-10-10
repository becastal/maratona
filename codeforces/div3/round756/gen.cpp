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
	vector<int> v(n);
	iota(v.begin(), v.end(), 1);

	int tam = 1;
	for (int i = 1; i <= n; i++) {
		tam *= i;
	}
	cout << tam << endl;

	do {
		cout << n << endl;
		for (int i : v) cout << i << ' '; cout << endl;
	} while(next_permutation(v.begin(), v.end()));
    
    return(0);
}
