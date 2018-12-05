/**********************************************************************************
 * 
 * You are given two linked lists representing two non-negative numbers. The
 * digits are stored in reverse order and each of their nodes contain a single
 * digit. Add the two numbers and return it as a linked list.
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) Output: 7 -> 0 -> 8
 * 
 **********************************************************************************/
/**
 * 
 * author : cjc
 * 2018 12 05 16:19
 * 
 */
class ListNode {
    private int val;
    private ListNode next;

    public ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }

    public void output() {
        System.out.println("this.val = " + this.val);
    }

    public ListNode getNext() {
        return this.next;
    }

    public void setNext(ListNode next) {
         this.next = next;
    }

    public int getVal() {
        return this.val;
    }
}

public class AddTwoNum {
    public ListNode addTwoNum(ListNode l1, ListNode l2) {
        ListNode h = null;
        ListNode forward = null;
        ListNode current = null;
        int sum=0, carry=0, x=0,y=0;

        while(l1 != null && l2 != null) {
            x = l1.getVal();
            y = l2.getVal();

            sum = carry + x + y;

           current = new ListNode(sum%10, null);
            if(h == null) {
                h = forward = current;
            } else {
                forward.setNext(current);
                forward = current;
            }
            carry = sum / 10;
            l1 = l1.getNext();
            l2 = l2.getNext();
        }
        return h;
    }

    public static void main(String[] args) {
        ListNode l1head = new ListNode(2, null); 
        ListNode l1sec = new ListNode(4, null);
        ListNode l1third = new ListNode(3, null);

        l1head.setNext(l1sec);
        l1sec.setNext(l1third);

        ListNode l2head = new ListNode(5, null);
        ListNode l2sec = new ListNode(6, null);
        ListNode l2third = new ListNode(4, null);

        l2head.setNext(l2sec);
        l2sec.setNext(l2third);

        AddTwoNum addTwoNum = new AddTwoNum();
        ListNode listNode =  addTwoNum.addTwoNum(l1head, l2head);
        addTwoNum.printlist(listNode);
        
    }

    public void printlist(ListNode head) {
        while(head != null) {
            head.output();
            head = head.getNext();
        }
    }
}