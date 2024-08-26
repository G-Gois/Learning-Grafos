#ifndef GRAFO_H
#define GRAFO_H
#include <vector>
#include "aresta.h"
class Grafo{
public:
    Grafo(int vertices);
    int num_vertices();
    int num_arestas();
    //bool tem_aresta(int i, int j);
    bool tem_aresta(Aresta e);
    void insert_aresta(Aresta a);
    void remove_aresta(Aresta a);
    void imprime_grafo();
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::vector<int>> matriz_adj_;  
};
#endif
