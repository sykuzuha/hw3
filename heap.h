#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()) : m_(m), c_(c) {};

  /**
  * @brief Destroy the Heap object
  * 
  */
  //~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> items_;
  void heapify(int idx);
  void trickleUp(int loc);
  int m_;
  PComparator c_;



};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return items_.front();



}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");

  }
  items_[0] = items_.back(); 
  items_.pop_back();
  heapify(0); // a.k.a. trickleDown()



}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  items_.push_back(item);
  trickleUp(items_.size()-1);
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx)
{
  /*if (idx >= size() / m_) 
  {
    return;
  }
  int smallerChild = m_ * idx + 1;
  if (m_ * idx + 1 < size()) 
  {
    int rChild = m_ * idx + 2;
    if (c_(items_[rChild], items_[smallerChild]))
    {
      smallerChild = rChild;
    }

  }

  if (c_(items_[idx], items_[smallerChild])) 
  {
    std::swap(items_[idx], items_[smallerChild]);
    heapify(smallerChild);
  }*/
  int smallest = idx; // Initialize smallest as root
  for (int i = 1; i <= m_; ++i) {
    int child = m_ * idx + i;
    if (child < items_.size() && c_(items_[child], items_[smallest])) {
      smallest = child;
    }
  }
  if (smallest != idx) {
    std::swap(items_[idx], items_[smallest]);
    heapify(smallest); // Recur for the affected sub-tree
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc)
{
  // could be implemented recursively
  int parent = (loc - 1)/m_;
  while(parent >= 0 && c_(items_[loc], items_[parent]) )
  {  
    std::swap(items_[parent], items_[loc]);
    loc = parent;
    parent = (loc - 1)/m_;
  }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return items_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return items_.size();
}

#endif

