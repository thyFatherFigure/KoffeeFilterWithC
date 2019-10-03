
/*
README
Author: Alexander Carlsson
Generated: 2019-09-04
Last updated: 2019-09-09

CircularList:
Implements a circular doublelinked CircularList object made up of a double linked list
made out of implemented Node objects.
Each node contains a gereric item.

Usage:
Use as object.
See functions for functions specific instructions.

Based on:
Stack.java, Java Generics Documentation
*/
import java.util.Iterator;
import java.util.NoSuchElementException;

public class CircularList<E> implements Iterable<E>{

	protected int size = 0;
	Node head = null;
	Node last = null;

	class Node {

		E item;
		Node next = null;
		Node prev = null;

		Node() {

		}
		Node(E item) {
			this.item = item;
		}

		/*
		toString
		DESCRIPTION:
			Returns the string representation of a Node
		PRECONDITIONS:
			n/a
		POSTCONDITIONS:
			n/a
		EXAMPLE:
			INPUT: new Node(5).toString();
			OUTPUT: [5],
		 */
		public String toString() {
			return "[" + item + "],";
		}

		/*
		addNodeBefore
			DESCRIPTION:
				Adds a node to the queue before chosen node instance
			PRECONDITIONS:
				Needs instanciated node.
			POSTCONDITIONS:
				n/a
			EXAMPLES:
				pre: fifoqueue = [1],[2],[3]
		  		INPUT: fifoQueue.head.addNode(Ö);
		  		OUTPUT: [Ö],[1],[2],[3],
		 */
		void addNodeBefore(Node node) {
			node.next = this;
			node.prev = this.prev;
			this.prev.next = node;
			this.prev = node;
		}
		/*
		addNodeAfter
			DESCRIPTION:
				Adds a node to the queue after chosen node instance
			PRECONDITIONS:
				Needs instanciated node.
			POSTCONDITIONS:
				n/a
			EXAMPLES:
				pre: fifoqueue = [1],[2],[3]
		  		INPUT: fifoQueue.head.addNode(Ö);
		  		OUTPUT: [1],[Ö],[2],[3],
		 */
		void addNodeAfter(Node node) {
			node.prev = this;
			this.next = node;
		}
	}
	/*
	  toString
	  	DESCRIPTION:
	  		Prints a string represetatione of the queue.
	  	PRECONDITIONS:
	  		Elements of queue are all Nodes
	  	POSTCONDITIONS:
	  		n/a
	  	EXAMPLES:
	  		pre: fifoqueue = [1],[2],[3]

	  		INPUT: sysout(fifoQueue.toString());
	  		OUTPUT: [1],[2],[3],

	  		pre: fifoqueue =

	  		INPUT: sysout(fifoQueue.toString());
	  		OUTPUT:
	 */
	public String toString() {
		if (size == 0) {
			return "";
		}
		if (head.next == last.next) {
			return head.toString();
		}

		head = head.next;
		String string = head.prev.toString() + toString();
		head = head.prev;

		return string;
	}

