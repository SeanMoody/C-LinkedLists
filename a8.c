/*
 * File:    a8.c
 * Author:  Sean Moody - 145584m@acadiau.ca
 * Date:    2020/04/03
 * Version: 1.0
 * Purpose:
 *      This file is the project file to create a linked
 *      list in C. 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

//Build the list struct with a constructor
void constructorListT(ListTP this)
{
    this->count = 0;
    this->maxNode = NULL;
    this->head = NULL;
    this->tail = NULL;
}

int main()
{
    //Variables
    char input[20];

    //List struct and pointer/constructor
    ListT list;
    constructorListT(&list);

    //Prompt user
    printf("\nWelcome to Sean Moody's Linked List Program\n");
    printf("Enter a command, or 'help' to list all commands\n\n");
    //Input loop
    while (1)
    {
        //Print list state after each update
        printf("List State:\n");
        if (list.count >= 1)
        {
            printf("Count: %d\n", list.count);
            printf("Head:\n");
            printf("Value %d - Name %s - Age %d\n", list.head->value, list.head->dt.name, list.head->dt.age);
            printf("Tail:\n");
            printf("Value %d - Name %s - Age %d\n", list.tail->value, list.tail->dt.name, list.tail->dt.age);
            printf("Max:\n");
            printf("Value %d - Name %s - Age %d\n\n", list.maxNode->value, list.maxNode->dt.name, list.maxNode->dt.age);
        }
        else
        {
            printf("Empty list\n\n");
        }
        //Take input
        scanf(" %s", input);

        //Determine input
        if ((strstr(input, "quit") || strstr(input, "exit")) == 1)
        {
            return EXIT_SUCCESS;
        }
        else if (strstr(input, "help") != NULL)
        {
            //Print help menu
            printf("Help Menu:\n\n");
            printf("'help'\nShows this menu.\n\n");

            printf("'quit' or 'exit'\nQuits the program.\n\n");

            printf("'add'\n");
            printf("Adds a node to the desired position.\n");
            printf("[positon]: F for front, or E for end.\n");
            printf("[name]: Person's Name. \n");
            printf("[age]: Person's Age. Enter as a number.\n");
            printf("[value]: Value to determine maximum. Enter as a number.\n\n");

            printf("'traverse'\n");
            printf("Traverses the list in the specified direction.\n");
            printf("[direction]: F for forward, or R for reverse\n\n");

            printf("'max'\nPrints the max node.\n\n");

            printf("'delete'\n");
            printf("Deletes the specified node\n");
            printf("[node]: H for head node, T for tail node, M for max node\n\n");
        }
        else if (strstr(input, "add") != NULL)
        {
            //Add a node to the list

            //Variables
            char position;
            char name[MAX_NAME_LENGTH];
            int age;
            int value;

            struct Datatype data;

            //Gather data for a node
            printf("\nAdding a node:\n");
            printf("Enter F to add to the front, or E to add to the end.\n");
            scanf(" %c", &position);
            printf("Enter a name.\n");
            scanf(" %50[^\n]", name);
            printf("Enter their age.\n");
            scanf(" %d", &age);
            printf("Enter their value.\n");
            scanf(" %d", &value);

            //Copy to datatype struct
            strcpy(data.name, name);
            data.age = age;

            //Determine if adding to front or back
            switch (position)
            {
            //Front
            case 'F':
            case 'f':
                if (addToFront(&list, value, data) == 0)
                {
                    printf("Add error, try again.\n");
                    return EXIT_FAILURE;
                }
                else
                {
                    printf("Node added.\n\n");
                }
                break;
            //End
            case 'E':
            case 'e':
                if (addToEnd(&list, value, data) == 0)
                {
                    printf("Add error, try again.\n");
                    return EXIT_FAILURE;
                }
                else
                {
                    printf("Node added.\n\n");
                }
                break;
            //Wrong position
            default:
                printf("Invalid position, try again\n");
            }
        }
        else if (strstr(input, "traverse") != NULL)
        {
            //Traverse List

            //Variables
            char direction;

            //Determine direction
            printf("Enter F to traverse forward, or R to traverse in reverse\n");
            scanf(" %c", &direction);

            switch (direction)
            {
            //Forward
            case 'F':
            case 'f':
                traverseList(&list);
                break;
            //Reverse
            case 'R':
            case 'r':
                traverseListReverse(&list);
                break;
            //Invalid
            default:
                printf("Invalid direction, try again\n");
            }
        }
        //Print max node in list
        else if (strstr(input, "max") != NULL)
        {
            printMax(&list);
        }
        else if (strstr(input, "delete") != NULL)
        {
            //Delete node
            char node;

            //Determine where to delete
            printf("Enter H for the head node, T for the tail node, M for the max node\n");
            scanf(" %c", &node);

            switch (node)
            {
            //Head
            case 'H':
            case 'h':
                deleteHeadNode(&list);
                break;
            //Tail
            case 'T':
            case 't':
                deleteTailNode(&list);
                break;
            //Max
            case 'M':
            case 'm':
                deleteMaxNode(&list);
                break;
            //Invalid
            default:
                printf("Invalid direction, try again\n");
            }
        }
    }
}
