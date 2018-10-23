// definition of extern variables

// for non-const variable, no need to use extern (overwrite by initialization)
double pi = 3.14;

// const variable is local to file, so extern is necessary
extern const int bufSize = 512;