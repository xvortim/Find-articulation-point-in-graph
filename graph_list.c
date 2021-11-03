#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fun_list.h"

int main() {
    int numV, numE;
    int from, to;

    printf("Enter the number of vertices: ");
        scanf("%d", &numV);
        char strings[numV][30];
        Graph *graph = new_graph( numV );

    printf("Enter the number of edges: ");
        scanf("%d", &numE);

    printf("Enter the vertices:\n");
        char string[30];
        for( int i = 0 ; i < numV ; i++ ) {
            scanf("%s", string );
            strcpy( strings[i], string );
        }

    printStringsIndex( strings, numV );

    printf("Enter the edges with a number from the list:\n");
        for( int i = 0 ; i < numE ; i++ ) {
            scanf("%d %d", &from, &to );
            new_edge( graph, from, to );
        }

    // print( graph );
    find_AP( graph, strings );

    return 0;
}
