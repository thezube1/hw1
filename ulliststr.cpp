#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_front(const std::string& val) {
  // if there is no first item in the head, create a new one and set the first item to val
  if (head_ == NULL) {
    head_ = new Item();
    tail_ = head_;
    head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;
    head_->val[head_->first] = val;
    ++size_;
    return;
  }

  // if there is room in-front of the 'first' element, then add val
  if (head_->first > 0) {
    --head_->first;
    head_->val[head_->first] = val;
    ++size_;
    return;
  }

  // finally if there is no space in the current head Item then create a new Item in the list
  Item* new_head = new Item();
  new_head->first = ARRSIZE-1;
  new_head->last = ARRSIZE;
  new_head->val[new_head->first] = val;

  new_head->next = head_;
  new_head->prev = NULL;
  head_->prev = new_head;
  head_ = new_head;
  
  ++size_;
}

void ULListStr::push_back(const std::string& val) {
  // if there is no item at the tail, create a new Item and set tail and head to it
  if (tail_ == NULL) {
    tail_ = new Item();
    head_ = tail_;
    tail_->first = 0;
    tail_->last = 1;
    tail_->val[0] = val;
    ++size_;
    return;
  }

  // if Item exists at tail and there's space add the val
  if (tail_->last < ARRSIZE) {
    tail_->val[tail_->last] = val;
    ++tail_->last;
    ++size_;
    return;
  }

  // if there is no space at the tail node, then create a new Item at the tail node with the value
  Item* new_tail = new Item();
  new_tail->first = 0;
  new_tail->last = 1;
  new_tail->val[0] = val;

  tail_->next = new_tail;
  new_tail->prev = tail_;
  new_tail->next = NULL;
  tail_ = new_tail;

  ++size_;
}

void ULListStr::pop_front() {
  // base case if empty list then do nothing
  if (head_ == NULL || size_ == 0) {
    return;
  }

  // simple, remove first value from head node
  ++head_->first;
  --size_;

  // check if node is empty
  if (head_->first == head_->last) {
    Item* old_node = head_;
    head_ = head_->next;
    if (head_ != NULL) {
      head_->prev = NULL;
    } else {
      tail_ = NULL;
    }
    delete old_node;
  }
}

void ULListStr::pop_back() {
  // again base case, if tail is null and list is empty do nothing
  if (tail_ == NULL || size_ == 0) {
    return;
  }

  // remove value from tail by decreasing
  --tail_->last;
  --size_;

  // check if node is now empty
  if (tail_->first == tail_->last) {
    Item* old_node = tail_;
    tail_ = tail_->prev;
    if (tail_ != NULL) {
      tail_->next = NULL;
    } else {
      // list is empty
      head_ = NULL;
    }
    delete old_node;
  }
}

std::string const & ULListStr::back() const {
  // first check if the list is empty, if it is throw error (had to look up how to throw a string error)
  if (empty()) {
    throw std::out_of_range("List is empty");
  }

  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }

  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  // if location is large than size of items then we know it's invalid
  if (loc >= size_) {
    return NULL; 
  }

  Item* curr_node = head_;
  size_t index = loc;

  // go through nodes to find the correct index, if we go through all then do nothing
  while (curr_node != NULL) {
    size_t count = curr_node->last - curr_node->first;
    if (index < count) {
      // return the correct string as a pointer
      return &curr_node->val[curr_node->first + index];
    }
    else {
      index -= count;
      curr_node = curr_node->next;
    }
  }
  // just incase!
  return NULL;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
