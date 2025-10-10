#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n;cin>>n;n--;

	string pal;cin>>pal;

	vector<string> dic(n);

	for(auto& s : dic)cin>>s;

	int q;cin>>q;
	
	set<char> conj;

	for(char c : pal)conj.insert(c);

	while(q--){
		string line;cin>>line;
		int ans = 0;
		for(string w : dic){
			int ok = 1;
			for(int i = 0; i < (int)line.size(); i++){
				if(line[i] == '*' and w[i] != pal[i]) ok = 0;
				else if(line[i] == '!' and (w[i] == pal[i] or !conj.count(w[i]))) ok = 0;
				else if(line[i] == 'X' and (w[i] == pal[i] or conj.count(w[i]))) ok = 0;
			}
			ans += ok;
		}
		cout<<max(ans, 1)<<endl;
	}
	exit(0);
}
