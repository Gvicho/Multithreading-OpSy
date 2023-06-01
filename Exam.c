#include<stdio.h>
#include<windows.h>
#include <unistd.h>

HANDLE th1,th2,th3,th4,th5,mux;
int arr[20],idx=0;

DWORD WINAPI func1(LPVOID p){
    for(int i=0;i<20;i++){
        arr[i]=i+1;
    }
    return 0;
}

DWORD WINAPI func2(LPVOID p){
    while(idx<20){
        WaitForSingleObject(mux,INFINITE);
        printf("%d ",arr[idx]);
        idx++;
        if(idx==20)printf("\n");
    }
    return 0;
}

DWORD WINAPI func3(LPVOID p){
    while(TRUE){
        printf("I'm alive!\n");
        sleep(1);// here I am using Linux library unistd.h soo time is in seconds...
    }
    return 0;
}

DWORD WINAPI func4(LPVOID p){
    sleep(10);// here I am using Linux library unistd.h soo time is in seconds...
    TerminateThread(th4,0);
    printf("Thread in infinite loop terminated!\n");
    return 0;
}

int main(){
    

    //a)
    th1 = CreateThread(NULL,0,func1,NULL,0,NULL);
    

    WaitForSingleObject(th1,INFINITE);
    

    CloseHandle(th1);
    
    //b)
    mux = CreateMutex(NULL,FALSE,NULL);
    th2 = CreateThread(NULL,0,func2,NULL,0,NULL);
    th3 = CreateThread(NULL,0,func2,NULL,0,NULL);

    WaitForSingleObject(th2,INFINITE);
    WaitForSingleObject(th3,INFINITE);

    CloseHandle(th2);
    CloseHandle(th3);

    //c)
    th4 = CreateThread(NULL,0,func3,NULL,0,NULL);
    th5 = CreateThread(NULL,0,func4,NULL,0,NULL);

    WaitForSingleObject(th4,INFINITE);
    WaitForSingleObject(th5,INFINITE);

    CloseHandle(th4);
    CloseHandle(th5);

    ReleaseMutex(mux);
    //d)
    return 0;
}