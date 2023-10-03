#include "LinkedList.hpp"

using namespace std;

// TODO
// Destructor
LinkedList::~LinkedList()
{
   //continue deleting until list is empty
   while(! removeAtLocation(0)){}
   cout<<"network deleted"<<endl;
}

// TODO
// Find a specific key and return a pointer to that node, else return NULL
// Given the key this function will find the node where the key is present
Node* LinkedList::findKey(int key) {
   Node* ptr = head;
   while (ptr != NULL && ptr->key != key)
   {
      ptr = ptr->next;
   }
   return ptr;
}

void LinkedList::insert(Node* prev, int newKey) {
  //Check if head is Null i.e list is empty
   if(head == NULL){
      head = new Node;
      head->key = newKey;
      head->next = NULL;
   }
   // if list is not empty, look for prev and append our node there
   else if(prev == NULL)
   {
      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = head;
      head = newNode;
   }
   else {
      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = prev->next;
      prev->next = newNode;
   }
}

// Print the keys in your list
void LinkedList::displayList() {
   Node* temp = head;

   if(temp == NULL){
      return;
   }

   while(temp->next != NULL){
       cout<< temp->key <<" -> ";
      temp = temp->next;
   }

   cout<<temp->key<<endl;
}

// TODO
// Delete node at a particular index
bool LinkedList::removeAtLocation(int n)
{
   bool isDeleted = false;
   Node* temp = nullptr;
   if(head == NULL){
      cout<< "List is empty"<<endl;
      return isDeleted;
   }

   // Special case to delete the head
   if (n == 0) {
      //just set temp to head, move head to one Node foreward and delte
      head = head->next;
      delete temp;
      temp = nullptr;
      isDeleted = true;
      return isDeleted;
   }

   Node *pres = head;
   Node *prev = NULL;

   //loop until finding desired position
   for(int i = 0 ; i < n; i++)
   {
      //check to see if list has n positions, if not, return false
      if(! pres)
      {
         cout << "N is larger than length of the list, delete failed!"<<endl;
         return isDeleted;
      }
      //iterate
      prev = pres;
      pres = pres->next;
      //once at desired location, perform deletion and return
      if(i == n)
      {
         temp = pres;   
         pres = pres->next;
         prev = pres;
         delete temp;
         temp = nullptr;
         isDeleted = true;
         return isDeleted;
      }
   }

   return isDeleted;
}