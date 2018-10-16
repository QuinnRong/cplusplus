#include <map>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*****
@map
template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = less<Key>,                     // map::key_compare
           class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
           > class map;

find:
          iterator find ( const key_type& k );
    const_iterator find ( const key_type& k ) const;
    return map::end if the specified key is not found.
    time: Logarithmic in size.

operator[]:
    mapped_type& operator[] (const key_type& k);
    mapped_type& operator[] (key_type&& k);
    If k matches the key of an element in the container, the function returns a reference to its mapped value.
    If k does not match the key of any element in the container, the function inserts a new element with that key
    and returns a reference to its mapped value.
at:
    A similar member function, map::at, has the same behavior when an element with the key exists,
    but throws an exception when it does not.

@functional
less:
    template <class T> struct less {
        bool operator() (const T& x, const T& y) const {return x<y;}
        typedef T first_argument_type;
        typedef T second_argument_type;
        typedef bool result_type;
    };

greater:
    template <class T> struct greater {
        bool operator() (const T& x, const T& y) const {return x>y;}
        typedef T first_argument_type;
        typedef T second_argument_type;
        typedef bool result_type;
    };

@utility
pair
    template <class T1, class T2> struct pair;

member variable:
    first;
    second;
****/
 
typedef pair<string, int> PAIR;

ostream& operator<<(ostream& out, const PAIR& p)
{
    return out << p.first << "\t" << p.second;
}

struct CmpByKeyLength
{
    bool operator()(const string& k1, const string& k2)
    {
        return k1.length() < k2.length();
    }
};

struct CmpByValue
{
    bool operator()(const PAIR& p1, const PAIR& p2)
    {
        return p1.second < p2.second;
    }
};


bool cmp_by_value(const PAIR& p1, const PAIR& p2)
{
    return p1.second < p2.second;
}

int main()
{   // sort by key (string characters)
    cout << "\nSorted by name:\n";
    map<string, int, greater<string>> name_score_map;
    name_score_map["LiMin"] = 90;
    name_score_map["ZiLinMi"] = 79;
    name_score_map["BoB"] = 92;
    name_score_map.insert(make_pair("Bing",99));
    name_score_map.insert(make_pair("Albert",86));
    for (map<string, int>::iterator iter = name_score_map.begin();
        iter != name_score_map.end();
        ++iter)
    {
        cout << *iter << endl;
    }

    // sort by key (string length)
    cout << "\nSorted by length of name:\n";
    map<string, int, CmpByKeyLength> name_score_map_len;
    name_score_map_len["LiMin"] = 90;
    name_score_map_len["ZiLinMi"] = 79;
    name_score_map_len["BoB"] = 92;
    name_score_map_len.insert(make_pair("Bing",99));
    name_score_map_len.insert(make_pair("Albert",86));
    for (map<string, int>::iterator iter = name_score_map_len.begin();
        iter != name_score_map_len.end();
        ++iter)
    {
        cout << *iter << endl;
    }

    // sort by value
    cout << "\nSorted by score:\n";
    map<string, int> name_score_map_val;
    name_score_map_val["LiMin"] = 90;
    name_score_map_val["ZiLinMi"] = 79;
    name_score_map_val["BoB"] = 92;
    name_score_map_val.insert(make_pair("Bing",99));
    name_score_map_val.insert(make_pair("Albert",86));
    // store in a vector
    vector<PAIR> name_score_vec(name_score_map_val.begin(), name_score_map_val.end());
    // sort(name_score_vec.begin(), name_score_vec.end(), CmpByValue());
    sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_value);
    for (int i = 0; i != name_score_vec.size(); ++i)
    {
        cout << name_score_vec[i] << endl;
    }
    return 0;
}

/*
result:

Sorted by name:
ZiLinMi 79
LiMin   90
BoB     92
Bing    99
Albert  86

Sorted by length of name:
BoB     92
Bing    99
LiMin   90
Albert  86
ZiLinMi 79

Sorted by score:
ZiLinMi 79
Albert  86
LiMin   90
BoB     92
Bing    99

*/
