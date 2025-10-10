set<int> s;

for(int i = 0; i < 10; i++) s.insert(i);
for(int i = 0; i < 10; i++) s.insert(i);

cout<<"Tamanho: "<<s.size()<<endl;
s.erase(2);
cout<<"Tamanho: "<<s.size()<<endl;
cout<<"2 esta no conjunto? "<<s.count(2)<<endl;
