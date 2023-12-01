#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 8080
using namespace std;

int main(int argument, char const *argv[])
{
    int obj_socket = 0, reader;
    struct sockaddr_in serv_addr;
    char *message = "A message from client";
    char buffer[1024] = {0};

    if ((obj_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Socket Creation Error!");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    // Converting IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        cout << "Invalid address! Address not supported!" << endl;
        return -1;
    }

    if (connect(obj_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        cout << "Connection Failed! Can't establish a connection over this socket!" << endl;
        return -1;
    }

    send(obj_socket, message, strlen(message), 0);
    cout << "Client: Message has been send!" << endl;

    reader = read(obj_socket, buffer, 1024);

    cout << "buffer: " << buffer << endl;

    return 0;
}