/*Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char votes[1000][100];
    for(int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }
    
    int max_votes = 0;
    char winner[100];
    strcpy(winner, "");
    
    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(strcmp(votes[i], votes[j]) == 0) {
                count++;
            }
        }
        
        if(count > max_votes || (count == max_votes && strcmp(votes[i], winner) < 0)) {
            max_votes = count;
            strcpy(winner, votes[i]);
        }
    }
    
    printf("%s %d\n", winner, max_votes);
    return 0;
}