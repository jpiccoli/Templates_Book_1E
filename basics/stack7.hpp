#pragma once

#include <vector>
#include <deque>

// Have to use "class" to define CONT - container
template<typename T, template<typename> class CONT = std::deque >
struct Stack7
{
  CONT<T> elems;

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

  template<typename T2, template <typename> class CONT2>
  Stack7<T>& operator= ( Stack7<T2> const& op2 )
  {
    if( (void*)this == (void *)&op2 )
      return *this;

    Stack7<T2, CONT2> tmp( op2 );

    elems.clear();
    while( !tmp.empty() )
    {
      elems.push_front( tmp.top() );
      tmp.pop();
    }

    return *this;
  }

};
