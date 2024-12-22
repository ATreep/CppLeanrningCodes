/*
 * Task
 * We have six short articles in `articles` directory, which are writen by three writers, each writer two articles.
 * Reading three article_a.txt files, we need to find the identity for each writer and match the writers with three article_b files.
 *
 * Method We Used
 * Count the occurrances of all words in the articles and combine ten most often used words' occurrances numbers into vectors. Calculate the difference between two vectors by dot product and cosine theta.
 */

// Standard: C++17

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <numeric>

using std::string;
using std::vector;

std::unordered_map<string, int> get_count_map(std::ifstream& ifs); 
vector<int> get_count_vector(std::unordered_map<string, int>& count_map, const vector<string>& word_table);
double calculate_cosin_theta(const vector<int>& v1, const vector<int>& v2);

bool debug = false;

int main() {
	std::ifstream fa_a("articles/writer_a_article_a.txt");
	std::ifstream fa_b("articles/writer_a_article_b.txt");
	std::ifstream fb_a("articles/writer_b_article_a.txt");
	std::ifstream fb_b("articles/writer_b_article_b.txt");
	std::ifstream fc_a("articles/writer_c_article_a.txt");
	std::ifstream fc_b("articles/writer_c_article_b.txt");

	if(!fa_a.is_open()) {
		std::cerr << "Error: Cannot open articles in './articles' directory." << std::endl;
		return 0;
	}

	auto ma_a = get_count_map(fa_a);
	auto ma_b = get_count_map(fa_b);
	auto mb_a = get_count_map(fb_a);
	auto mb_b = get_count_map(fb_b);
	auto mc_a = get_count_map(fc_a);
	auto mc_b = get_count_map(fc_b);

	vector<string> word_table{
	    "a", "about", "above", "after", "again", "against", "all", "am", "an", "and",
	    "any", "are", "aren't", "as", "at", "be", "because", "been", "before", "being",
	    "below", "between", "both", "but", "by", "can", "can't", "come", "could", "couldn't",
	    "did", "didn't", "do", "does", "doesn't", "doing", "don't", "down", "during", "each",
	    "few", "for", "from", "further", "had", "hadn't", "has", "hasn't", "have", "haven't",
	    "having", "he", "he'd", "he'll", "he's", "her", "here", "here's", "hers", "herself",
	    "him", "himself", "his", "how", "how's", "i", "i'd", "i'll", "i'm", "i've",
	    "if", "in", "into", "is", "isn't", "it", "it's", "its", "itself", "let's",
	    "me", "more", "most", "mustn't", "my", "myself", "no", "nor", "not", "of",
	    "off", "on", "once", "only", "or", "other", "ought", "our", "ours", "ourselves",
	    "out", "over", "own", "same", "shan't", "she", "she'd", "she'll", "she's", "should"
	};

	vector<int> va_a = get_count_vector(ma_a, word_table); 
	vector<int> va_b = get_count_vector(ma_b, word_table); 
	vector<int> vb_a = get_count_vector(mb_a, word_table); 
	vector<int> vb_b = get_count_vector(mb_b, word_table); 
	vector<int> vc_a = get_count_vector(mc_a, word_table); 
	vector<int> vc_b = get_count_vector(mc_b, word_table); 

	std::cout << "Cosin Theta of a_a and a_b: " << calculate_cosin_theta(va_a, va_b) << std::endl;
	std::cout << "Cosin Theta of b_a and a_a: " << calculate_cosin_theta(vb_a, va_a) << std::endl;

	return 0;
}

std::unordered_map<string, int> get_count_map(std::ifstream& ifs) {
	std::unordered_map<string, int> ret;
	
	string word;

	ifs.seekg(0);

	if(debug)
		std::cout << "File is_open=" << ifs.is_open() << std::endl;

	while (ifs >> word) {
		if(debug)
			std::cout << "Current indexing word: " << word << std::endl;
		std::transform(word.begin(), word.end(), word.begin(), tolower);
		if (word.substr(word.length() - 1) == "," || 
				word.substr(word.length() - 1) == ".")
			word = word.substr(0, word.length() - 1);
		ret[word]++;
	}
	ifs.close();
	return ret;
}

vector<int> get_count_vector(std::unordered_map<string, int>& count_map, const vector<string>& word_table) {
	vector<int> ret(word_table.size());
	for(int i = 0;i < word_table.size();i++) {
		ret[i] = count_map[word_table[i]];
	}
	return ret;
}

double calculate_magnitude(const vector<int>& v) {
	return std::sqrt(std::inner_product(v.begin(), v.end(), v.begin(), 0.0));
}

double calculate_cosin_theta(const vector<int>& v1, const vector<int>& v2) {
	double dot_product = std::inner_product(v1.begin(), v1.end(), v2.begin(), 0.0);
	double magnitude1 = calculate_magnitude(v1);
	double magnitude2 = calculate_magnitude(v2);

	return dot_product / (magnitude1 * magnitude2);

}
