#include<stdio.h>
void swap(char *str1,int st,int mid,int end){
    char str[end-st];
    int i1=st,i2=mid,i3=end;
    int i=0;
    while(i2<=i3){
        str[i]=str1[i2];
        i2++;
        i++;
    }
    str[i]=' ';
    i++;
    while(str1[i1]!=' '){
        str[i]=str1[i1];
        i1++;
        i++;
    }
    i=0;
    while(st<=end){
        str1[st]=str[i];
        i++;
        st++;
    }
}
int main(){
    char str1[100];
    printf("enter the first string: ");
    gets(str1);
    int k1=-1;
    int k2=-1;
    int sp=0;
    int i;
    for(i=0;i<strlen(str1);i++){
        if(str1[i]==' '){
            sp++;
       }
       if(sp==0 && k1==-1){
            k1=i;
       }
       else if(sp==1 && k2==-1){
            k2=i+1;
       }
       else if(sp==2){
            swap(str1,k1,k2,i-1);
            k1=-1;
            k2=-1;
            sp=0;
       }

    }
    if(sp==2){
    swap(str1,k1,k2,i-1);
    }
    puts(str1);
    return 0;
}
