#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

class Celda {
public:
    int fila;
    int columna;
    int esfuerzo;

    Celda(int f, int c, int e) : fila(f), columna(c), esfuerzo(e) {}
};

class ComparadorCelda {
public:
    bool operator()(const Celda& a, const Celda& b) const {
        return a.esfuerzo > b.esfuerzo;
    }
};

int esfuerzoMinimoRuta(vector<vector<int>>& alturas) {
    int filas = alturas.size();
    int columnas = alturas[0].size();

    vector<pair<int, int>> direcciones = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    auto esValida = [&](int fila, int columna) {
        return fila >= 0 && fila < filas && columna >= 0 && columna < columnas;
    };

    priority_queue<Celda, vector<Celda>, ComparadorCelda> pq;
    vector<vector<int>> distancia(filas, vector<int>(columnas, INT_MAX));

    pq.push(Celda(0, 0, 0));
    distancia[0][0] = 0;

    while (!pq.empty()) {
        Celda actual = pq.top();
        pq.pop();

        if (actual.fila == filas - 1 && actual.columna == columnas - 1) {
            return actual.esfuerzo;
        }

        for (auto& dir : direcciones) {
            int nuevaFila = actual.fila + dir.first;
            int nuevaColumna = actual.columna + dir.second;
            if (esValida(nuevaFila, nuevaColumna)) {
                int nuevoEsfuerzo = max(actual.esfuerzo, abs(alturas[actual.fila][actual.columna] - alturas[nuevaFila][nuevaColumna]));
                if (nuevoEsfuerzo < distancia[nuevaFila][nuevaColumna]) {
                    distancia[nuevaFila][nuevaColumna] = nuevoEsfuerzo;
                    pq.push(Celda(nuevaFila, nuevaColumna, nuevoEsfuerzo));
                }
            }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> alturas1 = {{1,2,2},{3,8,2},{5,3,5}};
    cout << esfuerzoMinimoRuta(alturas1) << endl;

    vector<vector<int>> alturas2 = {{1,2,3},{3,8,4},{5,3,5}};
    cout << esfuerzoMinimoRuta(alturas2) << endl;

    vector<vector<int>> alturas3 = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    cout << esfuerzoMinimoRuta(alturas3) << endl;

    return 0;
}
