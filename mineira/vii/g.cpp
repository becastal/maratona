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

	vector<pair<int , int>> montes(n);

	for(auto& x : montes) cin >> x.f >> x.s;

	sort(montes.begin() , montes.end());

	bool cond = true;
	int mini = INF;
	for(int i = 0 ; i < n ; i++){
			if(montes[i].s > mini){
					cond = false; break;
				}
			mini = min(mini , montes[i].s);
		}
	if(cond) cout << "S" << endl;
	else cout << "N" << endl;
    return(0);
}
