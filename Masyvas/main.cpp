#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Skaiciavimai();
void Nuskaitymas(string fv, int & nsk, int Nam[], int Gyv[]);
void Sudetis(int Gyv[], int Nam[], int nsk, double & sum, double & sum1, double & sum2, double & kn, double & dn);
double Vid(double sum, double a);
void Isvedimas(string fv, double sum, double sum1, double sum2, double vid1, double vid2);

const string Cdat = "data.txt";
const string Crez = "rez.txt";

int main()
{
	Skaiciavimai();
}

void Skaiciavimai()
{
	double sum = 0,
		sum1 = 0,
		sum2 = 0,
		kn = 0,
		dn = 0,
		vid1,
		vid2;
	const int Cmaxn = 500;
	int nsk;
	int Nam[Cmaxn];
	int Gyv[Cmaxn];
	
	Nuskaitymas(Cdat, nsk, Nam, Gyv);
	Sudetis(Gyv, Nam, nsk, sum, sum1, sum2, kn, dn);
	vid1 = Vid(sum1, dn);
	vid2 = Vid(sum2, kn);
	Isvedimas(Crez, sum, sum1, sum2, vid1, vid2);
}


void Nuskaitymas(string fv, int & nsk, int Nam[], int Gyv[])
{
	ifstream inFile(fv);
	inFile >> nsk;
	for(int i = 0; i < nsk; i++)
	{
		inFile >> Nam[i] >> Gyv[i];
		
	}
	inFile.close();
}

double Vid(double sum, double a)
{
	return sum / a;
}

void Sudetis(int Gyv[], int Nam[], int nsk, double & sum, double & sum1, double & sum2, double & kn, double & dn)
{
	for(int i = 0; i < nsk; i++)
	{
		if(Nam[i] % 2 > 0)
		{
			sum1 += Gyv[i];
			dn++;
		}
		else
		{
			sum2 += Gyv[i];
			kn++;
		}
	}
	sum = sum1 + sum2;
}

void Isvedimas(string fv, double sum, double sum1, double sum2, double vid1, double vid2)
{
	ofstream outFile(fv);
	outFile << fixed << setprecision(2) << setw(2) << sum << endl;
	outFile << fixed << setprecision(2) << setw(2) << sum1 << endl;
	outFile << fixed << setprecision(2) << setw(2) << sum2 << endl;
	outFile << fixed << setprecision(2) << setw(2) << vid1 << endl;
	outFile << fixed << setprecision(2) << setw(2) << vid2 << endl;
	outFile.close();
}