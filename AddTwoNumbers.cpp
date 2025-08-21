/*given two non-empty linked lists representing two non-negative integers and the digits are stored in reverse order,
and each of their nodes contains a single digit, add the two numbers and return the sum as a linked list.*/

#include <iostream>
using namespace std;

/*Approach:
use a duumy head node to simlify the linked list operations.
Traverse both linked lists simultaneously, adding corresponding digits.
Maintain a carry for cases where the sum of digits exceedes 9.
In case of a remaining carry , add another node.
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyHead = new ListNode(0); // Dummy node to Simplify operations.
        ListNode *current = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int sum = carry; // Start with the carry from the previous step.

            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;                       // Update carry for the next iteration.
            current->next = new ListNode(sum % 10); // Store the digit.
            current = current->next;                // Move to the next node.
        }

        return dummyHead->next; // Return the head of the resulting list.
    }
};

// Function that will print the linked list:
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << "->";
        head = head->next;
    }

    cout << endl;
}

// Helper function to create a linked list from an array:
ListNode *createList(int arr[], int size)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;

    for (int i = 1; i < size; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Main function to test the solution:
int main()
{
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};

    ListNode *l1 = createList(arr1, 3);
    ListNode *l2 = createList(arr2, 3);

    Solution sol;
    ListNode *result = sol.addTwoNumbers(l1, l2);

    cout << "result: ";
    printList(result);
    return 0;
}