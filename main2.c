#include  <stdio.h>
#include  <sys/types.h>

#define   MAX_COUNT  200

void  ChildProcess(int);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;
     int i;
     for(i = 0; i < 2; i++){
       
       pid = fork();
       if (pid == 0) {
         ChildProcess(i);
       }
            
       else if (pid < 0){
         printf("There is an error in the Fork.");
       } 
            
     }
     
    ParentProcess();
}

void  ChildProcess(int myid) {
     int   randomNum;
     printf("Child Pid: %d is going to sleep!\n" , getpid());
  
     srand(getpid());
     randomNum = rand() % 10;
  
     sleep(randomNum + 1);
  
     printf("Child Pid: is awake!\nWhere is my Parent: %d?\n", getpid());
     
      exit(0);
       
     }

//      for (i = 1; i <= MAX_COUNT; i++)
//           printf("   This line is from child, value = %d\n", i);
//      printf("   *** Child process is done ***\n");


void  ParentProcess(void)
{
     int   i, pid, status;
  

     for (i = 0; i; i++)
          pid = wait(&status);
          printf("Child Pid: %d has completed\n");
}
