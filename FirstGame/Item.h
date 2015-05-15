#ifndef __ITEM__
#define __ITEM__

class Item{
public:
	Item(){};
	Item(int hp, int money){
		_hp = hp;
		_money = money;
	}

	inline int getHp() const { return _hp; }
	inline void setHp(int val) { _hp = val; }
	inline int getMoney() const { return _money; }
	inline void setMoney(int val) { _money = val; }
private:
	int _hp;
	int _money;
};
#endif