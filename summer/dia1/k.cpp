#include <bits/stdc++.h>
#define f first
#define s secont
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 2e5+10;

using namespace std;

int main() {
	int n;cin>>n;
	vector<int> v(n), pref(n+1, 0);
	for(int& i : v)cin>>i;
	
	string in;cin>>in;
	
	for(int i = 1; i < n; i++) pref[i] = pref[i-1] + (in[i-1] == '1');

	for(int i = 0; i < n; i++){
		if(v[i] == i+1)continue;

		int M = max(i, v[i]-1);
		int m = min(i, v[i]-1);

		int dif = M-m;
		if(pref[M] - pref[m] != dif) return cout<<"NO"<<endl, 0;
	}
	cout<<"YES"<<endl;
	// AMO O ALE PIERRI	
	return 0;
}
