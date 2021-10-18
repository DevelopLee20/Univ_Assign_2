#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType{
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

int get_min_vertex(int n){
    int v;
    for(int i=0; i<n; i++){
        if(!selected[i]){
            v = i;
            break;
        }
    }
    for(int i=0; i<n; i++){
        if(!selected[i] && (distance[i] < distance[v])){
            v = i;
        }
    }
    return (v);
}

void prim(GraphType *g, int s){
    for(int u=0; u<g->n; u++){
        distance[u] = INF;
    }
    distance[s] = 0;

    for(int i=0; i<g->n; i++){
        int u = get_min_vertex(g->n);
        selected[u] = TRUE;
        
        if(distance[u] == INF){
            return;
        }
        printf("정점 %d 추가\n", u);

        for(int v=0; v<g->n; v++){
            if(g->weight[u][v] != INF){
                if(!selected[v] && g->weight[u][v] < distance[v]){
                    distance[v] = g->weight[u][v];
                }
            }
        }
    }
}

int main(void){
    int a[7][7] = {
        {0,29,INF,INF,INF,10,INF},
        {29,0,16,INF,INF,INF,15},
        {INF,16,0,12,INF,INF,INF},
        {INF,INF,12,0,22,INF,18},
        {INF,INF,INF,22,0,27,25},
        {10,INF,INF,INF,27,0,INF},
        {INF,15,INF,18,25,INF,0}
    };

    GraphType *g = (GraphType*)malloc(sizeof(GraphType));
    g->n = 7;
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            g->weight[i][j] = a[i][j];
        }
    }

    prim(g, 0);

    return 0;
}