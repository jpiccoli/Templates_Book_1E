#pragma once

template<typename T, int MAXSIZE>
struct Stack4
{
  T elems[ MAXSIZE ];
  int num_elems{ 0 };

  Stack4() {};

  void push( T const& elem )
  {
    std::cout << "push size\n";

    if( num_elems == MAXSIZE )
      throw std::out_of_range( "Stack is full" );

    elems[ num_elems ] = elem;
    ++num_elems;
  }

  void pop()
  {
    std::cout << "pop size\n";

    if( num_elems <= 0 )
      throw std::out_of_range( "Empty stack" );

    --num_elems;
  }

  T top()
  {
    std::cout << "top size\n";

    if( num_elems <= 0 )
      throw std::out_of_range( "Empty stack" );

    return elems[ num_elems - 1 ];
  }

};
