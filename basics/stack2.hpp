#pragma once

#include <string>
#include "stack1.hpp"

template<>
struct Stack<std::string>
{
  std::vector<std::string> elems;

  void push( std::string const& elem )
  {
    std::cout << "push string specialization\n";
    elems.push_back( elem );
  }

  std::string pop()
  {
    std::cout << "pop string specialization\n";

    if( elems.empty() )
      throw std::out_of_range( "Empty stack" );

    std::string elem = elems.back();
    elems.pop_back();
    return elem;
  }

  std::string top()
  {
    std::cout << "top string specialization\n";

    if( elems.empty() )
      throw std::out_of_range( "Empty stack" );

    return elems.back();  // return copy of last element
  }
};

