#include <Grafo.h>
#include <set>
#include "iostream"

using namespace std;

template <typename C> void DFS_FOREST(const Grafo<C> & grafo);
template <typename C> void DFS(const Grafo<C> & grafo, int origen, set<int> & visitados);

template <typename C> void DFS_FOREST(const Grafo<C> & grafo)
{
    set<int> visitados;
    list<int> vertices;
    grafo.devolver_vertices(vertices);
    list<int>::iterator itV = vertices.begin();
    while(itV != vertices.end()) {
        if(visitados.find(*itV) == visitados.end()) { // no visitado
            cout << "\n" << endl;
            DFS(grafo, *itV, visitados);
        }
        itV++;
    }
}

template <typename C> void DFS(const Grafo<C> & grafo, int origen, set<int> & visitados)
{
    visitados.insert(origen);
    list<typename Grafo<C>::Arco> adyacentes;
    grafo.devolver_adyacentes(origen, adyacentes);
    cout << origen << "--> ";
    typename list<typename Grafo<C>::Arco>::iterator itA = adyacentes.begin();
    while(itA != adyacentes.end()) {
        if(visitados.find(itA->devolver_adyacente()) == visitados.end()) { // no visitado
            DFS(grafo, itA->devolver_adyacente(), visitados);
        }
        itA++;
    }
    cout << origen << "--> ";
}
