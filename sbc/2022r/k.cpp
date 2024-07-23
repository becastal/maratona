#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5 + 10;
const int mod = 1e9;
using namespace std;
int N , M , K;

int memo[MAX+10][400+10];
vector<pair<int , int>> v;


int dp(int ind , int e , int p){
		cout << "==============" << endl;
		dbg(ind); dbg(e); dbg(p);
		if(e < 0) return 0;
		if(p > N) return 0;
		if(p == N) return 1;
		if(ind == M) return 0;
		auto& [x,y] = v[ind];
		int& pdm = memo[ind][e];

		//if(pdm != -1) return pdm;
		pdm = 0;
		pdm = (pdm+ dp(ind , e-y , p+x))%mod;
		pdm = (pdm + dp(ind+1 , e , p))%mod;
		dbg(pdm);	
		return pdm;
	}
int main()
{
    _;
   	cin >> N >> M >> K; 
	memset(memo , -1 , sizeof memo);
	v.resize(M);

	for(auto& [x,y] : v) cin >> x >> y;

	cout << dp(0 , K , 1) << endl;
    return(0);
}
