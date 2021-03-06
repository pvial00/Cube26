#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <algorithm>
#include "cube26.cpp"

int numchars = 1;

using namespace std;

void usage() {
	    cout << "Cube26Random - RNG" << "\n";
	    cout << "---------------------------------------------------------\n";
	    cout << "Usage: cube26random <num of characters>" << "\n";
}

int main(int argc, char** argv) {
    string bytes;
    if (argc < 2) {
        usage();
	exit(1);
    }
    if (argc >= 2) {
        numchars = atoi(argv[1]);
    }
    CubeRandom rand;
    bytes = rand.random(numchars);
    for (unsigned char b: bytes) {
        cout << b;
    }
    return 0;
}
