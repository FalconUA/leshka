#ifndef __TREE_HEADER_FILE__
#define __TREE_HEADER_FILE__

/* DELETE THIS AFTER READING 
 * короч неймспейс это пространство имён. его используем чтоб не путать
 * с другими пространствами имён (пусть тебя не смущает слово "пространство",
 * это просто слово крутое юзают.
 *
 * Проще говоря, если, например, в библиотеке ШЛ*ХА есть функция "сосать",
 * и в библиотеке РЕБЁНОК тоже есть функция "сосать", и ты одновременно 
 * подключаешь эти библиотеки, то, чтоб понять из какой библиотеки вызываем
 * функцию "сосать", мы задаём пространства имён, типа ШЛ*ХА::сосать() или
 * РЕБЁНОК::сосать()
 */

#include <vector>
#include <iostream>

namespace nt { 


	/* DELETE THIS AFTER READING
	 *
	 * короче думаю по названию понятно что это за класс. в общем немножко погуглишь что
	 * такое ООП, и с чем его хавать. единственное что конструктор node(node* par, int num)
	 * я запихнул в приватные методы поскольку только твой батя может решать кто твой батя.
	 * такие вот дела.
	 */
	class node {

	private:
		node* parent;	
		node(node* par, int num);

	public:
		/* members */
		int number;
		std::vector<node*> child;

		node(int num);
		~node();

		node* add_child(int num);
		int sum_children();
		int count_children();

		/* for demonstration purpose */

		/* DELETE THIS AFTER READING
		 *
		 * я тут короч хотел сделать перенаправление потоков, но потом хуй объяснишь,
		 * так что сделал по простому, вывод в std::cout
		 */

		void output();
	};


	/* DELETE THIS AFTER READING */

	class numtree {
	private:
		node* root;		
		std::vector<node*> nodes;

	public:
		numtree();
		~numtree();

		int add_child(int dad_id, int num);
		int count_nice_dads();
		node* dad_with_most_children();
		node* best_daddy();

		void output();
	};

} // end of namespace nt

#endif
