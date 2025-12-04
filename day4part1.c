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
    for (int i=0;i<inlen;i++){
        for (int j=0;j<strlen(lines[i]);j++){
            if (lines[i][j]!='@'){
                continue;
            }
            int rolls=0;
            if (!(i==0||j==0)){
                if (lines[i-1][j-1]=='@'){
                    rolls++;
                }
            }
            if (i!=0){
                if (lines[i-1][j]=='@'){
                    rolls++;
                }
            }
            if (!(i==0||j==139)){
                if (lines[i-1][j+1]=='@'){
                    rolls++;
                }
            }
            if (j!=0){
                if (lines[i][j-1]=='@'){
                    rolls++;
                }
            }
            if (j!=139){
                if (lines[i][j+1]=='@'){
                    rolls++;
                }
            }
            if (!(i==139||j==0)){
                if (lines[i+1][j-1]=='@'){
                    rolls++;
                }
            }
            if (i!=139){
                if (lines[i+1][j]=='@'){
                    rolls++;
                }
            }
            if (!(i==139||j==139)){
                if (lines[i+1][j+1]=='@'){
                    rolls++;
                }
            }
            if(rolls<4){
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
