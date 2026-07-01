// Q1.
// (a) Create a directory named OSLAB, create three files inside it, and display the contents using Linux
// commands
# Create a directory
mkdir OSLAB

# Move into the directory
cd OSLAB

# Create three files
touch file1.txt file2.txt file3.txt

# Display the files in the directory
ls

# Display detailed information
ls -l;

//-------------------------------------------------------------//
// (b) Implement the Producer–Consumer Problem using Semaphores.
ompilation Command:
gcc producer_consumer.c -o pc -pthread

Execution Command:
./pc
*/

#include <stdio.h>      // Standard input/output functions
#include <stdlib.h>     // Standard library functions
#include <pthread.h>    // Thread library
#include <semaphore.h>  // Semaphore library
#include <unistd.h>     // Sleep function

// Size of shared buffer
#define BUFFER_SIZE 5

// Shared buffer
int buffer[BUFFER_SIZE];

// Variables to track buffer positions
int in = 0;
int out = 0;

// Semaphores
sem_t empty;   // Counts empty slots
sem_t full;    // Counts filled slots

// Mutex lock for critical section
pthread_mutex_t mutex;

/*
--------------------------------------------------------
Producer Function
--------------------------------------------------------
*/
void *producer(void *arg)
{
    int item;

    // Produce 10 items
    for (int i = 1; i <= 10; i++)
    {
        // Generate random item
        item = rand() % 100;

        // Wait if buffer is full
        sem_wait(&empty);

        // Enter critical section
        pthread_mutex_lock(&mutex);

        // Insert item into buffer
        buffer[in] = item;

        printf("Producer produced item %d at index %d\n",
               item, in);

        // Update buffer index
        in = (in + 1) % BUFFER_SIZE;

        // Exit critical section
        pthread_mutex_unlock(&mutex);

        // Increase full semaphore
        sem_post(&full);

        // Delay for visualization
        sleep(1);
    }

    pthread_exit(NULL);
}

/*
--------------------------------------------------------
Consumer Function
--------------------------------------------------------
*/
void *consumer(void *arg)
{
    int item;

    // Consume 10 items
    for (int i = 1; i <= 10; i++)
    {
        // Wait if buffer is empty
        sem_wait(&full);

        // Enter critical section
        pthread_mutex_lock(&mutex);

        // Remove item from buffer
        item = buffer[out];

        printf("Consumer consumed item %d from index %d\n",
               item, out);

        // Update buffer index
        out = (out + 1) % BUFFER_SIZE;

        // Exit critical section
        pthread_mutex_unlock(&mutex);

        // Increase empty semaphore
        sem_post(&empty);

        // Delay for visualization
        sleep(2);
    }

    pthread_exit(NULL);
}

/*Main Function*/

int main()
{
    // Thread variables
    pthread_t producer_thread;
    pthread_t consumer_thread;

    // Initialize semaphore 'empty'
    // Initially all slots are empty
    sem_init(&empty, 0, BUFFER_SIZE);

    // Initialize semaphore 'full'
    // Initially buffer has 0 filled slots
    sem_init(&full, 0, 0);

    // Initialize mutex lock
    pthread_mutex_init(&mutex, NULL);

    // Create Producer Thread
    pthread_create(&producer_thread,
                   NULL,
                   producer,
                   NULL);

    // Create Consumer Thread
    pthread_create(&consumer_thread,
                   NULL,
                   consumer,
                   NULL);

    // Wait for Producer Thread to finish
    pthread_join(producer_thread, NULL);

    // Wait for Consumer Thread to finish
    pthread_join(consumer_thread, NULL);

    // Destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    printf("\nProducer-Consumer execution completed.\n");

    return 0;
}
/*
Compilation Command (Linux)
gcc producer_consumer.c -o pc -pthread
Run Command
./pc
Alternative Compilation Command
gcc producer_consumer.c -lpthread -o pc
If Permission Denied Occurs
chmod +x pc
./pc
Step-by-Step Terminal Execution
nano producer_consumer.c

Paste the code → Save using:

CTRL + O
ENTER
CTRL + X

Then compile and run:

gcc producer_consumer.c -o pc -pthread
./pc
output:
Producer produced item 45 at index 0
Consumer consumed item 45 from index 0
Producer produced item 72 at index 1
Producer produced item 18 at index 2
Consumer consumed item 72 from index 1
...
Producer-Consumer execution completed.
*/


