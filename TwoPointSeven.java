
/*
README
Author: Alexander Carlsson
Generated: 2019-09-06
Last updated: 2019-09-17

OrderedQueue:
Implements an OrderedQueue object based on CircularQueue.
Queue adds elements in and ordered order where each node contains an int item.

Usage:
Use as object.
See functions for function-specific instructions.

Based on:
OrderedQueue.java
*/

public class TwoPointSeven extends CircularList<Integer> {

	/*
	recursivePush
	DESCRIPTION:
		Recursively looks thorugh the list and adds the node
		ordered according to it's item value
	PRECONDITIONS:
		head != null
	POSTCONDITIONS:
		n/a
	EXAMPLES:
		pre: queue = [1],[2],[4],[5],[6]
		INPUT: recursivePush(queue.new Node(3));
		OUTPUT:
		post: queue = [1],[2],[3],[4],[5],[6]

		pre: queue = [1],[2],[4],[5],[6]
		INPUT: recursivePush(queue.new Node(4));
		OUTPUT:
		post: queue = [1],[2],[4],[4],[5],[6]

		pre: queue =
		INPUT: recursivePush(queue.new Node(4));
		OUTPUT: NullPointerException
	*/
	void recursivePush(Node node) {
		if(node.item < head.item) {

			head.addNodeBefore(node);

			return;
		}

		head = head.next;
		recursivePush(node);
		head = head.prev;
	}

	/*
	push
	DESCRIPTION:
		Adds node to list in ascending order according to the node item.
		This is partly achieved recusively with recusivePush
	PRECONDITIONS:
		n/a
	POSTCONDITIONS:
		n/a
	EXAMPLES:
		pre: queue = [1],[2],[4],[5],[6]
		INPUT: push(queue.new Node(3));
		OUTPUT:
		post: queue = [1],[2],[3],[4],[5],[6]

		pre: queue = [1],[2],[4],[5],[6]
		INPUT: push(queue.new Node(1));
		OUTPUT:
		post: queue = [1],[1],[2],[3],[4],[5],[6]

		pre: queue =
		INPUT: push(queue.new Node(4));
		OUTPUT:
		post: queue = [4],
	*/
	void push(Node node) {
		if(size == 0) {
			pushFirst(node);
			return;
		}

		if(node.item > last.item) {
			pushLast(node);
			return;
		}

		if(node.item < head.item) {
			pushFirst(node);
			return;
		}

		Node temp = head;
		recursivePush(node);
		head = temp;
		System.out.println(toString());
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TwoPointSeven queue = new TwoPointSeven();

		queue.push(queue.new Node(5));
		queue.push(queue.new Node(6));
		queue.push(queue.new Node(7));
		queue.push(queue.new Node(10));
		queue.push(queue.new Node(4));
		queue.push(queue.new Node(9));
		queue.push(queue.new Node(3));
		queue.push(queue.new Node(8));



		queue.push(queue.new Node(3));
		queue.push(queue.new Node(7));
		queue.push(queue.new Node(2));
		queue.push(queue.new Node(9));


	}

}
