#include<stdio.h>
#include<windows.h>
#include <unistd.h>

HANDLE th[10],mux;

DWORD WINAPI func(LPVOID p){
    WaitForSingleObject(mux,INFINITE);
    for(int i=1;i<=20;i++){
        printf("%d ",i);
    }printf("\n");
    return 0;
}

int main(){
    mux = CreateMutex(NULL,FALSE,NULL);

    for(int i = 0;i<10;i++){
        th[i] = CreateThread(NULL,0,func,NULL,0,NULL);
    }

    for(int i = 0;i<10;i++){
       WaitForSingleObject(th[i],INFINITE);
    }

    for(int i = 0;i<10;i++){
      CloseHandle(th[i]);
    }
    
    ReleaseMutex(mux);

    return 0;
}