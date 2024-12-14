#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

int main() {
    std::cout << "Insert Mode:\n";
    std::ofstream open_file("temp.txt", std::ios::app);
    std::string text;
    
    while (open_file) {
        getline(std::cin, text);
        
        if (text == "-1") {
            break;
        }
        
        open_file << text << "\n";
    }
    
    open_file.close();
    
    std::filesystem::path fullPath = std::filesystem::absolute("temp.txt");
    std::cout << "Full path of the file: " << fullPath << std::endl;

    return 0;
}
