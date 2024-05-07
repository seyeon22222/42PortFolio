
#include "IRCServer.hpp"
#include "Util.hpp"

int main(int argc, char **argv) {
	try {
		Util::parseArgv(argc);
		unsigned short port = Util::parsePort(argv[1]);
		(void)port;
		std::string password = Util::parsePassword(argv[2]);
		IRCServer	server(port, password);

		server.run();
	} catch (std::exception const &e) {
		std::cout << e.what();
	}
}
