#include <bits/stdc++.h>
#include <iostream>

using namespace std;
 
int main() {
    set<string> tesouro;
    string joia;

    while (cin >> joia) tesouro.insert(joia);
    
    cout << tesouro.size() << endl;

    return 0;
}