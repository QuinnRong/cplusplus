#include <unordered_map>

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
****/