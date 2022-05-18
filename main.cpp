#include "lavaResawndz.h"

const std::string targetBrsarName = "smashbros_sound";

// Test which exports a sawnd file of the specified name for the specified group.
#define ENABLE_SAWND_EXPORT_TEST true
// Test which imports a sawnd file, then exports the .brsar.
#define ENABLE_SAWND_IMPORT_TEST true
const unsigned long sawndTestsTargetGroupID = 0x11;
const std::string sawndTestsFilename = "sawnd.sawnd";

const std::string brsarDefaultFilename = targetBrsarName + ".brsar";
const std::string sawndDefaultFilename = "sawnd.sawnd";
const std::string nullArgumentString = "-";
bool isNullArg(const char* argIn)
{
	return (argIn != nullptr) ? (strcmp(argIn, nullArgumentString.c_str()) == 0) : 0;
}

int testmain()
{
	lava::brawl::brsar testBrsar;
	testBrsar.init(targetBrsarName + ".brsar");
#if ENABLE_SAWND_EXPORT_TEST
	lava::brawl::exportSawnd(testBrsar, sawndTestsTargetGroupID, sawndTestsFilename);
#endif
#if ENABLE_SAWND_IMPORT_TEST
	lava::brawl::importSawnd(testBrsar, sawndTestsFilename);
	testBrsar.exportContents(targetBrsarName + "_sawndimport.brsar");
#endif
	return 0;
}

int main(int argc, char** argv)
{
	srand(time(0));
	std::cout << "Resawndz " << lava::brawl::resawndzVersion << "\n";
	std::cout << "Written by QuickLava\n";
	std::cout << "Based directly on work by:\n";
	std::cout << " - Jaklub and Agoaj, as well as mstaklo, ssbbtailsfan, stickman and VILE (Sawndz, Super Sawndz)\n";
	std::cout << " - Soopercool101, as well as Kryal, BlackJax96, and libertyernie (BrawlLib, BrawlBox, BrawlCrate)\n\n";
	try
	{
		if (argc >= 2)
		{
			if (strcmp("sawndcreate", argv[1]) == 0 && argc >= 3)
			{
				lava::brawl::brsar sourceBrsar;
				std::string activeBrsarName = targetBrsarName + ".brsar";
				std::string targetFileName = sawndDefaultFilename;
				if (argc >= 4 && !isNullArg(argv[3]))
				{ 
					activeBrsarName = argv[3];
				}
				if (argc >= 5 && !isNullArg(argv[4]))
				{
					targetFileName = argv[4];
				}
				if (sourceBrsar.init(activeBrsarName))
				{
					lava::brawl::exportSawnd(sourceBrsar, std::stoi(argv[2]), targetFileName);
				}
				else
				{
					std::cerr << "[ERROR] Failed to initialize .brsar struct! Operation aborted!\n";
				}
				return 0;
			}
			if (strcmp("sawnd", argv[1]) == 0 && argc >= 2)
			{
				lava::brawl::brsar sourceBrsar;
				std::string activeBrsarName = targetBrsarName + ".brsar";
				std::string targetFileName = sawndDefaultFilename;
				if (argc >= 3 && !isNullArg(argv[2]))
				{
					activeBrsarName = argv[2];
				}
				if (argc >= 4 && !isNullArg(argv[3]))
				{
					targetFileName = argv[3];
				}
				if (sourceBrsar.init(activeBrsarName))
				{
					lava::brawl::importSawnd(sourceBrsar, targetFileName);
					sourceBrsar.exportContents(activeBrsarName);
				}
				else
				{
					std::cerr << "[ERROR] Failed to initialize .brsar struct! Operation aborted!\n";
				}
				return 0;
			}
		}
		std::cout << "Invalid argument set supplied! Please provide one of the following sets of arguments!\n";
		std::cout << "To export a .sawnd:\n";
		std::cout << "\tsawndcreate {GROUP_ID} {BRSAR_PATH, optional} {OUTPUT_PATH, optional}\n";
		std::cout << "To import a .sawnd:\n";
		std::cout << "\tsawnd {BRSAR_PATH, optional} {INPUT_PATH, optional}\n";
		std::cout << "Note: Default BRSAR_PATH is \"" << brsarDefaultFilename << "\", default IN/OUTPUT_PATH is \"" << sawndDefaultFilename << "\".\n";
		std::cout << "Note: To explicitly use one of the above defaults, specify \"" << nullArgumentString << "\" for that argument.\n";
	}
	catch (std::exception e)
	{
		std::cerr << "EXCEPTION: ";
		std::cerr << e.what();
	}
	return 0;
}