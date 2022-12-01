/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_three.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:21:42 by aaitoual          #+#    #+#             */
/*   Updated: 2022/12/02 00:13:08 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {
	template<typename T> class NODE {
		public :
			NODE	*parent;
			NODE	*right;
			NODE	*left;
			T		content;
			bool	color;
			NODE (T content_) : parent(NULL), right(NULL), left(NULL), color(1), content(content_) {}
			NODE (void) : parent(NULL), right(NULL), left(NULL), color(1), content(T()) {}
			NODE (NODE<T> & copy) : parent(NULL), right(NULL), left(NULL), color(1), content(T()) {}
			void	operator = (const NODE& copy) {
				color = copy.color;
				content = copy.content;
				right = copy->right;
				left = copy->left;
				parent = copy->parent;
			}
	};

	template<typename T>
	int	which_node(NODE<T> *node) {
		if (node->parent->right == node)
			return 1;	
		else if (node->parent->left == node)
			return 2;	
		return 0;
	}
	
	template<typename T>
	void	rotate(NODE<T> *first, NODE<T> *second, int case__, NODE<T> *__root) {
		NODE<T> *tmp;
		if (case__ == 1) {
			if (which_node(second) == 1) {
				first->right = second->left;
				second->left = first;
				first->right = NULL;
				if (first == __root)
					second = __root;
			}
			else if (which_node(second) == 2) {
				second->right = first;
				first->left = NULL;
				if (first == __root)
					second = __root;
			}
		}
		if (case__ == 2) {
			if (which_node(second) == 1) {
				tmp = second->left;
				second->left = first;
				first->right = tmp;
				first->color = 0;
				second->color = 1;
				if (first == __root)
					second = __root;
			}
			else if (which_node(second) == 2) {
				tmp = second->right;
				second->right = first;
				first->left = tmp;
				first->color = 0;
				second->color = 1;
				if (first == __root)
					second = __root;
			}
		}
	}
	
	template<typename  T>
	void	left_rotation(NODE<T> *node) {
		NODE<T> new_parent = node->right;
		NODE<T> tmp_parent = node->parent;
		
		node->right = new_parent->left;
		if (node->right)
			node->right->parent = node;
		new_parent->left = node;
		node->parent = new_parent;
		new_parent->parent = tmp_parent;
	}
	
	template<typename  T>
	void	right_rotation(NODE<T> *node) {
		NODE<T> new_parent = node->left;
		NODE<T> tmp_parent = node->parent;
		
		node->left = new_parent->right;
		if (node->left)
			node->left->parent = node;
		new_parent->right = node;
		node->parent = new_parent;
		new_parent->parent = tmp_parent;
	}

	template<typename T>
	void		color_cases(NODE<T> *node, NODE<T> *__root) {
		NODE<T>	*grand_parent;
		while (node->parent->color == 1) {
			grand_parent = node->parent->parent;
			if (grand_parent->right == node->parent) {
				std::cout << "------ " << node->content << std::endl;
				if (grand_parent->left->color == 1 ) {
					grand_parent->left->color = 0;
					grand_parent->color = 1;
					grand_parent->right->color = 0;
				}
				else {
					if (node == node->parent->left) {
						// node = node->parent
						right_rotation(k->parent);
					}
				}
				// else if (grand_parent->left->color == 0 && node == node->parent->right && node->parent->color == 1) {
				// 	rotate(node->parent, node, 2, __root);
				// }
				// else if (grand_parent->left->color == 0 && node == node->parent->left && node->parent->color == 1) {
				// 	rotate(node->parent, node, 1, __root);
				// }
			}
			else if (grand_parent->left == node->parent) {
				if (grand_parent->right->color == 1) {
					grand_parent->right->color = 0;
					grand_parent->color = 1;
					grand_parent->left->color = 0;
				}
				else if (node == node->parent->right) {
					left_rotation(node->parent);
				}
				else if (node == node->parent->left) {
					right_rotation(node->parent->parent);
				}
				// else if (grand_parent->right->color == 0 && node == node->parent->right && node->parent->color == 1) {
				// 	rotate(node, node->parent, 1, __root);
				// }
				// else if (grand_parent->right->color == 0 && node == node->parent->left && node->parent->color == 1) {
				// 	rotate(node->parent, node, 2, __root);
				// }
			}
			if (grand_parent == __root)
				grand_parent->color = 0;
		}
	}
	template<typename T> class RDT {
		public :
			NODE<T>	*__root;
			NODE<T>	*__nullnode;
			RDT (void) : __root(NULL), __nullnode(NULL) {}
			void	RDT_insert(NODE<T> *new_node) {
				NODE<T> *x = __root;
				NODE<T> *y;
				y = x;
				while (x != __nullnode) {
					y = x;
					if (new_node->content < x->content)
						x = x->left;
					else
						x = x->right;
				}
				if (y == __nullnode)
				{
					__root = new_node;
					new_node->color = 0;
				}
				else {
					new_node->parent = y;
					if (new_node->content < y->content)
						y->left = new_node;
					else
						y->right = new_node;
				}
				if (new_node->parent && new_node->parent->parent) {
					// std::cout << new_node->content << "----------\n";
					color_cases(new_node, __root);
				}
				// std::cout << __root->content << std::endl;
				__root->color = 0;
			}
	};
}