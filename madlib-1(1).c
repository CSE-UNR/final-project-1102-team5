//Truett Knepp, Angelina Bacon and Anthony Sanders

#include <stdio.h>
#include <stdbool.h>

#define MADLIB "madlib2.txt"
#define WORDLIST 8
#define STR_CAP 100
#define LINELIMIT 19

void storeMadlib();
void userInput();
void scanText();
void changeWord();
void display();

int main(){

int adjective = 0, noun = 0, verb = 0;
char words[WORDLIST][STR_CAP];
char madlib[LINELIMIT][STR_CAP];

FILE* sequence = fopen(MADLIB, "r");
if (sequence == NULL){
	printf("Could not open file\n");

}

storeMadlib(sequence, LINELIMIT, STR_CAP, madlib);
scanText(LINELIMIT, madlib, adjective, noun, verb);
userInput(WORDLIST, adjective, noun, verb, words);

fclose(sequence);
return 0;
}


void storeMadlib(FILE* madlibptr, int size, int length, char madlib[][length]){
for(int rowIndex = 0; rowIndex < size; rowIndex++){
	for(int colIndex = 0; colIndex < length; colIndex++){
		fscanf(madlibptr,"%c",&madlib[rowIndex][colIndex]);
		}
	}
}

void userInput(int adj, int noun, int verb, char words[][STR_CAP]){
for (int i = 0; i < adj; i++){
	printf("Please enter an adjective: ");
	scanf("%s", words[i]);
	}
for (int j = 0; j < adj + noun; j++){
	printf("Please enter a noun: ");
	scanf("%s", words[j]);
	}
for (int k = 0; k < adj + noun + verb; k++){
	printf("Please enter a verb: ");
	scanf("%s", words[k]);
	}
}


void scanText(int size, char madlib[][size], int j, int k, int l){
for (int i = 0; i < size; i++){
	if(madlib[i][0] == 'A'){
		j++;
		}
	else if(madlib[i][0] == 'N'){
		k++;
		}
	else if(madlib[i][0] == 'V'){
		l++;
		}
	}
}


void changeWord(int size, char madlib[][STR_CAP], char words[][STR_CAP]){
int adjIndex = 0, nounIndex = 0, verbIndex = 0;
for (int i = 0; i < size; i++){
	if(madlib[i][0] == 'A'){
		for(int j = 0; j < STR_CAP; j++){
		madlib[i][j] == words[adjIndex][j];
		if(words[adjIndex][j] == '\0'){
		}
	}
		adjIndex++;
		}
	else if(madlib[i][0] == 'N'){
		for(int j = 0; j < STR_CAP; j++){
		madlib[i][j] == words[nounIndex][j];
		if(words[nounIndex][j] == '\0'){
		}
		}
		nounIndex++;
		}
	else if(madlib[i][0] == 'V'){
		for(int j = 0; j < STR_CAP; j++){
		madlib[i][j] == words[verbIndex][j];
		if(words[verbIndex][j] == '\0'){
		}
		}
	verbIndex++;
}
}

}


void display(int size, int length, char madlib[][length]){
for(int rowIndex = 0; rowIndex < size; rowIndex++){
	for(int colIndex = 0; colIndex < length; colIndex++){
		printf("%s", madlib[rowIndex][colIndex]);
		}
		printf("\n");
	}
}

