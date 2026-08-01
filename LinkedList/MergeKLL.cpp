class Solution{
    public:                         
ListNode* Merge(ListNode* a, ListNode* b) {
    ListNode* result = NULL;
    if (a == NULL) return b;
    else if (b == NULL) return a;

    if (a->val <= b->val) {
        result = a;
        result->next = Merge(a->next, b);
    } else {
        result = b;
        result->next = Merge(a, b->next);
    }
    return result;
}

ListNode* mergeKLists(vector<ListNode*>& arr) {
    if (arr.empty()) return NULL;
    int i = 0;
    int last = arr.size() - 1;
    int j;

    while (last != 0) {
        i = 0;
        j = last;
        while (i < j) {
            arr[i] = Merge(arr[i], arr[j]);
            i++;
            j--;
            if (i >= j) {
                last = j;
            }
        }
    }
    return arr[0];
}
};