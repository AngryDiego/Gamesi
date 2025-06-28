#include <iostream>
#include <vector>
#include <memory>

class Character {
protected:
	int health;
	int speed;

public:
	int GetHealth() const {
		return health;
	}

	Character(int h, int s) {
		health = h;
		speed = s;
	}

	Character (int& health, int& speed) : health(health), speed(speed) {}

	virtual std::string Attack() const = 0;

	virtual std::string Movement() const = 0;
};

class Warrior : public Character {
public :

	Warrior(int h, int s) : Character (std::move(h), std::move(s)) {}

	std::string Attack() const override {
		return "Warrior is attacking";
	}

	std::string Movement() const override {
		return "Warrior is moving";
	}
};

class Wizard : public Character {
public:

	Wizard(int h, int s) : Character(std::move(h), std::move(s)) {}

	std::string Attack() const override {
		return "Wizard is casting fire bolt (I hate spell casters in DnD (They are unbalanced, literally any problem solved eather thru 'control person' or 'fire ball' and i`m not even talking about 'mage armor'. Their damage is too high compared to marshal classes.))";
	}

	std::string Movement() const override {
		return "Wizard is moving";
	}
};

class Archer : public Character {
public:

	Archer(int h, int s) : Character(std::move(h), std::move(s)) {}

	std::string Attack() const override {
		return "Archer is shooting";
	}

	std::string Movement() const override {
		return "archer is moving";
	}
};

int main() {
	std::vector<std::unique_ptr<Character>> characters ; // Creating vector with Unoque ptr and which have name "characters"
	characters.push_back(std::make_unique<Warrior>(100, 35)) ;// Creating Unique warrior and pushing it back (pushing it back to the front lines :3 )
	characters.push_back(std::make_unique<Archer>(65, 25));

	for (auto& character : characters) { //Creating For with size of vector
		std::cout << character->Attack() << ", " << character->Movement() << std::endl;// Making output of current character and Attack with movement by using -> (idk how or why it works)
	}
}
