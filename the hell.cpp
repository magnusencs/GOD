// im all out of hope: char 19 time 3.18
// one more bad dream: char 18 time 2.51
// could bring a fall: char 18 time 2.47
// when im far from home: char 21 time 3.85
// dont call me on the phone: char 25 time 2.53
// to tell me youre alone: char 22 time 3.09
// its easy to deceive... its easy to tease... but hard to get release: char 67 time 10.19



/* 
"im all out of hope"

Characters: 19

Time: 3.18 sec

Delay per char: (3.18 / 19) * 1000 ≈ 167.37 ms

"one more bad dream"

Characters: 18

Time: 2.51 sec

Delay per char: (2.51 / 18) * 1000 ≈ 139.44 ms

"could bring a fall"

Characters: 18

Time: 2.47 sec

Delay per char: (2.47 / 18) * 1000 ≈ 137.22 ms

"when im far from home"

Characters: 21

Time: 3.85 sec

Delay per char: (3.85 / 21) * 1000 ≈ 183.33 ms

"dont call me on the phone"

Characters: 25

Time: 2.53 sec

Delay per char: (2.53 / 25) * 1000 ≈ 101.2 ms

"to tell me youre alone"

Characters: 22

Time: 3.09 sec

Delay per char: (3.09 / 22) * 1000 ≈ 140.45 ms

"its easy to deceive... its easy to tease... but hard to get release"

Characters: 67

Time: 10.19 sec

Delay per char: (10.19 / 67) * 1000 ≈ 152.09 ms

*/

#include <iostream>
#include <chrono>
#include <string>
#include <thread>
#include <mmstream.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib")
#define end cout<<endl;

using namespace std;
	 
	  void d (string lyrics, int timeperchar, int delayafter) {
	  		 
	  		 for (char c : lyrics)
	  		 {
	  		 	cout<<c<<flush;
	  		 	this_thread::sleep_for(chrono::milliseconds(timeperchar));
	  		 	
			   }
			this_thread::sleep_for(chrono::milliseconds(delayafter));
	  }
		
	int main ()
		{ 	char rep;
		do {
		
			cout<<"start?";
			char ask;
			cin>>ask;
			if (ask == 'y'){

				PlaySound(TEXT("C:\\Users\\MyBook Hype\\Videos\\BILLYIDOL.WAV"), NULL, SND_FILENAME | SND_ASYNC);
			
			d ("im all out of hope", 168, 1010);
			  end;
			d ("one more bad dream", 80, 1250);
			  end;
			d ("could bring a fall", 90, 2300);
			  end;
	        d ("when im far from home", 134, 550);
	          end;
	        d ("dont call me on the phone", 80, 760);
	          end;
			d ("to tell me you're alone",90, 2220);
			  end; 
			d ("it's easy to deceive..", 160, 810);
			  end;
			d ("it's easy to tease....", 90, 680);
			  end;
			d ("but hard to get release", 90, 2200);
			  end;
			cout<<"                             "; d("@hbbrhmn_class.keter", 150, 1);
			
			
		for (int i = 0; i<= 300; i++){
			cout<<" "<<endl;
		}
		
		}
		
		else {return 1;
		
		} cout<<"ulang? ";
	
		cin>>rep;
		}
		

		while (rep == 'y');
		
	return 0;
	
		}












