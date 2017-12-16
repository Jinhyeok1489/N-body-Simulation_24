#include "Control.h"
#include "Force.h"
#include "Particle.h"
#include "Set.h"
#include "Time.h"///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <memory>

using namespace std;

//map<int, Particle> all; //global variable map!///////////////////////////////////////////////////////////////////////////

void parser(istream& is);

int main() {
	std::cout << "Enter a command: ";
	parser(cin);
}

void parser(istream& is) {

	unique_ptr<Time> timer{ new Time() };//smart pointer //////////////////////////////////////////////////////////////////수정

	unique_ptr<Particle> particle_all{ new Particle };/////////////////////////////////////////////////////////////////수정

	unique_ptr<Set> set_all{ new Set };////////////////////////////////////////////////////////////////////////////////////수정

	set_all->big_set_make(0, set_all.get());	//make default set///////////////////////////////////////////////수정

	//std::set<int> set_made;
	//map<int, Particle> all; //map/////////////////////////////////////////////////////////////////////////////////수정

	//map<int, std::map<int, std::map<int, Particle_s> > > all_set; //map saves set/////////////////////////////////수정

	for (string line; getline(is, line); ) {
		if (line == "qq")
		{
			timer.release(); //release unique_ptr timer
			particle_all.release(); //release unique_ptr particle_all
			set_all.release(); //release unique_ptr set_all

			cout << "All force deleted \n";
			cout << "All sets deleted \n";
			cout << "All particles deleted\n";
			cout << "Particles: 0\n"; //if it was deleted as expected we cannot find its size
			cout << "Sets: 0\n";	// therefore, we consider it as 0
			cout << "Forces: 0\n";
			cout << "Done\n\n";
			break;
		}
			
			
		istringstream iss{ line };
		vector<string> words{ istream_iterator<string> {iss},
			istream_iterator<string> {} };
		////////////////////////////////////////////////////////////////////////////////////////////////수정
		while (true)
		{
			if (words[0] == "ap") //if command is "ap"(add particle)
			{
				int exp_inp = 7; // expected number of inputs  
				if (words.size() != exp_inp)
					//if size of words is smaller than expected, error control 
					cout << "Now! We are run out of inputs! Please give more input! \n\n";
				else if (stoi(words[1]) < 0) //if particle number is smaller than 0
					cout << "Particle number is not in range! \n\n";
				else if (particle_all->part_info.find(stoi(words[1])) != particle_all->part_info.end())
					// if particle number was not found after searching the map
					cout << "That name of particle already exist!\n\n";
				else
				{
					unique_ptr<double[]> temp{ new double[words.size() - 1] };
					for (int j = 0; j < words.size() - 1; ++j)
						temp[j] = stod(words[j + 1]);
					particle_all->var_set(temp.get());
					//add key of result to all
					std::cout << "Particle " << words[1] << " added \n\n";

					set_all->indiv_set_make(0, stoi(words[1]), particle_all.get(), set_all.get());	//send to default set
				}
				break;
			}
			else if (words[0] == "pp")
			{
				int exp_inp = 2; // expected number of inputs  
				if (words.size() != exp_inp)
					//if size of words is not equal to expected, error control 
					cout << "Now! We are run out of inputs! Please give more input! \n\n";
				else if (particle_all->part_info.find(stoi(words[1])) == particle_all->part_info.end())
					// if particle number was not found after searching the map
					cout << "No particle with that number\n\n";
				else
					particle_all->print_particle(stoi(words[1]));
				break;
			}
			else if (words[0] == "dp")
			{
				particle_all->delete_particle(stoi(words[1]));
				break;
			}
			else if (words[0] == "as")//////////////////////////////////////////////////////////////////////////////////////수정
			{
				int exp_inp = 2;
				if (words.size() != exp_inp)
					// if size of words is not equal to exp_int
					cout << "Words size is too big or small from your input!\n\n";
				else if (stoi(words[1]) == 0)
				{
					std::cout << "You cannot make the default set." << endl << endl;
				}
				else
				{
					set_all->big_set_make(stoi(words[1]), set_all.get());/////////////////////////////////////////////////////수정
					std::cout << "Set " << words[1] << " added \n\n";
				}
				break;
			}
			else if (words[0] == "ae")/////////////////////////////////////////////////////////////////////////수정
			{
				int exp_int = 3;
				if (words.size() != exp_int)
				{
					cout << "Words size is too big or small from your input!\n\n";
					break;
				}
				else if (set_all->all_set_info.find(stoi(words[1])) == set_all->all_set_info.end())
					// if set number was not found after searching the map
					cout << "No set with that number\n\n";
				else if (particle_all->part_info.find(stoi(words[2])) == particle_all->part_info.end())
					// if particle number was not found after searching the map
					cout << "No particle with that number\n\n";
				else
				{
					bool det = set_all->checkbelong(stoi(words[2])); //check if particle still belong to set

					if (det == true)
						std::cout << "Particle " << words[2] << " is already belong to another set\n\n";
					else
					{
						set_all->delete_p_to_s(0, stoi(words[2]));	//delete from default set
																	//this variable is iterator for searching all_set_info
						set_all->indiv_set_make(stoi(words[1]), stoi(words[2]), particle_all.get(), set_all.get());
						std::cout << "Particle " << words[2] << " added to set " << words[1] << "\n\n";
					}
				}
				break;

				
			}
			else if (words[0] == "ps")
			{
				int exp_int = 2;
				if (words.size() != exp_int)
				{
					cout << "Words size is too big or small from your input!\n\n";
					break;
				}
				else if (set_all->all_set_info.find(stoi(words[1])) == set_all->all_set_info.end())
					// if set number was not found after searching the map
					cout << "No set with that number\n\n";
				else
					set_all->print_set(stoi(words[1]));
				break;
			}
			else if (words[0] == "de")
			{
				int exp_int = 3;
				if (words.size() != exp_int)
				{
					cout << "Words size is too big or small from your input!\n\n";
					break;
				}
				else if (set_all->all_set_info.find(stoi(words[1])) == set_all->all_set_info.end())
					// if set number was not found after searching the map
					cout << "No set with that number\n\n";
				else if (stoi(words[1]) == 0)
					std::cout << "You cannot delete a particle from default set." << endl;
				else
				{
					set_all->delete_p_to_s(stoi(words[1]), stoi(words[2]));////////////////////////////////////////////수정
					std::cout << "Particle " << words[2] << " deleted from Set" << words[1] << "\n\n";

					set_all->indiv_set_make(0, stoi(words[2]), particle_all.get(), set_all.get());	//send to default set
				}
				break;
			}
			else if (words[0] == "af")
			{
				int exp_int = 5;
				if (words.size() != exp_int)
					cout << "Words size is too big or small from your input!\n\n";
				else if (stoi(words[1]) < 0)
					//if force number is smaller than 0
					cout << "Force number is not in range!\n\n";
				else if (set_all->all_set_info.find(stoi(words[2])) == set_all->all_set_info.end())
					// if set number was not found after searching the map
					cout << "No set with that number\n\n";
				else
				{
					set_all->impose_force(stoi(words[1]), stoi(words[2]), stod(words[3]), stod(words[4]));
					std::cout << "Force " << words[1] << "is now imposed on Set " << words[2] << "!\n\n";
				}
				break;
			}
			else if (words[0] == "pf")
			{
				int exp_int = 2;
				if (words.size() != exp_int)
					cout << "Words size is too big or small from your input!\n\n";
				else if (set_all->force_info.find(stoi(words[1])) == set_all->force_info.end())
					//specific force was not found until the end
					cout << "There's no force with that name!\n\n";
				else
					set_all->print_force(stoi(words[1]));
				break;
			}
			else if (words[0] == "df")
			{
				int exp_int = 2;
				if (words.size() != exp_int)
					cout << "Words size is too big or small from your input!\n\n";
				else if (set_all->force_info.find(stoi(words[1])) == set_all->force_info.end())
					//specific force was not found until the end
					cout << "There's no force with that name!\n\n";
				else
				{
					set_all->delete_force(stoi(words[1]));
					std::cout << "Force " << words[1] << " deleted!\n\n";
				}
				break;
			}
			else if (words[0] == "ct")	//change timetick command
			{
				int exp_int = 2;
				if (words.size() != exp_int)
					cout << "Words size is too big or small from your input!\n\n";
				else
				{
					timer->ct(stod(words[1]));
					std::cout << "Timetick is changed into " << words[1] << "(sec)." << endl << endl;
				}
				break;
			}
			else if (words[0] == "pt")	//print time command
			{
				int exp_int = 1;
				if (words.size() != exp_int)
					cout << "Words size is too big or small from your input!\n\n";
				else
				{
					timer->pt();
					std::cout << endl;
				}
				break;
			}
			else if (words[0] == "ru")	//run commnad
			{
				int exp_int = 2;
				if (words.size() != exp_int)
					cout << "Words size is too big or small from your input!\n\n";
				else if (stod(words[1]) <= 0)
					cout << "Cannot smaller and equal to 0";
				else
				{
					timer->ru(stod(words[1]), set_all.get());
					std::cout << "Current Time is " << stod(words[1]) << "s" << endl;
					map<int, map<int, map<int, Particle_s>::iterator>>::iterator it_all_set;
					for (it_all_set = (set_all->all_set_info).begin(); it_all_set != (set_all->all_set_info).end(); it_all_set++)	//scan all set
					{
						int set_num = it_all_set->first;	//set number
						set_all->print_set(set_num);
					}
				}
				break;
			}
			else if (words[0] == "rv")	//run with visualization command
			{
				int exp_int = 2;
				if (words.size() != exp_int)
					cout << "Words size is too big or small from your input!\n\n";
				else if (stod(words[1]) <= 0)
					cout << "Cannot smaller and equal to 0";
				else
				{
					timer->vis = true;
					timer->ru(stod(words[1]), set_all.get());
					timer->vis = false;
				}
				break;
			}
			else if (words[0] == "cp")	//particle fixatioin command
			{
				int exp_int = 3;
				if (words.size() != exp_int)
					cout << "Words size is too big or small from your input!\n\n";
				else if (particle_all->part_info.find(stoi(words[1])) == particle_all->part_info.end())
					// if particle number was not found after searching the map
					cout << "No particle with that number\n\n";
				else if (words[2] == "true")
				{
					particle_all->part_info[stoi(words[1])].cp = true;
					std::cout << "Particle " << words[1] << " is free now." << endl << endl;
				}
				else if (words[2] == "false")
				{
					particle_all->part_info[stoi(words[1])].cp = false;
					std::cout << "Particle " << words[1] << " is fixed now." << endl << endl;
				}
				break;
			}
			else if (words[0] == "cg")	//gravity on/off command
			{
				int exp_int = 2;
				if (words.size() != exp_int)
					cout << "Words size is too big or small from your input!\n\n";
				else if (words[1] == "true")
				{
					timer->cg = true;
					std::cout << "Gravity is now on." << endl << endl;
				}
				else if (words[1] == "false")
				{
					timer->cg = false;
					std::cout << "Gravity is now off." << endl << endl;
				}
				break;
			}
			else if (words[0] == "pa")
			{
				int exp_int = 1;
				if (words.size() != exp_int)
					cout << "Words size is too big or small from your input!\n\n";
				else
					particle_all->print_all();
				break;
			}
			else if (words[0] == "pm")
			{
				int exp_int = 1;
				if (words.size() != exp_int)
					cout << "Words size is too big or small from your input!\n\n";
				else
				{
					cout << "Particles: " << particle_all->part_info.size() << "\n";
					cout << "Sets: " << set_all->all_set_info.size() << "(including default set 0)\n";
					cout << "Forces: " << set_all->force_info.size() << "\n\n";
				}
				break;
			}
			else if (words[0] == "pg")
			{
				int exp_int = 1;
				if (words.size() != exp_int)
					cout << "Words size is too big or small from your input!\n\n";
				else
				{
					if (timer->cg == true)
						cout << "Gravity is active now\n\n";
					else
						cout << "Gravity is not acitve now\n\n";
				}
				break;
			}
			else
			{
				cout << "Unrecognized command!\n\n";
				break;
			}
		}

		std::cout << "Enter a command: ";
	}
}