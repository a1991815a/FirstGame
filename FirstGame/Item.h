#ifndef __ITEM__
#define __ITEM__

class Item{
public:
	Item(){};
	Item(string name, int hp, int money){
		_name = name;
		_hp = hp;
		_money = money;
	}

	inline int getHp() const { return _hp; }
	inline void setHp(int val) { _hp = val; }
	inline int getMoney() const { return _money; }
	inline void setMoney(int val) { _money = val; }
	inline std::string getName() const { return _name; }
	inline void setName(std::string val) { _name = val; }
private:
	string _name;
	int _hp;
	int _money;
};
#endif