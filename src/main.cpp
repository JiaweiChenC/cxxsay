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

void display_cow( std::string e_eyes,
        std::string  e_tongue,
        std::string  e_cowpath,
        std::string  e_cowfile,
        std::string  e_message);

void add_word_to_message(const std::string & word);

void get_interactive_message();

const std::string version = "0.1";

unsigned int message_word_count = 0;

unsigned int wrap = 40;
std::string eyes = "oo";
std::string tongue = "  ";
std::string mouth = "  ";
std::string cowpath = "/usr/share/cow";
std::string cowfile = "default.cow";
std::string message = "";

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
        display_cow(eyes, tongue, cowpath, cowfile, message);
    return EXIT_SUCCESS;
}

void display_usage(std::string exname, std::string e_version) {
    std::cout << "cxx{say,think} version " << e_version << 
            ", (c) 2014 duane bekaert" << std::endl << "usage: " << 
            exname << " [-bdgpstwy] [-h] [-e eyes] [-f cowfile] " << 
            std::endl << 
            "          [-l] [-n] [-t tongue] [-w wrapcolumn] [message] " << 
            std::endl;
}

void display_cow_list(std::string e_cowpath) {
    std::cout << "lel" << std::endl;
}

void display_cow( std::string e_eyes,
        std::string  e_tongue,
        std::string  e_cowpath,
        std::string  e_cowfile,
        std::string  e_message) {
    std::cout << e_message << std::endl;
}

void add_word_to_message(const std::string& word) {
    if (word.empty()) return;
    
    if (message_word_count > 0)
        message += " ";
    message_word_count++;
    message += word;
}

void get_interactive_message() {
    std::cin.ignore('\n');
    std::cin >> message;

    if(std::cin.eof()) {
        return;
    }
}
