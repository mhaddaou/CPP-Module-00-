/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 03:49:56 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/10/28 13:55:52 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Classes.hpp"
#include "../includes/Base.hpp"

int main (){
        Base *ptr;
        ptr = generate();
        identify(ptr);
        identify(*(ptr));






        
        return 0;

    
}