#include <iostream>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <algorithm>
#include <sys/types.h>

using namespace std;

void makeARGV(char *cmd, char **argV)
{
        while(*cmd != '\0')
        {
                if(*cmd == '#')
                {
                        *cmd = '\0';
                        break;
                }

                while(*cmd == ' '|| *cmd == '\t' || *cmd == '\n')
                        *cmd++ = '\0';

                *argV++ = cmd;
                while(*cmd != '\0' && *cmd != ' ' && *cmd != '\t' && *cmd !='\n')
                        cmd++;
        }
        *argV = '\0';
}

int main()
{
        char cmd[100];
        /*
 *         char sz[128] = "";
 *
 *                 string name = getlogin(sz, sizeof(sz));
 *                         string host = gethostname(sz, sizeof(sz));*/
	while(1)
	{
        cout /*<< name << '@' << host */<< '$';
        cin.getline(cmd, 100, '\n');
        cout << endl;
	
        char *argV[100];
        makeARGV(cmd, argV);
	if(strcmp(*argV, "exit") == 0)
		exit(0);

        int pid = fork();
        if(pid == -1)
        {
                perror("fork fail");
                exit(1);
        }

        else if(pid == 0)
        {        if(execvp(*argV, argV) != 0)
                {
                        perror("error in execvp");
                        exit(1);
                }
	}
        else if(pid>0)
        {
                if(-1 == wait(0))
                        perror("There was an error with wait().");
        }
	}
	return 0;
}












