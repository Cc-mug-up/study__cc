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

#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <climits>
#include <cstddef>

// 内存池类，用于高效地分配和释放固定大小的内存块
template <typename T, size_t BlockSize = 4096>
class MemoryPool
{
public:
  /* 成员类型定义 */
  typedef T value_type;
  typedef T *pointer;
  typedef T &reference;
  typedef const T *const_pointer;
  typedef const T &const_reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef std::false_type propagate_on_container_copy_assignment;
  typedef std::true_type propagate_on_container_move_assignment;
  typedef std::true_type propagate_on_container_swap;

  // 重新绑定模板类型
  template <class U>
  struct rebind
  {
    typedef MemoryPool<U> other;
  };

  /* 成员函数声明 */
  // 构造函数
  MemoryPool() noexcept;
  // 拷贝构造函数
  MemoryPool(const MemoryPool &memoryPool) noexcept;
  // 移动构造函数
  MemoryPool(MemoryPool &&memoryPool) noexcept;
  // 从其他类型的内存池拷贝构造
  template <class U>
  MemoryPool(const MemoryPool<U> &memoryPool) noexcept;

  // 析构函数
  ~MemoryPool() noexcept;

  // 删除拷贝赋值操作符
  MemoryPool &operator=(const MemoryPool &memoryPool) = delete;
  // 移动赋值操作符
  MemoryPool &operator=(MemoryPool &&memoryPool) noexcept;

  // 获取对象的地址
  pointer address(reference x) const noexcept;
  const_pointer address(const_reference x) const noexcept;

  // 分配内存，忽略 n 和 hint
  pointer allocate(size_type n = 1, const_pointer hint = 0);
  // 释放内存
  void deallocate(pointer p, size_type n = 1);

  // 返回最大可分配的元素数量
  size_type max_size() const noexcept;

  // 在指定位置构造对象
  template <class U, class... Args>
  void construct(U *p, Args &&...args);
  // 销毁指定位置的对象
  template <class U>
  void destroy(U *p);

  // 分配并构造一个新元素
  template <class... Args>
  pointer newElement(Args &&...args);
  // 删除并释放一个元素
  void deleteElement(pointer p);

private:
  // 内存槽联合体，用于存储对象或指向下一个空闲槽
  union Slot_
  {
    value_type element;
    Slot_ *next;
  };

  // 数据指针类型
  typedef char *data_pointer_;
  // 内存槽类型
  typedef Slot_ slot_type_;
  // 内存槽指针类型
  typedef Slot_ *slot_pointer_;

  // 指向当前内存块的指针
  slot_pointer_ currentBlock_;
  // 指向当前可用内存槽的指针
  slot_pointer_ currentSlot_;
  // 指向当前内存块中最后一个内存槽的指针
  slot_pointer_ lastSlot_;
  // 指向空闲内存槽链表的指针
  slot_pointer_ freeSlots_;

  // 调整指针以满足对齐要求
  size_type padPointer(data_pointer_ p, size_type align) const noexcept;
  // 分配新的内存块
  void allocateBlock();

  // 静态断言，确保块大小足够大以容纳两个内存槽
  static_assert(BlockSize >= 2 * sizeof(slot_type_), "BlockSize too small.");
};

#include "MemoryPool.tcc"

#endif // MEMORY_POOL_H