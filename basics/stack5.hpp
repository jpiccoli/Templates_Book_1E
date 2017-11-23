#pragma once

#include <deque>

template<typename T>
struct Stack5
{
  std::deque<T> elems;

  bool empty()
  {
    return elems.empty();
  }

  void push( T const& elem )
  {
    elems.push_back( elem );
  }

  void pop()
  {
    std::cout << "pop member template\n";

    if( elems.empty() )
      throw std::out_of_range( "Empty stack" );

    elems.pop_back();
  }

  T top()
  {
    std::cout << "top string specialization\n";

    if( elems.empty() )
      throw std::out_of_range( "Empty stack" );

    return elems.back();  // return copy of last element
  }

  template<typename T2>
  Stack5<T>& operator= ( Stack5<T2> const& op2 )
  {
    if( (void*)this == (void *)&op2 )
      return *this;

    Stack5<T2> tmp( op2 );

    elems.clear();
    while( !tmp.empty() )
    {
      elems.push_front( tmp.top() );
      tmp.pop();
    }

    return *this;
  }
};

