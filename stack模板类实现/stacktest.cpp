#include <bits/stdc++.h>
#include "stack.h"
#include "stack.tcc"
using namespace std;
int main()
{
    cout << "stack type:int" << endl;
    Stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    while (!stack1.empty())
    {
        cout << stack1.gettop() << endl;
        stack1.pop();
    }
    cout << "stack1 is empty" << endl;
    cout << endl
         << "stack type:string" << endl;
    Stack<string> stack2;
    stack2.push("aaaa");
    stack2.push("bbbb");
    stack2.push("cccc");
    while (!stack2.empty())
    {
        cout << stack2.gettop() << endl;
        stack2.pop();
    }
    cout << "stack1 is empty" << endl;
    return 0;
}