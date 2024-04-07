#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++) 
    {
        int t, v;
        cin >> t >> v;
        total += t*v;
    }
    cout << total << endl;
}
