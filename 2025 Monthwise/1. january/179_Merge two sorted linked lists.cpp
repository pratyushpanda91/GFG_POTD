class Solution {
  public:
    struct Node* sortedMerge(struct Node* head1, struct Node* head2) {
    // code here
       if(head1==NULL)
        {
            return head2;
        }
        
        if(head2==NULL)
        {
            return head1;
        }
        
        if(head1->data<head2->data)
        {
             head1->next=sortedMerge(head1->next,head2);
             return head1;
        }
        else
        {
            head2->next=sortedMerge(head2->next,head1);
            return head2;
        }
}
};
