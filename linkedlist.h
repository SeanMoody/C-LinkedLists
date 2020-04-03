/*
 * File:    linkedlist.h
 * Author:  Sean Moody - 145584m@acadiau.ca
 * Date:    2020/04/03
 * Version: 1.0
 * Purpose:
 *      This file is the header file to implement a
 *      linked list in C
 */
#include <stdlib.h>
#include <stdio.h>

#ifndef LINKEDLIST
#define LINKEDLIST

#define MAX_NAME_LENGTH 50

//Create necessary datatypes (structs)
struct Datatype
{
    char name[MAX_NAME_LENGTH];
    int age;
};

typedef struct Node
{
    struct Node *next;
    struct Node *prev;
    int value;
    struct Datatype dt;
} NodeT, *NodeTP;

typedef struct
{
    struct Node *head;
    struct Node *tail;
    int count;
    struct Node *maxNode;
} ListT, *ListTP;

//Declare functions
int addToFront(ListTP list, int value, struct Datatype datatype);
int addToEnd(ListTP list, int value, struct Datatype datatype);
void traverseList(ListTP list);
void traverseListReverse(ListTP list);
void printMax(ListTP list);
void deleteHeadNode(ListTP list);
void deleteTailNode(ListTP list);
void deleteMaxNode(ListTP list);

#endif
