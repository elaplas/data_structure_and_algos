#ifndef DEQUE_H_
#define DEQUE_H_

namespace P{

template<class T>
class deque{

  public:

  explicit deque():m_capacityBook(10), 
                   m_capacityArr(10),
                   m_size(0)
  {
    m_ptrBook = new T*[m_capacityBook]();
  }


  void push_back(const T& val)
  {
    uint32_t bookIndex, arrIndex;
    get_indices(m_size, bookIndex, arrIndex);

    if ( bookIndex  >= m_capacityBook)
    {
      reserveForBook(m_capacityBook + 10);
    }
    if (arrIndex == 0)
    {
      reserveForArr(bookIndex);
    }
    m_ptrBook[bookIndex][arrIndex] = val;
    ++m_size;
  }

  void pop_front()
  {
    --m_size;
    uint32_t bookIndex, arrIndex;
    get_indices(m_size, bookIndex, arrIndex);
    if (arrIndex == m_capacityArr - 1)
    {
      if (bookIndex + 1 < m_capacityBook)
      {
        delete[] m_ptrBook[bookIndex + 1 ];
      }
    }
    // Corner case: container keeps no element
    if (m_size == 0)
    {
      delete[] *m_ptrBook;
      delete[] m_ptrBook;
    }
  }

  T& operator[](std::uint32_t i)
  {
    uint32_t bookIndex, arrIndex;
    get_indices(i, bookIndex, arrIndex);
    return m_ptrBook[bookIndex][arrIndex];
  }

  const T& operator[](std::uint32_t i) const
  {
    uint32_t bookIndex, arrIndex;
    get_indices(i, bookIndex, arrIndex);
    return m_ptrBook[bookIndex][arrIndex];
  }

  void reserveForBook(uint32_t new_cap)
  {
    T** new_ptr = new T*[new_cap]();
    for (std::uint32_t i = 0; i < m_capacityBook; ++i)
    {
      new_ptr[i] = m_ptrBook[i];
    }
    delete[] m_ptrBook;
    m_ptrBook = new_ptr;
    m_capacityBook = new_cap;
  }

  void reserveForArr(uint32_t bookIndex)
  {
    m_ptrBook[bookIndex] = new T[m_capacityArr];
  }

  void get_indices( const uint32_t i, uint32_t& bookIndex, uint32_t& arrIndex)
  {
    bookIndex = static_cast<uint32_t>(static_cast<float>(i) / static_cast<float>(m_capacityArr));
    arrIndex = i % m_capacityArr;
  }

  private:

  T** m_ptrBook;
  std::uint32_t m_capacityBook;
  std::uint32_t m_capacityArr;
  std::uint64_t m_size;
 
};

}

#endif//DEQUE_H_
