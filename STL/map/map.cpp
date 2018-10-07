#include <unordered_map>
#include <map>

/*****
@unordered_map
template < class Key,                                    // unordered_map::key_type
           class T,                                      // unordered_map::mapped_type
           class Hash = hash<Key>,                       // unordered_map::hasher
           class Pred = equal_to<Key>,                   // unordered_map::key_equal
           class Alloc = allocator< pair<const Key,T> >  // unordered_map::allocator_type
           > class unordered_map;

find:
          iterator find ( const key_type& k );
    const_iterator find ( const key_type& k ) const;
    return unordered_map::end if the specified key is not found.
    time: Average case: constant. Worst case: linear in container size.

@map
template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = less<Key>,                     // map::key_compare
           class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
           > class map;

operator[]:
    mapped_type& operator[] (const key_type& k);
    mapped_type& operator[] (key_type&& k);
    If k matches the key of an element in the container, the function returns a reference to its mapped value.
    If k does not match the key of any element in the container, the function inserts a new element with that key
    and returns a reference to its mapped value.
at:
    A similar member function, map::at, has the same behavior when an element with the key exists,
    but throws an exception when it does not.

@utility
pair
    template <class T1, class T2> struct pair;

member variable:
    first;
    second;

****/