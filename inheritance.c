// Simulate genetic inheritance of blood type
#define _DEFAULT_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    person *n=malloc(sizeof(person));
    // Generation with parent data
    if (generations > 1)
    {
        // TODO: Recursively create blood type histories for parents
        if(generations == 3)
        {

          //check if the memory is free
          if (n == NULL)
          {
            return 1;
          }

          //create a linked list
          person *parent_generations = NULL;
          //clear the pointer of garbage values
          n->parents[0] = NULL;
          //assign &n to the list
          n = parents[0];
          // point the list to n
          parent_generations = n;
          return *create_family(int generations-1);
        }
        else if (generations == 2)
        {

          // check for error, if yes free the list and return
          if (n== NULL)
          {
              free(parent_generations);
              return 1;
          }

          // clear the pointer of garbage values
          n->parents[0] = NULL;
          // set the value in n
          n = parents[0];
          // point to the second generation in our list
          parent_generations->parent[0]=n;
          //recursively create another generation
          return *create_family(int generations-1);
        }
        // TODO: Randomly assign child alleles based on parents
    }

    // Generation without parent data
    else
    {

        if (n == NULL)
        {
           free(parent_generations->parent[0]);
           free(parent_generations);
           return 1;
        }
        // TODO: Set parent pointers to NULL
        n->parents[0] = NULL;
        //ASK YOURSELF IF YOU NEED TO INITIALIZE POINTERS TO parent[1] OR ONLY parent [0]

        // TODO: Randomly assign alleles
        // ARRAY of alleles
        possible_alleles[]={A, B, O};
        n->alleles[0]=possible_alleles[rand() % 3];
        n->alleles[1]=possible_alleles[rand() % 3];
        parent_generations->parent[0]->parent[0]=n;
        //create a variable that assigns a allele to a parent

    }
    printf("%p\n", parent_generations->parent[0]);
    printf("%p\n", parent_generations->parent[1]);
    for (node *tmp=parent_generations; tmp != NULL; tmp=tmp->parent[0])
    {
        printf("%p\n", parent_generations->parent[0]);
    }
    // TODO: Return newly created person
    return *parent_generations->parent[0]->parent[0];
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: Handle base case
    while(parent_generations != NULL)
    {
    person *tmp = parent_generations->parent[0];
    // TODO: Free parents
    free(parent_generations);
    // TODO: Free child
    parent_genrations=tmp;
    }
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
