/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ___vec_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:42:39 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 19:38:20 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iterator>
# include "../../implementations/iterator_traits.hpp"

template<typename S>
class iterator_vec : public std::iterator < std::random_access_iterator_tag, S, const S, S>{
	public :
		typedef typename ft::iterator_traits<S>::reference 			reference;
		typedef typename ft::iterator_traits<S>::difference_type	difference_type;
	private :
		S	current;
	public :
		S	base() const {return current;}
		iterator_vec () : current() {}
		iterator_vec (S it) : current(it) {}
		template <typename T>
		iterator_vec (const iterator_vec<T>& it) : current(it.base()) {};
		reference				operator * () const {return *current;}
		S						operator -> () const {return current;}
		iterator_vec			operator ++ (int) {iterator_vec	tmp(current);current++;return tmp;}
		iterator_vec			operator + (int i) {return current + i;}
		iterator_vec			operator - (int i) {return current - i;}
		iterator_vec&			operator ++ () {current++;return *this;}
		iterator_vec			operator -- (int) {iterator_vec	tmp(current);current--;return tmp;}
		iterator_vec&			operator -- () {current--;return *this;}
		template <typename T>
		iterator_vec&			operator = (const iterator_vec<T>& copy) {current = copy.base(); return *this;}
		reference				operator [] (int i) {return current[i];}
		iterator_vec&			operator += (int i) {current += i; return *this;}
		iterator_vec&			operator -= (int i) {current -= i; return *this;}
		bool					operator != (iterator_vec& iter) {return (this->current != iter.current) ?  1 : 0;}
		bool					operator == (iterator_vec& iter) {return (this->current != iter.current) ?  0 : 1;}
		bool					operator > (iterator_vec& iter) {return (this->current > iter.current) ?  1 : 0;}
		bool					operator >= (iterator_vec& iter) {return (this->current >= iter.current) ?  1 : 0;}
		bool					operator < (iterator_vec& iter) {return (this->current < iter.current) ?  1 : 0;}
		bool					operator <= (iterator_vec& iter) {return (this->current <= iter.current) ?  1 : 0;}
		
		friend	bool			operator != (const iterator_vec& that, const iterator_vec& iter) {return (that.base() != iter.base()) ?  1 : 0;}
		friend	bool			operator == (const iterator_vec& that, const iterator_vec& iter) {return (that.base() != iter) ?  0 : 1;}
		friend	bool			operator > (const iterator_vec& that, const iterator_vec& iter) {return (that.base() > iter.base()) ?  1 : 0;}
		friend	bool			operator >= (const iterator_vec& that, const iterator_vec& iter) {return (that.base() >= iter.base()) ?  1 : 0;}
		friend	bool			operator < (const iterator_vec& that, const iterator_vec& iter) {return (that.base() < iter.base()) ?  1 : 0;}
		friend	bool			operator <= (const iterator_vec& that, const iterator_vec& iter) {return (that.base() <= iter.base()) ?  1 : 0;}
		friend	long			operator - (const iterator_vec &that, const iterator_vec& sec) {return that.base() - sec.base();}
		friend	iterator_vec	operator + (int i, iterator_vec it) {return it + i;}
		friend	iterator_vec	operator - (int i, iterator_vec it) {return it - i;}
};
template <typename val, typename val2>
long			operator + (const iterator_vec<val> &that, const iterator_vec<val2> &sec) {return that.base() + sec.base();}
