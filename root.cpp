/*************************************************************************
    > File Name: root.cpp
    > Author: TinyPi
    > Mail: haijun.pi@ck-telecom.com 
    > Created Time: 2015年04月22日 星期三 14时01分53秒
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>

#define BASH_FILE "root.sh"

using namespace std;
char *string_capture_right(char *src, int num)
{
	char *temp = src;
	int len = strlen(src);
	if(num > len) num = len;

	temp = temp + len - num;
	*temp = '\0';
	return src;
}

int main (int argc, char *argv[])
{
	char command[32] = {0};
	char *shfile_path;
	char *pro_name;

	if(NULL != strstr(argv[0], "./"))  //run via ./xxx/xxx/root
	{
		pro_name = strrchr(argv[0], '/');
		pro_name++;
		shfile_path = string_capture_right(argv[0], strlen(pro_name));  //get the path of root
	}
	else  //run via other ways
	{
		FILE *pf;
		char *temp;
		char which[32] = "which root";

		if(NULL != (pf = popen(which, "r")))
		{
			fgets(pro_name, 32, pf);

			temp = strrchr(pro_name, '/');
			temp ++;

			shfile_path = string_capture_right(pro_name, strlen(temp));
		}
		else
		{
			printf("popen error!!\n'");
			return 1;
		}
	}
	printf("shfile_path[%s]\n", shfile_path);
	strncpy(command, BASH_FILE, sizeof(BASH_FILE));  //get name of sh file

	strcat(shfile_path, command);

	system(shfile_path);   //run bash file

	return 0;
}
