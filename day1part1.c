#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    FILE *file = fopen("inputday1.txt", "r");
    char **lines = NULL;
    int count = 0;
    char buff[20];
    while (fgets(buff, sizeof(buff), file)){
        buff[strcspn(buff, "\n")] = 0;
        char *line = malloc(strlen(buff)+1);
        strcpy(line,buff);
        char **temp = realloc(lines, (count+1)*sizeof(char *));
        lines = temp;
        lines[count++] = line;
    }
    fclose(file);
    int pos = 50;
    int sol=0;
    for (int i=0;i<count;i++){
        if (lines[i][0]=='L'){
            int num;
            if (lines[i][2]=='\0'){
                num = lines[i][1]-48;
            }
            else if (lines[i][3]=='\0'){
                num = (lines[i][1]-48)*10+(lines[i][2]-48);
            }
            else{
                num = (lines[i][1]-48)*100+(lines[i][2]-48)*10+(lines[i][3]-48);
            }
            for (int j=0;j<num;j++){
                if (pos!=0){
                    pos--;
                }
                else{
                    pos=99;
                }
                if (pos==0){
                sol++;
            }
            }
            
        }
        if (lines[i][0]=='R'){
            int num;
            if (lines[i][2]=='\0'){
                num = lines[i][1]-48;
            }
            else if (lines[i][3]=='\0'){
                num = (lines[i][1]-48)*10+(lines[i][2]-48);
            }
            else{
                num = (lines[i][1]-48)*100+(lines[i][2]-48)*10+(lines[i][3]-48);
            }
            for (int j=0;j<num;j++){
                if (pos!=99){
                    pos++;
                }
                else{
                    pos=0;
                }
                if (pos==0){
                sol++;
            }
            }
            
        }
    }
    printf("%d\n",sol);
    free(lines);
    return 0;
}