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

long long strtoint(char *arr, int n){
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
    char buff[10000];
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
    long long startranges[10000];
    int x=0;
    int srcount=0;
    char numbuff[1000];
    int numlen=0;
    for (int i=0;lines[0][i]!='\0';i++){
        if (!x){
            if (lines[0][i]>='0'&&lines[0][i]<='9'){
                x=1;
            }
        }
        if (x){
            if (lines[0][i]<'0'||lines[0][i]>'9'){
                startranges[srcount]=strtoint(numbuff,numlen);
                srcount++;
                numlen=0;
                x=0;
                continue;
            }
            numbuff[numlen]=lines[0][i];
            numlen++;
        }
    }
    if (numlen > 0) {
      startranges[srcount++] = strtoint(numbuff, numlen);
    }
    startranges[srcount++]=-1;
    for (int i=0;startranges[i]>=0;i=i+2){
        for (long long j=startranges[i];j<startranges[i+1]+1;j++){
            int yes=0;
            char num[100];
            sprintf(num,"%lld",j);
            int len = strlen(num);
            for (int p=1;p<len;p++){
                if (len%p==0){
                    int pyes=1;
                    char part[p];
                    for (int q=0;q<p;q++){
                        part[q]=num[q];
                    }
                    for (int l=0;l<len;l+=p){
                        for (int h=l;h<l+p;h++){
                            if (num[h]!=part[h-l]){
                                pyes=0;
                            }
                        }
                    }
                    if (pyes){
                        yes=1;
                    }
                }
            }
            if (yes){
                total+=j;
            }
        }
    }
    printf("%lld\n",total);
    for (int i=0;i<inlen;i++){
        free(lines[i]);
    }
    free(lines);
    return 0;
}