#pragma once

#include <iostream>
#include <string>
#include <vector>

template<typename T>
struct Stack
{
  std::vector<T> elems;

  Stack() {};

  void push(T const& elem)
  {
    std::cout << "push generic\n";
    elems.push_back( elem );
  }

  T pop()
  {
    std::cout << "pop generic\n";

    if( elems.empty() )
      throw std::out_of_range( "Empty stack" );

    T elem = elems.back();
    elems.pop_back();
    return elem;
  }

  T top()
  {
    std::cout << "top generic\n";

    if( elems.empty() )
      throw std::out_of_range( "Empty stack" );

    return elems.back();  // return copy of last element
  }
};
