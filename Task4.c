#include<stdio.h>
#include<windows.h>
#include <unistd.h>

HANDLE th1,th2,mux;

DWORD WINAPI func1(LPVOID p){
    while(TRUE){
        printf("I am Alive\n");
        sleep(0.5);
    }
    return 0;
}
DWORD WINAPI func2(LPVOID p){
    sleep(5);
    TerminateThread(th1,0);
    printf("Thread in infinite loop terminated!");
    return 0;
}

int main(){

     th1 = CreateThread(NULL,0,func1,NULL,0,NULL);
     th2 = CreateThread(NULL,0,func2,NULL,0,NULL);


    WaitForSingleObject(th1,INFINITE);
    WaitForSingleObject(th2,INFINITE);

    
    CloseHandle(th1);
    CloseHandle(th2);
    

    return 0;
}