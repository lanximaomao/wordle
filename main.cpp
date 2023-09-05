/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:12:07 by tpoho             #+#    #+#             */
/*   Updated: 2023/09/05 19:27:34 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wordle.hpp"
#include <iostream>

int	main(void)
{
	Wordle wordle;
	std::string input_line;

	if (!wordle.readDictionary())
	{
		std::cout << "Could not read words from words.txt" << std::endl;
		return (1);
	}
	wordle.printWordsAvailable();
	while (!wordle.hasGameEnded())
	{
		std::cout << "Give input word: ";
		std::getline (std::cin, input_line);
		if (std::cin.eof())
			return (0);
		wordle.checkWord(input_line);
		wordle.printStatus();
		std::cout << std:: endl;
	}
	wordle.printEndText();
	return (0);
}
