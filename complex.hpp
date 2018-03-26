#ifndef COMPLEX
#define COMPLEX
class complex
{
public:
	complex(double rea,double imaginar)
	{
		//complex initialiser
		real = rea;
		imaginary=imaginar;
	}
	complex operator+(const complex& other) const
	{
		complex result;
		result.real=real+other.real;
		result.imaginary=imaginary+other.imaginary;
	}
	double real;
	double imaginary;
};
#endif
