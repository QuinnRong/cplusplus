#include <cstdio>
#include <vector>

/****
@definition
template < class T, class Alloc = allocator<T> > class vector; // generic template

@member functions
begin:
    iterator begin() noexcept;
    const_iterator begin() const noexcept;
end:
    iterator end() noexcept;
    const_iterator end() const noexcept;
front:
          reference front();
    const_reference front() const;
back:
          reference back();
    const_reference back() const;
push_back:
    void push_back (const value_type& val);
    void push_back (value_type&& val);
pop_back:
    void pop_back();
****/

int main()
{
    std::vector<int> intVector = {1,2,3,4,5};
    printf("%d\n", intVector.front());
    printf("%d\n", intVector[0]);
}