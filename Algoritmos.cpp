#include <Grafo.h>
#include <set>

template <typename C> void DFS_FOREST(const Grafo<C> & grafo);
template <typename C> void DFS(const Grafo<C> & grafo, int origen, set<int> & visitados);

template <typename C> void DFS_FOREST(const Grafo<C> & grafo)
{
    set<int> visitados;
    list<int> vertices;
    grafo.devolver_vertices(vertices);
    list<int>::iterator itV = vertices.begin();
    while(itV != vertices.end()) {
        if(vertices.find(*itV) != vertices.end()) { // no visitado
            cout << "\n" << endl;
            DFS(grafo, *itV, visitados);
        }
        itV++;
    }
}

template <typename C> void DFS(const Grafo<C> & grafo, int origen, set<int> & visitados)
{
    visitados.insert(origen);
    cout << origen << "--> ";
    typename list<Arco> adyacentes;
    grafo.devolver_adyacentes(origen, adyacentes);
    typename list<Arco>::iterator itA = adyacentes.begin();
    typename list<Arco>::iterator itA_aux;
    while(itA != adyacentes.end()) {
        itA_aux =
        if(adyacentes.find(itA->devolver_adyacente() != adyacentes.end())) { // no visitado
            DFS(grafo, origen, visitados);
        }
    }
}


