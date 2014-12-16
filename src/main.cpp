#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

extern "C" {
    #include <unistd.h>
    #include <getopt.h>
}

/* functions */
void display_usage(std::string exname, std::string e_version);

void display_cow_list(std::string e_cowpath);

void display_cow();

void add_word_to_message(const std::string & word);

void get_interactive_message();

/* constants */
const std::string version = "0.1";

/* variables */
unsigned int message_word_count = 0;

unsigned int wrap = 40;
std::string eyes = "oo";
std::string tongue = "  ";
std::string mouth = "  ";
std::string cowpath = "/usr/share/cow";
std::string cowfile = "default.cow";
std::string message = "";

/* main */
int main(int argc, const char *argv[])
{
    int opt;

    while ((opt = getopt (argc, (char **)argv, "hlne:f:T:W:")) != -1)
        switch (opt) {
            case 'h':
                display_usage(argv[0], version);
                return EXIT_SUCCESS;
            case 'l':
                std::cout << "Cow files in " << 
                        cowpath << ":" << std::endl;
                return EXIT_SUCCESS;
            case 'e':
                //if (eyes.size() == 1) {
                eyes.clear();
                eyes += optarg[0];
                eyes += optarg[1];
                break;
            case 'f':
                cowfile = optarg;
                break;
            case 'T':
                mouth.clear();
                mouth += optarg[0];
                mouth += optarg[1];
                break;
            case 'W':
                try {
                    wrap = std::stoi(optarg);
                } catch (std::exception e) {
                    wrap = 1;
                }
                break;
            default:
                break;
        }

        for (int index = optind; index < argc; index++) {
            add_word_to_message( argv[index]);
        }

        if (message_word_count==0)
            get_interactive_message(); 
        display_cow();
    return EXIT_SUCCESS;
}

void display_usage(std::string exname, std::string e_version) {
    std::cout << "cxx{say,think} version " << e_version << 
            ", (c) 2014 Duane Bekaert" << std::endl << "usage: " << 
            exname << " [-bdgpstwy] [-h] [-e eyes] [-f cowfile] " << 
            std::endl << 
            "          [-l] [-n] [-t tongue] [-w wrapcolumn] [message] " << 
            std::endl;
}

void display_cow_list(std::string e_cowpath) {
}

void display_cow() {
    std::cout << " ";
    for(int i = 0; i < message.size() + 2; i++)
        std::cout << "-";

    if (message.size() < wrap) {
        std::cout << std::endl << "< " << message << " >" << std::endl << " "; 
    } else {

    }

    for(int i = 0; i < message.size() + 2; i++)
        std::cout << "-";
    std::cout << std::endl;
}

void add_word_to_message(const std::string& word) {
    if (word.empty()) return;
    
    if (message_word_count > 0)
        message += " ";
    message_word_count++;
    message += word;
}

void get_interactive_message() {
    std::cin >> std::noskipws;
    std::istream_iterator<char> it(std::cin);
    std::istream_iterator<char> end;
    std::string results(it, end);
    
    message = results;
}
