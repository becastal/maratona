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
	int a[3] = {};
	a[1] = 1;
	int n; cin >> n;

	int x , y;

	for(int i = 0 ; i < n ; i++){
			cin >> x >> y;
			swap(a[x-1],a[y-1]);
		}
	for(int i = 0 ; i < 3;i++)
		if(a[i] == 1)cout << i+1<<endl;
    return(0);
}
