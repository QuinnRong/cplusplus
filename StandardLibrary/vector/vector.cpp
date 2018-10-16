#include <cstdio>
#include <vector>

/****
@definition
template < class T, class Alloc = allocator<T> > class vector; // generic template

@constructor
             default (1)    explicit vector (const allocator_type& alloc = allocator_type());
                        Constructs an empty container, with no elements.

                fill (2)    explicit vector (size_type n);
                                     vector (size_type n, const value_type& val,
                                            const allocator_type& alloc = allocator_type());
                        Constructs a container with n elements. Each element is a copy of val (if provided).

               range (3)    template <class InputIterator>
                                     vector (InputIterator first, InputIterator last,
                                            const allocator_type& alloc = allocator_type());
                        Constructs a container with as many elements as the range [first,last), 
                        with each element emplace-constructed from its corresponding element in that range, in the same order.

                copy (4)             vector (const vector& x);
                                     vector (const vector& x, const allocator_type& alloc);
                        Constructs a container with a copy of each of the elements in x, in the same order.

                move (5)             vector (vector&& x);
                                     vector (vector&& x, const allocator_type& alloc);

    initializer list (6)             vector (initializer_list<value_type> il,
                                            const allocator_type& alloc = allocator_type());
                        Constructs a container with a copy of each of the elements in il, in the same order.

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