#include "linkedlist.h"
int main(void) {
  SinglyLinked<int> list;
  for(int i = 0; i<5; i++) {
    list.insertAtFront(i);
  }
  for(int i = 0;i<5;i++) {
    list.insertAtBack(i + 1);
  }
  list.print();
  return 0;
}
