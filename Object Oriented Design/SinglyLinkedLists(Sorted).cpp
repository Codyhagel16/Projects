//This code is designed to define and implement sorted singly linked lists.//

#include<iostream>
using namespace std;

struct Cody //declares a structure 
{
    string name; //declares a string value
    int age; //declares an integer value
    double fees; //declares a double value

    Cody() //declares a constructor
    {
        name = " "; //stes value of string
        age = 0; //stes value of age
        fees = 0; //stes value for fees
    }
    Cody(string n, int a, double f) 
    {
        name = n; //sets it so name can equal n
        age = a; //sets it so age equals a
        fees = f; //stes it so f equals f
    }

};

struct Node //declares a node structure
{
    Cody datum; //sets cody struct to be referred to as datum
    Node* pNext; //declares node 

    Node()
    {
        datum.name = " "; //sets the datum name value
        datum.age = 0; //stes datum age value
        datum.fees = 0; // sets datum fees value
        pNext = nullptr; //sets a value to go to the next node 
    }

    Node(Cody cody, Node* link)
    {
        datum = cody; //sets datum to equal cody
        pNext = link; //links the pointer next value
    }

};

class SortedLinkedList //declares a class
{
private: //declares private members within class
    Node* pHead; //declares a pointer node for the head of the program

public: //declares public member within class
    SortedLinkedList()
    {
        pHead = nullptr;
    }

    SortedLinkedList(Node* link) //declares function to link the head pointer node
    {
        pHead = link;
    }

    bool isEmpty()
    {
        return (pHead == nullptr);
    }

    void CreateList() //declares a function to create list
    {
      cout << "Enter the number of nodes that you want to have entered in this list" << endl; //prompts user for number of nodes they want

      int numberOfNodes; //declares integer value
      cin >> numberOfNodes; //takes in teh number of nodes the user wants to add

      Node* pCurrentNode; //sets pointer for current node
      Node* pNewCode; //sets pointer for new inputted code 

      cout << "Enter the value to store in the 0th node: " << endl; //prompts user for code to be inputted into the node
      Cody cody0; //stes value to store input within new node

      string inputName; //declares string value for inputted name
      int inputAge; //declares int value for inputted integer 
      double inputFees; //declares oduble value for inputted double

      cin >> inputName; //stores inputed string
      cin >> inputAge; //stores inputted integer
      cin >> inputFees; //stores inputted double

      cody0.name = inputName; //sets values of string
      cody0.age = inputAge; //sets value of age
      cody0.fees = inputFees; //stes value of double

      pNewCode = new Node(cody0, nullptr);
      pHead = pNewCode; //stes the head of the node to be able to be the newly inputted code
      pCurrentNode = pHead; //sets new head node

      int count = 0; //sets an intger named count to 0

      while(count != (numberOfNodes-1)) //declares a while statement that will stop when the counter gets to 0
        {
          cout << "Enter the name and salary to store in the " << count+1 << " node" << endl; //prompts user for input on their desired amount of nodes

          cin >> inputName; // stores the string value
          cin >> inputAge; //stores integer value
          cin >> inputFees; //stores double value

          cody0.name = inputName; //stes string value
          cody0.age = inputAge; //sets integer value
          cody0.fees = inputFees; //sets double value

          pNewCode = new Node(cody0, nullptr);
          pCurrentNode->pNext = pNewCode;
          pCurrentNode = pNewCode; //stes possibilty that new input can be the head node
          count++; //end of while loop to add to the counter 
        }

    }

    void printLinkedList() //declares function to print list
    {
        cout << "Linked List: " << endl;
        for(const Node* p = pHead; p!=nullptr; p = p->pNext) //declares for loop to print out all node values
        {
          cout << p->datum.name << " " << p->datum.age << " " << p->datum.fees << endl; //prints out all stored values within a node
        }
        cout << endl;

    }

    Node* searchLinkedList(Node* pHead, Cody cody) //declares function to search linkedlist
    {

        Node* pPrevious  = nullptr; //pointer node to go to previous node
        Node* pCurrent = pHead; //pointer node to go to head node

        while (pCurrent != nullptr && pCurrent->datum.name<cody.name) //declares while loop to search for inputted name until found
        {
            pPrevious = pCurrent;
            pCurrent =pCurrent->pNext;
        }
        return pPrevious; //returns the found node
    }

    void insertNode(Cody cody) //declares function to insert node 
    {
        Node* pPrevious = searchLinkedList(pHead, cody); 

        Node* pCurrent = new Node;
        pCurrent->datum  = cody;

        if(pPrevious == nullptr) //declares if statement to insert node into correct area
        {
            pCurrent->pNext = pHead;
            pHead = pCurrent;
        }

        else
        {
            pCurrent->pNext = pPrevious->pNext;
            pPrevious->pNext = pCurrent;
        }


    }

    void removeNode(Cody cody) //declares function to remove node
    {
        Node* pPrevious = searchLinkedList(pHead, cody);

        if(pPrevious != nullptr) //declares if statement to remove proper node
        {
            if(pPrevious->pNext == nullptr
               ||pPrevious->pNext->datum.name!=cody.name)
               return;

            Node* pToRemove = pPrevious->pNext;
            pPrevious->pNext = pToRemove->pNext;
            delete pToRemove;
        }

        else
        {
            if(pHead == nullptr || pHead->datum.name != cody.name)
                return;
            Node* pToRemove = pHead;
            pHead = pToRemove->pNext;
            delete pToRemove;
        }
    }

    bool isMember(Cody cody)
    {
        Node* pPrevious = searchLinkedList(pHead, cody);

        if(pPrevious!=nullptr)
        {
            return pPrevious->pNext !=nullptr
            && pPrevious->pNext->datum.fees == cody.fees
            && pPrevious->pNext->datum.age == cody.age
            && pPrevious->pNext->datum.name == cody.name;
        }
        else
        {
            return pHead != nullptr
            && pHead->datum.fees == cody.fees
            && pHead->datum.age == cody.age
            && pHead->datum.name == cody.name;

        }
    }

    int numberOfMembers() //declares function to find number of members
    {
        int length = 0;
        for(const Node* p = pHead; p!= nullptr; p=p->pNext)
        {
            length++;
        }
        return length;
    }


};

int main() //declares main function
{
    SortedLinkedList list1; //declares list1

    list1.CreateList(); //creates list using function

    list1.printLinkedList(); //prints list using function
    cout<<endl;

    Cody cody1("Logan", 20, 200.40); //hardcodes 1st node
    Cody cody2("Ryan", 23, 06.43); //hardcodes second node
    Cody cody3("Micheal", 29, 200406438); //hardcodes 3rd node



    list1.insertNode(cody1); //insrets new node
    list1.insertNode(cody2); //inserts second new node
    list1.insertNode(cody3); //inserts third new node

    list1.printLinkedList(); //prints linkedlist
    cout << endl;
    cout << "The number of member of the list: " << list1.numberOfMembers()<<endl; //displays number of members within list using function
    cout << endl;

    cout << list1.isMember(cody2)<<endl; 

    list1.removeNode(cody2);


    list1.printLinkedList();
    cout << endl;
     cout << "The number of member of the list: " << list1.numberOfMembers()<<endl;

    cout << endl;
    cout << list1.isMember(cody2) << endl;


    return 0;

}