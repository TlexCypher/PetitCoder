#include "medium.h"
#include <stdio.h>
#include <stdlib.h>

struct ListNode *reverseBetween(struct ListNode *head, int left, int right) {
  struct ListNode *dummy =
      (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
  dummy->next = head;
  struct ListNode *prev_left = dummy;
  struct ListNode *left_node = dummy;
  struct ListNode *right_node = dummy;
  struct ListNode *next_right = dummy;
  for (int i = 0; i < left - 1; i++)
    prev_left = prev_left->next;
  for (int i = 0; i < left; i++)
    left_node = left_node->next;
  for (int i = 0; i < right; i++)
    right_node = right_node->next;
  for (int i = 0; i < right + 1; i++)
    next_right = next_right->next;
  struct ListNode *prev = NULL;
  struct ListNode *cur = left_node;
  for (int i = 0; i < (right - left + 1); i++) {
    struct ListNode *tmpNext = cur->next;
    cur->next = prev;
    prev = cur;
    cur = tmpNext;
  }
  prev_left->next = right_node;
  left_node->next = next_right;
  return dummy->next;
}
