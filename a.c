#include<stdio.h>
#include<windows.h>
#include <unistd.h>

HANDLE th;

DWORD WINAPI func(LPVOID p){
    sleep(5);
    printf("aeee\n");
    return 0;
}

int main(){
    th = CreateThread(NULL,0,func,NULL,0,NULL);
    printf("Hello World\n");
    WaitForSingleObject(th,INFINITE);
    CloseHandle(th);
    return 0;
}