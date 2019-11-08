#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <iostream>
#include <string>
int main() {
	pid_t pid = fork();
	pid_t waitpid(pid_t pid, int* status, int options);
	std::string ls = "ls";
	
	char* argv[2];
	argv[0] = (char*)ls.c_str();
	argv[1] = NULL;

	if (pid < 0) {
	   perror("fork() error");
	   exit(-1);
	}

	if (pid == 0) {
	   std::cout << "I AM A CHILD, ID: " << getpid() << std::endl;
	   if (execvp(argv[0], argv) < 0) {
		perror("exec fail");
		return 0;
	   }
	}
	
	if (pid > 0) {
	   waitpid(-1, NULL, 0);		
	   std::cout << "I AM A PARENT, ID: " << getpid() << std::endl;
	}

return 0;
}
