/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nqasem <nqasem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:26:38 by nqasem            #+#    #+#             */
/*   Updated: 2026/02/26 15:38:51 by nqasem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

// Base class definition
class Base {
public:
    virtual ~Base() {}
};

// Derived classes
class A : public Base {};
class B : public Base {};  
class C : public Base {};

// Function declarations
Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif