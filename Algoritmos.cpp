#include <Grafo.h>
#include <set>
#include "iostream"

using namespace std;

template <typename C> void DFS_FOREST(const Grafo<C> & grafo);
template <typename C> void DFS(const Grafo<C> & grafo, int origen, set<int> & visitados);

template <typename T> bool buscarCamino(const Grafo<T> & grafo, int origen, int destino, set<int> & visitados, list<int> & camino);
template <typename T> void buscarCaminos(const Grafo<T> & grafo, int origen, int destino, set<int> & visitados, list<int> & camino, list<list<int>> & caminos);

template <typename T> void imprimir_lista(const list<T> & lista);
template <typename T> void imprimir_caminos(const list<list<int>> & caminos);

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

template <typename T>
bool buscarCamino(const Grafo<T> & grafo, int origen, int destino, set<int> & visitados, list<int> & camino)
{

    visitados.insert(origen);
    camino.push_back(origen);

    if(origen == destino) {
        return true;
    }
    else {
        list<typename Grafo<T>::Arco> adyacentes;
        grafo.devolver_adyacentes(origen, adyacentes);

        typename list<typename Grafo<T>::Arco>::iterator itA = adyacentes.begin();
        while(itA != adyacentes.end()) {
            if(visitados.find(itA->devolver_adyacente()) == visitados.end()) {
                if(buscarCamino(grafo, itA->devolver_adyacente(), destino, visitados, camino)) {
                    return true;
                }
            }
            itA++;
        }
    }
    visitados.erase(origen);
    camino.pop_back();
    return false;
}

template <typename T> void imprimir_lista(const list<T> & lista)
{
    typename list<T>::const_iterator itL = lista.begin();
    while(itL != lista.end()) {
        cout << *itL << " ";
        itL++;
    }
}

template <typename T> void imprimir_caminos(const list<list<T>> & caminos)
{
    list<list<int>>::const_iterator itL = caminos.begin();
    while(itL != caminos.end()) {
        list<int>::const_iterator itL2 = itL->begin();
        cout << "\n";
            while(itL2 != itL->end()) {
                cout << *itL2 << " ";
                itL2++;
            }
        itL++;
    }
}

template <typename T> void buscarCaminos(const Grafo<T> & grafo, int origen, int destino, set<int> & visitados, list<int> & camino, list<list<int>> & caminos)
{
    visitados.insert(origen);
    camino.push_back(origen);
    if(origen == destino) {
        //imprimir_lista(camino);
        caminos.push_back(camino);
    }
    list<typename Grafo<T>::Arco> adyacentes;
    grafo.devolver_adyacentes(origen, adyacentes);
    typename list<typename Grafo<T>::Arco>::iterator itA = adyacentes.begin();
    while(itA != adyacentes.end()) {
        if(visitados.find(itA->devolver_adyacente()) == visitados.end())
        {
            buscarCaminos(grafo, itA->devolver_adyacente(), destino, visitados, camino, caminos);
        }
        itA++;
    }
    visitados.erase(origen);
    camino.pop_back();
}

