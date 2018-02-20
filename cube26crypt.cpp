#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <algorithm>
#include "cube26.cpp"

int iterations = 69;
int keylen = 128;
int nonce_length = 16;
int mac_length = 16;

using namespace std;

void usage() {
    cout << "Usage: cube26 <encrypt/decrypt> <input file> <output file> <password>" << "\n";
}

int main(int argc, char** argv) {
    ifstream infile;
    ofstream outfile;
    string mode, in, out, key, msg, nonce, data, mac;
    unsigned char b;
    int i;
    if (argc < 5) {
        usage();
        exit(EXIT_FAILURE);
    }
    mode = argv[1];
    in = argv[2];
    out = argv[3];
    key = argv[4];
    string random_dev = "/dev/urandom";
    infile.open(in.c_str(), std::ios::binary);
    infile.seekg(0, ios::end);
    int fsize = infile.tellg();
    infile.close();
    infile.open(in.c_str(), std::ios::binary);
    if (mode == "encrypt") {
        fsize = fsize - 1;
    }
    for (i = 0; i < fsize; i++) {
        b = infile.get();
	data.push_back(b);
    }
    infile.close();
    CubeKDF kdf;
    key = kdf.genkey(key, keylen, iterations);
    Cube cube;
    CubeMAC cubemac;
    if (mode == "encrypt") {
	CubeRandom rand;
	nonce = rand.random(nonce_length);
    	data = cube.encrypt(data, key, nonce);
	mac = cubemac.mac(data, key, mac_length);
	cout << mac.length() << "\n";
        outfile.open(out.c_str());
	outfile << mac+nonce+data;
	outfile.close();
    }
    else if (mode == "decrypt") {
	string m;
	mac = data.substr(0, mac_length);
        nonce = data.substr(mac_length, nonce_length);
        msg = data.substr(mac_length+nonce_length, (data.length() - (mac_length + nonce_length)));
        data.clear();
	m = cubemac.mac(msg, key, mac_length);
	if (m.compare(mac) == 0) {
	    msg = cube.decrypt(msg, key, nonce);
            outfile.open(out.c_str());
            outfile << msg;
            outfile.close();
	}
	else {
	    cout << "MAC failed: message has been tampered with.\n";
	    exit(1);
	}
    }
    return 0;
}
