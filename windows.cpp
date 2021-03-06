#include <iostream>

using namespace std;

// creates structure for a sample
struct hit
{
	double depth;
	double hardness;
};

int main ()
{
	// initalizes varibles 
	hit hit1,hit2,hit3,hit4;
	double mindepth = 0;
	double rc=0;
	const double space = 0.004;
	double rcdepth;
	double tolerance = 0; 
	double casedepth= 0 ;
	
	//gathers the desired case hardness or the RC value and performs data validation
	while (rc <= 0)
	{
		cout << "what is the desired case hardness? ";
		cin >> rc;

		if (rc <= 0)
		{
			cout << "please input a value greater than zero for the hardness " << endl;
		}
	}
	
	// gathers the case depth and tolerence information and peforms data validation
	while (casedepth <= 0 && casedepth - tolerance <= 0)
	{
		cout << "what is the case depth of the part? ";
		cin >> casedepth;

		cout << "what is the tolerance of the part? ";
		cin >> tolerance;

		if ((casedepth - tolerance) < 0)
		{
			cout << "the minimum case depth is below zero please input proper values for case and tolerance" << endl;
		}

		if (casedepth < 0 )
		{
			cout << "the case depth you entered is below zero please input a proper casedetph" << endl;
		}

		if (tolerance < 0)
		{
			cout << " the tolerance you entered is less than zero please input a propertolerance " << endl;
		}
	}
	
	// calulates the the case depth 
	mindepth = casedepth - tolerance;
	hit3.depth = casedepth + tolerance;
	hit1.depth = hit3.depth - 2 * space;
	hit2.depth = hit3.depth - space;
	hit4.depth = hit3.depth + space;

	//gathers information of the samples 
	cout << "what is the value of hit 1? ";
	cin >> hit1.hardness;

	cout << "what is the value of hit 2? ";
	cin >> hit2.hardness;

	cout << "what is the value of hit 3? ";
	cin >> hit3.hardness;

	cout << "what is the value of hit 4? ";
	cin >> hit4.hardness;


	// calulates the case depth in thousandths of an inch
	// using the linear interpolation formula based on were it drops below the desired hardness 
	if (hit1.hardness > rc &&  hit2.hardness < rc)
	{
		rcdepth = hit1.depth + .004*(hit1.hardness - rc) / (hit1.hardness - hit2.hardness);
	}

	else if (hit2.hardness > rc &&  hit3.hardness < rc)
	{
		rcdepth = hit2.depth + .004*(hit2.hardness - rc) / (hit2.hardness - hit3.hardness);
	}

	else if (hit3.hardness > rc &&  hit4.hardness < rc)
	{
		rcdepth = hit3.depth + .004*(hit3.hardness - rc) / (hit3.hardness - hit4.hardness);

	}

	else
	{
		rcdepth = 1;
	}


	// prints out the results and tells the user what to do about it 
	cout << " the case depth is " << rcdepth << endl ;

	if (rcdepth >= mindepth && rcdepth <= hit3.depth)
	{
		cout << " this part passes go ahead and pull that hold tag :) " << endl;
	}

	else if (rcdepth > hit3.depth)
	{
		cout << " this part is overcased please" << endl << "raise the temperature by redrawing the part at " << 300 + 30 * (hit3.hardness - rc) << endl;
	}

	else if (rc > hit1.hardness)
	{
		cout << " You done goofed up  and you either to: " << endl;
		cout << " 1. Take your survey at a lower depth";
		cout << " 2. create a new sample and try again";
	}
	
	else
	{
		cout << "this part is undercased" << endl;
	}

	cout << "hit 1 was taken at " << hit1.depth << endl;
	cout << "hit 2 was taken at " << hit2.depth << endl;
	cout << "hit 3 was taken at " << hit3.depth << endl; 
	cout << "hit 4 was taken at " << hit4.depth << endl; 
	
	system("pause");
	
	return 0;
}


