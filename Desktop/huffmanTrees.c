/*************************
* Jerrod Timmons
* CS315
* Huffman Tree
**************************/
/**************************************
* Program description:
*   This program will use the user's inputs
*   (character and frequencies) to create
*   a huffman tree and traverse the tree
*   both in order and preorder
**************************************/

/** INCLUDE DIRECTIVES ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool int

/******** STRUCTURES ********/

typedef struct nodeStructure
{
 char key;
 int frequency;
 struct nodeStructure *left, *right;
}treeItem;
typedef struct stack
{
 struct nodeStructure *t;
 struct stack *next;
} stackItem;

/**** FUNCTION PROTOTYPES ***/
void insertheap(treeItem **);
bool isempty (stackItem *);
void inorder(treeItem *);
void preorder (treeItem *);
void insertion(treeItem *[], int, int *, char, treeItem *, treeItem *);
void heapsort(treeItem *[], int);
treeItem *removal(treeItem *heap[], int *);

/*** MAIN FUNCTION *********/

int main ()
{
 treeItem *temp = NULL;
 treeItem *root;
 treeItem *heap[9] = {};
 char command = 'a';
 int frequency;
 int count = 1, *countptr = &count;

 while (command != '$'){
  printf("Enter a character (enter a '$' to quit entering characters): ");
  scanf(" %c", &command);

  if (command != '$'){
  printf("Enter '%c's frequency: ", command);
  scanf(" %d", &frequency);
  insertion(heap, frequency, countptr, command, NULL, NULL);
   }
 }

 while (heap[2] != NULL){
   root = malloc(sizeof(treeItem));
   root -> key = '-';

   /* pull from heap and set to children */
   root -> left = removal(heap, countptr);
   root -> right = removal(heap, countptr);
   root -> frequency = root -> right -> frequency;
   root -> frequency += root ->  left -> frequency;
   insertion(heap, root -> frequency, countptr, root -> key, root -> left, root -> right);
   }

inorder(heap[1]);
printf("\n");
preorder(heap[1]);
printf("\n");
}

struct nodeStructure *createNode(treeItem **newNode, int freq, char keyfunc){
  *newNode = malloc(sizeof(treeItem));
  (*newNode) -> left = NULL;
  (*newNode) -> right = NULL;
  (*newNode) -> frequency = freq;
  (*newNode) -> key = keyfunc;
  return *newNode;
  }

void heapsort(treeItem *array[], int sort){
 treeItem *temp = NULL;
 if (sort > 1)
     {
    while (sort != 1){
      if (array[sort] -> frequency < array[sort-1] -> frequency)
        {
         temp = array[sort];
         array[sort] = array[sort-1];
         array[sort-1] = temp;
        }
       sort--;
                 }
     }
 }
treeItem *removal(treeItem *arrayfunc[], int *count){

 treeItem *temp = arrayfunc[1];
 int remove;

 /*NO NOT START AT 1*/
 for (remove = 2; remove < 9; remove++){
   if(arrayfunc[remove] != NULL)
    {
     arrayfunc[remove-1] = arrayfunc[remove];
     arrayfunc[remove] = NULL;
    }
  }
  *count -= 1;
  return temp;
}

void insertion(treeItem *arrayfunc[], int freq, int *count, char value, treeItem *left, treeItem *right)
{

 treeItem *newNode = NULL;
 treeItem *temp;
 int insertion;

 /*creates node*/
 newNode = malloc(sizeof(treeItem));
 newNode -> key = value;
 newNode -> frequency = freq;
 newNode -> left = left;
 newNode -> right = right;

 /*if first value*/
 if (arrayfunc[1] == NULL)
   {
    arrayfunc[1] = newNode;
   }
 else
   {
    insertion = *count;
    arrayfunc[insertion] = newNode;
    while (insertion != 1 && arrayfunc[insertion] -> frequency < arrayfunc[insertion - 1] -> frequency){
            temp = arrayfunc[insertion - 1];
            arrayfunc[insertion - 1] = arrayfunc[insertion];
            arrayfunc[insertion] = temp;
            insertion--;
       }
   }
  *count += 1;
//requires *count-- either in function or after function is called.
}
void push (stackItem ** top, treeItem *funcNumber)
{
 stackItem *temp;
 temp = malloc(sizeof (stackItem));
 temp -> t = funcNumber;
 if (*top == NULL)
  {
   (*top) = temp;
   (*top) -> next = NULL;
  }
 else
  {
   temp -> next = *top;
   *top = temp;
  }
}
struct nodeStructure *pop (stackItem **top)
{
 stackItem *temp;
 temp = *top;
 
 if (temp != NULL)
   {
    if ((temp) -> next == NULL)
      {
       *top = NULL;
       return temp -> t;
      }
   else
      {
       (*top) = temp -> next;
       return temp -> t;
      }
   }
}
bool isempty (stackItem *top)
  {
   return (top == NULL)? 1:0;
  }
void inorder(treeItem *rootfunc)
{
 int done = 0;
 
 stackItem *stackStart = NULL;
 treeItem *trvPtr = rootfunc;
 printf("\nInorder traversal: \n");
 
 while (done == 0)
  {
   while (trvPtr != NULL)
  {
   if (trvPtr -> left != NULL)
     {
      push(&stackStart, trvPtr);
      trvPtr = trvPtr -> left;
     }
   else
     {
      printf("Key: %c Frequency: %d\n", trvPtr -> key, trvPtr -> frequency);
      trvPtr = trvPtr -> right;
     }
  }
 if (isempty (stackStart))
   done = 1;
 else
  {
   trvPtr = pop(&stackStart);
   printf("Key: %c Frequency: %d\n", trvPtr -> key, trvPtr -> frequency);
   trvPtr = trvPtr -> right;
  }
 } 
printf("\n");
}
void preorder(treeItem *rootfunc)
{
 int done = 0;
 
 stackItem *stackStart = NULL;
 treeItem *trvPtr = rootfunc;
 printf("\nPreorder traversal: \n");
 
 while (done == 0)
  {
   while (trvPtr != NULL)
  {
   printf("Key: %c Frequency: %d\n", trvPtr -> key, trvPtr -> frequency);
   if (trvPtr -> left != NULL)
     {
      push(&stackStart, trvPtr);
      trvPtr = trvPtr -> left;
     }
   else
     {
      trvPtr = trvPtr -> right;
     }
  }
 if (isempty (stackStart))
   done = 1;
 else
  {
   trvPtr = pop(&stackStart);
   trvPtr = trvPtr -> right;
  }
 } 
printf("\n");
}
void insertHeap(treeItem **heapnode){
 
}

