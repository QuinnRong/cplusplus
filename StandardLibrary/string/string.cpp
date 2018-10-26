#include <string>
#include <cstdio>
#include <cstring>

/****
@<cstring>
strcmp:
    int strcmp (const char * str1, const char * str2);
    return value: < 0 || == 0 || > 0.
strcpy:
    char * strcpy (char * destination, const char * source);
    destination is returned.
strcat:
    char * strcat (char * destination, const char * source);
    destination is returned.
memset:
    void * memset (void * ptr, int value, size_t num);
    value is interpreted as an unsigned char (true as 1, false as 0).

@<string>
#Member functions
to_string:
    string to_string (int||long||unsigned||float||double val);
c_str:
    const char* c_str() const;
substr:
    string substr (size_t pos = 0, size_t len = npos) const;
push_back:
    void push_back (char c);
pop_back:
    void pop_back();
stoi:
    int stoi (const string&  str, size_t* idx = 0, int base = 10);
    int stoi (const wstring& str, size_t* idx = 0, int base = 10);
    idx: set by the function to position of the next character in str after the numerical value.
stof:
    float stof (const string&  str, size_t* idx = 0);
    float stof (const wstring& str, size_t* idx = 0);
stod:
    double stod (const string&  str, size_t* idx = 0);
    double stod (const wstring& str, size_t* idx = 0);
#Non-member function overloads
getline:
    istream& getline (istream&  is, string& str, char delim);
    istream& getline (istream&& is, string& str, char delim);
    istream& getline (istream&  is, string& str);
    istream& getline (istream&& is, string& str);
    default delimitation is the newline character, '\n'.
operator>>:
    istream& operator>> (istream& is, string& str);
    This function overloads operator>> to behave as described in istream::operator>> for c-strings,
    but applied to string objects.
    Each extracted character is appended to the string as if its member push_back was called.
    The istream extraction operations use whitespaces as separators;
    Therefore, this operation will only extract what can be considered a word from the stream.
operator<<:
    ostream& operator<< (ostream& os, const string& str);
    Inserts the sequence of characters that conforms value of str into os.
****/

int main()
{
    int a = 123, b = 12;

    std::string str1 = std::to_string(a);
    std::string str2 = std::to_string(b);
    std::string res1 = str1 + str2;
    std::string res2 = str2 + str1;
    printf("%s > %s\n", (res1 > res2)?res1.c_str():res2.c_str(), (res1 > res2)?res2.c_str():res1.c_str());
    // 12312 > 12123

    char cstr1[50]; char cstr2[50];
    char cres1[100]; char cres2[100];
    sprintf(cstr1, "%d", a);
    sprintf(cstr2, "%d", b);
    strcpy(cres1, cstr1); strcat(cres1, cstr2);
    strcpy(cres2, cstr2); strcat(cres2, cstr1);
    printf("%s > %s\n", (strcmp(cres1, cres2) > 0)?cres1:cres2, (strcmp(cres1, cres2) > 0)?cres2:cres1);
    // 12312 > 12123

    unsigned char x;
    x = false; printf("%d\n", x);   // 0
    x = true; printf("%d\n", x);    // 1

    const char* pstr1 = "abc";      // "abc" stored in static memory
    const char* pstr2 = "abc";      // point to the same string constant
    printf("pstr1 = %p\n", pstr1);  // pstr1 is equal to pstr2
    printf("pstr2 = %p\n", pstr2);

    // char* pstr3 = "abc";         // ISO C++ forbids
    // char* pstr4 = "abc";         // ISO C++ forbids
    // printf("pstr3 = %p\n", pstr3);   // Segmentation fault
    // printf("pstr4 = %p\n", pstr4);   // Segmentation fault

    const char carr1[] = "abc";     // "abc" stored in stack memory
    const char carr2[] = "abc";     // "abc" stored in different stack memory
    printf("carr1 = %p\n", carr1);  // carr1 is inequal to carr2
    printf("carr2 = %p\n", carr2);
}