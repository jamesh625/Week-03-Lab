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
    printf("\n\nStarting our tests.\n\n");
    // First thing, create an empty list by freeing myList.
    printf ("Freeing myList...\n");
    free(myList);
    
    // Now reinitialise myList.
    printf ("Reinitialising myList...\n");
    myList = newDLList();
    
    // State (1): Empty list.
    // Check that list is really empty and valid.
    printf ("STATE (1): Empty List.\n");
    printf ("Check myList empty and valid...\n");
    assert (DLListIsEmpty(myList));
    assert (validDLList(myList));
    
    // Now for the actual tests.
    // Show list. Should be blank.
    printf ("Showing myList...\n");
    showDLList(stdout,myList);
    
    // Testing DLListBefore() (prepending).
    printf ("Using DLListBefore()...\n");
    DLListBefore(myList, "Line 1");
    
    // Show the list.
    printf ("Showing myList...\n");
    showDLList(stdout, myList);
    
    // Check not empty.
    printf ("Check myList not empty...\n");
    assert (!DLListIsEmpty(myList));
    
    // See what's at current and first and last.
    printf ("Current line:   %s\n", DLListCurrent(myList));
    DLListMoveTo(myList, 1);
    //printf ("  First line:   %s\n", DLListCurrent(myList));
    DLListMoveTo(myList, LAST_LINE);
    //printf ("   Last line:   %s\n", DLListCurrent);
    
    
    // Finally, check if list is still sane/valid.
    assert (validDLList(myList));
    
    return EXIT_SUCCESS;

}
