#include <stdio.h>
#include <string.h>

#define MIN(a, b) (a < b ? a : b)

int main(int argc, char **argv) {
    
    char *resource = argv[1];
    char *prefix = argv[2];

    size_t stem_length = strlen(resource);
    size_t prefix_length = strlen(prefix);

    size_t column[stem_length + 1];
    size_t x, y, lastdiag, olddiag;
    
    for (y = 1; y <= stem_length; y++) column[y] = y;
    for (x = 1; x <= prefix_length; x++) {
        column[0] = x;
        for (y = 1, lastdiag = x - 1; y <= stem_length; y++) {
            olddiag = column[y];
            column[y] = MIN(MIN(column[y] + 1, column[y - 1] + 1), lastdiag + (resource[y-1] == prefix[x - 1] ? 0 : 1));
            lastdiag = olddiag;
        }
    }
    printf("distance between `%s' and `%s': %zu\n", resource, prefix, column[stem_length]);
    return 0;
}

/*
gcc ld-ceed.c -o ld-ceed
./ld-ceed str1 str2
*/