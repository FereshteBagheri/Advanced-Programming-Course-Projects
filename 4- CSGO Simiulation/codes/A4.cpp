#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define KNIFE_DAMAGE 35
#define KNIFE_REWARD 500
#define HEAVY_PRICE 3000
#define HEAVY_DAMAGE 45
#define HEAVY_REWARD 100
#define PISTOL_PRICE 400
#define PISTOL_DAMAGE 20
#define PISTOL_REWARD 200
#define PRIMARY_MONEY 1000
#define COMMAND_DONE ok

struct weapon {
	int price=0;
	int damage=0;
	int killing_reward=0;
};

void split_string(string input, vector <string>& output, char delimiter) {
	stringstream s(input);
	string temp;
	while (getline(s, temp, delimiter)) {
		output.push_back(temp);
	}
}

void set_weapon_attributes(string weapon_type, weapon& weapon) {
	if (weapon_type == "knife") {
		weapon.damage = KNIFE_DAMAGE;
		weapon.killing_reward = KNIFE_REWARD;
	}
	else if (weapon_type == "heavy") {
		weapon.price = HEAVY_PRICE;
		weapon.damage = HEAVY_DAMAGE;
		weapon.killing_reward =HEAVY_REWARD ;
	}
	else if (weapon_type == "pistol") {
		weapon.price =PISTOL_PRICE ;
		weapon.damage = PISTOL_DAMAGE;
		weapon.killing_reward = PISTOL_REWARD;
	}
}




class Player {
public:
	Player(string name) {
		username = name;
	}
	string get_username();
	string get_team();
	vector<string> get_weapons();
	void go_afk();
	void go_atk();
	void set_team(string team_name);
	void set_round_primary_health();
	void add_money(int amount);
	void reduce_health(int damage);
	void increase_kills_by_one();
	void shoot(Player& attacked, string weapon_type);
	void buy_weapon(string weapon_type);
	int get_money();
	int get_health();
	bool is_teammate(Player player);
	bool has_weapon(string weapon);
	bool get_afk_status();
	bool get_death_status();
private:
	string username;
	string team;
	int health=100;
	int money=0;
	int kills=0;
	int deathes=0;
	vector <string> weapons;
	bool is_afk = false;
	bool is_dead=false;
};

int Player:: get_money() {
	return money;
}

string Player:: get_username() {
	return username;
}

int Player :: get_health() {
	return health;
}

string  Player::get_team() {
	return team;
}

bool  Player::get_afk_status() {
	return is_afk;
}

bool  Player::get_death_status() {
	return is_dead;
}

vector<string>  Player::get_weapons() {
	return weapons;
}
 
bool  Player::has_weapon(string weapon) {
	for (int i = 0; i < get_weapons().size(); i++) {
		if (weapon == get_weapons()[i]) {
			return true;
		}
	}
	return false;
}

void  Player::go_afk() {
	is_afk = true;
}

void  Player::go_atk() {
	is_afk = false;
}

void  Player::set_team(string team_name) {
	team = team_name;
}

bool Player::is_teammate(Player player) {
	if (get_team() == player.get_team()) {
		return true;
	}
		return false;
}

void Player :: add_money(int amount) {
	money += amount;
}

void Player::reduce_health(int damage) {
	health -= damage;
	if (health <= 0) {
		health = 0;
		deathes++;
	}
}

void Player::set_round_primary_health() {
	health = 100;
}

void Player :: increase_kills_by_one(){
	kills++;
}

void Player :: shoot(Player& attacked,string weapon_type) {
	weapon weapon;
	set_weapon_attributes(weapon_type, weapon);
	attacked.reduce_health(weapon.damage);
	if (attacked.get_health() == 0) {
		kills++;
		money += weapon.killing_reward;
	}
}

void Player::buy_weapon(string weapon_type) {
	weapon weapon;
	set_weapon_attributes(weapon_type, weapon);
	if (weapon.price > money) {
		cout << "insufficient money" << endl;
	}
	else {
		money -= weapon.price;
		weapons.push_back(weapon_type);
		cout<< "weapon bought successfully" << endl;
	}
}

class Round {
public:
	void set_start();
	bool get_start_status();
private:
	bool is_started=false;
};

void Round:: set_start() {
	is_started = true;
}

bool Round :: get_start_status() {
	return is_started;
}

class Command {
public:
	vector <string> splitted_line;
	Command(string command_line) {
		split_string(command_line, splitted_line, ' ');
		command = splitted_line[0];
	}
	void start(Round& round);
	void add_user(vector<Player>& all_players);
	void get_money(vector<Player> all_players);
	void get_health(vector<Player> all_players);
	void go_afk(vector<Player>& all_players);
	void go_atk(vector<Player>& all_players);
	void shoot(vector<Player>& all_players, Round& round);
	void buy(vector<Player>& all_players, Round& round);
	void manage_command(vector<Player>& all_players, Round& round);
private:
	string command;
	bool is_started;
};

