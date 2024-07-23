#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e6 + 10;
using namespace std;

int main()
{
    _;
	int v[MAX] = {0};

	int n; cin >> n;
	vector<int> b(n);

	for(int& x : b) cin >> x;

	int cont = 0;

	for(int& x : b){
			if(v[x] == 0){
					v[x-1] += 1;
					cont++;
				}
			else{
					v[x]--;
					v[x-1]++;
				}
		}
	cout << cont << endl;
    return(0);
}
