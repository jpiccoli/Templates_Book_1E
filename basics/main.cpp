//#include "stdafx.h"
#include <iostream>
#include <string>
#include <type_traits>
#include <deque>
#include <algorithm>

#include "max.hpp"
#include "max2.hpp"
#include "stack1.hpp"
#include "stack2.hpp"
#include "stack3.hpp"
#include "stack4.hpp"
#include "stack5.hpp"
#include "stack8.hpp"
#include "add_val.hpp"

// Created:: 11/23/2017

void basic_template_operations()
{
  int i = 42;
  std::cout << "max(7,i) = " << basics::max( 7, i ) << "\n";

  double f1 = 3.4;
  double f2 = -6.7;
  std::cout << "max(f1,f2) = " << basics::max( f1, f2 ) << "\n";

  std::string s1 = "mathematics";
  std::string s2 = "math";
  std::cout << "max(s1,s2) = " << basics::max( s1, s2 ) << "\n";

  // Disabiguation approach #1
  std::cout << "max(4,4.2) = " << basics::max( static_cast<double>(4), 4.2 ) << "\n";

  // Disabiguation approach #2
  std::cout << "max(4,4.2) = " << basics::max<double>( 4, 4.2 ) << "\n";

  ::max2( 7, 42, 68 );

  std::cout << "7.0, 42.0\n";
  ::max2( 7.0, 42.0 );

  std::cout << "a, b\n";
  ::max2( 'a', 'b' );

  std::cout << "7, 42\n";
  ::max2( 7, 42 );

  std::cout << "<>7, 42\n";
  ::max2<>( 7, 42 );

  std::cout << "<double>7, 42\n";
  ::max2<double>( 7, 42 );
}

void basic_stack_operations()
{
  Stack<int> int_stack;
  Stack<std::string> string_stack;
  Stack3<double, std::deque<double>> double_deque_stack;
  Stack3<int, std::deque<int>> int_deque_stack;
  Stack4<int, 20> int20_stack;
  Stack4<std::string, 40> string40_stack;

  int_stack.push( 7 );
  std::cout << "int_stack top = " << int_stack.top() << "\n";

  string_stack.push( "hello" );
  std::cout << "string_stack top = " << string_stack.top() << "\n";

  double_deque_stack.push( 27.2 );
  std::cout << "double_deque_stack top = " << double_deque_stack.top() << "\n";

  int_deque_stack.push( 11 );
  std::cout << "int_deque_stack top = " << int_deque_stack.top() << "\n";

  int20_stack.push( 17 );
  std::cout << "int20_stack top = " << int20_stack.top() << "\n";

  string40_stack.push( "world" );
  std::cout << "string40_stack top = " << string40_stack.top() << "\n";

  std::vector<int> v1{ 20, 30, 40, 50 };
  std::vector<int> v2;

  std::transform( v1.begin(), v1.end(), std::back_inserter( v2 ), [=] (const int& i) { return add_value<int, 5>(i); });
  for( auto const& j : v2 )
    std::cout << j << "\n";

  Stack5<int> int_template_stack;
  Stack5<double> double_template_stack;
  double_template_stack = int_template_stack;

  Stack8<int> int_template2_stack;
  Stack8<double> double_template2_stack;

  int_template2_stack.push( 42 );
  int_template2_stack.push( 7 );

  double_template2_stack.push( 44.7 );
  double_template2_stack.push( 11.7 );

  std::cout << "Template Template int top = " << int_template2_stack.top() << "\n";
  std::cout << "Template Template double top = " << double_template2_stack.top() << "\n";

  double_template2_stack = int_template2_stack;

  // Loss of data on conversion warning
  int_template2_stack = double_template2_stack;
}

int main()
{
  basic_template_operations();
  basic_stack_operations();

  return 0;
}

