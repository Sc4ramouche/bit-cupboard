function ListNode(val = 0, next = null) {
  this.val = val;
  this.next = next;
}

function mergeTwoLists(l1, l2) {
  if (l1 === null) return l2;
  if (l2 === null) return l1;

  const l1Tail = l1.next;
  const l2Tail = l2.next;

  return new ListNode(
    Math.min(l1.val, l2.val),
    new ListNode(Math.max(l1.val, l2.val), mergeTwoLists(l1Tail, l2Tail))
  );
}

// const l1 = arrayToLinkedList([1, 2, 4, 5, 6, 7]);
// const l2 = arrayToLinkedList([1, 3, 4]);
const l1 = arrayToLinkedList([5]);
const l2 = arrayToLinkedList([1, 2, 4]);

function arrayToLinkedList(elements) {
  if (elements.length === 0) return null;

  return new ListNode(elements[0], arrayToLinkedList(elements.slice(1)));
}

function printLinkedList(list) {
  if (list === null) return;

  console.log(list.val);
  printLinkedList(list.next);
}

printLinkedList(mergeTwoLists(l1, l2));
