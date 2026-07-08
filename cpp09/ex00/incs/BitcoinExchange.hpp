/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:51:58 by dpaes-so          #+#    #+#             */
/*   Updated: 2026/07/08 16:02:03 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <iomanip>
# include <fstream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

std::string ltrim(const std::string& s);
bool parse_date(int YY,int MM,int DD);
int count_spaces(const std::string& s);
bool first_parse(char *av, std::map <std::string, double> *db);
void map_print(std::map <std::string, double> db);
bool check_first_line(std::string line);
bool	input_parse(std::string key, std::string btc_n,std::string line);
bool start_matching(std::map <std::string, double> db,char *av);


#endif