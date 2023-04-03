#ifndef VECTOR_H_
#define VECTOR_H_

namespace P{

template<class Type>
class Vector{

 public:
  typedef Type* iterator;

  Vector(): Vector(0)
  {
  }

  explicit Vector(int cap): size_(0), capacity_(cap)
  {
    data_ = new Type[cap];
  }

  Vector(const Vector& other) noexcept {
    size_ = other.size_;
    capacity_ = other.capacity_,
    data_ = other.data_;

    for (int i = 0; i < size_; ++i) {
      data_[i] = other.data_[i];
    }
  }

  Vector(Vector&& other) noexcept {
      size_ = other.size_;
      capacity_ = other.capacity_;
      data_ = other.data_;
      other.data_ = nullptr;
  }

  Vector& operator=(const Vector& other)
  {
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = other.data_;

    for (int i = 0; i < size_; ++i) {
      data_[i] = other.data_[i];
    }
    return *this;
  }

  Vector& operator=(Vector&& other)
  {
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = other.data_;
    other.data_ = nullptr;
    return *this;
  }

  ~Vector()
  {
    if (data_)
    {
      delete[] data_;
    }
  }

  void clear()
  {
    size_ = 0;
    capacity_ = 0;
    if (data_)
    {
      delete[] data_;
    }
  }

  void push_back(const Type& element)
  {
    if (size_ >= capacity_)
    {
      reserve(capacity_ + 10);
    }
    data_[size_] = element;
    ++size_;
  }

  template<class... Arg>
  void emplace_back(Arg... args)
  {
    if (size_ >= capacity_)
    {
      reserve(capacity_ + 10);
    }

    new( (void*) (data_ + size_) ) Type(args...); // Ideally memory should have been allocated by "malloc" beforehand.
    ++size_;
  }

  void pop_back()
  {
    --size_;
  }

  Type& operator[](int i)
  {
    return data_[i];
  }

  const Type& operator[](int i) const
  {
    return data_[i];
  }

  Type& front()
  {
    return data_[0];
  }

  Type& back()
  {
    return data_[size_-1];
  }

  void reserve(int capacity)
  {
    Type* newData = new Type[capacity];
    int smallerSize = capacity < size_ ? capacity : size_;
    for (int i = 0; i < smallerSize; ++i)
    {
      newData[i] = data_[i];
    }
    delete[] data_;
    data_ = newData;
    capacity_ = capacity;
  }

  iterator erase(iterator first, iterator last)
  {
    auto endIt = end();

    // Corner case: end iterator passed as first iterator
    if (first == endIt)
    {
      return endIt;
    }
    auto followingItAfterErase = first + 1;
    // Move elements, which invalidates iterators including end iterator
    while (last != endIt)
    {
      ++last;
      // Check if last is not already the end iterator because the end iterator is valid but not dereferenceable
      if (last!= endIt)
      {
        *first = *last;
      }
      ++first;
    }
    // Fix size and end iterator ( one is added because the difference b/w two numbers don't count one number)
    auto itDiff = (last - first) + 1;
    size_ -= itDiff;

    return  followingItAfterErase;
  }

  iterator erase(iterator pos)
  {
    return erase(pos, pos);
  }

  iterator begin()
  {
    return data_;
  }

  iterator end()
  {
    return data_ + size_;
  }

private:
  int size_;
  int capacity_;
  Type* data_;
};

}

#endif//VECTOR_H_
