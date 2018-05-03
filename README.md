objective: 

This objective of this project is to make our own system call in order to understand the down deep 
working of the APIs (Application programming interface) that we usually use in our source codes by
referencing them as libraries for example stdio.h which facilitates us with the read and write 
operations and much more.

Procedure and Prerequisites:

   The only prerequisite is that you must work on the open source kernel such as linux, no matter which distribution is it for example 
   Ubuntu, Debian and so on, since we cannot modify and the source code for windows or Mac.
   
   Step By Step Procedings:
   
    NOTE: You must log in as the root user whenever interating with the kernel space in order to avoid authentications of the 
    rights.
    
 1)	Download the source code of the linux kernel from appropriate resource such as www.kernel.org since the source code 
    is not there by default in your system, its just the binary or executable files that run are system. 
    
    NOTE: For this example, I have used the linux kernel version 4.13.11 so I would recommend the same since it is the latest 
           version and I have tested that on my system.
          
 2) In the kernel source directory, (/usr/src/linux-4.13.11)  make a folder for your system call (sjf stands for shortage job first ) 
    afterwards write a C program implementation of your  system call (sjf.c) and create a Makefile for it.
    
        NOTE: Makefile is always different for every other directory and it is used to link all the files of your project.
    
 3)	Go into the kernel source code (/usr/src/linux-4.13.11) and open the Makefile, add the appropriate name of the folder in which your          system call resides.
          
         NOTE: Refer to the file that I have attached named as kernel_space/Makefile for an example.
        
 4) Go into the system call table log located in (/usr/src/linux-4.13.11/arch/x86/entry/syscalls/syscall_64.tbl) and add your system            call entry with an appropriate number.
 
          NOTE: The system call table can either be syscall_64.tbl or syscall_32.tbl depending on your system architecture which you can            view by writing uname -r on the command line.
 5)	Declare your system call in the syscalls.h file which contains the declaration of all the system calls in your system.
 
          NOTE: Refer to the file I have attached named as kernel_space/include/linux/syscalls.h for an example
       
 6)	Make a .config file and compile your kernel to implement the changes and and to add your system call.
      
         For .config file creation, there are two options to get it created. 
         
         The first option is to copy the .config file present in the  /boot directory of your current kernel to the base directory of your new kernel directory. This would take couple of hours to compile the kernel since this option includes all the kernel modules support for your architecture(may also include kernel module support which you would not need in the near future) so it is recommended to use the second method.
         
         The second option is to use two series of command, first is "make menuconfig" and the second is "make localmodconfig". This would make the .config file for only the modules currently attached to the computer and hence would take much less time.
           
           NOTE: IT can take up to 2 hours so be patient while compiling it.
           
 7)	Create a user space program and call your system call with the number you allocated into the system call table.
 
           NOTE: Refer to the file I have attached named as user_space/system_call.c
           
 8) Run the “dmesg” command and verify the working of your system call.
 
            NOTE: It should print whatever you have written inside the printk() function in system call implementation.
            

