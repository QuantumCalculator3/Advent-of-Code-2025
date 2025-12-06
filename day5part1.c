#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void csort(char *arr, int n) {
    for (int i=0;i<n-1;i++) {
        int min = i;
        for (int j=i+1;j < n;j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        char temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void isort(int *arr, int n) {
    for (int i=0;i<n-1;i++) {
        int min = i;
        for (int j=i+1;j < n;j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void llsort(long long *arr, int n) {
    for (int i=0;i<n-1;i++) {
        int min = i;
        for (int j=i+1;j < n;j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        long long temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int strtoint(char *arr, int n){
    int num = 0;
    for (int i=0;i<n;i++){
        num = num*10+(arr[i]-48);
    }
    return num;
}

long long strtll(char *arr, int n){
    long long num = 0;
    for (int i=0;i<n;i++){
        num = num*10+(arr[i]-48);
    }
    return num;
}

int main(){
    FILE *input = fopen("input.txt", "r");
    char **lines = NULL;
    int inlen = 0;
    char buff[1000];
    while (fgets(buff, sizeof(buff), input)){
        buff[strcspn(buff, "\n")] = 0;
        char *line = malloc(strlen(buff)+1);
        strcpy(line,buff);
        char **temp = realloc(lines, (inlen+1)*sizeof(char *));
        lines = temp;
        lines[inlen++] = line;
    }
    fclose(input);

    int total=0;
    long long rangestart[200];
    long long rangeend[200];
    for (int i=0;i<inlen;i++){
        if (lines[i][0]=='\0'){
            break;
        }
        char numbuff[100];
        char numbuff2[100];
        int len1=0;
        int len2=0;
        for (int j=0;j<strlen(lines[i]);j++){
            if (lines[i][j]=='-'){
                break;
            }
            numbuff[j]=lines[i][j];
            len1++;
        }
        rangestart[i]=strtll(numbuff,len1);
        for (int k=len1+1;k<strlen(lines[i]);k++){
            numbuff2[k-(len1+1)]=lines[i][k];
            len2++;
        }
        rangeend[i]=strtll(numbuff2,len2);
        if (i==inlen-1){
            rangestart[i+1]=-1;
            rangeend[i+1]=-1;
        }
    }
    for (int n=0;n<inlen;n++){
        if (lines[n][0]=='\0'){
            continue;
        }
        char numbuff[300];
        int len=0;
        int x=1;
        for (int j=0;j<strlen(lines[n]);j++){
            if (lines[n][j]=='-'){
                x=0;
            }
            numbuff[j]=lines[n][j];
            len++;
        }
        if (x){
            long long check = strtll(numbuff,len);
            int y=0;
            for (int o=0;;o++){
                if (rangestart[o]==0){
                    break;
                }
                if (check>=rangestart[o]&&check<=rangeend[o]){
                    y=1;
                    break;
                }
            }
            if (y){
                total++;
            }
        }
        
    }
    printf("%d\n",total);

    for (int i=0;i<inlen;i++){
        free(lines[i]);
    }
    free(lines);
    return 0;
}
