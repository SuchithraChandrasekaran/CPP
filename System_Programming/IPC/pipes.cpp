#include <stdio.h>
#include <unistd.h>

int main() 
{
    int fd[2];
    pipe(fd);  // Creating a pipe

    if (fork() == 0) 
    {  
        // Child process
        close(fd[0]);  // Close read end
        //H  e  l  l  o  ,     P  a  r  e  n  t  !  
        //1  2  3  4  5  6  7   8  9 10 11 12 13 14
        write(fd[1], "Hello, Parent!", 14);
        close(fd[1]);
    } 
    else 
    {  
        // Parent process
        char buffer[20];
        close(fd[1]);  // Close write end
        read(fd[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);
        close(fd[0]);
    }
    return 0;
}
