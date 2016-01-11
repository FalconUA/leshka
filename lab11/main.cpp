#include <iostream>
#include "tree.h"


int main(){
	nt::numtree tree;
	tree.add_child(-1, 100);	// id == 0
	tree.add_child(0, 10);		// id == 1
	tree.add_child(0, 11);		// id == 2
	tree.add_child(0, 31);		// id == 3
	tree.add_child(1, 50);
	tree.add_child(1, 60);

	std::cout << "# Tree structure:" << std::endl;
	tree.output();

	std::cout << std::endl << "# Number of dads, which the sum of his children is larger than his number: " << tree.count_nice_dads() << std::endl;

	nt::node* n = tree.dad_with_most_children();
	std::cout << "# Node which has the most children (total of " << n->child.size() << "): " << std::endl;
	n->output();

	nt::node* t = tree.best_daddy();
	std::cout << "# Node which the sum of his children is the largest (" << t->sum_children() << "): "<< std::endl;
	t->output();
	return 0;
}
