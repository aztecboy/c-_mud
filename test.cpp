


#include <iostream>
#include <cstring>
struct UserData{
		std::string username;
		std::string player_class;

};
std::string replace_character( std::string string_to_replace, char character, std::string string){
		

		double string_size=string.size();
		
		double buffer=0;

		double current_string_to_replace_size=0;

		while(true){

				current_string_to_replace_size=string_to_replace.size();

				if(string_to_replace[buffer]==character){

						string_to_replace.replace(buffer,1,string);

						buffer+=string_size;

						continue;

				}

				if(buffer==current_string_to_replace_size){
						break;
				
				}

				buffer++;

		
		}		
		return string_to_replace;

}


class RoomDescriptions{
		public:
				std::string const WELCOME_TO_C="Welcome to the world of c++ brave adventurer!";
				std::string const WHAT_YOUR_NAME="What is your name?";
				std::string const ARE_SURE_NAME="Are you sure your name is *?";
				std::string const YES_NO="[y/n]";
				std::string const WELCOME_C_USER="Welcome to the world of c++ *!";
				std::string const USER_CLASSES="1: Warrior[w]\n2: Mage[m]";
				std::string const WHICH_CLASS="Which class do you choose?";
				std::string const ARE_SURE_CLASS="Are you sure your class is *?";
				std::string const INVALID_CLASS="That class does not exist";
};
class Rooms{
		public:
				RoomDescriptions room_descriptions;
				UserData choose_a_class(UserData user_data){
						while(true){
						
								to_terminal(room_descriptions.USER_CLASSES);

								to_terminal(room_descriptions.WHICH_CLASS);

								char reply=from_terminal_single_char();

								std::string user_class="";

								if(reply=='w'){

										user_class="warrior";
								}
								else if(reply=='m'){

										user_class="mage";

								}
								else{
										to_terminal(room_descriptions.INVALID_CLASS);
										continue;
								}

								to_terminal(replace_character(room_descriptions.ARE_SURE_CLASS,'*',user_class));

								if(yes_or_no_room()){
										user_data.player_class=user_class;
										break;

								}
						}
						
				return user_data;

				}
				bool yes_or_no_room(){
						

						while(true){

								to_terminal(room_descriptions.YES_NO);

								char reply=from_terminal_single_char();
						
								if(reply=='y'){
		
										return true;

								}
								else if(reply=='n'){
										
										return false;
						
								}	
								else{
								
										to_terminal(replace_character("must be a y or n character, you put in character *.",'*',std::to_string(reply)));
								
								}
						}

				}

				UserData welcome(UserData user_data){

						to_terminal(room_descriptions.WELCOME_TO_C);

						while(true){

								to_terminal(room_descriptions.WHAT_YOUR_NAME);
						
								user_data.username=from_terminal();
						
								to_terminal(replace_character(room_descriptions.ARE_SURE_NAME,'*',user_data.username));
						
								if(yes_or_no_room()){
										break;
								}


						}
						to_terminal(replace_character(room_descriptions.WELCOME_C_USER,'*',user_data.username));
					

						return user_data;
				}

		private:
				
				void to_terminal(std::string arg1){
						if(arg1==""){

								throw std::runtime_error("Cannot output an empty string");
						}

						std::string string_to_output=arg1;

						if(string_to_output.back()=='\n'){}

						else{
								string_to_output=string_to_output+'\n';

						}
						std::cout<<string_to_output;

						return;

				}
				std::string from_terminal(){

						std::string input="";

						std::cin>>input;

						return input;

				}
				char from_terminal_single_char(){

						std::string input="";

						std::cin>>input; 

						return tolower(input.front());

				}



};
int main(){
		Rooms rooms;
		RoomDescriptions room_descriptions;
		UserData user_data;
		
		user_data=rooms.welcome(user_data);

		user_data=rooms.choose_a_class(user_data);
		return 0;

}
