
/*#include <iostream>
using namespace std;
int main ()
{
	string nama = "jimmy";
	cout<<"nama saya: "<<nama;
	
	return 0;
}
"sdhfsldfs" //string
234232 //int
  short int;
  unsigned short int;
  unsigned long int;
  long int;
  bool; //true or false || 0 atau 1
  
3.14 //float
's' //char

const float pi = 3.14


float =3.222;
double = 239.347923742834

spara_nama[3]= "jimmi", "habib", "rahmat", "hapis";
tring 
cout<<para_nama[1];

vector <string> nama;

nama.push_back(para_nama[1]);
nama.push_back(para_nama[0]);

for (int i = 0; i<=1000; ++i) 
{
	nama.push_back(para_nama[i]);
}

while (i!= 1000) {
	nama.push_back(para_nama[i]);
	i++;
}

string kalimat = "saya suka huruf CCCCC";
bool firsttime = true;
for (int j = 0; j<=kalimat.size(); ++i)
{
if (firsttime) {
  if (kalimat[j]== 'C';)
  {
  	kalimat [j] == 'D';
  }
  cout<<kalimat[j];
}
firsttime = false;
	
}

// saya suka huruf DCCCC;


if (firsttime)
// if (firsttme == true)
// if (firsttime== false)
 if (!firsttime)
*/



#include <Iostream>
using  namespace std;


bool checkall (int age, bool gender, bool rec)
{
	return (age >= 28 && gender && rec>=8);
}

int main ()
{
	bool iswoman = false;
	cout<<"enter your age: ";
	int ag;
	cin>>ag;
	cout<<"enter your gender (m/f)";
	char ask;
	cin>>ask;
	cout<<"enter your social val: ";
	int val;
	cin>>val;
	
	
	
	if(ask == 'm') {
		iswoman = true;
	}
	
	checkall(ag, iswoman, val);
	
	if (checkall(ag, iswoman, val)) {
		cout<<"anda boleh masuk";
	}
	else {
		cout<<"condition met not.";
		return 1;
	}
	
}
