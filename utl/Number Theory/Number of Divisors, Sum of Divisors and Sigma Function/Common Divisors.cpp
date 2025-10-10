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
 
	const int MAX = 1e6+10;
	int n; cin >> n;
	vector<int> v(n), cont(MAX+1, 0);
 
	for (int& i : v) {
		cin >> i;
		cont[i]++;
	}
 
	for (int d = MAX; d >= 1; d--) {
		int agr = 0;
 
		for (int j = d; j <= MAX; j += d) {
			agr += cont[j];
			if (agr > 1) {
				return cout << d << endl, 0;
			}
		}
	}
    
    return(0);
}
