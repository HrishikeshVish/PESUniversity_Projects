#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct node *head = NULL;
struct node *current = NULL;
struct node {
   int key;
   struct node *next;
};

void printList();
void insertFirst(int);
struct node* deleteFirst();
bool isEmpty();
int length();
struct node* find(int);
struct node* delete(int);
int findLast();
int findMiddle();
int getSum();

void printList() {
        
        struct node *ptr = head;
        printf("\nElements of the list have been printed below:\n[ ");

        while(ptr != NULL) {
                printf("%d ",ptr->key);
                ptr = ptr->next;
        }

        printf("]");
}

void insertFirst(int key) {
        struct node *link = (struct node*) malloc(sizeof(struct node));

        link->key = key;

        link->next = head;

        head = link;
}

struct node* deleteFirst() {

        struct node *temp = head;

        head = head->next;

        return temp;
}

bool isEmpty() {
        return head == NULL;
}

int length() {
        int length = 0;
        struct node *current;

        for(current = head; current != NULL; current = current->next) {
                length++;
        }

        return length;
}

struct node* find(int key) {

        struct node* current = head;

        if(head == NULL) {
                return NULL;
        }

        while(current->key != key) {

                if(current->next == NULL) {
                        return NULL;
                } else {
                        current = current->next;
                }
        }

        return current;
}

struct node* delete(int key) {

        struct node* current = head;
        struct node* previous = NULL;

        if(head == NULL) {
                return NULL;
        }

        while(current->key != key) {

                if(current->next == NULL) {
                        return NULL;
                } else {
                        previous = current;
                        current = current->next;
                }
        }

        if(current == head) {
                head = head->next;
        } else {
                previous->next = current->next;
        }

        return current;
}

int findLast() {
	
	struct node *current;

        for(current = head; current != NULL; current = current->next);

        return current->key;
}

int findMiddle() {
	
	int i;
	struct node *current;

        for(i = 0, current = head; i < (int) (length()/2); i++, current = current->next);

        return current->key;
}

int getSum() {
	
	int sum = 0;
	struct node *current;

        for(current = head; current != NULL; current = current->next)
        sum += current->key;

        return sum;
}


main() {

	int choice, ele;

	while(1) {
	
	choice = 0;
	
	printf("\nEnter your choice:\n1. Insert an Element\n2. Delete an Element\n3. Find an Element\n   Or Don't...\n4. Find the length of the List\n5. Display the list\n6. Delete all elements\n7. Find Middle Element\n8. Find Last Element\n9. Find the sum of the list\n0. Exit\n\n");
	scanf("%d", &choice);
	
	switch(choice)
	{
	case 1: {
		printf("\nEnter the element to be inserted: ");
		scanf("%d", &ele);
		insertFirst(ele);
		printf("\nThe Element has been successfully inserted!\n");
		break;
		}
	case 2: {
		printf("\nEnter the element to be deleted: ");
		scanf("%d", &ele);
		delete(ele);
		printf("\nThe Element has been successfully deleted!\n");
		break;
		}
	case 3: {
		printf("\nEnter the element to be found: ");
		scanf("%d", &ele);
		struct node *foundLink = find(40);
		if(foundLink != NULL) {
                	printf("\nThe Element has been found: ");
                	printf("%d ",foundLink->key);
                	printf("\n");
        	} else {
                printf("\nThe Element could not be found.");
        	}
        	break;
        	}
        case 4: { printf("\nThe length of the list is: %d\n", length()); break; }
        case 5: { printList(); putchar('\n'); break; }
        case 6: {
        	while(!isEmpty()) {
                struct node *temp = deleteFirst();
                printf("\nDeleted value: ");
                printf("%d ",temp->key);
        	}
        	printf("\nAll the elements have been successfully deleted!\n");
        	break;
        	}
        case 7: { printf("\nThe middle element is: %d\n", findMiddle()); break; }
        case 8: { printf("\nThe last element is: %d\n", findLast()); break; }
        case 9: { printf("\nThe sum of the keys of the list is: %d\n", getSum()); break; }
        case 0: exit(0);
        default: printf("\nInvalid Option. Please try again!\n");
        }
}
}
/*
        insertFirst(10);
        insertFirst(20);
        insertFirst(30);
        insertFirst(1);
        insertFirst(40);
        insertFirst(56);

        printf("Original List: ");

        //print list
        printList();

        while(!isEmpty()) {
                struct node *temp = deleteFirst();
                printf("\nDeleted value:");
                printf("(%d) ",temp->key);
        }

        printf("\nList after deleting all items: ");
        printList();
        insertFirst(10);
        insertFirst(20);
        insertFirst(30);
        insertFirst(1);
        insertFirst(40);
        insertFirst(56);

        printf("\nRestored List: ");
        printList();
        printf("\n");

        struct node *foundLink = find(40);

        if(foundLink != NULL) {
                printf("Element found: ");
                printf("(%d) ",foundLink->key);
                printf("\n");
        } else {
                printf("Element not found.");
        }

        delete(40);
        printf("List after deleting an item: ");
        printList();
        printf("\n");
        foundLink = find(40);

        if(foundLink != NULL) {
                printf("Element found: ");
                printf("(%d) ",foundLink->key);
                printf("\n");
        } else {
                printf("Element not found.");
        }

        printf("\n");
*/
