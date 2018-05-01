#include<linux/kernel.h>
#include<linux/syscalls.h>
asmlinkage long sys_sjf(void)
{
	const char *cpu="10,20,8,5";
	const char *time="0,2,5,2";
 
	int i=0,leave =0,n,total,leave2 =0,n2,total2;
	
	//Code to convert the char* to int array without using any library or system call
    for(i=0;cpu[i]!='\0';i++)
    {
    	if(cpu[i]==',')
    	{
    		leave++;
		}
	}
	total = i;
	n = leave+1;
	
	int a[n];
	int p[n];
	int temp =0;
	int mul = 10;
	
	//Assigning the number or ID to every CPU burst in order to recognize the process number 
	for(i=0;i<n;i++)
	{
		p[i]=i;
	}
	
	for(i=total-1;i>=0;i--)
    {
    	if(cpu[i]!=',')
    	{
    	
    	if(i==total-1 || cpu[i+1]==',')
    	temp = ((int) cpu[i] - 48) +  temp;
    	else
    	{
    		temp = (((int) cpu[i] - 48)*mul) +  temp;
    		mul = mul*10;
		}
	    }
	    else
	    {
	    
	    	a[n-1] = temp;
			n--;
			mul = 10;
			temp = 0;  
		}
    	if(i==0)
    	{
    
	    	a[n-1] = temp;
			n--;
			mul = 10;
			temp = 0;  
		}
    	
	}

	
    //Code to convert the char* of Arrival time into int array without any library
    
    for(i=0;time[i]!='\0';i++)
    {
    	if(time[i]==',')
    	{
    		leave2++;
		}
	}
	total2 = i;
	n2 = leave2+1;
	int temp2 =0;
	int mul2 = 10;
	
	int b[n2];
	
	for(i=total2-1;i>=0;i--)
    {
    	if(time[i]!=',')
    	{
    	
    	if(i==total2-1 || time[i+1]==',')
    	temp2 = ((int) time[i] - 48) +  temp2;
    	else
    	{
    		temp2 = (((int) time[i] - 48)*mul2) +  temp2;
    		mul2 = mul2*10;
		}
	    }
	    else
	    {
	    
	    	b[n2-1] = temp2;
			n2--;
			mul2 = 10;
			temp2 = 0;  
		}
    	if(i==0)
    	{
    
	    	b[n2-1] = temp2;
			n2--;
			mul2 = 10;
			temp2 = 0;  
		}
    	
	}
	
	//Sorting the Arrival time array with respect to CPU burst
	int j, temp3;
	
	for(i=0;i<leave2;i++)
	{
		for(j=0;j<leave2-i;j++)
		{
			if(b[j]>b[j+1])
			{
				temp3 = b[j];
				b[j] = b[j+1];
				b[j+1] = temp3;
				
				temp3 = a[j];
				a[j] = a[j+1];
				a[j+1] = temp3;
				
				 
			}
		}
	}
	//Printing after sorting
	printk(KERN_INFO "------------------Shortage Job First Preemptive Algorithm--------------------------\n");
	printk(KERN_INFO "---------------Given Input to the system call------------\n");
	printk(KERN_INFO "Process No\n");
	for(i=0;i<leave2+1;i++)
	{
		printk(KERN_INFO "%d\t\t",p[i]);
	}
		
	printk(KERN_INFO "CPU burst\n");
	for(i=0;i<leave2+1;i++)
	{
		
		printk(KERN_INFO "%d\t\t",a[i]);
		
	}
	
	printk(KERN_INFO "Arrival Time\n");
	for(i=0;i<leave2+1;i++)
	{
		printk(KERN_INFO "%d\n",b[i]);
	}
	
	//Done with sorting, moving towards algo
	
	//printf("last time: %d",b[leave]);
	
	int k=1;
	int l=0;
	int x,y,count=0,min=100000,min_index;
	for(i=0;i<=b[leave];i++)
	{
		if(i!=b[k])
		{
			//printf("decreasing\n");
			//printf("THE DECREASING PROCESS: %d\n",a[l] -1);
			a[l]--;	
		}
		else
		{
			//printf("In else");
			for(x=0;x<leave2+1;x++)
			{
				if(b[x]<=i)
					count++;
				//	printf("Count value is: %d\n",count);
			}
			for(x=0;x<count;x++)
			{
				//printf("the actaul cpu burst value is: %d\n",a[x]);
				if(a[x]<=min)
				{
				//	printf("%d is minimum\n",a[x]);
					min = a[x];
					min_index = x;
				}
			}
			
			l = min_index;
			k++;
			count = 0;
		}
	}
	
	
 	//printf("Leave %d\n",leave);
	for(i=0;i<leave;i++)
	{
		for(j=0;j<leave-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp3 = a[j];
				a[j] = a[j+1];
				a[j+1] = temp3;
				
				temp3 = p[j];
				p[j] = p[j+1];
				p[j+1] = temp3; 
			}
		}
		
	}
	
	printk(KERN_INFO "---------------How processes will run according to SJF----------\n");
	printk(KERN_INFO "Process No\n");
	for(i=0;i<leave2+1;i++)
	{
		printk(KERN_INFO "%d\t\t",p[i]);
	}
	printk(KERN_INFO "CPU burst\n");
	for(i=0;i<leave2+1;i++)
	{
		
		printk(KERN_INFO "%d\t\t",a[i]);
		
	}
	printk(KERN_INFO "Arrival Time\n");
	for(i=0;i<leave2+1;i++)
	{
		printk(KERN_INFO "%d\n",b[i]);
	}
	return 0;
	
	
}
