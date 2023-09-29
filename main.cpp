#include <iostream>
#include <string>
#include <filesystem>

using namespace std;

const string EXTENSION = "cpp";
const string TEMP = getenv("TEMP");

void error(string message) {
    cout << "ERROR: " << message << endl;
    exit(0);
}

int main(int argc, char **argv) {
    string file_path = argv[1];

    size_t bar = file_path.rfind('\\', file_path.length());
    string file = file_path.substr(bar + 1);
    size_t dot = file.rfind('.', file.length());

    string file_name = file.substr(0, dot);
    string file_extension = file.substr(dot + 1, file.length() - dot);

    if (!filesystem::exists({ file_path }))
        error("\"" + file_path + "\"" + " doesn't exist.");
    else if (file_extension != EXTENSION)
        error("\"" + file_path + "\" isn't a C++ source file. The extension must be \"." + EXTENSION + "\"");

    string exe_path = TEMP + "\\" + file_name + ".exe";
    string command = "g++ -o " + exe_path + " " + file_path + " & " + exe_path;

    if (argc > 2) {
        for (int i = 2; i < argc; i++) {
            command.append(" ");
            command.append(argv[i]);
        }
    }

    system(command.c_str());
    remove(exe_path.c_str());

    return 0;
}