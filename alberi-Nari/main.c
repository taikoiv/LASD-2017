#include <stdio.h>
#include <stdlib.h>
#include "ntree.h"
#include "ntree.c"
#include "code.h"
#include "code.c"

#include "ntee_arr.h"
#include "ntee_arr.c"

int main(){
    t_node *root = NULL, *tmp = NULL;
    t_node_a **arr = NULL, **tmp_a = NULL;
    int choise = 0, flag = 0, i=0;

    printf("Quale struttura dati vuoi che sia riempita?\n1)Alberi come liste\n2)Alberi come array\n: ");
    scanf("%d", &choise);

    printf("Quanti nodi vuoi inserire nell'albero? ");
    scanf("%d", &i);
    if(choise == 1){ //riempire le liste
        root = build_ntree(i);
        flag = 1;
    } else{
        arr = build_ntree_a(i);
        flag = 0;
    }

    do{
        printf("\t\tMENU'\n1)Riversa l'albero nell'altra struttura dati\n2)Ricerca un nodo\n3)Aggiungi un nodo\n4)Elimina un nodo\n5)Stampa albero\n6)Exit\n: ");
        scanf("%d", &choise);
        switch(choise){
            case 1:
                //change_structure(root, arr, flag);
                if(flag)
                    flag = 0;
                else
                    flag = 1;
                break;
            case 2:
                printf("Quale nodo vuoi cercare? ");
                scanf("%d", &i);
                if(flag){
                    tmp = search_ntree(root, i);
                    if(tmp)
                        printf("Nodo trovato!\n");
                    else
                        printf("Nodo NON trovato!\n");
                }
                else{
                    tmp_a = search_ntree_a(arr, i);
                    if(tmp_a)
                        printf("Nodo trovato!\n");
                    else
                        printf("Nodo NON trovato!\n");
                }

                break;
            case 3:
                printf("Inserisci valore: ");
                scanf("%d", &i);
                if(flag){
                    root = insert_node(root, i);
                    if(root)
                        printf("Nodo inserito correttamente!\n");
                }else{
                    arr = insert_node_a(arr, i);
                    if(arr)
                        printf("Nodo inserito correttamente!\n");
                }
                break;
            case 4:
                printf("Inserisci valore da eliminare: ");
                scanf("%d", &i);
                if(flag){
                    root = delete_node(root, i);
                }else{
                    //arr = delete_node_a(arr, i);
                }
                break;
            case 5:
                if(flag){
                    printf("Albero:\n");
                    print_ntree(root);
                }
                else{
                    //print_ntree_a(arr);
                }
                break;
            case 6:
                printf("\n\nArrivederci!\n");
                break;
            default:
                printf("Comando non riconosciuto! Riprova.\n\n");
                break;
        }
    }while(choise != 6);

    return 0;
}
