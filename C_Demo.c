#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/sysinfo.h>
#include <stdlib.h>

//short demo to return information using C on the command line.

int main()
{
	int fd = open("/etc/fstab",O_RDONLY);
	char from[1000];
	char hostbuffer[256];
	int hostname;
	struct stat foo;
	fstat(fd, &foo);
	printf("Size: %d bytes\n",foo.st_size); //determining how large the fstab file is on the current server
	off_t last = lseek(fd, -100, SEEK_END);
       	read(fd, from, 100);
	printf("End of file contains: %s\n", from); //finding and printing out the last 100 bytes of the fstab file
	close(fd);
	hostname = gethostname(hostbuffer, sizeof(hostbuffer));
	printf("Host name: %s\n", hostbuffer); //printing the current server host name
	struct sysinfo bar;
       	sysinfo(&bar);
	printf("Total RAM: %d\n", bar.totalram); //finding the total ram on the server
	char cwdbuffer[256];
	getcwd(cwdbuffer, sizeof(cwdbuffer));
	printf("Current working directory: %s\n", cwdbuffer); //finding the current working directory path
	srandom(bar.freeram);
	long int longnumber = random();
	printf("Random number: %ld\n", longnumber); //printing a random number using the changing free available ram
	return 0;
}
	
