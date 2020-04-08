#include "concepts.h"

pathlist *pathparser(char *val, pathlist *h)
{
	char *paths;


	paths = strtok(val, ":");
	while (paths)
	{
		/**printf("paths is?: %s\n", paths);*/
		add_node_end(&h, paths);
		paths = strtok(NULL, ":");
	}
	return (h);
}
/**
int main(void)
{
	char *path = "PATH";
	char *val;
	pathlist *pathhead;

	pathhead = NULL;
	val = _getenv(path);
	pathhead = pathparser(val, pathhead);
	print_pathlist(pathhead);
	return(0);
}*/
