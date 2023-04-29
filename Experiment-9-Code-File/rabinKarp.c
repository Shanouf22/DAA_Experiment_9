//header files
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

//global variables
char string[100];
char pattern[100];
int modVal;
int count=0; //to know how many occurences were found
int spuriousHit=0, validHit=0;

//function to compare two strings
bool isMatching(int offset){
    for(int i=0; i<strlen(pattern); i++){
        if(string[i+offset]!=pattern[i])
            return false;
    }
    return true;
}

//function to translate character string to number string
void translate(char str[]){
    char temp[100];
    int tempCount=0, tempNum;
    for(int i=0; i<strlen(str); i++){
        if(str[i]==' '){
            temp[tempCount++]=(char)48;
            continue;
        }
        tempNum=(int)str[i]-48;
        if(tempNum<58)
            temp[tempCount++]=(char)tempNum;
        else{
            tempNum-=48;
            temp[tempCount++]=(char)(tempNum/10+48);
            temp[tempCount++]=(char)(tempNum%10+48);
        }
    }
    temp[tempCount]='\0';
    strcpy(str,temp);
}

//function to obtain integar from num-string
int getIntegar(char str[], int start, int end){
    int num=0, factor=1;
    for(int i=end; i>=start; i--){
        if(str[i]=='0'){
            factor*=10;
            continue;
        }
        num+=factor*((int)str[i]-48);
        factor*=10;
    }
    return num;
}

//function to search for the pattern
void rabinKarpSearch(){
    translate(string);
    translate(pattern);
    int temp;
    int valToCompare=(getIntegar(pattern,0,strlen(pattern)-1))%modVal;
    for(int i=0; i<strlen(string)-strlen(pattern)+1; i++){
        temp=(getIntegar(string,i,i+strlen(pattern)-1))%modVal;
        if(temp==valToCompare){
            if(isMatching(i)){
                if(count==0)
                    printf("\nFollowing information about the index(es) were obtained-\n");
                printf("\nPattern found at index %d",i);
                count++;
                validHit++;
            }
            else
                spuriousHit++;
        }
    }
}

//main function
void main(){
    //taking user inputs
    printf("\nEnter a string -----> ");
    scanf("%[^\n]%*c",string);
    printf("Enter the pattern you want to search for in the provided string -----> ");
    scanf("%[^\n]%*c",pattern);
    printf("Enter a prime number that should be used in hash function -----> ");
    scanf("%d",&modVal);

    //searching for the pattern and printing the found indexes
    rabinKarpSearch();
    if(count!=0){
        if(count==1)
            printf("\n(%d occurrence was obtained!!)",count);
        else
            printf("\n(%d occurrences were obtained!!)",count);
    }
    else
        printf("\nNo such occurence of the provided pattern was found in the string!!");
    printf("\n\nTotal Spurious Hits-%d, Total Valid Hits-%d",spuriousHit,validHit);
    printf("\n\n");
}