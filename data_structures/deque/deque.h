#ifndef DEQUE_H_
#define DEQUE_H_

namespace P{

template<class T>
class deque{

  public:

  explicit deque():m_bookCapacity(10), 
                   m_arrCapacity(10),
                   m_arr_back(0),
                   m_size(0)
  {
    m_book_back = m_bookCapacity/2;
    m_book_front = (m_bookCapacity/2) -1; 
    m_arr_front = m_arrCapacity -1;
    m_ptrBook = new T*[m_bookCapacity]();
  }

  std::uint32_t size() const {return m_size;}


  void push_back(const T& val)
  {
    // Expand if it exceeds book capacity
    if ( m_book_back  >= m_bookCapacity)
    {
      reserveForBook(m_bookCapacity + 10);
    }
    // allocate memory for array
    if (m_arr_back == 0)
    {
      reserveForArr(m_book_back);
    }
    // Dereference book ptr
    m_ptrBook[m_book_back][m_arr_back] = val;
    // Increment arrary back
    ++m_arr_back;
    // Reset array back and increment book back
    if (m_arr_back % m_arrCapacity == 0)
    {
      m_arr_back = 0;
      ++m_book_back;
    }
    // Increment size
    ++m_size;
  }

  void push_front(const T& val)
  {
    // Expand if it exceeds book capacity
    if ( m_book_front  <= 0)
    {
      reserveForBook(m_bookCapacity + 10);
    }
    // Allocate memory for array
    if (m_arr_front == m_arrCapacity -1)
    {
      reserveForArr(m_book_front);
    }
    // Dereference book ptr
    m_ptrBook[m_book_front][m_arr_front] = val;
    // Increment arrary back
    --m_arr_front;
    // Reset array back and increment book back
    if (m_arr_front < 0)
    {
      m_arr_front = m_arrCapacity -1;
      --m_book_front;
    }
    // Increment size
    ++m_size;
  }

  void pop_back()
  {
    if (m_size == 0)
      return;

    --m_size;
    --m_arr_back;
    if (m_arr_back < 0)
    {
      m_arr_back = m_arrCapacity -1;
      delete[] m_ptrBook[m_book_back];
      --m_book_back;
    }
    
    // Corner case: container keeps no element
    if (m_size == 0)
    {
      delete[] *m_ptrBook;
      delete[] m_ptrBook;
    }
  }

  void pop_front()
  {
    if (m_size == 0)
      return;

    --m_size;
    ++m_arr_front;
    if (m_arr_front == m_arrCapacity)
    {
      m_arr_front = 0;
      delete[] m_ptrBook[m_book_front];
      ++m_book_front;
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
    // Calculate front offset to add to "i"
    std::int32_t offset;
    // If true, book front has been already decremented by one for the next push front operation, so it has to be incremented
    if (m_arr_front == m_arrCapacity-1)
    {
      offset = (m_book_front+1) * m_arrCapacity;
    }// Else array front has been already decremented by one for the next push front operation, so it has to be incremented
    else
    {
      offset = (m_book_front * m_arrCapacity) + m_arr_front + 1;
    }

    // Get book and array indices
    std::int32_t bookIndex, arrIndex;
    get_indices(i + offset, bookIndex, arrIndex);

    // Deference book pointer
    return m_ptrBook[bookIndex][arrIndex];
  }

  const T& operator[](std::uint32_t i) const
  {
    return const_cast<deque<T>*>(this)[i];
  }

  private:

  void reserveForBook(uint32_t new_cap)
  {
    auto diffCap = new_cap - m_bookCapacity;
    auto offSet = diffCap/2;
    T** newPtrBook = new T*[new_cap]();
    for (std::uint32_t i = 0; i < m_bookCapacity; ++i)
    {
      newPtrBook[i + offSet ] = m_ptrBook[i];
    }
    delete[] m_ptrBook;
    m_ptrBook = newPtrBook;
    m_bookCapacity = new_cap;
    m_book_back += offSet;
    m_book_front += offSet;
  }

  void reserveForArr(uint32_t bookIndex)
  {
    m_ptrBook[bookIndex] = new T[m_arrCapacity];
  }

  void get_indices( const int32_t i, int32_t& bookIndex, int32_t& arrIndex)
  {
    bookIndex = static_cast<int32_t>(static_cast<float>(i) / static_cast<float>(m_arrCapacity));
    arrIndex = i % m_arrCapacity;
  }

  private:

  T** m_ptrBook;
  std::uint32_t m_bookCapacity;
  std::uint32_t m_arrCapacity;
  std::int32_t m_book_front;
  std::int32_t m_book_back;
  std::int32_t m_arr_front;
  std::int32_t m_arr_back;
  std::uint64_t m_size;

};

}

#endif//DEQUE_H_
