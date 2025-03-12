fork()

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork(); // Creating a new process

    if (pid < 0) {
        printf("Fork failed!\n");
        exit(1);
    }
    else if (pid == 0) {
        printf("Child process, PID: %d\n", getpid());
    }
    else {
        printf("Parent process, PID: %d\n", getpid());
    }
    return 0;
}

wait()

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process running (PID: %d)\n", getpid());
        sleep(2);
        printf("Child process terminating...\n");
        exit(0);
    } 
    else {
        printf("Parent process waiting for child...\n");
        wait(NULL);
        printf("Child process finished.\n");
    }
    return 0;
}

exec ()

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();  // Create a new process

    if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) replacing program...\n", getpid());
       
        // Replacing the current program with the 'ls' command
        execlp("ls", "ls", "-l", NULL);
       
        // If exec() fails
        printf("Exec failed!\n");
        exit(1);
    }
    else {
        // Parent process
        printf("Parent process (PID: %d)\n", getpid());
    }

    return 0;
}



exit()

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Program is starting...\n");
    exit(0);  // Program ends immediately here
    printf("This will not be printed.\n");  // Never executed
}



alarm()

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Signal handler function
void alarm_handler(int sig) {
    printf("Alarm triggered! Time's up!\n");
}

int main() {
    // Registering the signal handler
    signal(SIGALRM, alarm_handler);

    printf("Setting an alarm for 5 seconds...\n");

    // Set an alarm for 5 seconds
    alarm(5);

    // Wait until the alarm goes off
    printf("Waiting for the alarm...\n");
    pause();  // Pause program until a signal is received

    return 0;
}




open() close() read() write()


#include <stdio.h>    
#include <fcntl.h>    
#include <unistd.h>   

int main() {
    int fd1, fd2;  
    char buffer[100];  

    // Step 1: Open "test.txt" in Read-Only Mode
    fd1 = open("test.txt", O_RDONLY);
    if (fd1 < 0) {
        printf("Error opening test.txt\n");
        return 1;
    }

    // Step 2: Read data from test.txt
    int bytes_read = read(fd1, buffer, sizeof(buffer) - 1);  // -1 to leave space for '\0'
    if (bytes_read < 0) {
        printf("Error reading file\n");
        close(fd1);
        return 1;
    }
    if (bytes_read == 0) {
        printf("File is empty.\n");
        close(fd1);
        return 1;
    }
    buffer[bytes_read] = '\0';  // Null terminate for safety

    // Step 3: Open/Create "output.txt" in Write Mode (Append mode to prevent overwriting)
    fd2 = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 < 0) {
        printf("Error opening output.txt\n");
        close(fd1);
        return 1;
    }

    // Step 4: Write data to output.txt
    int bytes_written = write(fd2, buffer, bytes_read);
    if (bytes_written < 0) {
        printf("Error writing to output.txt\n");
        close(fd1);
        close(fd2);
        return 1;
    }

    // Step 5: Close both files
    close(fd1);
    close(fd2);

    printf("File copied successfully!\n");
    return 0;
}
