#pragma once

inline int const& max2( int const&a, int const& b )
{
  std::cout << "inline\n\n";
  return a < b ? b : a;
}

template<typename T>
inline T const& max2( T const& a, T const& b )
{
  std::cout << "template 2 args\n";

  if( std::is_same<T, int>() )
    std::cout << "Integer type\n\n";

  if( std::is_same<T, double>() )
    std::cout << "Double type\n\n";

  if( std::is_same<T, char>() )
    std::cout << "Char type\n\n";

  return a < b ? b : a;
}

template<typename T>
inline T const& max2( T const& a, T const& b, T const& c )
{
  std::cout << "template 3 args\n\n";
  return basics::max( basics::max( a, b ), c );
}

