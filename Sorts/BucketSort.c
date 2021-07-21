#include <stdio.h>
#include <stdlib.h>

struct Node {

	int data;
	struct Node* next;
};

struct Queue {
	
	struct Node* head;
	struct Node* tail;
};

typedef struct Node Node;
typedef struct Queue Queue;

Node* new_node() {

    Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = 0;
    newNode->next = NULL;
        
    return newNode;
} // end of constructor for struct Node


//  
//  Functions of Queue
//  

Queue* new_queue() {
	
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));

	newQueue->head = NULL;
	newQueue->tail = NULL;

	return newQueue;
} // end of constructor for struct Queue

int is_queue_empty(Queue *queue) { return (queue->head == NULL); }

void enqueue(Queue* queue, int value) {

	Node *node = new_node();
	node->data = value;

	if (is_queue_empty(queue)) { queue->head = node; }
	else { (queue->tail)->next = node; }

	queue->tail = node;
} // end of enqueue(Queue*, int)

int dequeue(Queue* queue) {

	if (is_queue_empty(queue)) { return 0; }

	int value = (queue->head)->data;

	Node *node = queue->head;
	queue->head = (queue->head)->next;

	if (queue->head == NULL) { queue->tail = NULL; } // resolving dangling pointer

	free(node);

	return value;
} // end of dequeue(Queue*)

void display_queue(Queue *queue) {

	if (is_queue_empty(queue)) {
		
		printf("Queue is empty");
		return;
	}

	Node *ptr;
	for (ptr = queue->head; ptr != queue->tail; ptr = ptr->next) { printf("%d, ", ptr->data); }
	printf("%d", ptr->data);
} // end of display_queue(Queue*)


struct BucketChain {
	
	int length;
	Queue** chain;
};

typedef struct BucketChain BucketChain;


//
//  Functions of BucketChain
//

BucketChain* new_bucketchain(int length) {
	
	BucketChain* newBucketChain = (BucketChain*)malloc(sizeof(BucketChain));
	
	newBucketChain->length = length;
	newBucketChain->chain = (Queue**)malloc(length * sizeof(Queue*));

	int i;
	for (i = 0; i < length; i++) { 
		*(newBucketChain->chain + i) = new_queue(); 
	}

	return newBucketChain;
} // end of constructor of struct BucketChain

void display_bucketchain(BucketChain* bucketchain) {

	int i;
	for (i = 0; i < bucketchain->length; i++) {

		printf("bucket %d: ", i);
		display_queue(*(bucketchain->chain + i));
		printf("\n");
	}
} // end of display_bucketchain(BucketChain*)

void export_bucketchain_to_array(BucketChain* bucketchain, int *arr) {

	int chain_i = 0, arr_i = 0;
	Queue *queue;

	for (; chain_i < bucketchain->length; chain_i++) {

		queue = *(bucketchain->chain + chain_i);

		while (!is_queue_empty(queue)) {

			*(arr + arr_i++) = dequeue(queue);
		}
	} // end of outer for loop

} // end of export_bucketchain_to_array(BucketChain*, int*)


//
//  Functions regarding array
//

void input_array(int* arr, int length) {

	int i;
	for (i = 0; i < length; i++) { 
		scanf("%d", (arr + i)); 
	}
} // end of input_array(int*, int)

void display_array(int* arr, int length) {

	int i;
	for (i = 0; i < length; i++) { 
		printf("%d ", *(arr + i)); 
	}
} // end of input_array(int*, int)

int get_max_in_array(int *arr, int length) {

	int max = *arr;
	int i;

	for (i = 1; i < length; i++) {

		if (max < *(arr + i)) {
			max = *(arr + i);
		}
	}

	return max;
} // end of get_max_in_array(int*, int)


//
//  Utility functions
//

int count_digits(int number) {

	int count = 0;
	
	while (number != 0) { 
		
		number /= 10;
		count++;
	}

	return count;
} // end of count_digits(int)


//
//  Functions regarding bucket sort
//

void bucket_sort(int* arr, int length) {

	BucketChain *bucketchain = new_bucketchain(10); // because we are working with decimal numbers

	int n_passes = 	count_digits(get_max_in_array(arr, length));
	int divisor = 10, digit;
	int pass, i;

	for (pass = 0; pass < n_passes; pass++) {

		for (i = 0; i < length; i++) {

			digit = (*(arr + i) % divisor) / (divisor / 10);
			enqueue(*(bucketchain->chain + digit), *(arr + i));
		} // end of inner for loop
		
		export_bucketchain_to_array(bucketchain, arr);

		printf("Array after pass %d: ", (pass + 1));
		display_array(arr, length);
		printf("\n");

		divisor *= 10;
	} // end of outer for loop

} // end of bucket_sort(int*, int)


int main() {

	int length;
	printf("Enter the number of integers: ");
	scanf("%d", &length);

	int *arr;
	printf("Enter elements in array: ");
	input_array(arr, length);

	printf("\nInitial array: ");
	display_array(arr, length);
	printf("\n");

	printf("\n");
	bucket_sort(arr, length);

	printf("\nFinal array after sorting: ");
	display_array(arr, length);
	printf("\n");

	return 0;
} // end of main()
