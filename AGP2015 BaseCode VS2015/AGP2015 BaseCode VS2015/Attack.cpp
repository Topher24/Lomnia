#include "Attack.h"
#include "Character.h"





float C_Attack::damageCalc(Character& a, Character& b) //A is attacker, B is victim
{
	float res = b.ResSelect(resType); //Sets the resistance value according to the element of the attack being used (eg. fireRes for fire attacks)
	
	int damage = (a.strength +  (rand() % maxDamage + minDamage)); //Damage is comprised of both statistic strength and the power of the weapon

	damage = (damage - b.defence)*res;
	if (damage < 1)
		damage = 1;

	cout << attackText << " deals " << damage << " points of damage to " << b.name << "! " << endl << endl;
	return damage;
}

void C_Attack::Attack(Character& attacker, Character &opponent, int block)
{
	

	int damage = (damageCalc(attacker, opponent)/block) ;// rand() % maxDamage + minDamage;
	opponent.Damage(damage);
	cout << damage << " damage done to " << attacker.name << " using " << attackText << endl;
	attackCompleted = true;
}

void C_Attack::FailedBlockedAttack(Character& attacker, Character &opponent)
{
	cout << attacker.name << " FAILED BLOCK ATTACK!" << endl;
	blockingTime = 0; 
	blockingStatus = 2;

	Attack(attacker, opponent,  1);
}

void C_Attack::BlockedAttack(Character& attacker, Character &opponent)
{
	cout << attacker.name << " BLOCKED ATTACK!" << endl;
	blockingTime = 0;
	blockingStatus = 1;
	Attack(attacker, opponent, 2);
}



class Skill
{
public:
	string name;
	int cost;
	int power;

	int resType; // 0 = normal, 1 = fire, 2 = water, 3 = wind, 4 = earth
}light, heavy, fire, water, wind, earth;