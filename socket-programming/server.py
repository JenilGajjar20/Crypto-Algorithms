import socket
import random


def diffieHellmanKeyExchange(conn):
    primeNumber = 23
    primitiveRoot = 5

    privateKeyServer = random.randint(2, primeNumber - 1)

    publicKeyServer = (primitiveRoot ** privateKeyServer) % primeNumber

    conn.send(str(publicKeyServer).encode())

    publicKeyClient = int(conn.recv(1024).decode())

    sharedSecret = (publicKeyClient ** privateKeyServer) % primeNumber

    return sharedSecret


serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = '127.0.0.1'
port = 8080
serverSocket.bind((host, port))

serverSocket.listen(5)

print(f"Server listening on {host}:{port}")

while True:
    clientSocket, addr = serverSocket.accept()
    print(f"Got connection from {addr}")

    sharedSecret = diffieHellmanKeyExchange(clientSocket)
    print(f"Shared Secret: {sharedSecret}")

    clientSocket.close()
