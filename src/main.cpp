#include <iostream>
#include <string>
#include <asio.hpp>
#include <boost/bind.hpp>
#include "server.hpp"
#include "amf3.h"

namespace spitfire {
namespace server { spitfire::server::server * gserver; bool TimerThreadRunning = false; }}

int main(int argc, char* argv[])
{
	try
	{
		// Initialise the server.
		spitfire::server::gserver = new spitfire::server::server;
		// Run the server until stopped.
		spitfire::server::gserver->run();

		while (spitfire::server::TimerThreadRunning)
		{
			Sleep(1);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << "exception: " << e.what() << "\n";
	}
	system("pause");
	delete spitfire::server::gserver;

	return 0;
}
