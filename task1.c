#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct node_t{
    int value;
    struct node_t *next;
}node_t;

void add_node(node_t **head,node_t **tail, int data);
void print_node(node_t **node);
void delete(int data, node_t **node);
void swap(node_t **first, node_t **second);
void sort(node_t **node);

int main(void){
    int data;
    node_t *head = NULL;
    node_t *tail = NULL;
    for(int i = 0;i<7;i++){
        scanf("%d", &data);
        add_node(&head,&tail,data);
    }
    printf("the linked list: ");
    print_node(&head);
    swap(&head, &head->next);
    printf("\nswapping head and second node: ");
    print_node(&head);
    sort(&head);
    printf("\nthe sorted list: ");
    print_node(&head);
    printf("\nenter a node to delete: ");
    scanf("%d", &data);
    delete(data,&head);
    printf("the linked list: ");
    print_node(&head);
    
    return 0;
}

void delete(int data,node_t **node){
    node_t *temp_node = (node_t *) malloc(sizeof(node_t));
    temp_node = (*node);
    while(temp_node != NULL){
        if(temp_node->value == data){
            temp_node->value = temp_node->next->value;
            temp_node->next =  temp_node->next->next;
            temp_node = (*node);
            break;
        }
        temp_node = temp_node->next;
    }
}

void sort(node_t **node){
    node_t *temp_node = (node_t *) malloc(sizeof(node_t));
    node_t *sort_node = (node_t *) malloc(sizeof(node_t));
    temp_node = (*node);
    sort_node = (*node);
    while(temp_node != NULL){
        while(sort_node !=NULL){
            if(temp_node->value < sort_node->value){
                swap(&temp_node,&sort_node);
            }
            sort_node = sort_node->next;
        }
        sort_node =(*node);
        temp_node = temp_node->next;
    }
}

void swap(node_t **first,node_t **second){
    node_t *temp_node = (node_t *) malloc(sizeof(node_t));
    temp_node->value = (*first)->value;
    (*first)->value = (*second)->value;
    (*second)->value = temp_node->value;
}

void print_node(node_t **node){
    node_t *temp_node = (node_t *) malloc(sizeof(node_t));
    temp_node = (*node);
    while(temp_node != NULL){
        printf("%d ",temp_node->value);
        temp_node = temp_node->next;
    }
}

void add_node(node_t **head,node_t **tail, int data){
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->value = data;
    new_node->next = NULL;

    if((*head) == NULL){
        (*head) = new_node;
    } else {
        (*tail)->next = new_node;
    }
    (*tail) = new_node;

}