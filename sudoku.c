#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
    int fila, columna, val;

    // Verificar filas y columnas
    for (fila = 0; fila < 9; fila++) {
        for (columna = 0; columna < 9; columna++) {
            val = n->sudo[fila][columna];
            if (val == 0) continue;  // Valor vacío, no necesitamos verificarlo

            // Verificar fila
            for (int c = 0; c < 9; c++) {
                if (c != columna && n->sudo[fila][c] == val) {
                    return 0;  // Valor repetido en la misma fila
                }
            }

            // Verificar columna
            for (int r = 0; r < 9; r++) {
                if (r != fila && n->sudo[r][columna] == val) {
                    return 0;  // Valor repetido en la misma columna
                }
            }
        }
    }

    // Verificar submatrices 3x3
    for (int subfila = 0; subfila < 9; subfila += 3) {
        for (int subcol = 0; subcol < 9; subcol += 3) {
            int seen[10] = {0};

            for (fila = subfila; fila < subfila + 3; fila++) {
                for (columna = subcol; columna < subcol + 3; columna++) {
                    val = n->sudo[fila][columna];
                    if (val == 0) continue;  // Valor vacío, no necesitamos verificarlo

                    if (seen[val]) {
                        return 0;  // Valor repetido en la misma submatriz
                    }
                    seen[val] = 1;
                }
            }
        }
    }

    return 1;  // El nodo es válido
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    size_t i,j,k;

    for (i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            if (n->sudo[i][j] == 0){
                for (k = 0; k < 9; k++){
                    
                }
            }
        }
    }
    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/