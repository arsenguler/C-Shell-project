#ifndef _RNMOCCH_
#define _RNMOCCH_

int rnmocc(char *filename){
FILE *filep = fopen(filename,"r");
if(filep==NULL){
printf("\nFile does not exist or can not be accessed for reading\n");
return 1;}
int isNew=1,i, len, index=0;
char newName[50];
char words[2000][50];
char word[50];
int count[2000];
//Make every element inside count equal to zero.
for (i=0; i<2000; i++)
count[i] = 0;


while(fscanf(filep, "%s", word) != EOF){
//Converting word to lowercase
for(int i = 0; word[i]; i++){
  word[i] = tolower(word[i]);
}

//Removing last punctuation character
len = strlen(word);
if(ispunct(word[len - 1]))
word[len - 1] = '\0';
//Check if word is already inside words array.
isNew = 1;
for(i=0; i<index; i++){
if(strcmp(words[i], word) == 0)
isNew = 0;
}
/*if word is unique for worlds array, add it to words and increment the corresponding 
element of count then increment the index */
if(isNew){
strcpy(words[index], word);
count[index]++;
index++;
}
//if word is not unique, increment the corresponding element of count.
else
{
count[i - 1]++;
}
}
fclose(filep);
/*find the word with the most number of occurances and change the name of the file to that. */
int maxindex=0;
for(i=0; i<2000 && count[i]!=0; i++){
if(count[i]>count[maxindex])
maxindex=i;
}
rename(filename, words[maxindex]);
return 1;
}

#endif
