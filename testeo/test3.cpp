// C++ Program to Demonstrate
// Operator Overloading
#include <iostream>
class Integer {
	private:
	public:
	Integer(int v = 0) : value(v) {}
	
	Integer &operator=(Integer const &rhs) {
		if (this != &rhs) {  // Evitar autoasignación
			value = rhs.value;
		}
		std::cout << "operator " << value << std::endl;
		return *this;  // Devolver referencia al objeto actual
	}
	int value;
};

Integer::Integer(int const n)

int main()
{
	
	return (0);
}