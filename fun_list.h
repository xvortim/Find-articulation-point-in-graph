/* Code inspired by GeeksforGeeks */

#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex {
    int key;
    struct Vertex *next;
}   Vertex;

typedef struct {
    struct Vertex *head;
} Link;

typedef struct {
    int V;
    Link *arr;
} Graph;

Vertex* new_vertex( int key ) {
    Vertex *new_node = ( Vertex* )malloc( sizeof(Vertex) );
    new_node->key = key;
    new_node->next = NULL;

    return new_node;
}

Graph* new_graph( int V ) {
    Graph *graph = ( Graph * )malloc(sizeof( Graph ) );

    graph->V = V;
    graph->arr = ( Link* )malloc( V * sizeof( Link ) );

    for( int i = 0; i < V; ++i )
        graph->arr[i].head = NULL;

    return graph;
}

void new_edge( Graph *graph, int first, int last ) {
    Vertex *new_node = new_vertex( last );
    new_node->next = graph->arr[first].head;
    graph->arr[first].head = new_node;

    new_node = new_vertex( first );
    new_node->next = graph->arr[last].head;
    graph->arr[last].head = new_node;
}

void print( Graph *graph ) {
    printf("Printed graph:\n");
    for( int i = 0; i < graph->V; i++ ) {
        Vertex *temp = graph->arr[i].head;
        printf("%d", i );
        while( temp ) {
            printf(" -> %d", temp->key );
            temp = temp->next;
        }
        printf("\n");
    }
}

int min( int a, int b ) {
    return ( a < b ? a : b );
}

void AP_help( Graph *g, int node, int *visited, int *des, int *parent, int *low, int *ap ) {
    static int time = 0;
    int children = 0;

    Vertex *temp = g->arr[node].head;
    visited[node] = 1;

    time++;
    des[node] = low[node] = time;

    while( temp )
    {
        if( !visited[temp->key] )
        {
            children++;
            parent[temp->key] = node;
            AP_help( g, temp->key, visited, des, parent, low, ap );

            low[node] = min(low[node],low[temp->key]);

            if( parent[node] == -1 && children > 1 )
                ap[node] = 1;

            if( parent[node]!= -1 && des[node] <= low[temp->key] )
                ap[node] = 1;
        }
        else if( temp->key != parent[node] )
        {
            low[node] = min( low[node] , des[temp->key] );
        }
        temp = temp->next;
    }
}

void printStringsIndex( char strings[][30], int numV ) {
    printf("\n====================\n");
    for( int i = 0 ; i < numV ; i++ )
        printf("%d: %s\n", i, strings[i] );
    printf("====================\n");
}

void find_AP( Graph *g, char strings[][30] ) {
    int i;

    int *visited = ( int* )calloc( g->V, sizeof( int ) );
    int *ap = ( int* )calloc( g->V, sizeof( int ) );
    int *des = ( int* )malloc( sizeof( int ) * g->V );
    int *parent = ( int* )malloc( sizeof( int ) * g->V);
    int *low = ( int* )malloc( sizeof( int ) * g->V);

    for( i = 0 ; i < g->V ; i++ )
        parent[i] = -1;

    for( i = 0 ; i < g->V ; i++ )
        if( !visited[i] )
            AP_help(g, i, visited, des, parent, low, ap);

    int con = 0;
    printf("\nArticulation point at: \n");
    for( i = 0 ; i < g->V ; i++ ){
        if( ap[i] == 1 ) {
            con = 1;
            printf("%s\n", strings[i] );
        }
    }
    if( !con )
        printf("\nNo Articulation point found.");
}




