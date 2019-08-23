#include <iostream>
#include <vector>

using namespace std;

void Jumping_Mario(int casos);
vector<int> leer_saltos(int n_saltos);
vector<int> definir_saltos(vector<int> salts);
void imprimir_caso(int caso,int sal_alt, int sal_baj);

int main() {
   int num_de_casos = 0;
   cin>>num_de_casos;
    Jumping_Mario(num_de_casos);



}

void Jumping_Mario(int casos)
{
    vector<int> saltos_de_todos;
    for(int i = 0; i<casos;i++)
    {
        int num_saltos = 0;
        cin>>num_saltos;
        vector<int> tamano_de_saltos;
        tamano_de_saltos = leer_saltos(num_saltos);
        vector<int> tipo_saltos;
        tipo_saltos = definir_saltos(tamano_de_saltos);
        saltos_de_todos.push_back(tipo_saltos[0]);
        saltos_de_todos.push_back(tipo_saltos[1]);
    }
    for(int i = 0, m = 0; i<casos; i++)
    {
        imprimir_caso(i+1, saltos_de_todos[m],saltos_de_todos[m+1]);
        m = m+2;
    }
}

vector<int> leer_saltos(int n_saltos)
{
    vector<int> tamanos;
    for(int i = 0;i < n_saltos;i++)
    {
        int un_salto = 0;
        cin>>un_salto;
        tamanos.push_back(un_salto);
    }
    return tamanos;
}

vector<int> definir_saltos(vector<int> salts)
{
    int saltos_altos = 0;
    int saltos_bajos = 0;
    for(int i = 0; i < salts.size()-1;i++)
    {
        if(salts[i]>salts[i+1])saltos_bajos++;
        if(salts[i]<salts[i+1])saltos_altos++;
    }
    vector<int> tip_salts = {saltos_altos,saltos_bajos};
    return tip_salts;
}

void imprimir_caso(int caso, int sal_alt, int sal_baj)
{
    cout<<"Case "<<caso<<": "<<sal_alt<<" "<<sal_baj<<endl;
}