#include <stdlib.h>
#include <stdio.h>
#include "data.h"
#include <time.h>


/*
CHANGABLE:
1. maxlength in main()
2. method to checkifcity()
3. if we want to rid empty spaces
*/


/*
MISSING:
findlastchar cannot deal with strings length 0
implement the database
my getridofemptyspaces function modifies the database
*/

char citynamelength = 50; //maximum length of a predefined city name

char namelength(char* input, char maxlength){
  char len=0;
  for( int i=0; i< maxlength; i++){
    if( *(input+i)=='\0' ){return len;}
    len++;
  }
  return len;
}

char findlastchar(char* input, char maxlength){
if(*input=='\0'){
printf("The String you entered is empty. Not implemented yet. Program is broken now\n"); return '\n';
}
for(int i=0; i<maxlength; i++){
if(*(input+i)== '\0'){
return *(input+(i-1));
}
}//for loop
printf("your city name is too long OR my code is broken\n"); return '\n';
}


char getridofemptyspaces(char* input , char maxlength){ // returns the length of my word +1 (being the \0 char)
char posinres=0;
for(int i=0;i<maxlength;i++){
if( *(input+i)!=' ' &&  *(input+i)!='\n' ){
*(input + posinres)= *(input+i); posinres++;
if( *(input+i) == '\0' ){ break; }
}// if input isnt empty
}//for loop
return posinres;
}


char checkifsamestring(char* one, char* two, char length, char lengthsecond){ //if not, return 0. Else return 1.
length = getridofemptyspaces(one, length);
   char emptyinsecond = 0;
for(int i=0; i<length; i++){
  while( i + emptyinsecond < lengthsecond && *(two+i+emptyinsecond)==' ' ){emptyinsecond++;}
if(*(one+i) == '\0' && *(two+i+emptyinsecond)=='\0' ){return 1;}
else if( *(one+i) != *(two+i+emptyinsecond) ){return 0;}
}
return -1; //both strings dont end within length even though they should
}


char checkifcity(char* input, char length){ // if not city, then 0. Else 1
char iscity=0;

for( int i=0; i< sizeof(cities) / sizeof(cities[0]); i++ ){

char n = checkifsamestring( input, cities[i], length, namelength(cities[i], citynamelength) );

if(1== n){return 1;}
if(n==-1){printf("one of the strings doesnt end within the available length. Set the length of malloc in the int main() higher");}
}
return 0;
}//end of checkifcity




int main(int argc, char* argv[]){
char maxlength = 40;
char* userinput = malloc( maxlength *sizeof(char));
char score=0;
  srandom(time(NULL));
char activeletter= (random()%26)+'a';

while(1){

printf("you have managed to do %i cities. enter a city starting with the letter %c\n", score, activeletter);

/*if (fgets(userinput, maxlength, stdin) == NULL) {
    printf("fgets was NULL\n");
    break;
}*/

userinput = fgets(userinput, maxlength, stdin);

//if(userinput==NULL){printf("fgets was null");}

if( *(userinput) ==activeletter){ //if the letter is correct

if(checkifcity(userinput, maxlength)){ //if it is a city
printf("\nGood city.\n");
score = score+1;
activeletter = findlastchar(userinput, maxlength);
}//end of if it is a city

else{ // if it is a city
printf("\n invalid city\nEnter another\n");
}// end of if it is not a city

}// end of if the letter is correct
else{ //else block to if the first letter equals last letter
printf("\nletter is not the same. Start with %c\n\n", activeletter); 
}
} // end of while loop
free(userinput);
} //end of main
