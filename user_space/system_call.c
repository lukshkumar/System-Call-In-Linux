
#include<stdio.h>
#include<linux/kernel.h>
#include<sys/syscall.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

#define sjf_preemptive 339  // System Call Number Defined in syscall_64.tbl present in arch/x86/syscalls

int main()
{
	pid_t pid,pid2;
	pid = fork();
	if(pid>0)
	{
		wait(NULL);
		
			long int s = syscall(sjf_preemptive);
			execlp("./shell2.sh","./shell2.sh",(char*)0);	// Used for running the shell file to get the output for user-space	
	}
	else
	{
	execlp("./shell.sh","./shell.sh",(char*)0);	
	}

	return 0;
}
