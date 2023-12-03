import socket
import random


def diffieHellmanKeyExchange(conn):
    publicKeyServer = int(conn.recv(1024).decode())

    primeNumber = 23
    primitiveRoot = 5

    privateKeyClient = random.randint(2, primeNumber - 1)

    publicKeyClient = (primitiveRoot ** privateKeyClient) % primeNumber

    conn.send(str(publicKeyClient).encode())

    sharedSecret = (publicKeyServer ** privateKeyClient) % primeNumber

    return sharedSecret


clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = '127.0.0.1'
port = 8080
clientSocket.connect((host, port))

sharedSecret = diffieHellmanKeyExchange(clientSocket)
print(f"Shared Secret: {sharedSecret}")

clientSocket.close()
