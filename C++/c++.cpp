#include <iostream>
using namespace std;

class Node
{
public:
    int element;
    Node *next;
    Node *prev;   // added for doubly

    Node()
    {
        element = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int data)
    {
        element = data;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertFirst(int elem)
    {
        Node *temp = new Node(elem);

        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void insertLast(int elem)
    {
        Node *temp = new Node(elem);

        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void insertAt(int pos, int elem)
    {
        if (pos < 0 || pos > size)
        {
            cout << "Invalid Index" << endl;
            return;
        }

        if (pos == 0)
            insertFirst(elem);
        else if (pos == size)
            insertLast(elem);
        else
        {
            Node *temp = new Node(elem);
            Node *current = head;

            for (int i = 0; i < pos - 1; i++)
                current = current->next;

            temp->next = current->next;
            temp->prev = current;
            current->next->prev = temp;
            current->next = temp;

            size++;
        }
    }

    void deleteFirst()
    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
            return;
        }

        Node *temp = head;

        if (size == 1)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
        size--;
    }

    void deleteLast()
    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
            return;
        }

        if (size == 1)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
        size--;
    }

    void deleteAt(int posion)
    {
        if (posion < 0 || posion >= size)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        if (posion == 0)
        {
            deleteFirst();
            return;
        }

        if (posion == size - 1)
        {
            deleteLast();
            return;
        }

        Node *current = head;
        for (int i = 0; i < posion; i++)
            current = current->next;

        current->prev->next = current->next;
        current->next->prev = current->prev;

        delete current;
        size--;
    }

    void printList()
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->element << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    DoublyLinkedList list;

    list.insertLast(10);
    list.insertLast(20);
    list.insertAt(1, 15);
    list.insertAt(2, 25);

    list.printList();

    list.deleteFirst();
    list.deleteLast();

    list.printList();

    list.deleteAt(1);
    list.printList();

    return 0;
}
