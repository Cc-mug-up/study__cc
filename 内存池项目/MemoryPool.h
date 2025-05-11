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

// �ڴ���࣬���ڸ�Ч�ط�����ͷŹ̶���С���ڴ��
template <typename T, size_t BlockSize = 4096>
class MemoryPool
{
public:
  /* ��Ա���Ͷ��� */
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

  // ���°�ģ������
  template <class U>
  struct rebind
  {
    typedef MemoryPool<U> other;
  };

  /* ��Ա�������� */
  // ���캯��
  MemoryPool() noexcept;
  // �������캯��
  MemoryPool(const MemoryPool &memoryPool) noexcept;
  // �ƶ����캯��
  MemoryPool(MemoryPool &&memoryPool) noexcept;
  // ���������͵��ڴ�ؿ�������
  template <class U>
  MemoryPool(const MemoryPool<U> &memoryPool) noexcept;

  // ��������
  ~MemoryPool() noexcept;

  // ɾ��������ֵ������
  MemoryPool &operator=(const MemoryPool &memoryPool) = delete;
  // �ƶ���ֵ������
  MemoryPool &operator=(MemoryPool &&memoryPool) noexcept;

  // ��ȡ����ĵ�ַ
  pointer address(reference x) const noexcept;
  const_pointer address(const_reference x) const noexcept;

  // �����ڴ棬���� n �� hint
  pointer allocate(size_type n = 1, const_pointer hint = 0);
  // �ͷ��ڴ�
  void deallocate(pointer p, size_type n = 1);

  // �������ɷ����Ԫ������
  size_type max_size() const noexcept;

  // ��ָ��λ�ù������
  template <class U, class... Args>
  void construct(U *p, Args &&...args);
  // ����ָ��λ�õĶ���
  template <class U>
  void destroy(U *p);

  // ���䲢����һ����Ԫ��
  template <class... Args>
  pointer newElement(Args &&...args);
  // ɾ�����ͷ�һ��Ԫ��
  void deleteElement(pointer p);

private:
  // �ڴ�������壬���ڴ洢�����ָ����һ�����в�
  union Slot_
  {
    value_type element;
    Slot_ *next;
  };

  // ����ָ������
  typedef char *data_pointer_;
  // �ڴ������
  typedef Slot_ slot_type_;
  // �ڴ��ָ������
  typedef Slot_ *slot_pointer_;

  // ָ��ǰ�ڴ���ָ��
  slot_pointer_ currentBlock_;
  // ָ��ǰ�����ڴ�۵�ָ��
  slot_pointer_ currentSlot_;
  // ָ��ǰ�ڴ�������һ���ڴ�۵�ָ��
  slot_pointer_ lastSlot_;
  // ָ������ڴ�������ָ��
  slot_pointer_ freeSlots_;

  // ����ָ�����������Ҫ��
  size_type padPointer(data_pointer_ p, size_type align) const noexcept;
  // �����µ��ڴ��
  void allocateBlock();

  // ��̬���ԣ�ȷ�����С�㹻�������������ڴ��
  static_assert(BlockSize >= 2 * sizeof(slot_type_), "BlockSize too small.");
};

#include "MemoryPool.tcc"

#endif // MEMORY_POOL_H