#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26
#define NUM_ROTORS 8

/* Array of rotors */
const char* enigma_rotors[NUM_ROTORS+1] = {
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ", //0
    "EKMFLGDQVZNTOWYHXUSPAIBRCJ", //1
    "AJDKSIRUXBLHWTMCQGZNPYFVOE", //2
    "BDFHJLCPRTXVZNYEIWGAKMUSQO", //3
    "ESOVPZJAYQUIRHXLNFTGKDCMWB", //4
    "UKLBEPXWJVFZIYGAHCMTONDRQS", //5
    "JPGVOUMFYQBENHZRDKASXLICTW", //6
    "NZJHGRCXMYSWBOUFAIVLPEKQDT", //7
    "FKQHTLXOCBJSPDZRAMEWNIUYGV"  //8
};

/*
 * Convert a space-separated string of rotor indices into
 * an integer array of rotor indices
 *
 * @param rotor_ind_str   Space-separated string of rotor indices
 * @param num_rotors      Number of rotors provided in the string
 * @return                Integer array of rotor indices
 */
int* parse_rotor_indices(char* rotor_ind_str, int num_rotors) {
    int* int_arr = malloc(num_rotors * sizeof(int));

    int i = 0;
    int nums = 0;
    while (nums < num_rotors) {
        if (rotor_ind_str[i] == ' ') {
            i++;
            continue;
        }
        int_arr[nums] = rotor_ind_str[i] - 48;
        i++;
        nums++;
    }
    return int_arr;
}

/*
 * Create a 2D array of integers where
 * each row represents a rotor
 *
 * @param rotors          Integer array of rotor indices
 * @param num_rotors      Number of rotors provided
 * @return                2D array where each row represents a rotor
 */
int** set_up_rotors(int* rotors, int num_rotors) {
    int** result = malloc(num_rotors * sizeof(int*));

    for (int i = 0 ; i < num_rotors ; i++) {
        result[i] = malloc(ALPHABET_SIZE * sizeof(int));

        for (int j = 0 ; j < ALPHABET_SIZE ; j++) {
            result[i][j] = enigma_rotors[rotors[i]][j] - 65;
        }
    }

    return result;
}


/*
 * Rotate each rotor to the right by the
 * given number of rotations
 *
 * @param rotor_config   2D array of rotors
 * @param rotations      Number of rotations
 * @param num_rotors     Number of rotors provided
 */
void rotate_rotors(int** rotor_config, int rotations, int num_rotors) {
    int temp[ALPHABET_SIZE];

    for (int i = 0 ; i < num_rotors ; i++) {
        for (int j = 0 ; j < ALPHABET_SIZE ; j++) {
            int curr = j % ALPHABET_SIZE;
            int target = (j + rotations) % ALPHABET_SIZE;

            // printf("Curr: %d, Target: %d\n", curr, target);

            temp[target] = rotor_config[i][curr];
        }

        for (int w = 0 ; w < ALPHABET_SIZE ; w++) {
            rotor_config[i][w] = temp[w];
        }
    }
}

/*
 * Encrypt the given message
 *
 * @param message        Message to encrypt
 * @param rotor_config   2D array of rotors
 * @param num_rotors     Number of rotors provided
 * @return               Encrypted message
 */
char* encrypt(char *message, int** rotor_config, int num_rotors) {
    // to uppercase
    int u = 0;
    while (message[u] != '\0') {
        if (97 <= message[u] && message[u] <= 122) {
            message[u] -= 32;
        }
        u++;
    }

    int n = 0;
    while (message[n] != '\0')
        n++;

    char* result = malloc(n * sizeof(char));
   
    for (int i = 0 ; i < num_rotors ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (65 <= message[j] && message[j] <= 90) {
                message[j] = rotor_config[i][message[j] - 65];
                message[j] += 65;
            }
        }
    }

    for (int i = 0 ; i < n ; i++) {
        result[i] = message[i];
    }

    return result;
}

int find_i(int* message, int len, char ch) {
    for (int i = 0 ; i < len ; i++) {
        if ((message[i] + 65) == ch) {
            return i;
        }
    }
    return -1;
}

/*
 * Decrypt the given message
 *
 * @param message        Message to decrypt
 * @param rotor_config   2D array of rotors
 * @param num_rotors     Number of rotors provided
 * @return               Decrypted message
 */
char* decrypt(char *message, int** rotor_config, int num_rotors) {
    // to uppercase
    int u = 0;
    while (message[u] != '\0') {
        if (97 <= message[u] && message[u] <= 122) {
            message[u] -= 32;
        }
        u++;
    }
    int n = 0;
    while (message[n] != '\0')
        n++;
    char* result = malloc(n * sizeof(char));
    for (int i = 0 ; i < num_rotors ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (65 <= message[j] && message[j] <= 90) {
               int ind = find_i(rotor_config[i], ALPHABET_SIZE, message[j]);
               message[j] = enigma_rotors[0][ind];
            }
        }
    }

    for (int i = 0 ; i < n ; i++)
        result[i] = message[i];

    return result;
}

int parse_rotations(char* rotors_str)
{
    int n = 0;
    while (rotors_str[n] != '\0')
        n++;

    int rotations = 0;
    for (int i = 0 ; i < n ; i++)
        rotations = (rotations * 10) + (rotors_str[i] - 48);
    return rotations;
}


/*
 * Format of command line input:
 * ./enigma e "JAVA" 3 "1 2 4" 0
 * 
 *    e    - mode (e for encrypt, d for decrypt)
 * "JAVA"  - message
 *    3    - number of rotors to use
 * "1 2 4" - indices of rotors to use
 *    0    - number of rotations of the rotors
 */
int main(int argc, char* argv[]) {
    if (argc != 6) {
        printf("%s\n", "Incorrect number of parameters!");
        return -1;
    }
    char* mode  = argv[1];
    char* input = argv[2];
    int numRotors = *argv[3] - 48;
    char* rotors = argv[4];
    int rotations = parse_rotations(argv[5]);

    int* rot_arr = parse_rotor_indices(rotors, numRotors);
    int** res_rotors = set_up_rotors(rot_arr, numRotors);
    rotate_rotors(res_rotors, rotations, numRotors);

    // for (int i = 0 ; i < numRotors ; i++)
    // {
    //     for (int j = 0 ; j < ALPHABET_SIZE ; j++)
    //     {
    //         printf("%c", res_rotors[i][j] + 65);
    //     }
    //     printf("\n");
    // }

    // Encryption Mode
    if (*mode == 'e') {
        char* ciphertext = encrypt(input, res_rotors, numRotors);
        printf("Encrypted message: %s\n", ciphertext);
    }
    // Decryption Mode
    else if (*mode == 'd')
    {
        char* plaintext = decrypt(input, res_rotors, numRotors);
        printf("Decrypted message: %s\n", plaintext);
    }
}

