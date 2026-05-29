#include <stdio.h>

#define INF 9999999

int edge_list[][3] = {
  // {v, u, w}

  {0, 1, 4},
  {0, 2, 2},
  {0, 5, 7},

  {1, 2, 1},
  {1, 3, 5},
  {1, 6, 12},

  {2, 3, 8},
  {2, 4, 10},
  {2, 5, 3},

  {3, 4, 2},
  {3, 6, 6},
  {3, 7, 9},

  {4, 7, 4},
  {4, 8, 11},

  {5, 6, 1},
  {5, 8, 13},

  {6, 7, 2},
  {6, 9, 7},

  {7, 8, 3},
  {7, 9, 5},

  {8, 9, 1},
};

void dijkstra(int edge_list[][3], int size, int start)
{
  int graph[size][size];

  // inicializando grafo
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      graph[i][j] = 0;

  // {v, u, w}
  // graph[v][u] = w;
  // montando matriz de adjacência a partir de lista de edges
  for (int i = 0; i < 21; i++) {
    int v = edge_list[i][0];
    int u = edge_list[i][1];
    int w = edge_list[i][2];
    graph[v][u] = w;
    graph[u][v] = w;
  }

  int visited[size];
  int dist[size];

  // inicializando listas de visitados e de distancias
  for (int i = 0; i < size; i++) {
    visited[i] = 0;
    dist[i] = INF;
  }

  dist[start] = 0;

  for (int cnt = 0; cnt < size - 1; cnt++) {
    int min = INF;
    int min_idx = -1;
    for (int i = 0; i < size; i++) 
      if (!visited[i] && dist[i] < min) {
        min = dist[i];
        min_idx = i;
      }

    if (min_idx == -1)
      break;

    int u = min_idx;
    visited[u] = 1;

    //relaxamento 
    for (int i = 0; i < size; i++) {
      if (!visited[i] &&
          dist[u] != INF &&
          graph[u][i] != 0 &&
          dist[u] + graph[u][i] < dist[i])
      {
        dist[i] = dist[u] + graph[u][i];
      }
    }
  }

  printf("Vertice escolhido: %d\n", start);
  printf("Vertice adjacente \t Distancia Minima\n");
  for (int i = 0; i < size; i++) {
    if (i != start)
      printf("%d \t\t\t %d\n", i, dist[i]);
  }
}

int main(void)
{
  dijkstra(edge_list, 10, 0);
}
