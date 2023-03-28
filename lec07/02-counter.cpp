#include <iostream>

class Counter {
	protected:
		int value, load;
	public:
		virtual void inc () { value++; }
		void reset () { value = load; }
		int get () const { return value; }
		Counter (int val = 5) : load (val) { reset (); }
};

class CounterMod : public Counter {
	protected:
		int mod;
	public:
		void inc ();
		CounterMod (int val, int modulus);
};

CounterMod::CounterMod (int v, int m) :
	// volání konstruktoru předka
	Counter (v % m) { mod = m; }

void CounterMod::inc () {
	Counter::inc (); // volání metody inc () předka
	value = value % mod;
}

void callCounter (Counter * x)
{
	for (int i = 0; i < 10; i++, x->inc())
		std::cout << x->get();
}

int main()
{
    Counter a(0);
    CounterMod b(0,3);

    for (int i = 0; i < 10; i++, a.inc(), b.inc())
    {
        std::cout << "a: " << a.get() << "\tb: " << b.get() << "\n";
    }

	callCounter (new Counter(0));
	std::cout << std::endl;
	callCounter (new CounterMod(0, 3));

    return 0;
}