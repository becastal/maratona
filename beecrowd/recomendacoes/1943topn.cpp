#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> range {1, 3, 5, 10, 25, 50, 100};
    int n; cin >> n;
    int i = 0;
    while (n > range[i]) i++;
    cout << "Top " << range[i] << endl;
}
