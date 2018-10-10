#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

/****
@<cstdio>
freopen:
    FILE * freopen ( const char * filename, const char * mode, FILE * stream );
    mode: "r", "w", "a".
fopen:
    FILE * fopen ( const char * filename, const char * mode );
fclose:
    int fclose ( FILE * stream );
stdin:
    FILE * stdin;
stdout:
    FILE * stdout;
printf:
    int printf ( const char * format, ... );
scanf:
    int scanf ( const char * format, ... );
    On success, the number of items of the argument list successfully filled is returned.
    If a reading error happens or the end-of-file is reached, EOF is returned
sprintf:
    int sprintf (char * str, const char * format, ...);
    the total number of characters written is returned.

@<fsteeam>
ifstream:
    typedef basic_ifstream<char> ifstream;
open:
    void open (const char* filename,  ios_base::openmode mode = ios_base::in);
close:
    void close();

@<iomanip>
setw:
    setw (int n);
setfill:
    setfill (char_type c);
setprecision:
    setprecision (int n);

@<sstream>
istingstream:
           default (1)  explicit istringstream (ios_base::openmode which = ios_base::in);
    initialization (2)  explicit istringstream (const string& str,
                                                ios_base::openmode which = ios_base::in);
              copy (3)  istringstream (const istringstream&) = delete;
              move (4)  istringstream (istringstream&& x);
****/

int main()
{
    int N;
    
    freopen("1.txt", "r", stdin);
    scanf("%d", &N);        // cin >> N;
    printf("%d\n", N);      // cout << N << endl;
    fclose(stdin);

    ifstream ifs("1.txt");  // ifstream ifs; ifs.open("1.txt");
    ifs >> N;
    cout << N << endl;
    ifs.close();

    double f = 3.14159;
    cout << f << endl;                              // 3.14159
    cout << setw(10) << f << endl;                  //    3.14159
    cout << setfill('x') << setw(10) << f << endl;  // xxx3.14159
    cout << setprecision(2) << f << endl;           // 3.1
}