void Command::start(Round& round) {
	round.set_start();
	cout << "fight!" << endl;
 }

void Command::add_user(vector<Player>& all_players) {
	Player new_member(splitted_line[1]);
	new_member.add_money(PRIMARY_MONEY);
	if (splitted_line[2]=="terrorist") {
		new_member.set_team("terrorist");
	}
	else if (splitted_line[2] == "counter-terrorist") {
		new_member.set_team("counter-terrorist");
	}
	all_players.push_back(new_member);
	cout << "ok" << endl;
}

void Command::get_money(vector<Player> all_players){
	for (int i = 0; i < all_players.size(); i++) {
		if (splitted_line[1] == all_players[i].get_username()) {
			cout << all_players[i].get_money() << endl;
		}
	}
}

void Command::get_health(vector <Player> all_players){
	for (int i = 0; i < all_players.size(); i++) {
		if (splitted_line[1] == all_players[i].get_username()) {
			cout << all_players[i].get_health() << endl;
		}
	}
}

void Command::go_afk(vector<Player>& all_players) {
	for (int i = 0; i < all_players.size(); i++) {
		if (splitted_line[1] == all_players[i].get_username()) {
			all_players[i].go_afk();
		}
	}
	cout << "OK" << endl;
}

void Command::go_atk(vector<Player>& all_players) {
	for (int i = 0; i < all_players.size(); i++) {
		if (splitted_line[1] == all_players[i].get_username()) {
			all_players[i].go_atk();
		}
	}
	cout << "ok" << endl;
}

void Command::shoot(vector<Player>& all_players, Round& round) {
	if (!round.get_start_status()) {
		cout << "The game hasn't started yet" << endl;
	}
	else {
		int attacker_index = -1;
		int attacked_index = -1;
		for (int i = 0; i < all_players.size(); i++) {
			if (splitted_line[1] == all_players[i].get_username()) {
				attacker_index = i;
				break;
			}
		}
		for (int i = 0; i < all_players.size(); i++) {
			if (splitted_line[1] == all_players[i].get_username()) {
				attacked_index = i;
				break;
			}
		}
		if (attacker_index == -1 || attacked_index == -1) {
			cout << "user not available" << endl;
		}
		else if (all_players[attacker_index].get_afk_status() || all_players[attacked_index].get_afk_status()) {
			cout << "user not available" << endl;
		}
		else if (all_players[attacker_index].get_death_status()) {
			cout << "attacker is dead" << endl;
		}
		else if (all_players[attacked_index].get_death_status()) {
			cout << "attacked is dead" << endl;
		}
		else if (!all_players[attacker_index].has_weapon(splitted_line[3])) {
			cout << "attacker doesn't have this gun" << endl;
		}
		else if (all_players[attacker_index].is_teammate(all_players[attacked_index])) {
			cout << "you can't shoot this player" << endl;
		}
		else {
			all_players[attacker_index].shoot(all_players[attacked_index], splitted_line[3]);
			cout << "nice shot" << endl;
		}
	}
}

void Command::buy(vector<Player>& all_players, Round& round) {
	if (round.get_start_status()) {
		cout << "you can't buy weapons anymore" << endl;
	}
	else {
		int buyer_index=-1;
		for (int i = 0; i < all_players.size(); i++) {
			if (splitted_line[1] == all_players[i].get_username()) {
				buyer_index = i;
				break;
			}
		}
		if (buyer_index == -1 || all_players[buyer_index].get_afk_status()) {
			cout << "user not available" << endl;
		}
		else if (!(splitted_line[2] == "knife" || splitted_line[2] == "heavy" || splitted_line[2] == "pistol")) {
			cout << "weapon not available"<<endl;
		}
		else if (all_players[buyer_index].has_weapon(splitted_line[2])) {
			cout << "you already have this weapon" << endl;
		}

		else {
			all_players[buyer_index].buy_weapon(splitted_line[2]);
		}
	}
}

void Command::manage_command(vector<Player>& all_players, Round& round) {
	if (command == "start")
		start(round);
	else if (command == "add-user")
		add_user(all_players);
	else if (command == "get-money")
		get_money(all_players);
	else if (command == "get-health")
		get_health(all_players);
	else if (command == "go-afk")
		go_afk(all_players);
	else if (command == "go-atk")
		go_atk(all_players);
	else if (command == "shoot")
		shoot(all_players,round);
	else if (command == "buy")
		buy(all_players, round);
}

int main() {

	string input;
	vector<Player> all_players;
		Round round;
		while (getline(cin, input)) {
			vector <string> temp;
			split_string(input, temp, ' ');
			Command c(input);
			c.manage_command(all_players, round);
			if (temp[0] == "round") {
				for (int j = 0; j < stoi(temp[1]); j++) {
					getline(cin, input);
					Command c(input);
					c.manage_command(all_players, round);
				}
				//cout the resault
				break;
			}
		}

	return 0;
}