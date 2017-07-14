#include"../inc/common.h"





int main(){
   
    pid_t pid;
    int i=1;
    
    int fd;
    void *base=nullptr;
    size_t filesize=0;
    struct stat st;

     fd=Open("info",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
     fstat(fd,&st);
     filesize=st.st_size;
     base=Mmap(nullptr,filesize,PROT_WRITE,MAP_SHARED,fd,SEEK_SET);

    pid=Fork();
    if(pid){//parent
     
     char par_buf[100];
     bzero(par_buf,100);
     SCPY(par_buf,"par_1234\0");
     SCPY(base,par_buf);
     printf("parent i=%d\n",i);

     wait(&i);
     Munmap("info",filesize);
     return 0;

    }else{//child

     char par_buf[100];
     bzero(par_buf,100);
     SCPY(par_buf,"child_1234\0");
     SCPY(base,par_buf);
     printf("child i=%d\n",i);
     Munmap("info",filesize);
     exit(0);
     
   }

 
}