#include "grafo.h"
#include <iostream>
using namespace std;

Grafo::Grafo(int num_vertices) {
    if(num_vertices<=0){
        throw(invalid_argument("Erro no construtor. Número de vértices é inválido!"));
    }   
    num_vertices_ = num_vertices;
    num_arestas_=0;

    matriz_adj_.resize(num_vertices);
    for(int i=0; i<num_vertices; i++){
        matriz_adj_[i].resize(num_vertices,0);
    }
}

int Grafo::num_vertices(){
return num_vertices_;
}

int Grafo::num_arestas(){
return num_arestas_;
}

/*bool Grafo::tem_aresta(int i, int j){
    if(matriz_adj_[i][j]!=0){
        return true;
    }
    return false;
} */
bool Grafo::tem_aresta(Aresta e){
    if(matriz_adj_[e.v1][e.v2]!=0){
        return true;
    } 
    return false;
}

void Grafo::insert_aresta(Aresta a){
    if(tem_aresta(a)||a.v1==a.v2){
        return;
    }
    matriz_adj_[a.v1][a.v2]=1;
    matriz_adj_[a.v2][a.v1]=1;
    num_arestas_++;
    return;
}

void Grafo::remove_aresta(Aresta a){
    if(!tem_aresta(a)){
        return;
    }
    matriz_adj_[a.v1][a.v2]=0;
    matriz_adj_[a.v2][a.v1]=0;
    num_arestas_--;
    return;
}

void Grafo::imprime_grafo(){
    for(int i=0; i<num_vertices_; i++){
        cout<<i<<": ";
    for (int j = 0; j <num_vertices_; j++)
    {
        if (matriz_adj_[i][j]!=0){
            cout<<j<<" "; 
        }
    }
    cout<<'\n';
    }    
}

int Grafo::calcula_grau(int v){
    int grau=0;
    for(int i=0; i<num_vertices_; i++){
        if(matriz_adj_[v][i]!=0){
            grau++;
        }
    }
    return grau;
}
bool Grafo::tem_caminho(int v, int w, int marcado[],int num_chamadas) {
 for (int i = 0; i < num_chamadas; i++){
 cout<<" ";
 }
 cout <<"Caminho ("<<v<<w<<")"<<'\n';
 if (v == w) {
 printf("%d-", v);
 return true;
 }
 marcado[v] = 1;
 for (int u = 0; u < num_vertices_; u++)
 if (matriz_adj_[v][u] != 0)
 if (marcado[u] == 0)
 if (tem_caminho(u, w, marcado,num_chamadas+1)) {
 printf("%d-", v);
 return true;
 }
 return false;
}
