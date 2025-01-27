// Worst cxx ever written award 

#include <cstring>
#include <iostream>
#include <bitset>
#include <unistd.h>
#include <sstream>

bool verbose = false;


class combination_yield{
	//char startchar, endchar;
	public:
	std::string combination;
	combination_yield() {
		this->combination = "0000";
	};
	std::string yield_combination(){
		int index = 3;
		char current = combination[index];
		while(index >= 0){ 
			char current = combination[index];
			if(current < 127) {
				combination[index] = ++current;
				break;
			}
			else { 
			combination[index] = '0';
			index--;
			}
		}
		return this->combination;
	}
	
};

//Me: can we have Cxx
//Mom: We have Cxx at home
//Cxx at home:
std::string encrypt(char* mystring){
	char* ptr = mystring;
	unsigned int tmp = 0;
	unsigned int hash = 0;
	// we don't need cbegin where we're going
	for (int i = 0; ptr, i<=3; *++ptr, ++i) {
		//if(verbose){
		std::bitset<16> x(*ptr);
		std::cout << "Pointer" << i << ":" << *ptr << "" << x <<"\n";
		//}
		tmp = *ptr << (i + 1);
		//if(verbose){
		std::bitset<16> y(tmp);
		std::cout << "Bitshift: " << y <<"\n";
		//}
		// i XOR i+1 
		hash ^= tmp;
		
	}
	hash ^= 4;
	hash ^= 0xCE4B;
	//std::cout << std::hex << hash << "\n";
	std::stringstream ss;
	ss << std::hex << hash;
	return ss.str(); 

}


int main(int argc, char *argv[])
{
	// https://stackoverflow.com/questions/15344714/convert-command-line-argument-to-string
	int opt = 0;
	combination_yield combinator;

	while ((opt = getopt(argc, argv, "e:c:h")) != -1) {
	switch(opt){
		case 'e':
			if(optarg) std::cout<<encrypt(optarg)<<"\n";
			break;
		case 'c':
			std::cout<<"Cracking time! \n";
            		while (true) {
                		std::string combination = combinator.yield_combination();
                		std::cout << "Trying combination: " << combination << "\n";

                		if (encrypt(combination.data()) == optarg) {
                    			std::cout << "Found a collision: " << combination << "\n";
                    			return 0;
				}
			}
			break;
		case '?':
		case 'h':
			std::cout<<"\n-h\tDisplay this help message\n -v\tVerbose output \n -e\tEncrypt \n -c \tCrack";
			break;
		default :
			std::cout<<"----------------------------------------" << "\n";
			std::cout<<"Excelfun — legacy Excel encrypter and cracker. " <<
				"\n v. 0.0.4 \n" << "Options:\n" << "\t -e Encrypt \n"
				<< "\t -c Crack the password using ASCII characters \n"; 
			break;
	}
	//  unsigned int test1 = pass[0];
	//  unsinged int test2
	//  test1 = test <<1;
	//  test2 = test<<2;
	// int hash test1 ^ test2 ^ test3 ^ test4;

}}

