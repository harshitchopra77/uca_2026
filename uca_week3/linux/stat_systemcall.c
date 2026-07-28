#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include <errno.h>
#include <string.h>
int main(int argc, char* argv[]){
    struct stat output;
    if( argc != 2){
        printf("Incorrect Input!\n");
    }

    if(stat(argv[1],&output) == -1){
        printf("Couldn't open file, Error occured!\n");
        if(errno == ENOENT){
            printf("File does not exist\n");
        }
        if(errno == EACCES){
            printf("Persmission denied!\n");
        }
        else{
            printf("Some other error occured!\n");
        }
    }

    printf("=== File Attributes for: %s ===\n",argv[1]);

    printf("File Type:                 ");
    if (S_ISREG(output.st_mode)){
        printf("Regular File\n");
    }
    else if (S_ISDIR(output.st_mode)){
        printf("Directory\n");
    }

    printf("Permission:                %04o\n",output.st_mode&0777);
    printf("File Size:                 %ld bytes\n",output.st_size);
    printf("Hard Links Count:          %ld\n",output.st_nlink);
    printf("Owner (UID):               %d\n",output.st_uid);
    printf("Group (GID):               %d\n",output.st_gid);
    printf("Last Access Time:          %s",ctime(&output.st_atime));
    printf("Last Modification Time:    %s",ctime(&output.st_mtime));
    printf("Status Change Time:        %s",ctime(&output.st_ctime));
}