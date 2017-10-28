#ifndef protHeadArduino
#define protHeadArduino

#include <cstdio>
#include <vector>
#include <iostream>

class arduino
{

	public:
	void start();
	void stop();
	void read();
	std::string output();

	private:
	FILE* arduinoFile;
	std::vector<int> durations;

};

#endif
