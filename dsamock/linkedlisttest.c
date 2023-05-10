#include "linkedlist.h"
#include "process.h"
#define SIZE 5
#include <stdio.h>

int main()
{
    // use constructs used in linkedlist.h to test the functions
    // in linkedlist.c
    process_linked_list *list = create_empty_process_linked_list();
    process p1 = {"p1", 1, 0, 8, 0, 0, 8};
    process p2 = {"p2", 2, 1, 4, 0, 0, 4};
    process p3 = {"p3", 3, 4, 9, 0, 0, 9};
    process p4 = {"p4", 4, 2, 5, 0, 0, 5};
    process p5 = {"p5", 5, 3, 2, 0, 0, 2};

    add_first_to_linked_list(list, p1);
    add_first_to_linked_list(list, p2);
    add_at_index_linked_list(list, 2, p3);
    add_last_to_linked_list(list, p4);
    add_last_to_linked_list(list, p5);

    remove_first_linked_list(list, &p1);
    remove_last_linked_list(list, &p1);
    print_linked_list(list);


    // you can add more tests here
    return 0;
}