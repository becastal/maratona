map<string, int> m;

// Outra forma de inserir elementos 
m.emplace("Fusca", 1975);
m.emplace("Santana", 2001);

string carro = "Jetta";
auto it = m.find(carro);

if(it != m.end()) cout<<"Ano do carro: "<<m[carro]<<endl;
else cout<<"Carro nao cadastrado!"<<endl;
