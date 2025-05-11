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
 * һ��ģ���࣬ʵ���˼򵥵�ջ�ṹ��
 * �������ʾ�����ʹ�� allocator_traits���ر����� MemoryPool һ��ʹ�ã�
 */

#ifndef STACK_ALLOC_H
#define STACK_ALLOC_H

#include <memory>

// ����ջ�ڵ�ṹ
template <typename T>
struct StackNode_
{
  T data;           // �ڵ�洢������
  StackNode_ *prev; // ָ����һ���ڵ��ָ��
};

// T �Ǵ洢��ջ�еĶ������ͣ�Alloc ��ʹ�õķ���������
template <class T, class Alloc = std::allocator<T>>
class StackAlloc
{
public:
  typedef StackNode_<T> Node;                                     // ����ڵ�����
  typedef typename Alloc::template rebind<Node>::other allocator; // ����ڵ����������

  // Ĭ�Ϲ��캯��
  StackAlloc() { head_ = 0; }
  // Ĭ����������
  ~StackAlloc() { clear(); }

  // �ж�ջ�Ƿ�Ϊ��
  bool empty() { return (head_ == 0); }

  // ���ջ���ͷ�����Ԫ��
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

  // ��Ԫ��ѹ��ջ��
  void push(T element)
  {
    Node *newNode = allocator_.allocate(1);
    allocator_.construct(newNode, Node());
    newNode->data = element;
    newNode->prev = head_;
    head_ = newNode;
  }

  // ����ջ��Ԫ�ز�����
  T pop()
  {
    T result = head_->data;
    Node *tmp = head_->prev;
    allocator_.destroy(head_);
    allocator_.deallocate(head_, 1);
    head_ = tmp;
    return result;
  }

  // ����ջ��Ԫ��
  T top() { return (head_->data); }

private:
  allocator allocator_; // ������ʵ��
  Node *head_;          // ջ��ָ��
};

#endif // STACK_ALLOC_H