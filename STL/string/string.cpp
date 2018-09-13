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

@<cstdio>
sprintf:
    int sprintf (char * str, const char * format, ...);
    the total number of characters written is returned.

@<string>
to_string:
    string to_string (int||long||unsigned||float||double val);
****/

int main()
{
    int a = 123, b = 12;

    std::string str1 = std::to_string(a);
    std::string str2 = std::to_string(b);
    std::string res1 = str1 + str2;
    std::string res2 = str2 + str1;
    printf("%s > %s\n", (res1 > res2)?res1.c_str():res2.c_str(), (res1 > res2)?res2.c_str():res1.c_str());

    char cstr1[50]; char cstr2[50];
    char cres1[100]; char cres2[100];
    sprintf(cstr1, "%d", a);
    sprintf(cstr2, "%d", b);
    strcpy(cres1, cstr1); strcat(cres1, cstr2);
    strcpy(cres2, cstr2); strcat(cres2, cstr1);
    printf("%s > %s\n", (strcmp(cres1, cres2) > 0)?cres1:cres2, (strcmp(cres1, cres2) > 0)?cres2:cres1);

    unsigned char x;
    x = false; printf("%d\n", x);
    x = true; printf("%d\n", x);
}