/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:14:43 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/10/25 01:45:58 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form() :_name("Default Form"), _gradeToSigned(10),_gradeToexecuted(10){
    this->_isSigned = false;
}

Form::Form(const std::string name, const int gs, const int ge):_name(name),_gradeToSigned(gs),  _gradeToexecuted(ge){
    if (gs < 1)
        throw GradeTooHighException();
    else if (gs > 150)
        throw GradeTooLowException();
    this->_isSigned = false;
}

std::string Form::getName() const{
    return (this->_name);
}
bool Form::getIsSigned() const{
    return (this->_isSigned);
}
int Form::getGradeToexecuted() const{
    return (this->_gradeToexecuted);
}

int Form::getGradeToSigned() const{
    return (this->_gradeToSigned);
}

Form::Form (const Form& other) :_name(other._name), _gradeToSigned(other._gradeToSigned), _gradeToexecuted(other._gradeToexecuted){
    this->_isSigned = other.getIsSigned();
    *this = other;
}

Form& Form::operator=(const Form& other){
    this->_isSigned = other.getIsSigned();
    return (*this);
}

Form::~Form(){}

const char * Form::GradeTooHighException::what() const throw(){
    return ("ERROR \t Grade to high");
}

const char* Form::GradeTooLowException::what() const throw(){
    return ("ERROR \t Grade is to low");
}
const char* Form::FormIsnotSigned::what() const throw(){
    return ("ERROR \t this form is not signed");
}
const char *Form::FormNotFound::what() const throw(){
    return ("ERROR \tis not found any form with this name ");
}

void Form::beSigned(Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > _gradeToSigned)
        throw GradeTooLowException();
    _isSigned = true;
}

void Form::signForm(Bureaucrat & bureaucrat){
    if (_isSigned == true && bureaucrat.getGrade() <= _gradeToSigned){
        std::cout << bureaucrat.getName() << " signed "
                  << getName() << std::endl; 
    }
    else{
        std::cout << bureaucrat.getName() << " couldn’t sign "
                  << getName() << " because " 
                  << "your grade is to low" << std::endl;
    }
}


std::ostream& operator << (std::ostream &op, const Form & other){
    
    op << "Form " << other.getName() << " his grade required to sign is "<< other.getGradeToSigned() << std::endl
       << " and his grade required to execute is " << other.getGradeToexecuted() << " and " << std::endl;
    if (other.getIsSigned() == true)
        op << "he can sign" << std::endl;
    else
        op << "he can't sign" << std::endl;
    return (op);    
}