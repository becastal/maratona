#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main() {
	int n;cin>>n;
	stack<int>pai;
	vector<pair<int,int>> ans;
	for(int c = 0; c < n*2; c++){
		string a;int v;cin>>a>>v;
		if(a == "in"){ if(!pai.empty()) ans.push_back({pai.top(), v});pai.push(v);}
		else pai.pop();
	}
	for(auto& [x, y] : ans)cout<<x<<' '<<y<<endl;
	return 0;
}
