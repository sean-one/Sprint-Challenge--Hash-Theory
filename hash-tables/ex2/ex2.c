#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));

  // YOUR CODE HERE
  // create a counter for routes
  int route_count = 0;
  // create starting point
  char *start_source = "NONE";

  // iterate through tickets
  for (int i = 0: i < tickets->capacity; i++) {
    // create current pair
    LinkedPair *current_ticket = create_pair(tickets[i]->source, tickets[i]->destination);

    // compare start with current start
    if (strcmp(current_ticket->key, start_source) != 0) {
      // hash the current key
      int hashed = hash(current_ticket->key, ht->capacity);
      // check the ht for the current
      int hash_check = hash_table_retrieve(ht, current_ticket->key);
      if (hash_check < 0) {
        hash_table_insert(ht, current_ticket->key, current_ticket->value);
      } else { // if it is in the ht grab it and update start
        

      }


    }
  }
  

  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}



#ifndef TESTING
int main(void)
{
  // Short test
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  print_route(reconstruct_trip(tickets, 3), 3); // PDX, DCA, NONE

  return 0;
}
#endif
