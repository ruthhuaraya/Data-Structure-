#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    const char* SERVER_IP = "192.168.119.105"; // IP del servidor (Jhon)
    int SERVER_PORT = 12345;

    // Inicializar Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        std::cerr << "Fallo al iniciar Winsock. Error: " << WSAGetLastError() << std::endl;
        return 1;
    }

    // Crear socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        std::cerr << "No se pudo crear el socket. Error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // Configurar servidor
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    server.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Conectar al servidor
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        std::cerr << "Fallo al conectar al servidor." << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    std::cout << "Conectado al servidor.\n";
    
    // Enviar número
    std::string numero;
    std::cout << "Ingrese el primer numero: ";
    std::cin >> numero;

    send(sock, numero.c_str(), numero.size(), 0);
    std::cout << "Numero enviado al servidor.\n";

    // Cerrar
    closesocket(sock);
    WSACleanup();
    return 0;
}