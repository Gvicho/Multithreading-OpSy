#include<stdio.h>
#include<windows.h>
#include <unistd.h>

HANDLE th;

DWORD WINAPI func(LPVOID p){
    for(int i=1;i<=20;i++){
        printf("%d ",i);
    }printf("\n");
    return 0;
}

int main(){
    th = CreateThread(NULL,0,func,NULL,0,NULL);
    WaitForSingleObject(th,INFINITE);
    CloseHandle(th);
    return 0;
}