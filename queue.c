#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    /* TODO: What if malloc returned NULL? */
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* TODO: How about freeing the list elements and the strings? */
    list_ele_t *node;
    for (node = q->head; node != NULL;) {
        list_ele_t *tmp = node;
        node = node->next;
        free(tmp->value);
        free(tmp);
    }
    /* Free queue structure */
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;
    /* TODO: What should you do if the q is NULL? */
    /* return fasle if q is NULL*/
    if (!q)
        return false;
    newh = malloc(sizeof(list_ele_t));
    /* Don't forget to allocate space for the string and copy it */
    /* return fasle if newh is NULL*/
    if (!newh)
        return false;
    newh->value = (char *) malloc(sizeof(char) * (strlen(s) + 1));
    if (!newh->value) {
        free(newh);
        return false;
    }
    /* What if either call to malloc returns NULL? */
    /* initialize value of newh*/
    strncpy(newh->value, s, strlen(s));
    newh->value[strlen(s)] = 0;
    newh->next = q->head;
    q->head = newh;
    if (!q->tail)
        q->tail = newh;
    ++(q->size);
    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    list_ele_t *newh;
    /* TODO: What should you do if the q is NULL? */
    /* return fasle if q is NULL*/
    if (!q)
        return false;
    newh = malloc(sizeof(list_ele_t));
    /* Don't forget to allocate space for the string and copy it */
    /* return fasle if newh is NULL*/
    if (!newh)
        return false;
    newh->value = (char *) malloc(sizeof(char) * (strlen(s) + 1));
    if (!newh->value) {
        free(newh);
        return false;
    }
    /* What if either call to malloc returns NULL? */
    /* initialize value of newh*/
    strncpy(newh->value, s, strlen(s));
    newh->value[strlen(s)] = 0;
    newh->next = NULL;
    if (q->size == 0) {
        q->tail = q->head = newh;
    } else {
        q->tail->next = newh;
        q->tail = newh;
    }
    ++(q->size);
    return true;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    list_ele_t *tmp;
    size_t len;
    /* return false if q is NULL or q->head is NULL */
    if (!q || q->size == 0)
        return false;
    tmp = q->head;
    /* copy q->head value into buffer */
    len = strlen(tmp->value) > bufsize ? bufsize - 1 : strlen(tmp->value);
    strncpy(sp, tmp->value, len);
    sp[len] = 0;
    tmp = q->head;
    q->head = q->head->next;
    if (q->size == 1)
        q->tail = NULL;
    --(q->size);
    free(tmp->value);
    free(tmp);
    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    /* TODO: Remove the above comment when you are about to implement. */
    return q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