// Q2.
// (a) Demonstrate the use of cp, mv, and rm commands with suitable examples
mkdir OSLAB
cd OSLAB
touch file1.txt
cp file1.txt file2.txt
mv file2.txt newfile.txt
rm newfile.txt
ls
/*output*/
file1.txt



// (b) Implement the Dining Philosopher Problem using Semaphores.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5   // Number of philosophers

// Semaphore for forks
sem_t forks[N];

// Mutex for synchronization
pthread_mutex_t mutex;

// Philosopher function
void *philosopher(void *num)
{
    int id = *(int *)num;

    for (int i = 0; i < 3; i++)
    {
        // Philosopher is thinking
        printf("Philosopher %d is THINKING\n", id);
        sleep(1);

        /*
        Deadlock Avoidance Technique:
        Odd philosopher picks left fork first,
        Even philosopher picks right fork first.
        */

        if (id % 2 == 0)
        {
            // Pick right fork
            sem_wait(&forks[(id + 1) % N]);
            printf("Philosopher %d picked RIGHT fork %d\n",
                   id, (id + 1) % N);

            // Pick left fork
            sem_wait(&forks[id]);
            printf("Philosopher %d picked LEFT fork %d\n",
                   id, id);
        }
        else
        {
            // Pick left fork
            sem_wait(&forks[id]);
            printf("Philosopher %d picked LEFT fork %d\n",
                   id, id);

            // Pick right fork
            sem_wait(&forks[(id + 1) % N]);
            printf("Philosopher %d picked RIGHT fork %d\n",
                   id, (id + 1) % N);
        }

        // Eating section
        printf("Philosopher %d is EATING\n", id);
        sleep(2);

        // Put down left fork
        sem_post(&forks[id]);
        printf("Philosopher %d released LEFT fork %d\n",
               id, id);

        // Put down right fork
        sem_post(&forks[(id + 1) % N]);
        printf("Philosopher %d released RIGHT fork %d\n",
               id, (id + 1) % N);

        printf("Philosopher %d finished EATING\n\n", id);
    }

    pthread_exit(NULL);
}

// Main function
int main()
{
    pthread_t ph[N];
    int phil_num[N];

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Initialize semaphores for forks
    for (int i = 0; i < N; i++)
    {
        sem_init(&forks[i], 0, 1);
    }

    // Create philosopher threads
    for (int i = 0; i < N; i++)
    {
        phil_num[i] = i;

        pthread_create(&ph[i],
                       NULL,
                       philosopher,
                       &phil_num[i]);
    }

    // Wait for all philosophers
    for (int i = 0; i < N; i++)
    {
        pthread_join(ph[i], NULL);
    }

    // Destroy semaphores
    for (int i = 0; i < N; i++)
    {
        sem_destroy(&forks[i]);
    }

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    printf("\nDining Philosopher Problem Execution Completed.\n");

    return 0;
}

/*Compilation Command
gcc dining_philosopher.c -o dp -pthread
Run Command
./dp
Sample Output
Philosopher 0 is THINKING
Philosopher 1 is THINKING
Philosopher 2 is THINKING

Philosopher 1 picked LEFT fork 1
Philosopher 1 picked RIGHT fork 2
Philosopher 1 is EATING

Philosopher 1 released LEFT fork 1
Philosopher 1 released RIGHT fork 2
Philosopher 1 finished EATING
*/


// Q3.
// (a) Write a POSIX thread program using pthread_create() and pthread_join().
#include <stdio.h>
#include <pthread.h>

// Function executed by the thread
void *display(void *arg)
{
    printf("Hello! This is a thread.\n");
    return NULL;
}

int main()
{
    pthread_t tid;

    // Create a thread
    pthread_create(&tid, NULL, display, NULL);

    // Wait for the thread to finish
    pthread_join(tid, NULL);

    printf("Thread execution completed.\n");

    return 0;
}
/*output*/
Hello! This is a thread.
Thread execution completed.

