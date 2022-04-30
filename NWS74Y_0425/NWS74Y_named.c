#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int child;

    mkfifo("Szabo Larion", S_IRUSR | S-IWUSR);
    child = fork();

    if(child > 0) {
        char s[1024];
        int fd;

        fd = open("Szabo Larion", O_RDONLY);
        read(fd, s, sizeof(s));
        printf("%s", s);
        close(fd);
        unlink("Szabo Larion");

    } else if(child == 0) {
        int fd = open("Szabo Larion", O_RDONLY);
        write(fd, "SL NWS74Y\n", 12);
        close(fd);

    }
    return 0;
}