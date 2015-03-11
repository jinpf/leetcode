#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode *p1 = l1, *p2 = l2, *l3 = new ListNode(-1), *p3 = l3;
	int more = 0,var = 0;
	while (true) {
		if (p1 != nullptr) {
			if (p2 != nullptr) {
				var = (p1->val + p2->val) + more;
				p2 = p2->next;
			}
			else {
				var = p1->val + more;
			}
			p1 = p1->next;
		} else {
			if (p2 != nullptr) {
				var = p2->val + more;
				p2 = p2->next;
			}
			else if (more != 0){
				var = more;
			}
			else {
				break;
			}
		}
		p3->next = new ListNode(var % 10);
		more = var/ 10;
		p3 = p3->next;
	}
	return l3->next;
}

int main () {
	vector< vector<int> > v{{2,4,3,9,9},{5,6,4,7,9}};
	vector<ListNode*> L;

	// init
	for (int i = 0; i != v.size(); ++i) {
		ListNode *p = new ListNode(v[i][0]);
		L.push_back(p);
		for (int j = 1; j != v[i].size(); ++j) {
			p->next = new ListNode(v[i][j]);
			p = p->next;
		}
	}

	//print
	for (int i = 0; i != L.size(); ++i) {
		cout << "L[" << i+1 << "]:" ; 
		for (ListNode *p = L[i]; p != nullptr; p = p->next) {
			cout << p->val << " ";
		}
		cout << endl;
	}

	ListNode *result = addTwoNumbers(L[0],L[1]);

	cout << "     ";

	for (ListNode *p = result; p != nullptr; p = p->next) {
		cout << p->val << " ";
	}
	cout << endl;
}