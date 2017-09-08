#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;
string standard="no leaks are possible";
string filename="output/valgrind_test.txt";
int case_test();
int mem_test();

int main(){
    int total_score=0;
    cout<<"正在进行本地测试..."<<endl;
    total_score+=case_test();

    cout<<"测试结果"<<endl;
    cout<<"================================"<<endl;
    cout<<"你的本地测试总分是 "<<total_score<<" ."<<endl;
    cout<<"本地测试比较简单，请再三检查之后再上传！"<<endl;
    return 0;
}


int case_test(){

    pid_t p1=fork();
    if(p1==0){//child process
        int fd=open("output/your_vector.txt",O_RDWR | O_CLOEXEC | O_TRUNC | O_CREAT, S_IRWXU | S_IRWXG);
        if(fd<0){
            perror("Failed to open txt file");
            exit(1);
        }
        dup2(fd,STDOUT_FILENO);
        execlp("./main","./main",NULL);
        perror("Execlp failed:");
        exit(1);
    }
    else if(p1>0){//parent process
        int status;
        pid_t w_result=waitpid(p1,&status,0);
        if(w_result==-1){
            perror("Failed to wait");
            exit(1);
        }
        pid_t p2=fork();
        if(p2==0){//child process
            int fd_null=open("/dev/null",O_RDWR);
            dup2(fd_null,STDOUT_FILENO);
            execlp("diff","diff","output/your_vector.txt","output/your_vector_solution.txt",NULL);
            perror("Execlp diff failed");
            exit(1);
        }
        else if(p2>0){
            int status2;
            waitpid(p2,&status2,0);
            if(WIFEXITED(status2)){
                if(WEXITSTATUS(status2)!=0){
                    cout<<"[失败] 测试 1 (100分)"<<endl;
                    return 0;
		 }
                else{
                    cout<<"[通过] 测试 1 (100分)"<<endl;
		    return 100;
                }
            }

        }
        else{
            perror("Failed to fork");
            exit(1);
        }

    }
    else{
        perror("Failed to fork");
        exit(1);
    }
    return 0;
}
