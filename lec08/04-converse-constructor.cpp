#include <iostream>

struct Double {
	Double (int a) { 
		std::cout << "int\n"; 
	}
	// zákaz implicitní konverze
	explicit Double (long a) { 
		std::cout << "long\n"; 
	}
};

int main() {
	Double a = 10L;
	// 10L je long, ale implicitni konverze long -> Double je zakazana
    // kompilator proto hleda jiny vhodny konstruktor 
	// Je treba ji provest explicitne
    Double b = Double(10L);

    return 0;
}