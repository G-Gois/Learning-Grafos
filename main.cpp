#include "grafo.h"
#include <iostream>
using namespace std;

int main(){
    try{
        int num_vertices;
        cout<<"Digite o número de vértices: ";
        cin>>num_vertices;
        Grafo g(num_vertices);
        cout<<"Numero de vertices: "<<g.num_vertices()<<'\n';
        cout<<"Numero de arestas: "<<g.num_arestas()<<'\n';
        
        //criando Aresta 2,3
        Aresta e(2,3);
        g.insert_aresta(e);
        cout<< "tem aresta 2,3?";
        g.tem_aresta(e)==true?cout<<" TEM"<<'\n' : 
        cout<<" Num tem"<< '\n';
        g.imprime_grafo();
    } catch(const exception &e){
        cerr <<e.what()<<"\n";
    }
    return 0;
}