// (b) Demonstrate the use of pwd, ls -l, and find commands.
pwd
ls -l
find . -name "file1.txt"
/*output*/
/home/student/OSLAB

total 8
-rw-r--r-- 1 student student 120 Jul 1 10:30 file1.txt
-rw-r--r-- 1 student student 250 Jul 1 10:35 file2.txt
./file1.txt

// Q4.
// (a) Write a C program to create a child process using fork().
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed!\n");
    }
    else if (pid == 0)
    {
        // Child Process
        printf("This is the Child Process.\n");
        printf("Child Process ID (PID): %d\n", getpid());
        printf("Parent Process ID (PPID): %d\n", getppid());
    }
    else
    {
        // Parent Process
        printf("This is the Parent Process.\n");
        printf("Parent Process ID (PID): %d\n", getpid());
        printf("Child Process ID: %d\n", pid);
    }

    return 0;
}
// (b) Write a program to generate an alarm signal using alarm().
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/* Alarm signal handler */
void alarm_handler(int sig)
{
    printf("Alarm signal received.\n");
}

int main()
{
    /* Register SIGALRM handler */
    signal(SIGALRM, alarm_handler);

    /* Set alarm for 5 seconds */
    alarm(5);

    printf("Waiting for alarm...\n");

    /* Wait until signal arrives */
    pause();

    return 0;
}

/* Compilation
gcc alarm_signal.c -o alarm_signal
Execution
./alarm_signal

*/

// Q5.
// (a) Write a shell script to find the largest of three numbers using nested if-else.
#!/bin/bash

echo "Enter three numbers:"
read a b c

if [ $a -gt $b ]
then
    if [ $a -gt $c ]
    then
        echo "Largest number is: $a"
    else
        echo "Largest number is: $c"
    fi
else
    if [ $b -gt $c ]
    then
        echo "Largest number is: $b"
    else
        echo "Largest number is: $c"
    fi
fi
/*save the file*/
nano largest.sh

/*Execution*/
chmod +x largest.sh
./largest.sh

// (b) Write a C program to display Parent PID and Child PID using fork().
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed!\n");
    }
    else if (pid == 0)
    {
        // Child Process
        printf("\nChild Process\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());
    }
    else
    {
        // Parent Process
        printf("\nParent Process\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n", pid);
    }

    return 0;
}
/*compile*/
gcc parent_child_pid.c -o parent_child_pid
/*Execute*/
./parent_child_pid

// Q6.
// (a) Demonstrate thread synchronization using a mutex lock.
#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock;

// Function executed by each thread
void *increment(void *arg)
{
    for (int i = 1; i <= 5; i++)
    {
        pthread_mutex_lock(&lock);

        counter++;
        printf("Thread %ld: Counter = %d\n", (long)arg, counter);

        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Create two threads
    pthread_create(&t1, NULL, increment, (void *)1);
    pthread_create(&t2, NULL, increment, (void *)2);

    // Wait for both threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("\nFinal Counter = %d\n", counter);

    // Destroy mutex
    pthread_mutex_destroy(&lock);

    return 0;
}
/*Compile*/
gcc mutex.c -o mutex -pthread
/*Execute*/
./mutex
// (b) Write a shell script to find factorial using a for loop.

#!/bin/bash
echo "Enter a number:"
read n
fact=1
for ((i=1; i<=n; i++))
do
    fact=$((fact * i))
done
echo "Factorial of $n is $fact"
/*Save the Script*/
nano factorial.sh
/*Execute*/
chmod +x factorial.sh
./factorial.sh


// Q7.
// (a) Write a shell script to find the nth Fibonacci number using a function.

#!/bin/bash
# Function to find Fibonacci number
fibonacci()
{
    n=$1
    a=0
    b=1

    if [ $n -eq 0 ]
    then
        echo "0"
        return
    fi

    for ((i=2; i<=n; i++))
    do
        c=$((a+b))
        a=$b
        b=$c
    done

    if [ $n -eq 1 ]
    then
        echo "1"
    else
        echo "$b"
    fi
}
echo "Enter the value of n:"
read n
result=$(fibonacci $n)
echo "The $n th Fibonacci number is: $result"
/*save the script*/
nano fibonacci.sh
/*Execute*/
chmod +x fibonacci.sh
./fibonacci.sh

// (b) Write a program demonstrating communication using an unnamed pipe (pipe()).
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];
    pid_t pid;
    char write_msg[] = "Hello from Parent Process";
    char read_msg[100];

    // Create pipe
    if (pipe(fd) == -1)
    {
        printf("Pipe creation failed.\n");
        return 1;
    }

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed.\n");
        return 1;
    }
    else if (pid > 0)
    {
        // Parent Process
        close(fd[0]); // Close read end
        write(fd[1], write_msg, strlen(write_msg) + 1);
        close(fd[1]);
    }
    else
    {
        // Child Process
        close(fd[1]); // Close write end
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(fd[0]);
    }

    return 0;
}
/*compile*/
gcc pipe_program.c -o pipe_program
/*Execute*/
./pipe_program

