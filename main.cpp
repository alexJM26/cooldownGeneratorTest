#include <iostream>
#include <fstream>
#include <string>

int main() {

	std::string powerNames[3];
	int cooldowns[3];
	int minutes, seconds;

	std::ofstream out("CooldownFile.txt");

	std::cout << "Input Power Names: ";
	std::cin >> powerNames[0] >> powerNames[1] >> powerNames[2];
	std::cout << "Input Respective Cooldowns: ";
	std::cin >> cooldowns[0] >> cooldowns[1] >> cooldowns[2];

	for (int i = 0; i < 3; ++i) {
		std::string name = powerNames[i];
		int j = 0;
		while (j < name.size()) {
			if (name[j] == '_') name[j] = ' ';
			j++;
		}
		powerNames[i] = name;
	}

	out << "## POWER 1: " << powerNames[0] << std::endl;

	// power 1
	for (int i = cooldowns[0]; i >= 0; i-=20) {
		minutes = i / 1200;
		seconds = (i - ((i / 1200) * 1200)) / 20;

		if (seconds == 0 && minutes == 0) break;

		if (seconds >= 10)
			out << "execute if entity @s[scores={cooldown1=" << i - 19 << ".." << i << ",powerSlot=0}] run title @s actionbar "
				<< powerNames[0] << ": " << minutes << ":" << seconds << std::endl;
		else 
			out << "execute if entity @s[scores={cooldown1=" << i - 19 << ".." << i << ",powerSlot=0}] run title @s actionbar "
			<< powerNames[0] << ": " << minutes << ":0" << seconds << std::endl;
	}

	out << std::endl << "## POWER 2: " << powerNames[1] << std::endl;

	// power 2
	for (int i = cooldowns[1]; i >= 0; i-=20) {
		minutes = i / 1200;
		seconds = (i - ((i / 1200) * 1200)) / 20;

		if (seconds == 0 && minutes == 0) break;

		if (seconds >= 10)
			out << "execute if entity @s[scores={cooldown2=" << i - 19 << ".." << i << ",powerSlot=1}] run title @s actionbar "
				<< powerNames[1] << ": " << minutes << ":" << seconds << std::endl;
		else
			out << "execute if entity @s[scores={cooldown2=" << i - 19 << ".." << i << ",powerSlot=1}] run title @s actionbar "
			<< powerNames[1] << ": " << minutes << ":0" << seconds << std::endl;

	}

	out << std::endl << "## POWER 3: " << powerNames[2] << std::endl;

	// power 3
	for (int i = cooldowns[2]; i >= 0; i-=20) {
		minutes = i / 1200;
		seconds = (i - ((i / 1200) * 1200)) / 20;

		if (seconds == 0 && minutes == 0) break;

		if (seconds >= 10)
			out << "execute if entity @s[scores={cooldown3=" << i - 19 << ".." << i << ",powerSlot=2}] run title @s actionbar "
				<< powerNames[2] << ": " << minutes << ":" << seconds << std::endl;
		else
			out << "execute if entity @s[scores={cooldown3=" << i - 19 << ".." << i << ",powerSlot=2}] run title @s actionbar "
			<< powerNames[2] << ": " << minutes << ":0" << seconds << std::endl;
	}
}