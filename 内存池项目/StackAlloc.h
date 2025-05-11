/*-
 * Copyright (c) 2013 Cosku Acay, http://www.coskuacay.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

/*-
 * 一个模板类，实现了简单的栈结构。
 * 这个类演示了如何使用 allocator_traits（特别是与 MemoryPool 一起使用）
 */

#ifndef STACK_ALLOC_H
#define STACK_ALLOC_H

#include <memory>

// 定义栈节点结构
template <typename T>
struct StackNode_
{
  T data;           // 节点存储的数据
  StackNode_ *prev; // 指向下一个节点的指针
};

// T 是存储在栈中的对象类型，Alloc 是使用的分配器类型
template <class T, class Alloc = std::allocator<T>>
class StackAlloc
{
public:
  typedef StackNode_<T> Node;                                     // 定义节点类型
  typedef typename Alloc::template rebind<Node>::other allocator; // 定义节点分配器类型

  // 默认构造函数
  StackAlloc() { head_ = 0; }
  // 默认析构函数
  ~StackAlloc() { clear(); }

  // 判断栈是否为空
  bool empty() { return (head_ == 0); }

  // 清空栈并释放所有元素
  void clear()
  {
    Node *curr = head_;
    while (curr != 0)
    {
      Node *tmp = curr->prev;
      allocator_.destroy(curr);
      allocator_.deallocate(curr, 1);
      curr = tmp;
    }
    head_ = 0;
  }

  // 将元素压入栈顶
  void push(T element)
  {
    Node *newNode = allocator_.allocate(1);
    allocator_.construct(newNode, Node());
    newNode->data = element;
    newNode->prev = head_;
    head_ = newNode;
  }

  // 弹出栈顶元素并返回
  T pop()
  {
    T result = head_->data;
    Node *tmp = head_->prev;
    allocator_.destroy(head_);
    allocator_.deallocate(head_, 1);
    head_ = tmp;
    return result;
  }

  // 返回栈顶元素
  T top() { return (head_->data); }

private:
  allocator allocator_; // 分配器实例
  Node *head_;          // 栈顶指针
};

#endif // STACK_ALLOC_H