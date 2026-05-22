#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int val;
    Node *next;
    Node(int v) : val(v), next(NULL) {}
} Node;
Node *head = new Node(1);
void push_head(int val)
{
    Node *cur = new Node(val);
    cur->next = head;
    head = cur;
}
void display()
{
    Node *cur = head;
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
}
int main()
{
    srand(time(0));
    int n = 10;
    while (n--)
    {
        push_head(rand() % 10);
    }
    display();
    return 0;
}