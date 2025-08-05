#include <stdlib.h>

#define EXIT_SUCCESS 0;
#define EXIT_FAILURE -1;

void sigint_handler(int signal);
void sigchld_handler(int signal);
void childFunction(const char* argv[MAX_TOKENS],int argc);
void parentFunction();

