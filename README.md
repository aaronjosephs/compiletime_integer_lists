compiletime_integer_lists
=========================

Template meta programming coolness

Got bored wrote a struct that generates a constexpr array

Usage:
----

This is just taken from the tests
```c++
#include <iostream>                                                                
#include "generate.hpp"                                                            
                                                                                   
int main()                                                                         
{                                                                                  
    auto a = generate<11>();                                                       
    for (auto i : a ) {                                                            
        std::cout << i << " ";
    }//prints 0 1 2 3 4 5 6 7 8 9 10                                                                              
    std::cout << std::endl;                                                        
    auto b = generate<0,9>();                                                      
    for (auto i : b ) {                                                            
        std::cout << i << " ";                                               
    }//prints 0 1 2 3 4 5 6 7 8                                                                              
    std::cout << std::endl;                                                        
    auto c = generate<3,0,13>();                                                   
    for (auto i : c ) {                                                            
        std::cout << i << " ";                                               
    }//prints 0 3 6 9 12                                                                              
    return 0;                                                                      
}
```
Remeber the range is not inclusive

There is also an overload of generate that takes a constexpr function

```c++
#include <iostream>                                                                
#include <array>                                                                   
#include "generate_with_function.hpp"                                              
#include "generate.hpp"                                                            
                                                                                   
constexpr int f(const int & i) { return i * i + 4 * i - 3;}                        
int main()                                                                         
{                                                                                  
    auto arr = generate<100,f>();                                                  
    for (auto i : arr) {                                                           
        std::cout << i << " ";                                                     
    }std::cout<<std::endl;                                                         
    return 0;                                                                      
}   
```
