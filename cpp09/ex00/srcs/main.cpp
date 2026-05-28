/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:57:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/05/28 18:05:53 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/BitcoinExchange.hpp"

bool first_parse(char *av, std::map <std::string, double> *db)
{
	std::ifstream data_bs("data.csv");
	std::string str;
	std::ifstream in(av); 
	if(in.is_open() == 0)
	{
		std::cerr << "Could not open the input file\n";
		return(false);
	}
	if(data_bs.is_open() == 0)
	{
		std::cerr << "Could not open the data.csv file\n";
		return(false);
	}
	std::map<std::string, double>::iterator it;
	while(std::getline(data_bs,str))
	{
		std::string key = str.substr(0,str.find(','));
		std::string s = str.substr(str.find(',') + 1 );
		if(s.find_first_not_of("1234567890.") == std::string::npos && key.find_first_not_of("1234567890-") == std::string::npos)
		{
			if(std::count(key.begin(),key.end(),'-') == 2 && std::count(s.begin(),s.end(),'.') <= 1)
			{
				double value = strtod(s.c_str(),NULL);
				db->insert(std::make_pair(key,value));
			}
		}
	}
	return true;
}


void map_print(std::map <std::string, double> db)
{
	std::map<std::string, double>::iterator it2;
	for(it2 = db.begin();it2 != db.end();it2++)
	{
		std::cout <<  it2->first << " | " << it2->second << std::endl;
	}
}

void start_matching(std::map <std::string, double> db,char *av)
{
	std::string line;
	std::ifstream in(av); 
	
	// (void)db;
	map_print(db);
	while (std::getline(in,line))
	{
		try
		{
			std::string key = line.substr(0,line.find(' '));
			double btc_number = strtod(line.substr(line.find('|') + 1 ).c_str(),NULL);
			//parse
			std::cout << key << std::endl;
			std::cout << btc_number << std::endl;
			std::cout << db[key] << std::endl;
			std::cout << btc_number * db[key];
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
}
int main(int ac, char *av[])
{
	if(ac == 2)
	{		
		std::map<std::string,double> db;
		if(first_parse(av[1],&db) == false)
			return 1;
		// map_print(db);
		start_matching(db,av[1]);
	}
	else
	{
		std::cerr << "Invalid amount of arguments(./btc <input_file>)\n";
	}
	return 0;
}