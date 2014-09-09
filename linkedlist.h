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

  //remove a node from front
  Node<TYPE>* removeAtFront();

  //remove a node from back
  Node<TYPE>* removeAtBack();

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
** This function has a runtime O(1) ...constant
*/
template <class TYPE>
Node<TYPE>* SinglyLinked<TYPE>::insertAtBack(const TYPE& data) {
  Node<TYPE>* nn = new Node<TYPE>(data);

  //for(Node<TYPE>* curr = first_;curr->next_;curr=curr->next_); //curr points to the same Node as first points to

  if(first_ == NULL) {
    first_ = last_ = nn;
  }
  else {
    last_->next_ = nn;
    last_ = nn;
  }

  return nn;
}

//remove a node from front
template <class TYPE>
void removeAtFront() {
  if(first_) {
    Node<TYPE>* tmp = first_;
    first_ = first_->next_; //makes first_ points to the second node
    delete tmp;
  }
}

//remove a node from back
template <class TYPE>
void removeAtBack() {
  if(first_) {
    Node<TYPE>* curr = first_;
    Node<TYPE>* prev = NULL;
    while(curr->next_) {
      prev = curr;
      curr=curr->next_;
    }
    if(prev != NULL) {
      prev->next_ = NULL;
    }
    else {
      first_ = NULL;
    }
    delete curr;
  }
}

//prints Nodes
template <class TYPE>
void SinglyLinked<TYPE>::print() const {
  Node<TYPE>* curr = first_;
  while(curr) {
    cout << curr->data_ << endl;
    curr = curr->next_;
  }
}


//WHAT IS THE RUNTIME OF removes

//modify code to add last pointer to remove and calculate runtime with it
