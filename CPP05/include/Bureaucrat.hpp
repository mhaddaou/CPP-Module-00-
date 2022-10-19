/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:34:23 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/10/19 14:45:06 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat{
    private:
        const std::string _name;
        int               grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(int grade, const std::string name);
        Bureaucrat (Bureaucrat & other);
        Bureaucrat& operator=(const Bureaucrat & other);
        ~Bureaucrat();
        void GradeTooHighException();
        void GradeTooLowException();
        
};


#endif