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
    int fila, columna, valor;

    for (fila = 0; fila < 9; fila++){
        for (columna = 0; columna < 9; columna++) {
            valor = n->sudo[fila][columna];
            if (valor == 0) continue;  

            for (int c = 0; c < 9; c++){
                if (c != columna && n->sudo[fila][c] == valor) {
                    return 0; 
                }
            }

            for (int r = 0; r < 9; r++){
                if (r != fila && n->sudo[r][columna] == valor) {
                    return 0;  
                }
            }
        }
    }

    for (int subfila = 0; subfila < 9; subfila += 3){
        for (int subcol = 0; subcol < 9; subcol += 3){
            int seguimiento[10] = {0};

            for (fila = subfila; fila < subfila + 3; fila++){
                for (columna = subcol; columna < subcol + 3; columna++){
                    valor = n->sudo[fila][columna];
                    if (valor == 0){
                        continue;
                    }   

                    if (seguimiento[valor]) {
                        return 0;  
                    }
                    seguimiento[valor] = 1;
                }
            }
        }
    }

    return 1; 
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    size_t fila,columna,valor;

    for (fila = 0; fila < 9; fila++){
        for(columna = 0; columna < 9; columna++){
            if (n->sudo[fila][columna] == 0){
                for (valor = 0; valor < 9; valor++){
                    Node* nodo = copy(n);
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