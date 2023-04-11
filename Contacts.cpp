#include <iostream>
using namespace std;

class ContactNode {
   public:
      ContactNode(string name, string phone) {
      contactName = name;
      contactPhoneNumber = phone;
      nextNodePtr = nullptr;
}

string GetName() const {
return contactName;
}

string GetPhoneNumber() const {
return contactPhoneNumber;
}

void InsertAfter(ContactNode* nodePtr) {
ContactNode* tmpNext = nullptr;

  tmpNext = this->nextNodePtr;      
  this->nextNodePtr = nodePtr;      
  nodePtr->nextNodePtr = tmpNext;
}

ContactNode* GetNext() const {
return this->nextNodePtr;
}

void PrintContactNode() const {
cout << "Name: " << contactName << endl;
cout << "Phone number: " << contactPhoneNumber << endl;
}

   private:
      string contactName;
      string contactPhoneNumber;
      ContactNode* nextNodePtr;
};

int main() {
   
   ContactNode* headPtr = nullptr;
   ContactNode* currPtr = nullptr;
   ContactNode* lastPtr = nullptr;
   
   string name, phone;
   
   // Read input for first contact
   getline(cin, name);
   getline(cin, phone);
   
   // Create first node and set as head
   headPtr = new ContactNode(name, phone);
   lastPtr = headPtr;
   
   // Read input for second contact
   getline(cin, name);
   getline(cin, phone);
   
   // Create second node and insert after first node
   currPtr = new ContactNode(name, phone);
   lastPtr->InsertAfter(currPtr);
   lastPtr = currPtr;
   
   // Read input for third contact
   getline(cin, name);
   getline(cin, phone);
   
   // Create third node and insert after second node
   currPtr = new ContactNode(name, phone);
   lastPtr->InsertAfter(currPtr);
   lastPtr = currPtr;
   
   // Output each contact
   currPtr = headPtr;
   for (int i = 1; currPtr != nullptr; ++i) {
   cout << "Person " << i << ": " << currPtr->GetName() << ", " << currPtr->GetPhoneNumber() << endl;
   currPtr = currPtr->GetNext();
   }
   
   // Output linked list
   cout << endl << "CONTACT LIST" << endl;
   currPtr = headPtr;
   while (currPtr != nullptr) {
      currPtr->PrintContactNode();
      currPtr = currPtr->GetNext();
      cout << endl;
   }
   
   // Free memory
   currPtr = headPtr;
   while (currPtr != nullptr) {
   headPtr = currPtr->GetNext();
   delete currPtr;
   currPtr = headPtr;
   }

return 0;
}