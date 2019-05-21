#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _employee{
  char name[32];
  unsigned char age;
} Employee;

typedef struct _node{
  void *data;
  struct _node *next;
} Node;

typedef struct _linkedlist{
  Node *head;
  Node *tail;
  Node *current;
} Linkedlist;


Employee *makeEmployee(char *name, unsigned char age){
  Employee *employee = (Employee*) malloc(sizeof(Employee));
  strcpy(employee->name, name);
  employee->age = age;
  return employee;
}

void initializeLinkedList(Linkedlist *list){
  list->head = NULL;
  list->tail = NULL;
  list->current = NULL;
}

void addHead(Linkedlist *list, void *data){
  Node *node = (Node*) malloc(sizeof(Node));
  node->data = data;
  if (list->head == NULL){
    list->tail = node;
    node->next = NULL;
  } else {
    node->next = list->head;
  }
  list->head = node;
}

void printList(Linkedlist *linkedlist){
  Node *current = linkedlist->head;
  while(current != NULL){
    Employee *current_employee = current->data;
    printf("Name : %s, Age : %d\n", current_employee->name, current_employee->age);
    current = current->next;
  }
}

int main(){
  void printList(Linkedlist*);
  void initializeLinkedList(Linkedlist*);
  void addHead(Linkedlist*, void*);
  // void addTail(Linkedlist*, void*);
  // void delete(Linkedlist*, void*);
  // void getNode
  Employee *makeEmployee(char*, unsigned char);

  Linkedlist linkedlist;
  initializeLinkedList(&linkedlist);

  addHead(&linkedlist, makeEmployee("Dave", 34));
  addHead(&linkedlist, makeEmployee("Karl", 46));
  addHead(&linkedlist, makeEmployee("Amy", 28));

  printList(&linkedlist);

  return 0;
}
