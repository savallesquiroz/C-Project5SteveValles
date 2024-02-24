// Provided by:   ____________(Steve Valles Quiroz)__________
// Email Address: ____________(savallesquiroz@mail.fhsu.edu)________
//2023F_CSCI221_VB Computer Science II
//Project 5

#include "CSCI361Proj5.h"
#include <cstddef> // size_t
#include <cassert> // assert()
using namespace FHSULINKEDLIST;

#include "CSCI361Proj5.h"
#include <cassert> // assert()

namespace FHSULINKEDLIST
//   size_t list_length(Node* head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The value returned is the number of nodes in the linked
//     list. The list itself is unaltered.
{
    size_t list_length(const Node* head_ptr) {
        size_t length = 0; //Initialize to 0
        while (head_ptr != nullptr) { //Go through all nodes in the list.
            length++;
            head_ptr = head_ptr->link;//Point to next node.
        }
        return length;//Return the number of nodes
    }
  //   void list_head_insert(Node*& head_ptr, const Node::Item& entry)
  //     Precondition: head_ptr is the head pointer of a linked list.
  //     Postcondition: A new node containing the given entry has been added at
  //     the head of the linked list; head_ptr now points to the head of the new,
  //     longer linked list.
    void list_head_insert(Node*& head_ptr, const Node::Item& entry) {
        Node* new_node = new Node;//New node created
        new_node->data = entry;//Set the data of the new node to the entry
        new_node->link = head_ptr;//Set the link of the new node to the head
        head_ptr = new_node;//Set the head pointer to the new node
    }
  //   void list_insert(Node* previous_ptr, const Node::Item& entry)
  //     Precondition: previous_ptr points to a node in a linked list.
  //     Postcondition: A new node containing the given entry has been added
  //     after the node that previous_ptr points to.
    void list_insert(Node* previous_ptr, const Node::Item& entry) {
        assert(previous_ptr != nullptr);//Check if node is not null
        Node* new_node = new Node;//New node created
        new_node->data = entry;//Set the data of the new node to the entry
        new_node->link = previous_ptr->link;//Set the link of the new node to the link of the previous node
        previous_ptr->link = new_node;//Set the link of the previous node to the new node
    }
  //   Node* list_search(Node* head_ptr, const Node::Item& target)
  //     Precondition: head_ptr is the head pointer of a linked list.
  //     Postcondition: The pointer returned points to the first node containing
  //     the specified target in its data member. If there is no such node, the
  //     null pointer is returned. The list itself is unaltered.
    Node* list_search(Node* head_ptr, const Node::Item& target) {
        while (head_ptr != nullptr && head_ptr->data != target)//Go through all nodes in the list.
            head_ptr = head_ptr->link;//Point to next node.
        return head_ptr;//Return the targetted node
    }
  //   Node* list_locate(Node* head_ptr, size_t position)
  //     Precondition: head_ptr is the head pointer of a linked list, and
  //     position > 0.
  //     Postcondition: The pointer returned points to the node at the specified
  //     position in the list. (The head node is position 1, the next node is
  //     position 2, and so on). If there is no such position, then the null
  //     pointer is returned. The list itself is unaltered.
    Node* list_locate(Node* head_ptr, size_t position) {
        assert(position > 0);//Check if position is greater than 0
        while (--position > 0 && head_ptr != nullptr)//Go through all nodes in the list.
            head_ptr = head_ptr->link;
        return head_ptr;//Return the node at the position
    }
  //   void list_head_remove(Node*& head_ptr)
  //     Precondition: head_ptr is the head pointer of a linked list, with at
  //     least one node.
  //     Postcondition: The head node has been removed and returned to the heap;
  //     head_ptr is now the head pointer of the new, shorter linked list.
    void list_head_remove(Node*& head_ptr) {
        assert(head_ptr != nullptr);//Check if head_ptr is not null
        Node* remove_ptr = head_ptr;//Set the remove_ptr to the head_ptr
        head_ptr = head_ptr->link;//Set the head_ptr to the next node
        delete remove_ptr;//Delete the remove_ptr
    }
  //   void list_remove(Node* previous_ptr)
  //     Precondition: previous_ptr points to a node in a linked list, and this
  //     is not the tail node of the list.
  //     Postcondition: The node after previous_ptr has been removed from the
  //     linked list.
    void list_remove(Node* previous_ptr) {
        assert(previous_ptr != nullptr && previous_ptr->link != nullptr);//Check if previous_ptr and next node is not null
        Node* remove_ptr = previous_ptr->link;//Set the remove_ptr to the next node
        previous_ptr->link = remove_ptr->link;//Set the previous_ptr to the next node
        delete remove_ptr;//Delete the remove_ptr
    }
  //   void list_clear(Node*& head_ptr)
  //     Precondition: head_ptr is the head pointer of a linked list.
  //     Postcondition: All nodes of the list have been returned to the heap,
  //     and the head_ptr is now NULL
    void list_clear(Node*& head_ptr) {
        while (head_ptr != nullptr)//Go through all nodes in the list.
            list_head_remove(head_ptr);//Remove the head node
    }
  //   void list_copy(Node* source_ptr, Node*& head_ptr)
  //     Precondition: source_ptr is the head pointer of a linked list.
  //     Postcondition: head_ptr is the head pointer for
  //     a new list that contains the same items as the list pointed to by
  void list_copy(Node* source_ptr, Node*& head_ptr) {
    head_ptr = nullptr;//Set the head_ptr to null
    Node** tail_ptr = &head_ptr;//Set the tail_ptr to the head_ptr

    while (source_ptr != nullptr) {//Go through all nodes in the list.
        *tail_ptr = new Node;//Create a new node
        (*tail_ptr)->data = source_ptr->data;//Data for new node
        (*tail_ptr)->link = nullptr;//Set the next node to null

        tail_ptr = &((*tail_ptr)->link);//Set tail_ptr to the next node
        source_ptr = source_ptr->link;//Set source_ptr to the next node
    }
}
  //   size_t list_occurrences(Node* head_ptr, const Node::Item& target)
  //     Precondition: head_ptr is the head pointer of a linked list.
  //     Postcondition: The return value is the count of the number of times
  //     target appears as the data portion of a node on the linked list.
  //     The linked list itself is unchanged.
    size_t list_occurrences(Node* headPtr, const Node::Item& target) {
	    size_t count = 0;

	    for (; headPtr != nullptr; headPtr = headPtr->link)//Go through all nodes in the list.
		    if (headPtr->data == target)//Check if the data is the target
			    count++;

	    return count;//Return the count
    }
  //   void list_tail_attach(Node*& head_ptr, const Node::Item& entry)
  //     Precondition: head_ptr is the head pointer of a linked list.
  //     Postcondition: A new node containing the given entry has been added at
  //     the tail of the linked list; if this happens to be the first node of
  //     the linked list, then head_ptr now points to this node (otherwise
  //     head_ptr is unchanged)
    void list_tail_attach(Node*& headPtr, const Node::Item& entry) {
	    Node *newNode = new Node{entry, nullptr};//Create a new node
	    if (headPtr == nullptr)//If list is empty set head_ptr to new node
		    headPtr = newNode; 
	    else {//Otherwise go to the end of the list
		    Node *cursorNode = headPtr; //Start at the head node
		    while (cursorNode->link != nullptr)
			    cursorNode = cursorNode->link; 
		    cursorNode->link = newNode;//Set the next node to the new node
	    }
    }
  //   void list_tail_remove(Node*& head_ptr)
  //     Precondition: head_ptr is the head pointer of a linked list, with at
  //     least one node.
  //     Postcondition: The tail node has been removed and returned to the heap;
  //     if the list is now empty, then head_ptr is null; otherwise head_ptr
  //     is unchanged.
    void list_tail_remove(Node*& headPtr) {
	    assert(headPtr != nullptr); //List not empty
	    if (headPtr->link == nullptr) {//If there is only one node, delete and point to null
		    delete headPtr;
		    headPtr = nullptr;
	    } 
      else {//Otherwise go to the end of the list and delete last node
		    Node *cursorNode = headPtr; 
		    while (cursorNode->link->link != nullptr)
			    cursorNode = cursorNode->link; 
		    delete cursorNode->link;
		    cursorNode->link = nullptr; 
	    }
    }
  //   Node* list_copy_front(Node* source_ptr, size_t n)
  //     Precondition: source_ptr is the head pointer of a linked list
  //     Postcondition: The value returned is the head pointer for
  //     a new list that contains copies of the first n nodes from the list
  //     that source_ptr points to. If there less than n nodes in source list,
  //     just copy all nodes and done
    Node* list_copy_front(Node* source_ptr, size_t n) {
    if (source_ptr == nullptr || n == 0)//If the list is empty or n is 0 return null
        return nullptr;

    Node* copy_head_ptr = new Node;//Create a new node
    copy_head_ptr->data = source_ptr->data;//Copy the data
    copy_head_ptr->link = nullptr;//Set the next node to null

    Node* copy_tail_ptr = copy_head_ptr;//Create a new node
    source_ptr = source_ptr->link;//Move to the next node
    --n;//Decrement n

    while (source_ptr != nullptr && n-- > 0) {//While there are nodes to copy and n is greater than 0
        Node* new_node = new Node;
        new_node->data = source_ptr->data;
        new_node->link = nullptr;

        copy_tail_ptr->link = new_node;
        copy_tail_ptr = new_node;

        source_ptr = source_ptr->link;
    }

    return copy_head_ptr;//Return the head pointer of the new list
  }


}

