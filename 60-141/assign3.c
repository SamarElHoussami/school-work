/*	
	Title: Assign3.c
	Author: Samar El-Houssami
	Date last modified: 03/12/2017
	Objective: reads several lines of text and prints three tables indicating:
		1) the number of occurrences of each letter of the alphabet in the complete text 
		2) the number of one-letter words,two-letter words,three-letter words,and so on,appearing in the complete text
		3) the number of occurrences of each different word in the complete text
	
*/

//includes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//defines
#define MAX_LINES 10
#define MAX_LINE_LENGTH 80
#define MAX_WORD_LENNGTH 20

//prototypes
void letterAnalysis(char text[][MAX_LINE_LENGTH], int lines);	//the number of occurrences of each letter of the alphabet
int wordLengthAnalysis(char text[][MAX_LINE_LENGTH], int lines, int length);	//the number of one-letter words,two-letter words, etc..
void wordAnalysis(char text[][MAX_LINE_LENGTH], int lines);		//Select each word in the text for it to be compared
int wordMatch(char text[][MAX_LINE_LENGTH], char wordCompare[MAX_WORD_LENNGTH], int lines);	//Count the occurrences of the desired word in the text
void resetString(char string[]);								//reset string

int main()
{
	char text[MAX_LINES][MAX_LINE_LENGTH];
	int lines, length, numWords;
	
	printf("Enter the number of lines followed by the test itself:\n");
	scanf("%d\n", &lines);
	
	//read every line into the 2D array text[][]
	for(int i = 0; i < lines; i++)
	{
		scanf("%[^\n]s", text[i]);
		if (i!=(lines-1)) scanf("\n");
	}
	
	printf("\n");
	
	//how many times each letter appears in the text (output 1)
	letterAnalysis(text, lines);
	
	//how many words of each length there are (output 2)
	printf("Word length analysis:\n");
	for(int i = 1; i <= MAX_WORD_LENNGTH; i++)
	{
		numWords = wordLengthAnalysis(text, lines, i);
		
		if(numWords != 0)
			printf("%-5d %s of length %d\n", numWords, numWords == 1 ? "word":"words", i);
	}
	printf("\n");
	
	//how many times each word is repeated in the text (output 3)
	printf("Word count analysis:\n");
	wordAnalysis(text, lines);
	printf("\n");
	
	return 0;
}

// Input: 2D array of characters (text[][]), number of lines
// Objective: Count the occurences of every letter of alphabet
// Output: Number of occurences of each letter in the alphabet
void letterAnalysis(char text[][MAX_LINE_LENGTH], int lines)
{
	//represent letters of the alphabet
	int letterFreq[26] = {0};
	
	
	for(int i = 0; i < lines; i++)
		for(int y = 0; y < strlen(text[i]); y++)
			if(isalpha(text[i][y]))						
				letterFreq[tolower(text[i][y])-'a']++;	
				//'a'-'a' = 0, 'b'-'a' = 1, etc.
		
	printf("Letter count analysis:\n");
	
	for(char ch = 'a'; ch <= 'z'; ch++)
		printf("%c:%3d\n", ch, letterFreq[ch-'a']);
	
	printf("\n");
	
}

// Input: 2D array of characters (text[][]), number of lines, length
// Objective: Count the occurrences of words with the same length as the input
// Output: Number of occurrences of words with the same length as the input
int wordLengthAnalysis(char text[][MAX_LINE_LENGTH], int lines, int length)
{
	int countLength = 0;	
	int letters = 0;		
	
	//this will go through every word in the text
	for(int i = 0; i < lines; i++)	
	{
		for(int y = 0; y < strlen(text[i]); y++)
		{
			//counts how many letters there are in each word
			if(text[i][y] != ' ')
				letters++;
			
			if(text[i][y] == ' ')
			{
				//if the number of letters match the length we're looking for, countLength++
				if(letters == length)
					countLength++;
				
				//resets letters to 0 to move on to the next word
				letters = 0;
			}
		}
		
		//the same thing happens once the end of the line is reached
		if(letters == length)
			countLength++;
		
		letters = 0;
	}
	
	return countLength;
}

// Input: 2D array of characters(text[][]), number of lines
// Objective: Select each word in the text for it to be compared
// Output: Number of occurrences of each word
void wordAnalysis(char text[][MAX_LINE_LENGTH], int lines)
{
	char wordCompare[MAX_WORD_LENNGTH];
	int t = 0, matches;
	
	//this will go through every word in the text
	for(int i = 0; i < lines; i++)	
	{
		for(int y = 0; y < strlen(text[i]); y++)
		{
			if(text[i][y] != ' ')
				wordCompare[t++] = text[i][y];
				
			//sets each word to wordCompare[] one at a time
			if(text[i][y] == ' ')
			{
				//space = end of string
				wordCompare[t] = '\0';	
				
				//sends wordCompare to wordMatch to determine how many times the word is repeated in the text
				matches = wordMatch(text, wordCompare, lines);
				printf("\"%-20s\t appeared %d %s\n", strcat(wordCompare, "\""), matches, matches == 1 ? "time":"times");
				
				//resets wordCompare[] so it can be replaced with the next word
				resetString(wordCompare);
				t = 0;
			}
		}
		//the same thing happens once the end of the line is reached
		//new line = end of string
		wordCompare[t] = '\0';
		
		matches = wordMatch(text, wordCompare, lines);
		printf("\"%-20s\t appeared %d %s\n", strcat(wordCompare, "\""), matches, matches == 1 ? "time":"times");
		
		resetString(wordCompare);
		t = 0;
	}	
}

// Input: 2D array of characters(text[][]), word to be compared, number of lines
// Objective: Count the occurrences of the desired word in the text
// Output: Number of occurrences of the desired word in the text
int wordMatch(char text[][MAX_LINE_LENGTH], char wordCompare[MAX_WORD_LENNGTH], int lines)
{
	char temp[MAX_WORD_LENNGTH];	
	int t = 0, count = 0;
	
	//this will go through every word in the text
	for(int i = 0; i < lines; i++)	
	{
		for(int y = 0; y < strlen(text[i]); y++)
		{
			if(text[i][y] != ' ')
				temp[t++] = text[i][y];
			
			//sets each word to temp[] one at a time
			if(text[i][y] == ' ')
			{
				//space = end of string
				temp[t] = '\0';
				
				//if temp[] is the same as the word we're looking for (wordCompare[]), count++
				if(strcmp(wordCompare, temp) == 0)
					count++;
				
				//resets temp[] so it can be replaced with the next word
				resetString(temp);
				t = 0;
			}
		}
		
		//the same thing happens once the end of the line is reached
		//new line = end of string
		temp[t] = '\0';
		if(strcmp(wordCompare, temp) == 0)
			count++;
				
		resetString(temp);
		t = 0;
	}
	
	//returns the number of words that matched the wanted word
	return count;			
}

// Input: 1D array of characters
// Objective: Reset array
// Output: Emptied array
void resetString(char string[])
{
	for(int i = 0; i < MAX_WORD_LENNGTH; i++)
		string[i] = ' ';
}