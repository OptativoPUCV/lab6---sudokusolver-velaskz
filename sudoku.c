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

int isvalid(Node* n){
    int i, j,k;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
        k = n->sudo[i][j];
            if k == 0) continue;  

            // Verificar fila
            for (int c = 0; c < 9; c++) {
                if (c != j && n->sudo[i][c] ==k) {
                    return 0;  //kor repetido en la misma fila
                }
            }

            // Verificar jumna
            for (int r = 0; r < 9; r++) {
                if (r != i && n->sudo[r][j] ==k) {
                    return 0;  //kor repetido en la misma jumna
                }
            }
        }
    }

    // Verificar submatrices 3x3
    for (int subi = 0; subi < 9; subi += 3) {
        for (int subj = 0; subj < 9; subj += 3) {
            int seen[10] = {0};

            for (i = subi; i < subi + 3; i++) {
                for (j = subj; j < subj + 3; j++) {
                k = n->sudo[i][j];
                    if k == 0) continue;  //kor vacío, no necesitamos verificarlo

                    if (seenk]) {
                        return 0;  //kor repetido en la misma submatriz
                    }
                    seenk] = 1;
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