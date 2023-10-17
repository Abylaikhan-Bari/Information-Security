import os
import hashlib
import binascii

# User registration: Generate a salt and hash the password
def register_password(password, salt_length=16, iterations=100000):
    # Generate a random salt
    salt = os.urandom(salt_length)
    print(f'\nGenerated salt: {binascii.hexlify(salt).decode("utf-8")}')

    # Hash the password with the salt
    key = hashlib.pbkdf2_hmac('sha256', password.encode('utf-8'), salt, iterations)
    print(f'\nHashing password with the salt...')

    # Encode the salt and key as hexadecimal for storage in the database
    salt_hex = binascii.hexlify(salt).decode('utf-8')
    key_hex = binascii.hexlify(key).decode('utf-8')

    print(f'\nStored salt: {salt_hex}')
    print(f'\nStored key: {key_hex}')
    print(f'\nIterations: {iterations}')

    return salt_hex, key_hex, iterations

# User login: Verify the password
def verify_password(stored_salt, stored_key, stored_iterations, entered_password):
    # Decode the stored salt and key from hexadecimal
    salt = binascii.unhexlify(stored_salt.encode('utf-8'))
    key = binascii.unhexlify(stored_key.encode('utf-8'))

    # Hash the entered password with the stored salt and iterations
    entered_key = hashlib.pbkdf2_hmac('sha256', entered_password.encode('utf-8'), salt, stored_iterations)
    print(f'\nHashing entered password with stored salt and iterations...')

    # Compare the computed key with the stored key
    if entered_key == key:
        print('\nPassword is valid.')
        return True
    else:
        print('\nPassword is invalid.')
        return False

# Example usage
if __name__ == '__main__':
    # Registration
    entered_password = input("\nEnter password for registration: ")  # Enter a password during registration
    print('\nRegistering password...')
    salt, key, iterations = register_password(entered_password)

    # Verification
    while True:
        entered_password = input("\nEnter password for verification: ")  # Keep asking for a password until a correct one is entered
        print('\nVerifying password...')
        if verify_password(salt, key, iterations, entered_password):
            break  # Exit the loop when a correct password is entered