// Q8.
// (a) Write sender and receiver programs to demonstrate signal transmission using kill().

/* receiver.c */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
// Signal handler
void signalHandler(int sig)
{
    printf("\nSignal %d received successfully!\n", sig);
}

int main()
{
    // Register signal handler
    signal(SIGUSR1, signalHandler);

    printf("Receiver Process ID (PID): %d\n", getpid());
    printf("Waiting for signal...\n");

    while(1);

    return 0;
}

/*. sender.c */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int pid;

    printf("Enter Receiver PID: ");
    scanf("%d", &pid);

    // Send SIGUSR1 signal
    kill(pid, SIGUSR1);

    printf("Signal sent successfully.\n");

    return 0;
}

/*Compilation*/
gcc receiver.c -o receiver
gcc sender.c -o sender
/*Run the receiver*/
./receiver
/*Run the sender in another terminal*/
./sender


// (b) Write a shell script to find factorial using recursion.
/*. factorial_recursive.sh */
#!/bin/bash
factorial()
{
    if [ $1 -le 1 ]
    then
        echo 1
    else
        temp=$(factorial $(($1 - 1)))
        echo $(($1 * temp))
    fi
}
echo "Enter a number:"
read n
result=$(factorial $n)
echo "Factorial of $n is $result"

/*save*/
nano factorial_recursive.sh
/*Execute*/
chmod +x factorial_recursive.sh
./factorial_recursive.sh


// Q9.
// (a) Write sender and receiver programs to demonstrate communication using a Named Pipe (FIFO).
/* receiver.c */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char message[100];

    // Open the FIFO for reading
    fd = open("myfifo", O_RDONLY);

    read(fd, message, sizeof(message));

    printf("Received Message: %s\n", message);

    close(fd);

    return 0;
}

/*. sender.c */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    char message[100];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    // Open the FIFO for writing
    fd = open("myfifo", O_WRONLY);

    write(fd, message, strlen(message) + 1);

    close(fd);

    printf("Message Sent Successfully.\n");

    return 0;
}

/*. Before running the programs, create the FIFO: */
mkfifo myfifo
/*Compilation*/
gcc sender.c -o sender
gcc receiver.c -o receiver
/*. Run the Receiver */
./receiver
/*. Run the Sender in Another Terminal */
./sender

// (b) Demonstrate the use of Linux commands for file and directory management using pwd, ls, cd, mkdir, and
// rmdir.
#!/bin/bash
echo "===== Current Working Directory ====="
pwd

echo
echo "===== Listing Files and Directories ====="
ls

echo
echo "===== Creating Directory: OSLAB ====="
mkdir OSLAB

echo
echo "===== Listing After Creating Directory ====="
ls

echo
echo "===== Changing to OSLAB Directory ====="
cd OSLAB

echo
echo "===== Current Directory ====="
pwd

echo
echo "===== Going Back to Parent Directory ====="
cd ..

echo
echo "===== Removing OSLAB Directory ====="
rmdir OSLAB

echo
echo "===== Final Directory List ====="
ls

/* save */
nano directory.sh
/*execute*/
chmod +x directory.sh
./directory.sh


// Q10.
// (a) Demonstrate thread synchronization using Semaphore operations.
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

