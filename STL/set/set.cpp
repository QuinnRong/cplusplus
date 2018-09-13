#include <set>
#include <cstdio>

/*****
@definition
template < class T,                        // set::key_type/value_type
           class Compare = less<T>,        // set::key_compare/value_compare
           class Alloc = allocator<T>      // set::allocator_type
           > class set;

@member functions
begin:
    iterator begin() noexcept;
    const_iterator begin() const noexcept;
end:
    iterator end() noexcept;
    const_iterator end() const noexcept;
// for (auto iter = mySet.begin(); iter != mySet.end(); ++iter) {}
rbegin:
    reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
rend:
    reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;
// for (auto riter = mySet.rbegin(); riter != mySet.rend(); ++riter) {}
insert:
    pair<iterator,bool> insert (const value_type& val);
    pair<iterator,bool> insert (value_type&& val);
erase:
    iterator  erase (const_iterator position);
    size_type erase (const value_type& val);
    iterator  erase (const_iterator first, const_iterator last);
****/

void SetTestLess()
{
    printf("set<int, less<int>>\n");
    std::set<int> intSet;
    for (int i = 0; i < 10; ++i)
    {
        intSet.insert(i);
    }
    for (auto item : intSet)
        printf("%d ", item);
    printf("\n");

    intSet.erase(intSet.begin());
    for (auto item : intSet)
        printf("%d ", item);
    printf("\n");

    intSet.erase(--intSet.end());
    for (auto item : intSet)
        printf("%d ", item);
    printf("\n");
}

void SetTestGreater()
{
    printf("set<int, greater<int>>\n");
    std::set<int, std::greater<int>> intSet;
    for (int i = 0; i < 10; ++i)
    {
        intSet.insert(i);
    }
    for (auto item : intSet)
        printf("%d ", item);
    printf("\n");

    intSet.erase(intSet.begin());
    for (auto item : intSet)
        printf("%d ", item);
    printf("\n");

    intSet.erase(--intSet.end());
    for (auto item : intSet)
        printf("%d ", item);
    printf("\n");
}

int main()
{
    SetTestLess();
    SetTestGreater();
}