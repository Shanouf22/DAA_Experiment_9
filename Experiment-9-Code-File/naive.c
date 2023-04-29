//header files
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

//global variables
char string[100];
char pattern[100];
int count=0; //to know how many occurences were found

//function to compare two strings
bool isMatching(int offset){
    for(int i=0; i<strlen(pattern); i++){
        if(string[i+offset]!=pattern[i])
            return false;
    }
    return true;
}

//function to search for the pattern
void naiveSearch(){
    for(int i=0; i<strlen(string)-strlen(pattern)+1; i++){
        if(isMatching(i)){
            if(count==0)
                printf("\nFollowing information about the index(es) were obtained-\n");
            printf("\nPattern found at index %d",i);
            count++;
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

    //searching for the pattern and printing the found indexes
    naiveSearch();
    if(count!=0){
        if(count==1)
            printf("\n(%d occurrence was obtained!!)",count);
        else
            printf("\n(%d occurrences were obtained!!)",count);
    }
    else
        printf("\nNo such occurence of the provided pattern was found in the string!!");
    printf("\n\n");
}