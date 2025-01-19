class Solution {
  public:
    Node* rotate(Node* head, int k) {
        Node*temp = head;
        int n = 0;
        while(true){
            if(temp->next){
                temp = temp->next;
            }
            else{
                temp->next = head;
                n++;
                break;
            }
            n++;
        }
        Node*prev = temp;
        temp = head;
        k%=n;
        while(k > 0){
            prev = temp;
            temp = temp->next;
            k--;
        }
        if(prev){
            prev->next = nullptr;
        }
        return temp;
    }
};
