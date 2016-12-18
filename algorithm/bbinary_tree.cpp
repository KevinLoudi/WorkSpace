#include "bbinary_tree.h"

namespace DataStructure
{

  template<typename T>
  inline BTnode<T>::BTnode()
  {
      parent=left_child=right_child=NULL;
  }

  template<typename T>
  inline BTnode<T>::BTnode(const T& ele)
  {
      data=ele;
      parent=left_child=right_child=NULL;
  }

  template<typename T>
  BTnode<T>::~BTnode()
  {

  }

  template<typename T>
  BTnode<T> BTnode<T>::operator=(const BTnode<T> &other)
  {
      this->data=other.data;
  }

  template<typename T>
  bool BTnode<T>::operator<(const BTnode<T> &other) const
  {
      return (data<other.data);
  }

  template<typename T>
  bool BTnode<T>::operator>(const BTnode<T> &other) const
  {
      return (data>other.data);
  }

  template<typename T>
  bool BTnode<T>::operator==(const BTnode<T> &other) const
  {
      return !(data>other.data)&&!(data<other.data);
  }
};
