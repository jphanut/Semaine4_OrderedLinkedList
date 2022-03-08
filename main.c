#include <stdio.h>
#include <stdlib.h>

int compare(char a, char b) {
    return a-b;
}

typedef struct node{
    char val;
    struct node *next;
} node_t;

/*
* @value: value to be inserted. If the value is already in the list, no element is added and the list is not modified
* @fun: comparison function which defines the order relationship of the list
* @head: first node of the list, head != NULL
* @return: 0 if success, -1 otherwise
*/
int insert(node_t **head, char val, int (*cmp)(char,char)) {
    node_t * first = * head;
    node_t * current = first;
    node_t * previous = NULL;
    while (current != NULL && cmp(current->val, val)<0) {
        previous = current;
        current = current->next;
    }
    if (current != NULL && cmp(current->val, val)==0 ) return 0;
    node_t * newnode = (node_t *)malloc(sizeof(node_t ));
    if ( newnode == NULL) return -1;
    newnode->val = val;
    newnode->next = current != NULL? current: NULL;
    if ( previous != NULL ) previous->next = newnode;
    else {
       * head = newnode;
    }
    return 0;
}

void displaylist(node_t **head) {
    node_t * first = * head;
    printf("Display all elements in the list\n");
    printf("--------------------------------\n");
    for (node_t * current = first; current != NULL; current = current->next ) {
        printf("Element in list %d\n", current->val);
    }
    printf("\n");
}

int main()
{
    int rc = 0;
    printf("Exercise Ordered Linked List\n");
    printf("****************************\n\n");

    node_t * head = (node_t *)malloc(sizeof(node_t ));
    printf("ICreation of the list with 1 element 0\n");
    printf("----------------------------------------\n");
    if ( head == NULL ) printf("ERROR when allocating struct node\n");
    else printf("Operation succeeded\n");
    head->val = 0;
    head->next = NULL;
    displaylist(&head);

    printf("Insert element -1 at the top of the list\n");
    printf("----------------------------------------\n");
    rc = insert(&head, -1, &compare);
    if ( rc != 0 ) printf("ERROR when allocating struct node\n");
    else printf("Operation succeeded\n");
    displaylist(&head);

    printf("Insert element 2 at the tail of the list\n");
    printf("----------------------------------------\n");
    rc = insert(&head, 2, &compare);
    if ( rc != 0 ) printf("ERROR when allocating struct node\n");
    else printf("Operation succeeded\n");
    displaylist(&head);

    printf("Insert element 1 inside the list\n");
    printf("--------------------------------\n");
    rc = insert(&head, 1, &compare);
    if ( rc != 0 ) printf("ERROR when allocating struct node\n");
    else printf("Operation succeeded\n");
    displaylist(&head);

    printf("Insert element 1 already existing the list\n");
    printf("------------------------------------------\n");
    rc = insert(&head, 1, &compare);
    if ( rc != 0 ) printf("ERROR when allocating struct node\n");
    else printf("Operation succeeded\n");
    displaylist(&head);

    return 0;
}
