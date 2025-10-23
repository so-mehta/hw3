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
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

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
  std::vector<T> heap_list;
  void heapify(int curr_index); // this function is used for pop() and sorts down the heap according to the comparator
  void trickleUp(int loc);  // this function is used for push() and correctly sorts up the heat
  PComparator c;
  int m;
  


};

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){

}

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c){
  this-> m = m;
  this -> c = c;
}
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

      throw std::underflow_error("");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
    return heap_list[0];

}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return heap_list.size() == 0;
}


template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return heap_list.size();
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
      throw std::underflow_error("");

  } else {
      //first, swap first and last items
      T first = heap_list[0];   
      heap_list[0] = heap_list[heap_list.size()-1];
      heap_list[heap_list.size()-1] = first;

      //next, remove last item
      heap_list.pop_back();

      //finally, heapify
      if (heap_list.size() !=0){
        heapify(0);
      }
  }



}
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(int loc){
  if (loc == 0){   //we have reached the start of the list, can't trickle up any more
    return;
  }
  int parent = (loc -1 )/ m;
  while ((loc > 0) && (c(heap_list[loc], heap_list[parent]))){  //while you should swap a child and its parent, swap
    //swap parent and child
    T temp = heap_list[parent];
    heap_list[parent] = heap_list[loc];
    heap_list[loc] = temp;
    //update loc and parent variables 
    loc = parent;
    parent = (loc-1) / m;
  }


}
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify(int curr_index){
  
  int fChild = m * curr_index + 1;
  //base case: program has reached a leaf node
  if (fChild >= heap_list.size()){
    return;
  }
  int swapChild = fChild; //swapChild is the best of the parent's (curr_index's) children

  //for each of curr_index's other children, determine who's the best-- m represents the ary-ness of the tree
  for (int i = 1; i < m; i ++){
    if (fChild + i < heap_list.size()){
      if (c(heap_list[fChild + i], heap_list[swapChild])){
        swapChild = fChild + i;
      }
    }
  }

  //if the best child is better than the parent (curr_index, then swap and recurse-- otherwise do nothing)
  if (c(heap_list[swapChild], heap_list[curr_index])){
    T temp = heap_list[curr_index];
    heap_list[curr_index] = heap_list[swapChild];
    heap_list[swapChild] = temp;

    heapify(swapChild);
  }




}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
    heap_list.push_back(item);
    //swap upwards
    trickleUp(heap_list.size() -1);
}






#endif

