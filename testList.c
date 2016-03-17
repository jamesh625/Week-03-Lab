// testList.c - testing DLList data type
// Written by John Shepherd, March 2013

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "DLList.h"

int main(int argc, char *argv[])
{
    DLList myList;
    myList = getDLList(stdin);
    showDLList(stdout,myList);
    assert(validDLList(myList));

    // Our tests.
    
    // First thing, create an empty list by freeing myList.
    free(myList);
    
    // Now reinitialise myList.
    myList = newDLList();
    // Check that list is really empty.
    assert (DLListIsEmpty(myList));
    
    
    return EXIT_SUCCESS;
}
