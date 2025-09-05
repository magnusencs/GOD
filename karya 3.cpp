#include <iostream>
#include <cstdlib>
#include <ctime>
#include <mmstream.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib")
using namespace std;
int main () 
{

 srand(time(0)); 
  int randomnum = rand()% 50 + 1;
  int tebak;
  int percobaan = 5;

  cout<<"selamat datang di game tebak angka!;"<<endl;
   PlaySound(TEXT("C:\\Users\\MyBook Hype\\Videos\\"), NULL, SND_FILENAME | SND_ASYNC);
   //ah capek ah
  do {
  	cout<<"tebak angka anda 1-50"<<endl;
  	cin>>tebak;
  	percobaan++;
  	if (tebak>randomnum) 
  	{cout<<"terlalu besar, coba lagi.";
	  }
	  else if ( tebak <randomnum)
	  {cout<<"terlalu kecil,coba lagi, ";
	  }
	 else {cout<<"anda benar"<<endl;
	 cout<<"anda berhasil menebak angka dalam"<<percobaan<<"kali percobaaan"<<endl;
  }
   
	  }while (tebak != randomnum);
  return 0;

  } 
	
