#include <vector>
#include <iostream>
#include <concepts>

void print(std::integral auto i) {
    std::cout << "Integral: " << i << '\n';
}
 
void print(auto x) {
    std::cout << "Non-integral: " << x << '\n';
}

template <typename T> 
requires std::integral<T> || std::floating_point<T>
constexpr auto SizVec(std::vector<T> const &vec) {
    return vec.size();
}

int main() {
    std::vector ints { 1, 2, 3, 4, 5};
    std::cout << SizVec(ints) << '\n'; 

    print( 'o' ); static_assert( std::integral<char> );
    print( 007 ); static_assert( std::integral<int> );
    print( 2e2 ); static_assert( !std::integral<float> );
    print("∫∫∫"); static_assert( !std::integral<decltype("")> );
}