#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  DMOJ problem 1kp18c2p1. There are n lines of people waiting for food.
//  There are m people arriving who need to each join the shortest line.
//  Display how many people are in each line being joined before new person joins.
//
//  Sample Input:
//  3 4
//  3 2 5
//
//  Sample Output:
//  2
//  3
//  3
//  4
#define MAX_LINES 100

int shortest_line_index(int lines[], int n) {
  int j;
  //assume whichever number is at index 0 is the shortest to start with
  int shortest = 0;
  //compare the value at index 0 to every other index in the array
  //if new value is less, store its index as the lowest 
  for (j = 1; j < n; j++)
    if (lines[j] < lines[shortest])
      shortest = j;
  return shortest;
}

void solve(int lines[], int n, int m) {
  int i, shortest;
  //  go through each new person m
  for (i = 0; i < m; i++) {
    //use function to find current shortest line then print how many in it
    shortest = shortest_line_index(lines, n);
    printf("%d\n", lines[shortest]);
    // increment the shortest line
    lines[shortest]++;
  }
}

int main(void) {
  // initialize array of int to MAX_LINES
  int lines[MAX_LINES];
  int n, m, i;
  //When inputting using scanf, add & before variables that are not arrays
  //input number of lines and number of people waiting to join
  scanf("%d%d", &n, &m);
  //input current number of people in each line
  for (i = 0; i < n; i++)
    scanf("%d", &lines[i]);
  solve(lines, n, m);

  return 0;
}