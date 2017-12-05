
#include "Control.h"
#include "Force.h"
#include "Particle.h"
#include "Set.h"


using namespace std;

map<int, Particle> all; //global variable map!

void parser(istream& is);

int main() {
	cout << "Enter a command: ";
	parser(cin);
}

void parser(istream& is) {
	Particle *particle_all= new Particle; //dynamic memory allocation for Particle class
	Set *set_all = new Set; //dynamic memory allocation for Set class 

	map<int, Particle> all; //map

	map<int, Set* > all_set; //map saves set

	for (string line; getline(is, line); ) {
		if (line == "qq")
			break;
		istringstream iss{ line };
		vector<string> words{ istream_iterator<string> {iss},
			istream_iterator<string> {} };
		for (int i = 0; i < words.size(); ++i)
		{
			if (words[0] == "ap") //if command is "ap"(add particle)
			{
				double *temp=new double[words.size()];
				for (int j = 0; j < words.size()-1; ++j)
					temp[j] = stod(words[j+1], 0);
				particle_all->var_set(temp);
				//add key of result to all
				delete(temp);
				cout << "Particle " << words[1] << " added \n\n";
				break;
			}
			else if (words[0] == "pp")
			{
				particle_all->print_particle(stoi(words[1]));
				break;
			}
			else if (words[0] == "dp")
			{
				particle_all->delete_particle(stoi(words[1]));
				break;
			}
		}
		cout << "Enter a command: ";
	}
	delete(particle_all);
}