```cpp
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class linkedList
{
private:
    /* data */
public:
   void linkedListTraversal(struct Node* ptr){
    while(ptr!=NULL){
        cout<<"Element : "<<ptr->data<<endl;
        ptr=ptr->next;
    }
   }
};


int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head= new struct Node;
    second= new struct Node;
    third= new struct Node;
    fourth= new struct Node;
    head->data=7;
    head->next=second;
    second->data=8;
    second->next=third;
    third->data=12;
    third->next=fourth;
    fourth->data=11;
    fourth->next=NULL;
    linkedList LL;
    LL.linkedListTraversal(head);
    delete head;
    delete second;
    delete third;
    delete fourth;
    return 0;
}
```
