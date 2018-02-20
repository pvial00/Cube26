# Cube26 C++ implementation  
*** Disclaimer - This cipher is meant for entertainment and educational purposes
 only and should not be used to actually provide good security  
Cube is an advanced general purpose substitution stream cipher.

Cube passes NIST and DieHarder statistical tests.  The recommended key length for Cube26 is 128 letters.

Binaries are available for the various tools built around Cube.  Run the binary and check the usage.

*** Linux requires libbsd-dev to be installed  

The cube26 binary utilizes CubeMAC and is authenticated.  


# Usage:  
Cube cube;

cube.encrypt(data, key, nonce);  

cube.decrypt(data, key, nonce);  

# CubeSum (Slow hash function)  
CubeSum hash;  

hash.digest(data, optionalkey, length_in_bits);  

# CubeKDF  
CubeKDF kdf;  

kdf.genkey(key, keylen_in_bytes, iterations);  

# CubeRandom  
CubeRandom rand;  

rand.random(num_of_bytes);  

# File encryption binary usage

cube26 <encrypt/decrypt> <input file> <output file> <password>   

# Interactive encryption binary usage  

cube26i <encrypt/decrypt>   
