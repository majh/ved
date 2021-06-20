#include <string>
#include <cxxopts.hpp>
#include <spdlog/spdlog.h>


cxxopts::ParseResult parse(int argc, char** argv, cxxopts::Options& options)
{
    try
    {
        auto result = options.parse(argc, argv);
        if (!result.count("port"))
        {
            throw(cxxopts::option_required_exception("port"));
        }
        return result;
    }
    catch (cxxopts::OptionException& ex)
    {
        spdlog::error(ex.what());
        spdlog::error(options.help());
        exit(EXIT_FAILURE);
    }
}


int main(int argc, char** argv)
{
    cxxopts::Options options("MyProgram", "One line description of MyProgram");
    options.add_options()
        ( "d,debug", "Enable debugging")
        ( "h,help", "Print help")
        ( "p,port", "Serial port", cxxopts::value<std::string>())
        ;

    auto result = parse(argc, argv, options);

    if (result.count("debug"))
    {
        // Set global log level to debug
        spdlog::set_level(spdlog::level::debug);
    }

    if (result.count("help"))
    {
        spdlog::error(options.help());
        exit(EXIT_SUCCESS);
    }

    spdlog::debug("Using port {}", result["port"].as<std::string>());

    return 0;
}

