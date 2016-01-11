#include <vector>
#include <string>
#include <iostream>
#include "tree.h"


/* NODE CLASS IMPLEMENTATION */

nt::node::node(int num){
	this->parent = NULL;
	this->number = num;
}

nt::node::node(node* par, int num){
	this->parent = par;
	this->number = num;
}

nt::node::~node(){
	/* good boys and girls always cares about memory leaks */
	for (int i=0; i<this->child.size(); i++)
		delete child[i];
}

nt::node* nt::node::add_child(int num){
	nt::node* n = new nt::node(this, num);
	this->child.push_back(n);
	return n;
}

int nt::node::sum_children(){
	int s = 0;
	for (int i=0; i<this->child.size(); i++)
		s += child[i]->number;
	return s;
}

int nt::node::count_children(){
	return this->child.size();
}

void node_output(nt::node* n, std::string prefix){
	std::cout << prefix << ((n->child.size() > 0)?("v "):("> ")) << n->number << std::endl;
	for (int i=0; i<n->child.size(); i++)
		node_output(n->child[i], prefix + "  ");
}

void nt::node::output(){
	node_output(this, "");	
}

/* NUMTREE CLASS IMPLEMENTATION */
nt::numtree::numtree(){
	this->root = NULL;
}

nt::numtree::~numtree(){
	delete this->root;
}

int nt::numtree::add_child(int dad_id, int num){
	if (dad_id == -1){
		this->root = new nt::node(num);
		this->nodes.push_back(this->root);
		return this->nodes.size()-1;
	}

	else if (dad_id >= 0){
		this->nodes.push_back(this->nodes[dad_id]->add_child(num));
		return this->nodes.size()-1;
	}
}

int count_good_dads(nt::node* n){
	int s = 0;
	if (n->sum_children() > n->number)
		s++;

	for (int i=0; i<n->child.size(); i++)
		s += count_good_dads(n->child[i]);

	return s;	
}

int nt::numtree::count_nice_dads(){
	return count_good_dads(root);
}


nt::node* find_dad_with_most_children(nt::node* n){
	nt::node* most = n;	
	for (int i=0; i<n->child.size(); i++)
		if (most->count_children() < find_dad_with_most_children(n->child[i])->count_children())
			most = n->child[i];
	return most;
}

nt::node* nt::numtree::dad_with_most_children(){
	return find_dad_with_most_children(this->root);
}


nt::node* find_best_dad(nt::node* n){
	nt::node* best = n;	
	for (int i=0; i<n->child.size(); i++)
		if (best->sum_children() < find_best_dad(n->child[i])->sum_children())
			best = n->child[i];
	return best;
}

nt::node* nt::numtree::best_daddy(){
	return find_best_dad(this->root);
}


void nt::numtree::output(){
	this->root->output();
}
