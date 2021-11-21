/* 
	most_active_cookie.cpp
 */

// Common #includes for convience.
// No need to use them. 
// Remove any of them if you want.
#include <algorithm>
#include <cassert>
#include <deque>
#include <functional>
#include <iostream>
#include <fstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>


void most_active_cookie(std::ifstream& is, std::string date);
/*
	Used visual Studio IDE to aid in code creation
	Used Debugging tool to test with test case files

*/
int main(int argc, char** argv) {
	std::ifstream is;
	std::string date;
	std::string input_file(argv[1]);
	date = argv[3];
	is.open(input_file);
	
	if (!is.is_open()) {
		std::cout << "file not opened: " << argv[1];
		assert(false);
	}
	most_active_cookie(is, date);
	is.close();

}



void most_active_cookie(std::ifstream& is, std::string date) {
	std::set<std::string> most_freq_cookies;
	std::uint32_t max_count = 0;
	std::unordered_map<std::string, int> cookie_count;
	std::string cookie;
	while (is) {
		is >> cookie;
		std::size_t code_size = cookie.find(',');
		std::size_t time_size = cookie.find('T');
		std::string cookie_code(cookie.begin(), cookie.begin() + code_size);
		std::string cookie_date(cookie.begin() + code_size + 1, cookie.begin() + time_size);
		if (cookie_date == date) {
			if (cookie_count.find(cookie_code) != cookie_count.end()) {
				cookie_count[cookie_code]++;
			}
			else
			{
				cookie_count[cookie_code] = 1;

			}
			if (cookie_count[cookie_code] == max_count) {
				most_freq_cookies.insert(cookie_code);
			}
			if (cookie_count[cookie_code] > max_count) {
				most_freq_cookies.clear();
				most_freq_cookies.insert(cookie_code);
				max_count = cookie_count[cookie_code];
			}
		}

	}
	for (auto cookie : most_freq_cookies) {
		std::cout << cookie << "\n";
	}
}
