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
 
const int MAX = 1e5 + 10;
ll fat[MAX];
 
void fatorial(){
    fat[0] = 1;
    for(int i = 1 ; i < MAX; i++){
        fat[i] = i * fat[i - 1];
    }
}
 
ll fexp(ll a, ll b){
    if(b == 0){
        return 1;
    }
    if(b % 2 == 0){
        return fexp(a * a, b/2);
    }
    return a * fexp(a, b - 1);
 
}
 
ll comb(int n, int i){
    return fat[n] / (fat[i] * fat[n - i]);
}
 
int main()
{
    _;
 
	fatorial();
	vector<ll> pre(MAX, 0);
	pre[3] = 16, pre[4] = 48, pre[5] = 96;
 
	for (int i = 6; i < MAX; i++)
	{
		pre[i] = 4 * 2 + 8 * 3;
		pre[i] += (8 + ((i - 5) * 4)) * 4;
		pre[i] += (4 + ((i - 5) * 4)) * 6;
		pre[i] += (pow(i - 4, 2)) * 8;
	}
 
	int n; cin >> n;
	for (ll k = 1; k <= n; k++)
		cout << ((k * k * (k * k - 1)) / 2)  - pre[k] / 2 << endl;
    
    return(0);
}
