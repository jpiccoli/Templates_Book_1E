#pragma once

#pragma once

#include <vector>
#include <deque>

// Have to use "class" to define CONT - container
template<typename T, template<typename ELEM, typename ALLOC = std::allocator<ELEM> > class CONT = std::deque >
struct Stack8
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

  template<typename T2, template<typename, typename> class CONT2 >
  Stack8<T, CONT>& operator= ( Stack8<T2, CONT2> const& op2 )
  {
    if( (void*)this == (void *)&op2 )
      return *this;

    Stack8<T2, CONT2> tmp( op2 );

    elems.clear();
    while( !tmp.empty() )
    {
      elems.push_front( tmp.top() );
      tmp.pop();
    }

    return *this;
  }

};
