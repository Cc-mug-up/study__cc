#include <iostream>
using namespace std;
template <typename T>
class List
{
private:
    struct Node
    {
        Node *next;
        Node *prev;
        T data;
        Node(const T &newdata, Node *newnext = nullptr, Node *newprev = nullptr)
            : data(newdata), next(newnext), prev(newprev) {}
    };
    size_t size;
    Node *head;
    Node *tail;

public:
    List()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    ~List()
    {
        clear();
    }
    void clear()
    {
        Node *temp = nullptr;
        while (head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }
    void push_back(const T &val)
    {
        Node *newnode = new Node(val, nullptr, tail);
        if (tail != nullptr)
        {
            tail->next = newnode;
        }
        else
        {
            head = newnode;
        }
        tail = newnode;
        ++size;
    }
    void push_front(const T &val)
    {
        Node *newnode = new Node(val, head, nullptr);
        if (head != nullptr)
        {
            head->prev = newnode;
        }
        else
        {
            tail = newnode;
        }
        head = newnode;
        ++size;
    }
    void pop_back()
    {
        if (size > 0)
        {
            Node *newtail = tail->prev;
            delete tail;
            tail = newtail;
            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr;
            }
            --size;
        }
    }
    void pop_front()
    {
        if (size > 0)
        {
            Node *newhead = head->next;
            delete head;
            head = newhead;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
            --size;
        }
    }
    Node *getNode(const T &val)
    {
        Node *tem = head;
        while (tem != nullptr && tem->data != val)
        {
            tem = tem->next;
        }
        return tem;
    }
    T *find(const T &val)
    {
        Node *tem = getNode(val);
        if (tem == nullptr)
        {
            return nullptr;
        }
        return &tem->data;
    }
    void remove(const T &val)
    {
        Node *node = head;
        while (node != nullptr && node->data != val)
        {
            node = node->next;
        }
        if (node == nullptr)
        {
            return;
        }
        if (node != head && node != tail)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        else if (node == head && node == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else if (node == head)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        --size;
        delete node;
        node = nullptr;
    }
    void printElements()
    {
        Node *tem = head;
        while (tem)
        {
            std::cout << tem->data << " ";
            tem = tem->next;
        }
        std::cout << std::endl;
    }
    T &operator[](size_t index)
    {
        Node *tem = head;
        for (int i = 0; i < index; i++)
        {
            if (tem == nullptr)
            {
                throw std::out_of_range("Index out of range");
            }
            tem = tem->next;
        }
        return tem->data;
    }
    bool empty()
    {
        return size == 0;
    }
    size_t getSize()
    {
        return size;
    }
    Node *begin()
    {
        return head;
    }
    Node *end()
    {
        return nullptr;
    }
};
int main()
{
    List<int> list;
    list.push_back(5);
    list.push_back(7);
    list.push_back(8);
    list.printElements();
    list.push_front(10);
    list.printElements();
    std::cout << list[3] << " " << list.getSize() << std::endl;
    std::cout << *list.find(8);
    return 0;
}
