#include <iostream>
#include "MemoryPool.h"

int main()
{
  MemoryPool<size_t> pool;
  size_t* x = pool.allocate();
  
  *x = 0xDEADBEEF;
  std::cout << std::hex << *x << std::endl;
  
  pool.deallocate(x);
  return 0;
}