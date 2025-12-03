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

int strtoint(char *arr, int n){
    int num = 0;
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
    for (int i =0;i<inlen;i++){
        int len = strlen(lines[i]);
        int max1 = 0;
        for (int q=0;q<len-11;q++){
            if (lines[i][q]>lines[i][max1]){
                max1=q;
            }
        }
        int max2 = max1+1;
        for (int w=max2;w<len-10;w++){
            if (lines[i][w]>lines[i][max2]){
                max2=w;
            }
        }
        int max3 = max2+1;
        for (int e=max3;e<len-9;e++){
            if (lines[i][e]>lines[i][max3]){
                max3=e;
            }
        }
        int max4 = max3+1;
        for (int r=max4;r<len-8;r++){
            if (lines[i][r]>lines[i][max4]){
                max4=r;
            }
        }
        int max5 = max4+1;
        for (int t=max5;t<len-7;t++){
            if (lines[i][t]>lines[i][max5]){
                max5=t;
            }
        }
        int max6 = max5+1;
        for (int y=max6;y<len-6;y++){
            if (lines[i][y]>lines[i][max6]){
                max6=y;
            }
        }
        int max7 = max6+1;
        for (int u=max7;u<len-5;u++){
            if (lines[i][u]>lines[i][max7]){
                max7=u;
            }
        }
        int max8 = max7+1;
        for (int o=max8;o<len-4;o++){
            if (lines[i][o]>lines[i][max8]){
                max8=o;
            }
        }
        int max9 = max8+1;
        for (int p=max9;p<len-3;p++){
            if (lines[i][p]>lines[i][max9]){
                max9=p;
            }
        }
        int max10 = max9+1;
        for (int a=max10;a<len-2;a++){
            if (lines[i][a]>lines[i][max10]){
                max10=a;
            }
        }
        int max11 = max10+1;
        for (int s=max11;s<len-1;s++){
            if (lines[i][s]>lines[i][max11]){
                max11=s;
            }
        }
        int max12 = max11+1;
        for (int d=max12;d<len;d++){
            if (lines[i][d]>lines[i][max12]){
                max12=d;
            }
        }
        long long intermediate = (lines[i][max1]-'0')*100000000000LL + (lines[i][max2]-'0')*10000000000LL + (lines[i][max3]-'0')*1000000000LL + (lines[i][max4]-'0')*100000000LL + (lines[i][max5]-'0')*10000000LL + (lines[i][max6]-'0')*1000000LL + (lines[i][max7]-'0')*100000LL + (lines[i][max8]-'0')*10000LL + (lines[i][max9]-'0')*1000LL + (lines[i][max10]-'0')*100LL + (lines[i][max11]-'0')*10LL + (lines[i][max12]-'0');
        total += intermediate;
    }

    printf("%lld\n",total);

    for (int i=0;i<inlen;i++){
        free(lines[i]);
    }
    free(lines);
    return 0;
}