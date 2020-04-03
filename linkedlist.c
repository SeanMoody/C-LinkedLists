/*
 * File:    linkedlist.c
 * Author:  Sean Moody - 145584m@acadiau.ca
 * Date:    2020/04/03
 * Version: 1.0
 * Purpose:
 *      This file is the implementation file to implement a
 *      linked list in C
 */

//Libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

//Add new node to front of list
int addToFront(ListTP list, int value, struct Datatype datatype)
{
    //Create and initialize node
    NodeTP node = malloc(sizeof(NodeT));
    node->next = NULL;
    node->prev = NULL;
    node->dt = datatype;
    node->value = value;

    //Empty list
    if (list->count == 0)
    {
        //Set initial values to node
        list->head = node;
        list->tail = node;
        list->count++;
        list->maxNode = node;

        return 1;
    }
    //List with one element
    else if (list->count == 1)
    {
        //Set head to node, and transfer other nodes
        list->head = node;
        node->next = list->tail;
        list->tail->prev = node;
        //Check for maxNode
        if (list->maxNode->value < value)
        {
            list->maxNode = node;
        }
        list->count++;

        return 1;
    }
    else
    {
        //Lots of nodes in list
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
        //Check for maxNode
        if (list->maxNode->value < value)
        {
            list->maxNode = node;
        }
        list->count++;

        return 1;
    }
}

//Add new node to end of list
int addToEnd(ListTP list, int value, struct Datatype datatype)
{
    //Create and initialize node
    NodeTP node = malloc(sizeof(NodeT));
    node->next = NULL;
    node->prev = NULL;
    node->dt = datatype;
    node->value = value;

    //Empty list
    if (list->count == 0)
    {
        list->head = node;
        list->tail = node;
        list->count++;
        list->maxNode = node;

        return 1;
    }
    //List with one element
    else if (list->count == 1)
    {
        list->tail = node;
        node->prev = list->head;
        list->head->next = node;
        //Check for maxNode
        if (list->maxNode->value < value)
        {
            list->maxNode = node;
        }
        list->count++;

        return 1;
    }
    else
    {
        //Lots of nodes in list
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
        //Check for maxNode
        if (list->maxNode->value < value)
        {
            list->maxNode = node;
        }
        list->count++;

        return 1;
    }
}

//Traverse list from head to tail
void traverseList(ListTP list)
{
    //Empty list
    if (list->count == 0)
    {
        printf("The list is empty.\n\n");
        return;
    }
    NodeTP node = list->head;

    //Prompt user and traverse
    printf("Traversing the list from head to tail:\n");
    while (node != NULL)
    {
        //Print current node
        printf("Node:\n");
        printf("Value: %d - Name: %s - Age: %d\n\n", node->value, node->dt.name, node->dt.age);
        node = node->next;
    }
}

//Traverse list from tail to head
void traverseListReverse(ListTP list)
{
    if (list->count == 0)
    {
        printf("The list is empty.\n\n");
        return;
    }
    NodeTP node = list->tail;

    //Prompt and traverse
    printf("Traversing the list from tail to head:\n");
    while (node != NULL)
    {
        //Print current node
        printf("Node:\n");
        printf("Value: %d - Name: %s - Age: %d\n\n", node->value, node->dt.name, node->dt.age);
        node = node->prev;
    }
}

void printMax(ListTP list)
{
    //Empty list
    if (list->count == 0)
    {
        printf("The list is empty.\n\n");
        return;
    }
    //Print max node values
    printf("The max node in the list of a count of %d has:\n", list->count);
    printf("A value of: %d\n", list->maxNode->value);
    printf("And contains %s, age %d\n\n", list->maxNode->dt.name, list->maxNode->dt.age);
}

//Delete (replace) head node
void deleteHeadNode(ListTP list)
{
    if (list->count == 0)
    {
        printf("Cannot delete from an empty list.\n\n");
        return;
    }
    //Get node to delete
    NodeTP node = list->head;

    //If only one, then we only need to reinit
    if (list->count == 1)
    {
        //Reinitialize list
        list->count = 0;
        list->maxNode = NULL;
        list->head = NULL;
        list->tail = NULL;
    }
    //Remove head node and reset other nodes
    else
    {
        list->head = node->next;
        list->count--;
        list->head->prev = NULL;

        //Check for maxNode if we are deleting the maxNode
        if (list->maxNode == node)
        {
            int maxValue = 0;
            NodeTP travNode = list->head;

            while (travNode != NULL)
            {
                if (travNode->value > maxValue)
                {
                    maxValue = travNode->value;
                    list->maxNode = travNode;
                }
                travNode = travNode->next;
            }
        }
    }
}

//Delete (replace) tail node
void deleteTailNode(ListTP list)
{
    if (list->count == 0)
    {
        printf("Cannot delete from an empty list.\n\n");
        return;
    }
    NodeTP node = list->tail;

    if (list->count == 1)
    {
        //Reinitialize list
        list->count = 0;
        list->maxNode = NULL;
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        //Set values appropriately
        list->tail = node->prev;
        list->count--;
        list->tail->next = NULL;

        //Search for new maxNode
        if (list->maxNode == node)
        {
            int maxValue = 0;
            NodeTP travNode = list->head;

            while (travNode != NULL)
            {
                if (travNode->value > maxValue)
                {
                    maxValue = travNode->value;
                    list->maxNode = travNode;
                }
                travNode = travNode->next;
            }
        }
    }
}

//Delete (replace) max node
void deleteMaxNode(ListTP list)
{
    if (list->count == 0)
    {
        printf("Cannot delete from an empty list.\n\n");
        return;
    }
    NodeTP node = list->maxNode;

    if (list->count == 1)
    {
        //Reinitialize list
        list->count = 0;
        list->maxNode = NULL;
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        //If we're the head node, just call deleteHeadNode
        if (list->head == node)
        {
            deleteHeadNode(list);
            return;
        }
        else if (list->tail == node)
        {
            //Same if we're the tail node
            deleteTailNode(list);
            return;
        }
        else
        {
            //Middle somewhere, set values appropriately
            NodeTP before = node->prev;
            NodeTP after = node->next;
            before->next = after;
            after->prev = before;

            //Search for new maxNode
            int maxValue = 0;
            NodeTP travNode = list->head;

            while (travNode != NULL)
            {
                if (travNode->value > maxValue)
                {
                    maxValue = travNode->value;
                    list->maxNode = travNode;
                }
                travNode = travNode->next;
            }
            //Decrement count
            list->count--;
        }
    }
}
