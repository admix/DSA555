//Linked list implementation
#include <iostream>
using namespace std;

template <class TYPE>
struct Node {
  TYPE data_;
  Node<TYPE>* next_;

  Node(const TYPE& data, Node<TYPE>* n = NULL) {
    data_ = data;
    next_ = n;
  }

};

template <class TYPE>
class SinglyLinked {
  Node<TYPE>* first_;  //header node
  Node<TYPE>* last_;

public:
  Node<TYPE>* first() const {return first_;}
  SinglyLinked() {
    first_ = NULL;
  }
  //insert a node with data at start of linked list
  //return address of this new node
  Node<TYPE>* insertAtFront(const TYPE& data);

  //insert a node with data at back of linked list
  //return address of this new node
  Node<TYPE>* insertAtBack(const TYPE& data);

  //prints the linked list assuming that the TYPE can
  //be ouputed using standart << operator
  void print() const;

};

/*
** This function has a constant runtime. Doesn't matter how many nodes are in the linked list,
** this function has number of operations regardless of size of list
*/
template <class TYPE>
Node<TYPE>* SinglyLinked<TYPE>::insertAtFront(const TYPE& data) {
  Node<TYPE>* nn = new Node<TYPE>(data, first_);
  if(first_ == NULL) {
    last_ = nn;
  }
  first_ = nn;
  return nn;
}

/*
** This function has a linear runtime. We must loop through while loop 'n' times, where 'n' is the number of nodes in list
*/
template <class TYPE>
Node<TYPE>* SinglyLinked<TYPE>::insertAtBack(const TYPE& data) {
  Node<TYPE>* nn = new Node<TYPE>(data);

  //for(Node<TYPE>* curr = first_;curr->next_;curr=curr->next_); //curr points to the same Node as first points to
  if(first_) {
    Node<TYPE>* curr = first_; //same as above, but more readable
    while(curr->next_) {
      curr = curr->next_;
    }
    curr->next_ = nn; //last node points to a new one created Node
  }
  else {
    first_ = nn;
  }

  return nn;
}

template <class TYPE>
void SinglyLinked<TYPE>::print() const {
  Node<TYPE>* curr = first_;
  while(curr) {
    cout << curr->data_ << endl;
    curr = curr->next_;
  }
}
