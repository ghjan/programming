#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getExe(char *in, char *out)
{
	char buffer[1024] = { 0 };
	FILE *pipe = _popen(in, "r");
	if (!pipe)
		return;
	while (!feof(pipe))
	{
		if (fgets(buffer, 1024, pipe))
		{
			strcat(out, buffer);
		}
	}
	_pclose(pipe);//�رչܵ�
}
void main()
{
	char *cmd = "tasklist";
	char *content;
	content = (char *)malloc(1024 * 1024);
	*content = 0;//������  '\0�� 
	getExe(cmd, content);
	printf("%s\n\n", content);

	char *p = strstr(content, "QQ.exe");
	if (p == NULL)
		printf("û�ҵ�");
	else
	{
		int i = 8;
		while (i--)
		printf("%c", *p++);
	}


	getchar();
}