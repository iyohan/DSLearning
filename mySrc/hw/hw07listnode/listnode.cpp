/*
On my honor, I pledge that I have neither received nor provided improper assistance in
the completion of this assignment.
Signed: John Lee    Section: 02    Student Number: 21800815
*/

//  listnode.cpp
//  Created by idebtor@gmail.com on December 12, 2018.
/*
* Description:	This program implements a simple linked list of nodes
* without a head structure and without sentinel nodes. It simply links
* node to node. The caller is responsible for maintaining the the first
* (head) element of the list. Most functions need the first node to work
* with the list and returns the first node of the list since the first
* may be changed inside of the function.
*/
#include <iomanip>
#include <cassert>
#include "listnode.h"

// removes all the nodes from the list (which are destroyed),
// and leaving the container nullptr or its size to 0.
pNode clear(pNode p) {
	if (empty(p)) return nullptr;
	DPRINT(cout << "clear: ";);

	pNode curr = p;
	while (curr != nullptr) {
		pNode prev = curr;
		curr = curr->next;
		cout << prev->item << " ";
		delete prev;
	}
	cout << "\tcleard \tHappy Coding~~\n";
	return nullptr;
}

// returns the number of nodes in the list.
int size(pNode p) {
	if (empty(p)) return 0;
	int count = 0;
	for (pNode c = p; c != nullptr; c = c->next, count++);
	return count;
}

// returns the last node of in the list.
pNode last(pNode p) {
	if (empty(p)) return nullptr;
	while (p->next != nullptr) p = p->next;
	return p;
}

// returns true if the list is empty or no nodes.
// To remove all the nodes of a list, see clear().
bool empty(pNode p) {
	return p == nullptr;
}

// inserts a new node with val at the beginning of the list.
// This effectively increases the list size by one.
pNode push_front(pNode p, int val) {
	DPRINT(cout << "><push_front val=" << val << endl;);

	pNode new_p = new (nothrow) Node{val, p};
	assert(!empty(new_p));

	return new_p;
}

// adds a new node with val at the end of the list and returns the
// first node of the list. This effectively increases the list size by one.
pNode push_back(pNode p, int val) {
	DPRINT(cout << "><push_back val=" << val << endl;);
	if(empty(p)) return push_front(p, val);

	pNode curr = p;
	while(!empty(curr->next)){
		curr = curr->next;
	}
	curr->next = new (nothrow) Node{val, nullptr};
	assert(!empty(curr->next));

	return p;
}

// inserts a new node with val at the position of the node with x.
// The new node is actually inserted in front of the node with x.
// It returns the first node of the list.
// This effectively increases the container size by one.
pNode push(pNode p, int val, int x) {
	if (empty(p)) return push_front(p, val);
	if (p->item == x) return push_front(p, val);

	pNode curr = p;
	pNode prev = nullptr;
	while(curr->item != x){
		prev = curr;
		curr = curr->next;
		if(empty(curr)) return p;
	}
	prev->next = new (nothrow) Node{val, curr};
	assert(!empty(prev->next));

	return p;
}

// adds N number of new nodes at the end of the list, O(n)
// Values of new nodes are randomly generated in the range of
// [0..(N + size(p))].
// Since it simply calls push_back() repeatedly, it is O(N^2).
pNode push_backN(pNode p, int N) {
	DPRINT(cout << "<push_backN N=" << size(p) << endl;);

	int range = N + size(p);
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++) {
		int val = rand() % range;
		p = push_back(p, val);
		cout << setw(7) << "\r\tinserting in [" << i << "]=" << val;
	}
	cout << "\n";

	DPRINT(cout << "<push_backN size=" << size(p) << endl;);
	return p;
}

// removes the first node in the list and returns the new first node.
// This destroys the removed node, effectively reduces its size by one.
pNode pop_front(pNode p) {
	DPRINT(cout << ">pop_front size=" << size(p) << endl;);
	if(empty(p)) return nullptr;

	pNode p_second = p->next;
	delete p;

	return p_second;
}

// removes the last node in the list, effectively reducing the
// container size by one. This destroys the removed node.
pNode pop_back(pNode p) {
	DPRINT(cout << ">pop_back size=" << size(p) << endl;);
	if (empty(p)) return nullptr;

	pNode curr = p;
	pNode prev = nullptr;
	while(!empty(curr->next)){
		prev = curr;
		curr = curr->next;
	}
	if(curr != p){
		prev->next = nullptr;    //this statement was the key point. Why?
		delete curr;
	}
	else {
		delete curr;
		p = nullptr;
	}

	DPRINT(cout << "<pop_back size=" << size(p) << endl;);
	return p;
}

// deletes N number of nodes, starting from the end.
// It deletes all the nodes if N is zero which is the default or out of
// the range of the list.
// Since it simply calls pop_back() which is O(n) repeatedly, it is O(N^2).
pNode pop_backN(pNode p, int N) {
	DPRINT(cout << ">pop_backN N=" << N << endl;);

	for(int i = 0; i < N && !empty(p); i++)
		p = pop_back(p);

	DPRINT(cout << "<pop_backN size=" << size(p) << endl);
	return p;
}

// removes the first occurrence of the node with val from the list
pNode pop(pNode p, int val) {
	DPRINT(cout << ">pop val=" << val << endl;);
	if (empty(p)) return nullptr;    // nothing to delete
	if (p->item == val) return pop_front(p);

	pNode curr = p;
	pNode prev = nullptr;
	while(curr->item != val){
		prev = curr;
		curr = curr->next;
		if(empty(curr)) return p;
	}
	prev->next = curr->next;
	delete curr;

	DPRINT(cout << "<pop size=" << size(p) << endl;);
	return p;
}

// shows the values of all the nodes in the list if all is true or
// the list size is less than pmax * 2. If there are more than
// (pmax * 2) nodes, then it shows only pmax number of nodes from
// the beginning and the end in the list.
void show(pNode p, bool all) {
	DPRINT(cout << "show(" << size(p) << ")\n";);
	if (empty(p)) {
		cout << "\n\tThe list is empty.\n";
		return;
	}
	int i;
	int pmax = 10;   // a magic number, max number of items per line
	pNode curr;
	const int N = size(p);

	if (all || N < pmax * 2) {
		for (i = 1, curr = p; curr != nullptr; curr = curr->next, i++) {
			cout << " -> " << curr->item;
			if (i % pmax == 0) cout << endl;
		}
		return;
	}

	// print the first pmax items
	else if(!all){
		for(i = 1, curr = p; i <= pmax; i++, curr = curr->next){
			cout << " -> " << curr->item;
			if(i % pmax == 0 && i != pmax) cout << endl;
		}
		cout << "\n...left out...\n";
	// print the last pmax items
	// move the pointer to the place where pmax items are left.
		pNode curr_b = p->next;
		while(!empty(curr->next)){
			curr_b = curr_b->next;
			curr = curr->next;
		}
		for(i = 1; i <= pmax, !empty(curr_b); i++, curr_b = curr_b->next){
			cout << " -> " << curr_b->item;
			if(i % pmax == 0 && i != pmax) cout << endl;
		}

	}

	cout << "\n";
}
