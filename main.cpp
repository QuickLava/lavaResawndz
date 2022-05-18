#include "lavaResawndz.h"

const std::string targetBrsarName = "smashbros_sound";

int main(int argc, char** argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	srand(time(0));
	std::cout << "Resawndz " << lava::brawl::resawndzVersion << "\n";
	std::cout << "Written by QuickLava\n";
	std::cout << "Based directly on work by:\n";
	std::cout << " - Jaklub and Agoaj, as well as mstaklo, ssbbtailsfan, stickman and VILE (Sawndz, Super Sawndz)\n";
	std::cout << " - Soopercool101, as well as Kryal, BlackJax96, and libertyernie (BrawlLib, BrawlBox, BrawlCrate)\n\n";
	try
	{
		if (argc == 1)
		{
			std::cerr << "Please open the SuperSawndz GUI, rather than this program.\n";
			return 0;
		}
		else
		{
			if (strcmp("sawndcreate", argv[1]) == 0)
			{
				lava::brawl::brsar sourceBrsar;
				std::string activeBrsarName = targetBrsarName + ".brsar";
				if (argc == 4)
				{ 
					activeBrsarName = argv[3];
				}
				sourceBrsar.init(activeBrsarName);
				lava::brawl::exportSawnd(sourceBrsar, std::stoi(argv[2]), "sawnd.sawnd");
				return 0;
			}
			if (strcmp("sawnd", argv[1]) == 0)
			{
				lava::brawl::brsar sourceBrsar;
				std::string activeBrsarName = targetBrsarName + ".brsar";
				if (argc == 3)
				{
					activeBrsarName = argv[2];
				}
				sourceBrsar.init(activeBrsarName);
				lava::brawl::importSawnd(sourceBrsar, "sawnd.sawnd");
				sourceBrsar.exportContents(activeBrsarName);
				return 0;
			}
			std::cerr << "Incorrect command.\n";
			return 0;
		}
	}
	catch (std::exception e)
	{
		std::cerr << "EXCEPTION: ";
		std::cerr << e.what();
	}
	return 0;
}