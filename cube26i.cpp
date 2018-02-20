#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <algorithm>
#include "cube26.cpp"

int iterations = 10;
int keylen = 128;
int nonce_length = 16;
int mac_length = 16;

using namespace std;

void usage() {
    cout << "Usage: cube26i <encrypt/decrypt>" << "\n";
}

int main(int argc, char** argv) {
    ifstream infile;
    ofstream outfile;
    string mode, in, out, key, msg, nonce, data, mac;
    unsigned char b;
    int i;
    if (argc < 2) {
        usage();
        exit(EXIT_FAILURE);
    }
    mode = argv[1];
    CubeKDF kdf;
    Cube cube;
    CubeMAC cubemac;
    if (mode == "encrypt") {
        cout << "Enter data to encrypt: ";
        cin >> data;
        cout << "Enter key: ";
        cin >> key;
        key = kdf.genkey(key, keylen, iterations);
	CubeRandom rand;
	nonce = rand.random(nonce_length);
    	data = cube.encrypt(data, key, nonce);
        cout << nonce+data << "\n";
    }
    else if (mode == "decrypt") {
        cout << "Enter data to decrypt: ";
        cin >> data;
        cout << "Enter key: ";
        cin >> key;
        key = kdf.genkey(key, keylen, iterations);
        nonce = data.substr(0, nonce_length);
        msg = data.substr(nonce_length, (data.length() - (nonce_length)));
        data.clear();
	msg = cube.decrypt(msg, key, nonce);
        cout << msg << "\n";
    }
    return 0;
}
