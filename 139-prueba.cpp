#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h>


int main() {
    int fd[2];
    pipe(fd); 

    int pid = fork();
    if (pid == 0) {
        close(STDIN_FILENO);
        dup(fd[0]);
        close(fd[0]);
        close(fd[1]); 
        int file = open("output.txt", O_WRONLY);
        close(STDOUT_FILENO);
        dup(file);
        execlp("./139", "./139", NULL);
        perror("exec");
        return -1;
    }
    close(fd[0]); 
    close(STDOUT_FILENO);
    dup(fd[1]);
    close(fd[1]);
    for (int i = 9999999; i > -1; --i) {
        printf("%i\n", i);
    }
    close(STDOUT_FILENO);
    wait(NULL);
    printf("FIN\n");
    return 0;

}