# Vernam cipher library

## Description
The Vernam cipher is very simple. It uses Exclusive OR (XOR) operation.

Also Vernam cipher is called **O**ne-**T**ime-**P**ad(OTP) cipher, meaning that
encryption/decription key should be used only once, and then the key should be
destroyed.

Data to be encrypted and encryption key should have the same length. 

It has absolute cryptographic strength.

### Pros
* simple
* fast
* absolute cryptographic strength

### Cons
* need absolutly random key. The best solution is hardware random number
generator.
* key length should be at least as long as the data length
* the key should be never reused in data encryption again.
* need to have a sufficient number of keys at hand
* the must be completelly secret 
* key distribution is hard to realise
* lack of confirmation of the authenticity and integrity of the data
* cipher is very sensitive to any violation of the encryption procedure

## Library usage
To use you need to pass `VernamData` structure to cipher method
```c
typedef struct {
    size_t len;
    char* data;
    char* key;
} VernamData;

size_t Vernam_crypt(VernamData* data);
```

Cipher method returns number of byted encrypted/decrypted.

`Vernam\_crypt` method is used for data encryption and decryption.

'Vernam\_crypt' method rewrites `data` in `VernamData` structure.

You also need to specify length `len` of data and key. They must be the same.
