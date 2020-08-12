#include <stdio.h>
#include <string.h>

#include <map>
#include <string>
using namespace std;

char in[300];
char lib[1000];
int main() {
    // freopen("test.txt","r",stdin) ;
    map<string, string> key;
    gets(in);
    while (gets(in)) {
        if (strcmp(in, "[1337]") == 0) break;
        char *a = strtok(in, ":"), *b = strtok(NULL, ":");
        key[(string)a] = (string)b;
    }

    while (gets(in)) {
        if (strcmp(in, "[3ND]") == 0) break;

        char *a = strtok(in, " ");
        while (a != NULL) {
            if (strlen(key[(string)a].c_str()) == 0)
                printf("%s", a);
            else
                printf("%s", key[(string)a].c_str());
            a = strtok(NULL, " ");
            printf("%c", a != NULL ? ' ' : '\n');
        }
    }
}
