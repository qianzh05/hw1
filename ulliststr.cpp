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
void ULListStr::push_back(const std::string& val){
  size_ ++;//increase size
  if (tail_ == NULL){//when the list is empty: new node, set it as head and tail
    tail_ = new Item();
    tail_->val[tail_->last++] = val;
    head_ = tail_;
  }
  else if (tail_->last < ARRSIZE){//when there is enough room in the tail node
    tail_->val[tail_->last++] = val;
  }
  else{//when no enough room in the tail node, add a new node and update tail
    Item* temp = new Item();
    temp->val[temp->last++] = val;
    tail_->next = temp;
    temp->prev = tail_;
    tail_ = temp;
  }
}

void ULListStr::push_front(const std::string& val){//idea similar to push_back, but operates on head instead
  size_ ++;
  if (head_ == NULL){
    head_ = new Item();
    head_->val[ARRSIZE-1] = val;//add item from 9 to 0 instead of 0 to 9
    head_->last = ARRSIZE;
    head_->first = ARRSIZE - 1;
    tail_ = head_;
  }
  else if (head_->first > 0){
    head_->first --;
    head_->val[head_->first] = val;
  }
  else{
    Item* temp = new Item();
    temp->last = ARRSIZE;
    temp->first = ARRSIZE - 1;
    temp->next = head_;
    head_->prev = temp;
    temp->val[ARRSIZE - 1] = val;
    head_ = temp;
  }
}

void ULListStr::pop_front(){
  size_ --;//decrease size
  if (head_ == NULL) return;//cannot pop an empty list
  head_->first ++;
  if (head_->first == head_->last){//when a node is empty, update head and delete node
    Item * temp = head_;
    head_ = head_->next;
    if (head_ == NULL){
      tail_ = NULL;
    }
    else{
      head_->prev = NULL;
    }
    delete temp;
  }
}

void ULListStr::pop_back(){//similar but operates on tail
  size_ --;
  if (tail_ == NULL) return;
  tail_->last --;
  if (tail_->last == tail_->first){
    Item* temp = tail_;
    tail_ = tail_->prev;
    if (tail_ == NULL){
      head_ = NULL;
    }
    else{
      tail_->next = NULL;
    }
    delete temp;
  }
}


std::string const & ULListStr::back() const{
  if (tail_ == NULL){
    throw std::runtime_error("empty");
  }
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const{
  if (head_ == NULL){
    throw std::runtime_error("empty");

  }
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if (head_ == NULL) return NULL;
  else if (loc > size_) return NULL;
  Item* temp = head_;
  size_t pos = temp->first;//pos tracks the current place in a node
  for (size_t i = 0; i < loc; i++){//iterate loc times to reach loc
    pos ++;
    if (pos == temp->last){//move to the next node if we searched through all items in the current node
      temp = temp->next;
      pos = temp->first;
    }
  }
  return &temp->val[pos];
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
