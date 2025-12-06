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

    long long total=0;
    long long rangestart[200];
    long long rangeend[200];
    for (int k=0;k<200;k++){
        rangestart[k] = -1;
        rangeend[k] = -1;
    }
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
    int n;
    for (int i=0;;i++){
        if (rangestart[i]==-1){
            n=i;
            break;
        }
    }
    for (int i=0;i<n-1;i++) {
        int min = i;
        for (int j=i+1;j < n;j++) {
            if (rangestart[j] < rangestart[min]) {
                min = j;
            }
        }
        long long temp = rangestart[i];
        long long temp2 = rangeend[i];
        rangestart[i] = rangestart[min];
        rangeend[i] =rangeend[min];
        rangestart[min] = temp;
        rangeend[min]=temp2;
    }
    
    long long min = rangestart[0];
    for (int i=0;i<n;i++){
        if (rangestart[i]<min){
            min=rangestart[i];
        }
    }
    long long max = rangeend[0];
    for (int i=0;i<n;i++){
        if (rangeend[i]>max){
            max=rangeend[i];
        }
    }
    long long negs[1000];
    long long nege[1000];
    negs[0]=min+1;
    nege[0]=max-1;
    int neglen=1;

    for (int i=0;i<n;i++){
        for (int j=0;j<neglen;j++){
            if (negs[j]==-1){
                continue;
            }
            if (rangeend[i] < negs[j] || rangestart[i] > nege[j]){
                continue;
            }
            if (rangestart[i]==negs[j]&&rangeend[i]==nege[j]){
                negs[j]=-1;
                nege[j]=-1;
                continue;
            }
            if (rangestart[i]>negs[j]&&rangeend[i]<nege[j]){
                negs[neglen]=rangeend[i]+1;
                nege[neglen]=nege[j];
                neglen++;
                negs[neglen]=negs[j];
                nege[neglen]=rangestart[i]-1;
                neglen++;
                negs[j]=-1;
                nege[j]=-1;
                continue;
            }
            if (rangestart[i]<negs[j]&&rangeend[i]>nege[j]){
                negs[j]=-1;
                nege[j]=-1;
                continue;
            }
            if (rangestart[i]>=negs[j]&&rangeend[i]>=nege[j]&&rangestart[i]<=nege[j]){
                nege[j]=rangestart[i]-1;
                continue;
            }
            if (rangestart[i]<=negs[j]&&rangeend[i]>=negs[j]&&rangeend[i]<=nege[j]){
                negs[j]=rangeend[i]+1;
                continue;
            }
        }
    }
    for (int i=0;i<neglen;i++){
        if(negs[i]!=-1){
            total += (nege[i]-negs[i])+1;
        }
        
    }
    total = ((max-min)+1)-total;
    printf("%lld\n",total);

    for (int i=0;i<inlen;i++){
        free(lines[i]);
    }
    free(lines);
    return 0;
}
