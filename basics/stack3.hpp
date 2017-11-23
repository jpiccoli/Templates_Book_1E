#pragma once

#include <vector>

template<typename T, typename CONT = std::vector<T> >
struct Stack3
{
  CONT elems;

  bool empty()
  {
    return elems.empty();
  }

  void push( T const& elem )
  {
    std::cout << "push default args\n";
    elems.push_back( elem );
  }

  void pop()
  {
    std::cout << "pop default args\n";
    if( elems.empty() )
      throw std::out_of_range( "Empty stack" );

    elems.pop_back();
  }
  
  T top() const
  {
    std::cout << "top default args\n";
    if( elems.empty() )
      throw std::out_of_range( "Empty stack" );

    return elems.back();
  }

};
