#include <iostream>
#include <string>

// Функция для разбиения интернет-адреса на сервер, каталоги и имя файла
void splitURL(const std::string& url, std::string& server, std::string& directories, std::string& fileName) {
    size_t protocolEnd = url.find("://");
    size_t serverEnd = url.find('/', protocolEnd + 3);

    server = url.substr(protocolEnd + 3, serverEnd - protocolEnd - 3);
    directories = url.substr(serverEnd + 1, url.find_last_of('/') - serverEnd);
    fileName = url.substr(url.find_last_of('/') + 1);
}

int main() {
    std::string url;
    std::string server, directories, fileName;

    std::cout << "Введите интернет-адрес файла в формате 'http://www.сервер.ш\\каталог1\\каталог2\\...имя.расширение': ";
    std::cin.ignore();
    std::getline(std::cin, url);

    splitURL(url, server, directories, fileName);

    std::cout << "Сервер: " << server << std::endl;
    std::cout << "Каталоги: " << directories << std::endl;
    std::cout << "Имя файла: " << fileName << std::endl;

    return 0;
}
