/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    // if(head===null||head.next===null){
    //     return head
    // }
    // ***************
    // const res=reverseList(head.next)
    // head.next.next=head
    // head.next=null
    // ***************

    // ***************
    // let res=reverseList(head.next)
    // let tmp=res
    // while(tmp){
    //     if(!tmp.next){
    //         tmp.next=head
    //         tmp.next.next=null
    //         break
    //     }
    //     tmp=tmp.next
    // }
    // ***************

    // ***************
    let prev=null
    let cul=head
    while(cul){
        let nextTmp=cul.next
        cul.next=prev
        prev=cul
        cul=nextTmp
    }
    // ***************
    return prev
};