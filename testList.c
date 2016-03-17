// testList.c - testing DLList data type
// Written by John Shepherd, March 2013

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "DLList.h"

#define LAST_LINE 99999

static void addBeforeToEmptyListTest (DLList myList);
static void addAfterToEmptyListTest (DLList myList);
static void addBeforeToOneEltList (DLList myList);
static void addAfterToOneEltList (DLList myList);
static void showDetails (DLList myList);

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
   printf ("\nSTATE (1): Empty List.\n");


   addBeforeToEmptyListTest(myList);
    
    // Delete the only element and do everything again!
    printf ("\nDeleting current...\n");
    DLListDelete(myList);
    //showDetails (myList); Can't do this on empty list.
    
    // Now, same tests as above, but will add in second node.
    // Check that list is really empty and valid.
    printf ("\nSTATE (1): Empty List.\n");
    printf ("Check myList empty and valid...\n");
    assert (DLListIsEmpty(myList));
    assert (validDLList(myList));
    
    // Show list. Should be blank.
    printf ("Showing myList...\n");
    //showDLList(stdout,myList); Can't do this on empty list.
    
    // State (1): Empty list.
    addAfterToEmptyListTest(myList);
    
    // State (2): List with one node.
    printf ("\nState (2): List with one node.\n");
    
    // Check DLListBefore() one one node list.
    addBeforeToOneEltList (myList);

    // Make myList back to one node only.
    printf ("\nDeleting current...\n");
    DLListDelete(myList);
    showDetails (myList);

    // State (2): List with one node.
    printf ("\nState (2): List with one node.\n");
    
    // Check DLListAfter() on one node list.
    addAfterToOneEltList (myList);
    
    return EXIT_SUCCESS;

}

static void addBeforeToEmptyListTest (DLList myList) {
    printf ("\n\n Testing DLListBefore() on empty list.\n");

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
    char *str = "Line 1";
    printf ("Will insert ``%s``.\n", str);
    DLListBefore(myList, str);
    
    // Show the list.
    printf ("Showing myList...\n");
    showDLList(stdout, myList);
    
    // Check not empty.
    printf ("Check myList not empty...\n");
    assert (!DLListIsEmpty(myList));
    
    // See what's at current and first and last.
   showDetails(myList);
    
    
    // Finally, check if list is still sane/valid.
    printf ("Check myList is valid...\n");
    assert (validDLList(myList));
    
    printf ("DONE\n");

}

static void addAfterToEmptyListTest (DLList myList) {
    printf ("\n\n Testing DLListAfter() on empty list.\n");

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
    
    // Testing DLListAfter() (postpending).
    printf ("Using DLListAfter()...\n");
    char *str = "Line 1";
    printf ("Will insert ``%s``.\n", str);
    DLListBefore(myList, str);
    
    // Show the list.
    printf ("Showing myList...\n");
    showDLList(stdout, myList);
    
    // Check not empty.
    printf ("Check myList not empty...\n");
    assert (!DLListIsEmpty(myList));
    
    // See what's at current and first and last.
   showDetails(myList); 
    
    // Finally, check if list is still sane/valid.
    printf ("Check myList is valid...\n");
    assert (validDLList(myList));
    
    printf ("DONE\n");

}

static void addBeforeToOneEltList (DLList myList) {
    printf ("\n\n Testing DLListBefore() on list with one node.\n");

    // State (2): List with one node.
    // Check that list has one node and non-empty.
    printf ("STATE (2): List with One Node.\n");
    printf ("Check myList non-empty and valid...\n");
    assert (!DLListIsEmpty(myList));
    assert (validDLList(myList));
    assert (DLListLength(myList) == 1);
    
    
    // Now for the actual tests.
    // Show list. Should have "Line 1".
    printf ("Showing myList...\n");
    showDLList(stdout,myList);
    
    // Testing DLListBefore() (prepending).
    printf ("Using DLListBefore()...\n");
    char *str = "Line 2";
    printf ("Will insert ``%s``.\n", str);
    DLListBefore(myList, str);
    
    // Show the list.
    printf ("Showing myList...\n");
    showDLList(stdout, myList);
    
    // Check not empty and 2 nodes.
    printf ("Check myList not empty...\n");
    assert (!DLListIsEmpty(myList));
    printf ("Check two nodes...\n");
    assert (DLListLength(myList) == 2);
    
    // See what's at current and first and last.
   showDetails(myList);
    
    // Finally, check if list is still sane/valid.
    printf ("Check myList is valid...\n");
    assert (validDLList(myList));
    
    printf ("DONE\n");

}

static void addAfterToOneEltList (DLList myList) {
    printf ("\n\n Testing DLListAfter() on list with one node.\n");

    // State (2): List with one node.
    // Check that list has one node and non-empty.
    printf ("STATE (2): List with One Node.\n");
    printf ("Check myList non-empty and valid...\n");
    assert (!DLListIsEmpty(myList));
    assert (validDLList(myList));
    assert (DLListLength(myList) == 1);
    
    
    // Now for the actual tests.
    // Show list. Should have "Line 1".
    printf ("Showing myList...\n");
    showDLList(stdout,myList);
    
    // Testing DLListAfter() (postpending).
    printf ("Using DLListAfter()...\n");
    char *str = "Line 2";
    printf ("Will insert ``%s``.\n", str);
    DLListAfter(myList, str);
    
    // Show the list.
    printf ("Showing myList...\n");
    showDLList(stdout, myList);
    
    // Check not empty and 2 nodes.
    printf ("Check myList not empty...\n");
    assert (!DLListIsEmpty(myList));
    printf ("Check two nodes...\n");
    assert (DLListLength(myList) == 2);
    
   showDetails(myList);
    
    // Finally, check if list is still sane/valid.
    printf ("Check myList is valid...\n");
    assert (validDLList(myList));
    
    printf ("DONE\n");

}

static void showDetails (DLList myList) {
    // See what's at current and first and last and nitems.
    
    
    printf ("Current line:   ``%s``\n", DLListCurrent(myList));

   printf (" Showing list:\n");
   
   showDLList(stdout, myList);

    printf (" Total nodes:   %d\n", DLListLength(myList)); 
}