	/*
	 pushLast
	 	DESCRIPTION:
	 		Uses Node.addNode(Node) to add a node at the end of the queue.
	 	PRECONDITIONS:
	 		"last" is not empty
	 	POSTCONDITIONS:
	 		n/a
	 	EXAMPLE:
	 		pre: fifoqueue =

	  		INPUT: fifoQueue.pushLast(new Node(1));
	  		OUTPUT: [1],

	  		pre: fifoqueue = [1],

	  		INPUT: fifoQueue.pushLast(new Node(2));
	  		OUTPUT: [1],[2],
	 */
	public void pushLast(Node node) {

		if (size == 0) {
			head = node;
			last = node;

		} else {
			last.addNodeAfter(node);
			last = node;

		}

		last.next = head;
		head.prev = last;

		size++;
		System.out.println(toString());
	}
	/*
	 pushFirst
	 	DESCRIPTION:
	 		Uses Node.addNode(Node) to add a node at the beginning of the queue.
	 	PRECONDITIONS:
	 		"head" is not empty
	 	POSTCONDITIONS:
	 		n/a
	 	EXAMPLE:
	 		pre: fifoqueue =

	  		INPUT: fifoQueue.pushFirst(new Node(1));
	  		OUTPUT: [1],

	  		pre: fifoqueue = [1],

	  		INPUT: fifoQueue.pushFirst(new Node(2));
	  		OUTPUT: [2],[1],
	 */
	public void pushFirst(Node node) {

		if (size == 0) {
			head = node;
			last = node;

		} else {
			head.addNodeBefore(node);
			head = node;

		}
		last.next = head;
		head.prev = last;

		size++;
		System.out.println(toString());
	}
	/*
	emptyList
	DESCRIPTION:
		Empties the list and sets size to "0"
	PRECONDITIONS:
		n/a
	POSTCONDITIONS:
		n/a
	EXAMPLES:
		pre: queue = [1],[2],[3],[4],[5],[6]
			 size = 6
		INPUT: emptyList();
		OUTPUT:
		post: queue =
			  size = 0
	*/
	void emptyList() {
		head = null;
		last = null;

		size = 0;
		System.out.println(toString());


	}
	/*
	popFirst
	DESCRIPTION:
		Removes and returns the first node in the list. If the list only contains
		one element the list is properly emptied
	PRECONDITIONS:
		n/a
	POSTCONDITIONS:
		n/a
	EXAMPLES:
		pre: queue = [1],[2],[3],[4],[5],[6]
		INPUT: Node node = popFirst();
		OUTPUT:
		post: queue = [2],[3],[4],[5],[6]
			  node = [1]

	  	pre: queue = [1]
		INPUT: Node node = popFirst();
		OUTPUT:
		post: queue =
			  node = [1]

		pre: queue =
		INPUT: Node node = popFirst();
		OUTPUT: NoSuchElementException
				List is empty
	*/
	Node popFirst() {
		if (size <= 0) {
			throw new NoSuchElementException("List is empty");
		}

		Node temp = head;

		if(size == 1) {
			emptyList();
			return temp;
		}

		head = head.next;
		head.prev = last;
		last.next = head;

		size--;
		System.out.println(toString());

		return temp;
	}

	/*
	popLast
	DESCRIPTION:
		Removes and returns the last node in the list. If the list only contains
		one element the list is properly emptied
	PRECONDITIONS:
		n/a
	POSTCONDITIONS:
		n/a
	EXAMPLES:
		pre: queue = [1],[2],[3],[4],[5],[6]
		INPUT: Node node = popLast();
		OUTPUT:
		post: queue = [1],[2],[3],[4],[5]
			  node = [6]

	  	pre: queue = [1]
		INPUT: Node node = popLast();
		OUTPUT:
		post: queue =
			  node = [6]

		pre: queue =
		INPUT: Node node = popLast();
		OUTPUT: NoSuchElementException
				List is empty
	*/
	Node popLast() {
		if (size <= 0) {
			throw new NoSuchElementException("List is empty");
		}

		Node temp = last;

		if(size == 1) {
			emptyList();
			return temp;
		}
		last = last.prev;
		last.next = head;
		head.prev = last;

		size--;
		System.out.println(toString());

		return temp;
	}




	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CircularList<Character> queue = new CircularList<Character>();

		System.out.println("Prints during contruction/deconstruction");
		queue.pushLast(queue.new Node('2'));
		queue.pushLast(queue.new Node('3'));
		queue.pushFirst(queue.new Node('4'));
		queue.popFirst();
		queue.pushLast(queue.new Node('3'));
		queue.popLast();
		queue.popLast();
		queue.popLast();


		// list already empty
		queue.popLast();



		System.out.println("\nIterated prints");

		for(Character e : queue) {
			System.out.println(e);
		}

	}


	public Iterator<E> iterator() {
		return new LIterator();
	}


	public class LIterator implements Iterator<E> {
		boolean passedFirst = false;
		Node temp = head;

		public boolean hasNext() {

			if(head == null) {
				return false;
			}

			boolean	hasNext = (head != temp || passedFirst == false) ? true : false;

			return hasNext;
		}

		public E next() {

			head = head.next;

			if(head.prev == last) {
				passedFirst = true;
			}

			return head.prev.item;
		}


	}

}
