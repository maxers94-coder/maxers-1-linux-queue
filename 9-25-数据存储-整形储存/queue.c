/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/

queue_t *q_new()
{
    /* Remember to handle the case if malloc returned NULL */
    /**/

    queue_t* q = (queue_t*)test_malloc(sizeof(queue_t));
    if (q != NULL)
    {
        q->head = NULL;
        q->tail = NULL;
        q->size = 0;
        return  q;
    }
    else
    {
        return NULL;
    }
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* Remember to free the queue structue and list elements */
    if (q != NULL)
    {
        list_ele_t* node = q->head;
        while (node != NULL)
        {
            list_ele_t* next = node->next;
            test_free(node);
            node= next;
        }
        test_free(q);
    }

}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    /* What should you do if the q is NULL? */
    /* What if malloc returned NULL? */
    if (q == NULL)
    {
        return false;
    }
    list_ele_t* front = (list_ele_t*)test_malloc(sizeof(list_ele_t));
    if(front==NULL)
    {
        return false;
    }
    else
    {
        front->value = v;
        front->next=q->head;
        q->head=front;
        q->size++;
        return true;
    }
    
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
    /* Remember: It should operate in O(1) time */
    if (q == NULL)
    {
        return false;
    }
    list_ele_t* real = (list_ele_t*)test_malloc(sizeof(list_ele_t));
    if (real != NULL)
    {
        real->value = v;
        real->next=NULL;
        if(q->head==NULL)
        {
            q->head=real;
            q->tail=real;
        }
        else
        { 
            q->tail->next=real;
            q->tail=real;
        }
       
        q->size++;
        return true;
    }
    else
    {
        return false;
    }

   
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
    if (q == NULL)
    {
        return false;
    }

    if (q->head == NULL)
    {
        return false;
    }
    else
    {
        if (vp != NULL)
        {
            *vp = q->head->value;
        }
        list_ele_t* front = q->head->next;
        test_free(q->head);
        q->head = front;
        q->size--;
        return true;
    }
   
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* Remember: It should operate in O(1) time */
    /*if (q == NULL )
    {
        return 0;
    }
    else
    {
       
        list_ele_t* node = q->head;
        while (node != NULL)
        {
             list_ele_t* next = node->next;
             q->size++;
             node = next;
        }
        return q->size;
        
    }*/
   return q?q->size:0;
    
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
    if (q != NULL&&q->head!=NULL)
    {
        list_ele_t* pointpre = NULL;
        list_ele_t* pointnow = q->head;
        list_ele_t* pointnex=NULL;
        list_ele_t* pointold=q->head;

        while (pointnow!= NULL)
        {
            pointnex=pointnow->next;
            pointnow->next = pointpre;
            pointpre = pointnow;
            pointnow =pointnex;
        }
    
        q->head=pointpre;
        q->tail=pointold;
    }
}

