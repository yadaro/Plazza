//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <QApplication>
#include "include/plazzaGui.hpp"

// int main(int argc, char *argv[])
// {
//     QApplication app(argc, argv);
//     Window window;
//     window.show();
//     return app.exec();
// }

int main(int ac, char **av)
{
	QApplication app(ac, av);
	Window window;
	int threadMax = 0;

	if (ac == 2) {
		threadMax = atoi(av[1]);
		try {
			// start(threadMax);
			window.setNbrThreadMax(threadMax);
			window.show();
			return app.exec();
		}
		catch (std::exception e) {
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Bad arguments soory\n";
	return 0;
}