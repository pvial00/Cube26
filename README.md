# Cube26 C++ implementation  
Cube is an advanced general purpose substitution stream cipher.

No attack of any kind has been proposed against Cube.  Cube passes NIST and DieHarder statistical tests.


# Usage:  
Cube cube;

cube.encrypt(data, key, nonce);  

cube.decrypt(data, key, nonce);  

# CubeH (Slow hash function)  
CubeH hash;  

hash.digest(data, optionalkey, length_in_bits);  

# CubeKDF  
CubeKDF kdf;  

kdf.genkey(key, keylen_in_bytes, iterations);  

# CubeRandom  
CubeRandom rand;  

rand.random(num_of_bytes);  
