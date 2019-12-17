#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <cstring>

using namespace boost::filesystem;
namespace po = boost::program_options;

int main()
{
    std::string directory; 

    po::options_description desc("All options");
    po::variables_map vm;
    desc.add_options()
        ("help,h", "produce help message")
        ("directory,d",  po::value<std::string>(), "file path")
    ;

    if (vm.count("directory")) 
        directory = vm["directory"].as<std::string>();
    else if (vm.count("d"))
        directory = vm["d"].as<std::string>();
    else 
        directory = "/mnt/c/Users/Yanushka/Downloads/2019-09-26-raspbian-buster-lite.zip";

    path p{directory};

    std::cout << p.root_name() << '\n';
    std::cout << p.root_directory() << '\n';
    std::cout << p.root_path() << '\n';
    std::cout << p.relative_path() << '\n';
    std::cout << p.parent_path() << '\n'; // use this for path 
    std::cout << p.filename() << '\n';

    space_info info = space(p);

    std::cout << info.capacity << " bytes" << '\n';
    std::cout << info.free << " bytes" << '\n'; // use this for amount of free space

    std::cout << file_size(p.string()) << " bytes" << '\n';  // use this for size of the file 

}