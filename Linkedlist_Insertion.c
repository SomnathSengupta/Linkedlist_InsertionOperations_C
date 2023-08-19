#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    };
void list_traversial(struct Node* ptr) // It will Print the linkedlist elements.
{
    while (ptr != NULL){
        printf("Element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}
struct Node* insertAtBeginning(struct Node*Head, int data) // It will create a new node and it will add it at the beginning.
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = Head;

    return ptr;
}
struct Node* insertAtSpecifiedIndex(struct Node*Head, int data, int index) // It will create a new node and it will add it at Specified Index.
{
  struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
  struct Node* p = Head;
  int i = 0;
  while ( i != index -1){
    p = p -> next;
    i++;
  } 
  ptr -> next = p -> next;
  p -> next = ptr;
  ptr -> data = data;

  return Head; 
}
struct Node* insertAtLast(struct Node* Head, int data) // It will create a new node and it will add it at the Last.
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = Head;
    while (p -> next != NULL){
        p = p -> next;
    }
    p -> next = ptr;
    ptr -> next = NULL;
    ptr -> data = data;

    return Head;
}
int main()
{
    struct Node *Head, *second, *third; // Creation of Nodes.
    Head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    
    // Storing the data
    Head -> data = 8;
    second -> data = 7;
    third -> data = 9;

    // Linking Nodes.
     Head -> next = second;
    second -> next = third;
    third -> next = NULL;

    list_traversial(Head);
    printf("Now we are inserting one node at the beginning:\n");
    Head = insertAtBeginning(Head, 56);
    list_traversial(Head);
    
    printf("Now we are inserting one node at a specified index:\n");
    Head = insertAtSpecifiedIndex(Head, 65, 2);
    list_traversial(Head);

    printf("Now we are inserting one node at the last:\n");
    Head = insertAtLast(Head, 92);
    list_traversial(Head);

    return 0;
}