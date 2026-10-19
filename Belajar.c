#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv []) {
    char *nama1 = "songkeng";
    char *nama2 = "sabang";
    char *nama3 = "pade";
    if (argc < 4) {
        printf("argumen program kurang\n");
        printf("tambahkan argumen seperti: %s %s %s\n", argv[0], nama1, nama2, nama3);
        return -1;
    }
    
    printf("helo %s\n", argv[1]);
    printf("helo %s\n", argv[2]);
    printf("helo %s\n", argv[3]);
    return 0;
    
}
