#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  // YOUR CODE HERE
  if (length >= ht->capacity * 0.7){
    hash_table_resize(ht);
  }
  else if (length < 2) {
    return NULL;
  }
  for (int i = 0; i < length; i++) {
    // find out what is needed to make the sum (limit)
    int needed = limit - weights[i];
    // check if that number is in the hash table
    int hash_check = hash_table_retrieve(ht, needed);
    // if the number is not in the hash table
    if (hash_check < 0) {
      hash_table_insert(ht, weights[i], i);
    } else { // if it is in the table grab it and figure index 1 & 2
      int winner = weights[hash_check];
      if (winner > weights[i]) {
        Answer->index_1 = winner;
        Answer->index_2 = weights[i];
      }
      Answer->index_1 = weights[i];
      Answer->index_2 = winner;
    }
  }
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{

  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1);  // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3);  // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4);  // {6, 2}

  return 0;
}
#endif
