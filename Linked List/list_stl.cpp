#include<iostream>
#include<list>
using namespace std;

// To print Linked List, we use iterators.
void printList(list<int> ll){
    // Iterators:
    list<int>::iterator itr;   // creates an iterator
    for(itr = ll.begin(); itr != ll.end(); itr++){
        cout << *(itr) << " -> ";
    } cout << "NULL\n" ;
}

int main(){
    list<int> ll;  // creates ll with integer values

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(5);
    printList(ll);

    //list.size(): return no. of nodes in ll
    cout << "Size of Linked List: " << ll.size() << endl;

    // list.front() & list.back(): returns value of head and tail resp.
    cout << "Head of Linked List: " << ll.front() << endl;
    cout << "Tail of Linked List: " << ll.back() << endl;

    // list.pop_front() & list.pop_back(): pops from front & back Nodes resp.
    ll.pop_front();
    ll.pop_back();
    printList(ll);

    return 0;
}