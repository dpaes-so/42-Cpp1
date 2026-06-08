/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: finn <finn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:09:00 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/06/08 15:07:38 by finn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/BitcoinExchange.hpp"

std::string ltrim(const std::string& s)
{ 
    size_t pos = s.find_first_not_of(" \t\n\r\f\v"); 
    return (pos == std::string::npos) ? std::string() : s.substr(pos); 
} 

bool parse_date(int YY,int MM,int DD)
{
	if(YY > 9999 || YY < 0001|| MM > 12 || DD > 31 || DD < 1)
		return(false);
	switch (MM)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if(DD > 31)
				return (false);
			break;
		case 4: case 6: case 9: case 11:
			if(DD > 30)
				return (false);
			break;
		case 2:
			if((YY % 400 == 0) ||(YY % 4 == 0 && YY % 100 != 0))
			{
				if(DD > 29)
					return(false);
			}
			else
			{
				if(DD>28)
					return(false);
			}
			break;
		default:
			return(false);
	}
	return(true);
}

int count_spaces(const std::string& s)
{
	int count = 0;
	size_t i = 0;
	for(i = 0;i<s.length();i++)
	{
		if(s.at(i) == ' ')
			count++;
		if(count > 1)
			break;
	}
	return(count);
}
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
	if(data_bs.is_open() == 0 )
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
				int YY,MM,DD = 0;
				std::string month = key.substr(key.find('-') + 1,key.find('-')).c_str();
				YY = strtod(key.substr(0,key.find('-')).c_str(),NULL);
				MM = strtod(month.c_str(),NULL);
				DD = strtod(key.substr(key.find('-') + 4,key.find(' ')).c_str(),NULL);
				if(parse_date(YY,MM,DD) == false)
					continue;
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

bool check_first_line(std::string line)
{
	if("date | value" != line)
	{
		std::cerr << "Error: Wrong input file header\n";
		return (false);
	}
	return (true);
}

bool	input_parse(std::string key, std::string btc_n,std::string line)
{
	if (btc_n.find_first_not_of("1234567890.") != std::string::npos
		|| std::count(btc_n.begin(), btc_n.end(), '.') > 1)
			return (false);
	if (key.find_first_not_of("1234567890-") != std::string::npos
		|| std::count(key.begin(), key.end(), '-') != 2 || key.size() != 10)
			return (false);
	if((btc_n.size() == 1 && btc_n.at(0) == '.' )|| btc_n.empty())
		return(false);
	if(!ltrim(line.substr(line.find(' '),line.find('|') - line.find(' '))).empty())
		return(false);
	int YY,MM,DD = 0;
	std::string month = key.substr(key.find('-') + 1,key.find('-')).c_str();
	YY = strtod(key.substr(0,key.find('-')).c_str(),NULL);
	MM = strtod(month.c_str(),NULL);
	DD = strtod(key.substr(key.find('-') + 4,key.find(' ')).c_str(),NULL);
	return(parse_date(YY,MM,DD));
}

bool start_matching(std::map <std::string, double> db,char *av)
{
	std::string line;
	std::ifstream in(av);
	double btc_number = -1;
	
	std::getline(in,line);
	if(!check_first_line(line))
		return(false);
	if(in.eof())
		std::cerr << "Error: No dates in the input file!" << std::endl;
	while (std::getline(in,line))
	{
		if(line.empty())
		{
			std::cerr << "Error: Empty line!\n";
			continue;
		}
		if(count_spaces(line.substr(0,line.find('|'))) != 1 || count_spaces(line.substr(line.find('|') + 1)) != 1)
		{
			std::cerr << "Error: The should only be one space between the pipe and the input!\n";
			continue;;
		}
		std::string key = line.substr(0,line.find(' '));
		std::string btc_n = ltrim(line.substr(line.find('|') + 1 ));
		if(input_parse(key,btc_n,line) == false)
		{
			if(strtod(btc_n.c_str(),NULL) < 0)
				std::cerr << "Error: Not a positive number.\n";
			else
				std::cerr << "Error: Bad input => " << line << std::endl;
			continue;
		}
		btc_number = strtod(btc_n.c_str(),NULL);
		if(btc_number > 1000)
		{
			std::cerr << "Error: Too large a number.\n";
			continue;
		}
		std::map<std::string,double>::const_iterator it = db.upper_bound(key);
		if(it == db.begin())
		{
			std::cerr << "Error: Earliest date is " << (*db.begin()).first << std::endl;
			continue;
		}
		std::cout << key << " => "<< btc_number << " = ";
		it--;
		std::cout << btc_number * (*it).second << std::endl;
	}
	if(line.empty() && btc_number < 0)
		std::cerr << "Error: No dates in the input file!\n";
	return (true);
}

