#include "shellhead.h"

/**
* _getppid - Retrieve the current process id of parent
*/

pid_t _getppid(void)
{
	pid_t parent;

	parent = getpid();
	return(parent);
}

int main(void)
{
    pid_t my_pid;

    my_pid = _getppid();
    printf("%u\n", my_pid);
    return (0);
}
