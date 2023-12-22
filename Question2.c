#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"




char **read_words(const char *input_filename, int *nPtr){
	
    char **word_list;        
    /*write your implementation here*/
    int j = 0;
    int i = 0;
    char str[20]; // buffer
    int n;
    // !!READ C FILE HANDLING INSTRUCTIONS BEFORE PROCEEDING!! //

    // Step 1:  Open file "input_filename" in ASCII read mode
    FILE* input; // file handle
    input = fopen(input_filename, "r");
    if(input == NULL)
    {
        return NULL;
    }   

    // Step 2:  Read the first line of the text file as an integer into nPtr
    //          This is the number of valid lines in the text file containing words to be sorted
    fscanf(input, "%d", nPtr);

    // Step 3:  Allocate an array of nPtr number of char pointer under word_list
    if ((word_list = (char**)calloc(*nPtr, sizeof(char*))) == NULL)
    {
        return NULL;
    } 

    // Step 4:  Allocate an array of characters for each word under word_list; 
    //          Read each line from the input file and save it in the allocated array.  
    while (!feof(input))
    {
        fscanf(input, "%s", str);
        
        n = my_strlen(str);
        word_list[i] = (char*)malloc((n+1)*sizeof(char));
        // word_list[i] = str;
        for (j = 0; str[j]!='\0'; j++)
        {
            word_list[i][j] = str[j];
            // printf("%c", word_list[i][j]);
        }
        word_list[i][j] = '\0';
        i++;           
    };

    // Step 5:  Close the file handle
    fclose(input);
    // Step 6:  (for debugging purpose) Print out the contents in the string array
    //          This is for your own confirmation.  Remove this printing code before submission.
    return word_list;

}

void swap(char **str1, char **str2)
{    
	/*this is a helper function that you can implement and use to facilitate your development*/
    
    // Hint: str1 and str2 are not just double pointers - they are single pointers passed-by-reference
    //       Therefore, you should treat *str1 and *str2 as changeable addresses of the start of their
    //       respective strings.

    // Hint 2: Swapping two strings in an array of strings is as easy as swapping the starting addresses
    //         of the two target strings to be swapped.  Review Lecture Contents!
    
    char *temp;
    temp = *str1;
    *str1 = *str2;
    *str2 = temp;

}

void delete_wordlist(char **word_list, int size)
{
    /*This is a helper function that you MUST IMPLEMENT and CALL at the end of every test case*/
    /*THINK ABOUT WHY!!!*/

    // implement your table deletion code here //
   
    // Hint: Review how to deallocate 2D array on heap.  word_list is a 2D array of chars on heap.
    int i;

	// Deallocate sub-level arrays
	for( i = 0; i < size; i++ )
	{
		if( word_list[i] != NULL )  // If allocated
		{
			free( word_list[i]); // Deallocate it now
		}
	}
	// deallocate the pointer lookup table
	free( word_list );

	word_list = NULL;  // Make sure no one misuses dptr later
}

void sort_words_Bubble(char **words, int size)
{   
	/*write your implementation here*/

    // !!IMPLEMENT SWAP() BEFORE ATTEMPTING THIS FUNCTION!! //

    // By this time you should be able to implement bubble sort with your eyes closed ;)

    // Hint: Use your own my_strcmpOrder to compare the ASCII size of the two strings, and
    //       use the returned result as the sorting reference.  

    // Hint: Use swap() if string swapping is required
    int i, j; 
    
    for (i = 0; i < (size - 1); i++)
    {
        for(j = 0; j <= (size - 2); j++)
        {
            if(my_strcmpOrder(words[j], words[j+1]) == 1)
            {
                swap(&words[j], &words[j+1]);
            }
        }
    }
    
}


void sort_words_Selection(char **words, int size){

    // This implementation of string-sorting function using Selection Sort contains 2 semantic bugs

    // Fix the code, and document how you've found the bugs using GNU debugger.
    // Take screenshots of the debugger output at the instance where you've determined every bug.

    // You will be tested again at the cross exam.

    // If you forgot how Selection Sort works, review Lab 2 document.

    int i, j;    
    int min, minIndex;
    
    for(i = 0; i < size; i++)
    {
        minIndex = i;

        for(j = i + 1; j < size; j++)
        {
            // if(my_strcmpOrder(words[i], words[j]) == 1)
            if(my_strcmpOrder(words[minIndex], words[j]) == 1)
            {
                minIndex = j;
            }                        
        }
       
        // if(minIndex != j)
        if(minIndex != i)
        {
            swap(&words[i], &words[minIndex]);
        }

    }
    
}
