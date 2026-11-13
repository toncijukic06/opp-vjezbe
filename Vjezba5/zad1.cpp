#include <iostream>
#include <cassert>

class Volume { 
	int glasnoca;
	int pamti_glasnocu;
	static int restrict(int l){
			if (l < 0)
				return 0;
			if (l > 100)
				return 100;
			return l;
	}

private:
	bool valid() const {
		return glasnoca >= 0 and glasnoca <= 100;
	}

public:
		Volume(int l): glasnoca(l){
		if (l > 100) {
			glasnoca = 100;
		}
		if (l < 0) {
			glasnoca = 0;
		}
	}
		Volume() : Volume(50) {}

		int get() const {
			return glasnoca;
		}

		void up(int step = 10) {
			glasnoca= restrict(glasnoca+ step);
			pamti_glasnocu= glasnoca;
			assert(valid());
		}

		void down(int step = 10)
		{
			glasnoca= restrict(glasnoca - step);
			pamti_glasnocu= glasnoca;
			assert(valid());
		}
		void mute() {
			glasnoca = 0;
		}
		void unmute() {

			glasnoca = pamti_glasnocu;

		}

		


};

int main()
{
	Volume v;
	std::cout << v.get() << '\n';
	v.up();
	v.up(60);
	std::cout << v.get() << '\n';
	v.mute();
	std::cout << v.get() << '\n';
	v.unmute();
	std::cout << v.get() << '\n';
	Volume w(-20);
	w.down();
	std::cout << w.get() << '\n';
	return 0;
}

/*
Ocekivani ispis:

	50
	100
	0
	100
	0
*/
