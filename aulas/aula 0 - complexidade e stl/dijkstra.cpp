#include <bits/stdc++.h>
using namespace std;

int main()
{
	set<string> S;
	unordered_set<string> S;

	string si;
	while (cin >> si) {
		S.insert(si);
	}

	cout << S.size() << endl;
	cout << "o que tem no set: " << endl;
	for (auto s : S) cout << s << endl;
    
    return(0);
}
