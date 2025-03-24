#include <iostream>

class Rectangle
{
	private:
		double length;
		double width;
	
	public:
		 
		void set_dimension(double l, double w)
		{
			length = l;
			width = w;
		}
		
		double per(void);
};

double Rectangle::per(void)
{
	return (3);
}

int main(void)
{
	Rectangle rectangle1;

	rectangle1.set_dimension(10,20);
	return (0);
}