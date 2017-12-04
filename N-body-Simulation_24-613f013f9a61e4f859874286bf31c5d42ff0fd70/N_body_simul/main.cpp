#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void parser(istream& is) {
	for (string line; getline(is, line); ) {
		if (line == "qq")
			break;

		istringstream iss{ line };
		vector<string> words{ istream_iterator<string> {iss},
			istream_iterator<string> {} };

		cout << "tokenized words\n---------------\n";
		for (int i = 0; i < words.size(); ++i)
			cout << "words[" << i << "]: " << words[i] << endl;
	}
}

int main() {
	parser(cin);
}