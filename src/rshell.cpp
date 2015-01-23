#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

using namespace std;

int main()
{
	string input = "";
	/*
	char sz[128] = "";

	string name = getlogin(sz, sizeof(sz));
	string host = gethostname(sz, sizeof(sz));*/
	
	cout /*<< name << '@' << host */<< '$';
	cin >> input;
	cout << endl;

	char cmd[] = "ls";
	char *argV[] = {"ls" , "-a" , NULL};
	
//	for(int i = 0; i < input.size() ; i++)
	{}
//		argV[i] = new char[file[i]];	
	
//	for(int i = 0 ; i < input.size() ; i++)
	{
	}

	int pid = fork();
	if(pid == -1)
	{
		perror("fork fail");
		exit(1);
	}

	else if(pid == 0)
		if(execvp(*argV, argV) != 0)
		{
			perror("error in execvp");	
			exit(1);
		}
	
	else if(pid>0)
	{
		if(-1 == wait(0))
			perror("There was an error with wait().");
	}

	return 0;
}















