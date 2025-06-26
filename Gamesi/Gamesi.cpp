#include <iostream>

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

	virtual std::string Attack() const = 0;

	virtual std::string Movement() const = 0;
};

class Warrior : public Character {
	std::string Attack() const override {
		return "Warrior is attacking";
	}

	std::string Movement() const override {
		return "Warrior is moving";
	}
};

class Wizard : public Character {
	std::string Attack() const override {
		return "Wizard is casting fire bolt (I hate spell casters in DnD (They are unbalanced, literally any problem solved eather thru 'control person' or 'fire ball' and i`m not even talking about 'mage armor'. Their damage is too high compared to marshal classes.))";
	}

	std::string Movement() const override {
		return "Wizard is moving";
	}
};

class Archer : public Character {
	std::string Attack() const override {
		return "Archer is shooting";
	}

	std::string Movement() const override {
		return "archer is moving";
	}
};

int main() {
}
