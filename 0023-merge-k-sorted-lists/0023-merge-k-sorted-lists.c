/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* new_head=NULL;
    struct ListNode* tail=NULL;

    if (list1 == NULL){
        return list2;
    }
    if(list2 == NULL){
        return list1;
    }

    while(list1 != NULL && list2 != NULL){
        if(list1->val < list2->val){
            //add_with_tail(&new_head,&tail,list1->val);
            if (new_head == NULL){
                new_head = list1;
                tail = new_head;
            }else{
                tail->next = list1;
                tail = list1;
            }
            list1 = list1->next;
        }else{
            //add_with_tail(&new_head,&tail,list2->val);
            if (new_head == NULL){
                new_head = list2;
                tail = new_head;
            }else{
                tail->next = list2;
                tail = list2;
            }
            list2 = list2->next;
        }
    }
    
    if(list1 != NULL){
        tail->next=list1;
    }
    if(list2 != NULL){
        tail->next=list2;
    }
    
    return new_head;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize <= 0){
        return NULL;
    }
    struct ListNode *head = lists[0];
    struct ListNode *temp_list_head = *lists;

    for(int i = 1; i < listsSize;i++){
        head = mergeTwoLists(head,lists[i]);
    }
    return head;
}