void *thread1(void *arg)
{
    sem_wait(&sem);   // Acquire semaphore

    printf("Thread 1 is in Critical Section\n");
    sleep(2);
    printf("Thread 1 is leaving Critical Section\n");

    sem_post(&sem);   // Release semaphore
    return NULL;
}

void *thread2(void *arg)
{
    sem_wait(&sem);   // Acquire semaphore

    printf("Thread 2 is in Critical Section\n");
    sleep(2);
    printf("Thread 2 is leaving Critical Section\n");

    sem_post(&sem);   // Release semaphore
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    sem_init(&sem, 0, 1);

    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem);

    return 0;
}
/* Compilation*/
gcc semaphore.c -o semaphore -pthread
/* Run */
./semaphore


// (b) Write a program to ignore SIGINT.
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    // Ignore SIGINT (Ctrl + C)
    signal(SIGINT, SIG_IGN);

    printf("SIGINT (Ctrl+C) is ignored.\n");
    printf("Press Ctrl+C. The program will continue running.\n");

    while(1)
    {
        printf("Program is running...\n");
        sleep(2);
    }

    return 0;
}
/* Compilation */
gcc ignore_sigint.c -o ignore_sigint
/* Execution */
./ignore_sigint
When you press Ctrl + C, nothing happens, and the program continues to run because SIGINT is ignored.
To stop the program, press Ctrl + \ (sends SIGQUIT) or terminate it from another terminal using: kill -9 <PID>


// Q11.
// (a) Implement communication between parent and child using a pipe
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];
    pid_t pid;
    char message[] = "Hello from Parent";
    char buffer[100];

    // Create pipe
    pipe(fd);

    // Create child process
    pid = fork();

    if(pid > 0)
    {
        // Parent Process
        close(fd[0]);              // Close read end
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
    }
    else if(pid == 0)
    {
        // Child Process
        close(fd[1]);              // Close write end
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    }

    return 0;
}
/* Compilation */
gcc pipe.c -o pipe
/* Execution */
./pipe


// (b) Write a shell script to check whether a character is a vowel or consonant using case.
/* vowel.sh */
#!/bin/bash

echo "Enter a character:"
read ch

case $ch in
    a|e|i|o|u|A|E|I|O|U)
        echo "$ch is a Vowel"
        ;;
    [a-z]|[A-Z])
        echo "$ch is a Consonant"
        ;;
    *)
        echo "Invalid Input"
        ;;
esac

/*save the script*/
nano vowel.sh
/*execute*/
chmod +x vowel.sh
/*run*/
./vowel.sh


// Q12.
// (a) Write a shell script to find the factorial of a number using an until loop.
/* factorial_until.sh */
#!/bin/bash

echo "Enter a number:"
read n

fact=1
i=1

until [ $i -gt $n ]
do
    fact=$((fact * i))
    i=$((i + 1))
done

echo "Factorial of $n is: $fact"

/*save the script*/
nano factorial_until.sh
/*execute*/
nano factorial_until.sh
/*run*/
./factorial_until.sh



// (b) Write a C program to demonstrate blocking and unblocking of signals using sigprocmask().
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    sigset_t set;

    // Initialize the signal set
    sigemptyset(&set);

    // Add SIGINT (Ctrl+C) to the signal set
    sigaddset(&set, SIGINT);

    // Block SIGINT
    sigprocmask(SIG_BLOCK, &set, NULL);
    printf("SIGINT is blocked for 10 seconds.\n");
    sleep(10);

    // Unblock SIGINT
    sigprocmask(SIG_UNBLOCK, &set, NULL);
    printf("SIGINT is now unblocked.\n");
    printf("Press Ctrl+C now to terminate the program.\n");

    while(1);

    return 0;
}

/*compile*/
gcc sigprocmask.c -o sigprocmask
/*Execute*/
./sigprocmask

Sample Output
SIGINT is blocked for 10 seconds.
(Press Ctrl + C during these 10 seconds—nothing happens.)
After 10 seconds:
SIGINT is now unblocked.
Press Ctrl+C now to terminate the program.
Now, pressing Ctrl + C terminates the program.